#include "arrayServicio.h"
#include "validaciones_P1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "solicitud_datos_usuario_OK.h"

eServicio listaDeServicios[T];
eServicio elProducto;

int pedirDatos;
int modificarDatos;
int idIncremento = 19999;
int idProducto;

/* INICIALIZAR ESTRUCTURAS */
/* ******************************************************************************************************* */
void InicializarServicio(eServicio listadoServicio[], int TamP)
{
	int i;

	for (i = 0; i < TamP; i++)
	{
		listadoServicio[i].isEmpty = VACIO;
	}//fin for
}//fin funcion InicializarServicio

/* ******************************************************************************************************* */
void InicializarTipo(eTrabajo listadoTipo[], int TamT)
{
	int i;

	for (i = 0; i < TamT; i++)
	{
		listadoTipo[i].isEmpty = VACIO;
	}//fin for
}//fin funcion InicializarTipo


/* DATOS HARDCODEADOS DE ESTRUCTURAS */
//Servicios (Limpieza: $250, Parche: $300, Centrado: $400, Cadena: $350)
/* ******************************************************************************************************* */
void HardcodearProductos(eServicio listadoServicio[], int TamP)
{
	int   i;
	int   idProducto[]   = {20000, 20001, 20002, 20003, 20004};
	int  Limpieza[][40] = {250, 250, 250, 250, 250};
	int  Parche[][40]   = {300,300,300,300,300};
	int  Centrado[][40] = {400,400,400,400,400};
	int  Cadena[][40]   = {350,350,350,350,350};
	//float precio[]          = {54200.50, 45000, 250450.45, 150400};
	int   isEmpty[]      = {OCUPADO, OCUPADO, OCUPADO, OCUPADO};

	for(i = 0; i < TamP; i++)
	{
		listadoServicio[i].idProducto       = idProducto[i];
		//strcpy(listadoServicio[i].descripcion,descripcion[i]);
	//	listadoServicio[i].idNacionalidad   = nacionalidad[i];
	//	listadoServicio[i].idTipoProducto   = tipo[i];
	//	listadoServicio[i].precioProducto   = precio[i];
		listadoServicio[i].isEmpty          = isEmpty[i];
	}//fin for
}//fin funcion HardcodearProductos

/* ******************************************************************************************************* */
/*void HardcodearTipoProductos(eTrabajo listadoTipo[], int TamT)
{
	int i;
	int idTipoProducto[] = {1000, 1001, 1002, 1003};
	char descTipo[][40]  = {"Tabletas", "Monitores", "PC", "Varios"};
    int isEmpty[]        = {OCUPADO, OCUPADO, OCUPADO, OCUPADO};

	for(i = 0; i < TamT; i++)
	{
		listadoTipo[i].idTipoProducto = idTipoProducto[i];
		strcpy(listadoTipo[i].descTipo,descTipo[i]);
		listadoTipo[i].isEmpty        = isEmpty[i];
	}//fin for
}//fin funcion HardcodearTipoProductos
*/

/* ALTA PRODUCTOS */
/* ******************************************************************************************************** */
int CargaLibre(eServicio listadoServicio[], int TamP)
{
	int i;
	int index;
	index = -1;

	for (i = 0; i < TamP; i++)
	{
		if (listadoServicio[i].isEmpty == VACIO)
		{
			index = i;
			break;
		}
	}//fin for
	return index;
}//fin funcion CargaLibre

/* ******************************* */
int IngresarProducto(eServicio listadoServicio[], int TamP, eTrabajo listadoTipo[], int TamT)
{
	int index;
	index = CargaLibre(listadoServicio,TamP);

	if (index == -1)
	{
		printf("ATENCIÓN! No queda espacio para seguir ingresando servicios.\n");
	}
	else
	{
		listadoServicio[index] = CargarProducto(listadoServicio, TamP, listadoTipo, TamT);
		printf("Servicio ingresado con éxito:\n");
		MostrarUnProductoConIndex(listadoServicio, listadoTipo, TamT, index);
	}
	return 0;
}//fin funcion IngresarProducto


