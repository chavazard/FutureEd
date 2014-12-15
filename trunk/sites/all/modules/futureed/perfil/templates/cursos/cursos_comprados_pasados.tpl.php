<div class="large-<?= $anchoColumnas;?> columns end item">
    <div class="item-lista-chica">

        <div>
            <img src="<?= $item['field_curso_imagen']; ?>">
        </div>
        <div class="contenido">
            <div class="row titulo">
                <div class="large-12 columns"><a href="<?= $item['link_curso']; ?>"><h1><?= $item['field_curso_nombre'];?></h1></a></div>
            </div>
            <div class="row info">
                <div class="large-12 columns">
                    <p><?= CANAL;?>: <a href="<?= $item['link_curso_canal']; ?>"><?= $item['field_curso_canal']; ?></a></p>
                    <?php foreach($item['array_curso_tutores'] AS $tutor) { ?>
                    <p><?= TUTOR;?>: <a href="<?= $tutor['link_nombre_tutor']; ?>"><?= $tutor['calc_nombre_tutor']; ?></a></p>
                    <?php } ?>
                </div>
            </div>
            <div class="row info">
                <div class="large-2 columns"><i>PANT.</i></div>
                <div class="large-10 columns"><p><?= $item['field_curso_modalidad']; ?></p></div>
            </div>
            <div class="row info">
                <div class="large-2 columns"><i>CAL.</i></div>
                <div class="large-10 columns">
                    <p><?= INICIA;?>: <?= $item['field_curso_fecha']; ?></p>
                    <p><?= TERMINA;?>: <?= $item['field_curso_fecha_value2']; ?></p>
                </div>
            </div>
            <div class="row contenedor-btn-calificacion">
                <div class="small-6 columns no-margin">
                    <a href="<?= $item['field_curso_url_lms']; ?>" class="btn no-margin"><?= VER_CURSO;?></a>
                </div>
                <div class="small-5 columns no-margin right end contenedor-rated">
                    <? if ($item['field_curso_calificacion'] == NULL) {?>
                    <a class="btn" onClick="callAjax('curso_info','show_cursos_calificar','nid: <?= $item['nid'];?>');" data-reveal-id="calificar"><?= CALIFICAR;?></a>
                    <? } else{?>
                    <?php mostrar_calificacion_estrellas($item['field_curso_calificacion'],$item['field_curso_numero_votos']);?>
                    <? } ?>
                </div>
            </div>
            <hr>
            <div class="foot">
                <p><?= APOYO_FUNDACION; ?></p>
                <img class="thumbnail-avatar" src="<?= $usuario['field_fundacion_imagen'];?>"> <?= $item['field_fundacion_nombre'];?>
            </div>
        </div>

    </div>
</div>