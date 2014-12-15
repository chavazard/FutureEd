<?php

/**
 * @file
 * Handles the form elements of the customer survey form
 * All hooks are in the .module file.
 */

/**
 * Master form which calls an individual form for each step.
 * 
 * @see creacioncurso_form_validate().
 * @see creacioncurso_form_submit().
 * 
 * @param type $form
 * @param string $form_state
 * @return type 
 */
function creacioncurso_form($form, &$form_state) {
     

  $form = array();


  if (!isset($form_state['stage'])){
    $tokens = explode('/', current_path());

    if(is_numeric($tokens[sizeof($tokens)-1])){
      $form_state['stage'] = $tokens[sizeof($tokens)-2];
      $form['nid']=array(
        '#type' => 'hidden',
        '#value' => $tokens[sizeof($tokens)-1]
      );//$tokens[sizeof($tokens)-1];
    }
    else{
      $form_state['stage'] = $tokens[sizeof($tokens)-1];
      $form['nid']=null;
    }
  }



  if($form_state['stage']=='nuevo')$form_state['stage']='descripcion_objetivo';


  //$form = creacioncurso_get_menu($form, $form_state);

  switch ($form_state['stage']) {
    case 'descripcion_objetivo' :         return creacioncurso_descripcion_objetivo_form($form, $form_state); break; 
    case 'detalles_curso' :               return creacioncurso_detalles_curso_form($form, $form_state); break; 
    case 'evaluacion' :                   return creacioncurso_evaluacion_form($form, $form_state); break; 
    case 'imagen_video' :                 return creacioncurso_imagen_video_form($form, $form_state); break; 
    case 'bibliografia_recomendaciones' : return creacioncurso_bibliografia_recomendaciones_form($form, $form_state); break; 
    case 'preguntas_frecuentes' :         return creacioncurso_preguntas_frecuentes_form($form, $form_state); break; 
    case 'configuracion_pagos' :          return creacioncurso_configuracion_pagos_form($form, $form_state); break; 
    case 'datos_especificos' :            return creacioncurso_datos_especificos_form($form, $form_state); break; 
    case 'seleccion_canal' :              return creacioncurso_seleccion_canal_form($form, $form_state); break; 
    case 'configuracion_LMS' :            return creacioncurso_configuracion_LMS_form($form, $form_state); break; 
 
    default:                              return creacioncurso_descripcion_objetivo_form($form, $form_state); break; 
  }
  
  return $form;
    
}


/**
 * Form for the descripcion_objetivo step.
 * 
 * @see creacioncurso_form().
 *  
 * @param type $form
 * @param type $form_state
 * @return type 
 */
function creacioncurso_descripcion_objetivo_form($form, &$form_state) {
    
  $values = isset($form_state['multistep_values']['descripcion_objetivo']) ? $form_state['multistep_values']['descripcion_objetivo'] : array();
  
  $nid = 0;
  if(isset($_SESSION['node']['nid']) && $_SESSION['node']['nid'] > 0)
    $nid = $_SESSION['node']['nid'];
     
  if(isset($form['nid']['#value']) && $form['nid']['#value'] > 0)
    $nid = $form['nid']['#value'];
  
  $values = get_descripcion_objetivo_values($nid);
  
  //EJEMPLO IMPLEMENTACION FIELD COLLECTION
  //$fc_item = $node->field_puesto_laboral['und'][0]['value'];
  //$puesto = field_collection_item_load($fc_item,  $reset = FALSE);
  //$puesto->field_usuario_puesto['und'][0]['value'] = 'felde gesammelt 2';
  //print_r($puesto);
  
  
  $form['descripcion_objetivo']['titulo'] = array(
    '#type' => 'textfield',
    '#title' => NOMBRE_CURSO,
    '#required' => true,
    '#default_value' => isset($values['titulo']) ? $values['titulo'] : NULL,
    '#prefix' =>'<div class="row"><div class="small-5 columns etiqueta">' ,
    '#suffix' => '</div>',
  );


  $form['descripcion_objetivo']['tituloAccion'] = array(
    '#markup' =>'<div class="small-1 columns"><i class="fa fa-edit" id="editarNombre">Ed</i></div>',
  );


  $form['descripcion_objetivo']['save1'] = array(
    '#type' => 'submit',
    '#value' => BOTON_GUARDAR,
    '#prefix' =>'<div class="small-6 columns text-right"><div class="btn-primario">',
    '#suffix' => '</div>',
  );
  $form['descripcion_objetivo']['next1'] = array(
    '#type' => 'submit',
    '#value' => BOTON_SIGUIENTE,
    '#suffix' => '</div></div><hr></div>',
    '#prefix' =>'<div class="btn-secundario">',
  );

  //ok

  //inicio de row

 $form['descripcion_objetivo']['txtDescripcion'] = array(
    '#title' =>DESCRIPCION_CURSO,
    '#required' => TRUE,
    '#type' => 'textarea',
    '#prefix' =>'<div class="row"><div class="small-6 columns">' ,
    '#suffix' => '</div>',
    '#default_value' => isset($values['txtDescripcion']) ? $values['txtDescripcion'] : NULL,
  );
   
  $form['descripcion_objetivo']['txtObjetivo'] = array(
    '#title' =>OBJETIVO_CURSO,
    '#required' => TRUE,
    '#type' => 'textarea',
    '#prefix' =>'<div class="small-6 columns">' ,
    '#suffix' => '</div></div>',
    '#default_value' => isset($values['txtObjetivo']) ? $values['txtObjetivo'] : NULL,
  );

  //ok
  //inicio de row
   
  $form['descripcion_objetivo']['txtAudiencia'] = array(
    '#title' =>AUDIENCIA_CURSO,
    '#required' => TRUE,
    '#type' => 'textarea',
    '#default_value' => isset($values['txtAudiencia']) ? $values['txtAudiencia'] : NULL,
    '#maxlength' => 250,
    '#prefix' =>'<div class="row"><div class="small-6 columns">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => AUDIENCIA_CURSO),
  );
   
  $categories = get_parents(2);
  $form['descripcion_objetivo']['selCategoria'] = array(
    '#title' =>CATEGORIA_CURSO,
    '#key_type' => 'associative',
    '#required' => TRUE,
    '#type' => 'select',
    '#options' => $categories,
    '#prefix' =>'<div class="small-6 columns"><div class="row"><div class="small-12 columns"><label class="labelSelect">' ,
    '#suffix' => '</label></div>',
    '#default_value'=> isset($values['selCategoria']) ? $values['selCategoria']: '0', 
    //'#ajax' => array(
                //'event'=>'change',
                //'callback' => 'ajax_dropdown_callback',
                //'wrapper' => 'selSubcategoria'),
                //'path' => 'get_api?tid=1&f_name=get_term_children'),
  );
  
  //$selected = isset($form['descripcion_objetivo']['selCategoria']) ? $form['descripcion_objetivo']['selCategoria'] : key($categories);
  $selected = 1;
  $form['descripcion_objetivo']['selSubcategoria'] = array(
    '#title' =>SUBCATEGORIA_CURSO,
    '#required' => FALSE,
    '#type' => 'select',
    '#options' => get_term_children($selected),
    '#prefix' =>'<div class="small-12 columns" id="selSubcategoria"><label class="labelSelect">' ,
    '#suffix' => '</label></div>',
    '#default_value'=> isset($values['selSubcategoria']) ? $values['selSubcategoria']: '0',
  );
   
  $form['descripcion_objetivo']['btnSubcategoria'] = array(
   '#value' =>BOTON_SUBCATEGORIA,
    '#type' => 'button',
    '#prefix' =>'<div class="small-12 columns btn-gris">' ,
    '#suffix' => '</div></div></div></div>',
  );
   

  $languages = get_parents(3);
  $form['descripcion_objetivo']['selIdioma'] = array(
    '#title' =>IDIOMA,
    '#required' => FALSE,
    '#type' => 'select',
    '#options' =>$languages,
    '#prefix' =>'<div class="row"><div class="small-6 columns"><label class="labelSelect">' ,
    '#suffix' => '</label></div></div>',
    '#default_value'=> isset($values['selIdioma']) ? $values['selIdioma'] : '0',
  );


  $form['lblCamposObligatorios'] = array(
    '#markup' => '<div class="row"><div class="small-4 columns"><span class="form-required" title="'.CAMPOS_OBLIGATORIOS.'">* '.CAMPOS_OBLIGATORIOS.'</span></div>',
  );

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => BOTON_GUARDAR,
    '#prefix' =>'<div class="small-8 columns text-right"><div class="btn-primario">',
    '#suffix' => '</div>',
  );
  $form['next'] = array(
    '#type' => 'submit',
    '#value' => BOTON_SIGUIENTE,
    '#prefix' =>'<div class="btn-secundario">',
    '#suffix' => '</div></div>',
  );


  return 
  $form;
}

