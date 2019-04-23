

TP5
Recibidos
x

Alejandro Rangel <buffalem@gmail.com>
Archivos adjuntos
6 mar. 2019 18:32 (hace 6 días)
para mí


2 archivos adjuntos
En este momento, los exploradores de virus de Gmail no están disponibles – No se analizaron los archivos adjuntos en busca de virus. Descárgalos bajo tu responsabilidad.

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void ex1();
void imprimir(int* puntA,int size);


int main(){
ex1();
return 0;
}

void ex1(){
 int mediaT[MAX];
 int max=0,min=20,suma=0,media,cond;

 for(int i=0; i<MAX; ++i){
    cond=1;
    while(cond){
        printf("Escriba la calificion %d \n",i+1);
        scanf("%d",&mediaT[i]);
        if(mediaT[i]>=0 && mediaT[i]<=20)
            cond=0;
    }
    suma += mediaT[i];
    if(mediaT[i]>max)
        max=mediaT[i];
    if(mediaT[i]<max)
        max=mediaT[i];
 }
 media = suma/MAX;
 imprimir(mediaT,MAX);
 printf("El max es: %d \n",max);
 printf("El min es: %d \n",min);
 printf("La media es: %d \n",media);


}

void imprimir(int* puntA,int size){
  int i = 0;
  while(i<size)
  {
      printf("%d \n",*(puntA+i));
      ++i;
  }
}