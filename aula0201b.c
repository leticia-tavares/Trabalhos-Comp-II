/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: funcao CalcularTermoSerieFibonacci implementada com do...while
 *
 * $Author: leticia.santos $
 * $Date: 2019/04/05 02:14:17 $
 * $Log: aula0201b.c,v $
 * Revision 1.1  2019/04/05 02:14:17  leticia.santos
 * Initial revision
 *
 *
 */

#include "aula0201.h"

ull 
CalcularTermoSerieFibonacci(unsigned short numero)
{
	ull fibonacci, fibo0, fibo1;
	unsigned indice = 0;

	/* F(n) = n */
	if (numero <= 1)
		return (ull) numero;

	/* F(n) = F(n-1) + F(n-2) */
	fibo0 = 0;
	fibo1 = 1;
	
	do
	{
	fibonacci = (fibo0 +fibo1);
	fibo0 = fibo1;
	fibo1 = fibonacci;
	indice++;
	}

	while (indice < numero -1);
		
	return fibonacci;
}
