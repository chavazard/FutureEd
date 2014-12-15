<?php

/*
      PARA IMPLEMENTAR CON BACK END:
          $data = '?f_name=nombre_funcion&uid=1';    ()        
          $data = get_data_from_service($data, false);
          return $data;
          
      FUNCIONES PARA PERFIL USUARIO:
          get_usuario_header  (Header) 
          get_usuario_info    (Contacto) 
          get_usuario_prof_info (Información profesional y académica)
      
      FUNCIONES PARA PERFIL EMPRESA:
          get_empresa_header (Header) 
          get_empresa_info   (Contacto)
          get_empresa_acerca (Acerca de nosotros mision y vision)
 **/


/*----------------------- Consultar Perfil - Usuarios -----------------------*/

function consultar_usuarios_perfil_db($uid){
  $arrResultados = array();
  array_push($arrResultados,
    array(
      'uid' => 1,
      'calc_usuario_nombre' => 'Rene Camacho',
      'field_usuario_imagen' => 'http://placehold.it/100x100',
      'field_usuario_username' => 'vato_loco',
      'field_usuario_numero_seguidores' => '129',
      'field_usuario_numero_seguidos' => '40',
      'field_usuario_roles' => array(
        array(
          'rol1' => 1,
          'rol2' => 2,
          'rol3' => 3,
          'rol4' => 4,
        )
      ),
      'field_usuario_privacidad_perfil' => 1,
    )
  );  

  return $arrResultados;   
}