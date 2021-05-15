/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: Programa que exibe o tamanho em bytes das combinacoes entre tipos basicos, modificadores de sinal e modificadores de largura
 *
 * $Author: leticia.santos $
 * $Date: 2019/04/01 22:45:13 $
 * $Log: aula0107.c,v $
 * Revision 1.3  2019/04/01 22:45:13  leticia.santos
 * *** empty log message ***
 *
 * Revision 1.2  2019/04/01 22:28:04  leticia.santos
 * *** empty log message ***
 *
 * Revision 1.1  2019/03/30 02:43:58  leticia.santos
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

	for (contador = 0; contador < 80; contador++)
		printf("-");
	
	printf("\n\t\"-Modificadores de Sinal combinados com  Modificadores de Largura-\"");
	printf("\nsigned short:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(signed short), (sizeof(signed short) > 1)?"bytes":"byte");
	printf("\nsigned long:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(signed long), (sizeof(signed long) > 1)?"bytes":"byte");
	printf("\nsigned long long:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(signed long long), (sizeof(signed long long) > 1)?"bytes":"byte");
	printf("\nunsigned short:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(unsigned short), (sizeof(unsigned short) > 1)?"bytes":"byte");
	printf("\nunsigned long:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(unsigned long), (sizeof(unsigned long) > 1)?"bytes":"byte");
	printf("\nunsigned long long:\n\t\t\t\t\t\t\t%lu %s\n", (long unsigned) sizeof(unsigned long long), (sizeof(unsigned long long) > 1)?"bytes":"byte");

	for (contador = 0; contador < 80; contador++)
		printf("-");
	
	printf("\n\t\"-Tipos Basicos combinados com Modificadores de Sinal-\"");
	printf("\nsigned int:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(signed int), (sizeof(signed int) > 1)?"bytes":"byte");
	printf("\nunsigned int:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(unsigned int), (sizeof(unsigned int) > 1)?"bytes":"byte");
	printf("\nsigned char:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(signed char), (sizeof(signed char) > 1)?"bytes":"byte");
	printf("\nunsigned char:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(unsigned char), (sizeof(unsigned char) > 1)?"bytes":"byte");
	
	/*Combinacoes Invalidas*/
	printf("\n\t\"-Combinacoes Invalidas-\"");
	printf("\nsigned float");
	printf("\nunsigned float");
	printf("\nsigned double");
	printf("\nunsigned float");
	printf("\nsigned void");
	printf("\nunsigned void\n\n");

	for (contador = 0; contador < 80; contador++)
		printf("-");

	printf("\n\t\"-Tipos Basicos combinados com Modificadores de Largura-\"");
	printf("\nshort int:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(short int),(sizeof(short int) > 1)?"bytes":"byte");
	printf("\nlong int:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(long int), (sizeof(long int) > 1)?"bytes":"byte");
	printf("\nlong long int:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(long long int), (sizeof(long long int) > 1)?"bytes":"byte");
	printf("\nlong double:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(long double), (sizeof(long double) > 1)?"bytes":"byte");

	/*Combinacoes Invalidas*/
	printf("\n\t\"-Combinacoes Invalidas-\"");
	printf("\nshort double");
	printf("\nlong long double");
	printf("\nshort float");
	printf("\nlong float");
	printf("\nlong long float");
	printf("\nshort char");
	printf("\nlong char");
	printf("\nlong long char");
	printf("\nshort void");
	printf("\nlong void");
	printf("\nlong long void\n\n");

	for (contador = 0; contador < 80; contador++)
		printf("-");
	
	printf("\n\t\"-Tipos Basicos combinados com Modificadores de Sinal e com Modificadores de Largura-\"");
	printf("\nsigned short int:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(signed short int),(sizeof(signed short int) > 1)?"bytes":"byte");
	printf("\nsigned long int:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(signed long int), (sizeof(signed long int) > 1)?"bytes":"byte");
	printf("\nsigned long long int:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(signed long long int), (sizeof(signed long long int) > 1)?"bytes":"byte");
	printf("\nunsigned short int:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(unsigned short int), (sizeof(unsigned short int) > 1)?"bytes":"byte");
	printf("\nunsigned long int:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(unsigned short int), (sizeof(unsigned long int) > 1)?"bytes":"byte");
	printf("\nunsigned long long int:\n\t\t\t\t\t\t\t%lu %s", (long unsigned) sizeof(unsigned long long int), (sizeof(unsigned long long int) > 1)?"bytes":"byte");

	/*Combinacoes Invalidas com signed*/
	printf("\n\t\"-Combinacoes Invalidas-\"");
	printf("\nsigned short double");
	printf("\nsigned long double");
	printf("\nsigned long long double");
	printf("\nsigned short float");
	printf("\nsigned long float");
	printf("\nsigned long long float");
	printf("\nsigned short char");
	printf("\nsigned long char");
	printf("\nsigned long long char");
	printf("\nsigned short void");
	printf("\nsigned long void");
	printf("\nsigned long long void");

	/*Combinacoes Invalidas com unsigned*/
	printf("\nunsigned short double");
	printf("\nunsigned long double");
	printf("\nunsigned long long double");
	printf("\nunsigned short float");
	printf("\nunsigned long float");
	printf("\nunsigned long long float");
	printf("\nunsigned short char");
	printf("\nunsigned long char");
	printf("\nunsigned long long char");
	printf("\nunsigned short void");
	printf("\nunsigned long void\n\n");

	return OK;
}
 
