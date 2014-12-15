<?php


  /*function get_data_from_service($data, $debug)
  {
      Global $base_url;
      
      $result = drupal_http_request($base_url.'/api'.$data);
      $data = json_decode($result->data);
      
      if ($debug)
          var_dump($data);
          //print_r($data);
      
      return $data;
  }*/
    
    
  function ajax_dropdown_callback($form, &$form_state) {
    return $form['descripcion_objetivo']['selSubcategoria'];
  }



  /*function get_parents($vid)
  {
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
  }*/
  
  
  
function debugging($valores)
{
  $json = json_encode($valores);
  /*$data = 'f_name=insert_log&mod=creacioncurso&func=submit&cont=tal';
  $options = array(
                'method' => 'get',
                'data' => $data,
                'headers' => array(),
              );
  
  drupal_http_request('http://localhost/mi_futureEd/api?', $options);*/
  
  //drupal_http_request('http://localhost/mi_futureEd/api?f_name=insert_log&mod=creacioncurso&func=submit&cont=tal');
  //cURL('http://localhost/mi_futureEd/api?f_name=insert_log&mod=creacioncurso&func=submit&cont=tal');
  
  /*
  $curl = curl_init('http://localhost/mi_futureEd/api?f_name=insert_log&mod=creacioncurso&func=submit&cont='.$json);
  $result = curl_exec($curl);
  curl_close();
  */
  
  $insert = db_insert('custom_log')
		->fields(array('vc_module', 'vc_function','vc_content','dt_date'))
    ->values(array(
              'vc_module' => $module,
              'vc_function' => $func,
              'vc_content' => $json,
							'dt_date' => date('Y-m-d H:i:s'),
            ));
        $insert->execute();
  
}
  function agregar_nueva_pregunta($pregunta, $respuesta, $nid)
  {
     $fe_id = db_insert('preguntas_frecuentes')
                ->fields(array(
                  'pregunta' => $pregunta,
                  'respuesta' => $respuesta,
                          'entity_id' =>$nid ,
                ))
                ->execute();
  }
  
  function get_cuentas_deposito_usuario($uid)
  {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'cuenta_de_deposito')
      ->propertyCondition('uid', $uid)
      //->fieldCondition('field_news_publishdate', 'value', $year . '%', 'like')
      //->fieldOrderBy('field_photo', 'fid', 'DESC')
      ->range(0, 10);
      $result = $query->execute();
      
      /*EJEMPLO DE CARGAR NODO CON SOLO ALGUNOS CAMPOS*/
      /*if (isset($result['node'])) {
        $stories = $result['node'];
       
        // At first we need to get field's id. If you already know field id, you can ommit this step
        // Get all fields attached to a given node type
        $fields = field_info_instances('node', 'story');
       
        // Get id of body field
        $field_id = $fields['field_story_image']['field_id'];
       
        // Attach a field of selected id only to get value for it
        field_attach_load('node', $stories, FIELD_LOAD_CURRENT, array('field_id' => $field_id));
      }*/
    if(count($result) > 0)
    {
      foreach($result['node'] as $nid)
        $nids[] = $nid->nid;

      unset($query,$result);
      $result = db_query("SELECT nid, title FROM {node} WHERE nid IN (:nids )", array(':nids'=>$nids));
      $records = $result->fetchAllKeyed();
      return $records;
    }
    else
      return array('0'=>'Sin cuentas de depósito');
  }
	
  /*Obtiene informacion sobre la tabla datos especificos para poblar los checkbox*/
	function get_datos_especificos($nid)
	{
    if($nid > 0)
    {
      $result = db_select('curso_datos_especificos', 'c')
      ->fields('c',array('id_dato','i_grupo'))
      ->condition('entity_id', $nid,'=')
      ->execute()
      ->fetchAllKeyed();
      //->fetchAllAssoc('i_grupo');
      
      $datos=array();
      foreach($result as $key => $value)
          $datos[$value][]=$key;
          
      
      return $datos; 
  
    }
  }
  
  /*Consulta la informacion de un archivo dado su fic. Nombre y uri*/
  function get_file_information($fid)
  {
    $result = db_select('file_managed', 'f')
    ->fields('f', array('filename','uri'))
    ->condition('fid', $fid, '=')
    ->execute()
		->fetchAssoc();
    return $result;
  }
  
  /*Elimina el archivo actual de la forma, retirando por ajax el link Archivo Actual*/
  function crearcurso_remove_file_callback($form, &$form_state)
  {
    //debugging($form_state['values']['current_file_var']);
    $file = file_load(variable_get($form_state['values']['current_file_var'], ''));
    //debugging($file);
    if ($file->fid)
      file_delete($file, TRUE);

          
    variable_set($form_state['values']['current_file_var'], '');
    unset($form_state['values']['current_file_var']);    
    unset($form['lblArchivoExistente']);
    unset($form['remove_file']);
    //unset($form['imagen_video']);
    
    return array();
  }

  //Retira el botón upload del campo de archivo
  function crearcurso_element_process($element, &$form_state, $form)
  {
    $element = file_managed_file_process($element, $form_state, $form);
    $element['upload_button']['#access'] = FALSE;
    return $element;
  }
  
  //Función que trae las preguntas frecuentes para el Formulario de Preguntas Frecuentes
  function get_preguntas_frecuentes_edit($nid)
	{
    $values = array();
    if($nid > 0)
    {
      $result = db_query("SELECT id_pregunta, pregunta, respuesta FROM {preguntas_frecuentes} WHERE entity_id = ".$nid." AND status = 1;");
      $preguntas_array = $result->fetchAll();
      if( count($preguntas_array)>0 )
      {      
        $pre_values = array();
        foreach($preguntas_array as $p)
        {
          $pre_values['txtPreguntaFrecuente'] = $p->pregunta;
          $pre_values['txtIdPreguntaFrecuente'] = $p->id_pregunta;
          $pre_values['txtRespuestaPreguntaFrecuente'] = $p->respuesta;
          $values[] = $pre_values;
          unset($preguntas_array,$pre_values);
        }
      }
    }    
		return $values;
	}
  
  //Obtiene la informacion para el formulario de Descripcion y Objetivo de Curso
  function get_descripcion_objetivo_values($nid)
  {
    $node = node_load($nid);
    $values = array();
    if ($node != NULL)
    {
      $values['titulo'] = $node->title != NULL ? $node->title : NULL;
      $values['txtDescripcion'] = $node->field_curso_descripcion[$node->language][0]['value'] != NULL ? $node->field_curso_descripcion[$node->language][0]['value'] : NULL;
      $values['txtObjetivo'] = $node->field_curso_objetivo[$node->language][0]['value'] != NULL ? $node->field_curso_objetivo[$node->language][0]['value'] : NULL;
      $values['txtAudiencia'] = $node->field_curso_audiencia[$node->language][0]['value'] != NULL ? $node->field_curso_audiencia[$node->language][0]['value'] : NULL;
      $values['selCategoria'] = $node->field_categoria[$node->language][0]['tid'] != NULL ? $node->field_categoria[$node->language][0]['tid'] : NULL;
      $values['selSubcategoria'] = $node->field_subcategoria[$node->language][0]['tid'] != NULL ? $node->field_subcategoria[$node->language][0]['tid'] : NULL;
      $values['selIdioma'] = $node->field_curso_idioma[$node->language][0]['tid'] != NULL ? $node->field_curso_idioma[$node->language][0]['tid'] : NULL;
    }
    return $values;
  }
  
  //Obtiene la informacion para el formulario de Detalles de Curso
  function get_detalles_curso_values($nid)
  {
    $values = array();
    if($nid > 0)
    {
      $node = node_load($nid);
      if ($node != NULL)
      {
        $values['txtTemario'] = $node->field_curso_temario[$node->language][0]['value'] != NULL ? $node->field_curso_temario[$node->language][0]['value'] : NULL;
        $values['txtMetodologia'] = $node->field_curso_metodologia[$node->language][0]['value'] != NULL ? $node->field_curso_metodologia[$node->language][0]['value'] : NULL;
        $values['selModalidad'] = $node->field_curso_modalidad[$node->language][0]['tid'] != NULL ? $node->field_curso_modalidad[$node->language][0]['tid'] : NULL;
        $values['selAcreditacion'] = $node->field_curso_acreditacion[$node->language][0]['value'] != NULL ? $node->field_curso_acreditacion[$node->language][0]['value'] : NULL;
        $values['chkColaboracion'] = $node->field_curso_colaboracion[$node->language][0]['value'] != NULL ? $node->field_curso_colaboracion[$node->language][0]['value'] : NULL;
        $values['radLimiteAlumnos'] = $node->field_curso_limite_alumnos[$node->language][0]['value'] != NULL ? $node->field_curso_limite_alumnos[$node->language][0]['value'] : NULL;
        $values['txtNumeroAlumnos'] = $node->field_curso_numero_alumnos[$node->language][0]['value'] != NULL ? $node->field_curso_numero_alumnos[$node->language][0]['value'] : NULL;
        $values['selFechaImparticion'] = $node->field_curso_fechas_imparticion[$node->language][0]['value'] != NULL ? $node->field_curso_fechas_imparticion[$node->language][0]['value'] : NULL; 
        $values['selDuracionCurso'] = $node->field_curso_duracion[$node->language][0]['value'] != NULL ? $node->field_curso_duracion[$node->language][0]['value'] : NULL;
        $values['txtSemanal'] = $node->field_curso_horas_semana[$node->language][0]['value'] != NULL ? $node->field_curso_horas_semana[$node->language][0]['value'] : NULL;
        $values['selCaducidad'] = $node->field_curso_caducidad[$node->language][0]['value'] != NULL ? $node->field_curso_caducidad[$node->language][0]['value'] : NULL;
        $values['txtReqPrevios'] = $node->field_curso_requerimientos[$node->language][0]['value'] != NULL ? $node->field_curso_requerimientos[$node->language][0]['value'] : NULL;  
        $values['txtTotales'] = $node->field_curso_horas_totales[$node->language][0]['value'] != NULL ? $node->field_curso_horas_totales[$node->language][0]['value'] : NULL;  
        if (count($node->field_curso_fecha)>0)
        {
          $txt_inicio = $node->field_curso_fecha[$node->language][0]['value'] != NULL ? $node->field_curso_fecha[$node->language][0]['value'] : NULL;;
          $fecha_inicio = date("Y-m-d",(int)$txt_inicio);
          $values['fecha_inicio']= explode('-',$fecha_inicio);

          $txt_fin = $node->field_curso_fecha[$node->language][0]['value2'] != NULL ? $node->field_curso_fecha[$node->language][0]['value2'] : NULL;
          $fecha_fin = date("Y-m-d",(int)$txt_fin);
          $values['fecha_fin'] = explode('-',$fecha_fin);
        }
        $values['txtModuloCertificado'] = $node->field_curso_modulo_certificado[$node->language][0]['value'] != NULL ? $node->field_curso_modulo_certificado[$node->language][0]['value'] : NULL;
      }
    }
    return $values;
  }
  
  //Obtiene la informacion para el formulacion de Evaluacion
  function get_evaluacion_values($nid)
  {
    $values = array();
    if($nid > 0)
    {
      $node = node_load($nid);
      if ($node != NULL)
      {
        $values['profesores'] = $node->field_curso_profesores[$node->language][0]['value'] != NULL ? $node->field_curso_profesores[$node->language][0]['value'] : NULL;
        $values['txtEvaluacion'] = $node->field_curso_evaluacion[$node->language][0]['value'] != NULL ? $node->field_curso_evaluacion[$node->language][0]['value'] : NULL;
        $values['radTutoreo'] = $node->field_curso_tutoreo[$node->language][0]['value'] != NULL ? $node->field_curso_tutoreo[$node->language][0]['value'] : NULL;  
      }
    }
    return $values;
  }
  
  //Obtiene la informacion para el formulario de Imagen y Video
  function get_imagen_video_values($nid)
  {
    $values = array();
    if($nid > 0)
    {
      $node = node_load($nid);
      print_r($node);
      //$fid = 0;
      $values['fid'] = 0;
      //we use variable_get function wich pulls information of a file already uploaded
      if (count($node->field_curso_imagen)>0)
      {
        $values['fid'] = variable_get('image_fid_'.$nid);
        //$display_file = get_file_information($values['fid']);
        $values['display_file'] = get_file_information($values['fid']);
        //$uri=$GLOBALS['base_url'].'/sites/default/files/cursos/images/'.$display_file['filename'];
        $values['uri'] = $GLOBALS['base_url'].'/sites/default/files/cursos/images/'.$values['display_file']['filename'];
      }
        
      if (count($node->field_curso_video)>0)
        $values['txtVideo'] = $node->field_curso_video[$node->language][0]['value'] != NULL ? $node->field_curso_video[$node->language][0]['value'] : NULL; 
    }
    return $values;
  }
  
  //Obtiene la informacion para formulario de Bibliografía y Recomendaciones
  function get_bibliografia_values($nid)
  {
    if($nid > 0)
    {
      $node = node_load($nid);
 
      $values['txtBibliografiaOficial'] = $node->field_curso_bibliografia_oficial[$node->language][0]['value'] != NULL ? $node->field_curso_bibliografia_oficial[$node->language][0]['value'] : NULL;
      $values['txtBibliografiaRecomendada'] = $node->field_curso_bibliografia_re[$node->language][0]['value'] != NULL ? $node->field_curso_bibliografia_re[$node->language][0]['value'] : NULL;
      
      //VERFICAR FORMA DE DESPLEGAR LOS PRODUCTOS EN LISTA, COMO TEXTO NO EN LOS CAMPOS
      //$values['productos'] = $node->field_curso_productos['und'][0]['value'] != NULL ? $node->field_curso_productos['und'][0]['value'] : NULL;
    }
    return $values;
  }
  
  //Obtiene la informacion para el formulario de Configuración de Pagos
  function get_configuracion_pagos_values($nid)
  {
    $values = array();
    if($nid > 0)
    {
      $node = node_load($nid);
      //print_r($node);
      $values['chkCursoGratuito'] = $node->field_curso_gratuito[$node->language][0]['value'] != NULL ? $node->field_curso_gratuito[$node->language][0]['value'] : NULL;
      $values['txtCostoCurso'] = $node->field_curso_costo[$node->language][0]['value'] != NULL ? $node->field_curso_costo[$node->language][0]['value'] : NULL;
      $values['txtDescuentoCurso'] = $node->field_curso_descuento[$node->language][0]['value'] != NULL ? $node->field_curso_descuento[$node->language][0]['value'] : NULL;
      $values['chkDonacion'] = $node->field_curso_donacion[$node->language][0]['value'] != NULL ? $node->field_curso_donacion[$node->language][0]['value'] : NULL;
      $values['txtMontoDonacion'] = $node->field_curso_donativo[$node->language][0]['value'] != NULL ? $node->field_curso_donativo[$node->language][0]['value'] : NULL;
      $values['selCuentaDeposito'] = $node->field_curso_cuenta_deposito[$node->language][0]['value'] != NULL ? $node->field_curso_cuenta_deposito[$node->language][0]['value'] : NULL;
      $values['btnFiscal'] = $node->field_curso_comprobante_fiscal[$node->language][0]['value'] != NULL ? $node->field_curso_comprobante_fiscal[$node->language][0]['value'] : NULL;
      
      $values['fid'] = 0;
      
      if (count($node->field_curso_csd)>0)
      {
        //$values['filCSD'] = variable_get($nid.'_csd_fid');
        $values['fid'] = variable_get('csd_fid_'.$nid);
        //$_SESSION['node']['fid'] = $nid.'_csd_fid';
        //$display_file = get_file_information($fid);
        $values['display_file'] = get_file_information($values['fid']);
        //$uri=$GLOBALS['base_url'].'/sites/default/files/cursos/'.$display_file['filename'];
        $values['uri']=$GLOBALS['base_url'].'/sites/default/files/cursos/'. $values['display_file']['filename'];
      }
    }
    return $values;
  }
  
  /*Obtiene el listado de los de los canales creados por un usuario dado*/
  function get_canales_by_user($uid)
  {
    $nodes = get_nodes_by_fields($uid, 'canal', array('field_canal_imagen','field_canal_nombre'));
    //TODO el índice und de lenguaje está hardcode, debería tener el correspondiente... como node->language
    if($nodes != FALSE && count($nodes)>0)
      foreach($nodes as $key => $c )
        $data[$key] = array('nid'=>$c->nid,'imagen'=>$c->field_canal_imagen['und'][0]['value'],'nombre'=>$c->field_canal_nombre['und'][0]['value']);
    else
      $data = FALSE;
    
    return $data;   
  }
  
  /*Obtiene los canales de los un usuario dado es administrador*/
  function get_canales_by_admin($uid)
  {
    $nodes = get_nodes_by_fields(-1, 'canal', array('field_canal_imagen','field_canal_nombre'), array('field_canal_admin'=>$uid)) ;
    if($nodes != FALSE && count($nodes)>0)
      foreach($nodes as $key => $c )
        $data[$key] = array('nid'=>$c->nid,'imagen'=>$c->field_canal_imagen['und'][0]['value'],'nombre'=>$c->field_canal_nombre['und'][0]['value']);
    else
      $data = FALSE;
    
    return $data;
  }
  
  /*Obtiene el valor del canal al que pertenece el curso*/
  function get_canal_values($nid)
  {
		$values = array();
    if($nid > 0)
    {
      $node = node_load($nid);
      $values['hCanalSeleccionado'] = $node->field_curso_canal[$node->language][0]['value'] != NULL ? $node->field_curso_canal[$node->language][0]['value'] : NULL;
    }
    return $values;
  }
  
  
  /*Obtiene los valores para el poblar el formulario de LMS*/
  function get_configuracion_LMS_values ($nid)
  {
    $values = array();
    if($nid > 0)
    {
      $node = node_load($nid);
      
      $values['chkContenidoFed'] = $node->field_curso_interno[$node->language][0]['value'] != NULL ? $node->field_curso_interno[$node->language][0]['value'] : NULL;
      $values['chkSoporte'] = $node->field_curso_soporte_tecnico[$node->language][0]['value'] != NULL ? $node->field_curso_soporte_tecnico[$node->language][0]['value'] : NULL ;
      $values['txtURLCallback'] = $node->field_curso_url_callback[$node->language][0]['value'] != NULL ? $node->field_curso_url_callback[$node->language][0]['value'] : NULL;
      $values['txtIdCurso'] = $node->field_curso_id[$node->language][0]['value'] != NULL ?  $node->field_curso_id[$node->language][0]['value'] : NULL;
      $values['txtURLPortal'] = $node->field_curso_url_portal[$node->language][0]['value'] != NULL ? $node->field_curso_url_portal[$node->language][0]['value'] : NULL;
      $values['txtURLLMS'] = $node->field_curso_url_lms[$node->language][0]['value'] != NULL ? $node->field_curso_url_lms[$node->language][0]['value']: NULL;
      $values['txtEmailResponsable'] = $node->field_curso_correo_responsable[$node->language][0]['value'] != NULL ? $node->field_curso_correo_responsable[$node->language][0]['value'] : NULL;
    }
    return $values;
  }

	
	
  
