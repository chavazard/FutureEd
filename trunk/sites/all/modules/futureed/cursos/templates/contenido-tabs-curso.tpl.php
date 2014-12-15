<div class="contenedor-panels row">
    <div class="large-12 columns active-panel" id="panel-1">
        <?php if ($info_curso['field_curso_video'] != null) {?>
        <iframe width="100%" height="450" src="<?=$info_curso['field_curso_video'];?>" frameborder="0" allowfullscreen></iframe>
        <?php }?>
        <p>
            <?= $info_curso['field_curso_descripcion']; ?>                
        </p>
        <h3><?= OBJETIVOS_PRINCIPALES; ?></h3>
        <p>
            <?= $info_curso['field_curso_objetivo']; ?>
        </p>
        <h3><?= FECHAS_INICIAR_CURSO; ?></h3>
        <?php
            foreach ($info_curso['field_curso_fechas_imparticion'] as $fecha) {
                print ($fecha.'<br>');
            }
        ?>
        <?php if ($info_curso['field_curso_requerimientos'] != null) { ?>
            <h3><?=REQUISITOS_PREVIOS;?></h3>
            <?=$info_curso['field_curso_requerimientos'];?>
        <?php } ?>
    </div>
    <div class="large-12 columns inactive-panel" id="panel-2">
        <?=$info_curso['field_curso_temario'];?>
        <?php if ($info_curso['field_curso_bibliografia_oficial'] != null) { ?>
            <h3><?=BIBLIOGRAFIA_OFICIAL;?></h3>
            <?=$info_curso['field_curso_bibliografia_oficial'];?>
        <?php } ?>
        <?php if ($info_curso['field_curso_bibliografia_re'] != null) { ?>
            <h3><?=BIBLIOGRAFIA_RECOMENDADA;?></h3>
            <?=$info_curso['field_curso_bibliografia_re'];?>
        <?php } ?>        
    </div>
    <div class="inactive-panel" id="panel-3"  >
        <?=CARGANDO; ?>   
    </div>
    <div class="inactive-panel calificaciones-curso" id="panel-4">
        <div id="resumen-calificacion-curso"></div>
        <h3><?= OPCIONES_UTILES;?></h3>

        <div id="listado-opiniones-curso"></div>
        
    </div>
    <div class="inactive-panel" id="panel-5">
        <?=CARGANDO; ?>
    </div>            
</div>