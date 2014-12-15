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
function configuracioncuenta_get_menu($form, &$form_state) {
  
  $form_state['stage'] = isset($form_state['stage']) ? $form_state['stage'] : 1;  
    
  $form_stages = array(
    'informacion_general' => 1,
    'contacto' => 2,
    'direcciones' => 3,
    'profesional_academica' => 4,
    'intereses' => 5,
    'privacidad' => 6,
    'facturacion' => 7,
    'pago' => 8,
    'cuentas' => 9,
    'verificacion_cuenta' => 10,
    'historial_compras' => 11,
    'historial_ventas' => 12,
    'cambio_perfil' => 13,
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
    1 => array('data' => l(INFORMACION_GENERAL,'cuenta/configurar/informacion_general'.$strSufijo)),
    2 => array('data' => l(CONTACTO,'cuenta/configurar/contacto'.$strSufijo)),
    3 => array('data' => l(DIRECCIONES,'cuenta/configurar/direcciones'.$strSufijo)),
    4 => array('data' => l(PROFESIONAL_ACADEMICA,'cuenta/configurar/profesional_academica'.$strSufijo)),
    5 => array('data' => l(INTERESES,'cuenta/configurar/intereses'.$strSufijo)),
    6 => array('data' => '<hr>'),
    7 => array('data' => l(PRIVACIDAD,'cuenta/configurar/privacidad'.$strSufijo)),
    8 => array('data' => '<hr>'),
    9 => array('data' => l(FACTURACION,'cuenta/configurar/facturacion'.$strSufijo)),
    10 => array('data' => l(PAGO,'cuenta/configurar/pago'.$strSufijo)),
    11 => array('data' => l(CUENTAS,'cuenta/configurar/cuentas'.$strSufijo)),
    12 => array('data' => '<hr>'),
    13 => array('data' => l(VERIFICACION_CUENTA,'cuenta/configurar/verificacion_cuenta'.$strSufijo)),
    14 => array('data' => '<hr>'),
    15 => array('data' => l(HISTORIAL_COMPRAS,'cuenta/configurar/historial_compras'.$strSufijo)),
    16 => array('data' => l(HISTORIAL_VENTAS,'cuenta/configurar/historial_ventas'.$strSufijo)),
    17 => array('data' => '<hr>'),
    18 => array('data' => l(CAMBIO_PERFIL,'cuenta/configurar/cambio_perfil'.$strSufijo)),
  );
  
  
  $stages_list = theme('item_list', array('items' => $stages));
  
  $form['steps'] = array(
    '#type' => 'fieldset',
    '#title' => '',
    '#value' => $stages_list,
  );

  return $form;
  
}

function configuracioncuenta_get_path($form, &$form_state){
  
  $strSufijo="";
  $tokens = explode('/', current_path());
  $path=$tokens[sizeof($tokens)-1];
  if(is_numeric($path)){
    $strSufijo="/".$tokens[sizeof($tokens)-1];
    $path=$tokens[sizeof($tokens)-2];

  }
  $path=='configurar'?$path=='informacion_general':'';
 
  switch($path){
    case 'informacion_general':
      $stages=array('data' => TITULO_FORMULARIO_CUENTA.' > '.l(INFORMACION_GENERAL,'cuenta/configurar/'.$path.$strSufijo));
    break;
    case 'contacto':
      $stages=array('data' => TITULO_FORMULARIO_CUENTA.' > '.l(CONTACTO,'cuenta/configurar/'.$path.$strSufijo));
    break;
    case 'direcciones':
      $stages=array('data' => TITULO_FORMULARIO_CUENTA.' > '.l(DIRECCIONES,'cuenta/configurar/'.$path.$strSufijo));
    break;
    case 'profesional_academica':
      $stages=array('data' => TITULO_FORMULARIO_CUENTA.' > '.l(PROFESIONAL_ACADEMICA,'cuenta/configurar/'.$path.$strSufijo));
    break;
    case 'intereses':
      $stages=array('data' => TITULO_FORMULARIO_CUENTA.' > '.l(INTERESES,'cuenta/configurar/'.$path.$strSufijo));
    break;
    case 'privacidad':
      $stages=array('data' => TITULO_FORMULARIO_CUENTA.' > '.l(PRIVACIDAD,'cuenta/configurar/'.$path.$strSufijo));
    break;
    case 'facturacion':
      $stages=array('data' => TITULO_FORMULARIO_CUENTA.' > '.l(FACTURACION,'cuenta/configurar/'.$path.$strSufijo));
    break;
    case 'pago':
      $stages=array('data' => TITULO_FORMULARIO_CUENTA.' > '.l(PAGO,'cuenta/configurar/'.$path.$strSufijo));
    break;
    case 'cuentas':
      $stages=array('data' => TITULO_FORMULARIO_CUENTA.' > '.l(CUENTAS,'cuenta/configurar/'.$path.$strSufijo));
    break;
    case 'verificacion_cuenta':
      $stages=array('data' => TITULO_FORMULARIO_CUENTA.' > '.l(VERIFICACION_CUENTA,'cuenta/configurar/'.$path.$strSufijo));
    break;
    case 'historial_compras':
      $stages=array('data' => TITULO_FORMULARIO_CUENTA.' > '.l(HISTORIAL_COMPRAS,'cuenta/configurar/'.$path.$strSufijo));
    break;
    case 'historial_ventas':
      $stages=array('data' => TITULO_FORMULARIO_CUENTA.' > '.l(HISTORIAL_VENTAS,'cuenta/configurar/'.$path.$strSufijo));
    break;
    case 'cambio_perfil':
      $stages=array('data' => TITULO_FORMULARIO_CUENTA.' > '.l(CAMBIO_PERFIL,'cuenta/configurar/'.$path.$strSufijo));
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
function configuracioncuenta_move_to_next_stage($form, &$form_state) {

  //print_r($form_state['stage']);
  switch ($form_state['stage']) {
    case 'informacion_general' : return 'contacto'; break;
    case 'contacto' : return 'direcciones'; break;
    case 'direcciones' : return 'profesional_academica'; break;
    case 'profesional_academica' : return 'intereses'; break;
    case 'intereses' : return 'privacidad'; break;
    case 'privacidad' : return 'facturacion'; break;
    case 'facturacion' : return 'pago'; break;
    case 'pago' : return 'cuentas'; break;
    case 'cuentas' : return 'verificacion_cuenta'; break;
    case 'verificacion_cuenta' : return 'historial_compras'; break;
    case 'historial_compras' : return 'historial_ventas'; break;
    case 'historial_ventas' : return 'cambio_perfil'; break;
  }

}


/**
 * Given the current stage the user is on, calculate what the previous step
 * would be
 * 
 * @param type $form_state
 * @return string 
 */

function configuracioncuenta_move_to_previous_stage($form, &$form_state) {

  switch ($form_state['stage']) {
    case 'contacto' : return 'informacion_general'; break;
    case 'direcciones' : return 'contacto'; break;
    case 'profesional_academica' : return 'direcciones'; break;
    case 'intereses' : return 'profesional_academica'; break;
    case 'privacidad' : return 'intereses'; break;
    case 'facturacion' : return 'privacidad'; break;
    case 'pago' : return 'facturacion'; break;
    case 'cuentas' : return 'pago'; break;
    case 'verificacion_cuenta' : return 'cuentas'; break;
    case 'historial_compras' : return 'verificacion_cuenta'; break;
    case 'historial_ventas' : return 'historial_compras'; break;
    case 'cambio_perfil' : return 'historial_ventas'; break;

  }
    
}