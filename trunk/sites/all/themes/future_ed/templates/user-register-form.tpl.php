<?php
/**
* Formulario custom de registro de usuario
*	Creado el 18 de Noviembre del 2014
* por Ricardo Aguilera
*
*/

//$form['#validate'] = array('valida_usuario_nuevo');
//$form['#submit'] = array('guarda_usuario_nuevo');

//print_r($form);

print_r($form);
?>


<div class="future-ed-form-register">
	<div class="row titulo"><div class="small-12 columns" >
		<?= TITULO_REGISTRO ?>
	</div></div>
	<div class="row">

		<div class="small-6 columns" >
			<h4><?= SUBTITULO_REGISTRO ?></h4>

			<div class="futureed-user-pass-form-wrapper">
			  <?php print drupal_render_children($form) ?>
			</div>
		</div>
		

		<div class="small-6 columns end">
			<ul>
				<li>FB</li>
				<li>G+</li>
				<li>TW</li>
				<li>LI</li>
			</ul>

		</div>
	</div>

</div>