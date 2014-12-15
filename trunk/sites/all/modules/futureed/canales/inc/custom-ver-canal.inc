<?php

/*
Ver Canal - Consultar Canal Principal
*/
function consultar_canal_db($nid_canal){

  //var_dump($nid_canal);
  //$nid_canal = 6;
  $data = '?f_name=get_canal_info&nid='.$nid_canal;
  $data = get_data_from_service($data, true);

  $arrResultados = array();
  array_push($arrResultados,
    array(
      'field_canal_imagen' => $data->field_canal_imagen,
      'field_canal_nombre' => $data->field_canal_nombre,
      'calc_nombre' => $data->calc_nombre,
      'picture' => $data->picture,
      'field_canal_categoria' => $data->field_canal_categoria,
      'field_canal_subcategoria' => $data->field_canal_subcategoria,
      'descripcion' => $data->field_canal_descripcion
    )
  );  
  return $arrResultados;   
}

function consultar_canal_detalle_db($nid_canal){
  //var_dump($nid_canal);
  $data = '?f_name=get_canal_tutores&nid='.$nid_canal;
  $data = get_data_from_service($data, false);

  //TODO - Falta ajustar el codigo para cargar 'n' usuarios como se muestra en la pantalla - NOTA: ignorar y tal vez quitar pestaña de politicas
  
  $arrResultados = array();
  array_push($arrResultados,
    array(
      'nuestro_equipo' => t('Lorem Ipsum es simplemente el texto de relleno de las imprentas y archivos de texto. Lorem <br>
        Ipsum ha sido el texto de relleno estándar de las industrias desde el año 1500, cuando un impresor (N. del T. <br>
        persona que se dedica a la imprenta) desconocido usó una galería de textos y los mezcló de tal manera que logró <br> 
        hacer un libro de textos especimen. '),
      /*'politicas' => t('Lorem Ipsum es simplemente el texto de relleno de las imprentas y archivos de texto.<br>
        <br>
        Lorem Ipsum ha sido el texto de relleno estándar de las industrias desde el año 1500,<br>
        cuando un impresor (N. del T. persona que se dedica a la imprenta) desconocido usó<br>
        unagalería de textos y los mezcló de tal manera que logró hacer un libro de textos especimen.<br> 
        <br>
        No sólo sobrevivió 500 años, sino que tambien ingresó como texto de relleno en documentos<br>
        electrónicos, quedando esencialmente igual al original.<br>
        <br>
        Fue popularizado en los 60s<br>
        con la creación de las hojas "Letraset", las cuales contenian pasajes de Lorem Ipsum, y<br> 
        más recientemente con software de autoedición, como por ejemplo Aldus PageMaker, el cual<br>
        incluye versiones de Lorem Ipsum.'),*/
    )
  );  
  return $arrResultados;  

}


/*
Ver Canal - Consultar cursos
*/
function consultar_ver_canal_cursos_db($nid_curso, $limite_inicial, $limite_final){
  $data = '?f_name=get_canal_cursos&nid='.$nid_canal;
  $data = get_data_from_service($data, false);  
  
  
  $arrResultados = array();
  array_push($arrResultados,
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Matematicas II - 1','canal.com'),
      'tutor' => l('Salvador Gomez','usuario.com'),
      'creador' => l('Tecnologico de Monterrey','creador.com'),
      'fechaInicio' => '01/01/15',
      'duracion' => '4 Semanas',
      'precio' => '$1,500.00',
      'calificacion' => '5 Estrellas',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Matematicas II - 2','canal.com'),
      'tutor' => l('Salvador Gomez','usuario.com'),
      'creador' => l('Tecnologico de Monterrey','creador.com'),
      'fechaInicio' => '01/01/15',
      'duracion' => '4 Semanas',
      'precio' => '$1,500.00',
      'calificacion' => '5 Estrellas',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Matematicas II - 3','canal.com'),
      'tutor' => l('Salvador Gomez','usuario.com'),
      'creador' => l('Tecnologico de Monterrey','creador.com'),
      'fechaInicio' => '01/01/15',
      'duracion' => '4 Semanas',
      'precio' => '$1,500.00',
      'calificacion' => '5 Estrellas',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Matematicas II - 4','canal.com'),
      'tutor' => l('Salvador Gomez','usuario.com'),
      'creador' => l('Tecnologico de Monterrey','creador.com'),
      'fechaInicio' => '01/01/15',
      'duracion' => '4 Semanas',
      'precio' => '$1,500.00',
      'calificacion' => '5 Estrellas',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Matematicas II - 5','canal.com'),
      'tutor' => l('Salvador Gomez','usuario.com'),
      'creador' => l('Tecnologico de Monterrey','creador.com'),
      'fechaInicio' => '01/01/15',
      'duracion' => '4 Semanas',
      'precio' => '$1,500.00',
      'calificacion' => '5 Estrellas',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Matematicas II - 6','canal.com'),
      'tutor' => l('Salvador Gomez','usuario.com'),
      'creador' => l('Tecnologico de Monterrey','creador.com'),
      'fechaInicio' => '01/01/15',
      'duracion' => '4 Semanas',
      'precio' => '$1,500.00',
      'calificacion' => '5 Estrellas',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Matematicas II - 7','canal.com'),
      'tutor' => l('Salvador Gomez','usuario.com'),
      'creador' => l('Tecnologico de Monterrey','creador.com'),
      'fechaInicio' => '01/01/15',
      'duracion' => '4 Semanas',
      'precio' => '$1,500.00',
      'calificacion' => '5 Estrellas',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Matematicas II - 8','canal.com'),
      'tutor' => l('Salvador Gomez','usuario.com'),
      'creador' => l('Tecnologico de Monterrey','creador.com'),
      'fechaInicio' => '01/01/15',
      'duracion' => '4 Semanas',
      'precio' => '$1,500.00',
      'calificacion' => '5 Estrellas',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Matematicas II - 9','canal.com'),
      'tutor' => l('Salvador Gomez','usuario.com'),
      'creador' => l('Tecnologico de Monterrey','creador.com'),
      'fechaInicio' => '01/01/15',
      'duracion' => '4 Semanas',
      'precio' => '$1,500.00',
      'calificacion' => '5 Estrellas',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Matematicas II - 10','canal.com'),
      'tutor' => l('Salvador Gomez','usuario.com'),
      'creador' => l('Tecnologico de Monterrey','creador.com'),
      'fechaInicio' => '01/01/15',
      'duracion' => '4 Semanas',
      'precio' => '$1,500.00',
      'calificacion' => '5 Estrellas',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Matematicas II - 11','canal.com'),
      'tutor' => l('Salvador Gomez','usuario.com'),
      'creador' => l('Tecnologico de Monterrey','creador.com'),
      'fechaInicio' => '01/01/15',
      'duracion' => '4 Semanas',
      'precio' => '$1,500.00',
      'calificacion' => '5 Estrellas',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Matematicas II - 12','canal.com'),
      'tutor' => l('Salvador Gomez','usuario.com'),
      'creador' => l('Tecnologico de Monterrey','creador.com'),
      'fechaInicio' => '01/01/15',
      'duracion' => '4 Semanas',
      'precio' => '$1,500.00',
      'calificacion' => '5 Estrellas',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Matematicas II - 13','canal.com'),
      'tutor' => l('Salvador Gomez','usuario.com'),
      'creador' => l('Tecnologico de Monterrey','creador.com'),
      'fechaInicio' => '01/01/15',
      'duracion' => '4 Semanas',
      'precio' => '$1,500.00',
      'calificacion' => '5 Estrellas',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Matematicas II - 14','canal.com'),
      'tutor' => l('Salvador Gomez','usuario.com'),
      'creador' => l('Tecnologico de Monterrey','creador.com'),
      'fechaInicio' => '01/01/15',
      'duracion' => '4 Semanas',
      'precio' => '$1,500.00',
      'calificacion' => '5 Estrellas',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Matematicas II - 15','canal.com'),
      'tutor' => l('Salvador Gomez','usuario.com'),
      'creador' => l('Tecnologico de Monterrey','creador.com'),
      'fechaInicio' => '01/01/15',
      'duracion' => '4 Semanas',
      'precio' => '$1,500.00',
      'calificacion' => '5 Estrellas',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Matematicas II - 16','canal.com'),
      'tutor' => l('Salvador Gomez','usuario.com'),
      'creador' => l('Tecnologico de Monterrey','creador.com'),
      'fechaInicio' => '01/01/15',
      'duracion' => '4 Semanas',
      'precio' => '$1,500.00',
      'calificacion' => '5 Estrellas',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Matematicas II - 17','canal.com'),
      'tutor' => l('Salvador Gomez','usuario.com'),
      'creador' => l('Tecnologico de Monterrey','creador.com'),
      'fechaInicio' => '01/01/15',
      'duracion' => '4 Semanas',
      'precio' => '$1,500.00',
      'calificacion' => '5 Estrellas',
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

/*
Ver Canal - Consultar equipo
*/
function consultar_ver_canal_equipo_db($uid, $limite_inicial, $limite_final){
  $arrResultados = array();
  array_push($arrResultados,
    array(
      'imagen' => 'http://placehold.it/300x300',
      'tutor' => 'Ramiro Gonzalez 1',
    ),
    array(
      'imagen' => 'http://placehold.it/300x300',
      'tutor' => 'Ramiro Gonzalez 2',
    ),
    array(
      'imagen' => 'http://placehold.it/300x300',
      'tutor' => 'Ramiro Gonzalez 3',
    ),
    array(
      'imagen' => 'http://placehold.it/300x300',
      'tutor' => 'Ramiro Gonzalez 4',
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


function consultar_canales_usuario_db($uid_usuario){
    $arrResultados = array();

    array_push($arrResultados,
            array(
                
                'field_usuario_privacidad_canales' => 1,
                'calc_usuario_nombre' => 'Esteban Patiño',
                'array_canales' =>array(
                              
                             array(
                                  'nid' => 1,
                                  'field_canal_nombre' => 'Canal 1',
                                  'field_canal_imagen' => 'http://placehold.it/200x200',
                                  'link_canal' => 'canal/canal1'
                                  ),
                             array(
                                  'nid' => 2,
                                  'field_canal_nombre' => 'Canal 2',
                                  'field_canal_imagen' => 'http://placehold.it/200x200',
                                  'link_canal' => 'canal/canal1'
                                  ),
                             array(
                                  'nid' => 3,
                                  'field_canal_nombre' => 'Canal 3',
                                  'field_canal_imagen' => 'http://placehold.it/200x200',
                                  'link_canal' => 'canal/canal1'
                                  ),
                             array(
                                  'nid' => 4,
                                  'field_canal_nombre' => 'Canal 4',
                                  'field_canal_imagen' => 'http://placehold.it/200x200',
                                  'link_canal' => 'canal/canal1'
                                  ),
                             array(
                                  'nid' => 5,
                                  'field_canal_nombre' => 'Canal 5',
                                  'field_canal_imagen' => 'http://placehold.it/200x200',
                                  'link_canal' => 'canal/canal1'
                                  )
                             )                
            )
          );    
    return $arrResultados;      
}