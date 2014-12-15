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

<link href="//maxcdn.bootstrapcdn.com/font-awesome/4.2.0/css/font-awesome.min.css" rel="stylesheet">

<div class="large-9 columns end">
	<div class="row">
		<div class="large-12 columns">
			<img src="<?= $item['imagen']?>">
		</div>
	</div>
	<div class="row">
		<div class="large-10 columns"><h1><?= $item['titulo']?></h1></div>
		<div class="large-2 columns"><?php
			if($item['secreto']==true){
				?>
				<i class="fa fa-lock"></i> Grupo Secreto
				<?php
			}
		?>
		</div>
	</div>
	<div class="row">
		<div class="large-12 columns">
			<p><?= $item['descripcion']?></p>
		</div>
	</div>
	<div class="row">
		<div class="large-12 columns">
			<ul>
				<li>Categoría:<?= $item['categoria']?></li>
				<li>Subcategoria:<?= $item['subcategoria']?></li>
				<li>Miembros:<?= $item['miembros']?></li>
				<li>Privacidad:<?= $item['privacidad']?></li>

			</ul>
		</div>
	</div>
</div>