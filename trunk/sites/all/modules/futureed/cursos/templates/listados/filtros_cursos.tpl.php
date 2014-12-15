<?php
    $pathImagenes = base_path().drupal_get_path('module','fedcorefront').'/images/';
    $rate_full  = "rate-full.jpg";
    $rate_half  = "rate-half.jpg";
    $rate_empty = "rate-empty.jpg";
    $precio_min = 0;
    $precio_max = 500;
    $precio_ini_min = 75;
    $precio_ini_max = 300;
    drupal_add_js(base_path().drupal_get_path('module','cursos').'/js/app.js');
    
    if ($item['parametros_extra'] != '' && $item['parametros_extra'] != null)
        $parametros = '\''.$item['parametros_extra'].'\',\''.$item['contenedor'].'\',\''.$item['f_name'].'\'';
    else
        $parametros = 'null,\''.$item['contenedor'].'\',\''.$item['f_name'].'\'';
          
?>

<div class="row contenedor-filtros">    
    <div id='tabFiltro-1' onclick="muestraPanelTabToogle('panelFiltro-1','tabFiltro-1')" class="small-2 columns inactive-tab small-offset-6"><?=MODALIDAD;?></div>
    <!---<div id='tabFiltro-2' onclick="muestraPanelTabToogle('panelFiltro-2','tabFiltro-2')" class="large-4 columns tab inactive-tab"><?//=TIPO_DE_CURSO;?></div>--->
    <div id='tabFiltro-3' onclick="muestraPanelTabToogle('panelFiltro-3','tabFiltro-3')" class="small-2 columns inactive-tab"><?=ORDENAR_POR;?></div>
    <div id='tabFiltro-4' onclick="muestraPanelTabToogle('panelFiltro-4','tabFiltro-4')" class="small-2 columns inactive-tab no-border"><?=FILTROS_AVANZADOS;?></div>
    
    
</div>

<hr class="row hr-filtro-bold" >

