<?php



/**
 * @file
 * Handles the form elements of the customer survey form
 * All hooks are in the .module file.
 */

/**
 * Hook del formulario, para instanciar el formulario correspondiente a cada uno de los pasos definidos.
 * 
 * @see configuracioncuenta_form_validate().
 * @see configuracioncuenta_form_submit().
 * 
 * @param type $form
 * @param string $form_state
 * @return type 
 */


/**
 * Función para gestionar el formulario de  historial_ventas.
 * Aquí se insertarán los campos correspondientes a este paso
 * Creado por Ricardo Aguilera
 * 
 * @see configuracioncuenta_form().
 *  
 * @param type $form
 * @param type $form_state
 * @return type 
 */
function configuracioncuenta_historial_ventas($form, &$form_state) {

	$form = array();
  $form['historial_ventas']['filVentas'] = array(
    '#title' =>FILTRO_VENTAS,
    '#required' => FALSE,
    '#type' => 'select',
    '#maxlength' => 60,
    '#prefix' => '<div class="row"><div class="small-8 columns">&nbsp;</div><div class="small-2 columns">',
    '#suffix' => '</div>',
    '#options' => array(
        1=>"opcion 1",
        2=>"opcion 2",
        3=>"opcion 3",
        4=>"opcion 4",

      ),
  );
  $form['historial_ventas']['ordVentas'] = array(
    '#title' =>ORDENAMIENTO_VENTAS,
    '#required' => FALSE,
    '#type' => 'select',
    '#maxlength' => 60,
    '#prefix' => '<div class="small-2 columns">',
    '#suffix' => '</div></div>',
    '#options' => array(
      0=>"Seleccionar"

      ),
    
  );

  $form['historial_ventas']['historialVentasActuales'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns"> <div class=" resaltado" id="divhistorialVentasActuales">Historial de ventas del mes acutal</div></div></div>',
  );

  $form['historial_ventas']['historialVentasMesPasado'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns"> <div class=" resaltado" id="divhistorialVentasMesPasado">Historial de ventas del mes anterior</div></div></div>',
  );

  $form['historial_ventas']['historialVentasFacturadas'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns"> <div class=" resaltado" id="divhistorialVentasFacturadas">Historial de ventas Facturadas</div></div></div>',
  );


    
  return $form;
}
