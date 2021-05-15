/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: Programa de testes da funcao MultiplicarMatrizes
 *
 * $Author: leticia.santos $
 * $Date: 2019/05/11 01:01:17 $
 * $Log: aula0702.c,v $
 * Revision 1.1  2019/05/11 01:01:17  leticia.santos
 * Initial revision
 *
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "aula0701.h"

#define OK                           0
#define NUMERO_ARGUMENTOS            1 + (M_1_LINHAS)*(M_1_COLUNAS) + (M_2_LINHAS)*(M_2_COLUNAS)
#define NUM_ARG_INVALIDO             1
#define ARGUMENTO_INVALIDO           2
#define EOS                          '\0'

int
main (int argc, char *argv[])
{
	unsigned linha, coluna, verificador;
	unsigned contador = 1;
	float matriz1 [M_1_LINHAS][M_1_COLUNAS];
	float matriz2 [M_2_LINHAS][M_2_COLUNAS];
	float matrizProduto [M_1_LINHAS][M_2_COLUNAS];
	char *validacao;
	

	/* Teste 1 - numero de argumentos */
	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Numero de argumentos invalido. \n");
		printf ("Use: %s <a11> <a12> <a13> <a21> ... <b31> <b32> <b33> <b34> \n\n", argv[0]);
		exit (NUM_ARG_INVALIDO);
	}

	
	for (linha = 0; linha < M_1_LINHAS; linha++)
		for (coluna = 0; coluna < M_1_COLUNAS; coluna++)
		{
			matriz1 [linha][coluna] = strtof (argv [contador], &validacao);
			
			/* Teste 2 - caracteres invalidos */
			if (*validacao != EOS)
			{
				printf ("Caractere \" %c \" invalido na matriz1. O programa so aceita numeros inteiros e/ou \" - \". \n\n", *validacao);
				exit (ARGUMENTO_INVALIDO);
			}
			printf ("matriz1[%u][%u] = %f \n", linha, coluna, matriz1[linha][coluna]);
			contador++;
		}
	
	for (linha = 0; linha < M_2_LINHAS; linha++)
		for (coluna = 0; coluna < M_2_COLUNAS; coluna++)
		{
			matriz2 [linha][coluna] = strtof (argv [contador], &validacao);
			
			/* Teste 2 - caracteres invalidos */
			if (*validacao != EOS)
			{
				printf ("Caractere \" %c \" invalido na matriz2. O programa so aceita numeros inteiros e/ou \" - \". \n\n", *validacao);
				exit (ARGUMENTO_INVALIDO);
			}
			printf ("matriz2[%u][%u] = %f \n", linha, coluna, matriz2[linha][coluna]);
			contador++;
		}

	verificador = MultiplicarMatrizes (matriz1, matriz2, matrizProduto);
	
	/* Teste tipoErros */
	if (verificador != ok)
	{
		printf ("Use: %s <a11> <a12> <a13> <a21> ... <b31> <b32> <b33> <b34> \n\n", argv[0]);
		exit (ARGUMENTO_INVALIDO);
	}
	
	MostrarMatriz (matrizProduto);

	return OK;
}
