<?php

/*----------------------- Consultar Empresa - Nosotros -----------------------*/

/*Info Nosotros*/
function consultar_empresa_nosotros_contacto_db($uid){
  $arrResultados = array();
  array_push($arrResultados,
    array(
      'field_empresa_privacidad_contact' => 1,
      'field_empresa_correo' => 'empresa_correo@correo.com',
      'field_empresa_telefono' => '811 3979 290',
      'field_usuario_username_skype' => 'edu1',
      'field_usuario_username_facebook' => 'edu2',
      'field_usuario_username_google' => 'edu4',
      'field_usuario_sitio_web' => 'www.edu.com',
      'field_empresa_privacidad_social' => 1,
      'field_usuario_url_linkedin' => 'mx.linkedin.com/edu',
      'field_usuario_url_facebook' => 'www.facebook.com/edu',
      'field_usuario_url_google_plus' => 'plus.google.com/edu',
      'field_usuario_url_twitter' => 'www.twitter.com/edu',
      'calc_usuario_direccion' => 'Av. Gomez Morin 403 Col. del Valle, San Pedro, N.L., Mexico. C.P. 230947',
      'field_empresa_privacidad_perfil' => 1,
    )
  );  

  return $arrResultados;   
}

/*Info Sobre Nosotros*/
function consultar_empresa_sobre_nosotros_db($uid){
  $arrResultados = array();
  array_push($arrResultados,
    array(
      'field_usuario_privacidad_prof' => 1,
      'field_empresa_nosotros' => 'bla bla bla',
      'field_empresa_mision' => 'bla bla bla',
      'field_empresa_vision' => 'bla bla bla',
    )
  );  

  return $arrResultados;   
}