function creacioncurso_detalles_curso_form($form, &$form_state) {
  $values = isset($form_state['multistep_values']['detalles_curso']) ? $form_state['multistep_values']['detalles_curso'] : array();

  $nid = 0;
  if(isset($_SESSION['node']['nid']) && $_SESSION['node']['nid'] > 0)
    $nid = $_SESSION['node']['nid'];
    
  //se recibe por URL  
  if(isset($form['nid']['#value']) && $form['nid']['#value'] > 0)
    $nid = $form['nid']['#value'];
  
  $values = get_detalles_curso_values($nid);
  
 $form['detalles_curso']['txtTemario'] = array(
    '#title' =>TEMARIO,
    '#required' => TRUE,
    '#type' => 'textarea',
    '#default_value' => isset($values['txtTemario']) ? $values['txtTemario'] : NULL,
    '#prefix' =>'<div class="row"><div class="small-6 columns">' ,
    '#suffix' => '</div>',
  );
   
  $form['detalles_curso']['txtMetodologia'] = array(
    '#title' =>METODOLOGIA,
    '#required' => TRUE,
    '#type' => 'textarea',
    '#default_value' => isset($values['txtMetodologia']) ? $values['txtMetodologia'] : NULL,
    '#prefix' =>'<div class="small-6 columns">' ,
    '#suffix' => '</div></div>',
  );

  $modalidad = get_parents(9);
  $form['detalles_curso']['selModalidad'] = array(
    '#title' =>MODALIDAD,
    '#required' => FALSE,
    '#type' => 'select',
    '#options' => $modalidad,
    '#prefix' =>'<div class="row"><div class="small-6 columns"><label class="labelSelect">' ,
    '#suffix' => '</label></div>',
    '#default_value' => isset($values['selModalidad']) ? $values['selModalidad'] : NULL,
  );

   
  $form['detalles_curso']['selAcreditacion'] = array(
    '#title' =>ACREDITACION,
    '#required' => FALSE,
    '#type' => 'select',
    '#options' => array('0'=>'Selecciona', '1'=>'Acreditacion'),
    '#prefix' =>'<div class="small-6 columns"><label class="labelSelect">' ,
    '#suffix' => '</label></div></div>',
    '#default_value' => isset($values['selAcreditacion']) ? $values['selAcreditacion'] : NULL,
  );
   
  $form['detalles_curso']['chkColaboracion'] = array(
    '#title' =>COLABORACION,
    '#type' => 'checkbox',
    '#prefix' =>'<div class="row"><div class="small-6 columns">' ,
    '#suffix' => '</div>',
    '#default_value' => isset($values['chkColaboracion']) ? $values['chkColaboracion'] : NULL, //para validar el check box???
  );
   
  $form['detalles_curso']['radLimiteAlumnos'] = array(
    '#title' =>LIMITE_ALUMNOS,
    '#type' => 'radios',
    '#options' => array(
      '1'=>'Si',
      '0'=>'Indefinido'),
    '#prefix' =>'<div class="small-6 columns">' ,
    '#suffix' => '</div></div>',
    '#default_value' => isset($values['radLimiteAlumnos']) ? $values['radLimiteAlumnos'] : NULL, //para validar el select list???
  );
   
  $form['detalles_curso']['txtNumeroAlumnos'] = array(
    '#title' =>NUMERO_ALUMNOS,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtNumeroAlumnos']) ? $values['txtNumeroAlumnos'] : NULL,
    '#maxlength' => 4,
    '#prefix' =>'<div class="row"><div class="small-6 columns">&nbsp;</div><div class="small-6 columns">' ,
    '#suffix' => '</div></div>',
    '#attributes' =>array('placeholder' => NUMERO_ALUMNOS),
  );
   
  $form['detalles_curso']['radFechaImparticion'] = array(
    '#title' =>FECHA_IMPARTICION,
    '#type' => 'radios',
    '#options' => array(
      '0'=>'Cerrado',
      '1'=>'Abierto'),
    '#prefix' =>'<div class="row"><div class="small-6 columns">' ,
    '#suffix' => '</div>',
    '#default_value' => isset($values['selFechaImparticion']) ? $values['selFechaImparticion'] : NULL,
  );
   
  $form['detalles_curso']['radDuracion'] = array(
    '#title' =>DURACION_CURSO,
    '#type' => 'radios',
    '#options' => array(
      'semanas'=>'Semanas Totales',
      'horas'=>'Horas de Trabajo'),
    '#prefix' =>'<div class="small-6 columns">' ,
    '#suffix' => '</div></div>',
    '#default_value' => isset($values['selDuracionCurso']) ? $values['selDuracionCurso'] : NULL,
  );

  $form['detalles_curso']['txtFechaInicio'] = array(
    '#title' =>INICIO,
    '#type' => 'textfield',

    '#prefix' =>'<div class="row"><div class="small-6 columns"><label class="popup-fecha label-hidden">' ,
    '#suffix' => '</label></div>',
    '#default_value' => isset($fecha_inicio_arr) ? $fecha_inicio_arr : '',
    '#attributes' =>array('placeholder' => FORMATO_FECHA),
  );

  $form['detalles_curso']['txtSemanal'] = array(
    '#title' =>POR_SEMANA,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtSemanal']) ? $values['txtSemanal'] : NULL,
    '#maxlength' => 2,
    '#prefix' =>'<div class="small-6 columns end label-hidden">' ,
    '#suffix' => '</div></div>',
    '#attributes' =>array('placeholder' => POR_SEMANA),
  );

 $form['detalles_curso']['txtFechaFin'] = array(
    '#title' =>FIN,
    '#type' => 'textfield',

    '#prefix' =>'<div class="row"><div class="small-6 columns"><label class="popup-fecha label-hidden">' ,
    '#suffix' => '</label></div>',
    '#default_value' => isset($fecha_fin_arr) ? array('year'=>(int)$fecha_fin_arr[0],'month'=>(int)$fecha_fin_arr[1], 'day'=>(int)$fecha_fin_arr[2]) : NULL,
    '#attributes' =>array('placeholder' => FORMATO_FECHA),
  );
  
   //YA ESTÁ DEFINIDO
   
  $form['detalles_curso']['txtTotales'] = array(
    '#title' =>TOTALES,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtTotales']) ? $values['txtTotales'] : NULL,
    '#maxlength' => 4,
    '#prefix' =>'<div class="small-6 columns end label-hidden">' ,
    '#suffix' => '</div></div>',
    '#attributes' =>array('placeholder' => TOTALES),
  );
   
  $form['detalles_curso']['txtReqPrevios'] = array(
    '#title' =>REQUERIMIENTOS,
    '#required' => FALSE,
    '#type' => 'textarea',
    '#default_value' => isset($values['txtReqPrevios']) ? $values['txtReqPrevios'] : NULL,
    '#prefix' =>'<div class="row"><div class="small-6 columns">' ,
    '#suffix' => '</div>',
  );
   
  $form['detalles_curso']['txtModuloCertificado'] = array(
    '#title' =>MODULO_CERTIFICADO,
    '#required' => FALSE,
    '#type' => 'textarea',
    '#default_value' => isset($values['txtModuloCertificado']) ? $values['txtModuloCertificado'] : NULL,
    '#prefix' =>'<div class="small-6 columns">' ,
    '#suffix' => '</div></div>',
  );
   

   



  $form['lblCamposObligatorios'] = array(
    '#markup' => '<div class="row"><div class="small-4 columns"><span class="form-required" title="'.CAMPOS_OBLIGATORIOS.'">* '.CAMPOS_OBLIGATORIOS.'</span></div>',
  );

  $form['back'] = array(
    '#type' => 'submit',
    '#value' => BOTON_ANTERIOR,
    '#prefix' =>'<div class="small-8 columns text-right"><div class="btn-secundario">',
    '#suffix' => '</div>',
  );
  $form['save'] = array(
    '#type' => 'submit',
    '#value' => BOTON_GUARDAR,
    '#prefix' =>'<div class="btn-primario">',
    '#suffix' => '</div>',
  );
  $form['next'] = array(
    '#type' => 'submit',
    '#value' => BOTON_SIGUIENTE,
    '#prefix' =>'<div class="btn-secundario">',
    '#suffix' => '</div></div></div>',
  );
  return $form;
}

