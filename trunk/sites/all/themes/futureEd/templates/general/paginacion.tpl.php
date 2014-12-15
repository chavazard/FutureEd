<div class='row contenedorPaginacion' style='margin: auto'>
    <div class="large-12 paginacion">        
        <?php if ($pagina > 1) {?>
            <div class="elementoPaginacion" onclick="jQuery('#<?=$contenedorAjax;?>').load('<?=$path;?>/1');">&lt;&lt;</div>
            <div class="elementoPaginacion" onclick="jQuery('#<?=$contenedorAjax;?>').load('<?= $path?>/<?=$pagina-1;?>');">&lt;</div>            
        <?php } else { ?>
            <div class="elementoPaginacionInactivo">&lt;</div>
            <div class="elementoPaginacionInactivo">&lt;&lt;</div>
        <?php } ?>
        <?php for ($i=1;$i<=$totalPaginas;$i++) {
            if ($pagina != $i) { ?>
                <div class="elementoPaginacion" style="display: inline" onclick="jQuery('#<?=$contenedorAjax;?>').load('<?= $path.'/'.$i;?>');"><?=$i;?></div>
            <?php } else { ?>
                <div class="elementoPaginacionActual"><?=$i;?></div>
            <?php } ?>
        <?php } ?>
        <?php if ($pagina < $totalPaginas) {?>
            <div class="elementoPaginacion" onclick="jQuery('#<?=$contenedorAjax;?>').load('<?= $path?>/<?=$pagina+1;?>');">&gt;</div>
            <div class="elementoPaginacion" onclick="jQuery('#<?=$contenedorAjax;?>').load('<?=$path.'/'.$totalPaginas;?>');">&gt;&gt;</div>
        <?php } else { ?>
            <div class="elementoPaginacionInactivo">&gt;</div>
            <div class="elementoPaginacionInactivo">&gt;&gt;</div>
        <?php } ?>
        
    </div>
</div> 