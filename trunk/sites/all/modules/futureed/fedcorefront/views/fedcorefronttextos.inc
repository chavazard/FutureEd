<?php 
/**
 * @file
 * librería  principal .
 *
 * @author Ricardo Aguilera
 */

/**
 * Implements hook_help().
 *
 * Displays help and module information.
 *
 * @param path
 *   Which path of the site we're using to display help
 * @param arg
 *   Array that holds the current path as returned from arg() function
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
class Generales 
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

	function render_listaDetalle($args)
	{

		?>
		<div class="row busquedaDetalle">
			<div class="small-3 columns ">
				<div class="panel">
				<p>
				<img src="<?php echo $args['imagen']; ?>" style="width:100%;heigt:100%;">
				</p>
				</div>
			</div>
			<div class="small-9 columns">
				<div class="small-8 columns">
					<h5><?= $args['titulo'];?></h5>
					<p><?= $this->configListaDetalle['tipoInteraccion']; ?>:<?= $args['datoPrincipal']; ?></p>
					<p><?= $this->configListaDetalle['tipoDatoAdicional']; ?>: <b><?= $args['datoAdicional']; ?></b></p>
					<div class="small-4 columns">
						<button <?= $args['comportamientoBoton']; ?>><?= $this->configListaDetalle['textoBoton']; ?></button>
					</div>
					<div class="small-8 columns">
						<div class="small-4 columns"><?= $this->configListaDetalle['textoUsuarios'];?></div>
						<div class="small-8 columns"><?= $args['tiles'];?></div>
					</div>
				</div>
				<div class="small-4 columns">
					<div class="small-12 columns"> asdf</div>
					<div class="small-6 columns">
						<div class="small-12 columns"><?= $this->configListaDetalle['indicador1']; ?></div>
						<div class="small-12 columns"><?= $args['valor1']; ?></div>
					</div>
					<div class="small-6 columns">
						<div class="small-12 columns"><?= $this->configListaDetalle['indicador2']; ?></div>
						<div class="small-12 columns"><?= $args['valor2']; ?></div>
					</div>
				</div>
			</div>
		</div>

		<?php 
		
	}

	function set_listaDetalle($args){
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
		$this->configListaDetalle = array();
		$this->configListaDetalle = $args;


	}


	function set_anuncio($args){
		$this->configAnuncio = array();
		$this->configAnuncio = $args;


	}

	function render_anuncio($args){

		?>
		<div class="row">
			<div class="small-12 columns" style="height:<?= $this->configAnuncio['alto'];?>">
				<?= $args['imagen']?>
			</div>
		</div>
		<?php

	}

	function render_listaGeneral($args)
	{

		?>
		
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

		<?php 
		
	}

	function set_listaGeneral($args){
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
		$this->configListaDetalle = array();
		$this->configListaDetalle = $args;


	}




}
