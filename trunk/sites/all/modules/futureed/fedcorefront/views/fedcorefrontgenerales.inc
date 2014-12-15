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
	background-color: #F1F1F1;
}
.busquedaDetalle button{
	padding: 5px;
	font-size: 10px;
	background: #FF6600;
}

/*------------------*/
.cursosSugeridos {
	font-size: 12px;
	border:1px solid #333;
	padding: 5px;
}
.cursosSugeridos button{
	padding: 5px;
	font-size: 10px;
	background: #943;
}

/*------------------*/
.productosSugeridos {
	font-size: 12px;
	border:1px solid #333;
	padding: 5px;
}
.productosSugeridos button{
	padding: 5px;
	font-size: 10px;
	background: #943;
}

/*------------------*/
.cursosCreados {
	font-size: 12px;
	padding: 5px;
	border:1px solid #333;
	background-color: #F1F1F1;
}
.cursosCreados button{
	padding: 5px;
	font-size: 10px;
	background: #00E6E6;
}

.cursosCreados p{
	padding: 0;
	margin: 0;
}

/*------------------*/
.cursosComprados {
	font-size: 12px;
	padding: 5px;
	border:1px solid #333;
	background-color: #F1F1F1;
}
.cursosComprados button{
	padding: 5px;
	font-size: 10px;
	background: #00E6E6;
}

.cursosComprados p{
	padding: 0;
	margin: 0;
}

</style>

<?php
/**
* 
*/
class fedCorefrontGenerales 
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

	/********************************/
	var $configAnuncio = array();
	var $configCursosSugeridos = array();
	var $configProductosSugeridos = array();
	var $configCursosPerfil = array();
	/********************************/

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
					<div class="row">
						<div class="large-6 columns">
						<p><?= $this->configListaDetalle['tipoInteraccion']; ?><?= $args['datoPrincipal']; ?></p>
						</div>
						<div class="large-6 columns">
							<div class="cuenta-verificada"><?= $args['verificacion']; ?></div>							
						</div>	
					</div>
						<p><?= $this->configListaDetalle['tipoDatoAdicional']; ?><?= $args['datoAdicional']; ?></p>
					<div class="small-4 columns">
						<button <?= $args['comportamientoBoton']; ?>><?= $this->configListaDetalle['textoBoton']; ?></button>
					</div>
					<div class="small-8 columns">
						<div class="small-4 columns"><?= $this->configListaDetalle['textoUsuarios'];?></div>
						<div class="small-8 columns"><?= $args['tiles'];?></div>
					</div>
				</div>
				<div class="small-4 columns">
					<div class="small-12 columns">
						<div class="small-6 columns">
							<div class="logo-fed"><?= $args['logo']; ?></div>
						</div>
						<div class="small-6 columns"><?= $this->configListaDetalle['indicador']; ?><?= $args['valor']; ?></div>
					</div>
					<br><br><br><br>
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









/*------------------------------------------------------------------------------------------------------*/
	function render_cursosSugeridos($args)
	{
		?>
		<div class="row cursosSugeridos">
			<div class="small-3 columns ">
				<div class="panel">
					<p><img src="<?php echo $args['imagen']; ?>" style="width:100%;heigt:100%;"></p>
				</div>
			</div>
			<div class="small-9 columns">
				<h5><?= $args['titulo'];?></h5>
				<?= $this->configCursosSugeridos['tipoInteraccion']; ?>:<?= $args['datoPrincipal']; ?><br>
				<?= $this->configCursosSugeridos['indicador1']; ?>: <?= $args['valor1']; ?><br>
				<?= $this->configCursosSugeridos['indicador2']; ?>: <?= $args['valor2']; ?><br>
			</div>
		</div>
		<?php
	}

	function set_cursosSugeridos($args)
	{
		$this->configCursosSugeridos = array();
		$this->configCursosSugeridos = $args;
	}









	function render_productosSugeridos($args)
	{
		?>
		<div class="row productosSugeridos">
			<div class="small-3 columns ">
				<div class="panel">
					<p><img src="<?php echo $args['imagen']; ?>" style="width:100%;heigt:100%;"></p>
				</div>
			</div>
			<div class="small-9 columns">
				<h5><?= $args['titulo'];?></h5>
				<?= $this->configProductosSugeridos['tipoInteraccion']; ?>:<?= $args['datoPrincipal']; ?><br>
				<?= $this->configProductosSugeridos['indicador1']; ?>: <?= $args['valor1']; ?><br>
				<?= $this->configProductosSugeridos['indicador2']; ?>: <?= $args['valor2']; ?><br>
			</div>
		</div>
		<?php
	}
	
	function set_productosSugeridos($args)
	{
		$this->configProductosSugeridos = array();
		$this->configProductosSugeridos = $args;
	}









	function render_anuncio($args)
	{
		?>
		<div class="row">
			<div class="small-12 columns" style="height:<?= $this->configAnuncio['alto'];?>">
				<?= $args['imagen']?>
			</div>
		</div>
		<?php
	}

	function set_anuncio($args)
	{
		$this->configAnuncio = array();
		$this->configAnuncio = $args;
	}

	
	




	function render_cursosPerfil($args)
	{
		?>
		<div class="row cursosCreados">
			<div class="small-12 columns ">
				<div class="panel">
					<img src="<?php echo $args['imagen']; ?>" style="width:100%;heigt:100%;">
				</div>
			</div>

			<div class="small-12 columns ">
				<h6><?= $args['titulo'];?></h6>
				<p><?= $this->configCursosPerfil['tipo']; ?><b><?= $args['dato']; ?></b></p><br>
				<p><?= $this->configCursosPerfil['tipoDatoPrincipal']; ?><b><?= $args['datoPrincipal']; ?></b></p><br>
				<p><?= $this->configCursosPerfil['tipoDatoAdicional']; ?><b><?= $args['datoAdicional']; ?></b></p><br>
				<p><?= $args['comportamientoTexto']; ?></p><br>
				<button <?= $args['comportamientoBoton']; ?>><?= $this->configCursosPerfil['textoBoton']; ?></button><br>
				<hr>

				<div class="row">
					<div>
						<div class="small-3 columns">
							<img src="<?php echo $args['imagen1']; ?>">
						</div>
						<div class="small-3 columns">
							<img src="<?php echo $args['imagen2']; ?>">
						</div>
						<div class="small-3 columns">
							<img src="<?php echo $args['imagen3']; ?>">
						</div>
						<div class="small-3 columns">
							<button <?= $args['botonAdicional']; ?>><?= $this->configCursosPerfil['textoBotonAdicional']; ?></button>
						</div>
					</div>
				</div>

			</div>

		</div>
		<?php
	}

	function set_cursosPerfil($args)
	{
		$this->configCursosPerfil = array();
		$this->configCursosPerfil = $args;
	}



























}