function creacioncurso_evaluacion_form($form, &$form_state) {
  $values = isset($form_state['multistep_values']['evaluacion']) ? $form_state['multistep_values']['evaluacion'] : array();
  
  $nid = 0;
  if(isset($_SESSION['node']['nid']) && $_SESSION['node']['nid'] > 0)
    $nid = $_SESSION['node']['nid'];
    
  //se recibe por URL  
  if(isset($form['nid']['#value']) && $form['nid']['#value'] > 0)
    $nid = $form['nid']['#value'];
  
  $values = get_evaluacion_values($nid);
  
  $form['evaluacion']['radTutoreo'] = array(
    '#title' =>TUTOREO,
    '#type' => 'radios',
    '#options' => array('1' => TUTOREO_PERSONALIZADO, '0' => TUTOREO_AUTOESTUDIO),
    '#prefix' =>'<div class="row"><div class="small-12 columns">' ,
    '#suffix' => '</div><hr/></div>',
    '#default_value' => isset($values['radTutoreo']) ? $values['radTutoreo'] : NULL,
  );
   
     
  $form['evaluacion']['txtBusquedaProfesor'] = array(
    '#title' =>SELECT_PROFESOR,
    '#required' => FALSE,
    '#type' => 'textfield',
    //'#default_value' => isset($values['txtBusquedaProfesor']) ? $values['txtBusquedaProfesor'] : NULL,
    '#maxlength' => 60,
    '#prefix' =>'<div class="row"><div class="small-8 columns">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => SELECT_PROFESOR),
  );
    //$api_call = $GLOBALS['base_url'].'/api?f_name=get_profesor_names';
     
   /*PENDIENTE LA FUNCIONALIDAD DE AUTOCOMPLETE EN LA FORMA. YA SE IMPORTA LA LIBRERIA. EL SERVICIO DE API YA ESTA PROGRAMADO PARA REGRESAR LA BUSQUEDA*/ 
    /*drupal_add_js('jQuery(document).ready(function () { var options, a; function($){serviceUrl:"'.$api_call.'",lookup: [\'January\', \'February\', \'March\', \'April\', \'May\'];}; a =        (\'#txtBusquedaProfesor\').autocomplete(options); }); });', 'inline'); */
    
  $form['evaluacion']['btnAgregarProfesor'] = array(
    '#value' =>AGREGAR_PROFESOR,
    '#type' => 'button',
    '#prefix' =>'<div class="small-4 columns btn-gris">' ,
    '#suffix' => '</div><hr/></div>',
  );
     
  $form['evaluacion']['txtEvaluacion'] = array(
    '#title' =>EVALUACION,
    '#required' => TRUE,
    '#type' => 'textarea',
    '#prefix' =>'<div class="row"><div class="small-12 columns">' ,
    '#suffix' => '</div></div>',
    '#default_value' => isset($values['txtEvaluacion']) ? $values['txtEvaluacion'] : NULL,
  );
     


  $form['lblCamposObligatorios'] = array(
    '#markup' => '<div class="row"><div class="small-4 columns"><span class="form-required" title="'.CAMPOS_OBLIGATORIOS.'">* '.CAMPOS_OBLIGATORIOS.'</span></div>',
  );

  $form['back'] = array(
    '#type' => 'submit',
    '#value' => BOTON_ANTERIOR,
    '#prefix' =>'<div class="small-8 columns text-right"><div class="btn-secundario">',
    '#suffix' => '</div>',
  );
  $form['save'] = array(
    '#type' => 'submit',
    '#value' => BOTON_GUARDAR,
    '#prefix' =>'<div class="btn-primario">',
    '#suffix' => '</div>',
  );
  $form['next'] = array(
    '#type' => 'submit',
    '#value' => BOTON_SIGUIENTE,
    '#prefix' =>'<div class="btn-secundario">',
    '#suffix' => '</div></div></div>',
  );
    
  return $form;
}

