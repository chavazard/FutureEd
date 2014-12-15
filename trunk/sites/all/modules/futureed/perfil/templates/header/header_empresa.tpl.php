<?php print_r($wildcard);?>
<div class="row header-empresa">

    <div class="large-3 columns">
        <img src="<?= $item[0]['field_usuario_imagen'];?>">
    </div>

    <div class="large-8 columns">
        <div class="large-12 columns">
            <?= $item[0]['calc_usuario_nombre']; ?>
            <?php if ($item[0]['field_usuario_verificado'] == TRUE) {?>
                <img src="http://placehold.it/20x20">
            <?php }?>
        </div>
        <div class="large-12 columns"><?= $item[0]['field_usuario_username']; ?></div>
    
        <div class="small-4 columns">
            <?= t('Seguidores'); ?><a href="#"><?= $item[0]['field_usuario_numero_seguidores']?></a>
        </div>
        <div class="small-4 columns">
            <?= t('Siguiendo'); ?><a href="#"><?= $item[0]['field_usuario_numero_seguidos']?>
        </div>
        <div class="small-4 columns">
            <?php foreach($item[0]['field_usuario_roles'] AS $rol) { ?>
                <?php if ($rol['rol1'] == 1) {?>
                <a href="#"><img src="http://placehold.it/20x20"></a>   
                <?php }?>
                <?php if ($rol['rol2'] == 2) {?>
                <a href="#"><img src="http://placehold.it/20x20"></a>   
                <?php }?>
                <?php if ($rol['rol3'] == 3) {?>
                <a href="#"><img src="http://placehold.it/20x20"></a>   
                <?php }?>
                <?php if ($rol['rol4'] == 4) {?>
                <a href="#"><img src="http://placehold.it/20x20"></a>   
                <?php }?>
            <?php } ?>  
        </div>
    </div>

    <div class="large-1 columns">
        <a href="javascript:void(0)" onclick="console.log('Agregar');console.log('<?= $item[0]['uid']?>')" class="action">
            <img src="http://placehold.it/30x30">
        </a>
        <a href="javascript:void(0)" onclick="console.log('Enviar mensaje');console.log('<?= $item[0]['uid']?>')" class="action">
            <img src="http://placehold.it/30x30">
        </a>
        <a href="javascript:void(0)" onclick="console.log('Opciones');console.log('<?= $item[0]['uid']?>');switchMostrarElemento('usuario_opciones');" class="action">
            <img src="http://placehold.it/30x30">
        </a>
    </div>
    
    <div class="large-12 columns">
        <div class="small-2 columns">
            <div id='ta-1' onclick="muestraPanelTab('panell-1', this.id,'');" class="row tab active-tab"><?= l('Informacion', drupal_get_path_alias('empresa/'.$wildcard).'/informacion')?></div>
        </div>
        <div class="small-2 columns">
            <div id='ta-2' onclick="muestraPanelTab('panell-3', this.id,'');" class="row tab inactive-tab"><?= l('Nosotros', drupal_get_path_alias('empresa/'.$wildcard).'/nosotros')?></div>
        </div>
        <div class="small-2 columns">
            <div id='ta-3' onclick="muestraPanelTab('panell-2', this.id,'');" class="row tab inactive-tab"><?= l('Cursos', drupal_get_path_alias('empresa/'.$wildcard).'/cursos')?></div>
        </div>
        <div class="small-2 columns">
            <div id='ta-4' onclick="muestraPanelTab('panell-4', this.id,'');" class="row tab inactive-tab"><?= l('Canales', drupal_get_path_alias('empresa/'.$wildcard).'/canales')?></a></div>
        </div>
        <div class="small-2 columns">
            <div id='ta-5' onclick="muestraPanelTab('panell-5', this.id,'');" class="row tab inactive-tab"><?= l('Grupos', drupal_get_path_alias('empresa/'.$wildcard).'/grupos')?></div>
        </div>
        <div class="small-2 columns">
            <div id='ta-6' onclick="muestraPanelTab('panell-6', this.id,'');" class="row tab inactive-tab"><?= l('Productos', drupal_get_path_alias('empresa/'.$wildcard).'/productos')?></div>
        </div>            

        <div class="contenedor-panels row">
            <div class="inactive-panel" id="panell-1">    
            </div>
            <div class="inactive-panel" id="panell-2">                         
            </div>
            <div class="inactive-panel" id="panell-3">                         
            </div>
            <div class="inactive-panel" id="panell-4">                         
            </div>
            <div class="inactive-panel" id="panell-5">                         
            </div>
            <div class="inactive-panel" id="panell-6">                         
            </div> 
        </div>
    </div>

</div>