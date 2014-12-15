<?php
    if ($item['calificaciones-5-estrella'] > 0)
        $estiloCincoEstrellas = "votosActivo";
    else
        $estiloCincoEstrellas = "votosInactivo";
        
    if ($item['calificaciones-4-estrella'] > 0)
        $estiloCuatroEstrellas = "votosActivo";
    else
        $estiloCuatroEstrellas = "votosInactivo";
        
    if ($item['calificaciones-3-estrella'] > 0)
        $estiloTresEstrellas = "votosActivo";
    else
        $estiloTresEstrellas = "votosInactivo";
        
    if ($item['calificaciones-2-estrella'] > 0)
        $estiloDosEstrellas = "votosActivo";
    else
        $estiloDosEstrellas = "votosInactivo";
        
    if ($item['calificaciones-1-estrella'] > 0)
        $estiloUnaEstrella = "votosActivo";
    else
        $estiloUnaEstrella = "votosInactivo";
        
    $sumaVotos = $item['calificaciones-5-estrella'] + $item['calificaciones-4-estrella' + $item['calificaciones-3-estrella'] + $item['calificaciones-2-estrella'] + $item['calificaciones-1-estrella']];
    $porcentajeCincoEstrellas  = ($item['calificaciones-5-estrella'] * 100) / $sumaVotos;
    $porcentajeCuatroEstrellas = ($item['calificaciones-4-estrella'] * 100) / $sumaVotos;
    $porcentajeTresEstrellas   = ($item['calificaciones-3-estrella'] * 100) / $sumaVotos;
    $porcentajeDosEstrellas    = ($item['calificaciones-2-estrella'] * 100) / $sumaVotos;
    $porcentajeUnaEstrella     = ($item['calificaciones-1-estrella'] * 100) / $sumaVotos;
    
      
?>
 

<div class="resumen-calificaciones-curso">
    <?=t('Todos los comentarios son escritos por alumnos que finalizaron el curso');?>
    <div class="row">
        <div class="large-5 columns" >
            <div class="row">
                <div class="large-5 columns <?=$estiloCincoEstrellas?>">
                    <?=t('5 estrellas');?>        
                </div>
                <div class="large-7 columns">
                    <div class="progress large-12 success"><span class="meter" style="width: <?=$porcentajeCincoEstrellas;?>%"></span></div>                                      
                </div>                
            </div>
            <div class="row">
                <div class="large-5 columns <?=$estiloCuatroEstrellas?>">
                    <?=t('4 estrellas');?>        
                </div>
                <div class="large-7 columns">
                    <div class="progress large-12 success"><span class="meter" style="width: <?=$porcentajeCuatroEstrellas;?>%"></span></div>                                       
                </div>                
            </div>
            <div class="row">
                <div class="large-5 columns <?=$estiloTresEstrellas?>">
                    <?=t('3 estrellas');?>        
                </div>
                <div class="large-7 columns">
                    <div class="progress large-12 success"><span class="meter" style="width: <?=$porcentajeTresEstrellas;?>%"></span></div>                                         
                </div>                
            </div>                 
            <div class="row">
                <div class="large-5 columns <?=$estiloDosEstrellas?>">
                    <?=t('2 estrellas');?>        
                </div>
                <div class="large-7 columns">
                    <div class="progress large-12 success"><span class="meter" style="width: <?=$porcentajeDosEstrellas;?>%"></span></div>                                        
                </div>                
            </div>
            <div class="row">
                <div class="large-5 columns <?=$estiloUnaEstrella?>">
                    <?=t('1 estrella');?>        
                </div>
                <div class="large-7 columns">
                    <div class="progress large-12 success"><span class="meter" style="width: <?=$porcentajeUnaEstrella;?>%"></span></div>                                        
                </div>                
            </div>               
        </div>
        <div class="large-7 columns" >
            <h2><?=t('Calificación promedio');?></h2>
            <?php print theme('ver_rate_stars', array('item' => $item['rate'] ));?>
            
        </div>
    </div>
</div>





