<?php
/**
 * Función para gestionar el formulario de  historial_compras.
 * Aquí se insertarán los campos correspondientes a este paso
 * Creado por Ricardo Aguilera
 * 
 * @see configuracioncuenta_form().
 *  
 * @param type $form
 * @param type $form_state
 * @return type 
 */
function configuracioncuenta_historial_compras($form, &$form_state) {
  
  $form['historial_compras']['filIntervaloCompras'] = array(
    '#title' =>FILTRO_INTERVALO,
    '#required' => FALSE,
    '#type' => 'select',
    '#options' => array(
      0=>"Seleccionar1",
      1=>"Seleccionar2",
      2=>"Seleccionar3",
      3=>"Seleccionar4",

      ),
    
    '#prefix' => '<div class="row"><div class="small-2 columns">',
    '#suffix' => '</div><div class="small-4 columns">&nbsp;</div>',
  );

  
  $form['historial_compras']['filEntrega'] = array(
    '#title' =>FILTRO_ENTREGA,
    '#required' => FALSE,
    '#type' => 'select',
    '#options' => array(
      0=>"Seleccionar1",
      1=>"Seleccionar2",
      2=>"Seleccionar3",
      3=>"Seleccionar4",

      ),
    
    '#prefix' => '<div class="small-2 columns">',
    '#suffix' => '</div>',
  );

  
  $form['historial_compras']['filEstatus'] = array(
    '#title' =>FILTRO_ESTATUS,
    '#required' => FALSE,
    '#type' => 'select',
    '#options' => array(
      0=>"Seleccionar1",
      1=>"Seleccionar2",
      2=>"Seleccionar3",
      3=>"Seleccionar4",

      ),
    
    '#prefix' => '<div class="small-2 columns">',
    '#suffix' => '</div>',
  );

   
  $form['historial_compras']['orden'] = array(
    '#title' =>ORDEN_HISTORIAL,
    '#required' => FALSE,
    '#type' => 'select',
    '#options' => array(
      0=>"Seleccionar1",
      1=>"Seleccionar2",
      2=>"Seleccionar3",
      3=>"Seleccionar4",

      ),

    '#prefix' => '<div class="small-2 columns">',
    '#suffix' => '</div><hr/></div>',
  );

  $form['historial_compras']['historialCompras'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns"> <div class=" resaltado" id="divhistorialCompras">Historial de Compras</div></div></div>',
  );

  return $form;
}
