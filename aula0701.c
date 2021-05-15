/* Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: implementacao da funcoes MultiplicarMatrizes e MostrarMatriz
 *
 * $Author: leticia.santos $
 * $Date: 2019/05/11 01:01:08 $
 * $Log: aula0701.c,v $
 * Revision 1.1  2019/05/11 01:01:08  leticia.santos
 * Initial revision
 *
 *
 */

#include <stdio.h>
#include "aula0701.h"

tipoErros
MultiplicarMatrizes (float matriz1 [M_1_LINHAS][M_1_COLUNAS],
	             float matriz2 [M_2_LINHAS][M_2_COLUNAS],
		     float matrizProduto [M_1_LINHAS][M_2_COLUNAS])
{
	unsigned linha, coluna, contador;

	if (!matriz1)
		return matriz1NULL;
	
	if (!matriz2)
		return matriz2NULL;

	if (!matrizProduto)
		return matrizProdutoNULL;

	for (linha = 0; linha < M_1_LINHAS; linha++)
		for (coluna = 0; coluna < M_2_COLUNAS; coluna++)
		{
			matrizProduto[linha][coluna] = 0.0; 
	
			for (contador = 0; contador < M_2_LINHAS; contador++)
				matrizProduto[linha][coluna] += matriz1[linha][contador] * matriz2 [contador][coluna];
		}
		
	return ok;
}

void
MostrarMatriz (float matriz [M_1_LINHAS][M_2_COLUNAS])
{
	unsigned linha, coluna;

	printf("\n\n\t\t Matriz Produto \n\n");
	
	for (linha = 0; linha < M_1_LINHAS; linha++)
	{
		for (coluna = 0; coluna < M_2_COLUNAS; coluna++)
			printf ("   %.3f   ", matriz[linha][coluna]);
		printf("\n");
	}
}
