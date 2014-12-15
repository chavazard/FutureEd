<?php 
/**
 * @file
 * librería  para el historial de compras .
 *
 * @author Ricardo Aguilera
 */


class historialCompras 
{
	/**
	 * Función para crear un elemento de lista.
	 *
	 * Set beginning and end dates, retrieve posts from database
	 * saved in that time period.
	 * @param $args
	 * 		Un array de argumentos, con los que se configura la lista
	 * @return
	 *   A result set of the targeted posts.
	 */
	var $configListaDetalle = array();
	var $configAnuncio = array();


	function render_historialCompras($item)
	{
		//print_r($args);
		//print_r($this->configListaDetalle);
		?>

		<div class="large-12 columns end no-padding">
	<div class="item-lista-grande">
		<div class="row ">
			<div class="small-4 columns ">
				<div class="top">
					<a href="javascript:void(0)" onclick="console.log('funciona');console.log('<?= $item['idCurso']?>')" class="action">
						<img src="<?= $item['field_curso_imagen']; ?>">
					</a>

					<img class="main" src="<?= $item['imagen']; ?>">
					<img class="secundaria" src="<?= $item['field_usuario_imagen']; ?>">
				</div>
			</div>
			<div class="small-8 columns ">
				<div class="contenido">
					<div class = "row titulo">
						<div class="large-12 columns"><h1><?= $item['titulo'];?></h1></div>
					</div>
	
					<div class = "row ">
						<div class = "large-6 columns">
							
							<p><?= $this->configListaDetalle['tipoInteraccion']; ?>:<?= $item['datoPrincipal']; ?></p>
							<p><?= $this->configListaDetalle['tipoDatoAdicional']; ?>: <b><?= $item['datoAdicional']; ?></b></p>
						</div>
						<div class = "large-6 columns">
							<div class = " info">

								<h2><?= $this->configListaDetalle['indicador1']; ?>: <a href="#"><?= $item['valor1'];?></a></h2>
								
							</div>
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
							<div class = "botones ">	
								<a class="btn" value="javascript:void(0);" onClick="console.log('Ver Curso');"><?= HISTORIAL_VENTA_NUM_RASTREO;?></a><br><br>
								<a class="btn" value="javascript:void(0);" onClick="console.log('Ver Curso');"><?= HISTORIAL_VENTA_VALORACION;?></a>
							</div>
						</div>
					</div>
				</div>
			</div>
		</div>
	</div>
</div>

<?php /*
			<div class="small-12 columns busquedaGeneral end">
					<div class="small-2 columns">
						<img src="<?php echo $args['imagen']; ?>" style="width:100%;heigt:100%;">
					</div>
					<div class="small-8 columns">
						<h5><?= $args['titulo'];?></h5>
						<p><?= $this->configListaDetalle['tipoInteraccion']; ?>:<?= $args['datoPrincipal']; ?></p>
						<p><?= $this->configListaDetalle['tipoDatoAdicional']; ?>: <b><?= $args['datoAdicional']; ?></b></p>
						<?php if(1==1){
							?>
							<button class="form-submit">Subir Numero de Rastreo</button>
							<button class="form-submit">Pedir valoración</button>
							<?php

						} ?>
					</div>
					<div class="small-2 columns">
						<div class="small-12 columns"><?= $this->configListaDetalle['indicador1']; ?></div>
						<div class="small-12 columns"><?= $args['valor1']; ?></div>
					</div>

			</div>
			<?php */
		
	}
	/**
	 * Función para parametrizar los valoresgererales de una lista.
	 *
	 * @param $args
	 * 		Un array de argumentos, con los que se configura la lista
	 *		'tipoInteraccion' 
	 *		'tipoDatAdicional'
	 *		'textoBoton'
	 *		'textoUsuaros'
	 *		'indicador1'
	 *		'indicador2'
	 * @return
	 *   A result set of the targeted posts.
	 */
	function set_historialCompras($args){
	
		$this->configListaDetalle = array();
		$this->configListaDetalle = $args;


	}
}
