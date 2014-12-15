<div class="large-<?= $anchoColumnas;?> columns end no-padding">
	<div class="item-lista-grande">
		<div class="row busquedaCursos">



			<div class="small-4 columns ">
				<div class="top">
					<a href="javascript:void(0)" onclick="console.log('funciona');console.log('<?= $item['idCurso']?>')" class="action">
						<img src="<?= $item['field_curso_imagen']; ?>">
					</a>
					<img class="main" src="<?= $item['field_curso_imagen']; ?>">
					<img class="secundaria" src="<?= $item['field_usuario_imagen']; ?>">
				</div>
			</div>
			
			<div class="small-8 columns ">
				<div class="contenido">


					<div class = "row titulo">
						<div class="large-12 columns"><h1><?= $item['field_curso_nombre'];?></h1></div>
					</div>
	
					<div class = "row ">
						<div class = "large-6 columns">
							<?= CREADOR;?>: <a href="#"><?= $item['calc_creador_nombre'];?></a>
							<?php if ($item['field_usuario_verificado'] == TRUE) {?>
							<img src="http://placehold.it/20x20">
							<?php } else {?>
							<?php }?>
							<?php if ($item['field_curso_fecha'] == TRUE) {?>
							<p><?= FECHA_DE_INICIO;?>: <b><?= $item['field_curso_fecha'];?></b></p>
							<?php } else {?>
							<?php }?>
						</div>
						<div class = "large-6 columns">
							<div class = " info">
								<?php if ($item['field_curso_descuento'] == TRUE) {?>
								<b><u><?= $item['field_curso_precio'];?></u></b>
								<br>
								<b><?= $item['field_curso_descuento'];?></b>
								<h2><?= PRECIO;?>: <a href="#"><?= $item['calc_curso_costo_total'];?></a></h2>
								<?php } else {?>
								<h2><?= PRECIO;?>: <a href="#"><?= $item['field_curso_precio'];?></a></h2>
								<?php }?>
							</div>
						</div>
					</div>
					
					<div class = "row">
						<div class = "large-12 columns">
							<i><?= USUARIOS_POPULARES ?></i>
						</div>
					</div>

					<div class = "row">
						<div class = "large-6 columns">
							<div class = "info">
								<?php foreach($item['array_usuarios_curso'] AS $usuario) { ?>
			                    <a href="<?= $usuario['link_usuario_curso']; ?>"><img src="<?= $usuario['field_usuario_imagen']; ?>"></a>
			                    <?php } ?>
								<div>
									<?= $item['field_likes']; ?>
								</div>
							</div>
						</div>
						<div class = "large-6 columns">
							<div>
								<?= mostrar_calificacion_estrellas($item['field_curso_calificacion'],$item['field_curso_numero_votos']); ?>
							</div>
							<div class = "botones ">	
								<a class="btn" value="javascript:void(0);" onClick="console.log('Ver Curso');"><?= VER_CURSO;?></a>
							</div>
						</div>
					</div>

					
				</div>
			</div>



		</div>
	</div>
</div>