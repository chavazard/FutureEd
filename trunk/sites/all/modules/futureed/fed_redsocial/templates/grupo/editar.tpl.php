<?php

		print("<div id='wrapperFormGrupo'>");
		$my_form=drupal_get_form('grupo_formulario');
		//print_r($my_form);
		print drupal_render($my_form);
		print("</div>");