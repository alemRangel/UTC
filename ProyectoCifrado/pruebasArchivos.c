#include <stdio.h>
#include <string.h>
#define MAXSIZE 25
void prueba();
void mod();
void guardarArchivo(char* textoCifrado);
int main(){
    char texto[100];
    scanf("%s",texto);
    guardarArchivo(texto);
    
    return 0;
}
void mod(){
    int mod,a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    mod = b%a;
    printf("%d",mod);
}
void guardarArchivo(char* textoCifrado){
        FILE* file = NULL;
        char nomArchivo[MAXSIZE];
        int code;
        printf("\n Introduzca el nombre del archivo para guardar el cifrado \n");
        scanf("%s",nomArchivo);
        file = fopen(nomArchivo,"w+");
        code = fputs(textoCifrado,file);
        if(code<0)
        printf("Error al abrir el archivo");
        else
        {
            printf("Cifrado guardado con éxito");
        }
        
        fclose(file);
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