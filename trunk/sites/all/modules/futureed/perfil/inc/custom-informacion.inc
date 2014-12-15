<?php

/*----------------------- Consultar Usuario - Informacion -----------------------*/

/*Info Personal*/
function consultar_usuario_informacion_personal_db($uid){
  $arrResultados = array();
  array_push($arrResultados,
    array(
      'field_usuario_privacidad_persona' => 1,
      'field_usuario_fecha_nacimiento' => '12 de Noviembre de 1981',
      'field_usuario_privacidad_contact' => 1,
      'field_usuario_correo' => 'correo@correo.com',
      'field_usuario_telefono_casa' => '83123456',
      'field_usuario_telefono_oficina' => '8111234567',
      'field_usuario_telefono_otro' => '8111234567',
      'field_usuario_username_skype' => 'vato_loko1',
      'field_usuario_username_facebook' => 'vato_loko2',
      'field_usuario_username_google' => 'vato_loko3',
      'field_usuario_sitio_web' => 'www.vatoloko.com',
      'field_usuario_privacidad_social' => 1,
      'field_usuario_url_linkedin' => 'mx.linkedin.com/vatoloko',
      'field_usuario_url_facebook' => 'www.facebook.com/vatoloko',
      'field_usuario_url_google_plus' => 'plus.google.com/vatoloko',
      'field_usuario_url_twitter' => 'www.twitter.com/vatoloko',
    )
  );  

  return $arrResultados;   
}

/*Info Profesional*/
function consultar_usuario_informacion_profesional_db($uid){
  $arrResultados = array();
  array_push($arrResultados,
    array(
      'field_usuario_privacidad_prof' => 1,
      'array_usuario_info_prof' => array(
        array(
          'field_usuario_empresa' => 'Arquimedia',
          'field_usuario_titulo' => FALSE,
          'field_usuario_puesto' => 'Directivo de operaciones',
          'field_usuario_puesto_inicio' => 'Mayo 2004',
          'field_usuario_puesto_fin' => 'presente',
        ),
        array(
          'field_usuario_empresa' => 'Grupo Carza',
          'field_usuario_titulo' => FALSE,
          'field_usuario_puesto' => 'Asistente de director',
          'field_usuario_puesto_inicio' => 'Septiembre 2002',
          'field_usuario_puesto_fin' => 'Mayo 2004',
        )
      ),
      'field_usuario_privacidad_academi' => 1,
      'array_usuario_info_academi' => array(
        array(
          'field_usuario_escuela' => 'UANL',
          'field_usuario_estudios' => 'Arquitecto',
        ),
        array(
          'field_usuario_escuela' => 'Practum',
          'field_usuario_estudios' => 'Diseño y urbanizacion sustentable',
        ),
        array(
          'field_usuario_escuela' => 'Coursera',
          'field_usuario_estudios' => 'Expecialidad en urbanización y construcción con materiales renovables',
        )
      ),
    )
  );  

  return $arrResultados;   
}