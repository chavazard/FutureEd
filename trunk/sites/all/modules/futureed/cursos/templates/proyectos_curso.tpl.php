<div>

<?php
    if(is_numeric(arg(1)))
        $pagina = arg(1);
    else
        $pagina = 1;


    $indiceLinea = 0;
    $resultadosPorLinea = 4;
    $totalResultados = count($items['data']);
    $resultadosPorPagina = 4;
    $indiceResultado = 0;
    
    $limiteIni = (($pagina - 1)* $resultadosPorPagina) + 1;
    $limiteSup = $pagina * $resultadosPorPagina;
    $totalPaginas = ceil ($totalResultados/$resultadosPorPagina);
    
    
    foreach($items['data'] as $item){
        $indiceResultado++;
        if ($indiceResultado >= $limiteIni && $indiceResultado <= $limiteSup)
        {
            if ($indiceLinea < $resultadosPorLinea)
                $indiceLinea++;
            else
                $indiceLinea = 1;        
            
            ?>
            <div class="large-<?=  12/$resultadosPorLinea;?> columns end">
                <div class="row">
                    <img src="">
                </div>
                <h3><?= $item['titulo'];?></h3>
                Curso: <a href="#<?= $item['nid'];?>"><?= $item['tituloCurso'];?></a><br>
                <div class="muestraLikes"><?= $item['likes'].'   '. $indiceLinea;?></div>
            </div>
        
    <?php
        }
    }
   
    if ($indiceLinea <= $resultadosPorLinea)
    {
        $diferenciaMostrado = $resultadosPorLinea - $indiceLinea;
        for ($i = 1; $i <= $diferenciaMostrado; $i++)
        {?>
           <div class="large-<?=  12/$resultadosPorLinea;?> columns">&nbsp;</div>
        <?php    
        }
        
    }
    
    ?>
    
    <div class="large-12 paginacion">
        <div class="elementoPaginacion" onclick="jQuery('#panel-3').load('proyectos-curso/1');">&lt;&lt;</div>
        <?php if ($pagina > 1) {?>
            <div class="elementoPaginacion" onclick="jQuery('#panel-3').load('proyectos-curso/<?= $pagina-1;?>');">&lt;</div>
        <?php } else { ?>
            <div class="elementoPaginacionInactivo">&lt;</div>
        <?php } ?>
        <?php for ($i=1;$i<=$totalPaginas;$i++) {?>
            <div class="elementoPaginacion" onclick="jQuery('#panel-3').load('proyectos-curso/<?= $i;?>');"><?=$i;?></div>
        <?php } ?>
        <?php if ($pagina < $totalPaginas) {?>
            <div class="elementoPaginacion" onclick="jQuery('#panel-3').load('proyectos-curso/<?= $pagina+1;?>');">&gt;</div>
        <?php } else { ?>
            <div class="elementoPaginacionInactivo">&gt;</div>
        <?php } ?>
        <div class="elementoPaginacion" onclick="jQuery('#panel-3').load('proyectos-curso/<?=$totalPaginas;?>');">&gt;&gt;</div>
    </div>
    
</div>
