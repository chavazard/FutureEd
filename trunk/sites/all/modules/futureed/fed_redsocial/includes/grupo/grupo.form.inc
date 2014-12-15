<?php
/**
 * @file
 * Gestiona los formularios del grupo
 */




//Funciones para mostrar el formulario de grupos
//Creado el 21 de Noviembre del 2014
//Por Ricardo Aguilera 

/******-grupos-******/
function show_grupo_editor($tipoBusqueda){
  //print_r("asdf :o");
  
  $items['tipo'] = $tipoBusqueda; //no modificar
  return theme('grupo', array('items' => $items));
  //return theme('grupo', array($form, &$form_state));
}

//Funciones para renderear los formularios de grupos
function grupo_formulario($form, &$form_state){


    /**
    * setters para variabes locales
    */

    //Paths para guardar los archivos
    $directoriogrupo = 'public://grupo';

  $form['crear_grupo']['txtGrupo'] = array(
    '#title' =>GRUPO_NOMBRE,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtGrupo']) ? $values['txtGrupo'] : NULL,
    '#maxlength' => 60,
    '#prefix' =>'<div class="row"><div class="small-12 columns">' ,
    '#suffix' => '</div></div>',
    '#attributes' =>array('placeholder' => GRUPO_NOMBRE),
  );
     
  $form['crear_grupo']['txtDescripcion'] = array(
    '#title' =>GRUPO_DESCRIPCION,
    '#required' => TRUE,
    '#type' => 'textarea',
    '#prefix' =>'<div class="row"><div class="small-12 columns">' ,
    '#suffix' => '</div></div>',
  );
     
  $form['crear_grupo']['imgGrupo'] = array(
    '#title' =>GRUPO_IMAGEN,
    '#type' => 'managed_file',
    '#prefix' =>'<div class="row"><div class="small-12 columns">' ,
    '#suffix' => '</div></div>',
  );
     
  $form['crear_grupo']['selCategoria'] = array(
    '#title' =>GRUPO_CATEGORIA,
    '#required' => TRUE,
    '#type' => 'select',
    '#options' => array('0'=>'Selecciona'),
    '#prefix' =>'<div class="row"><div class="small-12 columns">' ,
    '#suffix' => '</div></div>',
  );
     
  $form['crear_grupo']['selSubcategoria'] = array(
    '#title' =>GRUPO_SUBCATEGORIA,
    '#required' => FALSE,
    '#type' => 'select',
    '#options' => array('0'=>'Selecciona'),
    '#prefix' =>'<div class="row"><div class="small-12 columns">' ,
    '#suffix' => '</div></div>',
  );
     
  $form['crear_grupo']['selCurso'] = array(
    '#title' =>GRUPO_CURSO,
    '#required' => FALSE,
    '#type' => 'select',
    '#options' => array('0'=>'Selecciona'),
    '#prefix' =>'<div class="row"><div class="small-12 columns">' ,
    '#suffix' => '</div></div>',
  );
     
  $form['crear_grupo']['divMiembros'] = array(
    '#title' =>GRUPO_MIEMBROS,
    '#type' => 'div',
    '#prefix' =>'<div class="row"><div class="small-12 columns">' ,
    '#suffix' => '</div></div>',
  );
     
  $form['crear_grupo']['selPrivacidad'] = array(
    '#title' =>GRUPO_PRIVACIDAD,
    '#required' => TRUE,
    '#type' => 'select',
    '#options' => array('0'=>'Selecciona'),
    '#prefix' =>'<div class="row"><div class="small-12 columns">' ,
    '#suffix' => '</div></div>',
  );
     
  $form['crear_grupo']['txtEtiquetas'] = array(
    '#title' =>GRUPO_ETIQUETAS,
    '#required' => TRUE,
    '#type' => 'textarea',
    '#prefix' =>'<div class="row"><div class="small-12 columns">' ,
    '#suffix' => '</div></div>',
  );
     

     
  $form['grupo']['lblCamposObligatorios'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns"><span class="form-required" title="'.CAMPOS_OBLIGATORIOS.'">* '.CAMPOS_OBLIGATORIOS.'</span></div><hr></div>',
  );

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => BOTON_CREAR_GRUPO,
    '#prefix' =>'<div class="row"><div class="small-12 columns">' ,
    '#suffix' => '</div></div>',
  );

  return $form;
}


/**
* Función para cargar los detalles del grupo
* Creada por Ricardo Aguilera
* El 21 de Noviembre del 2014
* Se deberá modificar para que se muestren los valores correctos
* que deberán cargarse desde la base e datos
*/
function get_detalle_grupo(){
  $items = array();

      $items['detallegrupo']=

      array(

          'intgrupo'=>'1',
          'strgrupo'=>'grupo bonito :o',
          'intCurso'=>'12',
          'strCurso'=>'Curso bonito',
          'intCategoria'=>'22',
          'strCategoria'=>'Categoría bonita',
          'strContenido'=>'Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. 

          Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. 

          Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. ',
          'imggrupo'=>'http://placehold.it/300x300',
          'pathArchivo'=>'http://placehold.it/500x500',
          'strArchivo'=>'nombre bonito del archivo',
          'datFecha'=>'01/12/13',



    );

  return $items;

}