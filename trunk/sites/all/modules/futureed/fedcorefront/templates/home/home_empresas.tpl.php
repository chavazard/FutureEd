

<div class="row pagina-front home" id="home_empresas">
	<div class="small-12 columns text-center ">
		<h3 class="secundario-azul-2"><?= EMPRESAS ?></h3>
	</div>
	<div class="small-12 columns">
		<div><?= EMPRESAS_TEXTO1 ?></div>
		<div><?= EMPRESAS_TEXTO2 ?></div>
		<div><a href="#"><?= EMPRESAS_LINK1 ?></a> | <a href="#"><?= EMPRESAS_LINK2 ?></a></div>
	</div>
	<div class="small-12 columns" id="snippet_empresas">
		<!--Snippet Empresas-->
		<?php

		$block = module_invoke('fedcorefront', 'block_view', 'carrusel-empresas');
		print render($block['content']); 
		
		?>
		<!--**-->
	</div>
	<div class="small-12 columns text-center" id="crear_cursos">
		<div>
			<h4><?= EMPRESAS_INVITACION ?></h4>
		</div>

		<div class="btn-secundario-azul-2">
			<input type="button"  value="<?= EMPRESAS_BOTON1 ?>">
		</div>

	</div>
</div>