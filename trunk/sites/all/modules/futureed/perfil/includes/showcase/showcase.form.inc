<?php
/**
 * @file
 * Gestiona los formularios del showcase
 */




//Funciones para mostrar el formulario de showcases
//Modificado el 20 de Noviembre del 2014
//Por Ricardo Aguilera 

/******-Showcases-******/
function show_showcase_editor($tipoBusqueda){
  //print_r("asdf :o");
  $items['tipo'] = $tipoBusqueda; //no modificar
  return theme('showcase', array('items' => $items));
  //return theme('showcase', array($form, &$form_state));
}

function show_showcase_detalle(){
  return theme('showcase_detalle',get_detalle_showcase());
}

//Funciones para renderear los formularios de showcases
function showcase_formulario($form, &$form_state){


    /**
    * setters para variabes locales
    */

    //Paths para guardar los archivos
    $directorioShowcase = 'public://showcase';

    $form['showcase']['filArchivo'] = array(
    '#title' =>SHOWCASE_ARCHIVO,
    '#type' => 'managed_file',
    '#prefix' =>'<div class="row"><div class="small-6 columns end">' ,
    '#suffix' => '</div></div>',
  );
     
  $form['showcase']['txtNombreProyecto'] = array(
    '#title' =>SHOWCASE_NOMBRE_PROYECTO,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtNombreProyecto']) ? $values['txtNombreProyecto'] : NULL,
    '#maxlength' => 60,
    '#prefix' =>'<div class="row"><div class="small-8 columns">' ,
    '#suffix' => '</div></div>',
    '#attributes' =>array('placeholder' => SHOWCASE_NOMBRE_PROYECTO),
  );
     
  $form['showcase']['txtInfoProyecto'] = array(
    '#title' =>SHOWCASE_INFO_PROYECTO,
    '#required' => TRUE,
    '#type' => 'textarea',
    '#prefix' =>'<div class="row"><div class="small-8 columns">' ,
    '#suffix' => '</div></div>',
  );
     
  $form['showcase']['txtCurso'] = array(
    '#title' =>SHOWCASE_CURSO,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtCurso']) ? $values['txtCurso'] : NULL,
    '#maxlength' => 60,
    '#prefix' =>'<div class="row"><div class="small-8 columns">' ,
    '#suffix' => '</div></div>',
    '#attributes' =>array('placeholder' => SHOWCASE_CURSO),
  );
     
  $form['showcase']['txtCategoria'] = array(
    '#title' =>SHOWCASE_CATEGORIA,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtCategoria']) ? $values['txtCategoria'] : NULL,
    '#maxlength' => 60,
    '#prefix' =>'<div class="row"><div class="small-8 columns">' ,
    '#suffix' => '</div></div>',
    '#attributes' =>array('placeholder' => SHOWCASE_CATEGORIA),
  );
     
  $form['showcase']['txtFecha'] = array(
    '#title' =>SHOWCASE_FECHA,
    '#type' => 'date',
    '#prefix' =>'<div class="row"><div class="small-8 columns">' ,
    '#suffix' => '</div></div>',
  );
     
  $form['showcase']['filFotografia'] = array(
    '#title' =>SHOWCASE_FOTOGRAFIA,
    '#type' => 'managed_file',
    '#upload_location' => $directorioShowcase,
    '#prefix' =>'<div class="row"><div class="small-12 columns">' ,
    '#suffix' => '</div></div>',
  );
     
  $form['pago']['lblCamposObligatorios'] = array(
    '#markup' => '<div class="row"><div class="small-4 columns"><span class="form-required" title="'.CAMPOS_OBLIGATORIOS.'">* '.CAMPOS_OBLIGATORIOS.'</span></div>',
  );

  $form['back'] = array(
    '#type' => 'submit',
    '#value' => BOTON_ANTERIOR,
    '#prefix' =>'<div class="small-8 columns">'
  );
  $form['next'] = array(
    '#type' => 'submit',
    '#value' => BOTON_VISTA_PREVIA,
  );
  $form['save'] = array(
    '#type' => 'submit',
    '#value' => BOTON_GUARDAR,
    '#suffix' => '</div></div>',
  );

  return $form;
}


/**
* Función para cargar los detalles del showcase
* Creada por Ricardo Aguilera
* El 20 de Noviembre del 2014
* Se deberá modificar para que se muestren los valores correctos
* que deberán cargarse desde la base e datos
*/
function get_detalle_showcase(){
  $items = array();

      $items['detalleShowcase']=

      array(

          'intShowcase'=>'1',
          'strShowcase'=>'showcase bonito :o',
          'intCurso'=>'12',
          'strCurso'=>'Curso bonito',
          'intCategoria'=>'22',
          'strCategoria'=>'Categoría bonita',
          'strContenido'=>'Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. 

          Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. 

          Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. ',
          'imgShowcase'=>'http://placehold.it/300x300',
          'pathArchivo'=>'http://placehold.it/500x500',
          'strArchivo'=>'nombre bonito del archivo',
          'datFecha'=>'01/12/13',



    );

  return $items;

}

/**
* Función para obtener el id del Showcase
* Creada por Ricardo Aguilera
* el 25 de Noviembre del 2014
* Deberá modificarse para agregarle funcionalidad real.
*/
function get_idShowcase(){

  return 23;

}

/**
* Función que sirve para regresar un null, que sólamente se necesita
* para poder agregar algún path al sistema y que no devuelva "page not found".
* en realidad, se puede utilizar para regresar un null a cualquier otra función, 
* sin que Drupal marque un error.
* Desarrollado por Ricardo Aguilera
* el 24 de Noviembre del 2014
*/ 

function showcase_void(){

  return "";
}