/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica 
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II -Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: implementacao da funcao CalcularSerieHarmonicaAlternada com pow
 *
 * $Author: leticia.santos $
 * $Date: 2019/04/28 05:41:02 $
 * $Log: aula0501e.c,v $
 * Revision 1.2  2019/04/28 05:41:02  leticia.santos
 * *** empty log message ***
 *
 * Revision 1.1  2019/04/28 05:25:13  leticia.santos
 * Initial revision
 *
 * 
 *
 */

#include <math.h>
#include "aula0501.h"

float
CalcularSerieHarmonicaAlternada (unsigned long int numero)
{
	if (numero == 0)
		return 0.0;
	
	if ((numero % 2) == 0)
		return (float) (-1/(pow(numero, numero)) + CalcularSerieHarmonicaAlternada(numero -1));
	
	return (float) (1/(pow(numero, numero)) + CalcularSerieHarmonicaAlternada(numero -1));
	
}		

