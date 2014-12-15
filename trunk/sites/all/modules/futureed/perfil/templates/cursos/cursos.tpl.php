<div class="row">
	<div class="large-6 columns">
		<div id='tab-1' onclick="muestraPanelTab('panel-1', this.id,'')" class="row tab active-tab"><?= CURSOS_COMPRADOS;?></div>
    </div>
    <div class="large-6 columns">
        <div id='tab-2' onclick="muestraPanelTab('panel-2', this.id,'')" class="row tab inactive-tab"><?= CURSOS_CREADOS;?></div>
    </div>         
</div>
<div class="contenedor-panels row">
    <div class="inactive-panel" id="panel-1">

        <div class="large-2 columns">
            <div id='tabB-1' onclick="muestraPanelTab('panelB-1', this.id, 'anidado');callAjax('panelB-1','show_cursos_comprados_actuales','uid: 0, pagina: 1, div_contenedor: \'panelB-1\'');" class="row tab-anidado active-tab-anidado"><?= CURSOS_ACTUALES;?></div>
        </div>
    	<div class="large-2 columns">
            <div id='tabB-2' onclick="muestraPanelTab('panelB-2', this.id, 'anidado');callAjax('panelB-2','show_cursos_comprados_pasados','uid: 0, pagina: 1, div_contenedor: \'panelB-2\'');" class="row tab-anidado inactive-tab-anidado"><?= CURSOS_PASADOS;?></div>
        </div>
        <div class="large-6 columns">
            <div id='tabB-3' onclick="muestraPanelTab('panelB-3', this.id, 'anidado');callAjax('panelB-3','show_cursos_comprados_tomar','uid: 0, pagina: 1, div_contenedor: \'panelB-3\'');;" class="row tab-anidado inactive-tab-anidado"><?= CURSOS_TOMAR;?></div>
        </div>
        <?php print drupal_render(drupal_get_form('cursos_comprados_comprados_form'));?>   

        <div class="contenedor-panels-anidado">
            <div class="active-panel-anidado" id="panelB-1">
            </div>
            <div class="active-panel-anidado" id="panelB-2">
            </div> 
            <div class="active-panel-anidado" id="panelB-3" >
            </div>        
        </div>        
    </div>
    <div class="inactive-panel" id="panel-2"> 

        <div class="large-2 columns">
            <div id='tabC-1' onclick="muestraPanelTab('panelC-1', this.id, 'anidado');callAjax('panelC-1','show_cursos_creados_todos','uid: 0, pagina: 1, div_contenedor: \'panelC-1\'');" class="row tab-anidado active-tab-anidado"><?= TODOS_CURSOS;?></div>
        </div>
    	<div class="large-2 columns">
            <div id='tabC-2' onclick="muestraPanelTab('panelC-2', this.id, 'anidado');callAjax('panelC-2','show_cursos_creados_actuales','uid: 0, pagina: 1, div_contenedor: \'panelC-2\'');" class="row tab-anidado inactive-tab-anidado"><?= CURSOS_ACTUALES;?></div>
        </div>
        <div class="large-6 columns">
            <div id='tabC-3' onclick="muestraPanelTab('panelC-3', this.id, 'anidado');callAjax('panelC-3','show_cursos_creados_pasados','uid: 0, pagina: 1, div_contenedor: \'panelC-3\'');" class="row tab-anidado inactive-tab-anidado"><?= CURSOS_PASADOS;?></div>
        </div> 
        <?php print drupal_render(drupal_get_form('cursos_comprados_creados_form'));?>    

        <div class="contenedor-panels-anidado">
            <div class="active-panel-anidado" id="panelC-1">
            </div>
            <div class="inactive-panel-anidado" id="panelC-2">           
            </div> 
            <div class="inactive-panel-anidado" id="panelC-3" >
            </div>        
        </div>                   
    </div>     
</div>