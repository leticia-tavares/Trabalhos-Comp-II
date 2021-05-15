/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: Programa que exibe o tamanho em bytes dos Tipos Basicos, Modiicadores de Sinal e de Largura
 *
 * $Author: leticia.santos $
 * $Date: 2019/04/01 22:40:45 $
 * $Log: aula0103.c,v $
 * Revision 1.2  2019/04/01 22:40:45  leticia.santos
 * *** empty log message ***
 *
 * Revision 1.1  2019/03/29 22:53:04  leticia.santos
 * Initial revision
 *
 *
 */


#include<stdio.h>
#define OK                 0


int main()
{
	
	int contador;
		
	printf("\n\t\"-Tipos Basicos-\"");
	printf("\nint:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(int),(sizeof(int) > 1)?"bytes":"byte");
	printf("\nfloat:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(float), (sizeof(float) > 1)?"bytes":"byte");
	printf("\ndouble:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(double), (sizeof(double) > 1)?"bytes":"byte");
	printf("\nchar:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(char), (sizeof(char) > 1)?"bytes":"byte");
	printf("\nvoid:\n\t\t\t\t\t\t\t%lu %s\n",(long unsigned) sizeof(void), (sizeof(void) > 1)?"bytes":"byte");

	for (contador = 0; contador < 80; contador++)
		printf("-");

	printf("\n\t\"-Modificadores de Sinal-\"");
	printf("\nsigned:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(signed), (sizeof(signed) > 1)?"bytes":"byte");
	printf("\nunsigned:\n\t\t\t\t\t\t\t%lu %s\n", (long unsigned) sizeof(unsigned), (sizeof(unsigned) > 1)?"bytes":"byte");

		
	for (contador = 0; contador < 80; contador++)
		printf("-");
	
	printf("\n\t\"-Modificadores de Largura-\"");
	printf("\nshort:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(short), (sizeof(short) > 1)?"bytes":"byte");
	printf("\nlong:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(long), (sizeof(long) > 1)?"bytes":"byte");
	printf("\nlong long:\n\t\t\t\t\t\t\t%lu %s\n", (long unsigned) sizeof(long long), (sizeof(long long) > 1)?"bytes":"byte");

	return OK;
}
 
