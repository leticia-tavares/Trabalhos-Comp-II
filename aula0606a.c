/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: programa de testes da funcao ValidarPisPasep atraves de 11 argumentos + hifen
 *
 * $Author: leticia.santos $
 * $Date: 2019/05/07 05:35:22 $
 * $Log: aula0606a.c,v $
 * Revision 1.1  2019/05/07 05:35:22  leticia.santos
 * Initial revision
 *
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0604.h"

#define OK                                                  0
#define NUMERO_ARGUMENTOS                                   13
#define ARGUMENTO_INVALIDO                                  3
#define EOS                                                 '\0'
#define NUM_ARG_INVALIDO                                    1

int
main (int argc, char *argv[])
{ 
	unsigned indice, validador;
	char * pisPasep;
	char * digitoVerificador;
	
	/* Teste 1 - numero de argumentos */
	if(argc != NUMERO_ARGUMENTOS)
	{
		printf ("Numero de argumentos invalido.\n");
		printf ("Use: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <d9> <d10> <-> <dv> \n\n", argv[0]);
		exit (NUM_ARG_INVALIDO);
	}
	
	pisPasep = (char *) malloc (sizeof (char) * 13);
	digitoVerificador = (char *) malloc (sizeof (char)* 1);
 
	for (indice = 0; indice < NUMERO_DIGITOS_PISPASEP - 1; indice++)
	{	
		/* Teste 2 - valor */
		if (strlen (argv [indice + 1]) != 1)
		{
			printf ("Argumento invalido (com mais de 1 digito \n");	
			printf ("Use: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <d9> <d10> <-> <dv> \n\n", argv[0]);
			exit (ARGUMENTO_INVALIDO);
		}
		
	}
	
	for (indice = 0; indice < COMPRIMENTO_PISPASEP + 2; indice++)
		pisPasep [indice] = argv [indice + 1][0];

	
	validador = ValidarPisPasep (pisPasep);
		
	if (validador == argumentoVazio)
		printf ("\nArgumento vazio e invalido.\n\n"); 	
	
	if (validador == argumentoInvalido)
	{
		printf ("Argumento invalido. arg in \n\n");
		printf ("Use: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <d9> <d10> <dv> \n\n", argv[0]);
	}
	
	if (validador == ok)
		printf ("PisPasep valido.\n\n");
	
	if (validador == invalido)
		printf ("PisPasep invalido.\n\n");
	

	free(pisPasep);
	free (digitoVerificador);

	return OK;
}

