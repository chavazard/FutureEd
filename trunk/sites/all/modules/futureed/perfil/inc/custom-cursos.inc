<?php

/*------------------------------------------- Consultar Cursos -------------------------------------------*/

/************************************** Cursos Comprados **************************************/

function consultar_cursos_comprados_actuales_db($uid, $limite_inicial, $limite_final){
  $arrResultados = array();
  array_push($arrResultados,
    array(
      'nid' => 1,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 1',
      'link_curso' => 'curso1',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal1',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario1',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso1',
      'field_fundacion_imagen' => 'http://placehold.it/100x100',
      'field_fundacion_nombre' => 'Instituto amanecer',
    ),
    array(
      'nid' => 2,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 2',
      'link_curso' => 'curso2',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal2',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario2',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso2',
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
    ),
    array(
      'nid' => 3,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 3',
      'link_curso' => 'curso3',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal3',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario3',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso3',
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
    ),
    array(
      'nid' => 4,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 4',
      'link_curso' => 'curso4',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal4',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario4',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso4',
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
    ),
    array(
      'nid' => 5,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 5',
      'link_curso' => 'curso5',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal5',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario5',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso5',
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
    ),
    array(
      'nid' => 6,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 6',
      'link_curso' => 'curso6',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal6',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario6',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso6',
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
    ),
    array(
      'nid' => 7,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 7',
      'link_curso' => 'curso7',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal7',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario7',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso7',
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
    ),
    array(
      'nid' => 8,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 8',
      'link_curso' => 'curso8',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal8',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario8',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso8',
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
    ),
    array(
      'nid' => 9,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 9',
      'link_curso' => 'curso9',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal9',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario9',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso9',
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
    ),
    array(
      'nid' => 10,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 10',
      'link_curso' => 'curso10',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal10',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario10',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso10',
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
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

function consultar_cursos_comprados_pasados_db($uid, $limite_inicial, $limite_final){
  $arrResultados = array();
  array_push($arrResultados,
    array(
      'nid' => 1,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 1',
      'link_curso' => 'curso1',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal1',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario1',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso1',
      'field_curso_calificacion' => 3.5,
      'field_curso_numero_votos' => 28,
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
    ),
    array(
      'nid' => 2,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 2',
      'link_curso' => 'curso2',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal2',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario2',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso2',
      'field_curso_calificacion' => NULL,
      'field_curso_numero_votos' => 28,
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
    ),
    array(
      'nid' => 3,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 3',
      'link_curso' => 'curso3',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal3',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario3',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso3',
      'field_curso_calificacion' => 3.5,
      'field_curso_numero_votos' => 28,
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
    ),
    array(
      'nid' => 4,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 4',
      'link_curso' => 'curso4',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal4',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario4',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso4',
      'field_curso_calificacion' => NULL,
      'field_curso_numero_votos' => 28,
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
    ),
    array(
      'nid' => 5,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 5',
      'link_curso' => 'curso5',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal5',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario5',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso5',
      'field_curso_calificacion' => 3.5,
      'field_curso_numero_votos' => 28,
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
    ),
    array(
      'nid' => 6,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 6',
      'link_curso' => 'curso6',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal6',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario6',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso6',
      'field_curso_calificacion' => 3.5,
      'field_curso_numero_votos' => 28,
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
    ),
    array(
      'nid' => 7,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 7',
      'link_curso' => 'curso7',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal7',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario7',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso7',
      'field_curso_calificacion' => 3.5,
      'field_curso_numero_votos' => 28,
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
    ),
    array(
      'nid' => 8,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 8',
      'link_curso' => 'curso8',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal8',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario8',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso8',
      'field_curso_calificacion' => 3.5,
      'field_curso_numero_votos' => 28,
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
    ),
    array(
      'nid' => 9,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 9',
      'link_curso' => 'curso9',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal9',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario9',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso9',
      'field_curso_calificacion' => 3.5,
      'field_curso_numero_votos' => 28,
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
    ),
    array(
      'nid' => 10,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 10',
      'link_curso' => 'curso10',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal10',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario10',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso10',
      'field_curso_calificacion' => 3.5,
      'field_curso_numero_votos' => 28,
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
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

function consultar_cursos_comprados_tomar_db($uid, $limite_inicial, $limite_final){
  $arrResultados = array();
  array_push($arrResultados,
    array(
      'nid' => 1,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 1',
      'link_curso' => 'curso1',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal1',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario1',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso1',
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
    ),
    array(
      'nid' => 2,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 2',
      'link_curso' => 'curso2',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal2',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario2',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso2',
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
    ),
    array(
      'nid' => 3,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 3',
      'link_curso' => 'curso3',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal3',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario3',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso3',
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
    ),
    array(
      'nid' => 4,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 4',
      'link_curso' => 'curso4',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal4',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario4',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso4',
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
    ),
    array(
      'nid' => 5,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 5',
      'link_curso' => 'curso5',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal5',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario5',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso5',
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
    ),
    array(
      'nid' => 6,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 6',
      'link_curso' => 'curso6',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal6',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario6',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso6',
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
    ),
    array(
      'nid' => 7,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 7',
      'link_curso' => 'curso7',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal7',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario7',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso7',
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
    ),
    array(
      'nid' => 8,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 8',
      'link_curso' => 'curso8',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal8',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario8',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso8',
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
    ),
    array(
      'nid' => 9,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 9',
      'link_curso' => 'curso9',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal9',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario9',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso9',
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
    ),
    array(
      'nid' => 10,
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 10',
      'link_curso' => 'curso10',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal10',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario10',
        )
      ),
      'field_curso_modalidad' => 'En linea',
      'field_curso_fecha' => '01/01/2015',
      'field_curso_fecha_value2' => '01/01/2015',
      'field_curso_url_lms' => 'curso10',
      'field_fundacion_imagen' => 'http://placehold.it/20x20',
      'field_fundacion_nombre' => 'Instituto nuevo Amanecer',
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

/************************************** Cursos Creados **************************************/

function consultar_cursos_creados_todos_db($uid, $limite_inicial, $limite_final){
  $arrResultados = array();
  array_push($arrResultados,
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 1',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'Autorizado',     
      'field_curso_fechas_imparticion' => 'cerrado',
      'field_curso_fecha' => '01/01/15',
      'field_curso_caducidad' => FALSE,
      'calc_numero_alumnos' => '20 alumnos',
      'field_curso_publicacion' => 'Publicado',
      'nid' => 1,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 2',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'En proceso',     
      'field_curso_fechas_imparticion' => 'abierto',
      'field_curso_fecha' => FALSE,
      'field_curso_caducidad' => '3 meses',
      'calc_numero_alumnos' => FALSE,  
      'field_curso_publicacion' => FALSE,
      'nid' => 2,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 3',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'No autorizado',  
      'field_curso_fechas_imparticion' => 'abierto',
      'field_curso_fecha' => FALSE,
      'field_curso_caducidad' => '3 meses',
      'calc_numero_alumnos' => FALSE,
      'field_curso_publicacion' => FALSE,
      'nid' => 3,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 4',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'Autorizado', 
      'field_curso_fechas_imparticion' => 'cerrado',
      'field_curso_fecha' => '01/01/15',
      'field_curso_caducidad' => FALSE,
      'calc_numero_alumnos' => '20 alumnos',
      'field_curso_publicacion' => 'Sin Publicar',
      'nid' => 4,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 5',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'Autorizado',
      'field_curso_fechas_imparticion' => 'cerrado',
      'field_curso_fecha' => '01/01/15',
      'field_curso_caducidad' => FALSE,
      'calc_numero_alumnos' => '20 alumnos',
      'field_curso_publicacion' => 'Sin Publicar',
      'nid' => 5,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 5',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'Autorizado',    
      'field_curso_fechas_imparticion' => 'cerrado',
      'field_curso_fecha' => '01/01/15',
      'field_curso_caducidad' => FALSE,
      'calc_numero_alumnos' => '20 alumnos',
      'field_curso_publicacion' => 'Sin Publicar',
      'nid' => 6,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 5',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'Autorizado',    
      'field_curso_fechas_imparticion' => 'cerrado',
      'field_curso_fecha' => '01/01/15',
      'field_curso_caducidad' => FALSE,
      'calc_numero_alumnos' => '20 alumnos',
      'field_curso_publicacion' => 'Sin Publicar',
      'nid' => 7,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 5',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'Autorizado',   
      'field_curso_fechas_imparticion' => 'cerrado',
      'field_curso_fecha' => '01/01/15',
      'field_curso_caducidad' => FALSE,
      'calc_numero_alumnos' => '20 alumnos',
      'field_curso_publicacion' => 'Sin Publicar',
      'nid' => 8,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 5',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'Autorizado',   
      'field_curso_fechas_imparticion' => 'cerrado',
      'field_curso_fecha' => '01/01/15',
      'field_curso_caducidad' => FALSE,
      'calc_numero_alumnos' => '20 alumnos',
      'field_curso_publicacion' => 'Sin Publicar',
      'nid' => 9,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 5',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'Autorizado',   
      'field_curso_fechas_imparticion' => 'cerrado',
      'field_curso_fecha' => '01/01/15',
      'field_curso_caducidad' => FALSE,
      'calc_numero_alumnos' => '20 alumnos',
      'field_curso_publicacion' => 'Sin Publicar',
      'nid' => 10,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 5',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'Autorizado',   
      'field_curso_fechas_imparticion' => 'cerrado',
      'field_curso_fecha' => '01/01/15',
      'field_curso_caducidad' => FALSE,
      'calc_numero_alumnos' => '20 alumnos',
      'field_curso_publicacion' => 'Sin Publicar',
      'nid' => 11,
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

function consultar_cursos_creados_actuales_db($uid, $limite_inicial, $limite_final){
  $arrResultados = array();
  array_push($arrResultados,
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 1',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'Autorizado',     
      'field_curso_fechas_imparticion' => 'cerrado',
      'field_curso_fecha' => '01/01/15',
      'field_curso_caducidad' => FALSE,
      'calc_numero_alumnos' => '20 alumnos',
      'field_curso_publicacion' => 'Publicado',
      'nid' => 1,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 2',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'En proceso',     
      'field_curso_fechas_imparticion' => 'abierto',
      'field_curso_fecha' => FALSE,
      'field_curso_caducidad' => '3 meses',
      'calc_numero_alumnos' => FALSE,  
      'field_curso_publicacion' => FALSE,
      'nid' => 2,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 3',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'No autorizado',  
      'field_curso_fechas_imparticion' => 'abierto',
      'field_curso_fecha' => FALSE,
      'field_curso_caducidad' => '3 meses',
      'calc_numero_alumnos' => FALSE,
      'field_curso_publicacion' => FALSE,
      'nid' => 3,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 4',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'Autorizado', 
      'field_curso_fechas_imparticion' => 'cerrado',
      'field_curso_fecha' => '01/01/15',
      'field_curso_caducidad' => FALSE,
      'calc_numero_alumnos' => '20 alumnos',
      'field_curso_publicacion' => 'Sin Publicar',
      'nid' => 4,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 5',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'Autorizado',
      'field_curso_fechas_imparticion' => 'cerrado',
      'field_curso_fecha' => '01/01/15',
      'field_curso_caducidad' => FALSE,
      'calc_numero_alumnos' => '20 alumnos',
      'field_curso_publicacion' => 'Sin Publicar',
      'nid' => 5,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 5',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'Autorizado',    
      'field_curso_fechas_imparticion' => 'cerrado',
      'field_curso_fecha' => '01/01/15',
      'field_curso_caducidad' => FALSE,
      'calc_numero_alumnos' => '20 alumnos',
      'field_curso_publicacion' => 'Sin Publicar',
      'nid' => 6,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 5',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'Autorizado',    
      'field_curso_fechas_imparticion' => 'cerrado',
      'field_curso_fecha' => '01/01/15',
      'field_curso_caducidad' => FALSE,
      'calc_numero_alumnos' => '20 alumnos',
      'field_curso_publicacion' => 'Sin Publicar',
      'nid' => 7,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 5',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'Autorizado',   
      'field_curso_fechas_imparticion' => 'cerrado',
      'field_curso_fecha' => '01/01/15',
      'field_curso_caducidad' => FALSE,
      'calc_numero_alumnos' => '20 alumnos',
      'field_curso_publicacion' => 'Sin Publicar',
      'nid' => 8,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 5',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'Autorizado',   
      'field_curso_fechas_imparticion' => 'cerrado',
      'field_curso_fecha' => '01/01/15',
      'field_curso_caducidad' => FALSE,
      'calc_numero_alumnos' => '20 alumnos',
      'field_curso_publicacion' => 'Sin Publicar',
      'nid' => 9,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 5',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'Autorizado',   
      'field_curso_fechas_imparticion' => 'cerrado',
      'field_curso_fecha' => '01/01/15',
      'field_curso_caducidad' => FALSE,
      'calc_numero_alumnos' => '20 alumnos',
      'field_curso_publicacion' => 'Sin Publicar',
      'nid' => 10,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 5',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'Autorizado',   
      'field_curso_fechas_imparticion' => 'cerrado',
      'field_curso_fecha' => '01/01/15',
      'field_curso_caducidad' => FALSE,
      'calc_numero_alumnos' => '20 alumnos',
      'field_curso_publicacion' => 'Sin Publicar',
      'nid' => 11,
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

function consultar_cursos_creados_pasados_db($uid, $limite_inicial, $limite_final){
  $arrResultados = array();
  array_push($arrResultados,
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 1',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'Autorizado',     
      'field_curso_fechas_imparticion' => 'cerrado',
      'field_curso_fecha' => '01/01/15',
      'field_curso_caducidad' => FALSE,
      'calc_numero_alumnos' => '20 alumnos',
      'field_curso_publicacion' => 'Publicado',
      'nid' => 1,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 2',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'En proceso',     
      'field_curso_fechas_imparticion' => 'abierto',
      'field_curso_fecha' => FALSE,
      'field_curso_caducidad' => '3 meses',
      'calc_numero_alumnos' => FALSE,  
      'field_curso_publicacion' => FALSE,
      'nid' => 2,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 3',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'No autorizado',  
      'field_curso_fechas_imparticion' => 'abierto',
      'field_curso_fecha' => FALSE,
      'field_curso_caducidad' => '3 meses',
      'calc_numero_alumnos' => FALSE,
      'field_curso_publicacion' => FALSE,
      'nid' => 3,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 4',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'Autorizado', 
      'field_curso_fechas_imparticion' => 'cerrado',
      'field_curso_fecha' => '01/01/15',
      'field_curso_caducidad' => FALSE,
      'calc_numero_alumnos' => '20 alumnos',
      'field_curso_publicacion' => 'Sin Publicar',
      'nid' => 4,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 5',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'Autorizado',
      'field_curso_fechas_imparticion' => 'cerrado',
      'field_curso_fecha' => '01/01/15',
      'field_curso_caducidad' => FALSE,
      'calc_numero_alumnos' => '20 alumnos',
      'field_curso_publicacion' => 'Sin Publicar',
      'nid' => 5,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 5',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'Autorizado',    
      'field_curso_fechas_imparticion' => 'cerrado',
      'field_curso_fecha' => '01/01/15',
      'field_curso_caducidad' => FALSE,
      'calc_numero_alumnos' => '20 alumnos',
      'field_curso_publicacion' => 'Sin Publicar',
      'nid' => 6,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 5',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'Autorizado',    
      'field_curso_fechas_imparticion' => 'cerrado',
      'field_curso_fecha' => '01/01/15',
      'field_curso_caducidad' => FALSE,
      'calc_numero_alumnos' => '20 alumnos',
      'field_curso_publicacion' => 'Sin Publicar',
      'nid' => 7,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 5',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'Autorizado',   
      'field_curso_fechas_imparticion' => 'cerrado',
      'field_curso_fecha' => '01/01/15',
      'field_curso_caducidad' => FALSE,
      'calc_numero_alumnos' => '20 alumnos',
      'field_curso_publicacion' => 'Sin Publicar',
      'nid' => 8,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 5',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'Autorizado',   
      'field_curso_fechas_imparticion' => 'cerrado',
      'field_curso_fecha' => '01/01/15',
      'field_curso_caducidad' => FALSE,
      'calc_numero_alumnos' => '20 alumnos',
      'field_curso_publicacion' => 'Sin Publicar',
      'nid' => 9,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 5',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'Autorizado',   
      'field_curso_fechas_imparticion' => 'cerrado',
      'field_curso_fecha' => '01/01/15',
      'field_curso_caducidad' => FALSE,
      'calc_numero_alumnos' => '20 alumnos',
      'field_curso_publicacion' => 'Sin Publicar',
      'nid' => 10,
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/300x150',
      'field_curso_nombre' => 'Matematicas 5',
      'field_curso_canal' => 'Negocios',
      'link_curso_canal' => 'canal1',
      'field_curso_estatus' => 'Autorizado',   
      'field_curso_fechas_imparticion' => 'cerrado',
      'field_curso_fecha' => '01/01/15',
      'field_curso_caducidad' => FALSE,
      'calc_numero_alumnos' => '20 alumnos',
      'field_curso_publicacion' => 'Sin Publicar',
      'nid' => 11,
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

































/************************************************************************/
/*Consultar cursos a calificar*/
function consultar_cursos_comprados_pasados_calificar_db($nid){
  var_dump($nid);
  $arrResultados = array();
  array_push($arrResultados,
    array(
      'nid' => 1,
      'field_curso_imagen' => 'http://placehold.it/200x100',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 1',
      'link_curso' => 'curso1',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal1',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario1',
        )
      ),
    ),
    array(
      'nid' => 2,
      'field_curso_imagen' => 'http://placehold.it/200x100',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 2',
      'link_curso' => 'curso2',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal2',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario1',
        )
      ),
    ),
    array(
      'nid' => 3,
      'field_curso_imagen' => 'http://placehold.it/200x100',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 3',
      'link_curso' => 'curso3',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal3',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario1',
        )
      ),
    ),
    array(
      'nid' => 4,
      'field_curso_imagen' => 'http://placehold.it/200x100',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 4',
      'link_curso' => 'curso4',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal4',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario1',
        )
      ),
    ),
    array(
      'nid' => 5,
      'field_curso_imagen' => 'http://placehold.it/200x100',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 5',
      'link_curso' => 'curso5',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal5',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario1',
        )
      ),
    ),
    array(
      'nid' => 6,
      'field_curso_imagen' => 'http://placehold.it/200x100',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 6',
      'link_curso' => 'curso6',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal6',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario1',
        )
      ),
    ),
    array(
      'nid' => 7,
      'field_curso_imagen' => 'http://placehold.it/200x100',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 7',
      'link_curso' => 'curso7',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal7',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario1',
        )
      ),
    ),
    array(
      'nid' => 8,
      'field_curso_imagen' => 'http://placehold.it/200x100',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 8',
      'link_curso' => 'curso8',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal8',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario1',
        )
      ),
    ),
    array(
      'nid' => 9,
      'field_curso_imagen' => 'http://placehold.it/200x100',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 9',
      'link_curso' => 'curso9',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal9',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario1',
        )
      ),
    ),
    array(
      'nid' => 10,
      'field_curso_imagen' => 'http://placehold.it/200x100',
      'field_curso_nombre' => 'Dibujemos nuestro futuro 10',
      'link_curso' => 'curso10',
      'field_curso_canal' => 'CEDIM',
      'link_curso_canal' => 'canal10',
      'array_curso_tutores' => array(
        array(
          'calc_nombre_tutor' => 'Eduardo Salas',
          'link_nombre_tutor' => 'usuario1',
        )
      ),
    )
  );  
  return $arrResultados;   
}