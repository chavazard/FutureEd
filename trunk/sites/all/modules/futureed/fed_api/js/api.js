jQuery(document).ready(function(){ // document.ready()

	$ = jQuery.noConflict();

	var api_url = Drupal.settings.basePath + 'api';
	
	

	$('.api-call').bind('click',function(){ // .api-call click()	
		
		//console.log($this);
		var params = {
			'f_name' : $(this).attr('id')
		}

		switch (params.f_name){
			case 'get_courses_nid':
				params.limit = $(this).data('limit');
				break;
			case 'get_courses_title':
				params.limit = $(this).data('limit');
				break;
			case 'get_user_name':
				params.uid = $(this).data('uid');
				break;
			/*case 'get_term_children':
				params.tid = $(this).data('tid');
				break;*/
		}

		var container_id = $(this).data('container');
		$.get(api_url,params,function(data){ // API Ajax		
			
			var markup = data;//syntaxHighlight(JSON.stringify(data, undefined, 2));
			//var container_id = $(this).data('container'); // Contiene el div donde se va a imprimir el resultado de AJAX
			//alert($(this).data);
			$('#'+container_id).html(markup);
		
		}); // API Ajax

	}); // .api-call click()

	// Format json in HTML
	function syntaxHighlight(json) {
    json = json.replace(/&/g, '&amp;').replace(/</g, '&lt;').replace(/>/g, '&gt;');
    return json.replace(/("(\\u[a-zA-Z0-9]{4}|\\[^u]|[^\\"])*"(\s*:)?|\b(true|false|null)\b|-?\d+(?:\.\d*)?(?:[eE][+\-]?\d+)?)/g, function (match) {
        var cls = 'number';
        if (/^"/.test(match)) {
            if (/:$/.test(match)) {
                cls = 'key';
            } else {
                cls = 'string';
            }
        } else if (/true|false/.test(match)) {
            cls = 'boolean';
        } else if (/null/.test(match)) {
            cls = 'null';
        }
        return '<span class="' + cls + '">' + match + '</span>';
    });
	}

}); // document.ready()
/*
$('.api-call').removeClass('active');
$(this).addClass('active');
*/

/* Función para cargar contenidos con Ajax
	contenedor: div donde se va a cargar el Ajax
	función: Función que se ejecutará
	parametros: Parametros personalizados de la función
*/
function callAjax(contenedor, funcion, parametros){ 
	//console.log(contenedor);
	//console.log(funcion);
	//console.log(parametros);
	var api_url = Drupal.settings.basePath + 'call-ajax';
	if (parametros != '' && parametros != null) 
		stringParametros = '{ f_name: "' + funcion + '", ' + parametros +' }';
	else
		stringParametros = "{ f_name: '"+funcion+"' }";

	var json = eval("("+stringParametros+")");


	console.log(json);
	jQuery('#'+contenedor).load(api_url, json, function( response, status, xhr ) {
		if ( status == "error" ) {			
			//manejo de errores
			//var msg = "Sorry but there was an error: ";
		        //$( "#error" ).html( msg + xhr.status + " " + xhr.statusText );			
		}
		//console.log(response);
		//console.log(status);
		//console.log(xhr);
		//return response;
	});
}

/* Función para agregar contenidos con Ajax y append
	contenedor: div donde se va a agregar el contenido Ajax
	función: Función que se ejecutará
	parametros: Parametros personalizados de la función
*/
function appendAjax(contenedor, funcion, parametros, callback, parametrosCallback){
	var api_url = Drupal.settings.basePath + 'call-ajax';
	
	if (parametros != '' && parametros != null) 
		stringParametros = '{ f_name: "' + funcion + '", ' + parametros +' }';
	else
		stringParametros = "{ f_name: '"+funcion+"' }";

	var json = eval("("+stringParametros+")");

	//jQuery('#'+contenedor).post('call-ajax', json, function( response, status, xhr ) {
	//alert(stringParametros);
	//$.post(api_url,json,function(data){ // API Ajax
	jQuery.post(api_url, json, function( data ) {
		$( "#"+contenedor ).append( data );
	});


}


