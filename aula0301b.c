/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: implementacao da funcao CalcularMaximoDivisorComum utilizando do...while
 *
 * $Author: leticia.santos $
 * $Date: 2019/04/14 14:52:17 $
 * $Log: aula0301b.c,v $
 * Revision 1.1  2019/04/14 14:52:17  leticia.santos
 * Initial revision
 *
 *
 */

#include "aula0301.h"

ull
CalcularMaximoDivisorComum(ull numero1, ull numero2)
{
	ull resto;
	
	if (numero1 == 0)
		return numero2;

	if (numero2 == 0)
		return numero1;

	resto = numero1 % numero2; 

	if (resto == 0)
		return numero2;

	do 
	{
		resto = numero1 % numero2;
		numero1 = numero2;
		numero2 = resto;
	}
	while (resto != 0);

	return numero1;		
}
