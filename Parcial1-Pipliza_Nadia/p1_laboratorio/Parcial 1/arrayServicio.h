#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ARRAYSERVICIO_H_
#define ARRAYSERVICIO_H_

#define MAX_CHARS_CADENAS 30
#define T 2
#define VACIO 0
#define OCUPADO 1
#define BAJA -1

/* ********* ESTRUCTURAS ******************************************************************************* */
//isEmpty 0 vacio - 1 ocupado
typedef struct
{
    int   idProducto;
    char  descripcion[40];
    int   idTipoProducto;
    int   idNacionalidad;
    float precioProducto;
    int   isEmpty;
}eServicio;

typedef struct
{
    int   idTipoProducto;
    char  descTipo[40];
    int   isEmpty;
}eTrabajo;



/* ********* FUNCIONES ABM ***************************************************************************** */

//PRODUCTO
eServicio PedirDatosProducto();
int  CargarProductos(eServicio[], int);
int  ELiminarProductos(eServicio[], int);
int  ModificarProductos(eServicio[], int);
int  BuscarLibre(eServicio[], int);
void InicializarServicios(eServicio[], int);
int  BuscarProducto(eServicio[], int);
void InicializarServicio(eServicio[], int);
void HardcodearProductos(eServicio[],int);
void ModificarProducto(eServicio[],int,eTrabajo[],int);
void EliminarProducto(eServicio[], int,eTrabajo[], int);

//TIPO
eTrabajo CargarTipoDeServicio();
void EliminarTipo(eTrabajo listadoTipo[],int index);
int  BuscarTipo(eTrabajo[],int);
void InicializarTipo(eTrabajo[],int);

int  InsertarTipo(eTrabajo[],int);
void BorradoEnCascadaPorTipo(eTrabajo listadoTipo[],int index,eServicio listadoServicio[],int TamP);
//void menuModificacion(eTrabajo[],int,int);
int  BuscarTipoPorId(eTrabajo listadoTipo[],int TamT,int productoIDTipo);
int  ValidarTipoDelProducto(eTrabajo listadoTipo[],int TamT,int productoIDTipo);
void HardcodearTipoProductos(eTrabajo[],int);


/* ********* FUNCIONES MOSTRAR Y ORDENAR **************************************************************** */

void MostrarUnProductoCompleto(eServicio, eTrabajo);
void menuModificacionTipo(listadoTipo, index, TamT);
void MostrarTipoDeServicios(listadoTipo, TamT);

//PRODUCTO
eServicio CargarProducto(eServicio[],int,eTrabajo[],int);
void MostrarUnProducto(eServicio);
void MostrarlistadoServicios(eServicio[], int);
void OrdenarProductosPorDescripcion(eServicio[], int);
void OrdenarProductosPorPrecio(eServicio[], int);
int  BuscarProductoPorId(eServicio[],int, int);
void ValidarIdDelProducto(eServicio[],int,int);
void tomarUnProducto(eServicio[],int, eTrabajo);
void mostrarTotalListaProductos(eServicio[],int,eTrabajo[],int);
void MostrarListadoDeServiciosFiltradosPorPrecio(eServicio[],int,float);
void ordenarProductosPorPrecio(eServicio[], int);
void ordenarProductosPorDescripcion(eServicio[], int);
int  ProductoMasCaro(eServicio[], int);
int  CantidadTotalProductosCargados(eServicio[], int);
void MostrarUnProductoConIndex(eServicio[], eTrabajo[],int, int);

//TIPO
eTrabajo TomarUnTipo(eTrabajo[], int, eServicio);
void MostrarTiposDeServiciosConMasElaborados(eServicio[],int,eTrabajo[],int TamT);
int  TiposDeServiciosConMasElaborados(eServicio[],int,eTrabajo[],int tipo);
int  CalcularTipoConMasProductosElaborados(eServicio[],int,eTrabajo[],int TamT);
void InicializarPromedio(int,int[],float[],float[]);
void CargarPromedio(int ,eTrabajo[],eServicio [],int [],float [], int);
void MostrarPromedioPorTipo(float[],float [],int[],eTrabajo [],int );
void MostrarTiposDeServicios(eTrabajo[],int);
void MostrarUnTipoConIndex(eTrabajo listadoTipo[],int index);
int  TiposDeServiciosConMasElaborados(eServicio[],int,eTrabajo[],int);
void MostrarTiposDeServiciosConMasElaborados(eServicio listadoServicio[],int TamP,eTrabajo listadoTipo[],int TamT);
void MostrarTipoConProductos(eServicio[],int,eTrabajo[],int);
void MostrarProductosConDescripcionDeTipo(eServicio[],int,eTrabajo[]);
void PromedioPorTipo(eServicio[], int, eTrabajo[], int);


#endif /* ARRAYservicioS_H_ */