function creacioncurso_imagen_video_form($form, &$form_state) {

  $values = isset($form_state['multistep_values']['imagen_video']) ? $form_state['multistep_values']['imagen_video'] : array();
  
  $nid = 0;
  //se preserva con session
  if(isset($_SESSION['node']['nid']) && $_SESSION['node']['nid'] > 0)
    $nid = $_SESSION['node']['nid'];
    
  //se recibe por URL  
  if(isset($form['nid']['#value']) && $form['nid']['#value'] > 0)
    $nid = $form['nid']['#value'];
    
  $values = get_imagen_video_values($nid);

  if( $values['fid'] > 0 )
  {
    $form['lblArchivoExistente'] = array(
    '#markup' => '<div id="edit-filimagenvideo" class="form-managed-file">Archivo existente:
                      <span class="file"><img class="file-icon" alt="" title="image/jpeg" src="'.$GLOBALS['base_url'].'/modules/file/icons/image-x-generic.png">
                        <a href="'.$values['uri'].'">'.$values['display_file']['filename'].'</a>
                      </span>',
    );

    $form['remove_file'] = array(
    '#type' => 'button',
    '#value' => 'Quitar',
    '#ajax' => array(
      'callback' => 'crearcurso_remove_file_callback',
      'wrapper' => 'edit-filimagenvideo',
      'method' => 'replace',
      'effect' => 'fade',
      ),
    );
     
    $form['current_file_var'] = array(
      '#type' => 'hidden',
      '#value' => 'image_fid_'.$nid,
      '#suffix'=> '</div>',
    );
  }

  $form['imagen_video']['filImagenVideo'] = array(
    '#title' =>SUBIR_IMAGEN,
    '#type' => 'managed_file',
    '#upload_location' => 'public://cursos/images/',
    '#upload_validators' => array(
      'file_validate_extensions' => array('gif png jpg jpeg JPG JPEG'),
      'file_validate_size' => array(2048*1024*1024),
    ),
    '#process' => array('crearcurso_element_process'),
    '#prefix' =>'<div class="row"><div class="small-8 columns">' ,
    '#suffix' => '</div></div>',
    //'#default_value' =>  $fid > 0  ?  $fid : NULL,
  );
   
  $form['imagen_video']['txtVideo'] = array(
    '#title' =>SUBIR_VIDEO,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtVideo']) ? $values['txtVideo'] : NULL,
    '#maxlength' => 250,
    '#prefix' =>'<div class="row"><div class="small-8 columns">' ,
    '#suffix' => '</div><hr/></div>',
    '#attributes' =>array('placeholder' => SUBIR_VIDEO),
  );
   
 $form['lblCamposObligatorios'] = array(
    '#markup' => '<div class="row"><div class="small-4 columns"><span class="form-required" title="'.CAMPOS_OBLIGATORIOS.'">* '.CAMPOS_OBLIGATORIOS.'</span></div>',
  );

  $form['back'] = array(
    '#type' => 'submit',
    '#value' => BOTON_ANTERIOR,
    '#prefix' =>'<div class="small-8 columns text-right"><div class="btn-secundario">',
    '#suffix' => '</div>',
  );
  $form['save'] = array(
    '#type' => 'submit',
    '#value' => BOTON_GUARDAR,
    '#prefix' =>'<div class="btn-primario">',
    '#suffix' => '</div>',
  );
  $form['next'] = array(
    '#type' => 'submit',
    '#value' => BOTON_SIGUIENTE,
    '#prefix' =>'<div class="btn-secundario">',
    '#suffix' => '</div></div></div>',
  );
    
  return $form;
}

