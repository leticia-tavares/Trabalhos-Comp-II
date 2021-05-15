/* Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: prototipo da funcoes MultiplicarMatrizes e MostrarMatriz
 *
 * $Author: leticia.santos $
 * $Date: 2019/05/11 01:00:58 $
 * $Log: aula0701.h,v $
 * Revision 1.1  2019/05/11 01:00:58  leticia.santos
 * Initial revision
 *
 *
 */

#ifndef _AULA0701_
#define _AULA0701_           "@(#)aula0701.h $Revision: 1.1 $"


/* Definicao de linhas e colunas */
#define M_1_LINHAS             5
#define M_1_COLUNAS            3

#define M_2_LINHAS             3
#define M_2_COLUNAS            4

/* matrizProduto tem numero de linhas da matriz 1 e numero de colunas da matriz 2  */ 


typedef enum 
{
	ok,
	matriz1NULL,
	matriz2NULL,
	matrizProdutoNULL,
	invalido	
}tipoErros;

tipoErros
MultiplicarMatrizes (float matriz1 [M_1_LINHAS][M_1_COLUNAS],
		     float matriz2 [M_2_LINHAS][M_2_COLUNAS],
		     float matrizProduto [M_1_LINHAS][M_2_COLUNAS]);


void
MostrarMatriz (float [M_1_LINHAS][M_2_COLUNAS]);

#endif
