<?php

/*--------------------------Busquedas --------------------------*/
/*Busqueda - Cursos*/
function consultar_busqueda_generales_cursos_db($arrFiltros, $string_busqueda, $limite_inicial, $limite_final){
  $arrResultados = array();
  array_push($arrResultados,
    array(
      'nid' => 1,  
      'field_curso_nombre' => l('Curso Matematicas II - 1','matematicas2.com'),
      'field_curso_imagen' => 'http://placehold.it/100x50',
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_creador_nombre' => 'Ricardo',
      'link_curso_creador' => 'usuario1',
      'field_usuario_verificado' => TRUE,
      'field_curso_fecha' => '01/01/2015',
      'link_curso' => 'curso1',
      'field_curso_precio' => '4,400.00 MXN',
      'field_curso_descuento' => FALSE,
      'calc_curso_costo_total' => FALSE,
      'field_curso_calificacion' => 5,
      'field_curso_numero_votos' => 28,
      'field_likes' => 15,
      'array_usuarios_curso' => array(
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        )
      ),
    ),
    array(
      'nid' => 2,  
      'field_curso_nombre' => l('Curso Matematicas II - 2','matematicas2.com'),
      'field_curso_imagen' => 'http://placehold.it/100x50',
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_creador_nombre' => 'Ricardo',
      'link_curso_creador' => 'usuario2',
      'field_usuario_verificado' => TRUE,
      'field_curso_fecha' => FALSE,
      'link_curso' => 'curso2',
      'field_curso_precio' => '4,400.00 MXN',
      'field_curso_descuento' => '10%',
      'calc_curso_costo_total' => '4,000.00 MXN',
      'field_curso_calificacion' => 4,
      'field_curso_numero_votos' => 10,
      'field_likes' => 5,
      'array_usuarios_curso' => array(
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_2',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_2',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_2',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_2',
        )
      ),
    ),
    array(
      'nid' => 3,  
      'field_curso_nombre' => l('Curso Matematicas II - 3','matematicas2.com'),
      'field_curso_imagen' => 'http://placehold.it/100x50',
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_creador_nombre' => 'Ricardo',
      'link_curso_creador' => 'usuario3',
      'field_usuario_verificado' => TRUE,
      'field_curso_fecha' => '01/01/2015',
      'link_curso' => 'curso3',
      'field_curso_precio' => '4,00.00 MXN',
      'field_curso_descuento' => FALSE,
      'calc_curso_costo_total' => FALSE,
      'field_curso_calificacion' => 4.5,
      'field_curso_numero_votos' => 30,
      'field_likes' => 10,
      'array_usuarios_curso' => array(
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_3',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_3',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_3',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_3',
        )
      ),
    ),
    array(
      'nid' => 1,  
      'field_curso_nombre' => l('Curso Matematicas II - 1','matematicas2.com'),
      'field_curso_imagen' => 'http://placehold.it/100x50',
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_creador_nombre' => 'Ricardo',
      'link_curso_creador' => 'usuario1',
      'field_usuario_verificado' => TRUE,
      'field_curso_fecha' => '01/01/2015',
      'link_curso' => 'curso1',
      'field_curso_precio' => '4,400.00 MXN',
      'field_curso_descuento' => FALSE,
      'calc_curso_costo_total' => FALSE,
      'field_curso_calificacion' => 5,
      'field_curso_numero_votos' => 28,
      'field_likes' => 15,
      'array_usuarios_curso' => array(
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        )
      ),
    ),
    array(
      'nid' => 1,  
      'field_curso_nombre' => l('Curso Matematicas II - 1','matematicas2.com'),
      'field_curso_imagen' => 'http://placehold.it/100x50',
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_creador_nombre' => 'Ricardo',
      'link_curso_creador' => 'usuario1',
      'field_usuario_verificado' => TRUE,
      'field_curso_fecha' => '01/01/2015',
      'link_curso' => 'curso1',
      'field_curso_precio' => '4,400.00 MXN',
      'field_curso_descuento' => FALSE,
      'calc_curso_costo_total' => FALSE,
      'field_curso_calificacion' => 5,
      'field_curso_numero_votos' => 28,
      'field_likes' => 15,
      'array_usuarios_curso' => array(
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        )
      ),
    ),
    array(
      'nid' => 1,  
      'field_curso_nombre' => l('Curso Matematicas II - 1','matematicas2.com'),
      'field_curso_imagen' => 'http://placehold.it/100x50',
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_creador_nombre' => 'Ricardo',
      'link_curso_creador' => 'usuario1',
      'field_usuario_verificado' => TRUE,
      'field_curso_fecha' => '01/01/2015',
      'link_curso' => 'curso1',
      'field_curso_precio' => '4,400.00 MXN',
      'field_curso_descuento' => FALSE,
      'calc_curso_costo_total' => FALSE,
      'field_curso_calificacion' => 5,
      'field_curso_numero_votos' => 28,
      'field_likes' => 15,
      'array_usuarios_curso' => array(
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        )
      ),
    ),
    array(
      'nid' => 1,  
      'field_curso_nombre' => l('Curso Matematicas II - 1','matematicas2.com'),
      'field_curso_imagen' => 'http://placehold.it/100x50',
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_creador_nombre' => 'Ricardo',
      'link_curso_creador' => 'usuario1',
      'field_usuario_verificado' => TRUE,
      'field_curso_fecha' => '01/01/2015',
      'link_curso' => 'curso1',
      'field_curso_precio' => '4,400.00 MXN',
      'field_curso_descuento' => FALSE,
      'calc_curso_costo_total' => FALSE,
      'field_curso_calificacion' => 5,
      'field_curso_numero_votos' => 28,
      'field_likes' => 15,
      'array_usuarios_curso' => array(
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        )
      ),
    ),
    array(
      'nid' => 1,  
      'field_curso_nombre' => l('Curso Matematicas II - 1','matematicas2.com'),
      'field_curso_imagen' => 'http://placehold.it/100x50',
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_creador_nombre' => 'Ricardo',
      'link_curso_creador' => 'usuario1',
      'field_usuario_verificado' => TRUE,
      'field_curso_fecha' => '01/01/2015',
      'link_curso' => 'curso1',
      'field_curso_precio' => '4,400.00 MXN',
      'field_curso_descuento' => FALSE,
      'calc_curso_costo_total' => FALSE,
      'field_curso_calificacion' => 5,
      'field_curso_numero_votos' => 28,
      'field_likes' => 15,
      'array_usuarios_curso' => array(
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        )
      ),
    ),
    array(
      'nid' => 1,  
      'field_curso_nombre' => l('Curso Matematicas II - 1','matematicas2.com'),
      'field_curso_imagen' => 'http://placehold.it/100x50',
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_creador_nombre' => 'Ricardo',
      'link_curso_creador' => 'usuario1',
      'field_usuario_verificado' => TRUE,
      'field_curso_fecha' => '01/01/2015',
      'link_curso' => 'curso1',
      'field_curso_precio' => '4,400.00 MXN',
      'field_curso_descuento' => FALSE,
      'calc_curso_costo_total' => FALSE,
      'field_curso_calificacion' => 5,
      'field_curso_numero_votos' => 28,
      'field_likes' => 15,
      'array_usuarios_curso' => array(
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        )
      ),
    ),
    array(
      'nid' => 1,  
      'field_curso_nombre' => l('Curso Matematicas II - 1','matematicas2.com'),
      'field_curso_imagen' => 'http://placehold.it/100x50',
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_creador_nombre' => 'Ricardo',
      'link_curso_creador' => 'usuario1',
      'field_usuario_verificado' => TRUE,
      'field_curso_fecha' => '01/01/2015',
      'link_curso' => 'curso1',
      'field_curso_precio' => '4,400.00 MXN',
      'field_curso_descuento' => FALSE,
      'calc_curso_costo_total' => FALSE,
      'field_curso_calificacion' => 5,
      'field_curso_numero_votos' => 28,
      'field_likes' => 15,
      'array_usuarios_curso' => array(
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        )
      ),
    ),
    array(
      'nid' => 1,  
      'field_curso_nombre' => l('Curso Matematicas II - 1','matematicas2.com'),
      'field_curso_imagen' => 'http://placehold.it/100x50',
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_creador_nombre' => 'Ricardo',
      'link_curso_creador' => 'usuario1',
      'field_usuario_verificado' => TRUE,
      'field_curso_fecha' => '01/01/2015',
      'link_curso' => 'curso1',
      'field_curso_precio' => '4,400.00 MXN',
      'field_curso_descuento' => FALSE,
      'calc_curso_costo_total' => FALSE,
      'field_curso_calificacion' => 5,
      'field_curso_numero_votos' => 28,
      'field_likes' => 15,
      'array_usuarios_curso' => array(
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        ),
        array(
          'calc_usuario_nombre' => 'Eduardo Salas',
          'field_usuario_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario_1',
        )
      ),
    )
  );  
  $totalResultados = sizeof($arrResultados);
        
  $indiceDevueltos = 1;
  
  $arrRegresar = array();
  $arrTemporal = array();
  
  foreach($arrResultados as $item){ 

      if ($indiceDevueltos >= $limite_inicial && $indiceDevueltos <= $limite_final)
      {
          array_push($arrTemporal, $item);
      }

      $indiceDevueltos++;
  } 
  
  array_push($arrRegresar,array(
    'totalResultados' => $totalResultados,
    'items' => $arrTemporal
  ));
  
  return $arrRegresar; 
}

