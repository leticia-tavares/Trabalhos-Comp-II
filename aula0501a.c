/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica 
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II -Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: implementacao da funcao CalcularSerieHarmonicaAlternada com recursividade
 *
 * $Author: leticia.santos $
 * $Date: 2019/04/28 04:28:43 $
 * $Log: aula0501a.c,v $
 * Revision 1.1  2019/04/28 04:28:43  leticia.santos
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
	if (numero == 0)
		return 0.0;

	if ((numero % 2) == 0)
		return (float) (-1.0/CalcularExponencial(numero, numero)) + CalcularSerieHarmonicaAlternada(numero - 1);

	return (float) (1.0/CalcularExponencial(numero, numero)) + CalcularSerieHarmonicaAlternada(numero - 1);

}
