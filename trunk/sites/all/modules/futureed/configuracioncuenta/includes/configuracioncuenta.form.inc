<?php
/**
 * @file
 * Handles the form elements of the customer survey form
 * All hooks are in the .module file.
 */

/**
* setters para variabes locales
*/

//Paths para guardar los archivos
$directorioComprobanteDomicilio = 'public://curso_comprobante';
$directorioDocumentoIdentificacion = 'public://curso_imagen';

global $user;

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
function configuracioncuenta_form($form, &$form_state) {


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

  if($form_state['stage']=='configurar')$form_state['stage']='informacion_general';

  $form['#attributes'] = array('enctype' => "multipart/form-data");


  switch ($form_state['stage']) {
    case 'informacion_general' :    return configuracioncuenta_informacion_general_form($form, $form_state); break;
    case 'contacto' :               return configuracioncuenta_contacto_form($form, $form_state); break;
    case 'direcciones' :            return configuracioncuenta_direcciones_form($form, $form_state); break;
    case 'profesional_academica' :  return configuracioncuenta_profesional_academica_form($form, $form_state); break;
    case 'intereses' :              return configuracioncuenta_intereses_form($form, $form_state); break;
    case 'privacidad' :             return configuracioncuenta_privacidad_form($form, $form_state); break;
    case 'facturacion' :            return configuracioncuenta_facturacion_form($form, $form_state); break;
    case 'pago' :                   return configuracioncuenta_pago_form($form, $form_state); break;
    case 'cuentas' :                return configuracioncuenta_cuentas_form($form, $form_state); break;
    case 'verificacion_cuenta' :    return configuracioncuenta_verificacion_cuenta_form($form, $form_state); break;
    case 'historial_compras' :      return configuracioncuenta_historial_compras($form, $form_state); break;
    case 'historial_ventas' :       return configuracioncuenta_historial_ventas($form, $form_state); break;
    case 'cambio_perfil' :          return configuracioncuenta_cambio_perfil_form($form, $form_state); break;

    default :                       return configuracioncuenta_informacion_general_form($form, $form_state); break;
  }
  //print_r("Arreglo entero pasado al formulario:");
  //print_r($form);
  return $form;

}






/**
 * Función para gestionar el formulario de  informacion_general.
 * Aquí se insertarán los campos correspondientes a este paso
 * Creado por Ricardo Aguilera
 *
 * @see configuracioncuenta_form().
 *
 * @param type $form
 * @param type $form_state
 * @return type
 */