/*Busqueda - Empresas*/
function consultar_busqueda_generales_empresas_db($string_busqueda, $limite_inicial, $limite_final){
  $arrResultados = array();
  array_push($arrResultados,
    array(
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_usuario_nombre' => 'Empresa 1',
      'field_usuario_verificado' => TRUE,
      'calc_usuario_ubicacion' => 'Mty, NL, Mexico',
      'array_cursos_usuario' => array(
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        )
      ),
      'calc_numero_cursos' => 159,
      'field_usuario_numero_seguidores' => 45,
      'field_usuario_roles' => array(
        array(
          'rol1' => 1,
          'rol2' => 2,
          'rol3' => 3,
        )
      ),
      'link_usuario' => 'usuario1',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_usuario_nombre' => 'Empresa 2',
      'field_usuario_verificado' => TRUE,
      'calc_usuario_ubicacion' => 'Mty, NL, Mexico',
      'array_cursos_usuario' => array(
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        )
      ),
      'calc_numero_cursos' => 20,
      'field_usuario_numero_seguidores' => 100,
      'field_usuario_roles' => array(
        array(
          'rol1' => 1,
          'rol2' => 2,
          'rol3' => 3,
        )
      ),
      'link_usuario' => 'usuario1',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_usuario_nombre' => 'Empresa 3',
      'field_usuario_verificado' => TRUE,
      'calc_usuario_ubicacion' => 'Mty, NL, Mexico',
      'array_cursos_usuario' => array(
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        )
      ),
      'calc_numero_cursos' => 20,
      'field_usuario_numero_seguidores' => 100,
      'field_usuario_roles' => array(
        array(
          'rol1' => 1,
          'rol2' => 2,
          'rol3' => 3,
        )
      ),
      'link_usuario' => 'usuario1',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_usuario_nombre' => 'Empresa 1',
      'field_usuario_verificado' => TRUE,
      'calc_usuario_ubicacion' => 'Mty, NL, Mexico',
      'array_cursos_usuario' => array(
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        )
      ),
      'calc_numero_cursos' => 20,
      'field_usuario_numero_seguidores' => 100,
      'field_usuario_roles' => array(
        array(
          'rol1' => 1,
          'rol2' => 2,
          'rol3' => 3,
        )
      ),
      'link_usuario' => 'usuario1',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_usuario_nombre' => 'Empresa 1',
      'field_usuario_verificado' => TRUE,
      'calc_usuario_ubicacion' => 'Mty, NL, Mexico',
      'array_cursos_usuario' => array(
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        )
      ),
      'calc_numero_cursos' => 20,
      'field_usuario_numero_seguidores' => 100,
      'field_usuario_roles' => array(
        array(
          'rol1' => 1,
          'rol2' => 2,
          'rol3' => 3,
        )
      ),
      'link_usuario' => 'usuario1',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_usuario_nombre' => 'Empresa 1',
      'field_usuario_verificado' => TRUE,
      'calc_usuario_ubicacion' => 'Mty, NL, Mexico',
      'array_cursos_usuario' => array(
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        )
      ),
      'calc_numero_cursos' => 20,
      'field_usuario_numero_seguidores' => 100,
      'field_usuario_roles' => array(
        array(
          'rol1' => 1,
          'rol2' => 2,
          'rol3' => 3,
        )
      ),
      'link_usuario' => 'usuario1',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_usuario_nombre' => 'Empresa 1',
      'field_usuario_verificado' => TRUE,
      'calc_usuario_ubicacion' => 'Mty, NL, Mexico',
      'array_cursos_usuario' => array(
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        )
      ),
      'calc_numero_cursos' => 20,
      'field_usuario_numero_seguidores' => 100,
      'field_usuario_roles' => array(
        array(
          'rol1' => 1,
          'rol2' => 2,
          'rol3' => 3,
        )
      ),
      'link_usuario' => 'usuario1',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_usuario_nombre' => 'Empresa 1',
      'field_usuario_verificado' => TRUE,
      'calc_usuario_ubicacion' => 'Mty, NL, Mexico',
      'array_cursos_usuario' => array(
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        )
      ),
      'calc_numero_cursos' => 20,
      'field_usuario_numero_seguidores' => 100,
      'field_usuario_roles' => array(
        array(
          'rol1' => 1,
          'rol2' => 2,
          'rol3' => 3,
        )
      ),
      'link_usuario' => 'usuario1',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_usuario_nombre' => 'Empresa 1',
      'field_usuario_verificado' => TRUE,
      'calc_usuario_ubicacion' => 'Mty, NL, Mexico',
      'array_cursos_usuario' => array(
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        )
      ),
      'calc_numero_cursos' => 20,
      'field_usuario_numero_seguidores' => 100,
      'field_usuario_roles' => array(
        array(
          'rol1' => 1,
          'rol2' => 2,
          'rol3' => 3,
        )
      ),
      'link_usuario' => 'usuario1',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_usuario_nombre' => 'Empresa 1',
      'field_usuario_verificado' => TRUE,
      'calc_usuario_ubicacion' => 'Mty, NL, Mexico',
      'array_cursos_usuario' => array(
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        )
      ),
      'calc_numero_cursos' => 20,
      'field_usuario_numero_seguidores' => 100,
      'field_usuario_roles' => array(
        array(
          'rol1' => 1,
          'rol2' => 2,
          'rol3' => 3,
        )
      ),
      'link_usuario' => 'usuario1',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_usuario_nombre' => 'Empresa 1',
      'field_usuario_verificado' => TRUE,
      'calc_usuario_ubicacion' => 'Mty, NL, Mexico',
      'array_cursos_usuario' => array(
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        )
      ),
      'calc_numero_cursos' => 20,
      'field_usuario_numero_seguidores' => 100,
      'field_usuario_roles' => array(
        array(
          'rol1' => 1,
          'rol2' => 2,
          'rol3' => 3,
        )
      ),
      'link_usuario' => 'usuario1',
    )
  );  
  $totalResultados = sizeof($arrResultados);
        
  $indiceDevueltos = 1;
  
  $arrRegresar = array();
  $arrTemporal = array();
  
  foreach($arrResultados as $item){ 

      if ($indiceDevueltos >= $limite_inicial && $indiceDevueltos <= $limite_final)
      {
          array_push($arrTemporal, $item);
      }

      $indiceDevueltos++;
  } 
  
  array_push($arrRegresar,array(
    'totalResultados' => $totalResultados,
    'items' => $arrTemporal
  ));
  
  return $arrRegresar;  
}

