/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica 
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II -Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: implementacao da funcao CalcularSerieHarmonicaAlternada com do...while
 *
 * $Author: leticia.santos $
 * $Date: 2019/04/28 04:47:26 $
 * $Log: aula0501b.c,v $
 * Revision 1.1  2019/04/28 04:47:26  leticia.santos
 * Initial revision
 *
 * 
 *
 */

#include "aula0401.h"
#include "aula0501.h"

float
CalcularSerieHarmonicaAlternada (unsigned long int numero)
{
	float resultado;

	if (numero == 0)
		return 0.0;
	
	resultado = 0;

	do
	{
		if ((numero % 2) == 0)
			resultado -= (float) 1/(CalcularExponencial(numero, numero));
		else
			resultado += (float) 1/(CalcularExponencial(numero, numero));
		numero--;
	}
	while (numero > 0);
	
	return resultado;
}		

