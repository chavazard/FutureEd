<div class="row">
	<div class="large-4 columns">
		<div id='tab-1' onclick="muestraPanelTab('panel-1', this.id,'');callAjax('panel-1','show_mis_canales','nid_canal: 0, pagina: 1, div_contenedor: \'panel-1\'');" class="row tab active-tab"><?=t('Mis Canales');?></div>
    </div>
    <div class="large-4 columns">
        <div id='tab-2' onclick="muestraPanelTab('panel-2', this.id,'');callAjax('panel-2','show_canales_administrar','nid_canal: 0, pagina: 1, div_contenedor: \'panel-2\'');" class="row tab inactive-tab"><?=t('Canales que Administro');?></div>
    </div>
    <div class="large-4 columns">
        <div id='tab-3' onclick="muestraPanelTab('panel-3', this.id,'');callAjax('panel-3','show_crear_canal','nid_canal: 0, pagina: 1, div_contenedor: \'panel-3\'');" class="row tab inactive-tab"><?=t('+ Crear Canal');?></div>
    </div>         
</div>

<div class="contenedor-panels row">

    <div class="active-panel" id="panel-1">
    </div>

    <div class="inactive-panel" id="panel-2">                  
    </div> 

    <div class="inactive-panel" id="panel-3">              
    </div> 
           
</div>