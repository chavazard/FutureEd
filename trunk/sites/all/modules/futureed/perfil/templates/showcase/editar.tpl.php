<style type="text/css">
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

		print("<div id='wrapperFormShowcase'>");
		$my_form=drupal_get_form('showcase_formulario');
		//print_r($my_form);
		print drupal_render($my_form);
		print("</div>");