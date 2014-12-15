<div class="large-<?= $anchoColumnas;?> columns end no-padding">
	<div class="item-lista-grande">
		<div class="row busquedaUsuarios">



			<div class="small-4 columns ">
				<div class="top">
					<a href="javascript:void(0)" onclick="console.log('funciona');console.log('<?= $item['idUsuario']?>')" class="action">
						<img src="<?= $item['field_usuario_imagen']; ?>">
					</a>
					<img class="main" src="<?= $item['field_usuario_imagen']; ?>">
				</div>
			</div>

			<div class="small-8 columns">
				<div class="contenido">


					<div class="row titulo">
						<div class="large-6 columns">
							<h1><?= $item['calc_usuario_nombre'];?></h1>
							<?php if ($item['field_usuario_verificado'] == TRUE) {?>
							<img src="http://placehold.it/20x20">
							<?php }?>
						</div>
					</div>

					<div class="row">
						<div class="large-6 columns">
							<p><?= $item['username']; ?></p>
							<p>Seguidores: <?= $item['field_usuario_numero_seguidores']; ?></p>
						</div>
						<div class = "large-6 columns">
							<div class="info">
								<?php foreach($item['field_usuario_roles'] AS $rol) { ?>
			                    	<?php if ($rol['rol1'] == 1) {?>
			                    	<a href="#"><img src="http://placehold.it/50x50"></a>	
			                    	<?php }?>
			                    	<?php if ($rol['rol2'] == 2) {?>
			                    	<a href="#"><img src="http://placehold.it/50x50"></a>	
			                    	<?php }?>
			                    	<?php if ($rol['rol3'] == 3) {?>
			                    	<a href="#"><img src="http://placehold.it/50x50"></a>	
			                    	<?php }?>
			                    <?php } ?>								
							</div>
						</div>
					</div>

					<div class = "row">
						<div class = "large-12 columns">
							<i><?= t('Cursos Populares'); ?></i>
						</div>
					</div>

					<div class = "row">
						<div class = "large-6 columns">
							<div class = "info">
								<?php foreach($item['array_cursos_usuario'] AS $cursos) { ?>
			                    <a href="<?= $cursos['link_usuario_curso']; ?>"><img src="<?= $cursos['field_curso_imagen']; ?>"></a>
			                    <?php } ?>
			                    <p>Cursos: <?= $item['calc_numero_cursos']; ?></p>
							</div>
						</div>
						<div class = "large-6 columns">
							<div class = "botones ">
								<a class="btn" value="javascript:void(0);" onClick="console.log('Ver Usuario');"><?= t('Ver Usuario');?></a>
							</div>
						</div>
					</div>

					
				</div>
			</div>	



		</div>
	</div>
</div>