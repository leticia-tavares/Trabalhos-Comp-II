/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: funcao CalcularTermoSerieFibonacci implementada com recursividade
 *
 * $Author: leticia.santos $
 * $Date: 2019/04/04 14:00:33 $
 * $Log: aula0201a.c,v $
 * Revision 1.1  2019/04/04 14:00:33  leticia.santos
 * Initial revision
 *
 *
 */

#include "aula0201.h"

ull 
CalcularTermoSerieFibonacci(unsigned short numero)
{
	if (numero <= 1)
		return (ull) numero;

	return (CalcularTermoSerieFibonacci(numero - 1) + CalcularTermoSerieFibonacci (numero - 2));
}
