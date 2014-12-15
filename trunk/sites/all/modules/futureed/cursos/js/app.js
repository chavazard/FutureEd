//js para cursos
var $ = jQuery.noConflict();


function agregaFiltroCurso(tipoFiltro, valor, elementoSeleccionado, parametros, contenedor, funcionalidad){
    switch (tipoFiltro){
	case 'modalidad':
	    muestraPanelTabToogle('panelFiltro-1','tabFiltro-1');
	    nombreCampo = "filtro-cursos-modalidad";	    	
	    padreFiltros = "filtros-modalidad-cursos";	      	    
	    break;
	/*case 'tipo':
	    muestraPanelTabToogle('panelFiltro-2','tabFiltro-2');
	    nombreCampo = "filtro-cursos-tipo";
	    padreFiltros = "filtros-tipo-cursos";
	    break;*/
	case 'ordenamiento':
	    muestraPanelTabToogle('panelFiltro-3','tabFiltro-3');
	    nombreCampo = "filtro-cursos-ordenamiento";
	    padreFiltros = "filtros-ordenamiento-cursos";
	    break;
	case 'calificacion':
	    muestraPanelTabToogle('panelFiltro-4','tabFiltro-4');
	    nombreCampo = "filtro-cursos-calificacion";
	    padreFiltros = "filtros-calificacion-cursos";
	    break;	
    }
    $('#'+nombreCampo).val(valor);
    
    $('#'+padreFiltros).children().each(function(){
	$(this).removeClass("filtro-seleccionado");
    });	       
    
    $('#'+elementoSeleccionado).addClass("filtro-seleccionado");
    $('#filtro-precios-min').addClass("filtro-seleccionado"); 
    aplicaFiltros(parametros,contenedor, funcionalidad);
}
 
function aplicaFiltros(parametrosEspeciales, contenedor,funcionalidad)
{
    modalidad    = $('#filtro-cursos-modalidad').val();
    //tipo         = $('#filtro-cursos-tipo').val();
    ordenamiento = $('#filtro-cursos-ordenamiento').val();
    calificacion = $('#filtro-cursos-calificacion').val();
    rango_precio_min = $('#filtro-precios-min').val();
    rango_precio_max = $('#filtro-precios-max').val();

    parametros  = 'modalidad:'         + modalidad;
    //parametros += ',tipo:'             + tipo;
    parametros += ',ordenamiento:'     + ordenamiento;
    parametros += ',calificacion:'     + calificacion;
    parametros += ',rango_precio_min:' + rango_precio_min;
    parametros += ',rango_precio_max:' + rango_precio_max;
    if (parametrosEspeciales != null) {
	parametros += "," + parametrosEspeciales;
    }
    
    callAjax(contenedor,funcionalidad,'pagina: 1, '+parametros+', div_contenedor: \''+contenedor+'\'');
    
}

/*Filtros de busqueda*/
function busquedaFiltros(parametrosEspeciales, contenedor)
{
    modalidad = $('#edit-opciones-modalidad').val();
    categoria = $('#edit-opciones-categoria').val();

    parametros  = 'modalidad:'+ modalidad;
    parametros += ',categoria:'+ categoria;
    if (parametrosEspeciales != null) {
    parametros += "," + parametrosEspeciales;
    }
    console.log(parametros);
    
    callAjax('contenedor_busqueda_general_cursos', 'show_busqueda_listado_cursos','pagina: 1, '+parametros+', div_contenedor: \''+contenedor+'\'');
    //callAjax('contador_resultados', 'show_contador_resultados',''+parametros+', div_contenedor: \''+contenedor+'\'');
}