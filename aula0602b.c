/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: programa de testes da funcao GerarDigitoVerificadorPisPasep ataraves de 1 argumento
 *
 * $Author: leticia.santos $
 * $Date: 2019/05/06 23:31:12 $
 * $Log: aula0602b.c,v $
 * Revision 1.2  2019/05/06 23:31:12  leticia.santos
 * *** empty log message ***
 *
 * Revision 1.1  2019/05/03 01:51:32  leticia.santos
 * Initial revision
 *
 *
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0601.h"

#define OK                                                  0
#define NUMERO_ARGUMENTOS                                   2
#define ARGUMENTO_INVALIDO                                  3
#define EOS                                                 '\0'
#define NUM_ARG_INVALIDO                                    1

int
main (int argc, char *argv[])
{ 
	unsigned indice, verificacao;
	byte pisPasep [NUMERO_DIGITOS_PISPASEP];
	
	/* Teste 1 - numeros de argumentos */
	if(argc != NUMERO_ARGUMENTOS)
	{
		printf ("Numero de argumentos invalido.\n");
		printf ("Use: %s <d1><d2><d3><d4><d5><d6><d7><d8><d9><d10> \n\n", argv[0]);
		exit (NUM_ARG_INVALIDO);
	}

	/* Teste 2 - numero negativo */
	for (indice = 0; indice < COMPRIMENTO_PISPASEP; indice++)
		if (argv[1][indice] == '-')
		{
			printf ("Caractere \"-\" invalido. \n");	
			printf ("Entre com numeros inteiros.\n\n");	
			exit (ARGUMENTO_INVALIDO);
		}

	/* Teste 3 - comprimento */
	if (strlen(argv[1]) != COMPRIMENTO_PISPASEP)
	{
		printf("\nArgumento invalido.\n\n");
		printf("Entre com 10 digitos.\n\n");
		exit (ARGUMENTO_INVALIDO);
	}
	
	/* Teste 4 - valor */
	for (indice = 0; indice != EOS; indice++)
		if((argv[1][indice] < 0)  || (argv[1][indice] > 9))
		{
			printf ("Argumento invalido.\n");
			printf ("Entre com numeros entre 0 e 9.\n\n");
			exit(ARGUMENTO_INVALIDO);
		}
	
	for (indice = 0; indice < COMPRIMENTO_PISPASEP; indice++)
		pisPasep [indice] = (byte) (argv[1][indice] - '0');

	verificacao  =  GerarDigitoVerificadorPisPasep (pisPasep);	
	
	
	if (verificacao != ok)
	{
		printf ("\nArgumento vazio e invalido.\n\nEntre com numeros inteiros de 0 a 9\n\n"); 		     exit (ARGUMENTO_INVALIDO);
	}	

	printf ("O digito verificador eh %i  \n\n", pisPasep [COMPRIMENTO_PISPASEP]);
	
	return OK;
}

