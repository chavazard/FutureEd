<script type="text/javascript">
jQuery(function($) {
    jQuery("#edit-iniciar-sesion-boton1").prop("type", "button");
    jQuery("#edit-iniciar-sesion-boton2").prop("type", "button");
});

jQuery(function($) {
    console.log("jQuery cargado exitosamente");
});
</script>

<!--* Modal - Iniciar Sesion*-->
<div id="iniciar-sesion" class="reveal-modal" data-reveal>
    <div class="row">
        <h5><?=t('Iniciar Sesion');?></h5>
        <div class="small-6 columns">
            <?php $inicioSesion = drupal_get_form('modal_iniciar_sesion_form');?>
            <?php print drupal_render($inicioSesion);?>
        </div>
    </div>
    <a class="close-reveal-modal">&#215;</a>
</div>
