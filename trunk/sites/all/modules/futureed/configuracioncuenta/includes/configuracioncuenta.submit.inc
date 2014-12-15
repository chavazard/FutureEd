<?php

#define('DRUPAL_ROOT', getcwd());
require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
require_once DRUPAL_ROOT . '/includes/password.inc';
/**
 * @file 
 * Handles the form submission of the customer survey form
 */


/**
 * Handles what to do with the submitted form depending on what stage has been
 * completed.
 * 
 * @see configuracioncuenta_form()
 * @see configuracioncuenta_form_validate()
 * 
 * @param type $form
 * @param type $form_state 
 */
function configuracioncuenta_form_submit($form, &$form_state) {
  
  //print_r($form_state['stage']);
  //print_r("este es el stage ");
  switch ($form_state['stage']) {
    
    //Si se está en el paso final del formulario:
    case 'cuentas':
      //Se guardan todos los valores del formulario
      $form_state['multistep_values'][$form_state['stage']] = $form_state['values'];
      //Se valida que se haya llegado al final del formulario sin haber dado click al boton de "back"
      if ($form_state['triggering_element']['#value'] != 'back') {
        //Se ejecuta una función custom que permitirá hacer los pasos necesarios antes de hacer el form submit.
        configuracioncuenta_guardar_valores_paso_anterior($form, $form_state['stage'],$form_state['values']);
        
        
        configuracioncuenta_personal_details_submit($form, $form_state);
        //Se setea la variable que identifica que el formulario está en el último paso
        //$form_state['complete'] = TRUE;
      }
     break;
    
    //En caso de que no se esté en el último paso, simplemente agregamos las variables que se usaron en el paso anterior al arreglo de variables
    //que guarda todas las variables del formulario.
    default:
      //Aquí se pueden gardar los datos del paso anterior
      configuracioncuenta_guardar_valores_paso_anterior($form, $form_state['stage'],$form_state['values']);

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
          $form_state['new_stage'] = configuracioncuenta_move_to_next_stage($form, $form_state);
     break;
 
  } 


  //Si el formulario está completo, redirecciona a la URL de "Completo"
  if (isset($form_state['complete'])) drupal_goto('cuenta/completo');   
  
  //Si se presionó el botón de back, se regresa al paso anterior
  if ($form_state['triggering_element']['#id'] == 'edit-back') {

    $form_state['new_stage'] = configuracioncuenta_move_to_previous_stage($form, $form_state);
  } 
  
  //Si se presionó el botón de next, se va al paso siguiente
  if (isset($form_state['multistep_values']['form_build_id'])) {
    $form_state['values']['form_build_id'] = $form_state['multistep_values']['form_build_id'];
  }

  //Se recalculan los pasos y vriables de control del formulario
  $form_state['multistep_values']['form_build_id'] = $form_state['values']['form_build_id'];
  $form_state['stage'] = $form_state['new_stage'];
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
function configuracioncuenta_personal_details_submit($form, &$form_state) {
  
 /* $multstep_values = $form_state['multistep_values'];
    
  $module = 'configuracioncuenta';
  $key = 'configuracioncuenta_complete';

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
function configuracioncuenta_complete() {
    
  return AGRADECIMIENTO_PASO_FINAL_CUENTA;  
    
}



function configuracioncuenta_guardar_valores_paso_anterior($form, $stage, $valores){
  
  global $user; //se instancía el objeto de usuario logeado.
  $edit=array();
 
  switch ($stage) {
    case 'informacion_general' :
        $fecha=strtotime($valores['selDiaNacimiento']['year'].'-'.$valores['selDiaNacimiento']['month'].'-'.$valores['selDiaNacimiento']['day']);
        $edit['field_usuario_fecha_nacimiento'][LANGUAGE_NONE][0]['value'] = $fecha;
        $edit['field_usuario_sexo'][LANGUAGE_NONE][0]['value'] = $valores['selSexo'];
        $edit['pass'] = $valores['txtContrasenia'];
    break;
  
    case 'contacto' :
        $edit['field_usuario_correo'][LANGUAGE_NONE][0]['value'] = $valores['txtCorreoElectronicoPrimario'];
        $edit['field_usuario_otro_correo'][LANGUAGE_NONE][0]['value'] = $valores['txtCorreoElectronicoSecundario'];
        $edit['field_usuario_telefono_casa'][LANGUAGE_NONE][0]['value'] = $valores['txtTelefonoCasa'];
        $edit['field_usuario_telefono_oficina'][LANGUAGE_NONE][0]['value'] = $valores['txtTelefonoOficina'];
        $edit['field_telefono_movil'][LANGUAGE_NONE][0]['value'] = $valores['txtTelefonoMovil'];
        $edit['field_usuario_telefono_otro'][LANGUAGE_NONE][0]['value'] = $valores['txtTelefonoOtro'];
        $edit['field_usuario_username_skype'][LANGUAGE_NONE][0]['value'] = $valores['txtSkype'];
        $edit['field_usuario_username_facebook'][LANGUAGE_NONE][0]['value'] = $valores['txtFacebook'];
        $edit['field_usuario_username_google'][LANGUAGE_NONE][0]['value'] = $valores['txtTwitter'];
        $edit['field_usuario_sitio_web'][LANGUAGE_NONE][0]['value'] = $valores['txtSitioWeb'];
    break;
  
    case 'direcciones' :
        $nid=$valores['nid'];
        if($nid == 0)  
        {
            $node = new stdClass();
            $node->language = LANGUAGE_NONE;
            $node->type = "direcciones";
            node_object_prepare($node);
            $node->uid = $user->uid;
            $node->status = 1; //(1 or 0): publicado automaticamente
            $node->promote = 0; //(1 or 0): desabilitado para página principal
            $node->comment = 0; // comentarios sobre el nodo deshabilitados
        }elseif($nid > 0)
            $node = node_load($nid);
            
        $node->field_direcciones_calle[$node->language][0]['value'] = $valores['txtCalle'];
        $node->field_direcciones_nexterior[$node->language][0]['value'] = $valores['txtNumeroExterior'];
        $node->field_direcciones_ninterior[$node->language][0]['value'] = $valores['txtNumeroInterior'];
        $node->field_direcciones_colonia[$node->language][0]['value'] = $valores['txtColonia'];
        $node->field_direcciones_municipio[$node->language][0]['value'] = $valores['txtDelegacionMunicipio'];
        #$node->field_direcciones_estado[$node->language][0]['value'] = $valores['txtEstado'];
        #$node->field_direcciones_pais[$node->language][0]['value'] = $valores['txtPais'];
        $node->field_direcciones_codigo_postal[$node->language][0]['value'] = $valores['txtCodigoPostal'];
        node_save($node);
    break;
  
    case 'profesional_academica' :
        $periodoini=strtotime($valores['selMesInicio']['year'].'-'.$valores['selMesInicio']['month'].'-01');
        $periodofin=strtotime($valores['selMesFin']['year'].'-'.$valores['selMesFin']['month'].'-01');
        $edit['field_usuario_empresa'][LANGUAGE_NONE][0]['value'] = $valores['txtCompania'];
        $edit['field_usuario_puesto'][LANGUAGE_NONE][0]['value'] = $valores['txtTituloPuesto'];
        $edit['field_usuario_empleo_actual'][LANGUAGE_NONE][0]['value'] = $valores['radEmpleoActual'];
        $edit['field_usuario_periodo_tiempo'][LANGUAGE_NONE][0]['value'] = $periodoini;
        $edit['field_usuario_periodo_tiempo'][LANGUAGE_NONE][0]['value2'] = $periodofin;
        $edit['field_usuario_escuela'][LANGUAGE_NONE][0]['value'] = $valores['txtEscuela'];
        $edit['field_usuario_titulo_estudios'][LANGUAGE_NONE][0]['value'] = $valores['radTituloEstudios'];
        $edit['field_usuario_tipo_estudio'][LANGUAGE_NONE][0]['value'] = $valores['txtTipoEstudio'];
        $edit['field_usuario_cursando'][LANGUAGE_NONE][0]['value'] = $valores['radEstudioCursando'];
    break;
  
    case 'intereses' :
        delete_intereses($user->uid);
        $interes=$valores['chkInteres'];
        $insert = db_insert('intereses')->fields(array('uid', 'taxonomy_id'));
        foreach($interes as $termino){
            if($termino>0){
                $insert->values(array(
                 'uid' => $user->uid,
                 'taxonomy_id' => $termino,
               ));
            }
        }
       $insert->execute();    
    break;
  
    case 'privacidad' :
        $edit['field_usuario_privacidad_perfil'][LANGUAGE_NONE][0]['value'] = $valores['radPerfilPublico'];
        $edit['field_usuario_privacidad_persona'][LANGUAGE_NONE][0]['value'] = $valores['radPersonalPublico'];
        $edit['field_usuario_privacidad_contact'][LANGUAGE_NONE][0]['value'] = $valores['radContactoPublico'];
        $edit['field_usuario_privacidad_social'][LANGUAGE_NONE][0]['value'] = $valores['radRedesPublico'];
        $edit['field_usuario_privacidad_prof'][LANGUAGE_NONE][0]['value'] = $valores['radProfesionalPublico'];
        $edit['field_usuario_privacidad_academi'][LANGUAGE_NONE][0]['value'] = $valores['radAcademicaPublico'];
        $edit['field_usuario_privacidad_cursos'][LANGUAGE_NONE][0]['value'] = $valores['radCursosPublico'];
        $edit['field_usuario_privacidad_grupos'][LANGUAGE_NONE][0]['value'] = $valores['radGruposPublico'];
        $edit['field_usuario_privacidad_portafo'][LANGUAGE_NONE][0]['value'] = $valores['radPortafolioPublico'];
        $edit['field_usuario_privacidad_product'][LANGUAGE_NONE][0]['value'] = $valores['radProductosPublico'];
        $edit['field_usuarios_privacidad_mensaj'][LANGUAGE_NONE][0]['value'] = $valores['radMensajesPublico'];
    break;
  
    case 'facturacion' :
        $nid=$valores['nid'];
          if($nid == 0)  
          {
            $node = new stdClass();
            $node->language = LANGUAGE_NONE;
            $node->type = "persona";
            node_object_prepare($node);
            $node->uid = $user->uid;
            $node->status = 1; //(1 or 0): publicado automaticamente
            $node->promote = 0; //(1 or 0): desabilitado para página principal
            $node->comment = 0; // comentarios sobre el nodo deshabilitados
          }elseif($nid > 0)
              $node = node_load($nid);
      
        $node->field_persona_tipo[$node->language][0]['value'] = $valores['radTipoPersona'];
        $node->field_persona_razon_social[$node->language][0]['value'] = $valores['txtRazonSocial'];
        $node->field_persona_rfc[$node->language][0]['value'] = $valores['txtRFC'];
        #$edit['field_usuario_factura_dir_ex'][LANGUAGE_NONE][0]['value'] = $valores['chkDireccionExistente'];
        #$edit['field_usuario_factura_dir_sel'][LANGUAGE_NONE][0]['value'] = $valores['selDireccionExistente'];
        $node->field_direcciones_calle[$node->language][0]['value'] = $valores['txtCalle'];
        $node->field_direcciones_nexterior[$node->language][0]['value'] = $valores['txtNumeroExterior'];
        $node->field_direcciones_ninterior[$node->language][0]['value'] = $valores['txtNumeroInterior'];
        $node->field_direcciones_colonia[$node->language][0]['value'] = $valores['txtColonia'];
        $node->field_direcciones_municipio[$node->language][0]['value'] = $valores['txtDelegacionMunicipio'];
        $node->field_direcciones_codigo_postal[$node->language][0]['value'] = $valores['txtCP'];
        //$node->field_direcciones_estado[$node->language][0]['value'] = $valores['selEstado'];
        //$node->field_direcciones_ciudad[$node->language][0]['value'] = $valores['SelCiudad'];
        $edit['field_usuario_correo'][LANGUAGE_NONE][0]['value'] = $valores['txtEmail'];
        $edit['field_usuario_telefono_otro'][LANGUAGE_NONE][0]['value'] = $valores['txtTelefono'];
        #$node->field_usuario_telefono_otro[$node->language][0]['value'] = $valores['txtTelefono'];
        #$node->field_usuario_correo[$node->language][0]['value'] = $valores['txtEmail'];
        node_save($node);
    break;
  
    case 'pago' :
        $nid=$valores['nid'];
        if($nid == 0)  
        {
            $node = new stdClass();
            $node->language = LANGUAGE_NONE;
            $node->type = "tarjeta_de_credito";
            node_object_prepare($node);
            $node->uid = $user->uid;
            $node->status = 1; //(1 or 0): publicado automaticamente
            $node->promote = 0; //(1 or 0): desabilitado para página principal
            $node->comment = 0; // comentarios sobre el nodo deshabilitados
            $node->title = $valores['txtAliasTarjeta'];  
        }elseif($nid > 0)
              $node = node_load($nid);
             
            $node->field_tarjeta_alias[$node->language][0]['value'] = $valores['txtAliasTarjeta']; 
            $node->field_tarjeta_numero[$node->language][0]['value'] = $valores['txtNumeroTarjeta'];
            $node->field_tarjeta_tipo[$node->language][0]['value'] = $valores['selTipoTarjeta'];
            $node->field_tarjeta_nombre[$node->language][0]['value'] = $valores['strNombrePlasticoTarjeta'];
            $fecha=strtotime($valores['selMesVencimientoTarjeta']['year'].'-'.$valores['selMesVencimientoTarjeta']['month']);
            $node->field_tarjeta_fecha_vencimiento[$node->language][0]['value'] = $fecha;
            $node->field_tarjeta_codigo_seguridad[$node->language][0]['value'] = $valores['txtCodigoSeguridadTarjeta'];
            #$node->field_tarjeta_predeterminada[$node->language][0]['value'] = $valores[''];
            print_r($node); 
            node_save($node);
    break;
  
    case 'cuentas' :
        $nid=$valores['nid'];
        if($nid == 0)  
        {
            $node = new stdClass();
            $node->language = LANGUAGE_NONE;
            $node->type = "cuenta_de_deposito";
            node_object_prepare($node);
            $node->uid = $user->uid;
            $node->status = 1; //(1 or 0): publicado automaticamente
            $node->promote = 0; //(1 or 0): desabilitado para página principal
            $node->comment = 0; // comentarios sobre el nodo deshabilitados
        }elseif($nid > 0)
            $node = node_load($nid);
       
            $node->field_cuenta_alias[$node->language][0]['value'] = $valores['txtAliasCuenta'];
            $node->field_cuenta_tipo[$node->language][0]['value'] = $valores['txtTipoCuenta'];
            $node->field_cuenta_nombre_banco[$node->language][0]['value'] = $valores['txtNombreBanco'];
            $node->field_cuenta_numero[$node->language][0]['value'] = $valores['txtNumeroCuenta'];
            $node->field_cuenta_nombre_titular[$node->language][0]['value'] = $valores['txtNombreTitular'];
            $node->field_cuenta_clabe[$node->language][0]['value'] = $valores['txtCLABE'];
            $edit['field_usuario_paypal'][LANGUAGE_NONE][0]['value'] = $valores['txtCorreoCuentaPaypal'];
            node_save($node);
    break;
  
    case 'verificacion_cuenta' :
      print_r('kjkjkjkj');
      
        $identificacion = file_load($valores['filDocumentoIdentificacion']);
        // Change status to permanent.
        $identificacion->status = FILE_STATUS_PERMANENT;
        // Save.
        $id_Saved = file_save($identificacion);
        variable_set($user->uid.'_doc_fid',$id_Saved->fid);
        
        
        $file = file_load($valores['filComprobanteDomicilio']);
        // Change status to permanent.
        $file->status = FILE_STATUS_PERMANENT;
        // Save.
        $fileSaved = file_save($file);
        
        print_r($id_Saved);
        
        $edit['field_usuario_doc_identificacion'][LANGUAGE_NONE][0]['value'] = $id_Saved->uri;
        $edit['field_usuario_comprobante_dom'][LANGUAGE_NONE][0]['value'] =$fileSaved->uri;
    break;
  
    case 'historial_compras' :
        
    break;
  
    case 'historial_ventas' :
       
    break;
  
    case 'cambio_perfil' :
        
    break;
 }
 
 user_save($user,$edit);
  
 
  print_r("<br>Stage:".$stage."<br>");
  print_r("<br>Valores:");
  print_r($valores);
  print_r("<br>");

}