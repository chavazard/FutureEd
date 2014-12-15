<?php

/*----------------------- Carrusel - Cursos -----------------------*/
function consultar_carrusel_cursos($nid_curso){
  $arrResultados = array();

  array_push($arrResultados,
    array(
      array(
        'field_curso_imagen' => 'http://placehold.it/100x100',
        'field_curso_titulo' => 'Curso 1',
        'link_curso' => 'curso/curso1',
        'field_curso_creador' => 'Rene Camacho',
        'link_creador' => 'usuario/rene',
        'field_curso_categoria' => 'Matematicas',
        'link_categoria' => 'categoria/categoria1',
        'field_curso_calificacion' => '5 Estrellas',
        'field_curso_likes' => '25',
      ),
      array(
        'field_curso_imagen' => 'http://placehold.it/100x100',
        'field_curso_titulo' => 'Curso 2',
        'link_curso' => 'curso/curso2',
        'field_curso_creador' => 'Rene Camacho',
        'link_creador' => 'usuario/rene',
        'field_curso_categoria' => 'Matematicas',
        'link_categoria' => 'categoria/categoria2',
        'field_curso_calificacion' => '5 Estrellas',
        'field_curso_likes' => '25',
      ),
      array(
        'field_curso_imagen' => 'http://placehold.it/100x100',
        'field_curso_titulo' => 'Curso 3',
        'link_curso' => 'curso/curso3',
        'field_curso_creador' => 'Rene Camacho',
        'link_creador' => 'usuario/rene',
        'field_curso_categoria' => 'Matematicas',
        'link_categoria' => 'categoria/categoria3',
        'field_curso_calificacion' => '5 Estrellas',
        'field_curso_likes' => '25',
      ),
      array(
        'field_curso_imagen' => 'http://placehold.it/100x100',
        'field_curso_titulo' => 'Curso 4',
        'link_curso' => 'curso/curso4',
        'field_curso_creador' => 'Rene Camacho',
        'link_creador' => 'usuario/rene',
        'field_curso_categoria' => 'Matematicas',
        'link_categoria' => 'categoria/categoria4',
        'field_curso_calificacion' => '5 Estrellas',
        'field_curso_likes' => '25',
      )
    )
  );    
  return $arrResultados;      
  }