/*ALTA TIPOS */
/* ******************************************************************************************************** */
int CargaLibreTipo(eTrabajo listadoTipo[], int TamT)
{
	int i;
	int index;
	index = -1;

	for (i = 0; i < TamT; i++)
	{
		if (listadoTipo[i].isEmpty == VACIO)
		{
			index = i;
			break;
		}
	}//fin for
	return index;
}//fin funcion CargaLibreTipo

/* ******************************* */
int menuAltaTipo(eTrabajo listadoTipo[], int TamT)
{
	int index;
	index = CargaLibreTipo(listadoTipo, TamT);

		if (index == -1)
		{
			printf("ATENCIÓN! No queda espacio para seguir ingresando tipos de trabajos\n");
		}
		else
		{
			listadoTipo[index] = CargarTipoDeServicio();
			printf("Tipo de trabajo ingresado con éxito:\n");
	//		MostrarUnTipoConIndex(listadoTipo, TamT, index);
		}
		return 0;
}//fin funcion menuAltaTipo


/*BAJA PRODUCTO */
/* ******************************************************************************************************* */
void EliminarProducto(eServicio producto[], int index, eTrabajo tipo[], int TamT)
{
    int opcion;

    MostrarUnProductoConIndex(producto, tipo, TamT, index);
	printf("\nIngrese 1 para CONFIRMAR: ");
	scanf("%d", &opcion);

	if (opcion == 1)
	{
		producto[index].isEmpty = VACIO;
		printf("Servicio eliminado con éxito.\n");
		MostrarUnProductoConIndex(producto, tipo, TamT, index);
	}
	else
	{
		printf("Operación cancelada.\n");
	}
}//fin funcion EliminarProducto


/*BAJA TIPO */
/* ******************************************************************************************************* */
void menuBajaTipo(eTrabajo listadoTipo[], int index)
{
	int opcion;
	MostrarUnTipoConIndex(listadoTipo, index);

	printf("\nIngrese 1 si desea eliminar el tipo: ");
	scanf("%d", &opcion);

	if (opcion == 1)
	{
		listadoTipo[index].isEmpty = VACIO;
		printf("Trabajo eliminado con éxito:\n");
	}
	else
	{
		printf("Operación cancelada.\n");
	}
}//fin funcion menuBajaTipo


/* MODIFICAR PRODUCTO */
/* ******************************************************************************************************* */
void ModificarProducto(eServicio listadoServicio[], int index, eTrabajo listadoTipo[], int TamT)
{
	int opcion;

	MostrarUnProductoConIndex(listadoServicio,listadoTipo,TamT,index);

	printf("\nIngrese: \n1. para modificar precio \n2. para modificar tipo de producto: ");
	scanf("%d", &opcion);

	while(opcion != 1 && opcion != 2)
	{
		printf("\nERROR.Ingrese: \n1. para modificar precio \n2. para modificar tipo de producto: ");
		scanf("%d", &opcion);
	}//fin while

	switch(opcion)
	{
	    case 1:
			listadoServicio[index].precioProducto = /*getFloatNew*/ printf("\nIngrese nuevo precio: ","ERROR.Ingrese nuevo precio: ");
			printf("\n Precio modificado: \n");
			MostrarUnProductoConIndex(listadoServicio, listadoTipo, TamT, index);
		break;

		case 2:
			MostrarTipoDeServicios(listadoTipo, TamT);
			listadoServicio[index].idTipoProducto = getIntNew("\nIngrese ID tipo producto: ","ERROR.Ingrese ID tipo producto: ");
			ValidarTipoDelProducto(listadoTipo,TamT,listadoServicio[index].idTipoProducto);
			printf("\n Tipo modificado: \n");
			MostrarUnProductoConIndex(listadoServicio,listadoTipo,TamT,index);
		break;
	}//fin switch
}//fin funcion ModificarProducto


