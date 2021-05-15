/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: programa de testes da funcao ValidarPisPasep atraves de 11 argumentos
 *
 * $Author: leticia.santos $
 * $Date: 2019/05/06 23:56:37 $
 * $Log: aula0603a.c,v $
 * Revision 1.3  2019/05/06 23:56:37  leticia.santos
 * *** empty log message ***
 *
 * Revision 1.2  2019/05/03 19:48:15  leticia.santos
 * *** empty log message ***
 *
 * Revision 1.1  2019/05/03 02:50:53  leticia.santos
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
#define NUMERO_ARGUMENTOS                                   12
#define ARGUMENTO_INVALIDO                                  3
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
		printf ("Use: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <d9> <d10> <dv> \n\n", argv[0]);
		exit (NUM_ARG_INVALIDO);
	}
	
	for (indice = 0; indice < NUMERO_DIGITOS_PISPASEP; indice++)
	{	
		/* Teste 2 - numero negativo */
		if (argv[indice + 1][0] == '-')
		{
			printf ("Caractere \"-\" invalido. \n");	
			printf ("Entre com numeros positivos inteiros.\n\n");	
			exit (ARGUMENTO_INVALIDO);
		}

		pisPasep [indice] = (byte) strtoul(argv[indice + 1], &verificacao, 10);
		
		/* Teste 3 - caractere invalido */
		if (*verificacao != EOS)
		{
			printf ("Caractere \" %c \" invalido.\n", *verificacao);
			printf ("Use: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <d9> <d10> <dv> \n\n", argv[0]);
			exit (ARGUMENTO_INVALIDO);
		}
	
		/* Teste 4 - valor */
		if( pisPasep [indice] > 9)
		{
			printf ("Argumento invalido.\n");
			printf ("Entre com numeros entre 0 e 9.\n\n");
			exit(ARGUMENTO_INVALIDO);
		}
	}

	validador =  ValidarPisPasep (pisPasep);	
	
	if (validador == argumentoVazio)
		printf ("\nArgumento vazio e invalido.\n\n"); 	
	
	if (validador == argumentoInvalido)
	{
		printf ("Argumento invalido. \n\n");
		printf ("Use: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <d9> <d10> <dv> \n\n", argv[0]);
	}
	
	if (validador == ok)
		printf ("PisPasep valido.\n\n");
	
	if (validador == invalido)
		printf ("PisPasep invalido.\n\n");
	
	return OK;
}






