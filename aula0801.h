/* 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: prototipo das funcoes do algoritmo de preenchimento de area
 *
 * $Author: leticia.santos $
 * $Date: 2019/05/20 23:55:53 $
 * $Log: aula0801.h,v $
 * Revision 1.2  2019/05/20 23:55:53  leticia.santos
 * *** empty log message ***
 *
 * Revision 1.1  2019/05/19 04:25:32  leticia.santos
 * Initial revision
 *
 *
 *
 */


#ifndef _AULA0801_
#define _AULA0801_         "@(#)aula0801.h $Revision: 1.2 $"

#ifdef __linux__
#define _XOPEN_SOURCE                         600
#define _POSIC_X_SOURCE                       10000
#endif
#include <unistd.h>

#define APAGADO                              '0'            
#define ACESO                                '1'

#define NUMERO_MAXIMO_LINHAS                250
#define NUMERO_MAXIMO_COLUNAS               800

#define TEMPO_MAXIMO                        1000000
#define TEMPO_CHAMADA_LIMPAR                  0

#define MINIMO_ORDENADA_ABSCISSA              1


typedef enum {apagado, aceso}tipoPixel;


typedef enum 
{
	ok,
	erroMonitorNULL,
	erroTempoInvalido,
	erroDimensaoInvalida,
	erroCaractereInvalido,
	erroRetanguloInvalido,
	erroPontoInvalido
}tipoErros;

tipoErros
MostrarMonitor (tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], unsigned maximoLinhas, unsigned maximoColunas, __useconds_t tempoEspera);

tipoErros
LimparMonitor (tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], unsigned maximoLinhas, unsigned maximoColunas);


tipoErros
DesenharRetangulo (tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], 
		   unsigned maximoLinhas, unsigned maximoColunas,
		   unsigned ordenadaEsquerda, unsigned abscissaEsquerda,
		   unsigned ordenadaDireita, unsigned abscissaDireita, __useconds_t tempoEspera);


tipoErros
PreencherPoligono (tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], unsigned maximoLinhas, unsigned maximoColunas, 
		   unsigned linha, unsigned coluna, __useconds_t tempoEspera);

#endif  
