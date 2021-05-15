/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: programa de testes para a funcao CalcularMaximoDivisorComum
 *
 * $Author: leticia.santos $
 * $Date: 2019/04/14 15:09:53 $
 * $Log: aula0302.c,v $
 * Revision 1.3  2019/04/14 15:09:53  leticia.santos
 * *** empty log message ***
 *
 * Revision 1.2  2019/04/14 14:55:43  leticia.santos
 * *** empty log message ***
 *
 * Revision 1.1  2019/04/14 02:02:04  leticia.santos
 * Initial revision
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "aula0301.h"

#define OK 	                    0
#define NUMERO_ARGUMENTOS           3
#define NUMERO_ARG_INVALIDO         1
#define CARACTERE_INVALIDO          2
#define ARGUMENTO_INVALIDO          1
#define EOS                        '\0'


int
main (int argc, char *argv[])
{
	ull numero1, numero2, mdc;
	char *validacao1;
	char *validacao2;

	/* Teste 1*/
	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nNumero de argumentos invalido.\n");
		printf ("\nUse: %s <inteiro nao negativo> <inteiro nao negativo>.\n\n", argv[0]);
		exit (NUMERO_ARG_INVALIDO);
	}

	/* Teste 2*/
	if ((argv[1][0] == '-') || (argv[2][0] == '-'))
	{
		printf ("\nCaractere  \"-\" invalido.\n");
		printf ("\nUse apenas numeros inteiros nao negativos.\n\n");
		exit (CARACTERE_INVALIDO);
	}

	numero1 = strtoul (argv[1], &validacao1, 10);
	numero2 = strtoul (argv[2], &validacao2, 10);
	
	/* Teste 3*/
	if ((*validacao1 != EOS) || (*validacao2 != EOS))
	{
	printf ("\nArgumento(s) Invalido(s).\n");
	printf ("\nCaractere(s) invalido(s): \" %c \"  e \" %c \"\n\n", *validacao1, *validacao2);
	exit (CARACTERE_INVALIDO);
	}
 
	/* Teste 4*/
	if ((numero1 == 0) && (numero2 == 0))
	{
		printf ("\nArgumentos invalidos.\n");
		printf ("\nDivisao de zero por zero.\n\n");
		exit (ARGUMENTO_INVALIDO);
	}

	mdc = CalcularMaximoDivisorComum (numero1, numero2);
	
	printf ("\n\t\tMaximo Divisor Comum\n");
	printf ("\n\nMDC (%llu, %llu) = %llu\n\n\n", numero1, numero2, mdc);

	return OK;
}





