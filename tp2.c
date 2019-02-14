#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ex1();
int ex2();
int ex3();
int ex4();
int main()
    {
       int choix;
       do
       {
           printf("Seleccione la opcion que desea \n Ex1 - 1 \n Ex2 - 2 \n Ex3 - 3 \n Ex4 - 4 \n Salir - 5 \n");
           scanf("%d",&choix);
           switch(choix)
           {
            case 1:
              ex1();
              break;
            case 2:
              ex2();
              break;
            case 3:
              ex3();
              break;
            case 4:
              ex4();
              break;
            case 5:
              printf("Fin del programa \n");
              break;
            default:
               printf("Selecciona una opcion valida \n");
           }
       } while(choix != 5);

       return 0;
    }

int ex1()
    {
      int num, resul = 1;
      printf("Escriba un numero entero positivo \n");
      scanf("%d",&num);
      if(num > 0)
      {
         for(int i = 1; i <= num; ++i)
           resul =  resul * i;

         printf("Resultado: %d \n", resul);
      }
      else
        printf("Escriba una opcion valida \n");

      return 0;
    }
int ex2()
    {
         int num, resul = 1;
      printf("Escriba un numero entero positivo \n");
      scanf("%d",&num);
      if(num > 0)
      {
         for(int i = num; i > 0; --i)
            printf("%d",i);
      }
      else
        printf("Escriba una opcion valida \n");

        printf("\n");
      return 0;

    }
int ex3()
    {
     int a,b;
     printf("Escriba dos numeros enteros y diferentes positivos  \n");
     scanf("%d",&a);
     scanf("%d",&b);
     if(a > 0 && b > 0 && a != b)
     {
         if(a < b)
         {
            a = a + b;
            b = a - b;
            a = a - b;
         }
        while(a > b)
        {
            a = a - b;
        }
     }
      else
        printf("Escriba una opcion valida \n");

        return 0;
    }

int ex4()
    {
      char nom1[10], nom2[9];
      int punt1 = 0,punt2 = 0;
      int val1,val2;
      int i, choice;
     do
     {
       i = 1;

      printf("Jugador 1, escriba su nombre \n");
      scanf("%s",&nom1);
      printf("Jugador 2, escriba su nombre \n");
      scanf("%s",&nom2);

      while(punt1 < 30 || punt2 < 30)
      {
      do
      {
          printf("Jugador 1, introduzca su puntuación del turno %d \n",i);
       scanf("%d",&val1);
       switch(val1)
       {
        case 1:
            punt1 = 0;
            break;
        case 4:
            punt1 =  punt1 *2;
            break;
       }
      } while(val1 == 6);
        punt1 =  punt1 + val1;

        do{
         printf("Jugador 2, introduzca su puntuación del turno %d \n",i);
               scanf("%d",&val2);
               switch(val2)
               {
                case 1:
                    punt2 = 0;
                    break;
                case 4:
                    punt2 =  punt2 *2;
                    break;
               }

        }while(val2 == 6);
             punt2 =  punt2 + val2;

       printf("La puntuación de %s uno es de: %d, La puntuación de %s es de: %d \n ",nom1,punt1,nom2,punt2);
       i = i + 1;
       val1 = 0;
       val2 = 0;
      }
      if(punt1 >= 30)
        printf("Felicidades %s \n",nom1);
      if(punt2 >= 30)
        printf("Felicidades %s \n",nom2);

        printf("Desea volver a jugar? \n 1 - Si \n 2 - No \n");
        scanf("%d",&choice);

     } while (choice == 1);



      return 0;
    }