<div class="contenedor-panels row">
    <div class="inactive-panel panel-filtro-der3" id="panelFiltro-1">
        <ul class="submenu-filtros" id="filtros-modalidad-cursos">
          <li id="filtro-modalidad-cursos-1"><a href="javascript:agregaFiltroCurso('modalidad',0,'filtro-modalidad-cursos-1',<?=$parametros;?>);"><?=TODOS;?></a></li>  
          <li id="filtro-modalidad-cursos-2"><a href="javascript:agregaFiltroCurso('modalidad',1,'filtro-modalidad-cursos-2',<?=$parametros;?>);"><?=PRESENCIAL;?></a></li>
          <li id="filtro-modalidad-cursos-3"><a href="javascript:agregaFiltroCurso('modalidad',2, 'filtro-modalidad-cursos-3',<?=$parametros;?>);"><?=ONLINE;?></a></li>
          <li id="filtro-modalidad-cursos-4"><a href="javascript:agregaFiltroCurso('modalidad',3, 'filtro-modalidad-cursos-4',<?=$parametros;?>);"><?=SEMIPRESENCIAL;?></a></li>
        </ul>
    </div>
    <!---
    <div class="inactive-panel" id="panelFiltro-2">
        <ul class="submenu-filtros" id="filtros-tipo-cursos">
          <li id="filtro-tipo-cursos-1"><a href="javascript:agregaFiltroCurso('tipo',0, 'filtro-tipo-cursos-1',<?=$parametros;?>);"><?//=TODOS;?></a></li>  
          <li id="filtro-tipo-cursos-2"><a href="javascript:agregaFiltroCurso('tipo',1, 'filtro-tipo-cursos-2',<?=$parametros;?>);"><?//=CURSO;?></a></li>
          <li id="filtro-tipo-cursos-3"><a href="javascript:agregaFiltroCurso('tipo',2, 'filtro-tipo-cursos-3',<?=$parametros;?>);"><?//=LICENCIATURA;?></a></li>
          <li id="filtro-tipo-cursos-4"><a href="javascript:agregaFiltroCurso('tipo',3, 'filtro-tipo-cursos-4',<?=$parametros;?>);"><?//=MAESTRIA;?></a></li>
          <li id="filtro-tipo-cursos-5"><a href="javascript:agregaFiltroCurso('tipo',4, 'filtro-tipo-cursos-5',<?=$parametros;?>);"><?//=TALLER;?></a></li>
          <li id="filtro-tipo-cursos-6"><a href="javascript:agregaFiltroCurso('tipo',5, 'filtro-tipo-cursos-6',<?=$parametros;?>);"><?//=DIPLOMADO;?></a></li>
          <li id="filtro-tipo-cursos-7"><a href="javascript:agregaFiltroCurso('tipo',6, 'filtro-tipo-cursos-7',<?=$parametros;?>);"><?//=DOCTORADO;?></a></li>
          <li id="filtro-tipo-cursos-8"><a href="javascript:agregaFiltroCurso('tipo',7, 'filtro-tipo-cursos-8',<?=$parametros;?>);"><?//=CERTIFICACION;?></a></li>
        </ul>
    </div>
    ---->
    <div class="inactive-panel panel-filtro-der2" id="panelFiltro-3">
        <ul class="submenu-filtros" id="filtros-ordenamiento-cursos">
            <li id="filtro-ordenamiento-cursos-1"><a href="javascript:agregaFiltroCurso('ordenamiento',0, 'filtro-ordenamiento-cursos-1',<?=$parametros;?>);"><?=POR_PRECIO_ASCENDENTE;?></a></li>
            <li id="filtro-ordenamiento-cursos-2"><a href="javascript:agregaFiltroCurso('ordenamiento',1, 'filtro-ordenamiento-cursos-2',<?=$parametros;?>);"><?=POR_PRECIO_DESCENDENTE;?></a></li>
            <li id="filtro-ordenamiento-cursos-3"><a href="javascript:agregaFiltroCurso('ordenamiento',2, 'filtro-ordenamiento-cursos-3',<?=$parametros;?>);"><?=POR_VALORACION_ASCENDENTE;?></a></li>
            <li id="filtro-ordenamiento-cursos-4"><a href="javascript:agregaFiltroCurso('ordenamiento',3, 'filtro-ordenamiento-cursos-4',<?=$parametros;?>);"><?=POR_VALORACION_DESCENDENTE;?></a></li>
            <li id="filtro-ordenamiento-cursos-5"><a href="javascript:agregaFiltroCurso('ordenamiento',4, 'filtro-ordenamiento-cursos-5',<?=$parametros;?>);"><?=POR_FECHA_INICIO_ASCENDENTE;?></a></li>
            <li id="filtro-ordenamiento-cursos-6"><a href="javascript:agregaFiltroCurso('ordenamiento',5, 'filtro-ordenamiento-cursos-6',<?=$parametros;?>);"><?=POR_FECHA_INICIO_DESCENDENTE;?></a></li>
            <li id="filtro-ordenamiento-cursos-7"><a href="javascript:agregaFiltroCurso('ordenamiento',6, 'filtro-ordenamiento-cursos-7',<?=$parametros;?>);"><?=POR_DURACION_ASCENDENTE;?></a></li>
            <li id="filtro-ordenamiento-cursos-8"><a href="javascript:agregaFiltroCurso('ordenamiento',7, 'filtro-ordenamiento-cursos-8',<?=$parametros;?>);"><?=POR_DURACION_DESCENDENTE;?></a></li>
        </ul>     
    </div>
    <div class="inactive-panel panel-filtro-der1" id="panelFiltro-4" >
        <div class="row">
            <div class="small-7 columns filtros-rango">
                <label for="amount"><?=PRECIO;?>:</label>                
                <div id="slider-precio" class="slider-bar"></div>
                <!---<input class="input-rango" type="text" id="amount" readonly >--->
                <div id="valor-slider" class="valor-rango"></div>    
            </div>
            <div class="small-5 columns" id="filtros-calificacion-cursos">
                <div  id="filtro-calificacion-cursos-1" class="row" onclick="javascript:agregaFiltroCurso('calificacion',1, 'filtro-calificacion-cursos-1',<?=$parametros;?>);">
                    <div class="small-2 columns no-margin"><img src="<?=$pathImagenes.$rate_full;?>"></div>
                    <div class="small-2 columns no-margin"><img src="<?=$pathImagenes.$rate_full;?>"></div>
                    <div class="small-2 columns no-margin"><img src="<?=$pathImagenes.$rate_full;?>"></div>
                    <div class="small-2 columns no-margin"><img src="<?=$pathImagenes.$rate_full;?>"></div>
                    <div class="small-4 columns no-margin"><?=O_MAS;?></div>
                </div>
                <div id="filtro-calificacion-cursos-2" class="row" onclick="javascript:agregaFiltroCurso('calificacion',2, 'filtro-calificacion-cursos-2',<?=$parametros;?>);">
                    <div class="small-2 columns no-margin"><img src="<?=$pathImagenes.$rate_full;?>"></div>
                    <div class="small-2 columns no-margin"><img src="<?=$pathImagenes.$rate_full;?>"></div>
                    <div class="small-2 columns no-margin"><img src="<?=$pathImagenes.$rate_full;?>"></div>
                    <div class="small-2 columns no-margin"><img src="<?=$pathImagenes.$rate_empty;?>"></div>
                    <div class="small-4 columns no-margin"><?=O_MAS;?></div>
                </div>
                <div id="filtro-calificacion-cursos-3" class="row" onclick="javascript:agregaFiltroCurso('calificacion',3, 'filtro-calificacion-cursos-3',<?=$parametros;?>);">
                    <div class="small-2 columns no-margin"><img src="<?=$pathImagenes.$rate_full;?>"></div>
                    <div class="small-2 columns no-margin"><img src="<?=$pathImagenes.$rate_full;?>"></div>
                    <div class="small-2 columns no-margin"><img src="<?=$pathImagenes.$rate_empty;?>"></div>
                    <div class="small-2 columns no-margin"><img src="<?=$pathImagenes.$rate_empty;?>"></div>
                    <div class="small-4 columns no-margin"><?=O_MAS;?></div>
                </div>
                <div id="filtro-calificacion-cursos-4" class="row" onclick="javascript:agregaFiltroCurso('calificacion',4, 'filtro-calificacion-cursos-4',<?=$parametros;?>);">
                    <div class="small-2 columns no-margin"><img src="<?=$pathImagenes.$rate_full;?>"></div>
                    <div class="small-2 columns no-margin"><img src="<?=$pathImagenes.$rate_empty;?>"></div>
                    <div class="small-2 columns no-margin"><img src="<?=$pathImagenes.$rate_empty;?>"></div>
                    <div class="small-2 columns no-margin"><img src="<?=$pathImagenes.$rate_empty;?>"></div>
                    <div class="small-4 columns no-margin"><?=O_MAS;?></div>
                </div>           
            </div>
        </div>    
    </div>
