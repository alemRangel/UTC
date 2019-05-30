#include <stdlib.h>
#include <stdio.h>

// Pongan en el main menuPila(),ex1(),ex2() o ex3() dependiendo lo que quieran probar

typedef struct Eslabon Eslabon;
struct Eslabon{
    int valor;
    Eslabon* ubicacion;
};

typedef Eslabon* Pila;

void inicializar(Pila* pila);
int pilaVacia(Pila* pila);
int apilar(Pila* pila);
int imprimirTodo(Pila* pila);
void imprimirPila(Eslabon* eslabon);
int ultimaApilada(Pila* pila);
int desapilar(Pila* pila);
void vaciarPila(Eslabon* eslabon);
int destruirPila(Pila* pila);
void menuPila();
void ex1();
void ex2();
void ex3();

int main(){
    ex1();
    return 0;
}

void inicializar(Pila* pila){
    *pila = NULL;
    printf("Pila inicializada \n");
}

int pilaVacia(Pila* pila){
 return (*pila == NULL)? 1:0;
}

int apilar(Pila* pila){
    Eslabon* nuevoEslabon;
    nuevoEslabon = (Eslabon*)malloc(sizeof(Eslabon));
    if(nuevoEslabon == NULL) 
        return 1;
    if(*pila == NULL){
         *pila = nuevoEslabon;
         nuevoEslabon -> ubicacion = NULL;
    }
    else{
        nuevoEslabon -> ubicacion = *pila;
        *pila = nuevoEslabon;
    }
    printf("Introduzca el valor de su nuevo eslabon\n");
    scanf("%d", &(nuevoEslabon->valor));
    printf("Apilado con exito \n");
    return 0;
}

void imprimirPila(Eslabon* eslabon)
{
    printf("Dato:%d \n", eslabon -> valor);
    if(eslabon -> ubicacion == NULL)
        return;
        
    imprimirPila(eslabon->ubicacion); 
}

int ultimaApilada(Pila* pila){
    if(pilaVacia(pila))
         return 1;
    Eslabon* ultimo;
    ultimo = *pila;
    printf("Ultimo elemento apilado: %d \n",ultimo->valor);
    return 0;
}

int desapilar(Pila* pila){
    if(pilaVacia(pila))
        return 1;
    Eslabon* ultimo;
    ultimo = *pila;
    *pila = ultimo->ubicacion;
    free(ultimo);
    printf("Desapilado con exito \n");
    return 0;
}

void vaciarPila(Eslabon* eslabon){
    if(eslabon->ubicacion==NULL)
        return;
    

    Eslabon* aux;
    aux = eslabon->ubicacion;
    free(eslabon);
    vaciarPila(aux);
}

int destruirPila(Pila* pila){
    if(pilaVacia(pila))
        return 1;
   vaciarPila(*pila);
   *pila = NULL;
   printf("Pila destruida \n");
   return 0;
}

int imprimirTodo(Pila* pila)
{
    if(pilaVacia(pila))
        return 1;
    imprimirPila(*pila);
    return 0;
}

void menuPila(){
    Pila pila;
    inicializar(&pila);
    int cont;
    int opc;

    do{
        printf("Seleccione una opcion: \n");
        printf("1- Apilar \n");
        printf("2- Desapilar \n");
        printf("3- Imprimir todo \n");
        printf("4- Ultima apilada \n");
        printf("5- Destuir Pila\n");
        scanf("%d",&opc);
        switch (opc)
        {
        case 1:
            apilar(&pila);
            break;
        
        case 2:
            if(desapilar(&pila))
                printf("La pila esta vacia \n");
            break;
        case 3:
            if(imprimirTodo(&pila))
                printf("La pila esta vacia \n");
            break;
        case 4:
            if(ultimaApilada(&pila))
                printf("La pila esta vacia \n");
            break;
        case 5:
            if(destruirPila(&pila))
                printf("La pila esta vacia \n");
            break;
        
        default:
            printf("Seleccioe un número valido \n");
            break;
        }

        printf("Desea seguir trabajando con la pila? 1/0 \n");
        scanf("%d",&opc);
    }while(opc==1);
}

void ex1(){
    Pila pila;
    inicializar(&pila);
    int opc;
    do{
        apilar(&pila);
        printf("Desea seguir apilando? 1/0\n");
        scanf("%d",&opc);
    }while(opc==1);
    imprimirTodo(&pila);
}