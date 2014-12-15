<?php

/**
 * @file
 * Gestion la validación del formulario
 * @see  configuracioncuenta.module
 */


/**
 * Validación del formulario, por cada paso se manda llamar una función diferente,
 * lo que significa que cada paso será gestionado de manera individual.
 * 
 * @param type $form
 * @param type $form_state
 * @return type 
 */
function configuracioncuenta_form_validate($form, &$form_state) {
    
  if ($form_state['triggering_element']['#value'] == 'Back') {
    return;
  }  
    
  switch ($form_state['stage']) { 

    case 'informacion_general' :    return configuracioncuenta_informacion_general_validate($form, $form_state); break; 
    case 'contacto' :               return configuracioncuenta_contacto_validate($form, $form_state); break; 
    case 'direcciones' :            return configuracioncuenta_direcciones_validate($form, $form_state); break; 
    case 'profesional_academica' :  return configuracioncuenta_profesional_academica_validate($form, $form_state); break; 
    case 'intereses' :              return configuracioncuenta_intereses_validate($form, $form_state); break; 
    case 'privacidad' :             return configuracioncuenta_privacidad_validate($form, $form_state); break; 
    case 'facturacion' :            return configuracioncuenta_facturacion_validate($form, $form_state); break; 
    case 'pago' :                   return configuracioncuenta_pago_validate($form, $form_state); break; 
    case 'cuentas' :                return configuracioncuenta_cuentas_validate($form, $form_state); break; 
    case 'verificacion_cuenta' :    return configuracioncuenta_verificacion_cuenta_validate($form, $form_state); break; 
    case 'historial_compras' :      return configuracioncuenta_historial_compras_validate($form, $form_state); break; 
    case 'historial_ventas' :       return configuracioncuenta_historial_ventas_validate($form, $form_state); break; 
    case 'cambio_perfil' :          return configuracioncuenta_cambio_perfil_validate($form, $form_state); break; 

  }
}



/**
 *  Validación del paso de informacion_general
 *  para hacer validaciones específicas sobre cada uno de los campos, 
 *  Construido por Ricardo Aguilera
 * 
 * @param type $form
 * @param type $form_state 
 */

function configuracioncuenta_informacion_general_validate($form, &$form_state) {
 
   //Validación de cada uno de los campos, por ejempo:
 /* if (!$form_state['values']['titulo']) {
   // form_set_error('room_rating', 'You must rate our room before continuing');    
  }  */ 
}

/**
 *  Validación del paso de contacto
 *  para hacer validaciones específicas sobre cada uno de los campos, 
 *  Construido por Ricardo Aguilera
 * 
 * @param type $form
 * @param type $form_state 
 */

function configuracioncuenta_contacto_validate($form, &$form_state) {
 
   //Validación de cada uno de los campos, por ejempo:
 /* if (!$form_state['values']['titulo']) {
   // form_set_error('room_rating', 'You must rate our room before continuing');    
  }  */ 
}

/**
 *  Validación del paso de direcciones
 *  para hacer validaciones específicas sobre cada uno de los campos, 
 *  Construido por Ricardo Aguilera
 * 
 * @param type $form
 * @param type $form_state 
 */

function configuracioncuenta_direcciones_validate($form, &$form_state) {
 
   //Validación de cada uno de los campos, por ejempo:
 /* if (!$form_state['values']['titulo']) {
   // form_set_error('room_rating', 'You must rate our room before continuing');    
  }  */ 
}

/**
 *  Validación del paso de profesional_academica
 *  para hacer validaciones específicas sobre cada uno de los campos, 
 *  Construido por Ricardo Aguilera
 * 
 * @param type $form
 * @param type $form_state 
 */

function configuracioncuenta_profesional_academica_validate($form, &$form_state) {
 
   //Validación de cada uno de los campos, por ejempo:
 /* if (!$form_state['values']['titulo']) {
   // form_set_error('room_rating', 'You must rate our room before continuing');    
  }  */ 
}

/**
 *  Validación del paso de intereses
 *  para hacer validaciones específicas sobre cada uno de los campos, 
 *  Construido por Ricardo Aguilera
 * 
 * @param type $form
 * @param type $form_state 
 */