/* MODIFICAR TIPO */
/* ******************************************************************************************************* */
void menuModificacionTipo(eTrabajo listadoTipo[], int index, int TamT)
{
	int opcion;

	MostrarUnTipoConIndex(listadoTipo, index);

	printf("\nIngrese para modificar: 1.descripcion de tipo o 2.para salir : ");
	scanf("%d", &opcion);

	while(opcion != 1 && opcion != 2)
	{
		printf("\nERROR. Ingrese para modificar: 1.descripcion de tipo o 2.para salir : ");
		scanf("%d", &opcion);
	}//fin while

	switch(opcion)
	{
		case 1:
		getStringWithNumbers(listadoTipo[index].descTipo, sizeof(listadoTipo[index].descTipo),
				             "Ingrese la nueva descripcion del tipo: ","ERROR. Ingrese la nueva descripcion del tipo: ");

		printf("\n Descripcion modificada: \n");
		MostrarUnTipoConIndex(listadoTipo, index);
		break;
	}//fin switch
}//fin funcion menuModificacionTipo


/* FUNCIONES BUSCAR */
/* ******************************************************************************************************* */
int BuscarProducto(eServicio producto[], int tam)
{
    int i;
	int idProducto;
	int index;
	index = -1;

	printf("Ingrese ID del producto: ");
	scanf("%d", &idProducto);

	for (i = 0; i < tam; i++)
	{
		if (idProducto == producto[i].idProducto && producto[i].isEmpty != VACIO)
		{
			index = i;
			break;
		}
	}//fin for
	return index;
}//fin funcion BuscarProducto

/* ******************************************************************************************************* */
int BuscarTipo(eTrabajo listadoTipo[],int TamT)
{
	int i;
	int idTipo;
	int index;
	index=-1;

	printf("Ingrese la id del tipo: ");
	scanf("%d", &idTipo);

	for (i=0;i<TamT;i++)
	{
		if (idTipo==listadoTipo[i].idTipoProducto&&listadoTipo[i].isEmpty!=VACIO)
		{
			index=i;
			break;
		}
	}
	return index;
}


/* ******************************************************************************************************* */
int BuscarProductoPorId(eServicio listadoServicio[], int TamP, int productoID)
{
	int index = -1;
	int i;
	for (i = 0; i < TamP; i++)
	{
		if (productoID == listadoServicio[i].idProducto && listadoServicio[i].isEmpty != VACIO)
		{
			index = i;
			break;
		}
	}//fin for
	return index;
}//fin funcion BuscarProductoPorId


/* ******************************************************************************************************* */
int BuscarTipoPorId(eTrabajo listadoTipo[], int TamT, int productoIDTipo)
{
	int index = -1;
	int i;

	for (i = 0; i < TamT; i++)
	{
		if (productoIDTipo == listadoTipo[i].idTipoProducto && listadoTipo[i].isEmpty != VACIO)
		{
			index = i;
			break;
		}
	}//fin for
	return index;
}//fin funcion BuscarTipoPorId


/* FUNCIONES AUXILIARES, MOSTRAR Y ORDENAR */
/* ******************************************************************************************************* */
eServicio CargarProducto(eServicio listadoServicio[], int TamP, eTrabajo listadoTipo[], int TamT)
{
    eServicio producto;

    producto.idProducto     = getIntNew("Ingrese ID para el producto: ","ERROR. Ingrese ID para el producto: ");
    ValidarIdDelProducto(listadoServicio, TamP, producto.idProducto);

    getStringWithNumbers(producto.descripcion,sizeof(producto.descripcion),"Ingrese la descripcion del producto: ","ERROR. Ingrese la descripcion del producto: ");

    MostrarTipoDeServicios(listadoTipo, TamT);
    producto.idTipoProducto = getIntNew("Ingrese ID del tipo de producto: /n","ERROR. Ingrese ID del tipo de producto: /n");
    producto.idTipoProducto = ValidarTipoDelProducto(listadoTipo, TamT, producto.idTipoProducto);
    //producto.precioProducto = getFloatNew("Ingrese el precio del producto: ","ERROR. Ingrese el precio del producto: ");
    producto.isEmpty        = OCUPADO;

    return producto;
}//fin funcion CargarProducto

