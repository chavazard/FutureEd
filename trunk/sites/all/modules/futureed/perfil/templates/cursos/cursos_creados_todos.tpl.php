<div class="large-<?=$anchoColumnas;?> columns end item">
	<div class="item-lista-chica">

		<div>
			<img src="<?= $item['field_curso_imagen']; ?>">
		</div>
		<div class="contenido">
			<div class="row titulo">
				<div class="large-12 columns"><a href="<?= $item['link_curso']; ?>"><h1><?= $item['field_curso_nombre'];?></h1></a></div>
			</div>
			<div class="row info">
				<div class = "large-12 columns">
					<p><?= CANAL;?>: <a href="<?= $item['link_curso_canal']; ?>"><?= $item['field_curso_canal']; ?></a></p>
					<p><?= t('Estatus');?>: <?= $item['field_curso_estatus']; ?></p>
				</div>
			</div>
			<div class="row info">
				<? if ($item['field_curso_fechas_imparticion'] == 'cerrado') {?>
                <p><?= t('Fecha de inicio');?>: <?= $item['field_curso_fecha'];?></p> 
                <p><?= t('Alumnos:');?>: <?= $item['calc_numero_alumnos'];?></p>
                <? } else{?>
                <p><?= t('Curso abierto');?>: <?= $item['field_curso_caducidad'];?></p> 
                <? } ?>
			</div>
			<div class = "row info">
				<div class="large-12 columns">
					<? if ($item['field_curso_fechas_imparticion'] == 'cerrado') {?>
					<p><?= $item['field_curso_publicacion']; ?></p>
					<? }?>
				</div>
			</div>
			<hr>
			<div class="foot">
				<a href="javascript:void(0)" onclick="console.log('Editar');console.log('<?= $item['nid']?>')" class="action">
					<img src="http://placehold.it/20x20">
				</a>
				<? if($item['field_curso_publicacion'] == 'Publicado') {?>
				<a href="javascript:void(0)" data-reveal-id="error" onclick="console.log('Eliminar');console.log('<?= $item['nid']?>')" class="action">
					<img src="http://placehold.it/20x20">
				</a>
				<? } else{?>
				<a href="javascript:void(0)" data-reveal-id="eliminar" onclick="console.log('Eliminar');console.log('<?= $item['nid']?>')" class="action">
					<img src="http://placehold.it/20x20">
				</a>
				<? }?>
				<a href="javascript:void(0)" onclick="console.log('Agregar a Canal');console.log('<?= $item['nid']?>')" class="action">
					<img src="http://placehold.it/20x20">
				</a>
			</div>
		</div>

	</div>
</div>

<script>
	/*
	muestraErrorEliminar('error')
	
	function muestraErrorEliminar(nombreDivMensaje)
	{
		document.getElementById(nombreDivMensaje).innerHTML = "No se puede eliminar el curso: <?=$item['nombre_curso']; ?>";
	}*/
</script>

<!--**********************************************************************************************************************-->

<?php
    define ("MODAL_ERROR_TXT1", t('Error'));
    define ("MODAL_ERROR_TXT2", t('No puedes eliminar el curso'));
    define ("MODAL_ERROR_TXT3", t('porque el curso esta activo'));
?>

<script type="text/javascript">
jQuery(function($) {
	jQuery("#edit-boton-regresar").prop("type", "button");
    jQuery("#edit-boton-eliminar").prop("type", "button");
});

jQuery(function($) {
    console.log("jQuery cargado exitosamente");
});
</script>

<!--************************ Modal - Error ************************-->
<div id="error" class="reveal-modal" data-reveal>
  
  	<div class="row">
    	<div class="small-2 columns">
        	<img src="http://placehold.it/100x100">
    	</div>
    	<div class="small-10 columns">
        	<h5><?= MODAL_ERROR_TXT1;?></h5>
        	<div><?= MODAL_ERROR_TXT2;?><br> <b>"<?= $item['field_curso_nombre'];?>"</b> <?= MODAL_ERROR_TXT2;?></div>
    	</div>
  	</div>

  	<a class="close-reveal-modal">&#215;</a>
</div>

<!--************************ Modal - Eliminar ************************-->
<div id="eliminar" class="reveal-modal" data-reveal>
  
	<div class="row">
	    <div class="small-12 columns">
	    	<div>¿Seguro que desea eliminar el curso<b>"<?= $item['field_curso_nombre'];?>"</b>?</div>
	    </div>
      	<hr>
      	<div class="small-12 columns">
        	<p>¿Cual es tu motivo?</p>
        	<div>
        		<?php print drupal_render(drupal_get_form('curso_eliminar_form'));?>
        	</div>
     	</div>
	</div>
  
  	<a class="close-reveal-modal">&#215;</a>
</div>

<!--************************ Modal - Aviso ************************-->
<div id="aviso" class="reveal-modal" data-reveal>
  
	<div class="row">
    	<div class="small-12 columns">
      		<div>Haz eliminado el curso<br><b>"<?= $item['field_curso_nombre'];?>"</b></div>
      		<button>OK</button>
    	</div>
  	</div>

  	<a class="close-reveal-modal">&#215;</a>
</div>