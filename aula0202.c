/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: programa de testes para a funcao CalcularTermoSerieFibonacci
 *
 * $Author: leticia.santos $
 * $Date: 2019/04/04 14:00:47 $
 * $Log: aula0202.c,v $
 * Revision 1.1  2019/04/04 14:00:47  leticia.santos
 * Initial revision
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "aula0201.h"

#define OK                                0
#define EOS                              '\0'
#define NUMERO_ARGUMENTOS                 2
#define NUMERO_ARGUMENTOS_INVALIDOS       1
#define CARACTERE_INVALIDO                2

int
main(int argc, char *argv[])
{
	unsigned short numero;
	unsigned indice;
	char *validacao;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf("Numero de argumentos invalidos!\n");
		printf("Use: %s <inteiro>\n", argv[0]);
		exit (NUMERO_ARGUMENTOS_INVALIDOS);
	}

	if (argv[1][0] == '-')
	{	
		printf("Caractere \"-\" invalido!\n");
		exit (CARACTERE_INVALIDO);
	}

	numero = strtoul(argv[1], &validacao, 10);
	if (*validacao != EOS)
	{
		printf("Caractere \"%c\" invalido.\n\n", *validacao);
		exit (CARACTERE_INVALIDO);
	}

	for (indice = 0; indice <= numero; indice++)
		printf("F(%u) = %llu \n", indice, CalcularTermoSerieFibonacci(indice));

	return OK;
}
