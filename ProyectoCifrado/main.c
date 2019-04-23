#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void capturaClave(char* clave,int* claveSize);
void cifradoAlgoritmo(char* textoCifrado, char* texto, char* clave,int* claveSize);
void guardarArchivo(char* textoCifrado);
void claveInversa(char* clave,int* claveSize);
void abrirArchivo(char* texto);

#define STEXT 500
#define SCLAVE 10
#define MAXSIZE 25

    int main(){
        char clave[SCLAVE]; // Almacena la clave
        int claveSize;
        char texto[STEXT]; // Almacena el texto
        char textoCifrado[STEXT];
        int opcVal,opc;  //Variables de control de flujo

        do{
            texto[0]=0;
            clave[0]=0;
            textoCifrado[0]=0;
             do{
                printf("Seleccione una opción: 1-Cifrar 2-Descifrar \n");
                scanf("%d",&opc);
                if(opc == 1 || opc == 2)  //Verifica que sea una opción valida
                    opcVal = 0;
                else{   
                    opcVal = 1;
                    printf("Seleccione 1 ó 2 \n");
                }
                    
            }while(opcVal); //Pregunta hasta que obtiene una respuesta

            switch(opc){
                case 1:
                capturaClave(clave,&claveSize);
                abrirArchivo(texto); 
                cifradoAlgoritmo(textoCifrado,texto,clave,&claveSize);
                guardarArchivo(textoCifrado);
                break;

                case 2:
                capturaClave(clave,&claveSize);
                claveInversa(clave,&claveSize);
                abrirArchivo(textoCifrado);
                cifradoAlgoritmo(texto,textoCifrado,clave,&claveSize); //Usamos el mismo algoritmo, pero esta vez 'clave'contiene la clave inversa
                break;
            }
            opc=0;
            printf("\n Si desea repetir, presione 1, si desea salir presione cualquir tecla. \n");
            scanf("%d",&opc);
            if(opc==1)
                opcVal=1;
        }while(opcVal);
           

        return 0;
    }

    void capturaClave(char* clave, int* claveSize){
        printf("Introduzca su clave para el cifrado \n");
        scanf("%s",clave);
        *claveSize = strlen(clave);
    }

   //Usa codigo ascii tradicional imprimible 32-254
    void cifradoAlgoritmo(char* textoCifrado, char* texto, char* clave,int* claveSize){
        int contador=0;
        int clavePos=0;
        int val;

        while((int)texto[contador]!=0){
            if((int)texto[contador]>31)
            {   
                val =(int) texto[contador] + (int)clave[clavePos];
                printf("%d,",texto[contador]);
                printf("%d,",clave[clavePos]);
                printf("%d,",val); 
                if(val%126 < 32)
                    textoCifrado[contador] = val%126 + 31;
                else
                    textoCifrado[contador] = val%126;
            }  
            else{
                textoCifrado[contador] = texto[contador];
            } 
                printf("%d \n",textoCifrado[contador]);
                ++contador;
                if(clavePos+1 == *claveSize)
                    clavePos = 0;
                else
                    ++clavePos; 
             }
        textoCifrado[contador] = '\0';
        printf("%s",textoCifrado); 
    }

    void guardarArchivo(char* textoCifrado){
        FILE* file = NULL;
        char nomArchivo[MAXSIZE];
        int code;
        printf("\n Introduzca el nombre del archivo para guardar el cifrado \n");
        scanf("%s",nomArchivo);
        file = fopen(nomArchivo,"r+");
        code = fputs(textoCifrado,file);
        if(code<0)
        printf("Error al abrir el archivo");
        else
        {
            printf("Cifrado guardado con éxito");
        }
        
        fclose(file);
    }


    void claveInversa(char* clave,int* claveSize){
        for(int i=0; i<*claveSize; ++i){
                 clave[i] = 127+31-clave[i];
        }
    }

    void abrirArchivo(char* texto){
        FILE* file  = NULL;
        char nomArchivo[MAXSIZE];
        char cadenaAux[MAXSIZE];
        printf("Introduzca el nombre del archivo \n");
        scanf("%s",nomArchivo);
        file = fopen(nomArchivo,"r+");
        if(file == NULL)
            {
                printf("El archivo está vacío o no existe \n");
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
        printf("%s \n",texto);
        fclose(file);
    }