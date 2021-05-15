/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: programa de testes da funcao ValidarPisPasep atraves de 1 argumento + hifen
 *
 * $Author: leticia.santos $
 * $Date: 2019/05/07 00:06:11 $
 * $Log: aula0603b.c,v $
 * Revision 1.2  2019/05/07 00:06:11  leticia.santos
 * *** empty log message ***
 *
 * Revision 1.1  2019/05/03 19:26:56  leticia.santos
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
	unsigned indice, validador;
	byte pisPasep [NUMERO_DIGITOS_PISPASEP];
	
	
	/* Teste 1 - Numero de Argumentos */
	if(argc != NUMERO_ARGUMENTOS)
	{
		printf ("Numero de argumentos invalido.\n");
		printf ("Use: %s <d1><d2><d3><d4><d5><d6><d7><d8><d9><d10>-<dv> \n\n", argv[0]);
		exit (NUM_ARG_INVALIDO);
	}
	
	/* Teste 2 - Numero negativo */
	if (argv[1][0] == '-')
	{
		printf ("Caractere \"-\" invalido. \n");	
		printf ("Entre com numeros positivos inteiros.\n\n");	
		exit (ARGUMENTO_INVALIDO);
	}
	
	/*Teste 3 - Presenca do hifen */
	if (argv[1][10] != '-')
	{
		printf ("Argumento invalido. Falta o hifen. \n");
		printf ("Use: %s <d1><d2><d3><d4><d5><d6><d7><d8><d9><d10>-<dv> \n\n", argv[0]);
		exit (ARGUMENTO_INVALIDO);
	}
	
	/* Teste 4- Comprimento do digito com o hifen */
	if (strlen (argv[1]) != NUMERO_DIGITOS_PISPASEP + 1)
	{
		printf ("Argumento invalido. \n");
		printf ("Use: %s <d1><d2><d3><d4><d5><d6><d7><d8><d9><d10>-<dv> \n\n", argv[0]);
		exit (ARGUMENTO_INVALIDO);
	}

	/* Teste 5 - Valor correto */
	for (indice = 0; indice < NUMERO_DIGITOS_PISPASEP - 1; indice++)
		if ((argv[1][indice] < '0') || (argv[1][indice] > '9'))
		{	
			printf ("Argumento invalido.\n");
			printf ("Entre com numeros inteiros entre 0 e 9.\n\n");
			exit (ARGUMENTO_INVALIDO);
		}

	/* Teste 6 - Valor correto digito verificador*/
	for (indice = 11; argv[1][indice] != EOS; indice++)
		if ((argv[1][indice] < '0') || (argv[1][indice] > '9'))
		{	
			printf ("Argumento invalido. Valor do digito invalido.\n");
			printf ("Entre com numeros inteiros entre 0 e 9.\n\n");
			exit(ARGUMENTO_INVALIDO);
		}

	for (indice = 0; indice < NUMERO_DIGITOS_PISPASEP; indice++)
		pisPasep [indice] = (byte) (argv[1][indice] - '0');
	
	pisPasep [10] = (byte) (argv[1][NUMERO_DIGITOS_PISPASEP] - '0');
		
	validador = ValidarPisPasep (pisPasep);
	
	if (validador == argumentoVazio)
	{
		printf ("\nArgumento vazio e invalido.\n\nEntre com numeros inteiros de 0 a 9\n\n"); 	
		exit (ARGUMENTO_INVALIDO);
	}	

	if (validador == argumentoInvalido)
	{
		printf ("\nArgumento invalido.\n\nEntre com numeros inteiros de 0 a 9\n\n"); 	
		exit (ARGUMENTO_INVALIDO);
	}
	
	if (validador == ok)
		printf ("PisPasep valido.\n\n");

	if (validador == invalido)
		printf ("PisPasep invalido. \n\n");
	
	return OK;
}






