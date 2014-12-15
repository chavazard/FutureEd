<?php

define ("INFO_PROF_TXT1", t('INFORMACIÓN PROFESIONAL'));
define ("INFO_PROF_TXT2", t('Empresa'));
define ("INFO_PROF_TXT3", t('Titulo o puesto'));
define ("INFO_PROF_TXT4", t('INFORMACIÓN ACADEMICA'));
define ("INFO_PROF_TXT5", t('Escuela'));
define ("INFO_PROF_TXT6", t('Estudios'));

?>

<style type="text/css">
#informacion_Profesional{
	background-color: #FFFFFF;
	margin: 0;
	padding: 0;
	border: 1px solid #F5F5F5;
}

#titulo_info_profe{
	background-color: #44B4C5;;
	color: #FFFFFF;
}
</style>
<div class="row" id="informacion_Profesional">
	<h5 id="titulo_info_profe">;<?= INFO_PROF_TXT1;?></h5>
	<?php foreach ($item[0]['array_usuario_info_prof'] as $dato[0]) {?>
    <div class="large-6 columns">
		<b><?= INFO_PROF_TXT2;?></b> 
    	<p><?= $dato[0]['field_usuario_empresa'];?></p>
    </div>
    <div class="large-6 columns">
        <b><?= INFO_PROF_TXT3;?></b> 
        <p><?= $dato[0]['field_usuario_puesto'];?></p> 
        <p><?= $dato[0]['field_usuario_puesto_inicio'];?> - <?= $dato[0]['field_usuario_puesto_fin'];?></p>  
    </div>
	<?}?>

	<h5><b><?= INFO_PROF_TXT4;?></b></h5>
	<?php foreach ($item[0]['array_usuario_info_academi'] as $dato[0]) {?>
    <div class="large-6 columns">
		<b><?= INFO_PROF_TXT5;?></b> 
    	<p><?= $dato[0]['field_usuario_escuela'];?></p>
    </div>
    <div class="large-6 columns">
        <b><?= INFO_PROF_TXT6;?></b> 
        <p><?= $dato[0]['field_usuario_estudios'];?></p> 
    </div>
	<?}?> 

</div>
