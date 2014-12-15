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
<div class="large-3 columns end">


	<div class="row">
		<div class="large-12 columns">
			<i class="fa fa-mail-reply"></i> 
				<a href="javascript:void(0);" onclick="callAjax('<?php print $miembros['destino']?>', '<?php print $miembros['trigger']?>','nid_curso: 0, pagina: 1, div_contenedor: \'<?php print $miembros['destino']?>\'');">
					Volver
				</a>
		</div>
	</div>

	<?php
	foreach($miembros['detalles'] as $miembro){
		?>

		<div class="row" style="border:1px solid #000;">
			<div class="large-4 columns">
				<img src="<?= $miembro['imagen']?>">
			</div>
			<div class="large-8 columns">
				<p><?= $miembro['nombre'];?>
				<?= $miembro['link'];?>
				<?php 
					if($miembro['admin']==true){
						?><i>Admin</i><?php
					}
				?></p>
			</div>
		</div>
		<?php
	}
	?>
	<div class="row">
		<div class="large-12 columns">
			<i class="fa fa-mail-reply"></i> 
				<?php 
				if($miembros['perteneciente']==false){

				//Solicitar inscripción al grupo 
				?>
				<div id="hResultadoInsert" style="display:none;"></div>
				<a href="javascript:void(0);" onclick="inscribir('<?php print $miembros['usuario']?>','<?php print $miembros['idGrupo']?>')">
					Unirse al grupo
				</a>
				<?php
				}
				?>

		</div>
		<div class="large-12 columns">
			<i class="fa fa-mail-reply"></i> 
				<div id="hResultadoReporte" style="display:none;"></div>
				<a href="javascript:void(0);" onclick="reportar('<?php print $miembros['idGrupo']?>')">
					Reportar grupo
				</a>

		</div>
	</div>


</div>

<script type="text/javascript">
function inscribir(uid,grupo){
	params='usuario:'+uid+',grupo:'+grupo;
	usuarioInscrito = callAjax('hResultadoInsert','inscribir_usuario_grupo',params);
	console.log(usuarioInscrito);	

}
function reportar(grupo){
	params='grupo:'+grupo;
	reportado = callAjax('hResultadoReporte','reportar_grupo',params);
	console.log(reportado);	

}
</script>
