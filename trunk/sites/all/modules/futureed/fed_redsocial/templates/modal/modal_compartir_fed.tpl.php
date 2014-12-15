<script type="text/javascript">
jQuery(function($) {
    $("#edit-compartir-fed-select").change( mostrar );
    mostrar();

    function mostrar() {
        var id = $( "#edit-compartir-fed-select" ).val();
        //console.log(id);
        if (id == "") {
            $("#mensaje_privado_texto1").hide();
            $("#mensaje_privado_texto2").hide();
            $("#boton_busqueda").hide();
            $("#mensaje_privado_campo").hide();
            $("#grupo_select_titulo").hide();
            $("#grupo_select_opciones").hide();
        }
        if (id == "mensaje") {
            $("#mensaje_privado_texto1").show();
            $("#mensaje_privado_texto2").show();
            $("#boton_busqueda").show();
            $("#mensaje_privado_campo").show();
            $("#grupo_select_titulo").hide();
            $("#grupo_select_opciones").hide();
        }
        if (id == "muro") {
            $("#mensaje_privado_texto1").hide();
            $("#mensaje_privado_texto2").hide();
            $("#boton_busqueda").hide();
            $("#mensaje_privado_campo").hide();
            $("#grupo_select_titulo").hide();
            $("#grupo_select_opciones").hide();
        }
        if (id == "grupo") {
            $("#mensaje_privado_texto1").hide();
            $("#mensaje_privado_texto2").hide();
            $("#boton_busqueda").hide();
            $("#mensaje_privado_campo").hide();
            $("#grupo_select_titulo").show();
            $("#grupo_select_opciones").show();
        }
    }
});
</script>

<script type="text/javascript">
jQuery(function($) {
    jQuery("#edit-compartir-fed-boton").prop("type", "button");
});

jQuery(function($) {
    console.log("jQuery cargado exitosamente");
});
</script>

<!--* Modal - Compartir FED *-->
<div id="compartir-fed" class="reveal-modal" data-reveal>

    <div class="row">
        <h5><?=t('Compartir por FED'); ?></h5>
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
            <?php $compartirFED = drupal_get_form('modal_compartir_fed_form');?>
            <?php print drupal_render($compartirFED);?>
        </div>
    </div>

    <a class="close-reveal-modal">&#215;</a>
</div>