/*Busqueda - Usuarios*/
function consultar_busqueda_generales_usuarios_db($string_busqueda, $limite_inicial, $limite_final){
  $arrResultados = array();
  array_push($arrResultados,
    array(
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_usuario_nombre' => 'Usuario 1',
      'field_usuario_verificado' => TRUE,
      'field_usuario_numero_seguidores' => 129,
      'array_usuarios_cursos' => array(
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        )
      ),
      'calc_numero_cursos' => 159,
      'field_usuario_roles' => array(
        array(
          'rol1' => 1,
          'rol2' => 2,
          'rol3' => 3,
          'rol4' => 4,
        )
      ),
      'link_usuario' => 'usuario1',
      'username' => 'el_jeringas_1',
      'uid' => 1,
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_usuario_nombre' => 'Usuario 2',
      'field_usuario_verificado' => TRUE,
      'field_usuario_numero_seguidores' => 129,
      'array_usuarios_cursos' => array(
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        )
      ),
      'calc_numero_cursos' => 159,
      'field_usuario_roles' => array(
        array(
          'rol1' => 1,
          'rol2' => 2,
          'rol3' => 3,
          'rol4' => 4,
        )
      ),
      'link_usuario' => 'usuario1',
      'username' => 'el_jeringas_2',
      'uid' => 2,
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_usuario_nombre' => 'Usuario 3',
      'field_usuario_verificado' => TRUE,
      'field_usuario_numero_seguidores' => 129,
      'array_usuarios_cursos' => array(
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        )
      ),
      'calc_numero_cursos' => 159,
      'field_usuario_roles' => array(
        array(
          'rol1' => 1,
          'rol2' => 2,
          'rol3' => 3,
          'rol4' => 4,
        )
      ),
      'link_usuario' => 'usuario1',
      'username' => 'el_jeringas_3',
      'uid' => 3,
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_usuario_nombre' => 'Usuario 4',
      'field_usuario_verificado' => TRUE,
      'field_usuario_numero_seguidores' => 129,
      'array_usuarios_cursos' => array(
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        )
      ),
      'calc_numero_cursos' => 159,
      'field_usuario_roles' => array(
        array(
          'rol1' => 1,
          'rol2' => 2,
          'rol3' => 3,
          'rol4' => 4,
        )
      ),
      'link_usuario' => 'usuario1',
      'username' => 'el_jeringas_3',
      'uid' => 1,
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_usuario_nombre' => 'Usuario 5',
      'field_usuario_verificado' => TRUE,
      'field_usuario_numero_seguidores' => 129,
      'array_usuarios_cursos' => array(
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        )
      ),
      'calc_numero_cursos' => 159,
      'field_usuario_roles' => array(
        array(
          'rol1' => 1,
          'rol2' => 2,
          'rol3' => 3,
          'rol4' => 4,
        )
      ),
      'link_usuario' => 'usuario1',
      'username' => 'el_jeringas_3',
      'uid' => 1,
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_usuario_nombre' => 'Usuario 6',
      'field_usuario_verificado' => TRUE,
      'field_usuario_numero_seguidores' => 129,
      'array_usuarios_cursos' => array(
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        )
      ),
      'calc_numero_cursos' => 159,
      'field_usuario_roles' => array(
        array(
          'rol1' => 1,
          'rol2' => 2,
          'rol3' => 3,
          'rol4' => 4,
        )
      ),
      'link_usuario' => 'usuario1',
      'username' => 'el_jeringas_3',
      'uid' => 1,
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_usuario_nombre' => 'Usuario 7',
      'field_usuario_verificado' => TRUE,
      'field_usuario_numero_seguidores' => 129,
      'array_usuarios_cursos' => array(
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        )
      ),
      'calc_numero_cursos' => 159,
      'field_usuario_roles' => array(
        array(
          'rol1' => 1,
          'rol2' => 2,
          'rol3' => 3,
          'rol4' => 4,
        )
      ),
      'link_usuario' => 'usuario1',
      'username' => 'el_jeringas_3',
      'uid' => 1,
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_usuario_nombre' => 'Usuario 8',
      'field_usuario_verificado' => TRUE,
      'field_usuario_numero_seguidores' => 129,
      'array_usuarios_cursos' => array(
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        )
      ),
      'calc_numero_cursos' => 159,
      'field_usuario_roles' => array(
        array(
          'rol1' => 1,
          'rol2' => 2,
          'rol3' => 3,
          'rol4' => 4,
        )
      ),
      'link_usuario' => 'usuario1',
      'username' => 'el_jeringas_3',
      'uid' => 1,
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_usuario_nombre' => 'Usuario 9',
      'field_usuario_verificado' => TRUE,
      'field_usuario_numero_seguidores' => 129,
      'array_usuarios_cursos' => array(
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        )
      ),
      'calc_numero_cursos' => 159,
      'field_usuario_roles' => array(
        array(
          'rol1' => 1,
          'rol2' => 2,
          'rol3' => 3,
          'rol4' => 4,
        )
      ),
      'link_usuario' => 'usuario1',
      'username' => 'el_jeringas_3',
      'uid' => 1,
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_usuario_nombre' => 'Usuario 10',
      'field_usuario_verificado' => TRUE,
      'field_usuario_numero_seguidores' => 129,
      'array_usuarios_cursos' => array(
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        )
      ),
      'calc_numero_cursos' => 159,
      'field_usuario_roles' => array(
        array(
          'rol1' => 1,
          'rol2' => 2,
          'rol3' => 3,
          'rol4' => 4,
        )
      ),
      'link_usuario' => 'usuario1',
      'username' => 'el_jeringas_3',
      'uid' => 1,
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/100x50',
      'calc_usuario_nombre' => 'Usuario 11',
      'field_usuario_verificado' => TRUE,
      'field_usuario_numero_seguidores' => 129,
      'array_usuarios_cursos' => array(
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        ),
        array(
          'field_curso_nombre' => 'curso1',
          'field_curso_imagen' => 'http://placehold.it/100x50',
          'link_usuario_curso' => 'usuario1',
        )
      ),
      'calc_numero_cursos' => 159,
      'field_usuario_roles' => array(
        array(
          'rol1' => 1,
          'rol2' => 2,
          'rol3' => 3,
          'rol4' => 4,
        )
      ),
      'link_usuario' => 'usuario1',
      'username' => 'el_jeringas_3',
      'uid' => 1,
    )
  );  
  $totalResultados = sizeof($arrResultados);
        
  $indiceDevueltos = 1;
  
  $arrRegresar = array();
  $arrTemporal = array();
  
  foreach($arrResultados as $item){ 

      if ($indiceDevueltos >= $limite_inicial && $indiceDevueltos <= $limite_final)
      {
          array_push($arrTemporal, $item);
      }

      $indiceDevueltos++;
  } 
  
  array_push($arrRegresar,array(
    'totalResultados' => $totalResultados,
    'items' => $arrTemporal
  ));
  
  return $arrRegresar;  
}

