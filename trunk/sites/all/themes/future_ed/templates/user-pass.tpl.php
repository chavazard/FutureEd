<?php
/**
* Formulario custom de recuperación de contraseña
*	Creado el 18 de Noviembre del 2014
* por Ricardo Aguilera
*
*/



	$form['name']['#title']=RECUPERA_CONTRA_NOMBRE;
	unset($form['name']['#description']);
	array_push($form['name']['#attributes'], array('placeholder' => RECUPERA_CONTRA_NOMBRE));


	$form['actions']['submit']['#value']=RECUPERA_CONTRA_BOTON;

	//print_r($form);

?>
<div class="future-ed-form-pass">
	<div class="row"><div class="small-12 columns" >
		<h4><?= TITULO_REGISTRA_CUENTA ?></h4>
		<p><?= TEXTO_RECUPERA_CONTRA ?></p>
	</div></div>
	<div class="yourtheme-user-pass-form-wrapper">
	  <?php print drupal_render_children($form) ?>
	</div>


</div>