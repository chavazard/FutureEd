<hr>
<div class="row">
    <div class="large-1 columns">
        <img src="<?=$item['imagen-usuario'];?>">
    </div>
    <div class="large-11 columns">
        <div>
            <div class="estrellas-curso-usuarios">
                <?php print theme('ver_rate_stars', array('item' => $item['rate'] ));?>
            </div>
            <div class="titulo-calificacion">
                <?=$item['titulo']?>
            </div>
            <div class="fecha-calificacion">
                <?=$item['fecha-calificacion']?>
            </div>
        </div>
        <div class="comentario-positivo">
            <?=$item['comentario-positivo']?>
        </div>
        <div class="comentario-negativo">
            <?=$item['comentario-negativo']?>
        </div>
        <div class="es-util">
            <?= TE_RESULTADO_UTIL_COMENTARIO;?>
            <div class="boton-si">Si</div>
        </div>
    </div>
</div>

