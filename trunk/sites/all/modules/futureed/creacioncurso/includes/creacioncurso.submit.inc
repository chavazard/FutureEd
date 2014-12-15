<?php

/**
 * @file 
 * Handles the form submission of the customer survey form
 */


/**
 * Handles what to do with the submitted form depending on what stage has been
 * completed.
 * 
 * @see creacioncurso_form()
 * @see creacioncurso_form_validate()
 * 
 * @param type $form
 * @param type $form_state 
 */
function creacioncurso_form_submit($form, &$form_state) {
  
  //print_r($form_state['stage']);
  //print_r("este es el stage ");
  switch ($form_state['stage']) {
    
    //Si se está en el paso final del formulario:
    case 'configuracion_LMS':
      $nid = 0;
      if(isset($form['nid']['#value']) || $form['nid']['#value'] > 0)  
        $nid = $form['nid']['#value'];
      
      if(isset($_SESSION['node']['nid']) && $_SESSION['node']['nid'] > 0)
        $nid = $_SESSION['node']['nid'];
      
      if($nid == 0)  
      {
        unset($node);
        $node = new stdClass(); 
        $node->title = $valores['titulo']; //título del nodo
        
        $node->type = "curso"; // este debe ser el machine_name del content type
        node_object_prepare($node);
        $node->language = LANGUAGE_NONE;
        $node->uid = $user->uid; 
        $node->status = 1; //(1 or 0): publicado automaticamente
        $node->promote = 0; //(1 or 0): desabilitado para página principal
        $node->comment = 0; // comentarios sobre el nodo deshabilitados
        $form['nid']['#value'] = $node->nid;
      }elseif($nid > 0)
        $node = node_load($nid); 
        
      $node->field_curso_interno[$node->language][0]['value'] = $form_state['values']['chkContenidoFed'];
      $node->field_curso_soporte_tecnico[$node->language][0]['value'] = $form_state['values']['chkSoporte'];
      $node->field_curso_url_callback[$node->language][0]['value'] = $form_state['values']['txtURLCallback'];
      $node->field_curso_id[$node->language][0]['value'] = $form_state['values']['txtIdCurso'];
      $node->field_curso_url_portal[$node->language][0]['value'] = $form_state['values']['txtURLPortal'];
      $node->field_curso_url_lms[$node->language][0]['value'] = $form_state['values']['txtURLLMS'];
      $node->field_curso_correo_responsable[$node->language][0]['value'] = $form_state['values']['txtEmailResponsable'];

      node_save($node);
      $nid = $node->nid;
      unset ($node);
      
      //Se guardan todos los valores del formulario
      $form_state['multistep_values'][$form_state['stage']] = $form_state['values'];
      //Se valida que se haya llegado al final del formulario sin haber dado click al boton de "back"
      if ($form_state['triggering_element']['#value'] != 'back') {
        //Se ejecuta una función custom que permitirá hacer los pasos necesarios antes de hacer el form submit.
        creacioncurso_personal_details_submit($form, $form_state);
        //Se setea la variable que identifica que el formulario está en el último paso
        $form_state['complete'] = TRUE;
      }
     break;
    
    //En caso de que no se esté en el último paso, simplemente agregamos las variables que se usaron en el paso anterior al arreglo de variables
    //que guarda todas las variables del formulario.
    default:
      //Aquí se pueden gardar los datos del paso anterior
      guardar_valores_paso_anterior($form, $form_state['stage'],$form_state['values']);

      $form_state['multistep_values'][$form_state['stage']] = $form_state['values'];
      
      /*print_r("<br> Stage:");
      print_r($form_state['triggering_element']);
      print_r("<br>");
*/
      //if ($form_state['triggering_element']['#id'] == 'edit-save')
      print_r("<br>este es el trigger:");
      print_r($form_state['triggering_element']['#id']);
      print_r("<br>");
      if ($form_state['triggering_element']['#id'] == 'edit-next')
          $form_state['new_stage'] = creacioncurso_move_to_next_stage($form, $form_state);

     break;
 
  } 

  //Si el formulario está completo, redirecciona a la URL de "Completo"
  if (isset($form_state['complete'])) drupal_goto('curso/completo');   
  
  //Si se presionó el botón de back, se regresa al paso anterior
  if ($form_state['triggering_element']['#id'] == 'edit-back') {
    print_r("moviendo para atrás");
    $form_state['new_stage'] = creacioncurso_move_to_previous_stage($form, $form_state);
  } 
  
  //Si se presionó el botón de next, se va al paso siguiente
  if (isset($form_state['multistep_values']['form_build_id'])) {
    $form_state['values']['form_build_id'] = $form_state['multistep_values']['form_build_id'];
  }

  //Se recalculan los pasos y vriables de control del formulario
  $form_state['multistep_values']['form_build_id'] = $form_state['values']['form_build_id'];
  if(isset($form_state['new_stage']))$form_state['stage'] = $form_state['new_stage'];

  
  $form_state['rebuild'] = TRUE;
    
}

 /**
  * Función para envíar un correo electrónico, se puede obviar, o utilizar con diferentes fines.
  * 
  * Creado por Ricardo Aguilera
  * 
  * @param type $form
  * @param type $form_state 
  */