function creacioncurso_bibliografia_recomendaciones_form($form, &$form_state) {

  $values = isset($form_state['multistep_values']['bibliografia_recomendaciones']) ? $form_state['multistep_values']['bibliografia_recomendaciones'] : array();

  $nid = 0;
  if(isset($_SESSION['node']['nid']) && $_SESSION['node']['nid'] > 0)
    $nid = $_SESSION['node']['nid'];
    
  if(isset($form['nid']['#value']) && $form['nid']['#value'] > 0)
    $nid = $form['nid']['#value'];
  
  $values = get_bibliografia_values($nid);
  
  $form['bibliografia_recomendaciones']['txtBibliografiaOficial'] = array(
    '#title' =>BIBLIOGRAFIA_OFICIAL,
    '#required' => FALSE,
    '#type' => 'textarea',
    '#prefix' =>'<div class="row"><div class="small-12 columns">' ,
    '#suffix' => '</div></div>',
    '#default_value' => isset($values['txtBibliografiaOficial']) ? $values['txtBibliografiaOficial'] : NULL, 
  );
   
  $form['bibliografia_recomendaciones']['txtBibliografiaRecomendada'] = array(
    '#title' =>BIBLIOGRAFIA_RECOMENDADA,
    '#required' => FALSE,
    '#type' => 'textarea',
    '#prefix' =>'<div class="row"><div class="small-12 columns">' ,
    '#suffix' => '</div><hr/></div>',
    '#default_value' => isset($values['txtBibliografiaRecomendada']) ? $values['txtBibliografiaRecomendada'] : NULL, 
  );
   
  $form['bibliografia_recomendaciones']['txtProductosRecomendados'] = array(
    '#title' =>AGREGAR_PRODUCTO_TEXTO,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtProductosRecomendados']) ? $values['txtProductosRecomendados'] : NULL,
    '#maxlength' => 250,
    '#prefix' =>'<div class="row"><div class="small-8 columns">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => AGREGAR_PRODUCTO_TEXTO),
  );
   
  $form['bibliografia_recomendaciones']['btnProductosRecomendados'] = array(
    '#value' =>AGREGAR_PRODUCTO_BOTON,
    '#type' => 'button',
    '#prefix' =>'<div class="small-4 columns btn-gris">' ,
    '#suffix' => '</div></div>',
  );
   

  $form['lblCamposObligatorios'] = array(
    '#markup' => '<div class="row"><div class="small-4 columns"><span class="form-required" title="'.CAMPOS_OBLIGATORIOS.'">* '.CAMPOS_OBLIGATORIOS.'</span></div>',
  );

  $form['back'] = array(
    '#type' => 'submit',
    '#value' => BOTON_ANTERIOR,
    '#prefix' =>'<div class="small-8 columns text-right"><div class="btn-secundario">',
    '#suffix' => '</div>',
  );
  $form['save'] = array(
    '#type' => 'submit',
    '#value' => BOTON_GUARDAR,
    '#prefix' =>'<div class="btn-primario">',
    '#suffix' => '</div>',
  );
  $form['next'] = array(
    '#type' => 'submit',
    '#value' => BOTON_SIGUIENTE,
    '#prefix' =>'<div class="btn-secundario">',
    '#suffix' => '</div></div></div>',
  );
    
  return $form;
}

