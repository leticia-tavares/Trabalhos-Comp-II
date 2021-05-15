/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: Programa que mostra o tamanho em bytes dos Tipos Basicos
 *
 * $Author: leticia.santos $
 * $Date: 2019/03/28 15:24:13 $
 * $Log: aula0101.c,v $
 * Revision 1.2  2019/03/28 15:24:13  leticia.santos
 * *** empty log message ***
 *
 * Revision 1.1  2019/03/28 12:28:16  leticia.santos
 * Initial revision
 *
 *
 */


#include<stdio.h>
#define OK                 0


int main()
{
	printf("\n\t\"-Tipos Basicos-\"");
	printf("\nint:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(int),(sizeof(int) > 1)?"bytes":"byte");
	printf("\nfloat:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(float), (sizeof(float) > 1)?"bytes":"byte");
	printf("\ndouble:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(double), (sizeof(double) > 1)?"bytes":"byte");
	printf("\nchar:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(char), (sizeof(char) > 1)?"bytes":"byte");
	printf("\nvoid:\n\t\t\t\t\t\t\t%lu %s\n",(long unsigned) sizeof(void), (sizeof(void) > 1)?"bytes":"byte");

	return OK;
}
 
