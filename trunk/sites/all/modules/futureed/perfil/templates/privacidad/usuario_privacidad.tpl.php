<?php

define ("PRIVACIDAD_TXT1", "¡Ups! Este usuario es privado");
define ("PRIVACIDAD_TXT2", "Necesitas que te autorice para que puedas ver sus publicaciones y perfil completo");

?>

<style type="text/css">
#usuario_privacidad{
	background-color: #F5F5F5;
}
#usuario_privacidad img{
	padding-top: 100px;
	padding-bottom: 20px
}
#usuario_privacidad p{
	padding-bottom: 100px;
}
</style>

<div class="row text-center" id="usuario_privacidad">
	<img src="http://placehold.it/30x30"><br>
	<b><?= PRIVACIDAD_TXT1; ?></b>
	<p><?= PRIVACIDAD_TXT2; ?>.</p>
</div>