<?php 
$estiloTitulo = "carrusel-titulo";
switch($item['tipo_carrusel']){
    case "cursos":
        $estiloTitulo .= " cursos"; 
        break;
    case "canales":
        $estiloTitulo .= " canales"; 
        break;
    case "grupos":
        $estiloTitulo .= " grupos"; 
        break;     
    default:
        $estiloTitulo = ""; 
        break;                
    
}
?>
<div class="contenedor-carrusel" >
    <h3 class="<?=$estiloTitulo;?>"><?=$item['titulo'];?></h3>
    <div class="mensaje-error-carrusel"><?=$item['mensaje'];?></div>
    
    <div class="btn-standard"><a href="#" data-reveal-id="<?=$item['modal_sugerir'];?>"><?=$item['label_boton'];?></a></div>
    
    
</div>


