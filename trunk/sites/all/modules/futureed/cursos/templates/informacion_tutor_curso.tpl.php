<h3><?=SOBRE_TUTOR;?></h3>
<?php foreach($info_tutor AS $tutor) {?>
    <div class="row">
        <div class="large-3 columns">
            <img src="<?= $tutor['field_tutor_imagen']; ?>">
        </div>
        <div class="large-9 columns">
            <?php //var_dump($info_tutor['info-tutor']); ?>
            <a href="<?= $info_tutor['link_nombre_tutor']; ?>"><?= $tutor['calc_nombre_tutor']; ?></a><br>
            <?= $tutor['field_usuario_empresa']; ?><br>
            <div class="row">
                <div class="large-4 columns">
                    <a href="<?= $tutor['uid_tutor']; ?>" class="btn-seguir-usuario">seg</a>
                </div>
                <div class="large-4 columns">
                    <a href="<?= $tutor['uid_tutor']; ?>" class="btn-mensaje-usuario">msg</a>
                </div>
                <div class="large-4 columns">
                    &nbsp;
                </div>    
            </div>
        </div>                    
    </div>
    <hr>
<?php } ?>    