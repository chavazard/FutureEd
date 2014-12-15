<?php

/*----------------------- Carrusel - Empresas -----------------------*/
function consultar_carrusel_empresas($uid){
  $arrResultados = array();

  array_push($arrResultados,
    array(
      array(
        'field_empresa_imagen' => 'http://placehold.it/100x100',
        'field_empresa_nombre' => 'Empresa1',
        'field_empresa_certificado' => 1,
        'link_empresa' => 'empresa/empresa1',
        'field_empresa_ubicacion' => 'Monterrey, NL, Mexico',
        'field_empresa_seguidores' => '10k',
        'field_empresa_canales' => '6',
        'link_canales' => 'canal/canal1',
        'field_empresa_canales_populares' => array(
          'canal_popular1' => 'http://placehold.it/10x10',
          'canal_popular2' => 'http://placehold.it/10x10',
          'canal_popular3' => 'http://placehold.it/10x10',
          'canal_popular4' => 'http://placehold.it/10x10',
        ),
        'field_empresa_cursos' => '3',
        'link_cursos' => 'curso/curso1',
        'field_empresa_calificacion' => '5 Estrellas',
        'field_empresa_likes' => '20',
      ),
      array(
        'field_empresa_imagen' => 'http://placehold.it/100x100',
        'field_empresa_nombre' => 'Empresa2',
        'field_empresa_certificado' => 1,
        'link_empresa' => 'empresa/empresa2',
        'field_empresa_ubicacion' => 'Monterrey, NL, Mexico',
        'field_empresa_seguidores' => '10k',
        'field_empresa_canales' => '6',
        'link_canales' => 'canal/canal2',
        'field_empresa_canales_populares' => array(
          'canal_popular1' => 'http://placehold.it/10x10',
          'canal_popular2' => 'http://placehold.it/10x10',
          'canal_popular3' => 'http://placehold.it/10x10',
          'canal_popular4' => 'http://placehold.it/10x10',
        ),
        'field_empresa_cursos' => '3',
        'link_cursos' => 'curso/curso1',
        'field_empresa_calificacion' => '5 Estrellas',
        'field_empresa_likes' => '20',
      ),
      array(
        'field_empresa_imagen' => 'http://placehold.it/100x100',
        'field_empresa_nombre' => 'Empresa3',
        'field_empresa_certificado' => 1,
        'link_empresa' => 'empresa/empresa3',
        'field_empresa_ubicacion' => 'Monterrey, NL, Mexico',
        'field_empresa_seguidores' => '10k',
        'field_empresa_canales' => '6',
        'link_canales' => 'canal/canal3',
        'field_empresa_canales_populares' => array(
          'canal_popular1' => 'http://placehold.it/10x10',
          'canal_popular2' => 'http://placehold.it/10x10',
          'canal_popular3' => 'http://placehold.it/10x10',
          'canal_popular4' => 'http://placehold.it/10x10',
        ),
        'field_empresa_cursos' => '3',
        'link_cursos' => 'curso/curso1',
        'field_empresa_calificacion' => '5 Estrellas',
        'field_empresa_likes' => '20',
      ),
      array(
        'field_empresa_imagen' => 'http://placehold.it/100x100',
        'field_empresa_nombre' => 'Empresa4',
        'field_empresa_certificado' => 1,
        'link_empresa' => 'empresa/empresa4',
        'field_empresa_ubicacion' => 'Monterrey, NL, Mexico',
        'field_empresa_seguidores' => '10k',
        'field_empresa_canales' => '6',
        'link_canales' => 'canal/canal4',
        'field_empresa_canales_populares' => array(
          'canal_popular1' => 'http://placehold.it/10x10',
          'canal_popular2' => 'http://placehold.it/10x10',
          'canal_popular3' => 'http://placehold.it/10x10',
          'canal_popular4' => 'http://placehold.it/10x10',
        ),
        'field_empresa_cursos' => '3',
        'link_cursos' => 'curso/curso1',
        'field_empresa_calificacion' => '5 Estrellas',
        'field_empresa_likes' => '20',
      )
    )
  );    
  return $arrResultados;      
  }