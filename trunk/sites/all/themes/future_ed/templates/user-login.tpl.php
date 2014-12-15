<?php
/**
* Formulario custon de login
*	Creado el 18 de Noviembre del 2014
* por Ricardo Aguilera
* Para el correcto funcionamiento, se debe descargar u habilitar el modulo de "Remember me"
* desde la URL https://www.drupal.org/project/remember_me
* Este módulo se utiliza para implementar la funcionalidad de "Recordarme".
*/


?>
<div class="future-ed-form-login">
	<div class="row"><div class="small-12 columns" ><h4><?= TITULO_LOGIN ?></h4></div></div>
	<?php

	//print_r($form);
	// sobreescribir valores de las etiquetas del formulario

	$form['name']['#title']=LOGIN_NOMBRE;
	unset($form['name']['#description']);
	array_push($form['name']['#attributes'], array('placeholder' => LOGIN_NOMBRE));

	$form['pass']['#title']=LOGIN_CONTRASENA;
	unset($form['pass']['#description']);
	array_push($form['pass']['#attributes'], array('placeholder' => LOGIN_CONTRASENA));

	$form['actions']['submit']['#value']=LOGIN_BOTON;
	$form['remember_me']['#title']=LOGIN_RECORDARME;

	?><div class="row"><div class="small-12 columns" ><?php
	print drupal_render($form['name']);
	?></div></div>
	<div class="row"><div class="small-12 columns" ><?php
	print drupal_render($form['pass']);
	?></div></div>
	<div class="row"><div class="small-6 columns" >
		<?php print drupal_render($form['remember_me']); ?>
	</div>
	<div class="small-6 columns" >
		<div class="user-login-links">
			<span class="password-link">
				<a href=<?php echo "'".base_path()."user/password'"?>><?= CONTRASENA_OLVIDADA ?></a>
			</span> 
		</div>
	</div></div>

	<?php
	    // render login button
	print drupal_render($form['form_build_id']);
	print drupal_render($form['form_id']);

	?><div class="row"><div class="small-12 columns" ><?php
	print drupal_render($form['actions']);
	?>
	</div></div>
	<div class="row"><div class="small-12 columns" >
		<div class="user-login-redes-sociales">
			<h4><?= INICIAR_SESION_REDES_SOCIALES?></h4>
			<ul class="user-login-iconos-rs">
				<li>FB</li>
				<li>G+</li>
				<li>TW</li>
				<li>IN</li>
			</ul>
		</div>
	</div></div>
	<div class="row"><div class="small-12 columns" >
		<div class="user-login-registrar">
			<h4><?= REGISTRAR_USUARIO ?></h4>
			<span class="register-link">
					<a href="/user/register" class="form-submit"><?= REGISTRAR_USUARIO_BOTON?></a>
			</span>
		</div>
	</div></div>
</div>
<!-- /user-login-custom-form -->