<?php    
    function mostrar_listado($resultadosPorLinea, $resultadosPorPagina, $items, $tpl)
    {
        if(is_numeric(arg(1)))
            $pagina = arg(1);
        else
            $pagina = 1;
    
 
        $indiceLinea = 0;
        $totalResultados = count($items);

        $totalPaginas = ceil ($totalResultados/$resultadosPorPagina);

        echo "<div class='row'  >";
        foreach($items as $item){                       
            $anchoColumnas = intval(12/$resultadosPorLinea);
            if ($indiceLinea < $resultadosPorLinea)
                $indiceLinea++;
            else
                $indiceLinea = 1;        

            print theme($tpl,array('item' => $item,'anchoColumnas' => $anchoColumnas));		

        }

        echo "</div>";

    }
    
    function mostrar_paginacion($resultadosPorPagina,$items,$totalResultados,$funcion,$parametros,$contenedorAjax,$themePaginacion,$pagina)
    {
        if ($parametros == '' || $parametros == null)
            $parametros = "dummy:0 ";
        
        if(!is_numeric($pagina))
            $pagina = 1;

        $limiteIni = (($pagina - 1)* $resultadosPorPagina) + 1;
        $limiteSup = $pagina * $resultadosPorPagina;
        $totalPaginas = ceil ($totalResultados/$resultadosPorPagina);

        print theme('paginacion',array('totalPaginas' => $totalPaginas,'pagina' => $pagina, 'funcionAjax' => $funcion, 'parametrosAjax' => $parametros, 'contenedorAjax'=>$contenedorAjax));
    }
    
    function mostrar_carrusel($resultados_por_pantalla, $items, $tpl, $id_slider,$titulo,$tipo)
    {                                  
        $estiloTitulo = "carrusel-titulo ";
        switch($tipo){
            case "cursos":
                $estiloTitulo .= "cursos"; 
                break;
            case "canales":
                $estiloTitulo .= "canales"; 
                break;
            case "grupos":
                $estiloTitulo .= "grupos"; 
                break;
            case "proyectos":
                $estiloTitulo .= "proyectos"; 
                break;                 
            default:
                $estiloTitulo .= ""; 
                break;                
            
        }
        
        
        $contenidoHTML = '<div class="contenedor-carrusel no-margin"  ><h3 class="'.$estiloTitulo.'">'.$titulo.'</h3><div id="'.$id_slider.'" class="liquid-slider row">';
        $indice_item = 0;
        
        $anchoColumnas = 12/$resultados_por_pantalla;

        foreach($items as $item){ 
            if ($indice_item != 0)
            {
                $resto_division =  $indice_item % $resultados_por_pantalla;
                if ($resto_division == 0)
                    $contenidoHTML .= "</div><div>"; 
            }else
                $contenidoHTML .= "<div>";
                
            $contenidoHTML .= "<div class='large-".$anchoColumnas." columns end'>";    
            $contenidoHTML .=  theme($tpl, array('item' => $item));
            $contenidoHTML .= "</div>";                
                        
            $indice_item++;            
        }
        $contenidoHTML .= "</div>";
        $contenidoHTML .= "</div>";
        $contenidoHTML .= "</div>";

        $contenidoHTML .= "  <script>
        jQuery('#".$id_slider."').liquidSlider();
            </script>";
        return $contenidoHTML; 
    }
    
    function mostrar_ver_mas($temaVerMas,$divContenedor,$fName,$parametros,$ultimoNid)
    {
        print theme($temaVerMas, array('item' => array(
                                                      'div_contenedor' => $divContenedor,
                                                      'f_name' => $fName,
                                                      'parametros' => $parametros,
                                                      'ultimo_nid' => $ultimoNid)
                                     ));    
    }
    
    
    function obtener_ultimo_nid($items,$campo_nid)
    {
        $longitud = sizeof($items) - 1;
        return ($items[$longitud][$campo_nid]);        
    }
    
    function mostrar_calificacion_estrellas($calificacion, $numeroVotos)
    {
        $rate = array('calificacion' => $calificacion, 'numero-votos' => $numeroVotos);
        print theme('ver_rate_stars', array('item' => $rate ));
    }
    
    
    ?>     
    
    
    
    

 
     

    

