#ifndef SOLICITUD_DATOS_USUARIO_OK_H_
#define SOLICITUD_DATOS_USUARIO_OK_H_

int ingresoDeDatos();
int menuDeOpciones();
int opcionesParaModificar();

/* FUNCIONES MENÚES */
void menuAltas(eServicio[],int,eTrabajo[],int);
void menuBaja(eServicio[],int,eTrabajo[],int);
void menuModificacion(eServicio[],int,eTrabajo[],int);

/* ALTA PRODUCTOS*/
int CargaLibre(eServicio[], int);
int IngresarProducto(eServicio[], int,eTrabajo[],int);

/* ALTA TIPOS*/
int CargaLibreTipo(eTrabajo[],int);
int menuAltaTipo(eTrabajo listadoTipo[], int TamT);

/* BAJA TIPOS*/
void menuBajaTipo(listadoTipo, index);


#endif /* SOLICITUD_DATOS_USUARIO_OK_H_ */
