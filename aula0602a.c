/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: programa de testes da funcao GerarDigitoVerificadorPisPasep
 *
 * $Author: leticia.santos $
 * $Date: 2019/05/06 23:11:45 $
 * $Log: aula0602a.c,v $
 * Revision 1.2  2019/05/06 23:11:45  leticia.santos
 * *** empty log message ***
 *
 * Revision 1.1  2019/05/03 01:21:07  leticia.santos
 * Initial revision
 *
 *
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include "aula0601.h"

#define OK                                                  0
#define NUMERO_ARGUMENTOS                                   11
#define ARGUMENTO_INVALIDO                                  2
#define EOS                                                 '\0'
#define NUM_ARG_INVALIDO                                    1

int
main (int argc, char *argv[])
{ 
	unsigned indice, validador;
	byte pisPasep [NUMERO_DIGITOS_PISPASEP];
	char *verificacao;
	
	/* Teste 1 - numero de argumentos */
	
	if(argc != NUMERO_ARGUMENTOS)
	{
		printf ("Numero de argumentos invalido.\n");
		printf ("Use: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <d9> <d10> \n\n", argv[0]);
		exit (NUM_ARG_INVALIDO);
	}

	for (indice = 0; indice < NUMERO_ARGUMENTOS - 1; indice++)
	{
		/* Teste 2 - Numero negativo */

		if (argv[indice + 1][0] == '-')
		{
			printf ("Caractere \"-\" invalido. \n");	
			printf ("Use: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <d9> <d10> \n\n", argv[0]);
			exit (ARGUMENTO_INVALIDO);
		}

		pisPasep[indice] = (byte) strtoul (argv[indice + 1], &verificacao, 10);

		/* Teste 3 - caracteres invalidos */
		if (*verificacao != EOS)
		{
			printf ("Caractere invalido \" %c \".\n", *verificacao);
			printf ("Use: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <d9> <d10> \n\n", argv[0]);
			exit (ARGUMENTO_INVALIDO);
		}
		
	}
	
	validador =  GerarDigitoVerificadorPisPasep (pisPasep);	
		
	if (validador != ok)
	{
		printf ("\nArgumento invalido.\n"); 	
		printf ("Use: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <d9> <d10> \n\n", argv[0]);
		exit (ARGUMENTO_INVALIDO);
	}	

	printf ("O digito verificador eh %i \n\n", pisPasep [COMPRIMENTO_PISPASEP]);
	return OK;
}






