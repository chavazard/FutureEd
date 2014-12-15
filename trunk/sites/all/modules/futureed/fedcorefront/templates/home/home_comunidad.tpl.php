<div class="row pagina-front home " id="home_comunidad">
	<div class="small-12 columns text-center">
		<h3 class="complementario-verde-4"><?= COMUNIDAD ?></h3>
		<h5 class="complementario-verde-4"><?= COMUNIDAD_BIENVENIDA1 ?></h5>
	</div>
	<div class="small-12 columns">
		<div><?= COMUNIDAD_TEXTO1 ?></div>
		<div><?= COMUNIDAD_TEXTO2 ?></div>
		<div><a href="#"><?= COMUNIDAD_LINK1 ?></a> | <a href="#"><?= COMUNIDAD_LINK1 ?></a></div>
	</div>
	<div class="small-12 columns  text-center" id="comunidad">
		<!--Comunidad-->
		<?php

		$block = module_invoke('fedcorefront', 'block_view', 'carrusel-comunidad');
		print render($block['content']); 
		
		?>
		<!--**-->
	</div>
	<div class="small-12 columns home-resaltado text-center" id="invitacion_registro">
		<div>
			<h4><?= COMUNIDAD_INVITACION ?></h4>
		</div>
		<div class="btn-primario">
			<input type="button" value="<?= COMUNIDAD_BOTON1 ?>">
		</div>

	</div>
</div>