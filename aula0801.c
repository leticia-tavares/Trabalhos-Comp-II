/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: implementacao das funcoes do algoritmo de preenchimento de area
 *
 *
 * $Author: leticia.santos $
 * $Date: 2019/05/20 23:56:03 $
 * $Log: aula0801.c,v $
 * Revision 1.2  2019/05/20 23:56:03  leticia.santos
 * *** empty log message ***
 *
 * Revision 1.1  2019/05/19 04:25:43  leticia.santos
 * Initial revision
 *
 *
 *
 */

#ifdef __linux__
#define _XOPEN_SOURCE 600 /*< 700 */
#define POSIX_X_SOURCE 10000 /* < 200809L */
#endif

#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#include "aula0801.h"

tipoErros
MostrarMonitor (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], unsigned maximoLinhas, unsigned maximoColunas, __useconds_t tempoEspera)
{
	unsigned indiceLinha, indiceColuna;
	
	system ("clear");

	if (!monitor)
		return erroMonitorNULL;

	if (tempoEspera >= TEMPO_MAXIMO)
		return erroTempoInvalido;

	if ((maximoLinhas > NUMERO_MAXIMO_LINHAS) || (maximoColunas > NUMERO_MAXIMO_COLUNAS))
		return erroDimensaoInvalida;
	
	/* Erro de caractere diferente de 0 ou 1 */
	for (indiceLinha = 0; indiceLinha < maximoLinhas; indiceLinha++)
		for (indiceColuna = 0; indiceColuna < maximoColunas; indiceColuna++)
			if ((monitor[indiceLinha][indiceColuna] != apagado) && (monitor[indiceLinha][indiceColuna] != aceso))
				return erroCaractereInvalido;
	
	/* Printa o monitor na tela */
	for (indiceLinha = 0; indiceLinha < maximoLinhas; indiceLinha++)
	{
		for (indiceColuna = 0; indiceColuna < maximoColunas; indiceColuna++)
			printf("%c", (monitor[indiceLinha][indiceColuna] == aceso)? ACESO : APAGADO);
		printf ("\n");
	}

	/* Tempo de congelamento da tela em ms*/
	usleep(tempoEspera);
	
	
	return ok;
}


tipoErros
LimparMonitor (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], unsigned maximoLinhas, unsigned maximoColunas)
{
	unsigned indiceLinha, indiceColuna;
	
	if (!monitor)
		return erroMonitorNULL;

	if ((maximoLinhas > NUMERO_MAXIMO_LINHAS) || (maximoColunas > NUMERO_MAXIMO_COLUNAS))
		return erroDimensaoInvalida;

	/* Apaga os pixels do monitor */
	for (indiceLinha = 0; indiceLinha < maximoLinhas; indiceLinha++)
		for (indiceColuna = 0; indiceColuna < maximoColunas; indiceColuna++)
			monitor[indiceLinha][indiceColuna] = apagado;
	
	/* Atualiza o monitor apagado */	
	MostrarMonitor (monitor, maximoLinhas, maximoColunas, TEMPO_CHAMADA_LIMPAR);

	return ok;
}	

tipoErros
DesenharRetangulo (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
		   unsigned maximoLinhas, unsigned maximoColunas,
		   unsigned ordenadaEsquerda, unsigned abscissaEsquerda,
		   unsigned ordenadaDireita, unsigned abscissaDireita, __useconds_t tempoEspera)

