#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Tarea{
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
} Tarea;

typedef struct Nodo{
    Tarea T;
    struct Nodo *Siguiente;
} Nodo;

typedef struct Lista {
    Nodo* siguiente;
    int cantidad;
}Lista;
Lista crearLista();
Tarea crearTarea(int* ID);
Lista crearNodo(Lista L,Tarea T);
Lista moverNodo(Lista pendientes, Lista terminadas, int ID);
void verLista(Lista L);
void busquedaID(Lista L, int ID);
void busquedaPalabra(Lista L, char* palabra);
Lista borrarEspecifico(Lista L, int ID);

// pasos
// crear listas a realizar y terminadas
// Ingresar tareas en a realizar
// mover tareas a terminadas
// Hacer una interfaz de menu
// opciones del menu -> cargar tareas {ingrear los datos y luego -> agregar nueva || finalizar carga}, 
// ver tareas a realizar -> opciones{Elegir tarea hecha, volver al menu}, ver tareas realizadas
// Buscar tarea por id o palabra y mostrar -> mostrar estado

int main() {
    int tareaIDcont = 0;
    int menu = 1; // "booleano" para mantener el menu corriendo esperando la acción
    int opcion;
    int menuTareas = 1;
    char* palabra = (char*)malloc(100*sizeof(char));
    // Creo la lista pendientes
    Lista pendientes = crearLista();
    Lista terminadas = crearLista();
    Tarea T;
    int elegido;
    while (menu){
        puts("Que desea hacer:");
        puts("1. Cargar tareas pendientes ");
        puts("2. Ver tareas pendientes ");
        puts("3. Ver tareas terminadas ");
        puts("4. Marcar tareas como terminadas");
        puts("5. Buscar tarea por ID ");
        puts("6. Buscar tarea por palabra clave ");
        puts("7. Salir ");
        scanf(" %d",&opcion);
        getchar();
        while (opcion < 1 || opcion > 6){
            puts("Opcion elegida no valida, ingrese un valor del 1 al 6");
            scanf(" %d",&opcion);
            getchar();

        }
        switch(opcion){
            case 1: // cargar tareas
                T = crearTarea(&tareaIDcont);
                pendientes = crearNodo(pendientes,T);
                puts("Tarea ingresada!!");
                menuTareas = 1;
                while(menuTareas){
                    puts("Que desea hacer?");
                    puts("1. Ingresar otra tarea");
                    puts("2. Volver al anterior menu");
                    scanf(" %d", &opcion);
                    getchar();
                    while (opcion < 1 || opcion > 2){
                        puts("Opcion elegida no valida, ingrese un valor del 1 al 2");
                        scanf(" %d",&opcion);
                        getchar();
                    }
                    switch (opcion)
                    {
                    case 1:
                        T = crearTarea(&tareaIDcont);
                        pendientes = crearNodo(pendientes,T);
                        break;
                    case 2:
                        menuTareas = 0; 
                    break;
                    default:
                        break;
                    }

                }
            break;
            
            case 2: // Ver pendientes
                void verLista(pendientes);
            break;
            
            case 3: // Ver terminadas
                void verLista(terminadas);
            break;
            
            case 4: // Elegir tarea realizada
                void verLista(pendientes);
                puts("Elija el ID de la tarea a marcar como realizada");
                scanf(" %d", &elegido);
                terminadas = moverNodo(pendientes,terminadas,elegido);
            break;
            
            case 5: // busqueda por ID
            break;
            
            case 6: // busqueda por palabra

            break;

            case 7:
            menu = 0;
            break;
            
            default: 
            break;

        }

    }
    free(palabra);
    return 0;
}

Lista crearLista(){
    Lista L;
    L.siguiente=NULL;
    L.cantidad=0;
    return L;
}

Tarea crearTarea(int* ID){
    Tarea T;
    int duracion;
    char* buffer = (char*) malloc(200*sizeof(char));
    T.TareaID = *(ID) ++ ;
    *(ID) ++;
    puts("Ingrese una descripción de la tarea");
    gets(buffer);
    strcpy(T.Descripcion,buffer); 
    puts("Ingrese una duración de la tarea (del 10 al 100):");
    scanf(" %d",&duracion);
    T.Duracion = duracion;
    free(buffer);
    return T;
}

Lista crearNodo(Lista L,Tarea T){
    Nodo* nodo = (Nodo*) malloc(sizeof(Nodo));
    nodo->Siguiente = L.siguiente;
    nodo->T = T;
    L.cantidad++;
    return L;
}

Lista borrarEspecifico(Lista L, int ID){
    // trabajo con un nodo anterior, uno actual y el siguiente
    
    
    return L;
}

void verLista(Lista L){
    if (L.cantidad == 0){
        puts("Lista vacia");
    }else {
        while (L.siguiente != NULL){
            puts("Tareas: ");
            printf("ID: %d\n",L.siguiente->T.TareaID);
            printf("Descripcion: \n%s \n",L.siguiente->T.Descripcion);
            printf("Duracion: %d \n",L.siguiente->T.Duracion);
        }
    }
}

Lista moverNodo(Lista pendientes, Lista terminadas, int ID){
    while (pendientes.siguiente->T.TareaID != ID){
        terminadas = crearNodo(terminadas,pendientes.siguiente->T);
        pendientes = borrarEspecifico(pendientes, ID);
        return terminadas;
    }
    puts("ID no encontrado");
    return terminadas;
}