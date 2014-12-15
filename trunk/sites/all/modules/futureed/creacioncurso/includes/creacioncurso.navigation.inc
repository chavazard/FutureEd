<?php 

/**
 * @file
 * Handles the navigation of the customer survey form
 * All hooks are in the .module file.
 */


/**
 * Generate a header which informs the user of which stage they're on.
 * 
 * @param type $form
 * @param type $form_state
 * @return type 
 */
function creacioncurso_get_menu($form, &$form_state) {
  
  $form_state['stage'] = isset($form_state['stage']) ? $form_state['stage'] : 1;  
    
  $form_stages = array(
    'descripcion_objetivo' => 1,
    'detalles_curso' => 2,
    'evaluacion' => 3,
    'imagen_video' => 4,
    'bibliografia_recomendaciones' => 5,
    'preguntas_frecuentes' => 6,
    'configuracion_pagos' => 7,
    'datos_especificos' => 8,
    'seleccion_canal' => 9,
    'configuracion_LMS' => 10,
  ); 
  if (isset($form_stages[$form_state['stage']])) {
   $current_step = $form_stages[$form_state['stage']]; 
  }
  else {
   $current_step = 1;
  }
  
  $strSufijo="";
  $tokens = explode('/', current_path());
  if(is_numeric($tokens[sizeof($tokens)-1])){
     $strSufijo="/".$tokens[sizeof($tokens)-1];
  }

  
  $stages = array(
    1 => array('data' => l(DESCRIPCION_OBJETIVOS,'cursoNuevo/descripcion_objetivo'.$strSufijo)),
    2 => array('data' => l(DETALLES_CURSO,'cursoNuevo/detalles_curso'.$strSufijo)),
    3 => array('data' => l(EVALUACION,'cursoNuevo/evaluacion'.$strSufijo)),
    4 => array('data' => l(IMAGEN_VIDEO,'cursoNuevo/imagen_video'.$strSufijo)),
    5 => array('data' => l(BIBLIOGRAFIA_RECOMENDACIONES,'cursoNuevo/bibliografia_recomendaciones'.$strSufijo)),
    6 => array('data' => l(PREGUNTAS_FRECUENTES,'cursoNuevo/preguntas_frecuentes'.$strSufijo)),
    7 => array('data' => l(CONFIGURACION_PAGOS,'cursoNuevo/configuracion_pagos'.$strSufijo)),
    8 => array('data' => "<hr/>"),
    9 => array('data' => l(DATOS_ESPECIFICOS,'cursoNuevo/datos_especificos'.$strSufijo)),
    10 => array('data' => l(SELECCION_CANAL,'cursoNuevo/seleccion_canal'.$strSufijo)),
    11 => array('data' => l(CONFIGURACION_LMS,'cursoNuevo/configuracion_LMS'.$strSufijo)),
  );
  //print_r($stages[$current_step]);
  //$stages[$current_step]['class'] = array('active');
 
  $stages_list = theme('item_list', array('items' => $stages));
  
  $form['steps'] = array(
    '#type' => 'fieldset',
    '#title' => '',
    '#value' => $stages_list,
  );


  return $form;
  
}