/*Busqueda - Canales*/
function consultar_busqueda_generales_canales_db($string_busqueda, $limite_inicial, $limite_final){
  $arrResultados = array();
  array_push($arrResultados,
    array(
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Canal Matematicas 1',
      'calc_creador_nombre' => 'Rene Camacho',
      'link_canal_creador' => 'usuario1',
      'field_usuario_verificado' => TRUE,
      'field_canal_categoria' => 'Ciencias',
      'link_canal_categoria' => 'categoria1',
      'link_canal' => 'canal1',
      'calc_numero_cursos' => 100,
    ),
    array(
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Canal Matematicas 2',
      'calc_creador_nombre' => 'Rene Camacho',
      'link_canal_creador' => 'usuario1',
      'field_usuario_verificado' => TRUE,
      'field_canal_categoria' => 'Ciencias',
      'link_canal_categoria' => 'categoria1',
      'link_canal' => 'canal1',
      'calc_numero_cursos' => 100,
    ),
    array(
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Canal Matematicas 3',
      'calc_creador_nombre' => 'Rene Camacho',
      'link_canal_creador' => 'usuario1',
      'field_usuario_verificado' => TRUE,
      'field_canal_categoria' => 'Ciencias',
      'link_canal_categoria' => 'categoria1',
      'link_canal' => 'canal1',
      'calc_numero_cursos' => 100,
    ),
    array(
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Canal Matematicas 1',
      'calc_creador_nombre' => 'Rene Camacho',
      'link_canal_creador' => 'usuario1',
      'field_usuario_verificado' => TRUE,
      'field_canal_categoria' => 'Ciencias',
      'link_canal_categoria' => 'categoria1',
      'link_canal' => 'canal1',
      'calc_numero_cursos' => 100,
    ),
    array(
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Canal Matematicas 1',
      'calc_creador_nombre' => 'Rene Camacho',
      'link_canal_creador' => 'usuario1',
      'field_usuario_verificado' => TRUE,
      'field_canal_categoria' => 'Ciencias',
      'link_canal_categoria' => 'categoria1',
      'link_canal' => 'canal1',
      'calc_numero_cursos' => 100,
    ),
    array(
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Canal Matematicas 1',
      'calc_creador_nombre' => 'Rene Camacho',
      'link_canal_creador' => 'usuario1',
      'field_usuario_verificado' => TRUE,
      'field_canal_categoria' => 'Ciencias',
      'link_canal_categoria' => 'categoria1',
      'link_canal' => 'canal1',
      'calc_numero_cursos' => 100,
    ),
    array(
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Canal Matematicas 1',
      'calc_creador_nombre' => 'Rene Camacho',
      'link_canal_creador' => 'usuario1',
      'field_usuario_verificado' => TRUE,
      'field_canal_categoria' => 'Ciencias',
      'link_canal_categoria' => 'categoria1',
      'link_canal' => 'canal1',
      'calc_numero_cursos' => 100,
    ),
    array(
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Canal Matematicas 1',
      'calc_creador_nombre' => 'Rene Camacho',
      'link_canal_creador' => 'usuario1',
      'field_usuario_verificado' => TRUE,
      'field_canal_categoria' => 'Ciencias',
      'link_canal_categoria' => 'categoria1',
      'link_canal' => 'canal1',
      'calc_numero_cursos' => 100,
    ),
    array(
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Canal Matematicas 1',
      'calc_creador_nombre' => 'Rene Camacho',
      'link_canal_creador' => 'usuario1',
      'field_usuario_verificado' => TRUE,
      'field_canal_categoria' => 'Ciencias',
      'link_canal_categoria' => 'categoria1',
      'link_canal' => 'canal1',
      'calc_numero_cursos' => 100,
    ),
    array(
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Canal Matematicas 1',
      'calc_creador_nombre' => 'Rene Camacho',
      'link_canal_creador' => 'usuario1',
      'field_usuario_verificado' => TRUE,
      'field_canal_categoria' => 'Ciencias',
      'link_canal_categoria' => 'categoria1',
      'link_canal' => 'canal1',
      'calc_numero_cursos' => 100,
    ),
    array(
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Canal Matematicas 1',
      'calc_creador_nombre' => 'Rene Camacho',
      'link_canal_creador' => 'usuario1',
      'field_usuario_verificado' => TRUE,
      'field_canal_categoria' => 'Ciencias',
      'link_canal_categoria' => 'categoria1',
      'link_canal' => 'canal1',
      'calc_numero_cursos' => 100,
    )
  );  
  $totalResultados = sizeof($arrResultados);
        
  $indiceDevueltos = 1;
  
  $arrRegresar = array();
  $arrTemporal = array();
  
  foreach($arrResultados as $item){ 

      if ($indiceDevueltos >= $limite_inicial && $indiceDevueltos <= $limite_final)
      {
          array_push($arrTemporal, $item);
      }

      $indiceDevueltos++;
  } 
  
  array_push($arrRegresar,array(
    'totalResultados' => $totalResultados,
    'items' => $arrTemporal
  ));
  
  return $arrRegresar;    
}

