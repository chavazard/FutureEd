<div class="row">
    <div class="row">

        <div class="small-12 columns">
            <?//php var_dump($item);?>
            <!--<img src="http://placehold.it/100x100">
            <img src="http://placehold.it/1050x180">-->
            <img src="<?= $item[0]['field_canal_imagen']; ?>">
        </div>

    </div>

    <div class="row">

        <div class="small-12 columns">
            <h6><?= $item[0]['field_canal_nombre']; ?></h6>
        </div>
        <div class="small-12 columns">
            <div class="small-3 columns">
                <b><?=CREADOR;?>:</b><u><?= $item[0]['calc_nombre']; ?></u>
                <br><b><?=CATEGORIA_CURSO;?>: </b><u><?= $item[0]['field_canal_categoria']; ?></u>
                <br><b><?=SUBCATEGORIA_CURSO;?>: </b><u><?= $item[0]['field_canal_subcategoria']; ?></u>
            </div>
            <div class="small-7 columns">
                <div class="row">
                    <div class="small-3 columns"><?=DESCRIPCION_CURSO;?>:</div>
                    <div class="small-9 columns">
                        <div><?= $item[0]['descripcion']; ?><a href="#"><?=t('Ver Mas');?>...</a></div>
                    </div>
                </div>
            </div>
            <div class="small-2 columns">
                <div class="row">
                    <b class="small-12 columns"><?t('Compartir')?></b>
                    <div class="small-12 columns">
                        <?php print theme('compartir-redes-sociales'); ?>
                    </div>
                </div>
            </div>
        </div>
    </div>

</div>