function configuracioncuenta_informacion_general_form($form, &$form_state) {
   global $user;
  $values = isset($form_state['multistep_values']['informacion_general']) ? $form_state['multistep_values']['informacion_general'] : array();
  $user_fields = user_load($user->uid);
  $values['selAnioNacimiento'] = $user_fields->field_usuario_fecha_nacimiento['und'][0]['value'] != NULL ? date('Y',$user_fields->field_usuario_fecha_nacimiento['und'][0]['value']) : NULL;
  #$values['selMesNacimiento'] = $user_fields->field_usuario_fecha_nacimiento['und'][0]['value'] != NULL ? date('m',$user_fields->field_usuario_fecha_nacimiento['und'][0]['value']) : NULL;
  #$values['selDiaNacimiento'] = $user_fields->field_usuario_fecha_nacimiento['und'][0]['value'] != NULL ? date('d',$user_fields->field_usuario_fecha_nacimiento['und'][0]['value']) : NULL;
  $values['selSexo'] = $user_fields->field_usuario_sexo['und'][0]['value'] != NULL ? $user_fields->field_usuario_sexo['und'][0]['value'] : NULL;
  $values['txtContrasenia'] = $user_fields->pass['value'] != NULL ? $user_fields->pass['value'] : NULL;
  $fecha = strlen($user_fields->field_usuario_fecha_nacimiento['und'][0]['value'])>0?date('d/m/Y',$user_fields->field_usuario_fecha_nacimiento['und'][0]['value']):'';
  //$fecha_arr = explode('-',$fecha);
  #$fecha_nac = array('year'=>$fecha_arr[0],'month'=>$fecha_arr[1],'day'=> $fecha_arr[2]);

  $form['informacion_general']['selDiaNacimiento'] = array(
    '#title' =>FECHA_NACIMIENTO,
    '#type' => 'textfield',
    '#required' => TRUE,
    '#prefix' =>'<div class="row"><div class="small-3 columns"><label class="popup-fecha">' ,
    '#suffix' => '</label></div>',
    '#default_value' => isset($fecha) ? $fecha : '',
    '#attributes' =>array('placeholder' => FORMATO_FECHA),
  );


  $form['informacion_general']['selSexo'] = array(
    '#title' =>SEXO,
    '#required' => TRUE,
    '#type' => 'radios',
    '#options' => array('1'=>FEMENINO,'2'=>MASCULINO),
    '#prefix' =>'<div class="small-3 columns"></div><div class="small-6 columns">' ,
    '#suffix' => '</div></div>',
    '#default_value' => isset($values['selSexo']) ? $values['selSexo'] : NULL,
  );

  $form['informacion_general']['txtContrasenia'] = array(
    '#title' =>CONTRASENIA,
    '#type' => 'password',
    '#default_value' => isset($values['txtContrasenia']) ? $values['txtContrasenia'] : NULL,
    '#prefix' =>'<div class="row"><div class="small-6 columns">' ,
    '#suffix' => '</div></div>',

    '#attributes' =>array('placeholder' => PLACEHOLDER_CONTRA_CAMBIAR),
  );


  $form['lblCamposObligatorios'] = array(
    '#markup' => '<div class="row"><div class="small-4 columns"><span class="form-required" title="'.CAMPOS_OBLIGATORIOS.'">* '.CAMPOS_OBLIGATORIOS.'</span></div>',
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


/**
 * Función para gestionar el formulario de  contacto.
 * Aquí se insertarán los campos correspondientes a este paso
 * Creado por Ricardo Aguilera
 *
 * @see configuracioncuenta_form().
 *
 * @param type $form
 * @param type $form_state
 * @return type
 */

function cargaListaAnios(){
  $arrTax = array();
  for($i=1900;$i<=date('Y');$i++){
    $arrTax[$i] = $i;
  }
  return $arrTax;
}

function configuracioncuenta_contacto_form($form, &$form_state) {

  $values = isset($form_state['multistep_values']['contacto']) ? $form_state['multistep_values']['contacto'] : array();
  global $user;
  $user_fields = user_load($user->uid);
  $values['txtCorreoElectronicoPrimario'] = $user_fields->field_usuario_correo['und'][0]['value'] != NULL ? $user_fields->field_usuario_correo['und'][0]['value'] : NULL;
  $values['txtCorreoElectronicoSecundario'] = $user_fields->field_usuario_otro_correo['und'][0]['value'] != NULL ? $user_fields->field_usuario_otro_correo['und'][0]['value'] : NULL;
  $values['txtTelefonoCasa'] = $user_fields->field_usuario_telefono_casa['und'][0]['value'] != NULL ? $user_fields->field_usuario_telefono_casa['und'][0]['value'] : NULL;
  $values['txtTelefonoOficina'] = $user_fields->field_usuario_telefono_oficina['und'][0]['value'] != NULL ? $user_fields->field_usuario_telefono_oficina['und'][0]['value'] : NULL;
  $values['txtTelefonoMovil'] = $user_fields->field_telefono_movil['und'][0]['value'] != NULL ? $user_fields->field_telefono_movil['und'][0]['value'] : NULL;
  $values['txtTelefonoOtro'] = $user_fields->field_usuario_telefono_otro['und'][0]['value'] != NULL ? $user_fields->field_usuario_telefono_otro['und'][0]['value'] : NULL;
  $values['txtSkype'] = $user_fields->field_usuario_username_skype['und'][0]['value'] != NULL ? $user_fields->field_usuario_username_skype['und'][0]['value'] : NULL;
  $values['txtFacebook'] = $user_fields->field_usuario_username_facebook['und'][0]['value'] != NULL ? $user_fields->field_usuario_username_facebook['und'][0]['value'] : NULL;
  $values['txtTwitter'] = $user_fields->field_usuario_username_google['und'][0]['value'] != NULL ? $user_fields->field_usuario_username_google['und'][0]['value'] : NULL;
  $values['txtSitioWeb'] = $user_fields->field_usuario_sitio_web['und'][0]['value'] != NULL ? $user_fields->field_usuario_sitio_web['und'][0]['value'] : NULL;

$form['contacto']['lblTitEmail'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns"><h6>'.TITULO_EMAIL.'</h6></div></div>',
  );

$form['contacto']['txtCorreoElectronicoPrimario'] = array(
    '#title' =>EMAIL,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtCorreoElectronicoPrimario']) ? $values['txtCorreoElectronicoPrimario'] : NULL,
    '#maxlength' => 60,
    '#prefix' =>'<div class="row"><div class="small-6 columns">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => EMAIL),
  );

$form['contacto']['txtCorreoElectronicoSecundario'] = array(
    '#title' =>EMAIL_2,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtCorreoElectronicoSecundario']) ? $values['txtCorreoElectronicoSecundario'] : NULL,
    '#maxlength' => 60,
    '#prefix' =>'<div class="small-6 columns end">' ,
    '#suffix' => '</div><hr/></div>',
    '#attributes' =>array('placeholder' => EMAIL_2),
  );

$form['contacto']['lblTitTel'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns"><h6>'.TITULO_TELEFONOS.'</h6></div></div>',
  );

$form['contacto']['txtTelefonoCasa'] = array(
    '#title' =>TEL_CASA,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtTelefonoCasa']) ? $values['txtTelefonoCasa'] : NULL,
    '#maxlength' => 15,
    '#prefix' =>'<div class="row"><div class="small-6 columns">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => TEL_CASA),
  );

$form['contacto']['txtTelefonoOficina'] = array(
    '#title' =>TEL_OFICINA,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtTelefonoOficina']) ? $values['txtTelefonoOficina'] : NULL,
    '#maxlength' => 15,
    '#prefix' =>'<div class="small-6 columns">' ,
    '#suffix' => '</div></div>',
    '#attributes' =>array('placeholder' => TEL_OFICINA),
  );

$form['contacto']['txtTelefonoMovil'] = array(
    '#title' =>TEL_MOVIL,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtTelefonoMovil']) ? $values['txtTelefonoMovil'] : NULL,
    '#maxlength' => 15,
    '#prefix' =>'<div class="row"><div class="small-6 columns">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => TEL_MOVIL),
  );

$form['contacto']['txtTelefonoOtro'] = array(
    '#title' =>TEL_OTRO,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtTelefonoOtro']) ? $values['txtTelefonoOtro'] : NULL,
    '#maxlength' => 15,
    '#prefix' =>'<div class="small-6 columns end">' ,
    '#suffix' => '</div><hr/></div>',
    '#attributes' =>array('placeholder' => TEL_OTRO),
  );

  $form['contacto']['lblTitOtros'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns"><h6>'.TITULO_OTROS_CONTACTO.'</h6></div></div>',
  );


  $form['contacto']['lblTitOtros'] = array(
    '#markup' => '<div class="row">
      <div class="small-4 columns"><label>'.CONTACTO_MENSAJERIA.'</label></div>
      <div class="small-4 columns"><label>'.CONTACTO_WEB.'</label></div>
      <div class="small-4 columns"><label>'.CONTACTO_REDES.'</label></div>
    </div>',
  );
$form['contacto']['txtSkype'] = array(
    '#title' =>SKYPE,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtSkype']) ? $values['txtSkype'] : NULL,
    '#maxlength' => 35,
    '#prefix' =>'<div class="row label-hidden"><div class="small-4 columns ">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => SKYPE),
  );

$form['contacto']['txtSitioWeb'] = array(
    '#title' =>SITIO_WEB,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtSitioWeb']) ? $values['txtSitioWeb'] : NULL,
    '#maxlength' => 60,
    '#prefix' =>'<div class="small-4 columns end">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => SITIO_WEB),
  );
$form['contacto']['txtLinkedin'] = array(
    '#title' =>LINKEDIN,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtLinkedin']) ? $values['txtLinkedin'] : NULL,
    '#maxlength' => 60,
    '#prefix' =>'<div class="small-4 columns end">' ,
    '#suffix' => '</div></div>',
    '#attributes' =>array('placeholder' => LINKEDIN),
  );

$form['contacto']['txtFacebookChat'] = array(
    '#title' =>FACEBOOK_CHAT,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtFacebookChat']) ? $values['txtFacebookChat'] : NULL,
    '#maxlength' => 35,
    '#prefix' =>'<div class="row label-hidden"><div class="small-4 columns">' ,
    '#suffix' => '</div><div class="small-4 columns">&nbsp;</div>',
    '#attributes' =>array('placeholder' => FACEBOOK_CHAT),
  );



$form['contacto']['txtFacebook'] = array(
    '#title' =>FACEBOOK,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtFacebook']) ? $values['txtFacebook'] : NULL,
    '#maxlength' => 35,
    '#prefix' =>'<div class="small-4 columns">' ,
    '#suffix' => '</div></div>',
    '#attributes' =>array('placeholder' => FACEBOOK),
  );


$form['contacto']['txtHangouts'] = array(
    '#title' =>HANGOUTS,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtHangouts']) ? $values['txtHangouts'] : NULL,
    '#maxlength' => 35,
    '#prefix' =>'<div class="row label-hidden"><div class="small-4 columns">' ,
    '#suffix' => '</div><div class="small-4 columns">&nbsp;</div>',
    '#attributes' =>array('placeholder' => HANGOUTS),
  );


$form['contacto']['txtTwitter'] = array(
    '#title' =>TWITTER,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtTwitter']) ? $values['txtTwitter'] : NULL,
    '#maxlength' => 35,
    '#prefix' =>'<div class="small-4 columns">' ,
    '#suffix' => '</div></div>',
    '#attributes' =>array('placeholder' => TWITTER),
  );

$form['contacto']['txtGooglePlus'] = array(
    '#title' =>GOOGLE_PLUS,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtGooglePlus']) ? $values['txtGooglePlus'] : NULL,
    '#maxlength' => 35,
    '#prefix' =>'<div class="row label-hidden"><div class="small-8 columns">&nbsp;</div><div class="small-4 columns">' ,
    '#suffix' => '</div></div>',
    '#attributes' =>array('placeholder' => GOOGLE_PLUS),
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


/**
 * Función para gestionar el formulario de  direcciones.
 * Aquí se insertarán los campos correspondientes a este paso
 * Creado por Ricardo Aguilera
 *
 * @see configuracioncuenta_form().
 *
 * @param type $form
 * @param type $form_state
 * @return type
 */
function configuracioncuenta_direcciones_form($form, &$form_state) {

  /*$values = isset($form_state['multistep_values']['direcciones']) ? $form_state['multistep_values']['direcciones'] : array();
  global $user;
  $n = get_persona($user->uid);

  $node = node_load($n);

  $nid=$node->nid;
  #print_r($nid);

  $values['txtCalle'] = $node->field_direcciones_calle['und'][0]['value'] != NULL ? $node->field_direcciones_calle['und'][0]['value'] : NULL;
  $values['txtNumeroExterior'] = $node->field_direcciones_nexterior['und'][0]['value'] != NULL ? $node->field_direcciones_nexterior['und'][0]['value'] : NULL;
  $values['txtNumeroInterior'] = $node->field_direcciones_ninterior['und'][0]['value'] != NULL ? $node->field_direcciones_ninterior['und'][0]['value'] : NULL;
  $values['txtColonia'] = $node->field_direcciones_colonia['und'][0]['value'] != NULL ? $node->field_direcciones_colonia['und'][0]['value'] : NULL;
  $values['txtDelegacionMunicipio'] = $node->field_direcciones_municipio['und'][0]['value'] != NULL ? $node->field_direcciones_municipio['und'][0]['value'] : NULL;
  $values['txtEstado'] = $node->field_direcciones_estado['und'][0]['value'] != NULL ? $node->field_direcciones_estado['und'][0]['value'] : NULL;
  $values['txtPais'] = $node->field_direcciones_pais['und'][0]['value'] != NULL ? $node->field_direcciones_pais['und'][0]['value'] : NULL;
  #$values['txtCalle'] = $user_fields->field_direcciones_ciudad['und'][0]['value'] != NULL ? $user_fields->field_direcciones_ciudad['und'][0]['value'] : NULL;
  $values['txtCodigoPostal'] = $node->field_direcciones_codigo_postal['und'][0]['value'] != NULL ? $node->field_direcciones_codigo_postal['und'][0]['value'] : NULL;

   #print_r($values);*/

   $form['direcciones']['nid'] = array(
    '#required' => FALSE,
    '#type' => 'hidden',
    '#default_value' => $nid,

  );

  $form['direcciones']['lblDireccionEnvio'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns"><h6>'.DIRECCION_ENVIO.'</h6></div></div>',
  );

  $form['direcciones']['divDireccionesAgregadas'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns"> <div class=" resaltado" id="divDireccionesAgregadasCont">Cargando...</div></div></div>',
  );


  //Sección para direcciones de envío

  $form['dirEnvio']['txtCalle'] = array(
    '#title' =>CALLE,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtCalle']) ? $values['txtCalle'] : NULL,
    '#maxlength' => 35,
    '#prefix' =>'<div class="row"><div class="small-4 columns">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => CALLE),
  );

$form['dirEnvio']['txtNumeroExterior'] = array(
    '#title' =>NO_EXTERIOR,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtNumeroExterior']) ? $values['txtNumeroExterior'] : NULL,
    '#maxlength' => 4,
    '#prefix' =>'<div class="small-2 columns">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => NO_EXTERIOR),
  );

$form['dirEnvio']['txtNumeroInterior'] = array(
    '#title' =>NO_INTERIOR,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtNumeroInterior']) ? $values['txtNumeroInterior'] : NULL,
    '#maxlength' => 4,
    '#prefix' =>'<div class="small-2 columns">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => NO_INTERIOR),
  );

$form['dirEnvio']['txtColonia'] = array(
    '#title' =>COLONIA,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtColonia']) ? $values['txtColonia'] : NULL,
    '#maxlength' => 35,
    '#prefix' =>'<div class="small-4 columns">' ,
    '#suffix' => '</div></div>',
    '#attributes' =>array('placeholder' => COLONIA),
  );

$form['dirEnvio']['txtDelegacionMunicipio'] = array(
    '#title' =>DELEG,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtDelegacionMunicipio']) ? $values['txtDelegacionMunicipio'] : NULL,
    '#maxlength' => 35,
    '#prefix' =>'<div class="row"><div class="small-4 columns">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => DELEG),
  );

$form['dirEnvio']['txtEstado'] = array(
    '#title' =>ESTADO,
    '#required' => TRUE,
    '#type' => 'select',
    '#options' => get_parents(7),
    '#prefix' =>'<div class="small-4 columns"><label class="labelSelect">' ,
    '#suffix' => '</label></div>',
  );

$form['dirEnvio']['txtPais'] = array(
    '#title' =>PAIS,
    '#required' => TRUE,
    '#type' => 'select',
    '#options' => get_parents(6),
    '#prefix' =>'<div class="small-4 columns"><label class="labelSelect">' ,
    '#suffix' => '</label></div>',
  );


$form['dirEnvio']['txtCodigoPostal'] = array(
    '#title' =>CP,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtCodigoPostal']) ? $values['txtCodigoPostal'] : NULL,
    '#maxlength' => 9,
    '#prefix' =>'<div class="row"><div class="small-4 columns end">' ,
    '#suffix' => '</div></div>',
    '#attributes' =>array('placeholder' => CP),
  );


  $form['dirEnvio']['btnAgregarDireccion'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns text-right btn-gris"> 
        <input type="button" name="btnAgregarDireccion" id="btnAgregarDireccion" value='.AGREGAR_DIRECCION.'></div><hr></div>
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


/**
 * Función para gestionar el formulario de  profesional_academica.
 * Aquí se insertarán los campos correspondientes a este paso
 * Creado por Ricardo Aguilera
 *
 * @see configuracioncuenta_form().
 *
 * @param type $form
 * @param type $form_state
 * @return type
 */
function configuracioncuenta_profesional_academica_form($form, &$form_state) {

  $values = isset($form_state['multistep_values']['profesional_academica']) ? $form_state['multistep_values']['profesional_academica'] : array();
  global $user;
  $user_fields = user_load($user->uid);
  $values['txtCompania'] = $user_fields->field_usuario_empresa['und'][0]['value'] != NULL ? $user_fields->field_usuario_empresa['und'][0]['value'] : NULL;
  $values['txtTituloPuesto'] = $user_fields->field_usuario_puesto['und'][0]['value'] != NULL ? $user_fields->field_usuario_puesto['und'][0]['value'] : NULL;
  $values['radEmpleoActual'] = $user_fields->field_usuario_empleo_actual['und'][0]['value'] != NULL ? $user_fields->field_usuario_empleo_actual['und'][0]['value'] : NULL;
  $values['txtAnioInicio'] = $user_fields->field_usuario_periodo_tiempo['und'][0]['value'] != NULL ? date('Y', $user_fields->field_usuario_periodo_tiempo['und'][0]['value']) : NULL;
  $values['selMesInicio'] = $user_fields->field_usuario_periodo_tiempo['und'][0]['value'] != NULL ? date('m', $user_fields->field_usuario_periodo_tiempo['und'][0]['value']) : NULL;
  $values['txtAnioFin'] = $user_fields->field_usuario_periodo_tiempo['und'][0]['value2'] != NULL ? date('Y', $user_fields->field_usuario_periodo_tiempo['und'][0]['value2']) : NULL;
  $values['selMesFin'] = $user_fields->field_usuario_periodo_tiempo['und'][0]['value2'] != NULL ? date('m', $user_fields->field_usuario_periodo_tiempo['und'][0]['value2']) : NULL;
  $values['txtEscuela'] = $user_fields->field_usuario_escuela['und'][0]['value'] != NULL ? $user_fields->field_usuario_escuela['und'][0]['value'] : NULL;
  $values['radTituloEstudios'] = $user_fields->field_usuario_titulo_estudios['und'][0]['value'] != NULL ? $user_fields->field_usuario_titulo_estudios['und'][0]['value'] : NULL;
  $values['txtTipoEstudio'] = $user_fields->field_usuario_tipo_estudio['und'][0]['value'] != NULL ? $user_fields->field_usuario_tipo_estudio['und'][0]['value'] : NULL;
  $values['radEstudioCursando'] = $user_fields->field_usuario_cursando['und'][0]['value'] != NULL ? $user_fields->field_usuario_cursando['und'][0]['value'] : NULL;

  $fecha = date('Y-m-d',$user_fields->field_usuario_periodo_tiempo['und'][0]['value']);
  $fecha_arr = explode('-',$fecha);
  $fecha_fin = date('Y-m-d',$user_fields->field_usuario_periodo_tiempo['und'][0]['value2']);
  $fecha_arr_fin = explode('-',$fecha_fin);


  $form['profesional_academica']['txtInformacionProfesional'] = array(

    '#markup' => '<div class="row"><div class="small-12 columns">'.INFORMACION_PROFESIONAL.'</div></div>',

  );

  $form['profesional_academica']['divprofesional'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns"> <div class=" resaltado" id="divInfoProfesional">Cargando...</div></div></div>',
  );

  $form['profesional_academica']['txtCompania'] = array(
    '#title' =>COMPANIA,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtCompania']) ? $values['txtCompania'] : NULL,
    '#maxlength' => 60,
    '#prefix' =>'<div class="row"><div class="small-4 columns">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => COMPANIA),
  );

  $form['profesional_academica']['txtTituloPuesto'] = array(
    '#title' =>TIT_PUESTO,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtTituloPuesto']) ? $values['txtTituloPuesto'] : NULL,
    '#maxlength' => 60,
    '#prefix' =>'<div class="small-4 columns end">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => TIT_PUESTO),
  );

  $form['profesional_academica']['radEmpleoActual'] = array(
    '#title' =>EMP_ACTUAL,
    '#type' => 'radios',
    '#options' => array('1'=>'Si','0'=>'No',),
    '#prefix' =>'<div class="small-4 columns">' ,
    '#suffix' => '</div></div>',
    '#default_value' => isset($values['radEmpleoActual']) ? $values['radEmpleoActual'] : NULL,
  );


    $form['profesional_academica']['selMesInicio'] = array(
    '#title' =>MES_INICIO,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#prefix' =>'<div class="row"><div class="small-4 columns"><label class="popup-mes">' ,
    '#suffix' => '</label></div>',
  );
/*
$form['profesional_academica']['selMesInicio'] = array(
    '#title' =>MES_INICIO,
    '#required' => TRUE,
    '#type' => 'date',
    '#prefix' =>'<div class="row"><div class="small-3 columns">' ,
    '#suffix' => '</div>',
    '#default_value' => isset($fecha_arr) ? array('month'=>(int)$fecha_arr[1], 'year'=> (int)$fecha_arr[0]) : '',
  );


  /*$form['profesional_academica']['selAnioInicio'] = array(
    '#title' =>ANIO_INICIO,
    '#required' => TRUE,
    '#type' => 'select',
    '#options' => array($arrAnios),
    '#prefix' =>'<div class="small-1 columns">' ,
    '#suffix' => '</div>',
    '#default_value' => isset($values['selAnioInicio']) ? $values['selAnioInicio'] : NULL,
  );*/

  $form['profesional_academica']['selMesFin'] = array(
    '#title' =>MES_FIN,
    '#required' => FALSE,
    '#type' => 'textfield',
    
    '#prefix' =>'<div class="small-4 columns"><label class="popup-mes">' ,
    '#suffix' => '</label></div>',
  );

  /*$form['profesional_academica']['selAnioFin'] = array(
    '#title' =>ANIO_FIN,
    '#required' => TRUE,
    '#type' => 'select',
    '#options' => array($arrAnios),
    '#prefix' =>'<div class="small-1 columns">' ,
    '#suffix' => '</div>',
    '#default_value' => isset($values['selAnioFin']) ? $values['selAnioFin'] : NULL,
  );*/



  $form['profesional_academica']['divAgregarPuesto'] = array(
     '#markup' => '<div class="small-4 columns btn-gris text-right"> 
        <input type="button" name="btnAgregarPuesto" id="btnAgregarPuesto" value='.AGREGAR_PUESTO.'></div><hr></div>
    ',
  );


  $form['profesional_academica']['txtInformacionAcademica'] = array(

    '#markup' => '<div class="row"><div class="small-12 columns ">'.INFORMACION_ACADEMICA.'</div></div>',

  );


  $form['profesional_academica']['divAcademica'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns"> <div class=" resaltado" id="divInfoAcademica">Cargando...</div></div></div>',
  );
  $form['profesional_academica']['txtEscuela'] = array(
    '#title' =>ESCUELA,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtEscuela']) ? $values['txtEscuela'] : NULL,
    '#maxlength' => 60,
    '#prefix' =>'<div class="row"><div class="small-4 columns">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => ESCUELA),
  );

  $form['profesional_academica']['radTituloEstudios'] = array(
    '#title' =>TIT_ESTUDIOS,
    '#type' => 'radios',
    '#options' => array('1'=>'Si','0'=>'No',),
    '#prefix' =>'<div class="small-4 columns">' ,
    '#suffix' => '</div></div>',
    '#default_value' => isset($values['radTituloEstudios']) ? $values['radTituloEstudios'] : NULL,
  );


  $form['profesional_academica']['txtTipoEstudio'] = array(
    '#title' =>TIPO_ESTUDIO,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtTipoEstudio']) ? $values['txtTipoEstudio'] : NULL,
    '#maxlength' => 15,
    '#prefix' =>'<div class="row"><div class="small-4 columns">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => TIPO_ESTUDIO),
  );

  $form['profesional_academica']['radEstudioCursando'] = array(
    '#title' =>ESTUDIO_CURSNDO,
    '#type' => 'radios',
    '#options' => array('1'=>'Si','0'=>'No',),
    '#prefix' =>'<div class="small-4 columns">' ,
    '#suffix' => '</div>',
    '#default_value' => isset($values['radEstudioCursando']) ? $values['radEstudioCursando'] : NULL,
  );

  $form['profesional_academica']['divAgregarEstudio'] = array(
     '#markup' => '<div class="small-4 columns btn-gris text-right"> 
        <input type="button" name="btnAgregarEstudio" id="btnAgregarEstudio" value='.AGREGAR_ESTUDIO.'></div><hr></div>
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


/**
 * Función para gestionar el formulario de  intereses.
 * Aquí se insertarán los campos correspondientes a este paso
 * Creado por Ricardo Aguilera
 *
 * @see configuracioncuenta_form().
 *
 * @param type $form
 * @param type $form_state
 * @return type
 */
function configuracioncuenta_intereses_form($form, &$form_state) {

  $values = isset($form_state['multistep_values']['intereses']) ? $form_state['multistep_values']['intereses'] : array();
 /* global $user;
  $user_fields = user_load($user->uid);
  $intereses=get_intereses($user->uid);

  foreach($intereses as $idinteres){

     $interes[]=$idinteres->taxonomy_id;
  }

  $categories = get_parents(2);*/

  $categories = array (
      1=>"prueba1",
      2=>"prueba2",
      3=>"prueba3",
      4=>"prueba4",
      5=>"prueba5",
    );
  
  $form['intereses']['chkInteres'] = array(
    '#title' =>INTERES,
    '#type' => 'checkboxes',
    '#options' => $categories,
    '#prefix' =>'<div class="row"><div class="small-12 columns tercio">',
    '#suffix' => '</div></div>',
    '#default_value' => $interes,

  );

$form['intereses']['txtOtroInteres'] = array(
    '#title' =>OTRO_INTERES,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtOtroInteres']) ? $values['txtOtroInteres'] : NULL,
    '#maxlength' => 35,
    '#prefix' =>'<div class="row"><div class="small-4 columns">',
    '#suffix' => '</div>',
  );

$form['intereses']['btnAgregarInteres'] = array(
    '#value' =>AGREGAR_INTERES,
    '#type' => 'button',
    '#prefix' =>'<div class="small-8 columns btn-gris text-right">',
    '#suffix' => '</div><hr/></div>', 
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


/**
 * Función para gestionar el formulario de  privacidad.
 * Aquí se insertarán los campos correspondientes a este paso
 * Creado por Ricardo Aguilera
 *
 * @see configuracioncuenta_form().
 *
 * @param type $form
 * @param type $form_state
 * @return type
 */
function configuracioncuenta_privacidad_form($form, &$form_state) {

  $values = isset($form_state['multistep_values']['privacidad']) ? $form_state['multistep_values']['privacidad'] : array();
  /*global $user;
  $user_fields = user_load($user->uid);
  print_r($user->uid);
  $values['radPerfilPublico'] = $user_fields->field_usuario_privacidad_perfil['und'][0]['value'] != NULL ? $user_fields->field_usuario_privacidad_perfil['und'][0]['value'] : NULL;
  $values['radPersonalPublico'] = $user_fields->field_usuario_privacidad_persona['und'][0]['value'] != NULL ? $user_fields->field_usuario_privacidad_persona['und'][0]['value'] : NULL;
  $values['radContactoPublico'] = $user_fields->field_usuario_privacidad_contact['und'][0]['value'] != NULL ? $user_fields->field_usuario_privacidad_contact['und'][0]['value'] : NULL;
  $values['radRedesPublico'] = $user_fields->field_usuario_privacidad_social['und'][0]['value'] != NULL ? $user_fields->field_usuario_privacidad_social['und'][0]['value'] : NULL;
  $values['radProfesionalPublico'] = $user_fields->field_usuario_privacidad_prof['und'][0]['value'] != NULL ? $user_fields->field_usuario_privacidad_prof['und'][0]['value'] : NULL;
  $values['radAcademicaPublico'] = $user_fields->field_usuario_privacidad_academi['und'][0]['value'] != NULL ? $user_fields->field_usuario_privacidad_academi['und'][0]['value'] : NULL;
  $values['radCursosPublico'] = $user_fields->field_usuario_privacidad_cursos['und'][0]['value'] != NULL ? $user_fields->field_usuario_privacidad_cursos['und'][0]['value'] : NULL;
  $values['radGruposPublico'] = $user_fields->field_usuario_privacidad_grupos['und'][0]['value'] != NULL ? $user_fields->field_usuario_privacidad_grupos['und'][0]['value'] : NULL;
  $values['radPortafolioPublico'] = $user_fields->field_usuario_privacidad_portafo['und'][0]['value'] != NULL ? $user_fields->field_usuario_privacidad_portafo['und'][0]['value'] : NULL;
  $values['radProductosPublico'] = $user_fields->field_usuario_privacidad_product['und'][0]['value'] != NULL ? $user_fields->field_usuario_privacidad_product['und'][0]['value'] : NULL;
  $values['radMensajesPublico'] = $user_fields->field_usuarios_privacidad_mensaj['und'][0]['value'] != NULL ? $user_fields->field_usuarios_privacidad_mensaj['und'][0]['value'] : NULL;

*/
  $form['privacidad']['lblPerfil'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns"><h6>'.TITULO_PRIVACIDAD_PERFIL.'</h6></div></div>',
  );
  $form['privacidad']['radPerfilPublico'] = array(
    '#title' =>PERFIL,
    '#type' => 'radios',
    '#options' => array('0'=>PRIVADO,'1'=>PUBLICO,),
    '#prefix' =>'<div class="row"><div class="small-6 columns"><div class="small-12 columns">
      <label class="small-3 columns">'.PERFIL.'</label><div class=" label-hidden">
    ' ,
    '#suffix' => '</div></div></div>',
    '#default_value' => isset($values['radPerfilPublico']) ? $values['radPerfilPublico'] : NULL,
  );
  $form['privacidad']['divPerfil'] = array(
    '#markup' => '<div class="small-6 columns"><div class=" resaltado">'.TEXTO_PRIVACIDAD_PERFIL.'</div></div><hr/></div>',
  );

  $form['privacidad']['lblInformacion'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns"><h6>'.TITULO_PRIVACIDAD_INFO.'</h6></div></div>',
  );
  $form['privacidad']['radPersonalPublico'] = array(
    '#title' =>PERSONAL,
    '#type' => 'radios',
    '#options' => array('0'=>PRIVADO,'1'=>PUBLICO,),
    '#prefix' =>'<div class="row"><div class="small-6 columns"><div class="small-12 columns">
      <label class="small-3 columns">'.PERSONAL.'</label><div class=" label-hidden">
    ' ,
    '#suffix' => '</div></div>',
    '#default_value' => isset($values['radPersonalPublico']) ? $values['radPersonalPublico'] : NULL,
  );

  $form['privacidad']['radContactoPublico'] = array(
    '#title' =>CONTACTO_NOMBRE,
    '#type' => 'radios',
    '#options' => array('0'=>PRIVADO,'1'=>PUBLICO,),
    '#prefix' =>'<div class="small-12 columns ">
      <label class="small-3 columns">'.CONTACTO_NOMBRE.'</label><div class=" label-hidden">
    ' ,
    '#suffix' => '</div></div>',
    '#default_value' => isset($values['radContactoPublico']) ? $values['radContactoPublico'] : NULL,
  );

  $form['privacidad']['radRedesPublico'] = array(
    '#title' =>REDES,
    '#type' => 'radios',
    '#options' => array('0'=>PRIVADO,'1'=>PUBLICO,),
    '#prefix' =>'<div class="small-12 columns ">
      <label class="small-3 columns">'.REDES.'</label><div class=" label-hidden">
    ' ,
    '#suffix' => '</div></div>',
    '#default_value' => isset($values['radRedesPublico']) ? $values['radRedesPublico'] : NULL,
  );

  $form['privacidad']['radProfesionalPublico'] = array(
    '#title' =>PROFESIONAL,
    '#type' => 'radios',
    '#options' => array('0'=>PRIVADO,'1'=>PUBLICO,),
    '#prefix' =>'<div class="small-12 columns ">
      <label class="small-3 columns">'.PROFESIONAL.'</label><div class=" label-hidden">
    ' ,
    '#suffix' => '</div></div>',
    '#default_value' => isset($values['radProfesionalPublico']) ? $values['radProfesionalPublico'] : NULL,
  );

  $form['privacidad']['radAcademicaPublico'] = array(
    '#title' =>ACADEMIA,
    '#type' => 'radios',
    '#options' => array('0'=>PRIVADO,'1'=>PUBLICO,),
    '#prefix' =>'<div class="small-12 columns ">
      <label class="small-3 columns">'.ACADEMIA.'</label><div class=" label-hidden">
    ' ,
    '#suffix' => '</div></div></div>',
    '#default_value' => isset($values['radAcademicaPublico']) ? $values['radAcademicaPublico'] : NULL,
  );

  $form['privacidad']['divInformacion'] = array(
    '#markup' => '<div class="small-6 columns"><div class=" resaltado" >'.TEXTO_PRIVACIDAD_INFO.'</div></div><hr/></div>',
  );

  $form['privacidad']['lblSecciones'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns"><h6>'.TITULO_PRIVACIDAD_SECCIONES.'</h6></div></div>',
  );
  $form['privacidad']['radCursosPublico'] = array(
    '#title' =>CURSOS,
    '#type' => 'radios',
    '#options' => array('0'=>PRIVADO,'1'=>PUBLICO,),
    '#prefix' =>'<div class="row"><div class="small-6 columns"><div class="small-12 columns">
      <label class="small-3 columns">'.CURSOS.'</label><div class="label-hidden">
    ' ,
    '#suffix' => '</div></div>',
    '#default_value' => isset($values['radCursosPublico']) ? $values['radCursosPublico'] : NULL,
  );

  $form['privacidad']['radGruposPublico'] = array(
    '#title' =>GRUPOS,
    '#type' => 'radios',
    '#options' => array('0'=>PRIVADO,'1'=>PUBLICO,),
    '#prefix' =>'<div class="small-12 columns">
      <label class="small-3 columns">'.GRUPOS.'</label><div class=" label-hidden">
    ' ,
    '#suffix' => '</div></div>',
    '#default_value' => isset($values['radGruposPublico']) ? $values['radGruposPublico'] : NULL,
  );

  $form['privacidad']['radPortafolioPublico'] = array(
    '#title' =>PORTAFOLIO,
    '#type' => 'radios',
    '#options' => array('0'=>PRIVADO,'1'=>PUBLICO,),
    '#prefix' =>'<div class="small-12 columns">
      <label class="small-3 columns">'.PORTAFOLIO.'</label><div class=" label-hidden">
    ' ,
    '#suffix' => '</div></div>',
    '#default_value' => isset($values['radPortafolioPublico']) ? $values['radPortafolioPublico'] : NULL,
  );

  $form['privacidad']['radProductosPublico'] = array(
    '#title' =>PRODUCTOS,
    '#type' => 'radios',
    '#options' => array('0'=>PRIVADO,'1'=>PUBLICO,),
    '#prefix' =>'<div class="small-12 columns">
      <label class="small-3 columns">'.PRODUCTOS.'</label><div class=" label-hidden">
    ' ,
    '#suffix' => '</div></div></div>',
    '#default_value' => isset($values['radProductosPublico']) ? $values['radProductosPublico'] : NULL,
  );

  $form['privacidad']['divSecciones'] = array(
    '#markup' => '<div class="small-6 columns"><div class=" resaltado">'.TEXTO_PRIVACIDAD_SECCIONES.'</div></div><hr/></div>',
  );
  $form['privacidad']['lblMensajeria'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns"><h6>'.TITULO_PRIVACIDAD_MENSAJERIA.'</h6></div></div>',
  );

  $form['privacidad']['radMensajesPublico'] = array(
    '#title' =>MENSAJES,
    '#type' => 'radios',
    '#options' => array('0'=>PRIVADO,'1'=>PUBLICO,),
    '#prefix' =>'<div class="row"><div class="small-6 columns">
      <label class="small-3 columns">'.MENSAJES.'</label><div class=" label-hidden">
    ' ,
    '#suffix' => '</div></div>',
    '#default_value' => isset($values['radMensajesPublico']) ? $values['radMensajesPublico'] : NULL,
  );

  $form['privacidad']['divMensajeria'] = array(
    '#markup' => '<div class="small-6 columns"><div class=" resaltado">'.TEXTO_PRIVACIDAD_MENSAJERIA.'</div></div><hr/></div>',
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


/**
 * Función para gestionar el formulario de  facturacion.
 * Aquí se insertarán los campos correspondientes a este paso
 * Creado por Ricardo Aguilera
 *
 * @see configuracioncuenta_form().
 *
 * @param type $form
 * @param type $form_state
 * @return type
 */
function configuracioncuenta_facturacion_form($form, &$form_state) {

  $values = isset($form_state['multistep_values']['facturacion']) ? $form_state['multistep_values']['facturacion'] : array();
  /*global $user;
  $n=get_persona($user->uid);
  print_r($n);
  #$user_fields = user_load($user->uid);
  $node = node_load($n);
  $nid=$node->nid;

  $values['radTipoPersona'] = $node->field_persona_tipo['und'][0]['value'] != NULL ? $node->field_persona_tipo['und'][0]['value'] : NULL;
  $values['txtRazonSocial'] = $node->field_persona_razon_social['und'][0]['value'] != NULL ? $node->field_persona_razon_social['und'][0]['value'] : NULL;
  $values['txtRFC'] = $node->field_persona_rfc['und'][0]['value'] != NULL ? $node->field_persona_rfc['und'][0]['value'] : NULL;
  $values['txtCalle'] = $node->field_direcciones_calle['und'][0]['value'] != NULL ? $node->field_direcciones_calle['und'][0]['value'] : NULL;
  $values['txtNumeroExterior'] = $node->field_direcciones_nexterior['und'][0]['value'] != NULL ? $node->field_direcciones_nexterior['und'][0]['value'] : NULL;
  $values['txtNumeroInterior'] = $node->field_direcciones_ninterior['und'][0]['value'] != NULL ? $node->field_direcciones_ninterior['und'][0]['value'] : NULL;
  $values['txtColonia'] = $node->field_direcciones_colonia['und'][0]['value'] != NULL ? $node->field_direcciones_colonia['und'][0]['value'] : NULL;
  $values['txtDelegacionMunicipio'] = $node->field_direcciones_municipio['und'][0]['value'] != NULL ? $node->field_direcciones_municipio['und'][0]['value'] : NULL;
  $values['selEstado'] = $node->field_direcciones_estado['und'][0]['value'] != NULL ? $node->field_direcciones_estado['und'][0]['value'] : NULL;
  $values['SelCiudad'] = $node->field_direcciones_ciudad['und'][0]['value'] != NULL ? $node->field_direcciones_ciudad['und'][0]['value'] : NULL;
  $values['txtCP'] = $node->field_direcciones_codigo_postal['und'][0]['value'] != NULL ? $node->field_direcciones_codigo_postal['und'][0]['value'] : NULL;
  $values['selPais'] = $node->field_direcciones_pais['und'][0]['value'] != NULL ? $node->field_direcciones_pais['und'][0]['value'] : NULL;
  $values['txtTelefono'] = $node->field_usuario_telefono_otro['und'][0]['value'] != NULL ? $node->field_usuario_telefono_otro['und'][0]['value'] : NULL;
  $values['txtEmail'] = $node->field_usuario_correo['und'][0]['value'] != NULL ? $node->field_usuario_correo['und'][0]['value'] : NULL;*/
  $form['privacidad']['divSecciones'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns"><div class=" resaltado">'.TEXTO_PRIVACIDAD_SECCIONES.'</div></div></div>',
  );

  $form['direcciones']['nid'] = array(
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => $nid,

  );

  $form['facturacion']['lblTipoPersona'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns"><h6>'.TIPO_PERSONA_TITULO.'</h6></div></div>',
  );
   $form['facturacion']['radTipoPersona'] = array(
    '#title' =>TIPO_PERSONA,
    '#type' => 'radios',

    '#options' => array('0'=>MORAL,'1'=>FISICA,),
    '#prefix' =>'<div class="row"><div class="small-12 columns">' ,
    '#suffix' => '</div></div>',
    '#default_value' => isset($values['radTipoPersona']) ? $values['radTipoPersona'] : NULL,
  );

  $form['facturacion']['txtRazonSocial'] = array(
    '#title' =>RAZON_SOCIAL,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtRazonSocial']) ? $values['txtRazonSocial'] : NULL,
    '#maxlength' => 60,
    '#prefix' =>'<div class="row"><div class="small-6 columns">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => RAZON_SOCIAL),
  );

  $form['facturacion']['txtRFC'] = array(
    '#title' =>RFC,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtRFC']) ? $values['txtRFC'] : NULL,
    '#maxlength' => 14,
    '#prefix' =>'<div class="small-4 columns end">' ,
    '#suffix' => '</div><hr/></div>',
    '#attributes' =>array('placeholder' => RFC),
  );


  $form['facturacion']['lblDomicilioFiscal'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns"><h6>'.DOMICILIO_FISCAL.'</h6></div></div>',
  );



  $form['facturacion']['chkDireccionExistente'] = array(
    '#title' =>DIRECCION_EXISTENTE,
    '#type' => 'checkbox',
    '#prefix' =>'<div class="row"><div class="small-8 columns" >' ,
    '#suffix' => '</div>',
  );

  $form['facturacion']['selDireccionExistente'] = array(
    '#title' =>SEL_DIRECCION_EXISTENTE,
    '#required' => FALSE,
    '#type' => 'select',
    '#options' => array('0'=>'Selecciona'),
    '#prefix' =>'<div class="small-4 columns"><label class="labelSelect">' ,
    '#suffix' => '</div></div></div>',
  );

  $form['facturacion']['txtCalle'] = array(
    '#title' =>CALLE,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtCalle']) ? $values['txtCalle'] : NULL,
    '#maxlength' => 35,
    '#prefix' =>'<div class="row"><div class="small-4 columns">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => CALLE),
  );

  $form['facturacion']['txtNumeroExterior'] = array(
    '#title' =>NO_EXTERIOR,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtNumeroExterior']) ? $values['txtNumeroExterior'] : NULL,
    '#maxlength' => 4,
    '#prefix' =>'<div class="small-2 columns">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => NO_EXTERIOR),
  );

  $form['facturacion']['txtNumeroInterior'] = array(
    '#title' =>NO_INTERIOR,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtNumeroInterior']) ? $values['txtNumeroInterior'] : NULL,
    '#maxlength' => 4,
    '#prefix' =>'<div class="small-2 columns">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => NO_INTERIOR),
  );

  $form['facturacion']['txtColonia'] = array(
    '#title' =>COLONIA,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtColonia']) ? $values['txtColonia'] : NULL,
    '#maxlength' => 35,
    '#prefix' =>'<div class="small-4 columns">' ,
    '#suffix' => '</div></div>',
    '#attributes' =>array('placeholder' => COLONIA),
  );

  $form['facturacion']['txtDelegacionMunicipio'] = array(
    '#title' =>DEL_MUNIC,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtDelegacionMunicipio']) ? $values['txtDelegacionMunicipio'] : NULL,
    '#maxlength' => 35,
    '#prefix' =>'<div class="row"><div class="small-4 columns">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => DEL_MUNIC),
  );

  $form['facturacion']['selPais'] = array(
    '#title' =>PAIS,
    '#required' => TRUE,
    '#type' => 'select',
    '#options' => get_parents(2),
    '#prefix' =>'<div class="small-4 columns"><label class="labelSelect">' ,
    '#suffix' => '</label></div>',
  );

  $form['facturacion']['selEstado'] = array(
    '#title' =>ESTADO,
    '#required' => TRUE,
    '#type' => 'select',
    '#options' => get_parents(2),
    '#prefix' =>'<div class="small-4 columns"><label class="labelSelect">' ,
    '#suffix' => '</label></div></div>',
  );

  $form['facturacion']['SelCiudad'] = array(
    '#title' =>CIUDAD,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['SelCiudad']) ? $values['SelCiudad'] : NULL,
    '#maxlength' => 35,
    '#prefix' =>'<div class="row"><div class="small-4 columns">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => CIUDAD),
  );

  $form['facturacion']['txtCP'] = array(
    '#title' =>CP,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtCP']) ? $values['txtCP'] : NULL,
    '#maxlength' => 6,
    '#prefix' =>'<div class="small-4 columns">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => CP),
  );

  $form['facturacion']['txtTelefono'] = array(
    '#title' =>TELEFONO,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtTelefono']) ? $values['txtTelefono'] : NULL,
    '#maxlength' => 15,
    '#prefix' =>'<div class="small-4 columns">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => TELEFONO),
  );

  $form['facturacion']['txtEmail'] = array(
    '#title' =>EMAIL,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtEmail']) ? $values['txtEmail'] : NULL,
    '#maxlength' => 60,
    '#prefix' =>'<div class="small-4 columns end">' ,
    '#suffix' => '</div></div>
    <div class="row"><div class="small-6 columns">&nbsp;</div>',
    '#attributes' =>array('placeholder' => EMAIL),
  );

$form['facturacion']['divEliminarDireccion'] = array(
     '#markup' => '<div class="small-3 columns btn-gris text-right"> 
        <input type="button" name="btnEliminarDireccion" id="btnEliminarDireccion" value='.ELIMINAR_DIRECCION.'>
        </div>
    ',
  );
$form['facturacion']['divAgregarDireccion'] = array(
     '#markup' => '<div class="small-3 columns btn-gris text-right"> 
        <input type="button" name="btnAgregarDireccion" id="btnAgregarDireccion" value='.AGREGAR_DIRECCION.'></div><hr></div>
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


/**
 * Función para gestionar el formulario de  pago.
 * Aquí se insertarán los campos correspondientes a este paso
 * Creado por Ricardo Aguilera
 *
 * @see configuracioncuenta_form().
 *
 * @param type $form
 * @param type $form_state
 * @return type
 */
function configuracioncuenta_pago_form($form, &$form_state) {

  $values = isset($form_state['multistep_values']['pago']) ? $form_state['multistep_values']['pago'] : array();
  global $user;
  #$user_fields = user_load($user->uid);
  /*$n=get_tarjeta($user->uid);
  $node = node_load($n);
  $nid=$node->nid;
   #
   print_r($n);
   #$node = node_load(18);
  #
  #$node=node_load_multiple($n);

  $values['txtAliasTarjeta'] = $node->title['und'][0]['value'] != NULL ? $node->title['und'][0]['value'] : NULL;
  $values['txtNumeroTarjeta'] = $node->field_tarjeta_numero['und'][0]['value'] != NULL ? $node->field_tarjeta_numero['und'][0]['value'] : NULL;
  $values['selTipoTarjeta'] = $node->field_tarjeta_tipo['und'][0]['value'] != NULL ? $node->field_tarjeta_tipo['und'][0]['value'] : NULL;
  $values['strNombrePlasticoTarjeta'] = $node->field_tarjeta_nombre['und'][0]['value'] != NULL ? $node->field_tarjeta_nombre['und'][0]['value'] : NULL;
  $values['selMesVencimientoTarjeta'] = $node->field_tarjeta_fecha_vencimiento['und'][0]['value'] != NULL ? $node->field_tarjeta_fecha_vencimiento['und'][0]['value'] : NULL;
  $values['txtCodigoSeguridadTarjeta'] = $node->field_tarjeta_codigo_seguridad['und'][0]['value'] != NULL ? $node->field_tarjeta_codigo_seguridad['und'][0]['value'] : NULL;
  $fecha = date('Y-m',$node->field_tarjeta_fecha_vencimiento['und'][0]['value']);
  $fecha_arr = explode('-',$fecha);*/
  $form['pago']['divTarjetas'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns"><div class="resaltado" id="divTarjetasCont">Cargando...</div></div></div>',
  );

  $form['direcciones']['nid'] = array(
    '#required' => FALSE,
    '#type' => 'hidden',
    '#default_value' => $nid,

  );

    $form['pago']['txtAliasTarjeta'] = array(
    '#title' =>ALIAS_TARJETA,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtAliasTarjeta']) ? $values['txtAliasTarjeta'] : NULL,
    '#maxlength' => 15,
    '#prefix' =>'<div class="row"><div class="small-6 columns">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => ALIAS_TARJETA),
  );


  $form['pago']['selTipoTarjeta'] = array(
    '#title' =>TIPO_TARJETA,
    '#required' => TRUE,
    '#type' => 'select',
    '#default_value' => isset($values['selTipoTarjeta']) ? $values['selTipoTarjeta'] : NULL,
    '#options' => array('0'=>VISA, '1'=>MASTERCARD),
    '#prefix' =>'<div class="small-6 columns"><label class="labelSelect">' ,
    '#suffix' => '</label></div></div>',
  );

  $form['pago']['txtNumeroTarjeta'] = array(
    '#title' =>NUMERO_TARJETA,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtNumeroTarjeta']) ? $values['txtNumeroTarjeta'] : NULL,
    '#maxlength' => 16,
    '#prefix' =>'<div class="row"><div class="small-6 columns">' ,
    '#suffix' => '</div>',
    '#attributes' =>array('placeholder' => NUMERO_TARJETA),
  );

  $form['pago']['selMesVencimientoTarjeta'] = array(
    

     '#title' =>MES_VENCIMIENTO_TARJETA,
    '#type' => 'textfield',

    '#prefix' =>'<div class="small-6 columns"><label class="popup-fecha ">' ,
    '#suffix' => '</label></div></div>',
    '#default_value' => isset($fecha_arr) ? $fecha_arr : '',
    '#attributes' =>array('placeholder' => FORMATO_FECHA),

  );

  $form['pago']['strNombrePlasticoTarjeta'] = array(
    '#title' =>NOMBRE_TARJETA,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['strNombrePlasticoTarjeta']) ? $values['strNombrePlasticoTarjeta'] : NULL,
    '#attributes' =>array('placeholder' => NOMBRE_TARJETA),
    '#prefix' =>'<div class="row"><div class="small-6 columns">' ,
    '#suffix' => '</div>',
  );

  /*
  El siguiente código deberá modificarse en caso de que el tamaño del código de seguridad varíe.
  Esto es especialmente importante si se incluye cobros contarjeta American Express, ya que éstas tiee códigos
  de seguridad de 4 dígitos.
  */


  $form['pago']['txtCodigoSeguridadTarjeta'] = array(
    '#title' =>CODIGO_SEGURIDAD_TARJETA,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtCodigoSeguridadTarjeta']) ? $values['txtCodigoSeguridadTarjeta'] : NULL,
    '#maxlength' => 3,
    '#prefix' =>'<div class="small-6 columns">' ,
    '#suffix' => '</div></div><div class="row"><div class="small-6 columns">&nbsp;</div>',
    '#attributes' =>array('placeholder' => CODIGO_SEGURIDAD_TARJETA),
  );


$form['pago']['divEliminarTarjeta'] = array(
     '#markup' => '<div class="small-3 columns btn-gris text-right"> 
        <input type="button" name="btnEliminarTarjeta" id="btnEliminarTarjeta" value='.ELIMINAR_TARJETA.'>
        </div>
    ',
  );
$form['pago']['divAgregarTarjeta'] = array(
     '#markup' => '<div class="small-3 columns btn-gris text-right"> 
        <input type="button" name="btnAgregarTarjeta" id="btnAgregarTarjeta" value='.AGREGAR_TARJETA.'></div><hr></div>
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


/**
 * Función para gestionar el formulario de  cuentas.
 * Aquí se insertarán los campos correspondientes a este paso
 * Creado por Ricardo Aguilera
 *
 * @see configuracioncuenta_form().
 *
 * @param type $form
 * @param type $form_state
 * @return type
 */
function configuracioncuenta_cuentas_form($form, &$form_state) {

  $values = isset($form_state['multistep_values']['cuentas']) ? $form_state['multistep_values']['cuentas'] : array();
 

$form['cuentas']['divcuentas'] = array(
    '#markup' => '<div class="row"><div class="small-12 columns"><div class="resaltado" id="divCuentaCont">Cargando...</div></div></div>',
  );

$form['cuentas']['txtTipoCuenta'] = array(
   '#title' =>TIPO_CUENTA,
    '#required' => TRUE,
    '#type' => 'select',
    '#default_value' => isset($values['txtTipoCuenta']) ? $values['txtTipoCuenta'] : NULL,
    '#options' => array(1=>"Paypal",2=>"Banco"),
    '#prefix' =>'<div class="row"><div class="small-6 columns"><label class="labelSelect">' ,
    '#suffix' => '</select></div>',
  );
   
$form['cuentas']['txtAliasCuenta'] = array(
   '#title' =>ALIAS_CUENTA,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtAliasCuenta']) ? $values['txtAliasCuenta'] : NULL,
    '#maxlength' => 15,
    '#prefix' =>'<div class="small-6 columns">' ,
    '#suffix' => '</div></div>',
  );
   
$form['cuentas']['txtNombreBanco'] = array(
   '#title' =>NOMBRE_BANCO,
    '#required' => TRUE,
    '#type' => 'select',
    '#default_value' => isset($values['txtNombreBanco']) ? $values['txtNombreBanco'] : NULL,
    '#options' => array(1=>"Bancomer",2=>"Banamex"),
    '#prefix' =>'<div class="row"><div class="small-6 columns"><label class="labelSelect">' ,
    '#suffix' => '</select></div>',
  );
   
$form['cuentas']['txtNombreTitular'] = array(
   '#title' =>NOMBRE_TITULAR,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtNombreTitular']) ? $values['txtNombreTitular'] : NULL,
    '#maxlength' => 60,
    '#prefix' =>'<div class="small-6 columns">' ,
    '#suffix' => '</div></div>',
  );
   
$form['cuentas']['txtNumeroCuenta'] = array(
   '#title' =>NUMERO_CUENTA,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtNumeroCuenta']) ? $values['txtNumeroCuenta'] : NULL,
    '#maxlength' => 16,
    '#prefix' =>'<div class="row"><div class="small-6 columns">' ,
    '#suffix' => '</div>',
  );
   
$form['cuentas']['txtCLABE'] = array(
   '#title' =>CLABE,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtCLABE']) ? $values['txtCLABE'] : NULL,
    '#maxlength' => 18,
    '#prefix' =>'<div class="small-6 columns">' ,
    '#suffix' => '</div></div>
    <div class="row"><div class="small-6 columns>&nbsp;</div>',
  );

$form['pago']['divEliminarCuenta'] = array(
     '#markup' => '<div class="small-3 columns btn-gris text-right"> 
        <input type="button" name="btnEliminarCuenta" id="btnEliminarCuenta" value='.ELIMINAR_CUENTA.'>
        </div>
    ',
  );
$form['pago']['divAgregarCuenta'] = array(
     '#markup' => '<div class="small-3 columns btn-gris text-right"> 
        <input type="button" name="btnAgregarCuenta" id="btnAgregarCuenta" value='.AGREGAR_CUENTA.'></div><hr></div>
    ',
  );

   
   
$form['cuentas']['txtCorreoCuentaPaypal'] = array(
   '#title' =>CORREO_PAYPAL,
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtCorreoCuentaPaypal']) ? $values['txtCorreoCuentaPaypal'] : NULL,
    '#maxlength' => 60,
    '#prefix' =>'<div class="row"><div class="small-6 columns btn-gris">' ,
    '#suffix' => '</div>',
  );
   

$form['pago']['divAgregarCuentaPaypal'] = array(
     '#markup' => '<div class="small-6 columns btn-gris text-right"> 
        <input type="button" name="btnAgregarCuentaPaypal" id="btnAgregarCuentaPaypal" value='.AGREGAR_PAYPAL.'></div><hr></div>
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
    '#suffix' => '</div></div>',
  );
    
  return $form;
}


/**
 * Función para gestionar el formulario de  verificacion_cuenta.
 * Aquí se insertarán los campos correspondientes a este paso
 * Creado por Ricardo Aguilera
 * 
 * @see configuracioncuenta_form().
 *  
 * @param type $form
 * @param type $form_state
 * @return type 
 */
function configuracioncuenta_verificacion_cuenta_form($form, &$form_state) {
    
  $values = isset($form_state['multistep_values']['verificacion_cuenta']) ? $form_state['multistep_values']['verificacion_cuenta'] : array();

  $form['verificacion_cuenta']['filDocumentoIdentificacion'] = array(
    '#title' =>DOC_IDENTIFICACION,
    '#type' => 'managed_file',
    '#progress_message' => 'Please wait...',
    '#progress_indicator' => 'bar',
    '#upload_location' => $directorioDocumentoIdentificacion,
    '#prefix' =>'<div class="row"><div class="small-8 columns">' ,
    '#suffix' => '</div></div>',
  );
   
  $form['verificacion_cuenta']['filComprobanteDomicilio'] = array(
    '#title' =>DOC_DOMICILIO,
    '#type' => 'managed_file',
    '#progress_message' => 'Please wait...',
    '#progress_indicator' => 'bar',
    '#upload_location' => $directorioComprobanteDomicilio,
    '#prefix' =>'<div class="row"><div class="small-8 columns">' ,
    '#suffix' => '</div></div>',
  );

  $form['lblCamposObligatorios'] = array(
    '#markup' => '<div class="row"><div class="small-4 columns"><span class="form-required" title="'.CAMPOS_OBLIGATORIOS.'">* '.CAMPOS_OBLIGATORIOS.'</span></div>',
  );

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => BOTON_GUARDAR,


    '#prefix' =>'<div class="btn-primario">',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Función para gestionar el formulario de  cambio_perfil.
 * Aquí se insertarán los campos correspondientes a este paso
 * Creado por Ricardo Aguilera
 * 
 * @see configuracioncuenta_form().
 *  
 * @param type $form
 * @param type $form_state
 * @return type 
 */
function configuracioncuenta_cambio_perfil_form($form, &$form_state) {
    
  $values = isset($form_state['multistep_values']['cambio_perfil']) ? $form_state['multistep_values']['cambio_perfil'] : array();




 $form['lblCamposObligatorios'] = array(
    '#markup' => '<div class="row"><div class="small-4 columns"><span class="form-required" title="'.CAMPOS_OBLIGATORIOS.'">* '.CAMPOS_OBLIGATORIOS.'</span></div>',
  );


 
  $form['save'] = array(
    '#type' => 'submit',

    '#value' => BOTON_GUARDAR,
    '#prefix' =>'<div class="btn-primario">',
    '#suffix' => '</div>',
  );

  return $form;
}