{
	/* ordenadaEsquerda = canto superior esquerdo;       ordenadaDireita = canto superior direito 
         * abscissaEsquerda = canto inferior esquerdo;       abscissaDireita = canto inferior direito */

	unsigned indiceLinha, indiceColuna;

	if (!monitor)
		return erroMonitorNULL;

	if (tempoEspera >= TEMPO_MAXIMO)
		return erroTempoInvalido;
	
	if ((maximoLinhas > NUMERO_MAXIMO_LINHAS) || (maximoColunas > NUMERO_MAXIMO_COLUNAS))
		return erroDimensaoInvalida;

	for (indiceLinha = 0; indiceLinha < maximoLinhas; indiceLinha++)
		for (indiceColuna = 0; indiceColuna < maximoColunas; indiceColuna++)
			if ((monitor[indiceLinha][indiceColuna] != apagado) && (monitor[indiceLinha][indiceColuna] != aceso))
				return erroCaractereInvalido;
	
	/* Erro de coordenadas */
	if ((ordenadaEsquerda > maximoLinhas) || (abscissaEsquerda > maximoColunas) || (ordenadaEsquerda >= ordenadaDireita) ||
	    (ordenadaDireita <= MINIMO_ORDENADA_ABSCISSA) || (abscissaEsquerda >= abscissaDireita) ||
            (abscissaDireita <= MINIMO_ORDENADA_ABSCISSA) || (ordenadaDireita > maximoLinhas) || (abscissaDireita > maximoColunas))
		return erroRetanguloInvalido;

	/* Desenha as colunas */	
	for (indiceLinha = (ordenadaEsquerda - 1); indiceLinha < ordenadaDireita; indiceLinha++)
	{
		monitor[indiceLinha][abscissaEsquerda - 1] = aceso;
		monitor[indiceLinha][abscissaDireita - 1] = aceso;
	}
	/* Desenha as linhas */
	for (indiceColuna = (abscissaEsquerda - 1); indiceColuna < abscissaDireita; indiceColuna++)
	{
		monitor[ordenadaEsquerda - 1][indiceColuna] = aceso;
		monitor[ordenadaDireita - 1][indiceColuna] = aceso;
	}	
	
	MostrarMonitor (monitor, maximoLinhas, maximoColunas, tempoEspera);
	
	usleep(tempoEspera);

	return ok;
}


tipoErros
PreencherPoligono (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], unsigned maximoLinhas, unsigned maximoColunas,
		   unsigned linha, unsigned coluna, __useconds_t tempoEspera)
{
	unsigned indiceLinha, indiceColuna;
	
	if (!monitor)
		return erroMonitorNULL;

	if (tempoEspera >= TEMPO_MAXIMO)
		return erroTempoInvalido;

	if ((maximoLinhas > NUMERO_MAXIMO_LINHAS) || (maximoColunas > NUMERO_MAXIMO_COLUNAS))
		return erroDimensaoInvalida;

	for (indiceLinha = 0; indiceLinha < maximoLinhas; indiceLinha++)
		for (indiceColuna = 0; indiceColuna < maximoColunas; indiceColuna++)
			if ((monitor[indiceLinha][indiceColuna] != apagado) && (monitor[indiceLinha][indiceColuna] != aceso))
				return erroCaractereInvalido;
	
	
	/* Erro ponto fora do monitor */
	if ((linha > maximoLinhas) || (coluna > maximoColunas))	
		return erroPontoInvalido;

	/* Pixel aceso, ok */
	if (monitor[linha][coluna] == aceso)
		return ok;

	/* Acende pixel apagado */
	monitor[linha][coluna] = aceso;
	
	/* Atualizar o monitor */
	MostrarMonitor (monitor, maximoLinhas, maximoColunas, tempoEspera);

	usleep(tempoEspera);
	

	/* Recursividade para preencher a area */

	if (linha <= maximoLinhas)
		PreencherPoligono (monitor, maximoLinhas, maximoColunas, linha + 1, coluna, tempoEspera);
		
	if (linha >= 1)
	       	PreencherPoligono (monitor, maximoLinhas, maximoColunas, linha - 1, coluna, tempoEspera);

       	if (coluna <= maximoColunas)
		PreencherPoligono (monitor, maximoLinhas, maximoColunas, linha, coluna + 1, tempoEspera);
       	
	if (coluna >= 1)
		PreencherPoligono (monitor, maximoLinhas, maximoColunas, linha, coluna - 1, tempoEspera);

	return ok;
}
