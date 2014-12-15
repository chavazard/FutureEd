<div class="large-<?= $anchoColumnas;?> columns end no-padding">
	<div class="item-lista-grande">
		<div class="row busquedaCanales">



			<div class="small-4 columns ">
				<div class="top">
					<a href="javascript:void(0)" onclick="console.log('funciona');console.log('<?= $item['idCanal']?>')" class="action">
						<img src="<?= $item['field_canal_imagen']; ?>">
					</a>
					<img class="main" src="<?= $item['field_canal_imagen']; ?>">
				</div>
			</div>

			<div class="small-8 columns">
				<div class="contenido">


					<div class="row titulo">
						<div class="large-6 columns">
							<h1><?= $item['field_canal_nombre'];?></h1>
						</div>
					</div>

					<div class="row">
						<div class="large-6 columns">
							Creador: <a href="<?= $item['link_canal_creador']; ?>"><?= $item['calc_creador_nombre']; ?></a>
							<?php if ($item['field_usuario_verificado'] == TRUE) {?>
							<img src="http://placehold.it/20x20">
							<?php }?>
							<p>Categoria: <a href="<?= $item['link_canal_categoria']; ?>"><?= $item['field_canal_categoria']; ?></a></p>
							<p>Cursos: <?= $item['calc_numero_cursos']; ?></p>
						</div>
						<div class = "large-6 columns">
							<div class="info">							
							</div>
						</div>
					</div>

					<div class = "row">
						<div class = "large-12 columns">
						</div>
					</div>

					<div class = "row">
						<div class = "large-6 columns">
							<div class = "info">
							</div>
						</div>
						<div class = "large-6 columns">
							<div class = "botones ">
								<a class="btn" value="javascript:void(0);" onClick="console.log('Ver Usuario');"><?= t('Ver Canal');?></a>
							</div>
						</div>
					</div>

					
				</div>
			</div>	



		</div>
	</div>
</div>