function creacioncurso_personal_details_submit($form, &$form_state) {
  
 /* $multstep_values = $form_state['multistep_values'];
    
  $module = 'creacioncurso';
  $key = 'creacioncurso_complete';

  $to = $multstep_values['personal_details']['email'] . '; ' . variable_get('site_mail', 'admin@example.com');
  $from = variable_get('site_mail', 'admin@example.com');

  $params = array(
    'body' => 'Thank you for filling in our survey. You have now been entered into our prize draw.',
    'subject' => 'Thank you for filling in our survey, ' . $multstep_values['personal_details']['name'],  
  );
 
  $language = language_default();
  $send = TRUE;
  $result = drupal_mail($module, $key, $to, $language, $params, $from, $send);
  if ($result['result'] == TRUE) {
    drupal_set_message(t('Your message has been sent.'));
  }
  else {
    drupal_set_message(t('There was a problem sending your message and it was not sent.'), 'error');
  }
    */

  print_r("paso final");
}

/**
 * Returns what to show on the completion page.
 * 
 * @return type 
 */
function creacioncurso_complete() {
  unset($_SESSION['node']);
  unset($form['nid']);
  return AGRADECIMIENTO_PASO_FINAL;  
    
}


function guardar_valores_paso_anterior($form, $stage, $valores){
  global $user;
  $nid = 0;
  if(isset($form['nid']['#value']) || $form['nid']['#value'] > 0)  
    $nid = $form['nid']['#value'];
  
  if(isset($_SESSION['node']['nid']) && $_SESSION['node']['nid'] > 0)
    $nid = $_SESSION['node']['nid'];
  
  if($nid == 0)  
  {
    unset($node);
    $node = new stdClass(); 
    $node->title = $valores['titulo']; //título del nodo
    
    $node->type = "curso"; // este debe ser el machine_name del content type
    node_object_prepare($node);
    $node->language = LANGUAGE_NONE;
    $node->uid = $user->uid; 
    $node->status = 1; //(1 or 0): publicado automaticamente
    $node->promote = 0; //(1 or 0): desabilitado para página principal
    $node->comment = 0; // comentarios sobre el nodo deshabilitados
    $form['nid']['#value'] = $node->nid;
  }elseif($nid > 0)
    $node = node_load($nid);
  
  
  //Aquí se asignan los valores que se entregan de la forma. En la parte de $node-> es el machine_name del campo correspondiente en el content type

  if( isset($node) )
  {
    switch ($stage) {
      case 'descripcion_objetivo' :
          $node->field_curso_nombre[$node->language][0]['value'] = $valores['titulo']; 
          $node->field_curso_descripcion[$node->language][0]['value'] = $valores['txtDescripcion'];  
          $node->field_curso_objetivo[$node->language][0]['value'] = $valores['txtObjetivo'];
          $node->field_curso_audiencia[$node->language][0]['value'] = $valores['txtAudiencia'];  
          $node->field_categoria[$node->language][0]['tid'] = $valores['selCategoria'];
          $node->field_subcategoria[$node->language][0]['tid'] = $valores['selSubcategoria'];
          $node->field_curso_idioma[$node->language][0]['tid'] = $valores['selIdioma'];
      break;

      case 'detalles_curso' :
        
        $node->field_curso_temario[$node->language][0]['value'] = $valores['txtTemario']; 
        $node->field_curso_metodologia[$node->language][0]['value'] = $valores['txtMetodologia'];  
        $node->field_curso_modalidad[$node->language][0]['tid'] = $valores['selModalidad'];
        $node->field_curso_colaboracion[$node->language][0]['value'] = $valores['chkColaboracion']; 
        $node->field_curso_acreditacion[$node->language][0]['value'] = $valores['selAcreditacion'];
        $node->field_curso_limite_alumnos[$node->language][0]['value'] = $valores['radLimiteAlumnos'];
        $node->field_curso_numero_alumnos[$node->language][0]['value'] = $valores['txtNumeroAlumnos'];
        $node->field_curso_fechas_imparticion[$node->language][0]['value'] = $valores['radFechaImparticion'];
        
        $fechainicio=strtotime($valores['txtFechaInicio']['year'].'-'.$valores['txtFechaInicio']['month'].'-'.$valores['txtFechaInicio']['day']);
        $fechafin=strtotime($valores['txtFechaFin']['year'].'-'.$valores['txtFechaFin']['month'].'-'.$valores['txtFechaFin']['day']);
  
        $node->field_curso_fecha[$node->language][0]['value'] = $fechainicio;
        $node->field_curso_fecha[$node->language][0]['value2'] = $fechafin;
        
        $node->field_curso_duracion[$node->language][0]['value'] = $valores['radDuracion'];
        $node->field_curso_horas_semana[$node->language][0]['value'] = $valores['txtSemanal'];
        $node->field_curso_horas_totales[$node->language][0]['value'] = $valores['txtTotales'];
        $node->field_curso_caducidad[$node->language][0]['value'] = $valores['selCaducidad'];
        $node->field_curso_requerimientos[$node->language][0]['value'] = $valores['txtReqPrevios'];
        $node->field_curso_modulo_certificado[$node->language][0]['value'] = $valores['txtModuloCertificado'];
        
      break; 
      case 'evaluacion' :
        $node->field_curso_tutoreo[$node->language][0]['value'] = $valores['radTutoreo'];
        $node->field_curso_profesores[$node->language][0]['value'] = $valores['txtBusquedaProfesor'];
        $node->field_curso_evaluacion[$node->language][0]['value'] = $valores['txtEvaluacion'];
        
      break; 
      case 'imagen_video' :
        
        if( $valores['filImagenVideo'] != '')
        {
          $file = file_load($valores['filImagenVideo']);
          // Change status to permanent.
          $file->status = FILE_STATUS_PERMANENT;
          // Save.
          $fileSaved = file_save($file);
          variable_set('image_fid_'.$nid,$fileSaved->fid);
          $node->field_curso_imagen[$node->language][0]['value'] = $fileSaved->uri;
        }
        
        $node->field_curso_video[$node->language][0]['value'] = $valores['txtVideo'];
      break;
           
      case 'bibliografia_recomendaciones' :
        $node->field_curso_bibliografia_oficial[$node->language][0]['value'] = $valores['txtBibliografiaOficial'];
        $node->field_curso_bibliografia_re[$node->language][0]['value'] = $valores['txtBibliografiaRecomendada'];
        $node->field_curso_productos[$node->language][0]['value'] = $valores['txtProductosRecomendados'];
      break; 
      //case 'preguntas_frecuentes' :
        
        //Se implementará el almacenamiento con llamadas ajax individuales
       /* $fe_id = db_insert('preguntas_frecuentes')
                ->fields(array(
                  'pregunta' => $valores['txtPreguntaFrecuente'],
                  'respuesta' => $valores['txtRespuestaPreguntaFrecuente'],
                          'entity_id' =>$nid ,
                ))
                ->execute();*/
        //break;
      
      
      case 'configuracion_pagos':
        if( $valores['filCSD'] != '')
        {
        $file = file_load($valores['filCSD']);
        // Change status to permanent.
        $file->status = FILE_STATUS_PERMANENT;
        // Save.
        $fileSaved = file_save($file);
          variable_set('csd_fid_'.$nid,$fileSaved->fid);
          $node->field_curso_csd[$node->language][0]['value'] = $fileSaved->uri;
        }
          
        $node->field_curso_gratuito[$node->language][0]['value'] = $valores['chkCursoGratuito'];
        $node->field_curso_costo[$node->language][0]['value'] = $valores['txtCostoCurso'];
        $node->field_curso_descuento[$node->language][0]['value'] = $valores['txtDescuentoCurso'];
        $node->field_curso_donacion[$node->language][0]['value'] = $valores['chkDonacion'];
        $node->field_curso_donativo[$node->language][0]['value'] = $valores['txtMontoDonacion'];
        $node->field_curso_cuenta_deposito[$node->language][0]['value'] = $valores['selCuentaDeposito'];
        $node->field_curso_comprobante_fiscal[$node->language][0]['value'] = $valores['btnFiscal'];
        
        #$node->field_curso_csd[$node->language][0]['value'] = $valores['filCSD'];
      break;
    
      case 'datos_especificos' :        
        db_delete('curso_datos_especificos')
          ->condition('entity_id', $nid)
          ->execute();
        $personales=$valores['datos_personales'];
        $insert = db_insert('curso_datos_especificos')->fields(array('entity_id', 'id_dato','i_grupo'));
        
        foreach($valores['datos_personales'] as $personal)
          if($personal>0){
             $insert->values(array(
              'entity_id' => $nid,
              'id_dato' => $personal,
              'i_grupo' => 1,
            ));
          }
        foreach($valores['datos_escuela'] as $esc)
          if($esc>0){
             $insert->values(array(
              'entity_id' => $nid,
              'id_dato' => $esc,
              'i_grupo' => 2,
            ));
          }        
        foreach($valores['datos_beca'] as $beca)
          if($beca>0){
             $insert->values(array(
              'entity_id' => $nid,
              'id_dato' => $beca,
              'i_grupo' => 3,
            ));
          }
        
        $insert->execute();
      break;
        
      case 'seleccion_canal' :
          $node->field_curso_canal[$node->language][0]['value'] = $valores['hCanalSeleccionado'];
      break; 
      /*configuracion LMS se guarda en el hook creacioncurso_form_submit*/
      //case 'configuracion_LMS' :
      //break;
   
      default:
      break; 
    }
  
 
    //print_r("<br>Stage:".$stage."<br>");
    //print_r("<br>Valores:");
    //print_r($valores);
    //print_r("<br>");
    
    
    node_save($node);
    //print_r($node);
    
    $nid = $node->nid;
      #unset ($node);
      $_SESSION['node'] = array('nid'=>$nid);
  }
  
  else
   echo('No hay nodo');
    

}