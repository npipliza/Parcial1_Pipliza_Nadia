#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayServicio.h"
#include "solicitud_datos_usuario_OK.h"
#include "Validaciones_P1.h"

int menuDeOpciones()
{
	int numero;

	printf("\nINGRESE UNA OPCIÓN: ***********************************************\n"
		   "1.  ALTA .\n"
		   "2.  BAJA .\n"
		   "3.  MODIFICAR .\n"
		   "4.  MOSTRAR Listado.\n"
		 //  "5.  MOSTRAR Productos ordenados por precio.\n"
		  // "6.  MOSTRAR Productos ordenados por descripción.\n"
		   "0.  SALIR\n"
		   "Elija una opción: \n");

	scanf("%d", &numero);

	return numero;
}//fin funcion menuDeOpciones

/* ***** MENÚ ALTAS **************************************************************************************** */
void menuAltas(eServicio listadoProducto[],int TamP,eTrabajo listadoTipo[],int TamT)
{
	int opcion;
	do
	{
		printf("Seleccione ÍTEM a dar de ALTA:\n"
			   "1. Servicio\n"
			   "2. Trabajo\n"
			   "0. SALIR\n");
		scanf("%d",&opcion);

	    switch(opcion)
	    {
	       //ALTA PRODUCTOS
		   case 1:
			   CargaLibre(listadoProducto,TamP);
			   IngresarProducto(listadoProducto,TamP, listadoTipo, TamT);
				system("pause");
		   break;

		   //ALTA TIPOS
		   case 2:
			   CargaLibreTipo(listadoTipo,TamT);
			   menuAltaTipo(listadoTipo,TamT);
				system("pause");
		   break;

	    }//fin switch

	 }while(opcion != 0);
}//fin funcion menuAltas


/* ***** MENÚ BAJAS *************************************************************************************** */
void menuBaja(eServicio listadoProducto[], int TamP, eTrabajo listadoTipo[], int TamT)
{
	int index;
	int opcion;

	do
	{
		printf("Seleccione ÍTEM a dar de BAJA:\n"
			   "1. Servicio\n"
			   "2. Trabajo\n"
			   "0. SALIR\n");
		scanf("%d",&opcion);

		   switch(opcion)
		   {
			   case 1:
				   index = BuscarProducto(listadoProducto, TamP);
				   if(index == -1)
				   {
						printf("El ID Producto ingresado no fue encontrado.\n");
				   }
				   else
				   {
						printf("ID Producto encontrado...\n");
						EliminarProducto(listadoProducto, index, listadoTipo, TamT);

				   }
					system("pause");
			   break;

			   case 2:
				    index = BuscarTipo(listadoTipo,TamT);
					if(index == -1)
					{
						printf("El ID Tipo ingresado no fue encontrado.\n");
					}
					else
					{
						printf("ID Tipo encontrado...\n");
						menuBajaTipo(listadoTipo, index);
						BorradoEnCascadaPorTipo(listadoTipo, index, listadoProducto, TamP);
					}
					system("pause");
			   break;

		   }//fin switch
      }while(opcion != 0);
}//fin funcion menuBaja


/* ***** MENÚ MODIFICACIONES ****************************************************************************** */
void menuModificacion(eServicio listadoProducto[], int TamP, eTrabajo listadoTipo[], int TamT)
{
	int index;
	int opcion;

	do
	{
		printf("Seleccione ÍTEM a MODIFICAR:\n"
			   "1. Producto\n"
			   "2. Tipo\n"
			   "3. Nacionalidad\n"
			   "0. SALIR\n");
		scanf("%d",&opcion);

		   switch(opcion)
		   {
		       //MODIFICAR PRODUCTO
			   case 1:
				   index = BuscarProducto(listadoProducto, TamP);
					if(index == -1)
					{
						printf("El ID Producto ingresado no fue encontrado.\n");
					}
					else
					{
						printf("ID Producto encontrado...\n");
						ModificarProducto(listadoProducto, index, listadoTipo, TamT);
					}
					system("pause");
					break;
			   break;

			   //MODIFICAR TIPO
			   case 2:
					index = BuscarTipo(listadoTipo, TamT);
					if(index == -1)
					{
						printf("El ID Tipo ingresado no fue encontrado.\n");
					}
					else
					{
						printf("ID Tipo encontrado...\n");
						menuModificacionTipo(listadoTipo, index, TamT);
					}
					system("pause");
			   break;

		   }//fin switch
	  }while(opcion != 0);
}//fin funcion menuModificacion
