/* 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: programa de testes da funcao GerarDigitoVerificadorPisPasep com 1 argumento de linha de comando
 *
 *
 * $Author: leticia.santos $
 * $Date: 2019/05/07 03:27:04 $
 * $Log: aula0605b.c,v $
 * Revision 1.1  2019/05/07 03:27:04  leticia.santos
 * Initial revision
 *
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0604.h"

#define OK                                                            0
#define EOS                                                         '\0'
#define NUMERO_ARGUMENTOS                                             2
#define ARGUMENTO_INVALIDO                                             3
#define NUM_ARG_INVALIDO                                              1

int
main (int argc, char *argv[])
{
	unsigned indice, verificador;
	char * pisPasep;
	char * digitoVerificador;
	
	/* Teste 1 - numero de argumentos */
	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Argumento invalido.\n");
		printf ("Use: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <d9> <d10> \n\n", argv[0]);
		exit (NUM_ARG_INVALIDO);
	}

	pisPasep = (char *) malloc (sizeof(char)*10);
	digitoVerificador = (char *) malloc (sizeof(char)*1);

	/* Teste 2 - comprimento */
	if (strlen (argv[1]) != COMPRIMENTO_PISPASEP)
	{
		printf ("Argumento com mais de um digito. \n");
		printf ("Use: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <d9> <d10> \n\n", argv[0]);
		exit (ARGUMENTO_INVALIDO);
	}
	for (indice = 0; indice < COMPRIMENTO_PISPASEP; indice++)
		pisPasep [indice] = argv [1][indice];
		
	verificador = GerarDigitoVerificadorPisPasep (pisPasep, digitoVerificador);

	if (verificador != ok)
	{
		printf ("Argumento invalido.\n");
		printf ("Use: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <d9> <d10> \n\n", argv[0]);
		exit (ARGUMENTO_INVALIDO);
	}

	printf ("Digito verificador: %c  \n\n", *digitoVerificador);

	free (digitoVerificador);
	free (pisPasep);

	return OK;
}
