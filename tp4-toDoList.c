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

void crearTarea();
void crearNodo();
void moverNodo();
void verLista();
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
    char* buffer = (char*) malloc(100*sizeof(char));
    int opcion;
    while (menu){
        puts("Que desea hacer:");
        puts("1. Cargar tareas pendientes ");
        puts("2. Ver tareas pendientes ");
        puts("3. Ver tareas terminadas ");
        puts("4. Buscar tarea por ID ");
        puts("5. Buscar tarea por palabra clave ");
        puts("6. Salir ");
        scanf(" %d",&opcion);
        getchar();
        while (opcion < 1 || opcion > 6){
            puts("Opcion elegida no valida, ingrese un valor del 1 al 6");
            scanf(" %d",&opcion);
            getchar();
        }
        switch(opcion){
            case 1:
                
            break;
            
            case 2: 
            break;
            
            case 3: 
            break;
            
            case 4: 
            break;
            
            case 5: 
            break;
            
            case 6: 
            break;
            
            default: 
            break;

        }

    }
    return 0;
}