function creacioncurso_preguntas_frecuentes_form($form, &$form_state) {

  $values = isset($form_state['multistep_values']['preguntas_frecuentes']) ? $form_state['multistep_values']['preguntas_frecuentes'] : array();

  $nid = 0;
  //se preserva con session
  if(isset($_SESSION['node']['nid']) && $_SESSION['node']['nid'] > 0)
    $nid = $_SESSION['node']['nid'];
  //se recibe por URL  
  if(isset($form['nid']['#value']) && $form['nid']['#value'] > 0)
    $nid = $form['nid']['#value'];
 
  $values = get_preguntas_frecuentes_edit($nid);
  
  $form['preguntas_frecuentes']['lblTitulo'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns"><h6>'.TITULO_PREG_FRECUENTE.'</h6></div></div>',
  );
      
  $form['preguntas_frecuentes']['divPreguntasFrecuentes'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns"> <div class=" resaltado" id="divPreguntasFrecuentes">
      Cargando...
      </div></div></div>',
  );

  // TODO integrar a front para desplegar dinámicamente las diferentes preguntas.
  // TODO falta campo hidden que almacene el id de la pregunta en la tabla.
  // La estructura de la pregunta es así:
  /*public 'id_pregunta' => string '9' (length=1)
    public 'pregunta' => string 'pregunta 3' (length=10)
    public 'respuesta' => string 'respuesta 3' (length=11)*/ 

  $form['preguntas_frecuentes']['txtPreguntaFrecuente'] = array(
    '#title' =>PREGUNTA_FRECUENTE,
    '#required' => FALSE,
    '#type' => 'textfield',
    //'#default_value' => isset($values['txtPreguntaFrecuente'][]) ? $values['txtPreguntaFrecuente'] : NULL,
    '#maxlength' => 250,
    '#prefix' =>'<div class="row"><div class="small-12 columns">' ,
    '#suffix' => '</div></div>',
    '#attributes' =>array('placeholder' => PREGUNTA_FRECUENTE),
  );
   
  $form['preguntas_frecuentes']['txtRespuestaPreguntaFrecuente'] = array(
    '#title' =>RESPUESTA_PREG_FRECUENTE,
    '#required' => FALSE,
    '#type' => 'textarea',
    '#prefix' =>'<div class="row"><div class="small-12 columns">' ,
    '#suffix' => '</div></div><div class="row"><div class="small-6 columns">&nbsp;</div>',
  );
   
  $form['pago']['lblEliminarPregunta'] = array(
     '#markup' => '<div class="small-3 columns btn-gris text-right"> 
        <input type="button" name="btnEliminarPregunta" id="btnEliminarPregunta" value='.ELIMINAR_PREGUNTA_FRECUENTE.'></div>
    ',
  );
   $form['pago']['lblAgregarPregunta'] = array(
     '#markup' => '<div class="small-3 columns btn-gris text-right"> 
        <input type="button" name="btnAgregarPregunta" id="btnAgregarPregunta" value='.AGREGAR_PREGUNTA_FRECUENTE.'>
        </div><hr></div>
    ',
  );

  $form['lblCamposObligatorios'] = array(
    '#markup' => '<div class="row"><div class="small-4 columns"><span class="form-required" title="'.CAMPOS_OBLIGATORIOS.'">* '.CAMPOS_OBLIGATORIOS.'</span></div>',
  );

  $form['back'] = array(
    '#type' => 'submit',
    '#value' => BOTON_ANTERIOR,
    '#prefix' =>'<div class="small-8 columns text-right"><div class="btn-secundario">',
    '#suffix' => '</div>',
  );
  $form['save'] = array(
    '#type' => 'submit',
    '#value' => BOTON_GUARDAR,
    '#prefix' =>'<div class="btn-primario">',
    '#suffix' => '</div>',
  );
  $form['next'] = array(
    '#type' => 'submit',
    '#value' => BOTON_SIGUIENTE,
    '#prefix' =>'<div class="btn-secundario">',
    '#suffix' => '</div></div></div>',
  );
 
  return $form;
}
function creacioncurso_configuracion_pagos_form($form, &$form_state) {
  global $user;
  $values = isset($form_state['multistep_values']['configuracion_pagos']) ? $form_state['multistep_values']['configuracion_pagos'] : array();

  $nid = 0;
  if(isset($_SESSION['node']['nid']) && $_SESSION['node']['nid'] > 0)
    $nid = $_SESSION['node']['nid'];

  if(isset($form['nid']['#value']) && $form['nid']['#value'] > 0)
    $nid = $form['nid']['#value'];
    
  $cuentas = get_cuentas_deposito_usuario($user->uid);
  $values = get_configuracion_pagos_values($nid);
  
  
  $form['configuracion_pagos']['chkCursoGratuito'] = array(
    '#title' =>CURSO_GRATUITO,
    '#type' => 'checkbox',
    '#prefix' =>'<div class="row"><div class="small-12 columns">' ,
    '#suffix' => '</div><hr></div>',
    '#default_value' => isset($values['chkCursoGratuito']) ? $values['chkCursoGratuito'] : NULL, //para validar el check box???
  );
   
  $form['configuracion_pagos']['txtCostoCurso'] = array(
    '#title' =>COSTO_CURSO,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtCostoCurso']) ? $values['txtCostoCurso'] : NULL,
    '#maxlength' => 6,
    '#prefix' =>'<div class="row resaltado"><div class="small-4 columns">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => COSTO_CURSO),
  );
   
  $form['configuracion_pagos']['txtDescuentoCurso'] = array(
    '#title' =>DESCUENTO_CURSO,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtDescuentoCurso']) ? $values['txtDescuentoCurso'] : NULL,
    '#maxlength' => 6,
    '#prefix' =>'<div class="small-4 columns">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => DESCUENTO_CURSO),
  );
   
  $form['configuracion_pagos']['chkDonacion'] = array(
    '#title' =>DONAR_CURSO,
    '#type' => 'checkbox',
    '#prefix' =>'<div class="small-4 columns">' ,
    '#suffix' => '</div>',
    '#default_value' => isset($values['chkDonacion']) ? $values['chkDonacion'] : NULL,
  );
   
  $form['configuracion_pagos']['txtMontoDonacion'] = array(
    '#title' =>MONTO_DONAR,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtMontoDonacion']) ? $values['txtMontoDonacion'] : NULL,
    '#maxlength' => 3,
    '#prefix' =>'<div class="small-4 columns label-hidden" style="margin-top:-19px;">' ,
    '#suffix' => '</div></div>',
    '#attributes' =>array('placeholder' => MONTO_DONAR),
  );
   
  $form['configuracion_pagos']['selCuentaDeposito'] = array(
    '#title' =>CUENTA_DEPOSITO,
    '#required' => TRUE,
    '#type' => 'select',
    '#options' => count($cuentas)>0 ? $cuentas : array('0'=>'Sin cuentas de depósito'),
    '#prefix' =>'<div class="row"><hr/><div class="small-6 columns"><label class="labelSelect">' ,
    '#suffix' => '</label></div></div>',
    '#default_value' => isset($values['selCuentaDeposito']) ? $values['selCuentaDeposito']: NULL,
  );

  $form['configuracion_pagos']['lblTipCuentaDeposito'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns">'.TIP_CUENTA_DEPOSITO.'</div><hr/></div>',
  );
  $form['configuracion_pagos']['lblTipComprobanteFiscal'] = array(
    '#markup' => '<div class="row resaltado"><div class="small-12 columns">'.TIP_COMPROBANTE_FISCAL.'</div></div>',
  );

  $form['configuracion_pagos']['btnFiscal'] = array(
    '#title' =>COMPROBANTE_FISCAL,
    '#type' => 'radios',
    '#prefix' =>'<div class="row"><div class="small-12 columns">' ,
    '#options' => array('1' => SI, '0' => NO),
    '#suffix' => '</div></div>',
    '#default_value' => isset($values['btnFiscal'])?$values['btnFiscal']:NULL
  );
  
  if( $values['fid'] > 0 )
  {
    $form['lblArchivoExistente'] = array(
    '#markup' => '<div id="edit-filcsd2" class="form-managed-file">Archivo existente:
                      <span class="file"><img class="file-icon" alt="" title="application/pdf" src="'.$GLOBALS['base_url'].'/modules/file/icons/application-pdf.png">
                        <a href="'.$values['uri'].'">'.$values['display_file']['filename'].'</a>
                      </span>',
    );

    $form['remove_file'] = array(
    '#type' => 'button',
    '#value' => 'Quitar',
    //'#prefix' =>'<div class="form-submit ajax-processed">',
    '#ajax' => array(
      'callback' => 'crearcurso_remove_file_callback',
      'wrapper' => 'edit-filcsd2',
      'method' => 'replace',
      'effect' => 'fade',
      ),
    );
     
    $form['current_file_var'] = array(
      '#type' => 'hidden',
      '#value' => 'csd_fid_'.$nid,
      '#suffix'=> '</div>',
    ); 
  }
  
  $form['configuracion_pagos']['filCSD'] = array(
    '#title' =>CERTIFICADO_CSD,
    '#required' => FALSE,
    '#type' => 'managed_file',
    '#upload_location' => 'public://cursos/',
    '#prefix' =>'<div class="row"><div class="small-6 columns">' ,
    '#suffix' => '</div></div>',
    '#process' => array('crearcurso_element_process'),
    '#upload_validators' => array(
      'file_validate_extensions' => array(),
      'file_validate_size' => array(3024*3024*3024),
    ),
    //'#default_value' => $fid,     
  );
   

  $form['lblCamposObligatorios'] = array(
    '#markup' => '<div class="row"><div class="small-4 columns"><span class="form-required" title="'.CAMPOS_OBLIGATORIOS.'">* '.CAMPOS_OBLIGATORIOS.'</span></div>',
  );

  $form['back'] = array(
    '#type' => 'submit',
    '#value' => BOTON_ANTERIOR,
    '#prefix' =>'<div class="small-8 columns text-right"><div class="btn-secundario">',
    '#suffix' => '</div>',
  );
  $form['save'] = array(
    '#type' => 'submit',
    '#value' => BOTON_GUARDAR,
    '#prefix' =>'<div class="btn-primario">',
    '#suffix' => '</div>',
  );
  $form['next'] = array(
    '#type' => 'submit',
    '#value' => BOTON_SIGUIENTE,
    '#prefix' =>'<div class="btn-secundario">',
    '#suffix' => '</div></div></div>',
  );
    
  return $form;
}

