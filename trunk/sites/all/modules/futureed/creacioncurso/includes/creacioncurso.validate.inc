
<?php

/**
 * @file
 * Handles the form validation of the customer survey form
 * All hooks are in the .module file.
 */


/**
 * Master validation function for the customer survey form - uses per-stage 
 * validation and calls functions for each one.
 * 
 * @param type $form
 * @param type $form_state
 * @return type 
 */
function creacioncurso_form_validate($form, &$form_state) {
    
  if ($form_state['triggering_element']['#value'] == 'Back') {
    return;
  }  
    
  switch ($form_state['stage']) { 

    case 'descripcion_objetivo' :         return creacioncurso_descripcion_objetivo_validate($form, $form_state); break; 
    case 'detalles_curso' :               return creacioncurso_detalles_curso_validate($form, $form_state); break; 
    case 'evaluacion' :                   return creacioncurso_evaluacion_validate($form, $form_state); break; 
    case 'imagen_video' :                 return creacioncurso_imagen_video_validate($form, $form_state); break; 
    case 'bibliografia_recomendaciones' : return creacioncurso_bibliografia_recomendaciones_validate($form, $form_state); break; 
    case 'preguntas_frecuentes' :         return creacioncurso_preguntas_frecuentes_validate($form, $form_state); break; 
    case 'configuracion_pagos' :          return creacioncurso_configuracion_pagos_validate($form, $form_state); break; 
    case 'datos_especificos' :            return creacioncurso_datos_especificos_validate($form, $form_state); break; 
    case 'seleccion_canal' :              return creacioncurso_seleccion_canal_validate($form, $form_state); break; 
    case 'configuracion_LMS' :            return creacioncurso_configuracion_LMS_validate($form, $form_state); break; 
  }
}


/**
 * Validation for the rate_the_room step
 * 
 * @param type $form
 * @param type $form_state 
 */
function creacioncurso_descripcion_objetivo_validate($form, &$form_state) {
  
  
}

/**
 *  Validación del paso de detalles_curso
 *  para hacer validaciones específicas sobre cada uno de los campos, 
 *  Construido por Ricardo Aguilera
 * 
 * @param type $form
 * @param type $form_state 
 */

function creacioncurso_detalles_curso_validate($form, &$form_state) {
 
   //Validación de cada uno de los campos, por ejempo:
 /* if (!$form_state['values']['titulo']) {
   // form_set_error('room_rating', 'You must rate our room before continuing');    
  }  */ 
}

/**
 *  Validación del paso de evaluacion
 *  para hacer validaciones específicas sobre cada uno de los campos, 
 *  Construido por Ricardo Aguilera
 * 
 * @param type $form
 * @param type $form_state 
 */

function creacioncurso_evaluacion_validate($form, &$form_state) {
 
   //Validación de cada uno de los campos, por ejempo:
 /* if (!$form_state['values']['titulo']) {
   // form_set_error('room_rating', 'You must rate our room before continuing');    
  }  */ 
}

/**
 *  Validación del paso de imagen_video
 *  para hacer validaciones específicas sobre cada uno de los campos, 
 *  Construido por Ricardo Aguilera
 * 
 * @param type $form
 * @param type $form_state 
 */

function creacioncurso_imagen_video_validate($form, &$form_state) {
 
   //Validación de cada uno de los campos, por ejempo:
 /* if (!$form_state['values']['titulo']) {
   // form_set_error('room_rating', 'You must rate our room before continuing');    
  }  */ 
}

/**
 *  Validación del paso de bibliografia_recomendaciones
 *  para hacer validaciones específicas sobre cada uno de los campos, 
 *  Construido por Ricardo Aguilera
 * 
 * @param type $form
 * @param type $form_state 
 */

function creacioncurso_bibliografia_recomendaciones_validate($form, &$form_state) {
 
   //Validación de cada uno de los campos, por ejempo:
 /* if (!$form_state['values']['titulo']) {
   // form_set_error('room_rating', 'You must rate our room before continuing');    
  }  */ 
}

/**
 *  Validación del paso de preguntas_frecuentes
 *  para hacer validaciones específicas sobre cada uno de los campos, 
 *  Construido por Ricardo Aguilera
 * 
 * @param type $form
 * @param type $form_state 
 */

function creacioncurso_preguntas_frecuentes_validate($form, &$form_state) {
 
   //Validación de cada uno de los campos, por ejempo:
 /* if (!$form_state['values']['titulo']) {
   // form_set_error('room_rating', 'You must rate our room before continuing');    
  }  */ 
}

/**
 *  Validación del paso de configuracion_pagos
 *  para hacer validaciones específicas sobre cada uno de los campos, 
 *  Construido por Ricardo Aguilera
 * 
 * @param type $form
 * @param type $form_state 
 */

function creacioncurso_configuracion_pagos_validate($form, &$form_state) {
 
   //Validación de cada uno de los campos, por ejempo:
 /* if (!$form_state['values']['titulo']) {
   // form_set_error('room_rating', 'You must rate our room before continuing');    
  }  */ 
}

/**
 *  Validación del paso de datos_especificos
 *  para hacer validaciones específicas sobre cada uno de los campos, 
 *  Construido por Ricardo Aguilera
 * 
 * @param type $form
 * @param type $form_state 
 */

function creacioncurso_datos_especificos_validate($form, &$form_state) {
 
   //Validación de cada uno de los campos, por ejempo:
 /* if (!$form_state['values']['titulo']) {
   // form_set_error('room_rating', 'You must rate our room before continuing');    
  }  */ 
}

/**
 *  Validación del paso de seleccion_canal
 *  para hacer validaciones específicas sobre cada uno de los campos, 
 *  Construido por Ricardo Aguilera
 * 
 * @param type $form
 * @param type $form_state 
 */

function creacioncurso_seleccion_canal_validate($form, &$form_state) {
 
   //Validación de cada uno de los campos, por ejempo:
 /* if (!$form_state['values']['titulo']) {
   // form_set_error('room_rating', 'You must rate our room before continuing');    
  }  */ 
}

/**
 *  Validación del paso de configuracion_LMS
 *  para hacer validaciones específicas sobre cada uno de los campos, 
 *  Construido por Ricardo Aguilera
 * 
 * @param type $form
 * @param type $form_state 
 */

function creacioncurso_configuracion_LMS_validate($form, &$form_state) {
 
   //Validación de cada uno de los campos, por ejempo:
 /* if (!$form_state['values']['titulo']) {
   // form_set_error('room_rating', 'You must rate our room before continuing');    
  }  */ 
}