</div>
    <input type="hidden"  id="filtro-cursos-modalidad" value=-1>
    <!---<input type="hidden" id="filtro-cursos-tipo" value=-1>--->
    <input type="hidden" id="filtro-cursos-ordenamiento" value=-1>
    <input type="hidden" id="filtro-cursos-calificacion" value=-1>
    <input type="hidden" id="filtro-precios-min" value=<?=$precio_min;?>>
    <input type="hidden" id="filtro-precios-max" value=<?=$precio_max;?>>      

<script>

$(function() { 
    $( "#slider-precio" ).slider({
        range: true,
        min: <?=$precio_min;?>,
        max: <?=$precio_max;?>,
        values: [ <?=$precio_ini_min;?>, <?=$precio_ini_max;?> ],
        slide: function( event, ui ) {
        //$( "#amount" ).val( "$" + ui.values[ 0 ] + " - $" + ui.values[ 1 ] );
        
        $( "#valor-slider" ).html("$" + ui.values[ 0 ] + " - $" + ui.values[ 1 ]);
        $( "#filtro-precios-min" ).val(ui.values[ 0 ]);
        $( "#filtro-precios-max" ).val(ui.values[ 1 ]);
    }
    });
   // $( "#amount" ).val( "$" + $( "#slider-precio" ).slider( "values", 0 ) + " - $" + $( "#slider-precio" ).slider( "values", 1 ) );
    $( "#valor-slider" ).html( "$" + $( "#slider-precio" ).slider( "values", 0 ) + " - $" + $( "#slider-precio" ).slider( "values", 1 ) );
    
    
});

$( "#slider-precio").on('slidestop', function( event ) {
    aplicaFiltros(<?=$parametros;?>);
});

</script>