function creacioncurso_datos_especificos_form($form, &$form_state) {

  $values = isset($form_state['multistep_values']['datos_especificos']) ? $form_state['multistep_values']['datos_especificos'] : array();
  
  $nid = 0;
  if(isset($_SESSION['node']['nid']) && $_SESSION['node']['nid'] > 0)
    $nid = $_SESSION['node']['nid'];

  if(isset($form['nid']['#value']) && $form['nid']['#value'] > 0)
    $nid = $form['nid']['#value'];
  
  $datos = get_datos_especificos($nid);
 
  $form['datos_especificos']['lblDatosEspecificosAlumnos'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns">'.DATOS_ESPECIFICOS_ALUMNO.'</div><hr/></div>',
  );
  $form['datos_especificos']['divTipAlumnos'] = array(
    '#markup' => '<div class="row resaltado"><div class="small-12 columns">'.TIP_ALUMNOS.'</div></div>',
  );

   $form['datos_especificos']['datos_personales'] = array(
    '#options' => array(
      '1' => t('Nombres'),
      '2' => t('Apellidos'),
      '3' => t('RFC'),
      '4' => t('CURP'),
      '5' => t('Grado máximo de estudios'),
      '6' => t('Género'),
      '7' => t('Teléfonos con LADA'),
      '8' => t('Teléfono móvil'),
      '9' => t('Clave presupuestal'),
    ),
    '#type' => 'checkboxes',
    '#title' => DATOS_ALUMNO_PERSONALES,
    '#required' => false,
    '#prefix' =>'<div class="row"><div class="small-12 columns"><label class="mitad-pantalla">' ,
    '#suffix' => '</label></div></div>',
    '#default_value' => count($datos[1]) >0 ? $datos[1] : NULL,
    //'#default_value' => isset($values['colaboracion']) ? $values['colaboracion'] : NULL, //para validar el check box???
  );
   $form['datos_especificos']['datos_escuela'] = array(
    '#options' => array(
      '10' => t('Nombre Escuela o centro donde labora'),
      '11' => t('Nivel que atiende'),
      '12' => t('Clave del centro de trabajo'),
      '13' => t('Calle'),
      '14' => t('Número'),
      '15' => t('Colonia'),
      '16' => t('Código postal'),
      '17' => t('Ciudad'),
      '18' => t('Estado'),
      '19' => t('País'),
    ),
    '#type' => 'checkboxes',
    '#title' => DATOS_ALUMNO_ESCUELA,
    '#required' => false,
    '#prefix' =>'<div class="row"><div class="small-12 columns mitad-pantalla">' ,
    '#suffix' => '</div></div>',
    '#default_value' => count($datos[2]) >0 ? $datos[2] : NULL,
  );
   $form['datos_especificos']['datos_beca'] = array(
    '#options' => array(
      '20' => t('Institución que lo beca'),
      '21' => t('Clave de beca'),
    ),
    '#type' => 'checkboxes',
    '#title' => DATOS_ALUMNO_BECA,
    '#required' => false,
    '#prefix' =>'<div class="row"><div class="small-12 columns mitad-pantalla">' ,
    '#suffix' => '</div></div>',
    '#default_value' => count($datos[3]) > 0 ? $datos[3] : NULL,
  );


  $form['lblCamposObligatorios'] = array(
    '#markup' => '<div class="row"><div class="small-4 columns"><span class="form-required" title="'.CAMPOS_OBLIGATORIOS.'">* '.CAMPOS_OBLIGATORIOS.'</span></div>',
  );

  $form['back'] = array(
    '#type' => 'submit',
    '#value' => BOTON_ANTERIOR,
    '#prefix' =>'<div class="small-8 columns text-right"><div class="btn-secundario">',
    '#suffix' => '</div>',
  );
  $form['save'] = array(
    '#type' => 'submit',
    '#value' => BOTON_GUARDAR,
    '#prefix' =>'<div class="btn-primario">',
    '#suffix' => '</div>',
  );
  $form['next'] = array(
    '#type' => 'submit',
    '#value' => BOTON_SIGUIENTE,
    '#prefix' =>'<div class="btn-secundario">',
    '#suffix' => '</div></div></div>',
  );
    
  return $form;
}