function configuracioncuenta_intereses_validate($form, &$form_state) {
 
   //Validación de cada uno de los campos, por ejempo:
 /* if (!$form_state['values']['titulo']) {
   // form_set_error('room_rating', 'You must rate our room before continuing');    
  }  */ 
}

/**
 *  Validación del paso de privacidad
 *  para hacer validaciones específicas sobre cada uno de los campos, 
 *  Construido por Ricardo Aguilera
 * 
 * @param type $form
 * @param type $form_state 
 */

function configuracioncuenta_privacidad_validate($form, &$form_state) {
 
   //Validación de cada uno de los campos, por ejempo:
 /* if (!$form_state['values']['titulo']) {
   // form_set_error('room_rating', 'You must rate our room before continuing');    
  }  */ 
}

/**
 *  Validación del paso de facturacion
 *  para hacer validaciones específicas sobre cada uno de los campos, 
 *  Construido por Ricardo Aguilera
 * 
 * @param type $form
 * @param type $form_state 
 */

function configuracioncuenta_facturacion_validate($form, &$form_state) {
 
   //Validación de cada uno de los campos, por ejempo:
 /* if (!$form_state['values']['titulo']) {
   // form_set_error('room_rating', 'You must rate our room before continuing');    
  }  */ 
}

/**
 *  Validación del paso de pago
 *  para hacer validaciones específicas sobre cada uno de los campos, 
 *  Construido por Ricardo Aguilera
 * 
 * @param type $form
 * @param type $form_state 
 */

function configuracioncuenta_pago_validate($form, &$form_state) {
 
   //Validación de cada uno de los campos, por ejempo:
 /* if (!$form_state['values']['titulo']) {
   // form_set_error('room_rating', 'You must rate our room before continuing');    
  }  */ 
}

/**
 *  Validación del paso de cuentas
 *  para hacer validaciones específicas sobre cada uno de los campos, 
 *  Construido por Ricardo Aguilera
 * 
 * @param type $form
 * @param type $form_state 
 */

function configuracioncuenta_cuentas_validate($form, &$form_state) {
 
   //Validación de cada uno de los campos, por ejempo:
 /* if (!$form_state['values']['titulo']) {
   // form_set_error('room_rating', 'You must rate our room before continuing');    
  }  */ 
}

/**
 *  Validación del paso de verificacion_cuenta
 *  para hacer validaciones específicas sobre cada uno de los campos, 
 *  Construido por Ricardo Aguilera
 * 
 * @param type $form
 * @param type $form_state 
 */

function configuracioncuenta_verificacion_cuenta_validate($form, &$form_state) {
 
   //Validación de cada uno de los campos, por ejempo:
 /* if (!$form_state['values']['titulo']) {
   // form_set_error('room_rating', 'You must rate our room before continuing');    
  }  */ 
}

/**
 *  Validación del paso de historial_compras
 *  para hacer validaciones específicas sobre cada uno de los campos, 
 *  Construido por Ricardo Aguilera
 * 
 * @param type $form
 * @param type $form_state 
 */

function configuracioncuenta_historial_compras_validate($form, &$form_state) {
 
   //Validación de cada uno de los campos, por ejempo:
 /* if (!$form_state['values']['titulo']) {
   // form_set_error('room_rating', 'You must rate our room before continuing');    
  }  */ 
}

/**
 *  Validación del paso de historial_ventas
 *  para hacer validaciones específicas sobre cada uno de los campos, 
 *  Construido por Ricardo Aguilera
 * 
 * @param type $form
 * @param type $form_state 
 */

function configuracioncuenta_historial_ventas_validate($form, &$form_state) {
 
   //Validación de cada uno de los campos, por ejempo:
 /* if (!$form_state['values']['titulo']) {
   // form_set_error('room_rating', 'You must rate our room before continuing');    
  }  */ 
}

/**
 *  Validación del paso de cambio_perfil
 *  para hacer validaciones específicas sobre cada uno de los campos, 
 *  Construido por Ricardo Aguilera
 * 
 * @param type $form
 * @param type $form_state 
 */

function configuracioncuenta_cambio_perfil_validate($form, &$form_state) {
 
   //Validación de cada uno de los campos, por ejempo:
 /* if (!$form_state['values']['titulo']) {
   // form_set_error('room_rating', 'You must rate our room before continuing');    
  }  */ 
}
