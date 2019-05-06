#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#define TXT 100
#define KEY 20

void ingresaTexto(char *texto,int tipo);
void ingresaLlave(char *llave, int tipo);
void ingresaLlaveCesar(int *kei,int tipo);
void asciiPos(char *texto, int *text, int largo);
void printAscii(int *texto, int largo, int tipo);
void cifrado(int*texto,int tamtxt,int *key,int tamkey);
void claveInversa(int *key,int *keyinv, int tamkey);
void abrirArchivo(char* texto);
void guardarArchivo(int* textoCifrado,int tam);
int main()
{
	char texto[TXT]; // Guarda el texto del usuario (puede ser el texto cifrado o antes de cifrar)
	int  text[TXT]; //Lleva el valor numérico de cada caracter de la variable char text
	char key[KEY]; //Guarda la clave del usuario
	int kei[KEY]; // Lleva el valor numérico de cada caracter de la variable char key
	int iek[KEY];	 // Guarda la clave inversa de la clave
	int opcion;  // Opción escogida para el programa 
	char cont=' '; //Si el usuario decide continuar, es igual a y o Y.
	do{ //Repite el prrograma hasta que el usuario decida salir
		do // Escoger una opción de cifrado o de descrifrado
	{
	system("cls");
	printf("Elija una opcion:\n");
	printf("1:Cifrado Cesar\n");
	printf("2:Descifrado Cesar\n");		
	printf("3:Cifrado Vigenere\n");
	printf("4:Descifrado Vigenere\n");
	printf("5:Cifrar un archivo de texto\n");
	printf("6:Descifrar un archivo de texto\n");
	printf("Tu opcion: ");
	scanf("%d",&opcion);
	if(opcion>6 || opcion<1){
		printf("\n Escriba un numero entre 1 y 6");
		sleep(1.5);
	}
	}while(opcion<1 || opcion>6); 

	ingresaTexto(texto,0);
	system("cls");
	switch(opcion)
	{
	case 1: printf("Cifrado Cesar\n");
			ingresaTexto(texto,1);
			asciiPos(texto, text, strlen(texto));
			ingresaLlaveCesar(kei,1); 
			cifrado(text,strlen(texto),kei,1);
			printAscii(text,strlen(texto),1);
			break;
	case 2: printf("Descifrado Cesar\n");
			ingresaTexto(texto,2);
			asciiPos(texto, text, strlen(texto));
			ingresaLlaveCesar(kei,2);
			claveInversa(kei,kei,1);
			cifrado(text,strlen(texto),kei,1);
			printAscii(text,strlen(texto),2);
			break;
	case 3:	printf("Cifrado Vigenere\n");
			ingresaTexto(texto,1);
		    ingresaLlave(key,1);
		    asciiPos(texto, text, strlen(texto));
		    asciiPos(key, kei, strlen(key));
		    cifrado(text,strlen(texto),kei,strlen(key));
		    printAscii(text,strlen(texto),1);		    
		    break;
	case 4:	printf("Descifrado Vigenere\n");
			ingresaTexto(texto,2);
		    ingresaLlave(key,2);
		    asciiPos(texto, text, strlen(texto));
		    asciiPos(key, kei, strlen(key));
			claveInversa(kei,kei,strlen(key));
		    cifrado(text,strlen(texto),kei,strlen(key));
		    printAscii(text,strlen(texto),2);	    
		    break;
	case 5:	printf("Cifrado texto Vigenere a un archivo ya existente \n");
			abrirArchivo(texto);
	    	ingresaLlave(key,1);
		    asciiPos(texto, text, strlen(texto));
		    asciiPos(key, kei, strlen(key));
		    cifrado(text,strlen(texto),kei,strlen(key));
			printAscii(text,strlen(texto),1);	
		    guardarArchivo(text,strlen(texto));   
		    break;
	case 6:	printf("Decifrado vigenere a un archivo ya existente \n");
			abrirArchivo(texto);
	    	ingresaLlave(key,2);
			asciiPos(texto, text, strlen(texto));
		    asciiPos(key, kei, strlen(key));
			claveInversa(kei,kei,strlen(key));
		    cifrado(text,strlen(texto),kei,strlen(key));
			printAscii(text,strlen(texto),2);
		    guardarArchivo(text,strlen(texto));
			break;
	}
		printf("Si desea continuar escriba 'Y', si no, escriba cualquier otro caracter \n");
		scanf(" %c",&cont);
	}while(cont=='y' || cont=='Y');
	printf("Gracias por usar el software, 20/20");
	sleep(2);
	return 0;	
}
/**
 * Nombre: ingresaTexto
 * Entrada: char* texto
 * Salida: void
 * Descripción: Se captura el texto escrito en consola en texto.
*/
void ingresaTexto(char*texto, int tipo)
{
	if(tipo==0)
	printf(" ");
	else if(tipo==1)
	printf("Ingrese el texto a codificar: ");
	else
	printf("Ingrese el texto a decodificar: ");
	
	gets(texto);
}
/**
 * Nombre: ingresaLlave
 * Entrada: char* llave
 * Salida: void
 * Descripción: Se captura la clave escrita en consola en llave.
 */
