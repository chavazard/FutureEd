<?php

// Función que trae las preguntas frecuentes de un curso específico
	function get_preguntas_frecuentes($nid)
	{
    $record = false;
		$result = db_query("SELECT id_pregunta, pregunta, respuesta FROM {preguntas_frecuentes} WHERE entity_id = ".$nid." AND status = 1;");
		$record = $result->fetchAll();
		return $record;
	}
  
	//Función que borra una pregunta frecuente individual
	function del_pregunta_frecuente($id)
	{
		if( $id > 0 )
		{
			$query = db_update ('preguntas_frecuentes')
				->fields(array('status' => 0))
				->condition('id_pregunta', $id);
			$rows = $query->execute();
      return $rows;
		}
    else
      return false;
	}
	
	//Funcion que almacena una nueva pregunta frecuente
	function add_pregunta_frecuente($pregunta, $respuesta, $nid = 0)
	{
    $rows = false;
		if($nid > 0 && $id == 0)
		{
			$query=db_insert('preguntas_frecuentes')
								->fields(array(
												'pregunta' => $pregunta,
												'respuesta' => $respuesta,
												'entity_id' =>$nid ,
								));
      $rows = $query->execute();
		}
    $rows = get_preguntas_frecuentes($nid);
    return $rows;
	}
  
  //Cambia la información de una pregunta frecuente
  function update_pregunta_frecuente($pregunta, $respuesta, $id = 0)
  {
    $rows = false;
    if($id > 0)
    {
      $query = db_update ('preguntas_frecuentes')
        ->fields(array('pregunta'=>$pregunta,'respuesta'=>$respuesta))
        ->condition('id_pregunta', $id);       
      $rows = $query->execute();
    }
    return $rows;
  }

	/**
	 * Funcion para sacar el listado de cursos sugeridos respecto a los intereses del usuario
	 * @param int $uid id de usuario
	 * @return object  Listado de cursos sugeridos 
	 */
	function get_cursos_sugeridos($uid, $inicio, $limite)
	{
		$result = db_query('SELECT taxonomy_id FROM {intereses} WHERE uid='.$uid.';');
		$record = $result->fetchAll();
		//var_dump($record);
		
		foreach ($record as $taxonomy_id)
		{
			$tids[] = $taxonomy_id->taxonomy_id;
		}
		
		
		$query = new EntityFieldQuery();
		$query->entityCondition('entity_type', 'node')
		  ->entityCondition('bundle', 'curso')
		  ->fieldCondition('field_categoria', 'tid', $tids, 'IN')
		  ->addTag('random')
		  ->range($inicio, $limite);
		$result = $query->execute();
		
		$faltantes = $limite - count($result);
		
		$inicio = $inicio + count($result);
		
		if($faltantes > 0){
			$query = new EntityFieldQuery();
			$query->entityCondition('entity_type', 'node')
			  ->entityCondition('bundle', 'curso')
			  ->fieldOrderBy('field_likes', 'value', 'ASC')
			  ->range($inicio, $faltantes);
			$query_result = $query->execute();

			$keys = array_keys($query_result['node']); 
			shuffle($keys);
			$random = array(); 
			foreach ($keys as $key) { 
				$random['node'][$key] = $query_result['node'][$key]; 
			}
			$query_result = $random;
			
			
			$result = array_merge($result, $query_result);
		}

		return get_cursos_list($result);
	}
	
	/**
	 * Implementation of hook_query_TAG_alter
	 */
	function fed_api_query_random_alter($query) {
		$query->orderRandom();
	}
	
	
	function get_curso_detail_info($nid)
	{
		$fields = array('field_curso_imagen');
		$results = get_fields_by_nid($nid, $fields, 'curso');
		$results['field_curso_imagen'] = create_image_url($results['field_curso_imagen']);
		$results['field_curso_nombre'] = get_property_by_id($nid, 'nid', 'title', 'node');
		
		return $results;
	}
  