<?php

define ("INFO_PERSO_TXT1", t('INFORMACIÓN PERSONAL'));
define ("INFO_PERSO_TXT2", t('Fecha de nacimiento'));
define ("INFO_PERSO_TXT3", t('CONTACTO'));
define ("INFO_PERSO_TXT4", t('Correo de contacto'));
define ("INFO_PERSO_TXT5", t('Telefono'));
define ("INFO_PERSO_TXT6", t('Telefono oficina'));
define ("INFO_PERSO_TXT7", t('Telefono móvil'));
define ("INFO_PERSO_TXT8", t('Skype'));
define ("INFO_PERSO_TXT9", t('Facebook'));
define ("INFO_PERSO_TXT10", t('Google hangouts'));
define ("INFO_PERSO_TXT11", t('Sitio web'));
define ("INFO_PERSO_TXT12", t('Redes Sociales'));

?>

<style type="text/css">
#informacion_Personal{
	background-color: #F5F5F5;
	margin: 0;
	padding: 0;
}

#titulo_info_perso{
	background-color: #D85034;
	color: #FFFFFF;
}
</style>

<div class="row" id="informacion_Personal">
	<h5 id="titulo_info_perso"><?= INFO_PERSO_TXT1;?></h5>

	<?php if ($item[0]['field_usuario_privacidad_persona'] == 1) {?>
    <b><?= INFO_PERSO_TXT2;?></b> 
    <p><?= $item[0]['field_usuario_fecha_nacimiento'];?></p>
    <?php }?>

	<h5><b><?= INFO_PERSO_TXT3;?></b></h5>

	<?php if ($item[0]['field_usuario_privacidad_contact'] == 1) {?>
	<b><?= INFO_PERSO_TXT4;?></b> 
    <p><?= $item[0]['field_usuario_correo'];?></p>
    
	<b><?= INFO_PERSO_TXT5;?></b> 
    <p><?= $item[0]['field_usuario_telefono_casa'];?></p>
    
    	
	<b><?= INFO_PERSO_TXT6;?></b> 
    <?php if ($item[0]['field_usuario_telefono_oficina'] == TRUE) {?>
    <p><?= $item[0]['field_usuario_telefono_oficina'];?></p>
    <?php }?>
    
	<b><?= INFO_PERSO_TXT7;?></b> 
    <p><?= $item[0]['field_usuario_telefono_otro'];?></p>
    <?php }?>

    <?php if ($item[0]['field_usuario_privacidad_social'] == 1) {?>
    <b><?= INFO_PERSO_TXT8;?></b> 
    <p><?= $item[0]['field_usuario_username_skype'];?></p>

    <b><?= INFO_PERSO_TXT9;?></b> 
    <p><?= $item[0]['field_usuario_username_facebook'];?></p>

    <b><?= INFO_PERSO_TXT10;?></b> 
    <p><?= $item[0]['field_usuario_username_google'];?></p>

	<b><?= INFO_PERSO_TXT11;?></b> 
    <p><?= $item[0]['field_usuario_sitio_web'];?></p>        

    <h5><?= INFO_PERSO_TXT12;?></h5>
    <div class="large-12 columns">
    	<a href="<?= $item[0]['field_usuario_url_facebook'];?>"><img src="http://placehold.it/30x30"> <?= $item[0]['field_usuario_url_facebook'];?></a>
    </div>
    <div class="large-12 columns">
    	<a href="<?= $item[0]['field_usuario_url_linkedin'];?>"><img src="http://placehold.it/30x30"> <?= $item[0]['field_usuario_url_linkedin'];?></a>
    </div>
    <div class="large-12 columns">
    	<a href="<?= $item[0]['field_usuario_url_twitter'];?>"><img src="http://placehold.it/30x30"> <?= $item[0]['field_usuario_url_twitter'];?></a>
    </div>
    <div class="large-12 columns">
    	<a href="<?= $item[0]['field_usuario_url_google_plus'];?>"><img src="http://placehold.it/30x30"> <?= $item[0]['field_usuario_url_google_plus'];?></a>
    </div>
    <?php }?>
</div>