void ingresaLlave(char*llave, int tipo)
{
	if(tipo==1)
	printf("Ingrese la clave de cifrado: ");
	else
	printf("Ingrese la misma clave que uso para cifrar: ");
	
	scanf("%s",llave);
	printf("\n");
}

/**
 * Nombre: asciiPos
 * Entrada: char* texto, int* text, int* largo
 * Salida: void
 * Descripción: Se envía el texto capturado en la variable texto para llenar 
 * la variable text con su correspondiente valor numérico ASCII. Largo indica 
 * la longitud del texto capturado.
 */
void asciiPos(char *texto, int *text, int largo)
{
	int j;
	for(j=0;j<largo;j++)
	{
		text[j]=(int)texto[j];
		if(text[j]<0)
		text[j]+=256;
		if(text[j]>251)
		text[j]-=223;
	}
	
}
/**
 * Nombre: printAscii
 * Entrada: int *texto int* largo
 * Salida: void
 * Descripción: Imprime un arreglo de enteros en su correspondencia según el 
 * código ASCII. Largo indica la longitud del arreglo texto.
 */
void printAscii(int *texto, int largo,int tipo)
{
	int i;
	if(tipo==1)
	printf("Texto cifrado:");
	else
	printf("Texto descifrado:");
	
	for(i=0;i<largo;i++)
	printf("%c",texto[i]);
	printf("\n");	
}
/**
 * Nombre: cifrado
 * Entrada:int*texto,int tamtxt,int* key,int tamkey
 * Salida: void 
 * Descripción: Implementación de algoritmo de cifrado. Si se escoge la
 * opción de cifrado Cesar, la variable key es un número único. Si se escoge 
 * la opción de cifrado Vigenere, es una clave.
 */
void cifrado(int*texto,int tamtxt,int* key,int tamkey)
{
	int ct,ck;
	ck=0;
	for(ct=0;ct<tamtxt;ct++)
	{
		texto[ct]=texto[ct]+key[ck]-64;
		if(texto[ct]>222&&texto[ct]<414)
        texto[ct]-=191;
        else if(texto[ct]>413)
        texto[ct]-=382;
		else
        texto[ct]+=32;
		ck++;
		if(ck==tamkey)
		ck=0;
	}
}
/**
 * Nombre: claveInversa
 * Entrada: int *key,int *keyinv, int tamkey
 * Salida: void
 * Descripción: Calcula una clave inversa guardada en keyinv
 * a partir de una clave guardada en key.
 */
void claveInversa(int *key,int *keyinv, int tamkey)
{
	int i;
	printf("Clave inversa: ");
	for(i=0;i<tamkey;i++)
	{
		keyinv[i]=287-key[i];
		printf("%c",keyinv[i]);
	}
	printf("\n");
}

/**
 * Nombre: ingresarLlaveCesar
 * Entrada: int * kei  char* key
 * Salida: void
 * Descripción: Le pide al usuario que escriba un numero para su clave cesar.
 * Si se llama con un 1, es un cifrado, si se llama con cualquier otra cosa
 * es un descifrado.
 */
void ingresaLlaveCesar(int* kei, int tipo){
	int num;
	if(tipo==1)
	printf("Escriba una clave para su cifrado Cesar (un numero entero): \n");
	else
	printf("Escriba la misma clave que uso para su cifrado cesar: \n");
	
	scanf("%d",&num);
	kei[0] = num;
}

/**
 * Nombre: abrirArchivo
 * Entrada: char* texto
 * Salida: void
 * Descripción: Le pide al usuario el nombre de un archivo de texto, y guarda su contenido en 
 * la variable texto.
 */
void abrirArchivo(char* texto){
        int i = 0;
		FILE* file  = NULL;
        char nomArchivo[KEY];
        char cadenaAux[KEY];
		do{
			printf("Introduzca el nombre del archivo \n");
        	scanf("%s",nomArchivo);
        	file = fopen(nomArchivo,"r+");
        	if(file == NULL)
                printf("El archivo está vacío o no existe, verifque que escribió bien su dirección \n");
			else 
			i = 1;
		}while(i==0);
       
         while(fgets(cadenaAux,KEY,file)!=NULL)
            {
                 if(texto[0]==0)
                 {
                 strcpy(texto,cadenaAux);
				 }
                 else
                 {
                     strcat(texto,cadenaAux);
                 }
             }
        printf("Archivo abierto con exito: \n %s \n",texto);
        fclose(file);
    }
/**
 * Nombre:guardarArchivo
 * Entrada:int* textoCifrado,int tam
 * Salida:void
 * Descripción:Guarda el texto contenido en la variable textoCifrado
 *  en un archivo ya existente.
 */
 void guardarArchivo(int* text,int tam){
        FILE* file = NULL;
        char nomArchivo[KEY];
        int code,i;
        printf("Introduzca el nombre del archivo para guardar el cifrado: \n");
        scanf("%s",nomArchivo);
        file = fopen(nomArchivo,"w+");
        for(i=0;i<tam;i++)
		{
		code = fputc((int)text[i],file);
        if(code<0)
        {
		printf("Error al abrir el archivo \n");
    	break;
		}
    	}
    	if(code>-1)
    	printf("Cifrado guardado con exito \n");
        fclose(file);
    }