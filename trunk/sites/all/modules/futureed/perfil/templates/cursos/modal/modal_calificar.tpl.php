<?php
    define ("MODAL_CALIFICAR_TXT1", t('Cómo evaluarías este curso'));
    define ("MODAL_CALIFICAR_TXT2", t('Elige cuántas manzanitas le otorgarías al profesor'));
?>

<script type="text/javascript">
jQuery(function($) {
    jQuery("#edit-cancelar-calificacion").prop("type", "button");
});

jQuery(function($) {
    console.log("jQuery cargado exitosamente");
});
</script>



<!--**** Modal - Calificar ****-->
<div id="calificar" class="reveal-modal" data-reveal>

    <div class="row">
        <div class="large-12 columns">
            <h5>¿<?= MODAL_CALIFICAR_TXT1; ?>?</h5>
        </div>

        <div id="curso_info"></div>    

        <div class="large-12 columns">
            <b><?= MODAL_CALIFICAR_TXT2; ?></b>
        </div>
        <div class="large-12 columns">
            <?php mostrar_calificacion_estrellas($item["field_curso_calificacion"]);?>
        </div> 

        <div class="small-12 columns">
            <?php print drupal_render(drupal_get_form('curso_calificar_form'));?>
        </div>
    </div>

    <a class="close-reveal-modal">&#215;</a>
</div>