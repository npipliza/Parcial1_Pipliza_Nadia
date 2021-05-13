#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "arrayServicio.h"
#include "validaciones_P1.h"
#include "solicitud_datos_usuario_OK.h"

#define TamP 4
#define TamT 4
int mostrarOpciones;

int main()
{
    eServicio     listadoServicio[TamP];
    eTrabajo listadoTipo[TamT];

    setbuf(stdout, NULL);

    InicializarServicio(listadoServicio,TamP);
    InicializarTipo(listadoTipo,TamT);

  //  HardcodearTipoProductos(listadoTipo,TamT);
    HardcodearProductos(listadoServicio,TamP);

    printf("INICIO... \n");
    do
	{
    	mostrarOpciones = menuDeOpciones();

		switch(mostrarOpciones)
		{
			//ALTA PRODUCTO
			case 1:
				menuAltas(listadoServicio,TamP,listadoTipo,TamT);
			break;

			//BAJA PRODUCTO
			case 2:
				menuBaja(listadoServicio,TamP,listadoTipo,TamT);
			break;

			//MODIFICACION PRODUCTO
			case 3:
				menuModificacion(listadoServicio,TamP,listadoTipo,TamT);
			break;

			//MOSTRAR TOTAL PRODUCTOS
			case 4:
				mostrarTotalListaProductos(listadoServicio,TamP,listadoTipo,TamT);
			break;

			//MOSTRAR ORDENADOS POR PRECIO
			case 5:
				ordenarProductosPorPrecio(listadoServicio,TamP);
				mostrarTotalListaProductos(listadoServicio,TamP,listadoTipo,TamT);
			break;

			//MOSTRAR ORDENADOS POR DESCRIPCION
			case 6:
				ordenarProductosPorDescripcion(listadoServicio,TamP);
				mostrarTotalListaProductos(listadoServicio,TamP,listadoTipo,TamT);
			break;
		}//fin switch mostrarOpciones
	}while(mostrarOpciones != 0);

    printf("\n...PROGRAMA FINALIZADO.");
}//fin funcion main