/* ******************************************************************************************************* */
eTrabajo TomarUnTipoUnTipo(eTrabajo listadoTipo[], int tamanio, eServicio listadoServicio)
{
	int i;
	eTrabajo auxTipo;

	for(i = 0; i < tamanio; i++)
	{
		if(listadoTipo[i].idTipoProducto == listadoServicio.idTipoProducto)
		{
			auxTipo = listadoTipo[i];
		}
	}//fin for
	return auxTipo;
}//fin funcion TomarUnTipo

/* ******************************************************************************************************* */
eTrabajo CargarTipoDeServicio()
{
	eTrabajo tipoDelProducto;

	tipoDelProducto.idTipoProducto = getIntNew("Ingrese un id del tipo de producto: /n","ERROR.Ingrese un id del tipo de producto: /n");
	getStringWithNumbers(tipoDelProducto.descTipo,sizeof(tipoDelProducto.descTipo),"Ingrese la descripcion del tipo: ","ERROR.Ingrese la descripcion del tipo: ");
	tipoDelProducto.isEmpty        = OCUPADO;

	return tipoDelProducto;
}//fin funcion CargarTipoDeServicio



/* ******************************************************************************************************* */
void mostrarTotalListaProductos(eServicio listadoServicio[], int TamP, eTrabajo listadoTipo[], int TamT)
{
	int i;
	eTrabajo tipoDelProducto;

	for(i = 0; i < TamP; i++)
	{
		//tipoDelProducto         = tomarUnTipo(listadoTipo, TamT, listadoServicio[i]);

		MostrarUnProductoCompleto(listadoServicio[i], tipoDelProducto);
	}//fin for
}//fin funcion mostrarTotalListaProductos

/* ******************************************************************************************************* */
void MostrarUnProductoCompleto(eServicio listadoServicio, eTrabajo listadoTipo)
{
	if(listadoServicio.isEmpty == OCUPADO)
	{
		printf("ID del producto: %d | "
			   "Producto: %s | "
			   "Tipo: %s | "
			   "Precio:%.2f \n", listadoServicio.idProducto,
								 listadoServicio.descripcion,
							     listadoTipo.descTipo,
								 listadoServicio.precioProducto);
	}//fin if mostrar
}//fin funcion MostrarUnProductoCompleto



/* ******************************************************************************************************* */
void  ValidarIdDelProducto(eServicio listadoServicio[], int TamP, int productoID)
{
	int index;
	index = BuscarProductoPorId(listadoServicio, TamP, productoID);

	while(index != -1)
	{
		productoID = getIntNew("El ID elegido ya fue utilizado, ingrese otro ID para el producto: ","ERROR. Ingrese ID para el producto: ");
		index      = BuscarProductoPorId(listadoServicio,TamP,productoID);
	}//fin while
}//fin funcion ValidarIdDelProducto

/* ******************************************************************************************************* */
void ordenarProductosPorPrecio(eServicio producto[], int tam)
{
	int i;
	int j;
	eServicio auxiliar;

	for(i = 0; i < tam-1; i++)
	{
		for (j = i+1; j < tam; j++)
		{
			if (producto[i].precioProducto>producto[j].precioProducto)
			{
				auxiliar    = producto[i];
				producto[i] = producto[j];
				producto[j] = auxiliar;
			}
		}
	}//fin for
}//fin funcion ordenarProductosPorPrecio




/* ******************************************************************************************************* */
void ordenarProductosPorDescripcion(eServicio producto[], int tam)
{
	int i;
	int j;
	eServicio auxiliar;

	for(i = 0; i < tam-1; i++)
	{
		for (j = i+1; j < tam; j++)
		{
			if (strcmp(producto[i].descripcion,producto[j].descripcion) >= 0)
			{
				auxiliar    = producto[i];
				producto[i] = producto[j];
				producto[j] = auxiliar;
			}
		}//fin for j
	}//fin for i
}//fin funcion ordenarProductosPorDescripcion