function creacioncurso_seleccion_canal_form($form, &$form_state) {

  $values = isset($form_state['multistep_values']['seleccion_canal']) ? $form_state['multistep_values']['configuracion_curso'] : array();
  
  $values = get_canal_values($nid);
  $form['seleccion_canal']['lblGenerarContenido'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns">'.GENERAR_CONT.'</div></div>',
  );

  $form['seleccion_canal']['divExplicacion'] = array(
    '#markup' => '<div class="small-12 small-centered columns"><div class=" resaltado">'.TIP_CONTENIDO_CANAL.'</div></div></div>',
  );
  $form['seleccion_canal']['hCanalSeleccionado'] = array(
    '#type' => 'hidden',
    '#id' => 'hCanalSeleccionado',
    '#default_value' => isset($values['hCanalSeleccionado'])?$values['hCanalSeleccionado']:NULL,
  );

  $form['seleccion_canal']['divContenido'] = array(
    '#markup' => '<div class="small-12 columns">
    <div class="row">
      <div class="large-6 columns">
        <div id="tab-1" class="row tab active-tab">'.MIS_CANALES.'</div>
      </div>
      <div class="large-6 columns">
        <div id="tab-2" class="row tab inactive-tab">'.CANALES_QUE_ADMINISTRO.'</div>
      </div>       
    </div>

    <div class="contenedor-panels row">
      <div class="inactive-panel" id="panel-1">
      </div>
      <div class="inactive-panel" id="panel-2">             
      </div>       
    </div>


    </div></div></div>',
  );
   
$form['lblCamposObligatorios'] = array(
    '#markup' => '<div class="row"><div class="small-4 columns"><span class="form-required" title="'.CAMPOS_OBLIGATORIOS.'">* '.CAMPOS_OBLIGATORIOS.'</span></div>',
  );


  $form['back'] = array(
    '#type' => 'submit',
    '#value' => BOTON_ANTERIOR,
    '#prefix' =>'<div class="small-8 columns text-right"><div class="btn-secundario">',
    '#suffix' => '</div>',
  );
  $form['save'] = array(
    '#type' => 'submit',
    '#value' => BOTON_GUARDAR,
    '#prefix' =>'<div class="btn-primario">',
    '#suffix' => '</div>',
  );
  $form['next'] = array(
    '#type' => 'submit',
    '#value' => BOTON_SIGUIENTE,
    '#prefix' =>'<div class="btn-secundario">',
    '#suffix' => '</div></div></div>',
  );
    
  return $form;
}

function creacioncurso_configuracion_LMS_form($form, &$form_state) {

  $values = isset($form_state['multistep_values']['configuracion_lms']) ? $form_state['multistep_values']['configuracion_lms'] : array();
  
  /*$nid = 0;
  if(isset($_SESSION['node']['nid']) && $_SESSION['node']['nid'] > 0)
    $nid = $_SESSION['node']['nid'];

  if(isset($form['nid']['#value']) && $form['nid']['#value'] > 0)
    $nid = $form['nid']['#value'];
    
  $values = get_configuracion_LMS_values($nid);
  */$form['configuracion_lms']['lblGenerarContenido'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns">'.GENERAR_CONT.'</div></div>',
  );


  $form['configuracion_lms']['chkContenidoFed'] = array(
    '#title' =>'',
    '#type' => 'radios',
    '#options' => array('1' => SI, '0' => NO),
    '#prefix' =>'<div class="row"><div class="small-2 columns">' ,
    '#suffix' => '</div>',
    '#default_value' => isset($values['chkContenidoFed']) ? $values['chkContenidoFed'] : NULL,
  );

  $form['configuracion_lms']['divTipAlumnos'] = array(
    '#markup' => '<div class="small-12 columns no-padding"><div class=" resaltado ">'.TIP_CONTENIDO_FUTUREED.'</div></div></div>',
  );
   
  $form['configuracion_lms']['chkSoporte'] = array(
    '#title' =>SOPORTE_TECNICO,
    '#type' => 'radios',
    '#options' => array('1' => SI, '0' => NO),
    '#prefix' =>'<div class="row"><div class="small-12 columns">' ,
    '#suffix' => '</div><hr/></div>',
    '#default_value' => isset($values['chkSoporte']) ? $values['chkSoporte'] :NULL,
  );
   
  $form['configuracion_lms']['txtURLCallback'] = array(
    '#title' =>URL_CALLBACK,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtURLCallback']) ? $values['txtURLCallback'] : NULL,
    '#maxlength' => 250,
    '#prefix' =>'<div class="row"><div class="small-6 columns">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => URL_CALLBACK),
  );
   
$form['configuracion_lms']['txtIdCurso'] = array(
    '#title' =>ID_CURSO,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtIdCurso']) ? $values['txtIdCurso'] : NULL,
    '#maxlength' => 15,
    '#prefix' =>'<div class="small-6 columns">' ,
    '#suffix' => '</div></div>',
    '#attributes' =>array('placeholder' => ID_CURSO),
  );
   
  $form['configuracion_lms']['txtURLPortal'] = array(
    '#title' =>URL_PORTAL,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtURLPortal']) ? $values['txtURLPortal'] : NULL,
    '#maxlength' => 250,
    '#prefix' =>'<div class="row"><div class="small-6 columns">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => URL_PORTAL),
  );
   
  $form['configuracion_lms']['txtURLLMS'] = array(
    '#title' =>URL_LMS,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtURLLMS']) ? $values['txtURLLMS'] : NULL,
    '#maxlength' => 250,
    '#prefix' =>'<div class="small-6 columns">' ,
    '#suffix' => '</div></div>',
    '#attributes' =>array('placeholder' => URL_LMS),
  );
   
  $form['configuracion_lms']['txtEmailResponsable'] = array(
    '#title' =>CORREO_RESPONSABLE_TECNICO,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtEmailResponsable']) ? $values['txtEmailResponsable'] : NULL,
    '#maxlength' => 60,
    '#prefix' =>'<div class="row"><div class="small-6 columns end">' ,
    '#suffix' => '</div></div>',
    '#attributes' =>array('placeholder' => CORREO_RESPONSABLE_TECNICO),
  );
   


  
  $form['lblCamposObligatorios'] = array(
    '#markup' => '<div class="row"><div class="small-4 columns"><span class="form-required" title="'.CAMPOS_OBLIGATORIOS.'">* '.CAMPOS_OBLIGATORIOS.'</span></div>',
  );

  $form['back'] = array(
    '#type' => 'submit',
    '#value' => BOTON_ANTERIOR,
    '#prefix' =>'<div class="small-8 columns text-right"><div class="btn-secundario">',
    '#suffix' => '</div>',
  );
  $form['save'] = array(
    '#type' => 'submit',
    '#value' => BOTON_GUARDAR,
    '#prefix' =>'<div class="btn-primario">',
    '#suffix' => '</div></div></div>',
  );
    
  return $form;
}

