/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II -Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: programa de teste para a funcao CalcularSerieHarmonicaAlternada
 *
 * $Author: leticia.santos $
 * $Date: 2019/04/28 04:28:55 $
 * $Logs$
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "aula0401.h"
#include "aula0501.h"

#define OK                                         0
#define NUMERO_ARGUMENTOS                          2
#define NUMERO_ARG_INVALIDO                        1
#define ARGUMENTO_INVALIDO                         3
#define EOS                                        '\0'


int
main (int argc, char *argv[])
{
	unsigned long int numero;
	char *validacao;
	float resultado;
		
	/* Teste 1 */
	if (argc != NUMERO_ARGUMENTOS)
	{
		printf("\nNumero de argumentos invalido.\n");
		printf("\nUse: %s <inteiro-nao-negativo>. \n\n", argv[0]);
		exit (NUMERO_ARG_INVALIDO);
	}
	
	/* Teste 2 */
	if (argv[1][0] == '-')
	{
		printf("\nCaractere \"-\" invalido.\n");
		printf("\nUse apenas numeros inteiros nao negativos.\n\n" );
		exit (ARGUMENTO_INVALIDO);
	}
	
	numero = strtoul (argv[1], &validacao, 10);

	/* Teste 3 */
	if (*validacao != EOS)
	{ 
		printf ("\nArgumento invalido.\n");
		printf ("\nCaractere invalido: \" %c \" \n\n", *validacao);
		exit (ARGUMENTO_INVALIDO);
	}

	resultado = CalcularSerieHarmonicaAlternada (numero);

	printf("\n\t\tSerie Harmonica Alternada\n");
	printf ("\n\nS(%lu) = %f \n\n", numero, resultado);

	return OK;
}
