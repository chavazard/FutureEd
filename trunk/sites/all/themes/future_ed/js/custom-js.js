/*-------------- MUESTRA U OCULTA MODALES DE NOTIFICACIONES ----------------------*/
/* Parametros: nombre del modal,
 *             booleano que indica si se mostrará u ocultará
 *             */
function mostrarModalNotificaciones(nombreModal){
    modalActual = document.getElementById(nombreModal);
    
    if (modalActual.style.display == 'none' || modalActual.style.display == '') 
        mostrar = true;
    else
        mostrar = false;
    
    mostrarElemento('modal-notificaciones', false);
    mostrarElemento('modal-opciones-perfil', false);
    mostrarElemento('modal-user-login-form', false);
    mostrarElemento(nombreModal, mostrar);
}

/*-------------- MUESTRA U OCULTA TABS ----------------------*/
/* Parametros: nombre del panel a mostrar
 *             nombre del tab que se selecciona
 *             sufijoEstilo para identificar que estilo de tab tomará
 * Muestra el panel y oculta los demás
 *
 * Modificada el 26 de Noviembre del 2014, por Ricardo Aguilera
 * Se hizo más generalizada la funcionalidad, para permitir que los ID de los títulos
 * pudieran ser cualquiera.
 *             */
function muestraPanelTab(nombrePanel, nombreTab, sufijoEstilo){

    sufijoEstilo != ""? sufijoEstilo="-"+sufijoEstilo : "";

    //console.log("   Función muestraPanelTab-->");
    //console.log("   nombrePanel:"+nombrePanel);
    //console.log("   nombreTab:"+nombreTab);

    var panel = jQuery("#"+nombrePanel);
    var tab = jQuery("#"+nombreTab);

    //console.log(panel);
    //console.log(tab);

    panel.parent().children().each(function(){
        //console.log("------------");
        //console.log($(this));
        $(this).removeClass("active-panel"+sufijoEstilo);
        $(this).addClass("inactive-panel"+sufijoEstilo);
        //console.log($(this));
    });
    tab.parent().children().each(function(){
        //console.log($(this));
        $(this).removeClass("active-tab"+sufijoEstilo);
        $(this).addClass("inactive-tab"+sufijoEstilo);
    });

    panel.addClass("active-panel"+sufijoEstilo);
    panel.removeClass("inactive-panel"+sufijoEstilo);
    tab.addClass("active-tab"+sufijoEstilo);
    tab.removeClass("inactive-tab"+sufijoEstilo);

    //console.log("   fin de ejecución muestraPanelTab");
}


/*-------------- MUESTRA U OCULTA TABS SI EL PANEL ESTA ACTUALMENTE MOSTRANDOSE LO OCULTA----------------------*/
/* Parametros: nombre del panel a mostrar
 *             nombre del tab que se selecciona
 * Muestra el panel y oculta los demás
 *
 *             */
function muestraPanelTabToogle(nombrePanel, nombreTab){
    var panel = jQuery("#"+nombrePanel);
    var tab = jQuery("#"+nombreTab);

    panelVisible =  $('#'+nombrePanel).hasClass('active-panel'); 
    

    panel.parent().children().each(function(){
        //console.log("------------");
        //console.log($(this));
        $(this).removeClass("active-panel");
        $(this).addClass("inactive-panel");
        //console.log($(this));
    });
    tab.parent().children().each(function(){
        //console.log($(this));
        $(this).removeClass("active-tab");
        $(this).addClass("inactive-tab");
    });

    if (panelVisible == false) {
        panel.addClass("active-panel");
        panel.removeClass("inactive-panel");
        tab.addClass("active-tab");
        tab.removeClass("inactive-tab");
    }else{
        panel.addClass("inactive-panel");
        panel.removeClass("active-panel");
        tab.addClass("inactive-tab");
        tab.removeClass("active-tab");        
    }

}


/*-------------- MUESTRA U OCULTA OPCIONES DE UN SUBMENU ----------------------*/
/* Parametros: nombre del padre que va a mostrar los hijos
 * Muestra los hijos de un padre y oculta los hijos de los otros padres, si estan visibles los hijos del padre los oculta
 * 
 *             */
function muestraChildsMenu(nombreElementoMenu){
    var elementoMenu = jQuery("#"+nombreElementoMenu);
    var padreMenu = elementoMenu.parent().parent();

    console.log(padreMenu);
    
    
    var elementosMenu = padreMenu.children();
    var tag;
    var submenu;
    actualmenteVisible =  elementoMenu.hasClass('active-menu-li'); 
    padreMenu.children().each(function(){        
        hijos = $(this).children();
        
        hijos.each(function(){
            submenu = $(this).hasClass('submenu');
            if (submenu == false) {
                $(this).addClass("inactive-menu-li");
                $(this).removeClass("active-menu-li"); 
            }else{
                $(this).removeClass("active-panel");
                $(this).addClass("inactive-panel");          
            }            
        });        

    });   

    if (actualmenteVisible == false) {
        elementoMenu.addClass("active-menu-li");
        elementoMenu.removeClass("inactive-menu-li");


        elementoMenu.parent().children().each(function(){
            submenu = $(this).hasClass('submenu');
            if (submenu == true) {
                $(this).addClass("active-panel");
                $(this).removeClass("inactive-panel");
            }
        });
    }else{
        elementoMenu.addClass("inactive-menu-li");
        elementoMenu.removeClass("active-menu-li");


        elementoMenu.parent().children().each(function(){
            submenu = $(this).hasClass('submenu');
            if (submenu == true) {
                $(this).addClass("inactive-panel");
                $(this).removeClass("active-panel");
            }
        });
    }
}





/*-------------- MUESTRA U OCULTA UN ELEMENTO ----------------------*/
/* Parametros: nombre del elemento,
 *             booleano que indica si se mostrará u ocultará
 *             */
function mostrarElemento(nombreElemento, mostrar) {
    elemento = document.getElementById(nombreElemento);
    if (elemento != undefined) {
        if (mostrar) {
            elemento.style.display = 'block';
        }else{
            elemento.style.display = 'none';
        }
    }
    
}


/*-------------- MUESTRA U OCULTA UN ELEMENTO, SI ESTA VISIBLE LO OCULTA, SINO LO MUESTRA ----------------------*/
/* Parametros: nombre del elemento,
 *             booleano que indica si se mostrará u ocultará
 *             */
function switchMostrarElemento(nombreElemento) {
    elemento = document.getElementById(nombreElemento);

    if (elemento.style.display == 'none' || elemento.style.display == '') 
        mostrar = true;
    else
        mostrar = false;

    if (elemento != undefined) {
        if (mostrar) {
            elemento.style.display = 'block';
        }else{
            elemento.style.display = 'none';
        }
    }
    
}


/*-------------- MANDA LLAMAR HOOK MENU PARA OBTENER DATOS Y MANEJARLOS CON JAVASCRIPT ----------------------*/
/* Parametros:  path que se va a mandar llamar,
 *             función de callback,
 *             parámetros para la función callback
 *             */

function obtenerInfoHookMenu(path, callBack, parametros){
    $.get(path,{status:1}, function(data){
                if (data != null){                                        
                        if (callBack != null) {
                            callBack(data, parametros);
                        }                                                                         
                }
                else{
                    //funcion para manejo de errores
                }										
    });
}

/*------------- OCULTA BANNER DE INVITACIÓN HEADER -----------------------------------------*/
function ocultarBannerHeader() {
    mostrarElemento('header-invitacion-suscribete',false);
    document.getElementById('main-container').className = 'main-cointainer-margin-top';
}


