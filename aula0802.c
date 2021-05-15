/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: programa de testes da funcao PreencherPoligono
 *
 * $Author: leticia.santos $
 * $Date: 2019/05/20 23:56:13 $
 * $Log: aula0802.c,v $
 * Revision 1.2  2019/05/20 23:56:13  leticia.santos
 * *** empty log message ***
 *
 * Revision 1.1  2019/05/19 04:26:04  leticia.santos
 * Initial revision
 *
 *
 *
 */

#ifdef __linux__
#define _XOPEN_SOURCE           600
#define _POSIC_X_SOURCE         10000
#endif
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#include "aula0801.h"

#define OK                             0
#define NUMERO_ARGUMENTOS              10
#define NUM_ARG_INVALIDO               1
#define ARGUMENTO_INVALIDO             2
#define CARACTERE_INVALIDO             3               
#define EOS                            '\0'

int
main (int argc, char *argv[])
{
	unsigned int indice, auxiliar;
	unsigned int argumentos[NUMERO_ARGUMENTOS]; 
	char *verificacao;
	tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];
	tipoErros validar[4];

	if(argc != NUMERO_ARGUMENTOS)
	{
		printf ("Numero de argumentos invalido.\n");
		printf ("Use: %s <nLinhas> <nColunas> <ordenadaEsquerda> <ordenadaDireita> <abscissaDireita> <abscissaEsquerda> <linhaPonto> <colunaPonto> <tempo-espera>. \n\n", argv[0]);
		exit (NUM_ARG_INVALIDO);
	}

	for (indice = 0; indice < (NUMERO_ARGUMENTOS - 1); indice++)
	{
		if (argv[indice + 1][0] == '-')
		{
			printf ("Caractere \"-\" invalido. Entre com numeros positivos inteiros.\n");
			printf ("Use: %s <nLinhas> <nColunas> <ordenadaEsquerda> <ordenadaDireita> <abscissaDireita> <abscissaEsquerda> <linhaPonto> <colunaPonto> <tempo-espera>. \n\n", argv[0]);
			exit (CARACTERE_INVALIDO);
		}
	
		auxiliar = (unsigned int) strtoul (argv[indice + 1], &verificacao, 10);
		
		if (*verificacao != EOS)
		{
			printf ("Caractere \" %c \" invalido. \n", *verificacao);
			printf ("Use: %s <nLinhas> <nColunas> <ordenadaEsquerda> <ordenadaDireita> <abscissaDireita> <abscissaEsquerda> <linhaPonto> <colunaPonto <tempo-espera>. \n\n", argv[0]);
			exit (CARACTERE_INVALIDO);
		}
		argumentos[indice] = auxiliar;
	}
	
	/*Erro de dimensao antes de chamar a funcao PreencherPoligono */
	if ((argumentos[2] > argumentos[0]) || (argumentos[4] > argumentos[1]) || (argumentos[3] > argumentos[0]) || (argumentos[5] > argumentos[1]))
	{

		printf ("\nErro 3:\tMonitor com dimensao invalida\n\n");
		printf ("Use: %s <nLinhas> <nColunas> <ordenadaEsquerda> <ordenadaDireita> <abscissaDireita> <abscissaEsquerda> <linhaPonto> <colunaPonto <tempo-espera>. \n\n", argv[0]);
		exit(ARGUMENTO_INVALIDO);
	}


	validar[0] = LimparMonitor (monitor, argumentos[0], argumentos[1]);
	validar[1] = DesenharRetangulo (monitor, argumentos[0], argumentos[1], argumentos[2], argumentos[5], argumentos[3], argumentos[4], argumentos[8]);
	validar[2] = MostrarMonitor (monitor, argumentos[0], argumentos[1], argumentos[8]);
	validar[3] = PreencherPoligono (monitor, argumentos[0], argumentos[1], (argumentos[6] - 1), (argumentos[7] - 1), argumentos[8]);

	for(indice = 0; indice < 4; indice++)
	{
		
		switch (validar[indice])	
		{
			case ok:
				MostrarMonitor (monitor, argumentos[0],argumentos[1], argumentos[8]);
				printf ("\n");
			break;

			case erroMonitorNULL:
			{
				printf ("\nErro 1:\tMonitor vazio\n\n");
				printf ("Use: %s <nLinhas> <nColunas> <ordenadaEsquerda> <ordenadaDireita> <abscissaDireita> <abscissaEsquerda> <linhaPonto> <colunaPonto <tempo-espera>. \n\n", argv[0]);
				exit(ARGUMENTO_INVALIDO);
			}
			break;

			case erroTempoInvalido:
			{
				printf ("\nErro 2:\t Tempo de espera invalido\n\n");
				printf ("Use: %s <nLinhas> <nColunas> <ordenadaEsquerda> <ordenadaDireita> <abscissaDireita> <abscissaEsquerda> <linhaPonto> <colunaPonto <tempo-espera>. \n\n", argv[0]);
				exit(ARGUMENTO_INVALIDO);
			}
			break;

			case erroDimensaoInvalida:
			{
				printf ("\nErro 3:\tMonitor com dimensao invalida\n\n");
				printf ("Use: %s <nLinhas> <nColunas> <ordenadaEsquerda> <ordenadaDireita> <abscissaDireita> <abscissaEsquerda> <linhaPonto> <colunaPonto <tempo-espera>. \n\n", argv[0]);
				exit(ARGUMENTO_INVALIDO);
			}
			break;

			case erroCaractereInvalido:
			{
				printf ("\nErro 4:\tCaractere invalido. Monitor deve estar aceso ou apagado\n\n");
				printf ("Use: %s <nLinhas> <nColunas> <ordenadaEsquerda> <ordenadaDireita> <abscissaDireita> <abscissaEsquerda> <linhaPonto> <colunaPonto <tempo-espera>. \n\n", argv[0]);
				exit(ARGUMENTO_INVALIDO);
			}
			break;

			case erroRetanguloInvalido:
			{
				printf ("\nErro 5:\tRetangulo impossivel. As coordenadas passadas sao invalidas\n\n");
				printf ("Use: %s <nLinhas> <nColunas> <ordenadaEsquerda> <ordenadaDireita> <abscissaDireita> <abscissaEsquerda> <linhaPonto> <colunaPonto <tempo-espera>. \n\n", argv[0]);
				exit(ARGUMENTO_INVALIDO);
			}
			break;
			
			case erroPontoInvalido:
			{
				printf ("\nErro 6:\tPonto (pixel) impossivel. As coordenadas passadas sao invalidas\n\n");
				printf ("Use: %s <nLinhas> <nColunas> <ordenadaEsquerda> <ordenadaDireita> <abscissaDireita> <abscissaEsquerda> <linhaPonto> <colunaPonto <tempo-espera>. \n\n", argv[0]);
				exit(ARGUMENTO_INVALIDO);
			}
			break;	
		}
	}
	
	return OK;
}/* Funcao main() */


