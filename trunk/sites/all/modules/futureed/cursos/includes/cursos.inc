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

<?php
/**
* 
*/
class Core 
{
	
	var $configCursosPerfil = array();
	var $configCursosComprados = array();


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
				<p><?= $this->configCursosPerfil['tipo']; ?><u><?= $args['dato']; ?></u></p>
				<p><?= $this->configCursosPerfil['tipo1']; ?><u><?= $args['dato1']; ?></u></p>
				<p><?= $this->configCursosPerfil['tipo2']; ?><u><?= $args['dato2']; ?></u></p>
				<p><?= $this->configCursosPerfil['tipoDatoPrincipal']; ?><b><?= $args['datoPrincipal']; ?></b></p>
				<p><?= $this->configCursosPerfil['tipoDatoAdicional']; ?><b><?= $args['datoAdicional']; ?></b></p>
				<p><?= $this->configCursosPerfil['tipoDatoAdicional1']; ?><?= $args['datoAdicional1']; ?></p>
				<p><?= $this->configCursosPerfil['tipoDatoAdicional2']; ?><?= $args['datoAdicional2']; ?></p>
				<p><?= $args['comportamientoTexto']; ?></p><br>
				<button <?= $args['comportamientoBoton']; ?>><?= $this->configCursosPerfil['textoBoton']; ?></button><p><?= $args['calificaciones']; ?></p>
				<hr>

				<div class="row">
					<div class="small-12 columns">
						<p><?= $this->configCursosPerfil['textoAdicional']; ?></p>
					</div>
					<div class="small-12 columns">
						<p><?= $args['comportamientoAdicional']; ?></p>
					</div>
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
						<?php if ($args['botonAdicional'] == TRUE)  { ?>
						<button <?= $args['botonAdicional']; ?>><?= $this->configCursosPerfil['textoBotonAdicional']; ?></button>
						<?php } ?>
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




/*
	function render_cursosComprados($args)
	{
		?>
		<div class="row cursosComprados">
			<div class="small-12 columns ">
				<div class="panel">
					<img src="<?php echo $args['imagen']; ?>" style="width:100%;heigt:100%;">
				</div>
			</div>

			<div class="small-12 columns ">
				
				<h6><?= $args['titulo'];?></h6>
				<p><?= $this->configCursosComprados['tipo1']; ?><u><?= $args['dato1']; ?></u></p><br>
				<p><?= $this->configCursosComprados['tipo2']; ?><u><?= $args['dato2']; ?></u></p><br>
				<p><?= $this->configCursosComprados['tipoDatoPrincipal']; ?><?= $args['datoPrincipal']; ?></p>
				<p><?= $this->configCursosComprados['tipoDatoAdicional1']; ?><?= $args['datoAdicional1']; ?></p><br>
				<p><?= $this->configCursosComprados['tipoDatoAdicional2']; ?><?= $args['datoAdicional2']; ?></p><br>
				<button <?= $args['comportamientoBoton']; ?>><?= $this->configCursosComprados['textoBoton']; ?></button><br>
				<hr>

				<div class="row">
					<div class="small-12 columns">
						<p><?= $this->configCursosComprados['textoAdicional']; ?></p>
					</div>
					<div class="small-12 columns">
						<p><?= $args['comportamientoAdicional']; ?></p>
					</div>
				</div>

			</div>

		</div>
		<?php
	}

	function set_cursosComprados($args)
	{
		$this->configCursosComprados = array();
		$this->configCursosComprados = $args;
	}
*/


























}
