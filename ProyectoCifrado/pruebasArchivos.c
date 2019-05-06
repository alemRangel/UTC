#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

#define MAXSIZE 25
void leerArchivo();
void prueba();
void mod();
void guardarArchivo(char* textoCifrado);
void caracterNumero(char* texto, char* textoGuardar, int* size);
int main(){
    char texto[MAXSIZE];
    gets(texto);
    printf("size:%d \n",strlen(texto));
    guardarArchivo(texto);
    return 0;
}
void leerArchivo(){
    FILE* file = NULL;
     char aux;
   // char *locale = setlocale(LC_ALL, "en_US.utf8");
    file = fopen("text.txt","r+");
    //wint_t c;
    if(file != NULL){
        while((aux=fgetc(file))!= EOF){
            if(aux<0)
            printf("%d",aux);
            else 
            printf("%c",aux);
          //  printf("-%d")
           // printf("_%d,",aux);
        }
    }
    else
    {
        printf("Error");
        return;
    }

    fclose(file);
}

void mod(){
    int mod,a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    mod = b%a;
    printf("%d",mod);
}
void caracterNumero(char* texto, char* textoGuardar, int* size){

}
void guardarArchivo(char* textoCifrado){
        FILE* file = NULL;
        char nomArchivo[MAXSIZE];
        char textoGuardar[MAXSIZE*4];
        int code;
        int size=0;
        printf("Introduzca el nombre del archivo para guardar el cifrado \n");
        scanf(" %s",nomArchivo);
        file = fopen(nomArchivo,"w+");
        caracterNumero(textoCifrado,textoGuardar,&size);
        for(int i=0; i<size; ++i)
        fputc(textoCifrado[i],file);

        code=textoCifrado[0];
        if(code<0)
        printf("Error al abrir el archivo");
        else
        {
            printf("Cifrado guardado con éxito");
        }
        
        fclose(file);
    }
    /*
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
         while(fgets(cadenaAux,MAXSIZE,file)!=EOF)
          {
                 if(texto[0]==0)
                 strcpy(texto,cadenaAux);
                 else
                 {
                     strcat(texto,cadenaAux);
                 }
                 putchar()
          }
          int size = strlen(texto);
          printf("%d \n",size);
          for(int i=0; i<size; ++i)
          printf("%d,",texto[i]);

          printf("\n");
          fclose(file);
}*/