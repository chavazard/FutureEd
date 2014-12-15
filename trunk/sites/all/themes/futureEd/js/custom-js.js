//console.log(Drupal.settings.path);


/*-------------- MUESTRA U OCULTA MODALES DE NOTIFICACIONES ----------------------*/
/* Parametros: nombre del modal,
 *             booleano que indica si se mostrará u ocultará
 *             */
function mostrarModalNotificaciones(nombreModal){
    modal1 = document.getElementById('modal-notificaciones');
    
    modalActual = document.getElementById(nombreModal);
    
    if (modalActual.style.display == 'none' || modalActual.style.display == '') 
        mostrar = true;
    else
        mostrar = false;
    
    modal1.style.display = 'none';
    
    mostrarElemento(nombreModal, mostrar);
}

/*-------------- MUESTRA U OCULTA TABS ----------------------*/
/* Parametros: nombre del panel a mostrar
 *             nombre del tab que se selecciona
 *             sufijoEstilo para identificar que estilo de tab tomará
 * Muestra el panel y oculta los demás
 *             */
function muestraPanelTab(nombrePanel, nombreTab, sufijoEstilo){
    var i = 1;
    var encontrado = true;
    var elemento;
    var tab;
    var  arrNombrePanel = nombrePanel.split("-");
    var  arrNombreTab   = nombreTab.split("-");
    var prefijoPanel = arrNombrePanel[0];
    var prefijoTab   = arrNombreTab[0];
    
    if (sufijoEstilo != '') {
        sufijoEstilo = '-' + sufijoEstilo;
    }
    
    while (encontrado == true) {
        elemento = document.getElementById(prefijoPanel+'-'+i);
        tab = document.getElementById(prefijoTab+'-'+i);
        if (elemento == null || tab == null) {
            return;
        }else{
            if (nombrePanel != prefijoPanel+'-'+i) {
                elemento.className = "inactive-panel"+sufijoEstilo;
                tab.className = "row tab"+sufijoEstilo+" inactive-tab"+sufijoEstilo;
            }else{
                elemento.className = "active-panel"+sufijoEstilo;
                tab.className = "row tab"+sufijoEstilo+" active-tab"+sufijoEstilo;
            }           
        }
        i++;
    } 
}



/*-------------- MUESTRA U OCULTA UN ELEMENTO ----------------------*/
/* Parametros: nombre del modal,
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
<<<<<<< .mine
            
            
   });	*/
}

function buscaComentarios()
{
    alert('busca');
    llamaServicioAjax();
}


function muestraComentarios(json, parametros)
{
    alert('llegas');
}

function manejarRespuestaAjax(){
    alert("exito");
}


/*-------------- AGREGAR/ELIMINAR ELEMENTOS EN UNA LISTA ----------------------*/
/* 
 *             
 *
 */

 =======
                else{
                    //funcion para manejo de errores
                }										
    });
}>>>>>>> .r69
