<div class='row contenedorPaginacion'>
    <div class="small-12 small-centered columns paginacion text-center">        
        <?php if ($pagina > 1) {?>
            <div class="elementoPaginacion" onclick="callAjax('<?=$contenedorAjax;?>','<?=$funcionAjax;?>','<?=$parametrosAjax;?>, div_contenedor: \'<?=$contenedorAjax?>\', pagina: 1');">&lt;&lt;</div>
            <div class="elementoPaginacion" onclick="callAjax('<?=$contenedorAjax;?>','<?=$funcionAjax;?>','<?=$parametrosAjax;?>, div_contenedor: \'<?=$contenedorAjax?>\', pagina:<?=$pagina-1;?>');">&lt;</div>            
        <?php } else { ?>
            <div class="elementoPaginacionInactivo">&lt;</div>
            <div class="elementoPaginacionInactivo">&lt;&lt;</div> 
        <?php } ?>
        <?php for ($i=1;$i<=$totalPaginas;$i++) {
            if ($pagina != $i) { ?>
                <div class="elementoPaginacion" style="display: inline" onclick="callAjax('<?=$contenedorAjax;?>','<?=$funcionAjax;?>','<?=$parametrosAjax;?>, div_contenedor: \'<?=$contenedorAjax?>\', pagina:<?=$i;?>');"><?=$i;?></div>
            <?php } else { ?>
                <div class="elementoPaginacionActual"><?=$i;?></div>
            <?php } ?>
        <?php } ?>
        <?php if ($pagina < $totalPaginas) {?>
            <div class="elementoPaginacion" onclick="callAjax('<?=$contenedorAjax;?>','<?=$funcionAjax;?>','<?=$parametrosAjax;?>, div_contenedor: \'<?=$contenedorAjax?>\', pagina:<?=$pagina+1;?>');">&gt;</div>
            <div class="elementoPaginacion" onclick="callAjax('<?=$contenedorAjax;?>','<?=$funcionAjax;?>','<?=$parametrosAjax;?>, div_contenedor: \'<?=$contenedorAjax?>\', pagina:<?=$totalPaginas;?>');">&gt;&gt;</div>
        <?php } else { ?>
            <div class="elementoPaginacionInactivo">&gt;</div>
            <div class="elementoPaginacionInactivo">&gt;&gt;</div>
        <?php } ?>
        
    </div>
</div>
