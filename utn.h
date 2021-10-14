#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <time.h>
#define FULL 0
#define EMPTY 1

int getInt();
float getFloat();
char getChar();

char getNumeroAleatorio(int desde , int hasta, int iniciar);
char getValidSexo (char requestMessage[], char* input);

int esNumerico(char *str) ;
int esTelefono(char *str);
int esAlfaNumerico(char *str);
int esSoloLetras(char *str);
int esNumericoFlotante(char str[]);

void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
void getValidString(char requestMessage[],char errorMessage[], char input[]);
void cleanStdin(void);
float getValidFloat(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
int getauxiliaryString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado);
int utn_getFloat(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, float* input);
int isValidFloatNumber(char* stringRecibido);


#endif // UTN_H_INCLUDED
