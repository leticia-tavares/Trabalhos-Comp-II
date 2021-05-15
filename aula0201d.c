/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: funcao CalcularTermoSerieFibonacci implementada com while 
 *
 * $Author: leticia.santos $
 * $Date: 2019/04/05 02:55:19 $
 * $Log: aula0201d.c,v $
 * Revision 1.1  2019/04/05 02:55:19  leticia.santos
 * Initial revision
 *
 *
 */

#include "aula0201.h"

ull
CalcularTermoSerieFibonacci (unsigned short numero)
{

	unsigned indice = 0;
	ull fibonacci, fibo0, fibo1;

	/* F(n) = n */
	if (numero <= 1)
		return numero;

	/* F(n) = F(n-1) + F(n-2) */
	fibo0 = 0;
	fibo1 = 1;

	while (indice < numero -1)
	{
		fibonacci = (fibo0 + fibo1);
		fibo0 = fibo1;
		fibo1 = fibonacci;
		indice++;
	}
	return fibonacci;
}
