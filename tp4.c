#include <stdio.h>
#include <stdlib.h>

#define ASIZE 5
void imprimir(int* puntA,int size);
void llenado(int* puntA,int size);
void ex1();
void ex2();
void ex3();
void ex4();
void ex5();
int main()
{
    ex5();
    return 0;
}
void ex5(){
 int tab[ASIZE];
 int* pT = tab;
 int min,max,aux;
 printf("Escriba su valor minimo");
 scanf("%d",&min);
 printf("Escriba su valor maximo");
 scanf("%d",&max);
 if(!(min>0 && min<ASIZE && min<=max && max<=ASIZE))
    {
      printf("Escriba numeros validos \n");
      return;
    }
    
 llenado(tab,ASIZE);
 aux = *(pT+min-1);
 for(int i=0; i<max-min; ++i){
  if(*(pT+i+min)<aux)
    aux = *(pT+i+min);
 }
 printf("Minimo:%d",aux);
}
void ex4(){
 int validar=1;
 int tab1[ASIZE],tab2[ASIZE];
 llenado(tab1,ASIZE);
 llenado(tab2,ASIZE);
 for(int i=0; i<ASIZE; ++i){
    if(!(*(tab1+i)==*(tab2+i))){
        validar = 0;
        break;
    }
 }
 if(validar)
    printf("True");
 else
    printf("False");

}
void ex3(){
  int array[ASIZE];
    int* pA = array;
    int aux=0;

    llenado(array,ASIZE);
    for(int i=0; i<ASIZE; ++i){
        for(int j=0; j<ASIZE-1; ++j){
         if(*(pA+j)<*(pA+j+1))
         {
             aux = *(pA+j);
             *(pA+j) = *(pA+j+1);
             *(pA+j+1) = aux;
         }
        }
    }
    imprimir(array,ASIZE);
}
void ex1(){
    int A[] = {12,23,34,45,56,67,78,89,90};
    int* P;
    P=A;
    printf("%d",*P+2);
    printf("%d",*(P+2));
    printf("%d",&A[4]-3);
    printf("%d",A+3);
    printf("%d",&A[7]-P);
    printf("%d",P+(*P-10));
    printf("%d",*(P+*(P+8)-A[7]));

}
void ex2(){
 int aux;
 int x;
 int pos=0,i = 0;
 int a[10];
 int* pa;
 pa = a;
 printf("Escriba su numero a verificar \n");
 scanf("%d",&x);
 while(i<10)
 {
     printf("Escriba el numero %d de su arreglo \n",i+1);
     scanf("%d",&aux);
     if(!(aux==x))
      {
        *(pa+pos) = aux; //a[pos] = aux;
        ++pos;
      }
      ++i;
}
 imprimir(a,pos);
}
void llenado(int* puntA,int size){
  for(int i=0; i<size; ++i)
    {
        printf("Introduzca el valor:%d \n",i+1);
        scanf("%d",&*(puntA+i));
    }
}
void imprimir(int* puntA,int size){
  int i = 0;
  while(i<size)
  {
      printf("%d \n",*(puntA+i));
      ++i;
  }
}