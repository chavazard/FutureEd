<div class="row">
	<div class="large-6 columns">
		<div id='tab-1' onclick="muestraPanelTab('panel-1', this.id,'');callAjax('panel-1','show_siguiendo','uid: 1, pagina: 1, div_contenedor: \'panel-1\'');" class="row tab active-tab"><?=t('Siguiendo');?></div>
    </div>
    <div class="large-6 columns">
        <div id='tab-2' onclick="muestraPanelTab('panel-2', this.id,'');callAjax('panel-2','show_seguidores','uid: 1, pagina: 1, div_contenedor: \'panel-2\'');" class="row tab inactive-tab"><?=t('Seguidores');?></div>
    </div>  
</div>
<div class="row" id="lista_busqueda">
    <?php print drupal_render(drupal_get_form('lista_seguimiento_form'));?>
    <div class="small-7 columns"></div>
</div>
<div class="contenedor-panels row">
    <div class="inactive-panel" id="panel-1">
    </div>
    <div class="inactive-panel" id="panel-2">                  
    </div>     
</div>