function creacioncurso_get_path($form, &$form_state){
  
  $strSufijo="";
  $tokens = explode('/', current_path());
  $path=$tokens[sizeof($tokens)-1];
  if(is_numeric($path)){
    $strSufijo="/".$tokens[sizeof($tokens)-1];
    $path=$tokens[sizeof($tokens)-2];

  }
  $path=='nuevo'?$path=='descripcion_objetivo':'';
 
  switch($path){
    case 'descripcion_objetivo':
      $stages=array('data' => TITULO_FORMULARIO_CURSO.' > '.l(DESCRIPCION_OBJETIVOS,'cursoNuevo/'.$path.$strSufijo));
    break;
    case 'detalles_curso':
      $stages=array('data' => TITULO_FORMULARIO_CURSO.' > '.l(DETALLES_CURSO,'cursoNuevo/'.$path.$strSufijo));
    break;
    case 'evaluacion':
      $stages=array('data' => TITULO_FORMULARIO_CURSO.' > '.l(EVALUACION,'cursoNuevo/'.$path.$strSufijo));
    break;
    case 'imagen_video':
      $stages=array('data' => TITULO_FORMULARIO_CURSO.' > '.l(IMAGEN_VIDEO,'cursoNuevo/'.$path.$strSufijo));
    break;
    case 'bibliografia_recomendaciones':
      $stages=array('data' => TITULO_FORMULARIO_CURSO.' > '.l(BIBLIOGRAFIA_RECOMENDACIONES,'cursoNuevo/'.$path.$strSufijo));
    break;
    case 'preguntas_frecuentes':
      $stages=array('data' => TITULO_FORMULARIO_CURSO.' > '.l(PREGUNTAS_FRECUENTES,'cursoNuevo/'.$path.$strSufijo));
    break;
    case 'configuracion_pagos':
      $stages=array('data' => TITULO_FORMULARIO_CURSO.' > '.l(CONFIGURACION_PAGOS,'cursoNuevo/'.$path.$strSufijo));
    break;
    case 'datos_especificos':
      $stages=array('data' => TITULO_FORMULARIO_CURSO.' > '.l(DATOS_ESPECIFICOS,'cursoNuevo/'.$path.$strSufijo));
    break;
    case 'seleccion_canal':
      $stages=array('data' => TITULO_FORMULARIO_CURSO.' > '.l(SELECCION_CANAL,'cursoNuevo/'.$path.$strSufijo));
    break;
    case 'configuracion_LMS':
      $stages=array('data' => TITULO_FORMULARIO_CURSO.' > '.l(CONFIGURACION_LMS,'cursoNuevo/'.$path.$strSufijo));
    break;


  }
  
  $stages_list = theme('item_list', array('items' => $stages));
  
  $form['steps'] = array(
    '#type' => 'fieldset',
    '#title' => '',
    '#value' => $stages_list,
  );

  return $form;
  
}


/**
 * Given the current stage the user is on, calculate what the next step would be
 * 
 * @param type $form_state
 * @return string 
 */
function creacioncurso_move_to_next_stage($form, &$form_state) {

  print_r("<br>siguiente<br>");

  if($form_state['triggering_element']['#id'] == 'edit-save')return $form_state['stage'];
  switch ($form_state['stage']) {

    case 'descripcion_objetivo' :         return 'detalles_curso'; break;
    case 'detalles_curso' :               return 'evaluacion'; break;
    case 'evaluacion' :                   return 'imagen_video'; break;
    case 'imagen_video' :                 return 'bibliografia_recomendaciones'; break;
    case 'bibliografia_recomendaciones' : return 'preguntas_frecuentes'; break;
    case 'preguntas_frecuentes' :         return 'configuracion_pagos'; break;
    case 'configuracion_pagos' :          return 'datos_especificos'; break;
    case 'datos_especificos' :            return 'seleccion_canal'; break;
    case 'seleccion_canal' :              return 'configuracion_LMS'; break;
  }

}


/**
 * Given the current stage the user is on, calculate what the previous step
 * would be
 * 
 * @param type $form_state
 * @return string 
 */

function creacioncurso_move_to_previous_stage($form, &$form_state) {

  print_r("<br>anterior<br>");
  if($form_state['triggering_element']['#id'] == 'edit-save')return $form_state['stage'];

  switch ($form_state['stage']) {
    
    case 'detalles_curso' :               return 'descripcion_objetivo'; break;
    case 'evaluacion' :                   return 'detalles_curso'; break;
    case 'imagen_video' :                 return 'evaluacion'; break;
    case 'bibliografia_recomendaciones' : return 'imagen_video'; break;
    case 'preguntas_frecuentes' :         return 'bibliografia_recomendaciones'; break;
    case 'configuracion_pagos' :          return 'preguntas_frecuentes'; break;
    case 'datos_especificos' :            return 'configuracion_pagos'; break;
    case 'seleccion_canal' :              return 'datos_especificos'; break;
    case 'configuracion_LMS' :            return 'seleccion_canal'; break;

  }
    
}

