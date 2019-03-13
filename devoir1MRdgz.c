#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void ex1_1();
void ex1_2();
void ex2();
void ex3();
void ex4_1();
void ex4_2();
void ex5();

int main(){
    ex5();
    return 0;
}
void ex1_1(){
    int array[10];
    for(int i=0; i<10; ++i)  //En este for, guardas tu arreglo
    {
      printf("Escriba el numero %d \n",(i+1));
      scanf("%d",&array[i]);
    }
    for(int i=0; i<10; ++i) //En este for, se imprimen los números negativos
        {
        if(array[i]<0)  //Si algún elemento del arreglo es menor a 0, entonces es negativo
            printf("%d \n",array[i]); //Si es negativo, lo imprimes
        }
    
}
void ex1_2(){
  int array[10];
  int infimo; 
    for(int i=0; i<10; ++i) //En este for, guardas tu arreglo
    {
      printf("Escriba el numero %d \n",(i+1));
      scanf("%d",&array[i]);
    }
    infimo = array[0]; //Guardas la primera posición del arreglo en la variable ínfimo
    for(int i=0; i<10-1; ++i)
    {
        if(infimo>array[i+1]); // Si hay algún elemento del arreglo que sea menor que el actual valor de ínfimo
        infimo = array[i+1];  // se vuelve el ínfimo
    }
    printf("%d",infimo);
        
}

void ex2(){ // Este funciona, siempre y cuando la cadena no tenga espacios(para ponerle espacios,
  char str[50]; // hay que usar otra función que no es scanf()). Declaras tu cadena
  char punto;
  int contador=0,nA=0;
    printf("Escriba su texto \n");
    scanf("%s",str); //Aquí se guarda la string
    printf("%s",str);
  do{
   punto = str[contador];
   ++contador;
   if(punto == 'a' || punto == 'A')
     ++nA;
  }while(!(punto=='.'));

  printf("El numero de a o de A antes del primer punto  es de: %d, el numero de caracteres es:%d",nA,contador);
}

void ex3(){
  int contador = 0;
  int producto = 1,aux;
  do
  {
   printf("Escriba su numero a multiplicar \n");
   scanf("%d",&aux);
   if(aux!=0)
   producto = producto * aux;
  } while(aux != 0); // verifica que se acabe cuando escribas un 0
  printf("Producto:%d",producto);
}

void ex4_1(){
 int lado;
 printf("Inserte el size de su cuadrado \n");
 scanf("%d",&lado);
 for(int i=0; i<lado; ++i){ //altura
     for(int j=0; j<lado; ++j){ //longitud
         printf("*");
     }
     printf("\n");
 }
}

void ex4_2(){
 int lado;
 printf("Inserte el size de su piramide \n");
 scanf("%d",&lado);
 for(int i=0; i<lado; ++i){ //Altura de la piramide
     for(int k=0; k<lado-i; ++k) //Espacios necesarios
        printf(" ");
     for(int j=0; j<1+2*i; ++j)  //Serie aritmetica 1+2*n, corresponde a los asteriscos por fila
         printf("*"); 

     printf("\n");
 }
}

void ex5(){ 
 int random = rand()%101;
 int opc,contador;
 do{
  ++contador;
  printf("Introduzca su numero entre 0 y 100,\n");
  printf("le diremos si su elección fue mayor o menor que\n");
  printf("el numero de la computadora");
  scanf("%d",&opc);
  if(opc < random)
    printf("La opcion que selecciono es menor \n");
  else if(opc > random)
    printf("La opcion que selecciono es menor \n");
   
 }while(opc != random);
 printf("Bravo, vous avez trouvé en %d coups \n",contador);
 printf("Le nombre est: %d",random);
}

