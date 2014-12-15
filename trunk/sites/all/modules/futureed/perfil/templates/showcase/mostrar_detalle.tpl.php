<?php 
/**
*	Template para mostrar el detalle de los cursos(dentro de la funcionalidad de "showcase")
* Creado Por Ricardo Aguielra Zamarripa
*	El 20 de Noviembre del 2014
*	@param
* $variables : el arreglo de valores que se envía desde el control.
* Por cuestión de control, se env{ian los valores en el índice $variables['detalleShowcase']
* la estructura del índice es la siguiente:
* 				'intShowcase'=>'1', 																												//El id del showcase
*          'strShowcase'=>'showcase bonito :o', 																			//El título del showcase
*          'intCurso'=>'12', 																													//El id del curso
*          'strCurso'=>'Curso bonito', 																								//El nombre del curso
*          'intCategoria'=>'22',																											//El id de la categoría																								
*          'strCategoria'=>'Categoría bonita',																				//El nombre de la categoría
*	         'strContenido'=>'Lorem ipsum dolor sit amet, consectetur adipiscing elit, 	//El contenido del showcase
*		       'imgShowcase'=>'http://placehold.it/300x300',															//La imagen del showcase
*          'pathArchivo'=>'http://placehold.it/500x500',															//El path al archivo
*          'strArchivo'=>'nombre bonito del archivo',																	//El nombre del archivo
*          'datFecha'=>'01/12/13',																										//Fecha del showcase
*
*/
$items = $variables['detalleShowcase'];
//print_r($items);
?>
<div id="wrapperFormShowcase" class="row">

	<div class="small-4 columns">
		<div>
			<img src="<?= $items['imgShowcase']?>">
		</div>
		<div id="divArchivoDescargable">
			<a href="<?= $items['pathArchivo']?>" target="_blank"><?= $items['strArchivo']?></a>
		</div>

	</div>

	<div class="small-8 columns">
		<div id="divTituloCurso">
			<h1><?= $items['strCurso']?></h1>
			<p><?= $items['datFecha']?></p>
		</div>
		<div id="divSubtituloCurso">
			<p>Curso: <?= l($items['strCurso'], 'curso/'.$items['intCurso'])?></p>
			<p>Categoría: <?= l($items['strCategoria'], 'categoria/'.$items['intCategoria'])?></p>
		</div>

		<div id="divContenidoCurso">
			<p>
					<?= $items['strContenido']?>
					
			</p>
				</div>


	</div>

</div>