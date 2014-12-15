<?php

/*----------------------- Consultar Cursos Sugeridos -----------------------*/

function consultar_item_cursos_sugeridos_db($nid_curso, $limite_inicial, $limite_final){
  $arrResultados = array();
  array_push($arrResultados,
    array(
      'field_curso_imagen' => 'http://placehold.it/150x150',
      'calc_curso_nombre' => 'Curso 1',
      'calc_curso_creador' => 'ITESM, Monterrey',
      'link_curso_creador' => 'usuario1',
      'field_curso_precio' => '1,500.00',
      'field_curso_calificacion' => '4 estrellas',
      'field_curso_likes' => '28',
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/150x150',
      'calc_curso_nombre' => 'Curso 2',
      'calc_curso_creador' => 'ITESM, Monterrey',
      'link_curso_creador' => 'usuario1',
      'field_curso_precio' => '1,500.00',
      'field_curso_calificacion' => '4 estrellas',
      'field_curso_likes' => '28',
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/150x150',
      'calc_curso_nombre' => 'Curso 3',
      'calc_curso_creador' => 'ITESM, Monterrey',
      'link_curso_creador' => 'usuario1',
      'field_curso_precio' => '1,500.00',
      'field_curso_calificacion' => '4 estrellas',
      'field_curso_likes' => '28',
    ),
    array(
      'field_curso_imagen' => 'http://placehold.it/150x150',
      'calc_curso_nombre' => 'Curso 4',
      'calc_curso_creador' => 'ITESM, Monterrey',
      'link_curso_creador' => 'usuario1',
      'field_curso_precio' => '1,500.00',
      'field_curso_calificacion' => '4 estrellas',
      'field_curso_likes' => '28',
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