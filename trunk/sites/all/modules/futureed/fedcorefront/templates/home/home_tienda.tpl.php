<div class="row pagina-front home " id="home_tienda">
	<div class="small-12 columns text-center">
		<h3 class="complementario-verde-2"><?= t('Tienda en línea')?></h3>
	</div>
	<div class="small-12 columns">
		<div><?= t('Lorem Ipsum es simplemente el texto de relleno de las imprentas y archivos de texto.')?></div>
		<div><?= t('Lorem Ipsum es simplemente el texto de relleno de las imprentas.')?></div>
		<div><a href="#"><?= t('Busca más productos')?></a> | <a href="#"><?= t('Crea tu Producto')?></a></div>
	</div>
	<div class="small-12 columns" id="snippet_productos">
		<!--Snippet Productos-->
		<?php
		/*
		$block = module_invoke('fedcorefront', 'block_view', 'carrusel-productos');
		print render($block['content']); 
		*/
		?>
		<!--**-->
	</div>


	<div class="small-12 columns home-resaltado text-center" id="crear_cursos">
		<div>
			<h4 ><?= PRODUCTOS_INVITACION ?></h4>
		</div>

		<div class="btn-complementario-verde-2">
			<input type="button"  value="<?= PRODUCTOS_BOTON1 ?>">
		</div>

	</div>
</div>