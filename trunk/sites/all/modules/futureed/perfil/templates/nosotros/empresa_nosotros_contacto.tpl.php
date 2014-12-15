<?php

define ("INFO_NOSOTROS_TXT1", t('CONTACTO'));
define ("", t(''));
define ("", t(''));
define ("", t(''));
define ("", t(''));
define ("", t(''));

?>

<style type="text/css">
#sobre_nosotros{
    background-color: #F5F5F5;
    margin: 0;
    padding: 0;
}

#titulo_sobre_nosotros{
    background-color: #D85034;
    color: #FFFFFF;
}
</style>

<div class="row" id="sobre_nosotros">
	<h5 id="titulo_sobre_nosotros"><?= INFO_NOSOTROS_TXT1;?></h5>

    <b><?= t('Dirección');?></b> 
    <p><?= $item[0]['calc_usuario_direccion'];?></p>

	
	<b><?= t('Telefono');?></b> 
    <p><?= $item[0]['field_empresa_telefono'];?></p>
    
	<b><?= t('Correo Electronico');?></b> 
    <p><?= $item[0]['field_empresa_correo'];?></p>
    
	<b><?= t('Sitio web');?></b> 
    <a href="<?= $item[0]['field_usuario_sitio_web'];?>"><p><?= $item[0]['field_usuario_sitio_web'];?></p></a>

    <h5><?= t('Redes sociales');?></h5>
    <div class="large-12 columns">
    	<a href="<?= $item[0]['field_usuario_url_facebook'];?>"><img src="http://placehold.it/30x30"> <?= $item[0]['field_usuario_username_facebook'];?></a>
    </div>
    <div class="large-12 columns">
    	<a href="<?= $item[0]['field_usuario_url_twitter'];?>"><img src="http://placehold.it/30x30"> <?= $item[0]['field_usuario_username_twitter'];?></a>
    </div>
    <div class="large-12 columns">
    	<a href="<?= $item[0]['field_usuario_url_linkedin'];?>"><img src="http://placehold.it/30x30"> <?= $item[0]['field_usuario_username_linkedin'];?></a>
    </div>
    <div class="large-12 columns">
    	<a href="<?= $item[0]['field_usuario_url_google_plus'];?>"><img src="http://placehold.it/30x30"> <?= $item[0]['field_usuario_username_google'];?></a>
    </div>
</div>
