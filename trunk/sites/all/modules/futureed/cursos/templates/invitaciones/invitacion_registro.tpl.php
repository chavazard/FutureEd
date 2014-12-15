<style type="text/css">
#invitacion_registro{
	background-color: #FFFFFF;
	margin: 0;
	padding: 0;
}

#invitacion_registro_header{
	color: gray;
	width: 200px;
	margin: 0;
	padding: 0;
	padding-left: 10px;
	padding-bottom: 5px;
	padding-top: 5px;
}

#invitacion_registro_contenido{
	margin: 0;
	padding: 0;
	background-color: #3D3D3E;
	color: #FFFFFF;
	margin-bottom: 10px;

}

	#invitacion_registro_contenido ul{
		margin-top: 20px;
		margin-left: 70px;
		width: 160px;
	}

	#invitacion_registro_contenido li{
		font-size: 12px;
		color: #FF0000;
	}

	#invitacion_registro_contenido li span{
		color: #FFFFFF;
	}

#invitacion_registro_boton{
	margin: 0;
	padding: 0;
}

	#invitacion_registro_boton button{
		margin-left: 70px;
		font-size: 14px;
	}

	#invitacion_registro_boton a:link{
		color: #FFFFFF;
	}
</style>

<div class="row" id="invitacion_registro">
	<div class="small-12 columns" id="invitacion_registro_header">
		<b><?php echo t('PERTENECE A LA RED FutureED y podrás');?>...</b>
	</div>

	<div class="small-12 columns" id="invitacion_registro_contenido">
		<ul>
			<li><span><?php echo t('Tomar mas de 1,700 cursos');?><span></li>
			<li><span><?php echo t('Pertenecer a la comunidad y tener contacto directo con maestros, alumnos y otros usuarios');?>...<span></li>
			<li><span><?php echo t('Crear tus propios cursos');?><span></li>
			<li><span><?php echo t('Vender tus productos y mas');?>...<span></li>
		</ul>
	</div>

	<div class="small-12 columns" id="invitacion_registro_boton">
		<button><b><a href="#"><?php echo t('REGISTRARME');?></a></b></button>
	</div>
</div>