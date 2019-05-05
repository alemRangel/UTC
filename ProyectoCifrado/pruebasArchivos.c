#include <stdio.h>
#include <string.h>
#define MAXSIZE 25
void prueba();
void mod();
int main(){
    char texto[100];
    texto[0] = 0;
    prueba(texto);
    printf("%s",texto); 
    
    return 0;
}
void mod(){
    int mod,a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    mod = b%a;
    printf("%d",mod);
}
void prueba(char* texto){
         FILE* file  = NULL;
        char nomArchivo[MAXSIZE];
        char cadenaAux[MAXSIZE];
        printf("Introduzca el nombre del archivo \n");
        scanf("%s",nomArchivo);
          file = fopen("text.txt","rt");
        if(file == NULL)
            {
                printf("El archivo está vacío o no existe");
                return;
            }
         while(fgets(cadenaAux,MAXSIZE,file)!=NULL)
          {
                 if(texto[0]==0)
                 strcpy(texto,cadenaAux);
                 else
                 {
                     strcat(texto,cadenaAux);
                 }
          }
          int size = strlen(texto);
          printf("%d \n",size);
          for(int i=0; i<size; ++i)
          printf("%d,",texto[i]);

          printf("\n");
          fclose(file);
}