/* ******************************************************************************************************* */
int CantidadTotalProductosCargados(eServicio producto[], int tam)
{
	int i;
	int totalProductosCargados;

	for(i = 0; i < tam; i++)
	{
		if(producto[i].isEmpty == OCUPADO)
		{
			totalProductosCargados = i+1;
		}
	}//fin for
	return totalProductosCargados;
}//fin funcion CantidadtotalProductosCargados

/* ******************************************************************************************************* */
void PromedioPorTipo(eServicio producto[], int TamPsCargados, eTrabajo tipoProducto[], int TamT)
{
	float promedio[TamT];
	float acumulador[TamT];
	int   contador[TamT];

	InicializarPromedio(TamT,contador,acumulador,promedio);
    CargarPromedio(TamPsCargados,tipoProducto,producto,contador,acumulador,TamT);
    MostrarPromedioPorTipo(promedio,acumulador,contador,tipoProducto,TamT);
}

/* ******************************************************************************************************* */
void InicializarPromedio(int tamanio, int contador[], float acumulador[], float promedio[])
{
	int i;

	for(i = 0; i < tamanio; i++)
	{
		contador[i]   = 0;
		acumulador[i] = 0;
		promedio[i]   = 0;
	}//fin for
}//fin funcion InicializarPromedio


/* ******************************************************************************************************* */
void CargarPromedio(int TamPsCargados, eTrabajo tipoProducto[], eServicio producto[], int contador[], float acumulador[], int TamT)
{
	int j;
	int i;

	for(i = 0; i < TamT; i++)
	{
		for(j = 0; j < TamPsCargados; j++)
		{
			if((producto[j].idTipoProducto == tipoProducto[i].idTipoProducto) && producto[j].isEmpty == OCUPADO && tipoProducto[i].isEmpty == OCUPADO)
			{
				contador[i]++;
				acumulador[i] = acumulador[i] + producto[j].precioProducto;
			}
		}//fin for j
	}//fin for i
}//fin funcion CargarPromedio

/* ******************************************************************************************************* */
void MostrarPromedioPorTipo(float promedio[], float acumulador[], int contador[], eTrabajo tipoProducto[], int TamT)
{
	int i;

	for(i = 0; i < TamT; i++)
	{
		if(tipoProducto[i].isEmpty == OCUPADO)
		{
			promedio[i] = (float)acumulador[i] / contador[i];

			if(acumulador[i] == 0 && tipoProducto[i].isEmpty == OCUPADO)
			{
				printf("No hay productos cargados de tipo: %s\n",tipoProducto[i].descTipo);
			}
			else
			{
				printf("El precio promedio de %s es: %.2f\n",tipoProducto[i].descTipo,promedio[i]);
			}
		}//fin if ocupado
	}//fin for
}//fin funcion MostrarPromedioPorTipo


/* ******************************************************************************************************* */
int ProductoMasCaro(eServicio producto[], int tam)
{
	int maximo;
	int i;

	maximo = 0;

	for(i = 0; i < tam; i++)
	{
		if((maximo == 0 || producto[i].precioProducto>maximo) && producto[i].isEmpty == OCUPADO)
		{
			maximo = producto[i].precioProducto;
		}
	}//fin for
	return maximo;
}//fin funcion ProductoMasCaro

/* ******************************************************************************************************* */
void MostrarTipoConProductos(eServicio listadoServicio[], int TamP, eTrabajo listadoTipo[], int TamT)
{
	int i;

	for(i = 0; i < TamT; i++)
	{
		if(listadoTipo[i].isEmpty == OCUPADO)
		{
			printf("%d--%s\n", listadoTipo[i].idTipoProducto, listadoTipo[i].descTipo);
			tomarUnProducto(listadoServicio, TamP, listadoTipo[i]);
		}
	}//fin for
}//fin funcion MostrarTipoConProductos

