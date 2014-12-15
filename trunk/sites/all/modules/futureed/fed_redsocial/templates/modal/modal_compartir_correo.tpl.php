<script type="text/javascript">
jQuery(function($) {
    jQuery("#edit-compartir-correo-boton").prop("type", "button");
});

jQuery(function($) {
    console.log("jQuery cargado exitosamente");
});
</script>

<!--* Modal - Compartir Correo *-->
<div id="compartir-correo" class="reveal-modal" data-reveal>
  
    <div class="row">
        <h5><?=t('Compartir por Correo Electronico'); ?></h5>
        <hr>
        <div class="small-3 columns">
            <img src="<?= $item[0]['imagen']; ?>">
        </div>
        <div class="small-9 columns">
            <p><?= $item[0]['nombre_canal']; ?></p>
            <p><?=t('Por')?>: <?= $item[0]['marca']; ?></p>
            <p><?=t('Liga')?>: <a href="#">(path)</a></p>
        </div>
        <hr>
        <div class="small-6 columns">
            <?php $compartirCorreo = drupal_get_form('modal_compartir_correo_form');?>
            <?php print drupal_render($compartirCorreo);?>
        </div>
    </div>
  
    <a class="close-reveal-modal">&#215;</a>
</div>