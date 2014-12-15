<div class="row pagina-front home" id="home_cursos">
	<div class="small-12 columns text-center">
		<h3 class="main-naranja"><?= CURSOS ?></h3>
	</div>
	<div class="small-12 columns ">
		<div><?= CURSOS_TEXTO1 ?></div>
		<div><?= CURSOS_TEXTO1 ?></div>
		<div><a href="#"><?= CURSOS_LINK1 ?></a> | <a href="#"><?= CURSOS_LINK2 ?></a></div>
	</div>
	<div class="small-12 columns" id="snippet_cursos ">
		<!--Snippet Cursos-->
		<?php

		$block = module_invoke('fedcorefront', 'block_view', 'carrusel-cursos');
		print render($block['content']); 
		
		?>
		<!--**-->
	</div>
	<div class="small-12 columns text-center" id="crear_cursos">
		<div>
			<h4><?= CURSOS_INVITACION ?></h4>
		</div>
		<div class="btn-main-naranja">
			<input type="button" value="<?= CURSOS_BOTON1 ?>">
		</div>
	</div>
</div>