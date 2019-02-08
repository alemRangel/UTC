#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ex1();
int ex2();
int ex3();
int ex4();
int ex5();
int ex6();
int ex7();
int ex8();
int ex9();

int main()
{
    int funcion = ex9(); //Poner el ejercicio a evaluar
    return 0;
}
int ex1()
{
    float a,b,c;
    float suma,multi,moyenne;

    printf("Entrez 3 nombres \n");
    scanf("%f",&a);
    scanf("%f",&b);
    scanf("%f",&c);

    suma = a + b + c;
    multi = a * b * c;
    moyenne = suma / 3;

    printf("la suma es: %f ,  la multiplicacion es: %f y la mediana es: %f",suma,multi,moyenne);
    return 0;
}

int ex2()
{
    const float TVA = 1.206;
    float ht, ttc;
    
    printf("Écrire le prix: \n");
    scanf("%f",&ht);
    ttc = TVA * ht;
    printf("Le TTC est:%f",ttc);
    printf("Le TVA est:%f",ttc-ht);
 

    return 0;
}

int ex3()
{
 const float PI = 3.14;
 float radio, area,perimetro;

 printf("Ecrire le rayon \n");
 scanf("%f",&radio);

 area = PI * pow(radio,2);
 perimetro = 2 * PI * radio;

 printf("El perimetro es: %f  y el area es: %f",perimetro,area);

 return 0;
}

int ex4()
{
    float dCour,dDalles,nPaquetes,nDalles;

    printf("Ecrire les dimensions du Cour \n");
    scanf("%f",&dCour);
    printf("Ecrire les dimensiones de un dalle \n" );
    scanf("%f",&dDalles);

    nDalles = dCour / dDalles;
    if((int)nDalles - nDalles != 0)
    {
        nDalles = nDalles + 1;
    }
    printf("Numero de Dalles:%d",(int)nDalles);

    nPaquetes = ((nDalles)/15);
    if((int)nPaquetes - nPaquetes != 0)
    {
        nPaquetes = nPaquetes + 1;
    }
    printf("\n Numero de Paquetes: %d",(int)nPaquetes);

    return 0;
}

int ex5()
{
   float a,b,c;
   float respuesta;
   int choice;

   printf("Entrez trois nombres: \n");
   scanf("%f",&a);
   scanf("%f",&b);
   scanf("%f",&c);

   printf("1- Rechercher P \n 2- Rechercher G \n");
   scanf("%d",&choice);

   switch(choice)
   {
    case 1:
    {
      respuesta = a;
      if(respuesta > b)
            respuesta = b;

        if(respuesta > c)
         respuesta = c;


      printf("P vaut %f",respuesta);
      break;
    }

   case 2:
    {
     respuesta = a;
      if(respuesta < b)
        respuesta = b;

      if(respuesta < c)
         respuesta = c;


      printf("G vaut %f",respuesta);
      break;

    }
   default:
    {
        printf("Choix incorrect");
    }
   }
   return 0;
}

int ex6() 
{
  int numero;
  printf("Ecrire un numero \n");
  scanf("%d",&numero);
  if(numero%2 == 0)
        printf("Est pair");
  else
       printf("Est non");

}
int ex7()
{
 int a,b,c,aux;
  printf("Entrez trois nombres: \n");
   scanf("%d",&a);
   scanf("%d",&b);
   scanf("%d",&c);
   if(a>b)
   {
       aux = a;
       a = b;
       b = aux;
   }
    if(b>c)
   {
       aux = b;
       b = c;
       c = aux;
   }
   if(a>b)
    {
       aux = a;
       a = b;
       b = aux;
   }

  printf("L´ordre croissant c´est %d,%d,%d:",a,b,c);
  return 0;
}

int ex8()
{
 const float sobreEsfuerzo = 1.25, megaEsfuerzo = 1.5;
 float tarifa,salario;
 int horasT;

 printf("Escriba la tarifa por hora \n");
 scanf("%f",&tarifa);
 printf("Escriba las horas trabajadas \n");
 scanf("%d",&horasT);
 if(horasT<40)
  salario = horasT * tarifa;
  else if(horasT < 48)
  salario = horasT * tarifa * sobreEsfuerzo;
  else
  salario = horasT * tarifa * megaEsfuerzo;

  printf("El sueldo es de: %f",salario);
  
 return 0;
}

int ex9()
{
 int opc;
 const float pi = 3.141594;
 float long1,long2,area,perimetro;

 printf("Seleccione la opción que desee calcular: \n");
 printf("1 -  circulo \n");
 printf("2 -  cuadrado \n");
 printf("3 -  rectangulo\n");
 scanf("%d",&opc);

 switch(opc)
 {
     case 1:
     {
      printf("Introduzca el radio \n");
      scanf("%f",&long1);
      area = pi * pow(long1,2);
      perimetro = 2 * long1 * pi;
      break;
     }
     case 2:
     {
      printf("Introduzca la longitud del lado \n");
      scanf("%f",&long1);
      area = pow(long1,2);
      perimetro = 4 * long1;
      break;
     }
     case 3:
     {
      printf("Introduzca la longitud de un lado \n");
      scanf("%f",&long1);
      printf("Introduzca la longitud del otro lado \n");
      scanf("%f",&long2);
      area = long1 * long2;
      perimetro = 2*long1 + 2*long2;
      break;
     }
     default:
     {
         printf("Seleccione una opcion valida");
         return 0;
     }
 }
 printf("El area es de: %f y el perimetro es de: %f",area,perimetro);
 return 0;
}