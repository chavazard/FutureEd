<div class="row">
    <div class="small-3 columns">
        <div id='tab-1' onclick="muestraPanelTab('panel-1', this.id,'');callAjax('cursos','show_ver_canal_cursos','nid_curso: 0, pagina: 1, div_contenedor: \'cursos\'');" class="row tab active-tab"><?=t('Cursos');?></div>
    </div>
    <div class="small-3 columns">
        <div id='tab-2' onclick="muestraPanelTab('panel-2', this.id,'');callAjax('equipo','show_ver_canal_equipo','uid: 0, pagina: 1, div_contenedor: \'equipo\'');" class="row tab inactive-tab"><?=t('Equipo');?></div>
    </div>
    <!--<div class="small-2 columns">
        <div id='tab-3' onclick="muestraPanelTab('panel-3', this.id,'');jQuery('#panel-3').load('ver-canal-politicas');" class="row tab inactive-tab"><?=t('Politicas');?></div>
    </div>--> 
    <div class="small-6 columns">
        <div class="row">
            <?php $busqueda = drupal_get_form('busqueda_form');?>
            <?php print drupal_render($busqueda);?>
        </div>
    </div>  
</div>

<div class="contenedor-panels row">
    <div class="inactive-panel" id="panel-1">
        <div class="row">
            <?php $filtros = drupal_get_form('filtros_form');?>
            <?php print drupal_render($filtros);?>
            <div class="small-3 columns">
                <u><?=t('Filtros avanzados');?></u>
            </div>
        </div>
        <h6><?=t('Todos los Cursos');?></h6>
        <div id="cursos"></div>
    </div>
    <div class="inactive-panel" id="panel-2">
        <h6><?=t('Acerca del Canal');?></h6>
        <p><?= $item[0]['acerca_canal'];?></p>
        <hr>
        <h6><?=t('Nuestro Equipo');?></h6>
        <p><?= $item[0]['nuestro_equipo'];?></p>
        <div id="equipo"></div>
    </div> 
    <!--<div class="inactive-panel" id="panel-3">
    </div>-->
</div>


<script type="text/javascript">
jQuery(function($) {
    jQuery("#edit-busqueda-boton").prop("type", "button");
});

jQuery(function($) {
    console.log("jQuery cargado exitosamente");
});
</script>