/*Busqueda - Grupos*/
function consultar_busqueda_generales_grupos_db($string_busqueda, $limite_inicial, $limite_final){
  $arrResultados = array();
  array_push($arrResultados,
    array(
      'titulo' => 'Grupo 1',
      'imagen' => 'http://placehold.it/100x50',
      'datoPrincipal' => '',
      'datoAdicional' => '',
      'comportamientoBoton' => '',
      'valor2' => '',
      'verificacion' => '',      
    ),
    array(
      'titulo' => 'Grupo 2',
      'imagen' => 'http://placehold.it/100x50',
      'datoPrincipal' => '',
      'datoAdicional' => '',
      'comportamientoBoton' => '',
      'valor2' => '',
      'verificacion' => '',      
    ),
    array(
      'titulo' => 'Grupo 3',
      'imagen' => 'http://placehold.it/100x50',
      'datoPrincipal' => '',
      'datoAdicional' => '',
      'comportamientoBoton' => '',
      'valor2' => '',
      'verificacion' => '',      
    ),
    array(
      'titulo' => 'Grupo 4',
      'imagen' => 'http://placehold.it/100x50',
      'datoPrincipal' => '',
      'datoAdicional' => '',
      'comportamientoBoton' => '',
      'valor2' => '',
      'verificacion' => '',      
    ),
    array(
      'titulo' => 'Grupo 5',
      'imagen' => 'http://placehold.it/100x50',
      'datoPrincipal' => '',
      'datoAdicional' => '',
      'comportamientoBoton' => '',
      'valor2' => '',
      'verificacion' => '',      
    ),
    array(
      'titulo' => 'Grupo 6',
      'imagen' => 'http://placehold.it/100x50',
      'datoPrincipal' => '',
      'datoAdicional' => '',
      'comportamientoBoton' => '',
      'valor2' => '',
      'verificacion' => '',      
    ),
    array(
      'titulo' => 'Grupo 7',
      'imagen' => 'http://placehold.it/100x50',
      'datoPrincipal' => '',
      'datoAdicional' => '',
      'comportamientoBoton' => '',
      'valor2' => '',
      'verificacion' => '',      
    ),
    array(
      'titulo' => 'Grupo 8',
      'imagen' => 'http://placehold.it/100x50',
      'datoPrincipal' => '',
      'datoAdicional' => '',
      'comportamientoBoton' => '',
      'valor2' => '',
      'verificacion' => '',      
    ),
    array(
      'titulo' => 'Grupo 9',
      'imagen' => 'http://placehold.it/100x50',
      'datoPrincipal' => '',
      'datoAdicional' => '',
      'comportamientoBoton' => '',
      'valor2' => '',
      'verificacion' => '',      
    ),
    array(
      'titulo' => 'Grupo 10',
      'imagen' => 'http://placehold.it/100x50',
      'datoPrincipal' => '',
      'datoAdicional' => '',
      'comportamientoBoton' => '',
      'valor2' => '',
      'verificacion' => '',      
    ),
    array(
      'titulo' => 'Grupo 11',
      'imagen' => 'http://placehold.it/100x50',
      'datoPrincipal' => '',
      'datoAdicional' => '',
      'comportamientoBoton' => '',
      'valor2' => '',
      'verificacion' => '',      
    )
  );  
  $totalResultados = sizeof($arrResultados);
        
  $indiceDevueltos = 1;
  
  $arrRegresar = array();
  $arrTemporal = array();
  
  foreach($arrResultados as $item){ 

      if ($indiceDevueltos >= $limite_inicial && $indiceDevueltos <= $limite_final)
      {
          array_push($arrTemporal, $item);
      }

      $indiceDevueltos++;
  } 
  
  array_push($arrRegresar,array(
    'totalResultados' => $totalResultados,
    'items' => $arrTemporal
  ));
  
  return $arrRegresar;  
}
