    <?php $nid_curso = 5; ?>

    <div class="row">
        <div class="large-3 columns active-tab" id='tab-1'>
            <div  onclick="muestraPanelTab('panel-1','tab-1','')" class="row tab "><?=INFORMACION_CURSO;?></div>
        </div>
        <div class="large-2 columns" id='tab-2'>
            <div  onclick="muestraPanelTab('panel-2','tab-2','');" class="row tab inactive-tab"><?=TEMARIO;?></div>
        </div>
        <div class="large-2 columns" id='tab-3'>
            <div  onclick="muestraPanelTab('panel-3','tab-3','');callAjax('panel-3','mostrar_proyectos_curso','nid_curso: <?=$nid_curso;?>, pagina: 1, div_contenedor: \'panel-3\'');" class="row tab inactive-tab"><?=PROYECTOS;?></div>
        </div> 
        
        <div class="large-2 columns" id='tab-4'>
            <div  onclick="muestraPanelTab('panel-4','tab-4','');callAjax('resumen-calificacion-curso','mostrar_resumen_calificaciones','nid_curso: <?=$nid_curso;?>, pagina: 1');callAjax('listado-opiniones-curso','mostrar_calificaciones_curso','nid_curso: <?=$nid_curso;?>, pagina: 1, div_contenedor: \'listado-opiniones-curso\'');" class="row tab inactive-tab"><?=t('Calificaciones');?></div>
        </div>
        <div class="large-3 columns" id='tab-5'>
            <div  onclick="muestraPanelTab('panel-5','tab-5','');callAjax('panel-5','print_preguntas_frecuentes','nid_curso: <?=$nid_curso;?>');" class="row tab inactive-tab"><?=PREGUNTAS_FRECUENTES;?></div>
        </div>          
        
    </div>    
    
    
    