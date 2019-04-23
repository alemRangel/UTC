#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void ex1();
void ex2();
void ex3_1();
void ex3_2();
void imprimir(int* puntA,int size);


int main(){
ex3_1();
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
        min=mediaT[i];
 }
 media = suma/MAX;
 imprimir(mediaT,MAX);
 printf("El max es: %d \n",max);
 printf("El min es: %d \n",min);
 printf("La media es: %d \n",media);
}

void ex2(){
    
}

void ex3_1(){
 char str[50];
    int contA=0;
    int i = 0;
    printf("Inserte una cadena de letras mayusculas, sin espacio, y termine con un punto \n");
    scanf("%s",str);
    do{
     if(toAscii(str[i]) == 65)
        contA = contA+1;
     ++i;
    }while(str[i-1]!=56);
    printf("El numero de As es de: %d \n",contA);
}

void ex3_2(){
    
    
}

void imprimir(int* puntA,int size){
  int i = 0;
  while(i<size)
  {
      printf("%d \n",*(puntA+i));
      ++i;
  }
}