/* ******************************************************************************************************* */
void MostrarProductosConDescripcionDeTipo(eServicio listadoServicio[], int TamP, eTrabajo listadoTipo[])
{
	int i;
	eTrabajo tipoDelProducto;

	for(i = 0; i < TamP; i++)
	{
		if(listadoServicio[i].isEmpty == OCUPADO)
		{
			printf("\n%d | %s\n", listadoServicio[i].idTipoProducto, listadoServicio[i].descripcion);
		//	tipoDelProducto=TomarUnTipo(listadoTipo, TamP, listadoServicio[i]);
			printf("%s", tipoDelProducto.descTipo);
		}
	}//fin for
}//fin funcion MostrarProductosConDescripcionDeTipo

/* ******************************************************************************************************* */
void tomarUnProducto(eServicio listadoServicio[], int TamP, eTrabajo listadoTipo)
{
	int i;

	for(i = 0; i < TamP; i++)
	{
		if(listadoServicio[i].isEmpty == OCUPADO && (listadoTipo.idTipoProducto == listadoServicio[i].idTipoProducto))
		{
			printf("\t%d--%s\n", listadoServicio[i].idProducto, listadoServicio[i].descripcion);
		}
	}//fin for
}//fin funcion tomarUnProducto

/* ******************************************************************************************************* */
void MostrarUnProductoConIndex(eServicio producto[], eTrabajo tipo[], int TamT, int index)
{
	int i;

	for (i = 0; i < TamT; i++)
	{
			if (producto[index].idTipoProducto == tipo[i].idTipoProducto)
			{
			   printf("%d | %s | $%.2f | %s\n", producto[index].idProducto, tipo[i].descTipo, producto[index].precioProducto, producto[index].descripcion);
			   break;
			}
	}//fin for i
}//fin funcion MostrarUnProductoConIndex





/* ******************************************************************************************************* */
void BorradoEnCascadaPorTipo(eTrabajo unTipo[], int index, eServicio listadoServicio[], int TamP)
{
	int i;

	for(i = 0; i < TamP; i++)
	{
		if(unTipo[index].idTipoProducto == listadoServicio[i].idTipoProducto && listadoServicio[i].isEmpty == OCUPADO)
		{
			listadoServicio[i].isEmpty = VACIO;
		}
	}//fin for
}//fin funcion BorradoEnCascadaPorTipo

/* ******************************************************************************************************* */
int ValidarTipoDelProducto(eTrabajo listadoTipo[], int TamT, int productoIDTipo)
{
	int index;
	index = BuscarTipoPorId(listadoTipo, TamT, productoIDTipo);

	while(index == -1)
	{
		MostrarTipoDeServicios(listadoTipo, TamT);
		productoIDTipo = getIntNew("ERROR.Ingrese un id DISPONIBLE \n","ERROR.Ingrese un id DISPONIBLE (Los que se encuentran en la lista)/n");
		index          = BuscarTipoPorId(listadoTipo, TamT, productoIDTipo);
	}//fin while
	return productoIDTipo;
}//fin funcion ValidarTipoDelProducto


/* ******************************************************************************************************* */
void MostrarTipoDeServicios(eTrabajo tipo[], int TamT)
{
	int i;
	printf("Tipos de Producto:\n");

	for(i = 0; i < TamT; i++)
	{
		if(tipo[i].isEmpty == OCUPADO)
		{
			printf("ID: %d | Tipo: %s\n", tipo[i].idTipoProducto, tipo[i].descTipo);
		}
	}//fin for
}//fin funcion MostrarTipoDeServicios

/* ******************************************************************************************************* */
void MostrarUnTipoConIndex(eTrabajo listadoTipo[], int index)
{
	printf("%d | %s\n", listadoTipo[index].idTipoProducto, listadoTipo[index].descTipo);
}//fin funcion MostrarUnTipoConIndex

