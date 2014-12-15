<?php
    function consultar_proyectos_cursos_db($nid_curso, $limite_inicial, $limite_final){
        $arrResultados = array();
        
        array_push($arrResultados,
                array(        
                  'field_proyecto_nombre' => 'Diseña el cambio',
                  'field_proyecto_imagen' => 'http://placehold.it/200x200',
                  'link_proyecto' => 'proyecto/proyecto',
                  'field_proyecto_likes' => 22,
                  'calc_nombre_autor' => 'Juan Antonio Leal',
                  'field_usuario_imagen' => 'http://placehold.it/200x200',
                  'link_autor' => 'usuario/jose'                 
                ),
                array(        
                  'field_proyecto_nombre' => 'Diseña el cambio2',
                  'field_proyecto_imagen' => 'http://placehold.it/200x200',
                  'link_proyecto' => 'proyecto/proyecto',
                  'field_proyecto_likes' => 22,
                  'calc_nombre_autor' => 'Juan Antonio Leal',
                  'field_usuario_imagen' => 'http://placehold.it/200x200',
                  'link_autor' => 'usuario/jose'                   
                ),
                array(
                  'field_proyecto_nombre' => 'Diseña el cambio3',
                  'field_proyecto_imagen' => 'http://placehold.it/200x200',
                  'link_proyecto' => 'proyecto/proyecto',
                  'field_proyecto_likes' => 22,
                  'calc_nombre_autor' => 'Juan Antonio Leal',
                  'field_usuario_imagen' => 'http://placehold.it/200x200',
                  'link_autor' => 'usuario/jose'               
                ),
                array(        
                  'field_proyecto_nombre' => 'Diseña el cambio4',
                  'field_proyecto_imagen' => 'http://placehold.it/200x200',
                  'link_proyecto' => 'proyecto/proyecto',
                  'field_proyecto_likes' => 22,
                  'calc_nombre_autor' => 'Juan Antonio Leal',
                  'field_usuario_imagen' => 'http://placehold.it/200x200',
                  'link_autor' => 'usuario/jose'                   
                ),
                array(        
                  'field_proyecto_nombre' => 'Diseña el cambio5',
                  'field_proyecto_imagen' => 'http://placehold.it/200x200',
                  'link_proyecto' => 'proyecto/proyecto',
                  'field_proyecto_likes' => 22,
                  'calc_nombre_autor' => 'Juan Antonio Leal',
                  'field_usuario_imagen' => 'http://placehold.it/200x200',
                  'link_autor' => 'usuario/jose'                 
                )   )             ;
        
        
        
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
    
    function consultar_header_curso_db($nid_curso){
        
        //var_dump($nid_curso);
        //$nid_curso = 5;
        $data = '?f_name=get_curso_datos_header&nid='.$nid_curso;
        $data = get_data_from_service($data, false);
        
        $arrResultados = array();
        
        array_push($arrResultados,
                array(
        
                  'title' => $data->field_curso_nombre,
                  'calc_curso_creador' => $data->calc_curso_creador,
                  'link_curso_creador' => $data->link_curso_creador,
                  'field_curso_categoria'  => $data->field_curso_categoria,
                  'link_curso_categoria' => $data->link_curso_categoria,
                  'field_curso_subcategoria' =>  $data->field_curso_subcategoria,
                  'link_curso_subcategoria' =>  $data->link_curso_subcategoria,
                  'field_curso_imagen' => $data->field_curso_imagen,
                  'field_likes' => $data->field_likes,
                  'field_curso_calificacion' => $data->field_curso_calificacion,
                  'field_curso_numero_votos' => $data->field_curso_numero_votos,
                  'usuarios-populares-curso' =>array(
                                
                               array(
                                    'avatar-usuario' =>'http://placehold.it/200x200',
                                    'nombre-usuario' =>'usuario 1',
                                    'usuario-conectado' => true
                                    ),
                               array(
                                    'avatar-usuario' =>'http://placehold.it/200x200',
                                    'nombre-usuario' =>'usuario 2',
                                    'usuario-conectado' => false
                                    ),
                               array(
                                    'avatar-usuario' =>'http://placehold.it/200x200',
                                    'nombre-usuario' =>'usuario 3',
                                    'usuario-conectado' => true
                                    ),
                               array(
                                    'avatar-usuario' =>'http://placehold.it/200x200',
                                    'nombre-usuario' =>'usuario 4',
                                    'usuario-conectado' => false
                                    ),
                               array(
                                    'avatar-usuario' =>'http://placehold.it/200x200',
                                    'nombre-usuario' =>'usuario 5',
                                    'usuario-conectado' => true
                                    )
                               ),
                   'field_curso_profesores' => array()//$data->field_curso_profesores //TODO - falta revisarlo en front
                )
              );    
        return $arrResultados;  
    }
    
    function consultar_precio_curso_db($nid_curso){
        $arrResultados = array();
    
        
        $data = '?f_name=get_curso_precio&nid='.$nid_curso;
        $data = get_data_from_service($data, false);
    
        array_push($arrResultados,
                array(
                  'precio' => $data->field_curso_costo
                )
              );    
        return $arrResultados;      
    }
    
    function consultar_curso_info_gral_db($nid_curso){
        $data = '?f_name=get_curso_informacion&nid='.$nid_curso;
        $data = get_data_from_service($data, false);
    
        $arrResultados = array();
        array_push($arrResultados,
                array(
                  'field_curso_video' => $data->field_curso_imagen,
                  'field_curso_descripcion' => $data->field_curso_descripcion,
                  'field_curso_objetivo' => $data->field_curso_objetivo,
                  'field_curso_temario' => '<h2>Temario</h2>'.$data->field_curso_temario,
                  'field_curso_requerimientos' => $data->field_curso_requerimientos,
                  'field_curso_bibliografia_oficial' => $data->field_curso_bibliografia_oficial,
                  'field_curso_bibliografia_re' => $data->field_curso_bibliografia_re,
                  'field_curso_proximas_fechas' => $data->field_curso_proximas_fechas //$data->field_curso_proximas_fechas ////TODO - falta revisar implementacion
                )
              );    
        return $arrResultados;      
    }
    
    function consultar_curso_caracteristicas_principales_db($nid_curso){
        
        $data = '?f_name=get_curso_vista_rapida&nid='.$nid_curso;
        $data = get_data_from_service($data, false);
        
        $arrResultados = array();
    
        array_push($arrResultados,
                array(
                  'field_curso_modalidad' => $data->field_curso_modalidad,
                  'fiel_curso_tutoreo' => $data->field_curso_tutoreo,
                  'field_curso_idioma' => $data->field_curso_idioma
                  )
              );    
        return $arrResultados;          
    }
    
    function consultar_curso_fecha_db($nid_curso){
        $data = '?f_name=get_curso_fechas&nid='.$nid_curso;
        $data = get_data_from_service($data, false);
        
        $arrResultados = array();
    
        array_push($arrResultados,
                array(
                  'field_curso_proximas_fechas' => $data->field_curso_fecha,
                  'calc_curso_duracion' => $data->calc_curso_duracion
                  )
              );    
        return $arrResultados;          
    }    
    
    function consultar_curso_tutor_db($nid_curso){
        
        $data = '?f_name=get_curso_tutores&nid='.$nid_curso;
        $data = get_data_from_service($data, false);
        
        return $data;        
        //TODO - Verificar que los datos se impriman bien en el TPL (no hay datos)
        //$arrResultados = $data;//array();
        
        array_push($arrResultados,
                array(
                        array(
                            'picture' =>'http://placehold.it/200x200',
                            'calc_nombre_tutor' => $data->calc_nombre_tutor,
                            'link_nombre_tutor' => $data->link_tutor,
                            'field_usuario_empresa' => $data->field_usuario_empresa,
                            'uid' => 4
                        ),
                        array(
                            'picture' =>'http://placehold.it/200x200',
                            'calc_nombre_tutor' =>'Ramiro Gonzalez 2',
                            'link_nombre_tutor' =>'user/ramiro',
                            'field_usuario_empresa' => 'ITESM, Monterrey',
                            'uid' => 4
                        )                       
                    )
            );

        return $arrResultados;   
    }
    
    function consultar_grupos_curso_db($nid_curso){
        $arrResultados = array();
    
        array_push($arrResultados,
                array(        
                    array(
                        'field_grupo_imagen' =>'http://placehold.it/30x30',
                        'field_grupo_nombre' =>'Grupo 1',
                        'link_grupo' =>'grupo/grupo1'
                        ),
                    array(
                        'field_grupo_imagen' =>'http://placehold.it/30x30',
                        'field_grupo_nombre' =>'Grupo 1',
                        'link_grupo' =>'grupo/grupo1'
                        )
                )
              );    
        return $arrResultados;      
    }
    /*
    function consultar_curso_db($nid_curso){
        $arrResultados = array();
    
        array_push($arrResultados,
                array(
        
                  'titulo' => 'Curso de programación',
                  'canal'  => l('ITESM, Monterrey, NL, México', 'ver-canal/itesm'),
                  'categoria'  => l('Negocios', 'ver-cursos-categoria/negocios'),
                  'subcategoria' =>  l('Administracion', 'ver-cursos-subcategoria/negocios'),
                  'imagen' => 'http://placehold.it/200x200',
                  'video' => '//www.youtube.com/embed/coK4jM5wvko?list=PLU8oAlHdN5BktAXdEVCLUYzvDyqRQJ2lk',
                  'descripcion' => 'Esta es la descripcion del curso bla bla blabla bla bla',
                  'objetivosPrincipales' => '<ul><li>Objetivo 1</li><li>Objetivo 2</li></ul> BLa bla bla los objetivos shalala shalala',
                  'temario' => '<h2>Temario</h2><p>Bla bla bla bla</p>',
                  'precio' => 900,
                  'likes' => 600,
                  'fecha_proximo_curso' => 'Lunes 5 de Diciembre del 2014',
                  'duracion' => '3 semanas',
                  'rate' =>array(
                        'calificacion' => 3.5,
                        'numero-votos' => 200 
                  ),
                  'usuarios-populares-curso' =>array(
                                
                               array(
                                    'avatar-usuario' =>'http://placehold.it/200x200',
                                    'nombre-usuario' =>'usuario 1',
                                    'usuario-conectado' => true
                                    ),
                               array(
                                    'avatar-usuario' =>'http://placehold.it/200x200',
                                    'nombre-usuario' =>'usuario 2',
                                    'usuario-conectado' => false
                                    ),
                               array(
                                    'avatar-usuario' =>'http://placehold.it/200x200',
                                    'nombre-usuario' =>'usuario 3',
                                    'usuario-conectado' => true
                                    ),
                               array(
                                    'avatar-usuario' =>'http://placehold.it/200x200',
                                    'nombre-usuario' =>'usuario 4',
                                    'usuario-conectado' => false
                                    ),
                               array(
                                    'avatar-usuario' =>'http://placehold.it/200x200',
                                    'nombre-usuario' =>'usuario 5',
                                    'usuario-conectado' => true
                                    )
                               ), 
                  'fechas' => array(
                                    '2014/11/05',
                                    '2014/12/05'
                                    ),
                  'caracteristicas-principales' => array(
                                    'Curso 100% en linea',
                                    'Autodidacta',
                                    'No requisitos previos',
                                    'Español',
                                    'Lecciones en 4 videos',
                                    'Material descargable',
                                    '90% comentarios positivos'
                                    ),
                   'info-tutor' => array(
                                    'foto' =>'http://placehold.it/200x200',
                                    'nombre' =>'Ramiro Gonzalez',
                                    'institucion' => 'ITESM, Monterrey',
                                    'biografia-breve' => 'Breve biografia del maestro, the power of blablabla.',
                                    'uid' => 4
                                    ),
                   'grupos' => array(
                                    array(
                                        'imagen-grupo' =>'http://placehold.it/30x30',
                                        'nombre-grupo' =>l('Grupo 1','ver-grupo/grupo1')
                                        ),
                                    array(
                                        'imagen-grupo' =>'http://placehold.it/30x30',
                                        'nombre-grupo' =>l('Grupo 2','ver-grupo/grupo2')
                                        )
                                ),
                  'valor1' => '1,000.00',
                  'valor2' => '5 estrellitas =)',
                )
              );    
        return $arrResultados;      
    }*/
    
    
    function consultar_curso_opiniones_calificaciones($nid_curso, $limite_inicial, $limite_final){
        $arrResultados = array();
    
        array_push($arrResultados,
                    array(
                      'nombre-usuario' => 'Cristina Montenegro',
                      'imagen-usuario' => 'http://placehold.it/200x200',
                      'ciudad-usuario' => 'Monterrey, México',
                      'fecha-calificacion' => 'Agosto 10, 2014',
                      'titulo' => 'Muy recomendable!!!',
                      'comentario-positivo' => 'Comentario positivo bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla',
                      'comentario-negativo' => 'Comentario negativo bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla',
                      'rate' =>array(
                              'calificacion' => 3.5,
                              'numero-votos' => 200 
                      )                      
                    ),array(
                      'nombre-usuario' => 'Cristina Montenegro',
                      'imagen-usuario' => 'http://placehold.it/200x200',
                      'ciudad-usuario' => 'Monterrey, México',
                      'fecha-calificacion' => 'Agosto 10, 2014',
                      'titulo' => 'Muy recomendable 2!!!',
                      'comentario-positivo' => 'Comentario positivo bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla',
                      'comentario-negativo' => 'Comentario negativo bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla',
                      'rate' =>array(
                              'calificacion' => 3.5,
                              'numero-votos' => 200 
                      )                    
                    ),array(
                      'nombre-usuario' => 'Cristina Montenegro',
                      'imagen-usuario' => 'http://placehold.it/200x200',
                      'ciudad-usuario' => 'Monterrey, México',
                      'fecha-calificacion' => 'Agosto 10, 2014',
                      'titulo' => 'Muy recomendable 3!!!',
                      'comentario-positivo' => 'Comentario positivo bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla',
                      'comentario-negativo' => 'Comentario negativo bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla',
                      'rate' =>array(
                              'calificacion' => 3.5,
                              'numero-votos' => 200 
                      )                    
                    ),array(
                      'nombre-usuario' => 'Cristina Montenegro',
                      'imagen-usuario' => 'http://placehold.it/200x200',
                      'ciudad-usuario' => 'Monterrey, México',
                      'fecha-calificacion' => 'Agosto 10, 2014',
                      'titulo' => 'Muy recomendable 4!!!',
                      'comentario-positivo' => 'Comentario positivo bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla',
                      'comentario-negativo' => 'Comentario negativo bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla, bla',
                      'rate' =>array(
                              'calificacion' => 3.5,
                              'numero-votos' => 200 
                      )                    
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
    
    function consultar_curso_calificaciones($nid_curso){
        $arrResultados = array();
    
        array_push($arrResultados,
                array(
                  'calificaciones-1-estrella' => 3,
                  'calificaciones-2-estrella' => 1,
                  'calificaciones-3-estrella' => 2,
                  'calificaciones-4-estrella' => 6,
                  'calificaciones-5-estrella' => 7,
                  'calificacion-promedio' => 6.5,
                  'rate' =>array(
                        'calificacion' => 3.5,
                        'numero-votos' => 200 
                  ),                  
                  )
              );    
        return $arrResultados;      
    }    
    
    
    function consultar_comentarios_curso($nid_curso, $ultimo_nid, $limite){
        $arrResultados = array();
        $arrayDevuelve = array();
        $arrayTemp = array();
    
        if ($ultimo_nid == -1){
            $ultimo_nid = 999999;
        }
        array_push($arrResultados,
            array(
                array(
                  'nid' => 20,
                  'nombre-usuario' => l('Cristina Montenegro 1','curso'),
                  'imagen-usuario' => 'http://placehold.it/20x20',
                  'fecha-hora' => 'Agosto 10, 2014',
                  'comentario' => 'Muy recomendable!!!',
                  'field_comentario_megusta_total' => 6,
                  'field_comentario_megusta' => true,
                  'calc_comentario_respuestas' => array(
                        array(
                                'nid' => 21,
                                'nombre-usuario' => l('Cristina Montenegro resp 1','curso'),
                                'imagen-usuario' => 'http://placehold.it/20x20',
                                'fecha-hora' => 'Agosto 10, 2014',
                                'comentario' => 'Muy recomendable!!!',
                                'field_comentario_megusta_total' => 7,
                                'field_comentario_megusta' => true
                            ),
                        array(
                                'nid' => 22,
                                'nombre-usuario' => l('Cristina Montenegro resp 2','curso'),
                                'imagen-usuario' => 'http://placehold.it/20x20',
                                'fecha-hora' => 'Agosto 10, 2014',
                                'comentario' => 'Muy recomendable!!!',
                                'field_comentario_megusta_total' => 8,
                                'field_comentario_megusta' => false
                        )
                    ))
                ,array(
                  'nid' => 19,  
                  'nombre-usuario' => l('Cristina Montenegro 2','curso'),
                  'imagen-usuario' => 'http://placehold.it/20x20',
                  'fecha-hora' => 'Agosto 10, 2014',
                  'comentario' => 'Muy recomendable!!!',
                  'field_comentario_megusta_total' => 8,
                  'field_comentario_megusta' => false, 
                  'calc_comentario_respuestas' => null
                ),array(
                  'nid' => 18,  
                  'nombre-usuario' => l('Cristina Montenegro 3','curso'),
                  'imagen-usuario' => 'http://placehold.it/20x20',
                  'fecha-hora' => 'Agosto 10, 2014',
                  'comentario' => 'Muy recomendable!!!',
                  'field_comentario_megusta_total' => 8,
                  'field_comentario_megusta' => false,
                  'calc_comentario_respuestas' => null
                ),array(
                  'nid' => 17,  
                  'nombre-usuario' => l('Cristina Montenegro 4','curso'),
                  'imagen-usuario' => 'http://placehold.it/20x20',
                  'fecha-hora' => 'Agosto 10, 2014',
                  'comentario' => 'Muy recomendable!!!',
                  'field_comentario_megusta_total' => 8,
                  'field_comentario_megusta' => false,
                  'calc_comentario_respuestas' => null
                ),array(
                  'nid' => 16,  
                  'nombre-usuario' => l('Cristina Montenegro 5','curso'),
                  'imagen-usuario' => 'http://placehold.it/20x20',
                  'fecha-hora' => 'Agosto 10, 2014',
                  'comentario' => 'Muy recomendable!!!',
                  'field_comentario_megusta_total' => 8,
                  'field_comentario_megusta' => false,
                  'calc_comentario_respuestas' => null
                ),array(
                  'nid' => 15,  
                  'nombre-usuario' => l('Cristina Montenegro 6','curso'),
                  'imagen-usuario' => 'http://placehold.it/20x20',
                  'fecha-hora' => 'Agosto 10, 2014',
                  'comentario' => 'Muy recomendable!!!',
                  'field_comentario_megusta_total' => 8,
                  'field_comentario_megusta' => false,
                  'calc_comentario_respuestas' => null
                ),array(
                  'nid' => 14,  
                  'nombre-usuario' => l('Cristina Montenegro 7','curso'),
                  'imagen-usuario' => 'http://placehold.it/20x20',
                  'fecha-hora' => 'Agosto 10, 2014',
                  'comentario' => 'Muy recomendable!!!',
                  'field_comentario_megusta_total' => 8,
                  'field_comentario_megusta' => false,
                  'calc_comentario_respuestas' => null
                )                
            )
          );
        
        $i = 0;        
    
        foreach($arrResultados[0] as $elemento)
        { 
            if ($elemento['nid'] < $ultimo_nid && $i < $limite)
            {       
                array_push($arrayTemp, $elemento);
                $i++;
            }
            
        }
        
             
        
        return $arrayTemp;  
    }       
    
    function consultar_cursos_usuario_db($uid_usuario){
        $arrResultados = array();
    
        array_push($arrResultados,
            array(
                
                'field_usuario_privacidad_canales' => 1,
                'calc_usuario_nombre' => 'Esteban Patiño',
                'array_cursos' =>array(
                              
                             array(
                                'field_curso_nombre' => 'Curso 1',
                                'field_curso_imagen' => 'http://placehold.it/200x200',
                                'link_curso' => 'curso/curso2',
                                'tipo_curso' => 1 //1 es curso creado, 2 curso tomado
                                  ),
                             array(
                                'field_curso_nombre' => 'Curso 2',
                                'field_curso_imagen' => 'http://placehold.it/200x200',
                                'link_curso' => 'curso/curso2',
                                'tipo_curso' => 1 //1 es curso creado, 2 curso tomado
                                  ),
                             array(
                                  'field_curso_nombre' => 'Curso 3',
                                'field_curso_imagen' => 'http://placehold.it/200x200',
                                'link_curso' => 'curso/curso2',
                                'tipo_curso' => 1 //1 es curso creado, 2 curso tomado
                                  ),
                             array(
                                  'field_curso_nombre' => 'Curso 4',
                                'field_curso_imagen' => 'http://placehold.it/200x200',
                                'link_curso' => 'curso/curso2',
                                'tipo_curso' => 1 //1 es curso creado, 2 curso tomado
                                  ),
                             array(
                                  'field_curso_nombre' => 'Curso 5',
                                'field_curso_imagen' => 'http://placehold.it/200x200',
                                'link_curso' => 'curso/curso2',
                                'tipo_curso' => 1 //1 es curso creado, 2 curso tomado
                                  )
                             )                
            )
          );        
              
        return $arrResultados;      
    }
    
    function consultar_curso_recomendados($nid_curso){
        
        $data = '?f_name=get_cursos_recomendados&nid='.$nid_curso;
        $data = get_data_from_service($data, false);
        
        //TODO - Falta implementacion de el servicio para realizar la conexion
        
        $arrResultados = array();
    
        array_push($arrResultados,
                array(
                    array(
                      'nid_curso',  
                      'field_curso_nombre' => 'Curso 1',
                      'field_curso_imagen' => 'http://placehold.it/200x200',
                      'link_curso' => 'curso/curso2',
                      'field_curso_categoria' =>  'negocios',
                      'link_curso_categoria' => 'cursos/negocios',
                      'creador_curso_nombre' =>  'EducarUno',
                      'creador_curso_imagen' =>  'http://placehold.it/200x200',
                      'link_curso_creador' => 'usuarios/educar-uno',
                      'field_curso_calificacion' => 1.5,
                      'field_curso_numero_votos' => 230                   
                    ),array(
                      'nid_curso',
                      'field_curso_nombre' => 'Curso 2',
                      'field_curso_imagen' => 'http://placehold.it/200x200',
                      'link_curso' => 'curso/curso2',
                      'field_curso_categoria' =>  'negocios',
                      'link_curso_categoria' => 'cursos/negocios',
                      'creador_curso_nombre' =>  'EducarUno',
                      'creador_curso_imagen' =>  'http://placehold.it/200x200',
                      'link_curso_creador' => 'usuarios/educar-uno',
                      'field_curso_calificacion' => 1.5,
                      'field_curso_numero_votos' => 230                      
                    ),array(
                      'nid_curso',   
                      'field_curso_nombre' => 'Curso 3',
                      'field_curso_imagen' => 'http://placehold.it/200x200',
                      'link_curso' => 'curso/curso2',
                      'field_curso_categoria' =>  'negocios',
                      'link_curso_categoria' => 'cursos/negocios',
                      'creador_curso_nombre' =>  'EducarUno',
                      'creador_curso_imagen' =>  'http://placehold.it/200x200',
                      'link_curso_creador' => 'usuarios/educar-uno',
                      'field_curso_calificacion' => 1.5,
                      'field_curso_numero_votos' => 230                      
                    ),array(
                      'nid_curso',   
                      'field_curso_nombre' => 'Curso 4',
                      'field_curso_imagen' => 'http://placehold.it/200x200',
                      'link_curso' => 'curso/curso2',
                      'field_curso_categoria' =>  'negocios',
                      'link_curso_categoria' => 'cursos/negocios',
                      'creador_curso_nombre' =>  'EducarUno',
                      'creador_curso_imagen' =>  'http://placehold.it/200x200',
                      'link_curso_creador' => 'usuarios/educar-uno',
                      'field_curso_calificacion' => 1.5,
                      'field_curso_numero_votos' => 230                      
                    ),array(
                      'nid_curso',  
                      'field_curso_nombre' => 'Curso 5',
                      'field_curso_imagen' => 'http://placehold.it/200x200',
                      'link_curso' => 'curso/curso2',
                      'field_curso_categoria' =>  'negocios',
                      'link_curso_categoria' => 'cursos/negocios',
                      'creador_curso_nombre' =>  'EducarUno',
                      'creador_curso_imagen' =>  'http://placehold.it/200x200',
                      'link_curso_creador' => 'usuarios/educar-uno',
                      'field_curso_calificacion' => 1.5,
                      'field_curso_numero_votos' => 230                     
                    ),array(
                      'nid_curso',  
                      'field_curso_nombre' => 'Curso 6',
                      'field_curso_imagen' => 'http://placehold.it/200x200',
                      'link_curso' => 'curso/curso2',
                      'field_curso_categoria' =>  'negocios',
                      'link_curso_categoria' => 'cursos/negocios',
                      'creador_curso_nombre' =>  'EducarUno',
                      'creador_curso_imagen' =>  'http://placehold.it/200x200',
                      'link_curso_creador' => 'usuarios/educar-uno',
                      'field_curso_calificacion' => 1.5,
                      'field_curso_numero_votos' => 230  
                    ),array(
                      'nid_curso',  
                      'field_curso_nombre' => 'Curso 7',
                      'field_curso_imagen' => 'http://placehold.it/200x200',
                      'link_curso' => 'curso/curso2',
                      'field_curso_categoria' =>  'negocios',
                      'link_curso_categoria' => 'cursos/negocios',
                      'creador_curso_nombre' =>  'EducarUno',
                      'creador_curso_imagen' =>  'http://placehold.it/200x200',
                      'link_curso_creador' => 'usuarios/educar-uno',
                      'field_curso_calificacion' => 1.5,
                      'field_curso_numero_votos' => 230   
                    )
                )
              );    
        return $arrResultados;      
    }
    
    
    /*
    FUNCIÓN PARA OBTENER CURSOS POPULARES
    PARÁMETRO $arrFiltros: Arreglo con los siguientes campos                
                  'modalidad',   entero si no se seleccionó filtro llega como -1
                  'tipo',        entero si no se seleccionó filtro llega como -1
                  'ordenamiento',    entero si no se seleccionó criterio de ordenamiento llega como -1
                  'calificacion',    entero si no se seleccionó filtro llega como -1
                  'rango_precio_min', entero si no se seleccionó criterio de ordenamientofiltro llega como -1
                  'rango_precio_max'  entero si no se seleccionó criterio de ordenamientofiltro llega como -1
    */
    
    function consultar_cursos_populares_db($limite_inicial, $limite_final){                
        $arrResultados = array();
        array_push($arrResultados,
                    array(
                      'nid_curso' => 1,  
                      'field_curso_nombre' => 'Curso 1',
                      'field_curso_imagen' => 'http://placehold.it/200x200',
                      'link_curso' => 'curso/curso2',
                      'creador_curso_nombre' =>  'EducarUno',
                      'creador_curso_imagen' =>  'http://placehold.it/200x200',
                      'link_curso_creador' => 'usuarios/educar-uno',
                      'field_curso_costo' => '$ 4,000 MXN',
                      'field_curso_duracion' => '4 semanas',
                      'calc_nombre_tutor' =>'Ramiro Gonzalez 1',
                      'link_nombre_tutor' =>'user/ramiro',
                      'field_curso_canal' =>'Canal 1',
                      'link_curso_canal' =>'user/ramiro',                      
                      'array_usuarios_curso' => array(
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 1',
                                'link_usuario_curso' => 'usuario/juanita'
                            ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 2',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 3',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 4',
                                'link_usuario_curso' => 'usuario/juanita'
                        ))
                    ),array(
                      'nid_curso' => 2,  
                      'field_curso_nombre' => 'Curso 2',
                      'field_curso_imagen' => 'http://placehold.it/200x200',
                      'link_curso' => 'curso/curso2',
                      'creador_curso_nombre' =>  'EducarUno',
                      'creador_curso_imagen' =>  'http://placehold.it/200x200',
                      'link_curso_creador' => 'usuarios/educar-uno',
                      'field_curso_costo' => '$ 4,000 MXN',
                      'field_curso_duracion' => '4 semanas',
                      'calc_nombre_tutor' =>'Ramiro Gonzalez 1',
                      'link_nombre_tutor' =>'user/ramiro',                         
                      'array_usuarios_curso' => array(
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 1',
                                'link_usuario_curso' => 'usuario/juanita'
                            ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 2',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 3',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 4',
                                'link_usuario_curso' => 'usuario/juanita'
                        ))                 
                    ),array(
                      'nid_curso' => 3,  
                      'field_curso_nombre' => 'Curso 3',
                      'field_curso_imagen' => 'http://placehold.it/200x200',
                      'link_curso' => 'curso/curso2',
                      'creador_curso_nombre' =>  'EducarUno',
                      'creador_curso_imagen' =>  'http://placehold.it/200x200',
                      'link_curso_creador' => 'usuarios/educar-uno',
                      'field_curso_costo' => '$ 4,000 MXN',
                      'calc_nombre_tutor' =>'Ramiro Gonzalez 1',
                      'link_nombre_tutor' =>'user/ramiro',                         
                      'field_curso_duracion' => '4 semanas',
                      'array_usuarios_curso' => array(
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 1',
                                'link_usuario_curso' => 'usuario/juanita'
                            ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 2',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 3',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 4',
                                'link_usuario_curso' => 'usuario/juanita'
                        ))                    
                    ),array(
                      'nid_curso' => 4,  
                      'field_curso_nombre' => 'Curso 4',
                      'field_curso_imagen' => 'http://placehold.it/200x200',
                      'link_curso' => 'curso/curso2',
                      'creador_curso_nombre' =>  'EducarUno',
                      'creador_curso_imagen' =>  'http://placehold.it/200x200',
                      'link_curso_creador' => 'usuarios/educar-uno',
                      'field_curso_costo' => '$ 4,000 MXN',
                      'calc_nombre_tutor' =>'Ramiro Gonzalez 1',
                      'link_nombre_tutor' =>'user/ramiro',                         
                      'field_curso_duracion' => '4 semanas',
                      'array_usuarios_curso' => array(
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 1',
                                'link_usuario_curso' => 'usuario/juanita'
                            ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 2',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 3',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 4',
                                'link_usuario_curso' => 'usuario/juanita'
                        ))                    
                    ),array(
                      'nid_curso' => 5,  
                      'field_curso_nombre' => 'Curso 5',
                      'field_curso_imagen' => 'http://placehold.it/200x200',
                      'link_curso' => 'curso/curso2',
                      'creador_curso_nombre' =>  'EducarUno',
                      'creador_curso_imagen' =>  'http://placehold.it/200x200',
                      'link_curso_creador' => 'usuarios/educar-uno',
                      'field_curso_costo' => '$ 4,000 MXN',
                      'calc_nombre_tutor' =>'Ramiro Gonzalez 1',
                      'link_nombre_tutor' =>'user/ramiro',                         
                      'field_curso_duracion' => '4 semanas',
                      'array_usuarios_curso' => array(
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 1',
                                'link_usuario_curso' => 'usuario/juanita'
                            ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 2',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 3',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 4',
                                'link_usuario_curso' => 'usuario/juanita'
                        ))                   
                    ),array(
                      'nid_curso' => 6,  
                      'field_curso_nombre' => 'Curso 6',
                      'field_curso_imagen' => 'http://placehold.it/200x200',
                      'link_curso' => 'curso/curso2',
                      'creador_curso_nombre' =>  'EducarUno',
                      'creador_curso_imagen' =>  'http://placehold.it/200x200',
                      'link_curso_creador' => 'usuarios/educar-uno',
                      'field_curso_costo' => '$ 4,000 MXN',
                      'calc_nombre_tutor' =>'Ramiro Gonzalez 1',
                      'link_nombre_tutor' =>'user/ramiro',                         
                      'field_curso_duracion' => '4 semanas',
                      'array_usuarios_curso' => array(
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 1',
                                'link_usuario_curso' => 'usuario/juanita'
                            ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 2',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 3',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 4',
                                'link_usuario_curso' => 'usuario/juanita'
                        ))
                    ),array(
                      'nid_curso' => 7,  
                      'field_curso_nombre' => 'Curso 7',
                      'field_curso_imagen' => 'http://placehold.it/200x200',
                      'link_curso' => 'curso/curso2',
                      'creador_curso_nombre' =>  'EducarUno',
                      'creador_curso_imagen' =>  'http://placehold.it/200x200',
                      'link_curso_creador' => 'usuarios/educar-uno',
                      'field_curso_costo' => '$ 4,000 MXN',
                      'calc_nombre_tutor' =>'Ramiro Gonzalez 1',
                      'link_nombre_tutor' =>'user/ramiro',                         
                      'field_curso_duracion' => '4 semanas',
                      'array_usuarios_curso' => array(
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 1',
                                'link_usuario_curso' => 'usuario/juanita'
                            ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 2',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 3',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 4',
                                'link_usuario_curso' => 'usuario/juanita'
                        ) 
                    )
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
    FUNCIÓN PARA OBTENER EL PRIMER TUTOR DE UNA LISTA DE TUTORES
    PARÁMETRO $array_tutores: Array de tutores
    DAVID TERRONES 12/12/2014
    */    
    function obtener_primer_tutor($array_tutores)
    {        
        if (!is_null($array_tutores) && count($array_tutores) > 0)
        {
            $primer_tutor = array_pop($array_tutores);
            $primer_tutor_object = (object) array('calc_nombre_tutor' => $primer_tutor->calc_nombre_tutor, 'link_nombre_tutor' => $primer_tutor->link_nombre_tutor);   
        }else
        {
            $primer_tutor_object = (object) array('calc_nombre_tutor' => '', 'link_nombre_tutor' => '');   
        }
        
        return $primer_tutor_object;
    }
    
    
    /*
    FUNCIÓN PARA OBTENER LOS PRIMEROS USUARIOS DE UNA LISTA
    PARÁMETRO $array_usuarios: Array de tutores
              $limite_usuarios: numero de usuarios que se obtendrán de la lista 
    DAVID TERRONES 12/12/2014
    */    
    function obtener_usuarios_de_lista($array_usuarios, $limite_usuarios)
    {
        $lista_usuarios = array();
        
        if (!is_null($array_usuarios) && count($array_usuarios) > 0)
        {
            $cantidad_usuarios = count($array_usuarios);
            if ($cantidad_usuarios > $limite_usuarios)
                $cantidad_usuarios = $limite_usuarios;
            
            for ($i=0; $i < $cantidad_usuarios;$i++)
            {
                array_push($lista_usuarios,
                    array(
                      'calc_usuario_nombre' => $array_usuarios[$i]->calc_usuario_nombre,
                      'field_usuario_imagen' => $array_usuarios[$i]->field_usuario_imagen,
                      'link_usuario_curso' => $array_usuarios[$i]->link_usuario_curso
                      )
                    );
            }
            
            $primer_tutor = array_pop($array_tutores);
            $primer_tutor_object = (object) array('calc_nombre_tutor' => $primer_tutor->calc_nombre_tutor, 'link_nombre_tutor' => $primer_tutor->link_nombre_tutor);   
        }else
        {
            $lista_usuarios = null;//$primer_tutor_object = (object) array('calc_nombre_tutor' => '', 'link_nombre_tutor' => '');   
        }
        
        return $lista_usuarios;
    }
    
        /*
    FUNCIÓN PARA OBTENER CURSOS POR CATEGORIA 
    PARÁMETRO $arrFiltros: Arreglo con los siguientes campos
                  'categoria',   nid_categoria
                  'modalidad',   entero si no se seleccionó filtro llega como -1
                  'tipo',        entero si no se seleccionó filtro llega como -1
                  'ordenamiento',    entero si no se seleccionó criterio de ordenamiento llega como -1
                  'calificacion',    entero si no se seleccionó filtro llega como -1
                  'rango_precio_min', entero si no se seleccionó criterio de ordenamientofiltro llega como -1
                  'rango_precio_max'  entero si no se seleccionó criterio de ordenamientofiltro llega como -1
    */
        
    function consultar_cursos_categoria_db($arrFiltros,$limite_inicial, $limite_final){
        //var_dump($arrFiltros);
        $parametros = "";
        //$parametros .= "categoria=".$arrFiltros['categoria']; 60 63
        $parametros .= "categoria=-1";
        $parametros .= "&modalidad=".$arrFiltros['modalidad'];
        $parametros .= "&ordenamiento=".$arrFiltros['ordenamiento'];
        $parametros .= "&calificacion=".$arrFiltros['calificacion'];
        $parametros .= "&rango_precio_min=".$arrFiltros['rango_precio_min'];
        $parametros .= "&rango_precio_max=".$arrFiltros['rango_precio_max'];
        $parametros .= "&inicio=".$limite_inicial;
        $parametros .= "&limite=".$limite_final;
        $url = "?f_name=get_cursos_busqueda&".$parametros; 
        //var_dump($url);
        /*
        $data = $url;        
        $data = get_data_from_service($data, false);  
                //var_dump($data);        
        
        $arrResultados = array();
        foreach($data AS $elemento)
        {
            //var_dump($elemento);
            
            $tutor = obtener_primer_tutor($elemento->array_curso_profesores);
            $lista_usuarios = obtener_usuarios_de_lista($elemento->array_usuarios_curso,4);
                        
            array_push($arrResultados,
                    array(
                      'nid_curso' => $elemento->nid,  
                      'field_curso_nombre' => $elemento->field_curso_nombre,
                      'field_curso_imagen' => $elemento->field_curso_imagen,
                      'link_curso' => $elemento->link_curso,
                      'creador_curso_nombre' =>  $elemento->calc_creador_nombre,
                      'creador_curso_imagen' =>  $elemento->field_usuario_imagen,
                      'link_curso_creador' => $elemento->link_curso_creador,
                      'field_curso_costo' => $elemento->field_curso_costo,
                      'field_curso_duracion' => $elemento->calc_curso_duracion,
                      'calc_nombre_tutor' => $tutor->calc_nombre_tutor,
                      'link_nombre_tutor' => $tutor->link_nombre_tutor,
                      'field_curso_canal' => $elemento->field_curso_canal,
                      'link_curso_canal' => $elemento->link_curso_canal,
                      'field_likes' => $elemento->field_likes,
                      'field_curso_calificacion' => $elemento->field_curso_calificacion,
                      'field_curso_numero_votos' => $elemento->field_curso_numero_votos,                      
                      'array_usuarios_curso' => $lista_usuarios
                    )
                  );
                    
            
        }

        return $arrResultados;
        */
        $arrResultados = array();
        array_push($arrResultados,
                    array(
                      'nid_curso' => 1,  
                      'field_curso_nombre' => 'Curso cat 1',
                      'field_curso_imagen' => 'http://placehold.it/200x200',
                      'link_curso' => 'curso/curso2',
                      'creador_curso_nombre' =>  'EducarUno',
                      'creador_curso_imagen' =>  'http://placehold.it/200x200',
                      'link_curso_creador' => 'usuarios/educar-uno',
                      'field_curso_costo' => '$ 4,000 MXN',
                      'field_curso_duracion' => '4 semanas',
                      'calc_nombre_tutor' =>'Ramiro Gonzalez 1',
                      'link_nombre_tutor' =>'user/ramiro',
                      'field_curso_canal' =>'Canal 1',
                      'link_curso_canal' =>'user/ramiro',
                      'field_curso_calificacion' => 3.5,
                      'field_curso_numero_votos' => 50,                      
                      'array_usuarios_curso' => array(
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 1',
                                'link_usuario_curso' => 'usuario/juanita'
                            ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 2',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 3',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 4',
                                'link_usuario_curso' => 'usuario/juanita'
                        ))
                    ),array(
                      'nid_curso' => 2,  
                      'field_curso_nombre' => 'Curso 2',
                      'field_curso_imagen' => 'http://placehold.it/200x200',
                      'link_curso' => 'curso/curso2',
                      'creador_curso_nombre' =>  'EducarUno',
                      'creador_curso_imagen' =>  'http://placehold.it/200x200',
                      'link_curso_creador' => 'usuarios/educar-uno',
                      'field_curso_costo' => '$ 4,000 MXN',
                      'field_curso_duracion' => '4 semanas',
                      'calc_nombre_tutor' =>'Ramiro Gonzalez 1',
                      'link_nombre_tutor' =>'user/ramiro',
                      'field_curso_calificacion' => 3.5,
                      'field_curso_numero_votos' => 50,                                            
                      'array_usuarios_curso' => array(
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 1',
                                'link_usuario_curso' => 'usuario/juanita'
                            ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 2',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 3',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 4',
                                'link_usuario_curso' => 'usuario/juanita'
                        ))                 
                    ),array(
                      'nid_curso' => 3,  
                      'field_curso_nombre' => 'Curso 3',
                      'field_curso_imagen' => 'http://placehold.it/200x200',
                      'link_curso' => 'curso/curso2',
                      'creador_curso_nombre' =>  'EducarUno',
                      'creador_curso_imagen' =>  'http://placehold.it/200x200',
                      'link_curso_creador' => 'usuarios/educar-uno',
                      'field_curso_costo' => '$ 4,000 MXN',
                      'calc_nombre_tutor' =>'Ramiro Gonzalez 1',
                      'link_nombre_tutor' =>'user/ramiro',                         
                      'field_curso_duracion' => '4 semanas',
                      'field_curso_calificacion' => 3.5,
                      'field_curso_numero_votos' => 50,                                            
                      'array_usuarios_curso' => array(
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 1',
                                'link_usuario_curso' => 'usuario/juanita'
                            ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 2',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 3',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 4',
                                'link_usuario_curso' => 'usuario/juanita'
                        ))                    
                    ),array(
                      'nid_curso' => 4,  
                      'field_curso_nombre' => 'Curso 4',
                      'field_curso_imagen' => 'http://placehold.it/200x200',
                      'link_curso' => 'curso/curso2',
                      'creador_curso_nombre' =>  'EducarUno',
                      'creador_curso_imagen' =>  'http://placehold.it/200x200',
                      'link_curso_creador' => 'usuarios/educar-uno',
                      'field_curso_costo' => '$ 4,000 MXN',
                      'calc_nombre_tutor' =>'Ramiro Gonzalez 1',
                      'link_nombre_tutor' =>'user/ramiro',                         
                      'field_curso_duracion' => '4 semanas',
                      'field_curso_calificacion' => 3.5,
                      'field_curso_numero_votos' => 50,                                            
                      'array_usuarios_curso' => array(
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 1',
                                'link_usuario_curso' => 'usuario/juanita'
                            ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 2',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 3',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 4',
                                'link_usuario_curso' => 'usuario/juanita'
                        ))                    
                    ),array(
                      'nid_curso' => 5,  
                      'field_curso_nombre' => 'Curso 5',
                      'field_curso_imagen' => 'http://placehold.it/200x200',
                      'link_curso' => 'curso/curso2',
                      'creador_curso_nombre' =>  'EducarUno',
                      'creador_curso_imagen' =>  'http://placehold.it/200x200',
                      'link_curso_creador' => 'usuarios/educar-uno',
                      'field_curso_costo' => '$ 4,000 MXN',
                      'calc_nombre_tutor' =>'Ramiro Gonzalez 1',
                      'link_nombre_tutor' =>'user/ramiro',                         
                      'field_curso_duracion' => '4 semanas',
                      'field_curso_calificacion' => 3.5,
                      'field_curso_numero_votos' => 50,                                            
                      'array_usuarios_curso' => array(
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 1',
                                'link_usuario_curso' => 'usuario/juanita'
                            ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 2',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 3',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 4',
                                'link_usuario_curso' => 'usuario/juanita'
                        ))                   
                    ),array(
                      'nid_curso' => 6,  
                      'field_curso_nombre' => 'Curso 6',
                      'field_curso_imagen' => 'http://placehold.it/200x200',
                      'link_curso' => 'curso/curso2',
                      'creador_curso_nombre' =>  'EducarUno',
                      'creador_curso_imagen' =>  'http://placehold.it/200x200',
                      'link_curso_creador' => 'usuarios/educar-uno',
                      'field_curso_costo' => '$ 4,000 MXN',
                      'calc_nombre_tutor' =>'Ramiro Gonzalez 1',
                      'link_nombre_tutor' =>'user/ramiro',                         
                      'field_curso_duracion' => '4 semanas',
                      'field_curso_calificacion' => 3.5,
                      'field_curso_numero_votos' => 50,                                            
                      'array_usuarios_curso' => array(
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 1',
                                'link_usuario_curso' => 'usuario/juanita'
                            ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 2',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 3',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 4',
                                'link_usuario_curso' => 'usuario/juanita'
                        ))
                    ),array(
                      'nid_curso' => 7,  
                      'field_curso_nombre' => 'Curso 7',
                      'field_curso_imagen' => 'http://placehold.it/200x200',
                      'link_curso' => 'curso/curso2',
                      'creador_curso_nombre' =>  'EducarUno',
                      'creador_curso_imagen' =>  'http://placehold.it/200x200',
                      'link_curso_creador' => 'usuarios/educar-uno',
                      'field_curso_costo' => '$ 4,000 MXN',
                      'calc_nombre_tutor' =>'Ramiro Gonzalez 1',
                      'link_nombre_tutor' =>'user/ramiro',                         
                      'field_curso_duracion' => '4 semanas',
                      'field_curso_calificacion' => 3.5,
                      'field_curso_numero_votos' => 50,                                            
                      'array_usuarios_curso' => array(
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 1',
                                'link_usuario_curso' => 'usuario/juanita'
                            ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 2',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 3',
                                'link_usuario_curso' => 'usuario/juanita'
                        ),
                        array(
                                'field_usuario_imagen' => 'http://placehold.it/20x20',
                                'calc_usuario_nombre' => 'Cristina Montenegro 4',
                                'link_usuario_curso' => 'usuario/juanita'
                        ) 
                    )
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
    
    
    function consultar_preguntas_frecuentes($nid_curso){
        $arrResultados = array();
        
        
        $data = '?f_name=get_preguntas_frecuentes&nid='.$nid_curso;
        $data = get_data_from_service($data, false);
        
        array_push($arrResultados, $data
                /*array(
                    array(
                      'pregunta' => 'pregunta 1',
                      'respuesta' => 'Respuesta 1'                     
                    ),array(
                      'pregunta' => 'pregunta 2',
                      'respuesta' => 'Respuesta 3'
                    ),array(
                      'pregunta' => 'pregunta 3',
                      'respuesta' => 'Respuesta 3'
                    ),array(
                      'pregunta' => 'pregunta 4',
                      'respuesta' => 'Respuesta 4'
                    ),array(
                      'pregunta' => 'pregunta 5',
                      'respuesta' => 'Respuesta 5'
                    )
                )*/
              );    
        return $arrResultados;      
    }
    

    function consultar_likes_usuarios_curso($nid_curso, $ultimo_nid, $limite){
        $arrResultados = array();
        $arrayDevuelve = array();
        $arrayTemp = array();
    
        if ($ultimo_nid == -1){
            $ultimo_nid = 999999;
        }        
        $arrResultados = array();
    
        array_push($arrResultados,
                array(                    
                    array(
                      'nid' => 20,  
                      'imagen-usuario' => 'http://placehold.it/38x38',
                      'nombre-usuario' => 'Ken Terrones',
                      'nombre-usuario-liga' => l('Ken Terrones','usuario/ken-terrones'),
                      'usuario-conectado' => true 
                    ),array(
                      'nid' => 19,    
                      'imagen-usuario' => 'http://placehold.it/38x38',
                      'nombre-usuario' => 'Ken Terrones 2',
                      'nombre-usuario-liga' => l('Ken Terrones 2','usuario/ken-terrones'),
                      'usuario-conectado' => false 
                    ),array(
                      'nid' => 18,    
                      'imagen-usuario' => 'http://placehold.it/38x38',
                      'nombre-usuario' => 'Ken Terrones 3',
                      'nombre-usuario-liga' => l('Ken Terrones 3','usuario/ken-terrones'),
                      'usuario-conectado' => true 
                    ),array(
                      'nid' => 17,    
                      'imagen-usuario' => 'http://placehold.it/38x38',
                      'nombre-usuario' => 'Ken Terrones4',
                      'nombre-usuario-liga' => l('Ken Terrones 4','usuario/ken-terrones'),
                      'usuario-conectado' => false 
                    ),array(
                      'nid' => 16,    
                      'imagen-usuario' => 'http://placehold.it/38x38',
                      'nombre-usuario' => 'Ken Terrones 5',
                      'nombre-usuario-liga' => l('Ken Terrones 5','usuario/ken-terrones'),
                      'usuario-conectado' => false 
                    ),array(
                      'nid' => 15,    
                      'imagen-usuario' => 'http://placehold.it/38x38',
                      'nombre-usuario' => 'Ken Terrones 6',
                      'nombre-usuario-liga' => l('Ken Terrones 6','usuario/ken-terrones'),
                      'usuario-conectado' => false 
                    ),array(
                      'nid' => 14,    
                      'imagen-usuario' => 'http://placehold.it/38x38',
                      'nombre-usuario' => 'Ken Terrones 7',
                      'nombre-usuario-liga' => l('Ken Terrones 7','usuario/ken-terrones'),
                      'usuario-conectado' => true 
                    ),array(
                      'nid' => 13,    
                      'imagen-usuario' => 'http://placehold.it/38x38',
                      'nombre-usuario' => 'Ken Terrones 8',
                      'nombre-usuario-liga' => l('Ken Terrones 8','usuario/ken-terrones'),
                      'usuario-conectado' => false 
                    ),array(
                      'nid' => 12,    
                      'imagen-usuario' => 'http://placehold.it/38x38',
                      'nombre-usuario' => 'Ken Terrones 9',
                      'nombre-usuario-liga' => l('Ken Terrones 9','usuario/ken-terrones'),
                      'usuario-conectado' => false 
                    )
                )
              );    
        $i = 0;        
    
        foreach($arrResultados[0] as $elemento)
        { 
            if ($elemento['nid'] < $ultimo_nid && $i < $limite)
            {       
                array_push($arrayTemp, $elemento);
                $i++;
            }
            
        }

        return $arrayTemp;  
    }        

    function get_data_from_service($data, $debug)
    {
        Global $base_url;
        
        $result = drupal_http_request($base_url.'/api'.$data);
        $data = json_decode($result->data);
        
        if ($debug)
            var_dump($data);
            //print_r($data);
        
        return $data;
    }    
    
    ?>

