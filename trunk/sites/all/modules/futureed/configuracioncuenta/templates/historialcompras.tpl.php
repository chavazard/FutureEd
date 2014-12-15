<?php
/*
* Busquedas:
* Creado por Ricardo Aguilera
* el 24 de Octubre del 2014
* utiliza la variable $items, que se divide en dos secciones:
* $items['tipo']: contiene el tipo del item que se está buscando y sirve para configurar automáticamente
* 					los textos fijos del bloque
* $items['data']: contiente un arreglo de los items que se van a mostrar; este arreglo debe tener al siguiente estructura:
* $items['data'][0]= array(8) {
*			  ["titulo"]=>"string"  				//El título que tendrá el resultado de la búsqueda
*			  ["imagen"]=>"string"					//La imagen a mostrar
*			  ["datoPrincipal"]=>"string"			//El dato principal a mostrar
*			  ["datoAdicional"]=>"string"			//El dato adicional a mostrar
*			  ["comportamientoBoton"]=>"string"		//Comportamiento del botón 
*			  ["tiles"]=>"string"					//los tiles a mostrar
*			  ["valor1"]=>"string"					//El valor del primer recuadro
*			  ["valor2"]=>"string"					//El valor del segundo recuadro
*			};
*
*/
$arrCofig = array();
$titulo = "Historial de Compras";

			$arrCofig = array(
			'tipoInteraccion' => 'Creador',
			'tipoDatoAdicional' => 'Fecha de Inicio',
			'textoBoton' => 'Ver Curso',
			'textoUsuarios' => 'Usuarios Populares',
			'indicador1' => 'Precio',
			'indicador2' => 'Calificación',
		);
			


//$items = $variables['items'];

 $module_path = drupal_get_path('module', 'configuracioncuenta');


require_once("$module_path/includes/historialventas.tema.inc");

$historialventas = new historialventas;


//setear par cursos
$historialventas->set_historialventas(
	$arrCofig

);

?><div class="row">
<h3><?= $titulo; ?></h3>
<?php
foreach($items['data'] as $item){
	//var_dump($item);
$historialventas->render_historialventas(
	$item

);
}
?></div><?php 


































/*
$anuncio = new Generales;

$anuncio->set_anuncio(
	array(
		'alto'=>'100px'
	)
);

$anuncio->render_anuncio(
	array(
		'imagen'=>'soy una foto'
	)

);

$anuncio->render_anuncio(
	array(
		'imagen'=>'soy una foto'
	)

);

$anuncio->render_anuncio(
	array(
		'imagen'=>'soy una foto'
	)

);

$anuncio->set_anuncio(
	array(
		'alto'=>'250px'
	)
);

$anuncio->render_anuncio(
	array(
		'imagen'=>'soy una foto'
	)

);
*/