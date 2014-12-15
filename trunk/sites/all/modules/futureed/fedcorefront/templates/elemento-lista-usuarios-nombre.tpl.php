<div class='small-<?= $anchoColumnas;?> columns end'>
    <div style="float: left">
        <?=$item['nombre-usuario'];?>
    </div>
    <div>
        <?php if ($item['usuario-conectado'] == true) {?>
            <div class="marca-conectado"><img src="<?php echo base_path() . 'sites/all/themes/futureEd/images/conectado.jpg'; ?>" ></div>
        <?php }?>
        <img src="<?=$item['avatar-usuario'];?>">
    </div>
</div>