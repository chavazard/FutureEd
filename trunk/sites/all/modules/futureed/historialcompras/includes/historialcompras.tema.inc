<?php 
/**
 * @file
 * librería  para el historial de compras .
 *
 * @author Ricardo Aguilera
 */



?>
<style type="text/css">
.busquedaGeneral {
	font-size: 12px;
	border:1px solid #333;
	padding: 5px;
}
.busquedaGeneral button{
	padding: 5px;
	font-size: 10px;
	background: #943;
}


.busquedaDetalle {
	font-size: 12px;
	border:1px solid #333;
	padding: 5px;
}
.busquedaDetalle button{
	padding: 5px;
	font-size: 10px;
	background: #943;
}

</style>

<?php
/**
* 
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


	function render_historialCompras($args)
	{
		//print_r($args);
		//print_r($this->configListaDetalle);
		?>
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
			<?php /*
			<div class="small-3 columns busquedaGeneral end">
				<div class="small-12 columns">
					<img src="<?php echo $args['imagen']; ?>" style="width:100%;heigt:100%;">
				</div>
				<div class="small-12 columns">
					<h5><?= $args['titulo'];?></h5>
					<p><?= $this->configListaDetalle['tipoInteraccion']; ?>:<?= $args['datoPrincipal']; ?></p>
					<p><?= $this->configListaDetalle['tipoDatoAdicional']; ?>: <b><?= $args['datoAdicional']; ?></b></p>
				</div>


				<div class="small-12 columns">
					<div class="small-12 columns"><?= $this->configListaDetalle['textoUsuarios'];?></div>
					<div class="small-9 columns"><?= $args['tiles'];?></div>
					<div class="small-3 columns">
						<div class="small-12 columns"> asdf</div>
						
					</div>
				</div>
				<div class="small-12 columns">
					<div class="small-6 columns">
						<div class="small-12 columns"><?= $this->configListaDetalle['indicador1']; ?></div>
						<div class="small-12 columns"><?= $args['valor1']; ?></div>
					</div>
					<div class="small-6 columns">
						<div class="small-12 columns"><?= $this->configListaDetalle['indicador2']; ?></div>
						<div class="small-12 columns"><?= $args['valor2']; ?></div>
					</div>

				</div>
				<div class="small-12 columns">
					<button <?= $args['comportamientoBoton']; ?>><?= $this->configListaDetalle['textoBoton']; ?></button>
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
