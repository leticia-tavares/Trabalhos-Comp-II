/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica 
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II -Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: implementacao da funcao CalcularSerieHarmonicaAlternada com while
 *
 * $Author: leticia.santos $
 * $Date: 2019/04/28 05:09:40 $
 * $Log: aula0501d.c,v $
 * Revision 1.1  2019/04/28 05:09:40  leticia.santos
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

	while (numero > 0)
	{
		if ((numero % 2) == 0)
			resultado -= (float) 1/(CalcularExponencial(numero, numero));
		else
			resultado += (float) 1/(CalcularExponencial(numero, numero));
		numero--;
	}
		
	return resultado;
}		

