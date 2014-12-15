<?php
	module_load_include('inc', 'configuracioncuenta', 'includes/configuracioncuenta.misc');
	
	// Logical

	// All titles of $limit number of courses
	function get_courses_nid($limit){
		 // Query for nids matching our conditions
		$query = new EntityFieldQuery();
		$query->entityCondition('entity_type', 'node')
		->propertyCondition('status', 1)
		->propertyCondition('type', array('curso'))
		->propertyOrderBy('created', 'DESC')
		 ->range(0, $limit);
	
		$result = $query->execute();

		// Get all nodes in only one query by using Drupal bult-in node_load_multiple() function
		$nids = array_keys($result['node']);

		return $nids;
	}

	// Get title of $limit number of courses
	function get_courses_title($limit){
		$titles = db_select('node', 'n')
	    ->fields('n',array('title'))
	    ->condition('type', 'curso', '=')
	    ->range(0,$limit)
	    ->execute()
	    ->fetchAll();

		return $titles;
	}

	// Get profesor names from a given string
	function get_profesor_names($string)
	{
		//$string = 'i';
		$result = db_query("SELECT name FROM {users} WHERE name LIKE '%%%$string%%%' LIMIT 10;");
		$record = $result->fetchAll();
		/*$results = db_select('users', 'u');
	  $results->addfield('u','name','value');
	  $results->condition('name', '%'.$string.'%','LIKE');
	  $results->range(0,10);
	  $results->execute();
	  $results->fetchAssoc();*/
		
		/*if(count($results)>0)
		foreach($results as $r)
		{
			$json[] = $r->name;
			
		}*/
		 
		//process the result
		//$json = $results->name;		
		$json = json_encode($record);
		print('{"suggestions":'.$json.'}');
	}
	
	// Función que trae fields específicos de un node, dado un nid
	function get_node_fields($nid, $fields, $user_fields)
	{
		$node = node_load($nid);
		//print_r($node);
		$result = array();
		foreach($fields as $field){
			$item = field_get_items('node', $node, $field);
			$result[$field] = $item[0]['value'];
			if($field == 'uid'){
				get_user_fields($item[0]['value'], $user_fields, null);
			}
		}

		$json = json_encode($result);
		print($json);
		
	}
	
	
	function insert_log($module,$func,$cont)
	{
		$insert = db_insert('custom_log')
		->fields(array('vc_module', 'vc_function','vc_content','dt_date'))
    ->values(array(
              'vc_module' => $module,
              'vc_function' => $func,
              'vc_content' => $cont,
							'dt_date' => date('Y-m-d H:i:s'),
            ));
        $insert->execute();
		print ($cont);
	}
	
	// Función que trae fields específicos de un node, dado un nid
	function get_fields_by_nid($nid, $fields, $type, $user_fields = null)
	{
		$query = new EntityFieldQuery();
		$query->entityCondition('entity_type', 'node')
		  //->entityCondition('bundle', 'curso')
		  ->propertyCondition('nid', $nid);
		$result = $query->execute();

		return get_fields_result($fields, $result, $type, $nid, $user_fields);
	}
	
	//Función que regresa nodos creados por cierto usuario, dado un uid
	function get_nodes_by_uid($uid, $type, $inicio =null, $limit = null, $ordenamiento = null, $count = null){
		/* Ordenamiento cursos creados:
		 * 0 fecha de inicio
		 * 1 estatus
		*/
		$query = new EntityFieldQuery();
		$query->entityCondition('entity_type', 'node')
		  ->entityCondition('bundle', $type)
		  //->propertyCondition('type', $type)
		  ->propertyCondition('uid', $uid);
		  if(isset($limit))
			$query->range($inicio, $limit);
		  if(isset($ordenamiento) && $ordenamiento != -1){
			$fields = array('field_curso_fecha', 'field_curso_estatus');
			$columns = array('value', 'tid');
			$query->fieldOrderBy($fields[$ordenamiento], $columns[$ordenamiento], 'ASC');
		  }
		  if(isset($count) && $count)
			$query->count();
		$result = $query->execute();

		return $result;
	}
	
	//Función que regresa listado de elementos de un usuario, dado un tipo y un uid
	function get_usuario_lista($uid, $type, $inicio = null, $limit = null, $ordenamiento = null){
		switch($type){
			case 'curso':
				$field = array('field_usuario_privacidad_cursos');
				break;
			case 'canal':
				$field = array('field_usuario_privacidad_canales');
				break;
		}
		$privacidad = get_user_fields($uid, $field);
		//print_r($privacidad);
		$result = array();
		if(!is_numeric($privacidad[$field]) || $privacidad[$field] == 1){
			$privacidad[$field] = true;
			$nodes = get_nodes_by_uid($uid, $type, $inicio, $limit, $ordenamiento);
			$count = get_nodes_by_uid($uid, $type, $inicio, $limit, $ordenamiento, true);
			//print_r($nodes);
			switch($type){
				case 'curso':
					$result = get_cursos_list($nodes);
					$result['field_usuario_privacidad_cursos'] = $privacidad['field_usuario_privacidad_cursos'];
					$result['total_cursos'] = $count;
					break;
				case 'canal':
					$result = get_canales_list($nodes);
					$result[$field] = $privacidad[$field];
					$result['total_canales'] = $count;
					break;
			}
		}
		else
			$privacidad[$field] = false;
		return $result;
	}
	
	//Función que regresa la lista de cursos de un canal
	function get_canal_cursos($nid_canal){
		$fields = array('nid', 'field_curso_fecha', 'field_curso_costo', 'field_curso_calificacion');
		
		$query = new EntityFieldQuery();
		$query->entityCondition('entity_type', 'node')
		  ->entityCondition('bundle', 'curso')
		  ->fieldCondition('field_curso_canal', 'value', $nid_canal, '=');
		$query_result = $query->execute();
		
		return get_cursos_list($query_result);
	}
	
	function get_cursos_busqueda($string, $categoria, $subcategoria, $modalidad, $ordenamiento, $rango_precio_min, $rango_precio_max, $inicio, $limite, $canal_nid = null){
		/*
                 'string', cadena de caracteres que ingresó el usuario como búsqueda, si no aplica llega como -1
                 'categoria',   nid_categoria
                 'modalidad',   entero si no se seleccionó filtro llega como -1
                 //'tipo',        entero si no se seleccionó filtro llega como -1// YA NO LLEVA TIPO
                 'ordenamiento',    entero si no se seleccionó criterio de ordenamiento llega como -1:
			0 precio ascendente
			1 precio desc
			2 valoracion asc
			3 valoracion desc
			4 fecha inicio asc
			5 fechia inicio desc
			6 duracion asc
			7 duracion desc
                 'calificacion',    entero si no se seleccionó filtro llega como -1
                 'rango_precio_min', entero si no se seleccionó criterio de ordenamientofiltro llega como -1
                 'rango_precio_max'  entero si no se seleccionó criterio de ordenamientofiltro llega como -1
                 'inicio' y 'limite', siempre deben llegar por la paginación
                 'canal_nid', nid del canal que solo llega en caso de que se quieran obtener solo los cursos de cierto canal
                 */
		
		$query_result = get_query_busqueda($string, $categoria, $subcategoria, $modalidad, $ordenamiento, $rango_precio_min, $rango_precio_max, $inicio, $limite, null, false);
		
		 if($rango_precio_min != -1 && $rango_precio_max != -1){
			$query_result = get_rango_precios($query_result, $rango_precio_min, $rango_precio_max, false);
			$count = get_rango_precios($query_result, $rango_precio_min, $rango_precio_max, true);
		  }
		  else{
			$count = get_query_busqueda($string, $categoria, $subcategoria, $modalidad, $ordenamiento, $rango_precio_min, $rango_precio_max, $inicio, $limite, null, true);
		  }
		
		if($ordenamiento == 6)
			$query_result = get_ordenamiento_duracion($query_result, 'ASC');
		if($ordenamiento == 7)
			$query_result = get_ordenamiento_duracion($query_result, 'DESC');
		
		$result = array();
		$result[] = get_cursos_list($query_result);
		$result['precio_maximo'] = get_precio_min_max($result[0]);
		$result['total_cursos'] = $count;
		return $result;
	}
	
	function get_query_busqueda($string, $categoria, $subcategoria, $modalidad, $ordenamiento, $rango_precio_min, $rango_precio_max, $inicio, $limite, $canal_nid = null, $count){
		if($string != -1){
			$nids = search_nodes_by_string($string);
			$nids = json_decode(json_encode($nids),true);
		}
		
		$query = new EntityFieldQuery();
		$query->entityCondition('entity_type', 'node')
		  ->entityCondition('bundle', 'curso');
		  
		  if($string != -1)
			$query->propertyCondition('nid', $nids, 'IN');
		  if($canal_nid != -1 && $canal_nid != null)
			$query->fieldCondition('field_curso_canal', 'value', $canal_nid, '=');
		  if($categoria != -1)
			$query->fieldCondition('field_categoria', 'tid', $categoria, '=');
		  if($subcategoria != -1)
			$query->fieldCondition('field_subcategoria', 'tid', $subcategoria, '=');	
		  if($modalidad != -1)
			$query->fieldCondition('field_curso_modalidad', 'tid', $modalidad, '=');
		  if($ordenamiento != -1 && $ordenamiento != 6 && $ordenamiento != 7){
			$fields = array('field_curso_costo', 'field_curso_costo', 'field_curso_calificacion', 'field_curso_calificacion', 'field_curso_fecha', 'field_curso_fecha');
			$directions = array('ASC', 'DESC', 'ASC', 'DESC', 'ASC', 'DESC');
			$query->fieldOrderBy($fields[$ordenamiento], 'value', $directions[$ordenamiento]);
		  }
		if($count)
			$query->count();
		else
			$query->range($inicio, $limite);
		  
		$query_result = $query->execute();
		
		return $query_result;
	}
	
	function get_ordenamiento_duracion($query_result, $direction){
		$nids = '';
		foreach($query_result['node'] as $node){
			$nids = $nids . $node->nid .',';
		}
		$nids = substr($nids, 0, strlen($nids)-1);
		//print_r($query_result);
		$result = db_query('SELECT entity_id as nid, bundle as type, (field_curso_fecha_value2 - field_curso_fecha_value) as duration FROM field_data_field_curso_fecha WHERE entity_id IN ('.$nids.') ORDER BY duration '.$direction);
		$record = $result->fetchAll();
		//print_r($record);
		
		$array = array();
		foreach($record as $re){
			$array['node'][$re->nid] = $re;
		}
		return $array;
		
	}
	
	function get_rango_precios($query_result, $rango_precio_min, $rango_precio_max, $count){
		$nids = '';
		foreach($query_result['node'] as $node){
			$nids = $nids . $node->nid .',';
		}
		$nids = substr($nids, 0, strlen($nids)-1);
		if($count)
			$query = 'SELECT COUNT(costo.entity_id) as count';
		else
			$query = 'SELECT costo.entity_id as nid, costo.bundle as type';
				   
		$query = $query . ' FROM drupal_futureed.field_data_field_curso_costo costo, drupal_futureed.field_data_field_curso_descuento descuento
				   WHERE costo.entity_id = descuento.entity_id AND costo.entity_id IN('.$nids.')
				   AND ((costo.field_curso_costo_value * (100 - descuento.field_curso_descuento_value) / 100) BETWEEN '.$rango_precio_min.' AND '.$rango_precio_max.')';
		//print_r($query);
		$result = db_query($query);
		$record = $result->fetchAll();
		
		if($count)
			return $record[0]->count;
		
		$array = array();
		foreach($record as $re){
			$array['node'][$re->nid] = $re;
		}
		return $array;
		
	}
	
	function get_precio_min_max($result){
		$precio_max = 0;
		foreach($result as $node){
			$descuento = (float)(100 - ($node['field_curso_descuento'])) / 100;
			$costo = (float)($node['field_curso_costo']);
			$costo_total = $costo * $descuento;
			
			if($costo_total > $precio_max)
				$precio_max = $costo_total;
		}
		return $precio_max;
	}
	
	//Función que regresa una lista de cursos con todos los campos posibles que se muestran en los listados
	function get_cursos_list($query_result){		//TODO - Falta implementar datos especiales, como lista de usuarios populares, etc.
		
		$fields = array('nid', 'uid', 'field_categoria', 'field_subcategoria', 'field_curso_fecha', 'field_curso_profesores',
				'field_curso_imagen', 'field_curso_costo', 'field_curso_descuento', 'field_curso_canal', 'field_curso_calificacion',
				'field_curso_numero_votos', 'field_likes', 'field_curso_estatus', 'field_curso_modalidad');
		$user_fields = array('field_usuario_nombre', 'field_usuario_apellidos', 'field_usuario_verificado');
		
		$nodes = get_fields_result($fields, $query_result, 'curso');
		//print_r($nodes);
		$result = array();
		$stop = false;
		foreach($nodes as $node){
			if(count($nodes) < 2 || !is_array($nodes[0])){
				$node = $nodes;
				$stop = true;
			}
			//Datos curso:
			$node['field_curso_nombre'] = get_property_by_id($node['nid'], 'nid', 'title', 'node');
			$node['link_curso'] = create_urls('node', $node['nid']);
			$node['calc_curso_duracion'] = calculate_weeks($node['field_curso_fecha'], $node['field_curso_fecha_value2']);
			$node['field_curso_fecha'] = date("d-m-y", $node['field_curso_fecha']); 			//TODO - Definir formato de fecha
			$node['field_curso_fecha_value2'] = date("d-m-y", $node['field_curso_fecha_value2']); 
			$node['calc_curso_costo_total'] = get_costo_total($node['field_curso_costo'], $node['field_curso_descuento']);
			//$node['field_curso_costo'] = format_precio($node['field_curso_costo']);
			$node['link_curso_categoria'] = create_urls('taxonomy', $node['field_categoria']);	//TODO - Definir formato de urls categoría y subcategoría
			$node['link_curso_subcategoria'] = create_urls('taxonomy', $node['field_subcategoria']);
   	        $node['link_curso_canal'] = create_urls('node', $node['field_curso_canal']);
			$node['field_curso_canal'] = get_property_by_id($node['field_curso_canal'], 'nid', 'title', 'node');	
			$node['field_categoria'] = get_term_by_tid($node['field_categoria']);
			$node['field_subcategoria'] = get_term_by_tid($node['field_subcategoria']);
			$node['field_curso_imagen'] = create_image_url($node['field_curso_imagen']);
				
			//Datos creador:
			$node['calc_creador_nombre'] = $node['field_usuario_nombre'].' '.$node['field_usuario_apellidos'];
			$username = get_property_by_id($node['uid'], 'uid', 'name', 'users');
			$node['link_curso_creador'] = create_urls('user', $username);
			$node['field_usuario_imagen'] = get_user_picture($node['uid']);
				
			//Datos tutores:
			$tutores_fields = array('field_usuario_nombre', 'field_usuario_apellidos');
			$node['array_curso_profesores'] = get_tutores($node['nid'], 'curso', $tutores_fields);
			
			/* PARA TESTING TUTORES*/
			$array_tutores = array();
			array_push($array_tutores,
					array('calc_nombre_tutor' => 'tutor1',
					      'link_nombre_tutor'  => 'link tutor1'
					     ),
					array('calc_nombre_tutor' => 'tutor2',
					      'link_nombre_tutor'  => 'link tutor2'
					     )
				  );
			$node['array_curso_profesores'] = $array_tutores;
			
			/* PARA TESTING USUARIOS POPULARES*/
			$array_usuarios = array();
			array_push($array_usuarios,
					array('calc_usuario_nombre' => 'usuario 1',
					      'field_usuario_imagen'  => 'imagen usuario 1',
					      'link_usuario_curso' => 'link usuario 1'
					     ),
					array('calc_usuario_nombre' => 'usuario 2',
					      'field_usuario_imagen'  => 'imagen usuario 2',
					      'link_usuario_curso' => 'link usuario 2'
					     ),
					array('calc_usuario_nombre' => 'usuario 3',
					      'field_usuario_imagen'  => 'imagen usuario 3',
					      'link_usuario_curso' => 'link usuario 2'
					     )				
				  );
			$node['array_usuarios_curso'] = $array_usuarios;
						

			$result[] = $node;
				
			if($stop)
				break;
		}
		
		return $result;
	}
	
	/*Obtiene los canales de los un usuario dado su administrador*/
	function get_canales_admin($uid, $inicio, $limite, $count){
		$query = new EntityFieldQuery();
		$query->entityCondition('entity_type', 'node')
		  ->entityCondition('bundle', 'canal')
		  ->fieldCondition('field_canal_admin', 'value', $uid, '=')
		  ->range($inicio, $limite);
		  if($count)
			$query->count();
		$result = $query->execute();
		
		if($count)
			return $result;

		return get_canales_list($result);
	}
	      
	
	
	//Función que regresa una lista de canales con todos los campos posibles que se muestran en los listados
	function get_canales_list($query_result){		
		$fields = array('nid', 'uid', 'field_categoria', 'field_subcategoria', 'field_canal_imagen');
		$user_fields = array('field_usuario_nombre', 'field_usuario_apellidos', 'field_usuario_verificado');
		
		$nodes = get_fields_result($fields, $query_result, 'curso', null, $user_fields);
		//print_r($nodes);
		$result = array();
		//if(count($nodes) > 1 && is_array($nodes[0])){
		foreach($nodes as $node){
			if(count($nodes) < 2 || !is_array($nodes[0])){
				$node = $nodes;
				$stop = true;
			}
			//Datos canal:
			$node['field_canal_nombre'] = get_property_by_id($node['nid'], 'nid', 'title', 'node');
			$node['link_canal'] = create_urls('node', $node['nid']);
			$node['link_canal_categoria'] = create_urls('taxonomy', $node['field_categoria']);
			$node['link_canal_subcategoria'] = create_urls('taxonomy', $node['field_subcategoria']);
			$node['field_categoria'] = get_term_by_tid($node['field_categoria']);
			$node['field_subcategoria'] = get_term_by_tid($node['field_subcategoria']);
			$node['field_canal_imagen'] = create_image_url($node['field_canal_imagen']);
				
			//Datos creador:
			$node['calc_creador_nombre'] = $node['field_usuario_nombre'].' '.$node['field_usuario_apellidos'];
			$username = get_property_by_id($node['uid'], 'uid', 'name', 'users');
			$node['link_canal_creador'] = create_urls('user', $username);
			$node['field_usuario_imagen'] = get_user_picture($node['uid']);
			
			//Falta: calc_numero_cursos
			$node['calc_numero_cursos'] = get_numero_cursos_canal($node['nid']);
			
			$result[] = $node;
				
			if($stop)
				break;
		}
		return $result;
	}
	
	function get_numero_cursos_canal($nid){
		$query = new EntityFieldQuery();
		$query->entityCondition('entity_type', 'node')
		  ->entityCondition('bundle', 'curso')
		  ->fieldCondition('field_curso_canal', 'value', $nid, '=')
		  ->count();
		$result = $query->execute();

		return $result;
	}
	

	
	//Función que procesa el resultado obtenido en get_fields_by_nid y obtiene solo los campos necesarios
	function get_fields_result($fields, $result, $type, $nid = null, $user_fields = null)
	{
		//----------Result Debug
		/*
		$json = json_encode($result);
		print_r('<br>Resultado<br>');
		print_r($json);
		*/
		//return;
		//----------
		if (isset($result['node'])) {
			$nodes = $result['node'];
			$fields_result = array();       
			$fields_info = field_info_instances('node', $type);     
			foreach($fields as $field){
				if($field != 'nid' && $field != 'uid'){
					$field_id = $fields_info[$field]['field_id'];
					field_attach_load('node', $nodes, FIELD_LOAD_CURRENT, array('field_id' => $field_id));	
				}
			}
			//print_r($nodes);
			if(count($nodes) > 1){
				$nodes_result = array();
			}
			foreach($nodes as $node){
				//print_r($node);
				foreach($fields as $field){
					if($field != 'nid' && $field != 'uid'){
						$value = field_get_items('node', $node, $field);
						if(isset($value)){
							$temp = array();
							foreach($value as $item){
								if(isset($item['tid'])){		//Cuando el campo es de tipo term reference, el valor aparece como 'tid'
									$temp[] = $item['tid'];
								}
								else{
									$temp[] = $item['value'];
								}
								if(isset($item['value2'])){		//Por ejemplo en el caso de una fecha final, esta aparecerá como 'value2'
									$temp[$field.'_value2'] = $item['value2'];
								}
							}
							if(count($value) > 1){
								$fields_result[$field] = array();
								$fields_result[$field] = $temp;
							}
							else{
								$fields_result[$field] = $temp[0];
								if(isset($temp[$field.'_value2'])){
									$fields_result[$field.'_value2'] = $temp[$field.'_value2'];
								}
							}
						}
					}
				}
				if(in_array('nid', $fields)){
					$fields_result['nid'] = $node->nid;
					$nid = $fields_result['nid'];
				}
				if(in_array('uid', $fields)){
					$fields_result['uid'] = get_property_by_id($nid, 'nid', 'uid', 'node');
					if(isset($user_fields))
						$fields_result = get_user_fields($fields_result['uid'], $user_fields, $fields_result);
				}
				if(count($nodes)>1){
					$nodes_result[] = $fields_result;
				}
			}
			if(count($nodes)>1){
				return $nodes_result;
			}
			else{
				return $fields_result;
			}
		}
	}
	
	//Función que obtiene una propiedad dado un id y un nombre de tabla
	function get_property_by_id($id, $id_name, $var, $table){
		if (is_null($id))
			return null;
		
		$result = db_query('SELECT '.$var.' FROM {'.$table.'} WHERE '.$id_name.'='.$id.';');
		$record = $result->fetchAll();
		$value = $record[0]->$var;
		return $value;
	}
	
	//Función que trae un término dado su tid
	function get_term_by_tid($tid){
		if(is_array($tid)){
			$result = array();
			foreach($tid as $id){
				$result[] = taxonomy_term_load($id)->name;
			}
		}
		else{
			$result = taxonomy_term_load($tid)->name;
		}
		return $result;
	}
	
	function get_parents($vid){
	  $tree = taxonomy_get_tree($vid,0);
		  $categorias = array();
		  $padres = array();
		  
		  foreach($tree as $elemento){
				 $tid = $elemento->tid;
				 $padres = taxonomy_get_parents($tid);
				 if(empty($padres) || count($padres) == 0)
						 #$categorias[$tid] = $tid;
			  $categorias[$tid] = $elemento->name;
		  }
	  return $categorias;
	}
	
	function get_term_children($tid){
	  //print_r("funciona");
	  $children = taxonomy_get_children($tid);
	  $hijos = array();
	  foreach($children as $elemento){
			 $tid = $elemento->tid;
			 $hijos[$tid] = $elemento->name;
	  }
	  
	  return $hijos;
	}
	
	/**
	 * Funcion para traer todo un vocabulario de taxonomia y formatearlo
	 * @var $vid -> id de taxonomia
	 */
	function get_all_taxonomy_tree($vid)
	{
		Global $base_url;
		
		$data = taxonomy_get_tree($vid);
		$padre = array();
		
		for ($i= 0; $i < count($data); $i++ )
		{
			if ($data[$i]->parents[0] == '0')
			{
				$key = $data[$i]->name;
				$padre[$key] = array();
				
				$hijos = array();
				for ($j = $i + 1; $j < count($data); $j++)
				{
					if ($data[$j]->parents[0] != 0){
						$hijos[] = array($data[$j]->name, $base_url.'/cursos/'.$data[$j]->name);
					}
					else
						break;
				}
				$padre[$key][0] = $base_url.'/cursos/'.$data[$i]->name;
				$padre[$key][1] = $hijos;
				$padre[$key][2] = $data[$i]->tid;
				$i = $j - 1; //optimizacion
			}
		}
		return $padre;
	}
	
	//Función que obtiene una foto de un usuario dado su uid
	function get_user_picture($uid){
		$picture = get_property_by_id($uid, 'uid', 'picture', 'users');
		if (is_numeric($picture)) {
			$picture = file_load($picture);
		}
		if (!empty($picture->uri)) {
			$filepath = $picture->uri;
			$picture = create_image_url($filepath);
		}
		return $picture;
	}
	
	function get_usuario_header($uid)
	{
		$user_fields = array('field_usuario_nombre','field_usuario_apellidos', 'field_usuario_numero_seguidores', 'field_usuario_numero_seguidos','field_usuario_roles');
		$privacidad = get_privacidad_usuario($uid); 					
		$results = get_user_fields($uid, $user_fields);
		$results['calc_usuario_nombre'] = $results['field_usuario_nombre'].' '.$results['field_usuario_apellidos'];
		$results['field_usuario_username'] = get_property_by_id($uid, 'uid', 'name', 'users');
		$results['field_usuario_imagen'] = get_user_picture($uid);
		$results['field_usuario_privacidad_perfil'] = $privacidad['field_usuario_privacidad_perfil'];
		$results['field_usuarios_privacidad_mensaj'] = $privacidad['field_usuarios_privacidad_mensaj'];
		
		return $results;
	}
	
	//Función que trae campos específicos de un usuario dado su uid
	function get_user_fields($uid, $user_fields, $array = null){

		$query = new EntityFieldQuery();
		$query->entityCondition('entity_type', 'user')
			->propertyCondition('uid', $uid);
		$result = $query->execute();
		
		if (isset($result['user'])) {
			$users = $result['user'];
			$fields_info = field_info_instances('user');     
			foreach($user_fields as $field){
				$field_id = $fields_info[$field]['field_id'];
				field_attach_load('user', $users, FIELD_LOAD_CURRENT, array('field_id' => $field_id));
			}
			if($array == null){
				$array = array();
			}
			foreach($users as $user){
				foreach($user_fields as $field){
					$value = field_get_items('user', $user, $field);
					$array[$field] = $value[0]['value'];
					if(isset($value[0]['value2'])){	//Por ejemplo en el caso de una fecha final, esta aparecerá como 'value2'
						
						$array[$field.'_value2'] = $value[0]['value2'];
					}
					
				}
			}
		}
		return $array;
	}
	
	//Función que trae la información que se muestra en el perfil de usuario, según la privacidad de cada sección
	function get_usuario_info($uid){
		//$fields = array('field_usuario_privacidad_persona', 'field_usuario_privacidad_contact', 'field_usuario_privacidad_social', 'field_usuario_privacidad_prof');
		//$privacidad = get_user_fields($uid, $fields);
		$privacidad = get_privacidad_usuario($uid);

		//print_r($privacidad);
		$result = array();
		if(!is_numeric($privacidad['field_usuario_privacidad_persona']) || $privacidad['field_usuario_privacidad_persona'] == 1){
			$fields = array('field_usuario_fecha_nacimiento');
			$result = get_user_fields($uid, $fields, $result);
		}
		if(!is_numeric($privacidad['field_usuario_privacidad_contact']) || $privacidad['field_usuario_privacidad_contact'] == 1){
			$fields = array('field_usuario_correo', 'field_usuario_telefono_casa', 'field_usuario_telefono_oficina', 'field_usuario_telefono_otro', 'field_usuario_username_skype', 'field_usuario_username_facebook', 'field_usuario_username_google', 'field_usuario_sitio_web');
			$result = get_user_fields($uid, $fields, $result);
		}
		if(!is_numeric($privacidad['field_usuario_privacidad_social']) || $privacidad['field_usuario_privacidad_social'] == 1){
			$fields = array('field_usuario_url_linkedin', 'field_usuario_url_facebook', 'field_usuario_url_google_plus', 'field_usuario_url_twitter');
			$result = get_user_fields($uid, $fields, $result);
		}
		
		$result['field_usuario_privacidad_persona'] = $privacidad['field_usuario_privacidad_persona'];
		$result['field_usuario_privacidad_contact'] = $privacidad['field_usuario_privacidad_contact'];
		$result['field_usuario_privacidad_social'] = $privacidad['field_usuario_privacidad_social'];
		$result['field_usuario_privacidad_perfil'] = $privacidad['field_usuario_privacidad_perfil'];				
		return $result;
	}
	
	//Función que trae la información que se muestra en el perfil de una empresa, según la privacidad de cada sección
	function get_empresa_info($uid){		
		//$fields = array('field_usuario_privacidad_contact', 'field_usuario_privacidad_social', 'field_usuario_privacidad_prof');
		//$privacidad = get_user_fields($uid, $fields);
		$privacidad = get_privacidad_usuario($uid);

		get_usuario_direccion($uid);
		
		$result = array();

		if(!is_numeric($privacidad['field_usuario_privacidad_contact']) || $privacidad['field_usuario_privacidad_contact'] == 1 ){
			$fields = array('field_empresa_correo', 'field_empresa_telefono', 'field_usuario_username_skype', 'field_usuario_username_facebook', 'field_usuario_username_google', 'field_usuario_sitio_web');
			$result = get_user_fields($uid, $fields, $result);
			$result['calc_usuario_direccion'] = get_usuario_direccion($uid);
		}
		if(!is_numeric($privacidad['field_usuario_privacidad_social']) || $privacidad['field_usuario_privacidad_social'] == 1){
			$fields = array('field_usuario_url_linkedin', 'field_usuario_url_facebook', 'field_usuario_url_google_plus', 'field_usuario_url_twitter');
			$result = get_user_fields($uid, $fields, $result);
		}
		
		$result['field_empresa_privacidad_contact'] = $privacidad['field_usuario_privacidad_contact'];
		$result['field_empresa_privacidad_social'] = $privacidad['field_usuario_privacidad_social'];
		$result['field_empresa_privacidad_perfil'] = $privacidad['field_usuario_privacidad_perfil'];
		
		return $result;
	}
	
	//Función que trae la dirección de un usuario por su uid
	function get_usuario_direccion($uid){
		$result = get_direcciones($uid);
		
		if ($result != false)
		{
			$result = array_pop($result);
			
			$interior = "";
			if ($result['ninterior'])
				$interior = " int. ".$result['ninterior'];
			$cp = "";
			if ($result['cp'])
				$cp = " C.P. ".$result['cp'];			
			$result = $result['calle'].$result['nexterior'].$interior." ".$result['colonia']." ".$result['ciudad']." ".$result['estado']." ".$result['pais'].$cp;  
			
		}else
			return null;
		return($result);		
	}
	
	//Función que trae la información profesional y académica que se muestra en el perfil de usuario, según la privacidad de cada sección
	function get_usuario_prof_info($uid){ 
		//$fields = array('field_usuario_privacidad_prof', 'field_usuario_privacidad_academi');
		//$privacidad = get_user_fields($uid, $fields);
		$privacidad = get_privacidad_usuario($uid);

		$result = array();
		if(!is_numeric($privacidad['field_usuario_privacidad_prof']) || $privacidad['field_usuario_privacidad_prof'] == 1){
			$fields = array('field_usuario_empresa');
			$result = get_user_fields($uid, $fields, $result);
		}
		if(!is_numeric($privacidad['field_usuario_privacidad_academi']) || $privacidad['field_usuario_privacidad_academi'] == 1){
			$fields = array('field_usuario_escuela');
			$result = get_user_fields($uid, $fields, $result);
		}

		$result['field_usuario_privacidad_prof'] = $privacidad['field_usuario_privacidad_prof'];
		$result['field_usuario_privacidad_academi'] = $privacidad['field_usuario_privacidad_academi'];
		$result['field_usuario_privacidad_perfil'] = $privacidad['field_usuario_privacidad_perfil'];
		
		return $result;
	}
	
	//Función que trae la información profesional y académica que se muestra en el perfil de usuario, según la privacidad de cada sección
	function get_empresa_acerca($uid){ 
		$fields = array('field_empresa_nosotros', 'field_empresa_mision','field_empresa_vision');
		$result = get_user_fields($uid, $fields);
		return $result;
	}		
	
	//Función que obtiene los permisos de privacidad de un usuario
	function get_privacidad_usuario($uid){
		/*global $user;
		$actual_uid = $user->uid;
		//$actual_uid = 3;*/
		$result = array();
		$fields = array('field_usuario_privacidad_prof', 'field_usuario_privacidad_academi','field_usuario_privacidad_contact','field_usuario_privacidad_persona','field_usuarios_privacidad_mensaj','field_usuario_privacidad_social','field_usuario_privacidad_perfil');
		
		/*if ($actual_uid == $uid) //Un usuario esta consultando sus propios datos
		{
			foreach ($fields as $field) {
				$result[$field] = "1";
			}
		}else{*/
			$result = get_user_fields($uid, $fields);
		//}

		return($result);
		
	}
	
	//Función que trae información de los tutores de un curso, dado su nid
	function get_tutores($nid, $type, $user_fields){
		if($type == 'curso')
			$field = 'field_curso_profesores';
		if($type == 'canal')
			$field = 'field_canal_tutores';
		$fields = array($field);
		$tutores = get_fields_by_nid($nid, $fields, $type);
		if($tutores == null)
			return array();
		
		if ($tutores[$field] == null)
		{
			return array();
		}
		if (count($tutores[$field]) > 1){
			$tutores = $tutores[$field];
		}	
			$result = array();
			foreach($tutores as $tutor){
				$array = get_user_fields($tutor, $user_fields);
				$array['calc_nombre_tutor'] = $array['field_usuario_nombre'].' '.$array['field_usuario_apellidos'];
				$username = get_property_by_id($tutor, 'uid', 'name', 'users');
				$array['link_nombre_tutor'] = create_urls('user', $username);
				$array['uid_tutor'] = $tutor;
				if(in_array('picture', $user_fields))
					$array['field_tutor_imagen'] = get_user_picture($tutor);
				$result[] = $array;
			}
		return $result;
	}
	
	//Función que crea URLs dado un tipo de entidad y un parámetro
	function create_urls($tipo, $parametro){
		global $base_url;
		switch($tipo){
			case 'node':
				$url = drupal_get_path_alias($base_url.'/node/'.$parametro);		//$parametro = nid
				break;
			case 'user':
				$url = $base_url.'/usuario/'.$parametro;				//$parametro = username
				break;
			case 'taxonomy':
				$url =  drupal_get_path_alias($base_url.'/taxonomy/term/'.$parametro);	//$parametro = tid
				break;
		}
		return $url;
	}
	
	//Función que regresa un URL de imagen, dado el path guardado en BD
	function create_image_url($image_path){
		$url = str_replace('public:/', base_path().'sites/default/files', $image_path);
		return $url;
	}
	
	//Función que calcula la duración de un curso en semanas, dada una fecha inicial y una final
	function calculate_weeks($date_start, $date_end){
		$num_days = abs($date_start - $date_end)/60/60/24;
		$num_weeks = $num_days/7;
		if ( is_numeric( $num_weeks ) && strpos( $num_weeks, '.' )){
			$num_weeks = round($num_weeks, 1);
		}
		if($num_weeks == 1)
			$num_weeks = $num_weeks.' '.SEMANA;
		else
			$num_weeks = $num_weeks.' '.SEMANAS;
		return $num_weeks;
	}
	
	//Función que da el formato a un precio
	function format_precio($precio){
		return '$'.number_format($precio).' MXN';
	}
	
	//Función que regresa el costo total de un curso, con descuento aplicado
	function get_costo_total($costo, $descuento){
		if(isset($descuento)){
			$descuento = (float)(100 - $descuento) / 100;
			$costo = (float)$costo;
			$costo_total = $costo * $descuento;
			return format_precio($costo_total);
		}
		else
			return format_precio($costo);
	}
	
	//Funcion para guardar otros intereses de un usuario
	function insert_interes($name,$uid){
		$insert = db_insert('intereses_otros')
		->fields(array(
			'nombre' => $name,
			'entity_id' => $uid,
			'fecha' => date('Y-m-d H:m:s'), 
		))
		->execute();
        
	}
	
	//Funcion para guardar las cuentas de deposito de un usuario
	function insert_cuenta_deposito($tipo,$alias,$banco,$titular,$cuenta,$clabe,$paypal,$uid){
		$insert = db_insert('cuentas_deposito')
		->fields(array(
			'tipo' => $tipo,
			'alias' => $alias,
			'banco' => $banco,
			'titular' => $titular,
			'cuenta' => $cuenta,
			'clabe' => $clabe,
			'paypal' => $paypal,
			'entity_id' => $uid, 
		))
		->execute();
        
	}
	
	//Funcion para guardar los datos de pago de un usuario
	function insert_datos_pago($alias,$tarjeta,$tipo,$nombre,$fecha,$codigo,$uid){
		$insert = db_insert('datos_pago')
		->fields(array(
			'alias' => $alias,
			'tarjeta' => $tarjeta,
			'tipo' => $tipo,
			'nombre' => $nombre,
			'fecha_vencimiento' => $fecha,
			'codigo' => $codigo,
			'entity_id' => $uid, 
		))
		->execute();
        
	}

	function update_all_aliases()
	{
		module_load_include('inc', 'pathauto');
		module_load_include('inc', 'pathauto.pathauto');
	      
		// Delete the existing node aliases.
		/*db_delete('url_alias')
		  ->condition('source', 'node/%', 'LIKE')
		  ->execute();
	      
		// Regenerate the node aliases.
		$nids = db_query("SELECT nid FROM {node}")->fetchCol();
		pathauto_node_update_alias_multiple($nids, 'bulkupdate');
		*/
		// Delete the topics taxonomy aliases.
		db_delete('url_alias')
		  ->condition('source', 'taxonomy/term/%', 'LIKE')
		  ->execute();
	      
		// Regenerate the taxonomy aliases.
		$tids = db_query("SELECT tid FROM {taxonomy_term_data}")->fetchCol();
		pathauto_taxonomy_term_update_alias_multiple($tids, 'bulkupdate');
		
	}
	
	function search_nodes_by_string($cadena)
	{
		//$parts = preg_split(  "/[\s,]*\\\"([^\\\"]+)\\\"[\s,]*|" . "[\s,]*'([^']+)'[\s,]*|" . "[\s,]+/" , $cadena );
		$parts = preg_split(  "/[:;.,[:space:]]/"  , $cadena );
		//$parts = preg_split(  '/(<(?:[^<>]+(?:"[^"]*"|\'[^\']*\')?)+>)/' ,
		//print_r($parts);
		//print_r("<br>");
		
		$query = " ";
		foreach ($parts as $key)
		{
			if (strlen($key) <= 2 || $key == '')
				continue;
			
			if (trim($query) != '')
				$query .= " OR ";
			
			$query .= "word LIKE '%".$key."%'";
		}
		
		$query = "SELECT distinct(sid) as nid FROM search_index WHERE ".$query.";";
		
		$query .= " UNION SELECT distinct(sid) as nid FROM search_dataset WHERE data LIKE '%.$cadena.%'";
		
		$result = db_query($query);
		$record = $result->fetchAll();
		
		
		return $record;		

	}

	/*
	*	get_nodes_by_fields (int, string, array, array)
	*	autor: Simon Martinez
	*	simon@playfulinteracte.com
	*	Obtiene información específica de nodos
	*	de un content type creados por un usuario dado
	*
	*	$uid int
	*	Id de usuario del que se desea consultar nodos
	*	
	*	$content_type string
	*	Nombre del bundle ('curso', 'canal', 'direccion')
	*
	*	$fields
	*	Nombre de los campos (machine_names) que deseemos
	*	consultar ordenados en un arreglo con estructura
	*	simmple (array('field1', 'field2'))
	*
	*	$conditions
	*	Se enlistan en un arreglo los campos y las variables
	*	que se quieran condicionar. Por lo pronto la condicion
	*	es de igualdad solamente y sobre los campos que sean
	*	definidos por usuario y no relacionados a taxonomias.
	*	
	*	return array()
	*	Un arreglo ordenado por indices con los $nid.
	*	Cada posicion del arreglo representa un objeto con
	*	los campos[nid],[vid],[type], además de los campos
	*	solicitados en $fields ad sus valores
	*	correspondientes.
	*													
	*/
	function get_nodes_by_fields($uid = FALSE, $content_type = '', $fields = array(), $conditions = array())
	{
		if($uid == FALSE || $content_type == '' || count($fields)==0 )
			return FALSE;

		//Se consulta la entidad con condiciones básicas
		$query=new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node');
		$query->entityCondition('bundle', $content_type);
    if($uid > 0)
			$query->propertyCondition('uid', $uid);
		if(count($conditions)>0)
			foreach($conditions as $key => $c)
				$query->fieldCondition($key, 'value', $c, '=');	
    //->propertyCondition('status', 1)
    $query ->range(0, 20);
		$result = $query->execute();

		if (isset($result['node']))
		{
			$nodes = $result['node'];
			//Se obtiene la información de los campos del content type
			$fields_info = field_info_instances('node', $content_type);
			//Se llena el arreglo $nodes con información sólo de campos indicados en $fields
			foreach($fields as $f)
				field_attach_load('node', $nodes, FIELD_LOAD_CURRENT, array('field_id'=>(string)$fields_info[$f]['field_id']));
			
			return $nodes;
		}
		else
			return FALSE;
	}
	
	
	/*function get_term_children($tid){
  //print_r("funciona");
  $children = taxonomy_get_children($tid);
  $hijos = array();
  foreach($children as $elemento){
                 $tid = $elemento->tid;
                 $hijos[$tid] = $elemento->name;
  }
  
  print_r($hijos);
}*/
