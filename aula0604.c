/* 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: implementacao das funcoes GerarDigitoVerificadorPisPasep e ValidarPisPasep
 *
 *
 * $Author: leticia.santos $
 * $Date: 2019/05/07 05:35:37 $
 * $Log: aula0604.c,v $
 * Revision 1.2  2019/05/07 05:35:37  leticia.santos
 * *** empty log message ***
 *
 * Revision 1.1  2019/05/07 03:09:21  leticia.santos
 * Initial revision
 *
 *
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aula0604.h"

tipoErros
GerarDigitoVerificadorPisPasep (char * pisPasep, char * digitoVerificador)
{
	unsigned soma = 0;
	unsigned indice, resto;
	char *resultado;
	
	resultado = (char *) malloc (sizeof(char)*2);	
	
	 if (!pisPasep)
		return argumentoVazio;
	
	
	for (indice = 0; indice < COMPRIMENTO_PISPASEP; indice++)
		if ((pisPasep [indice] < '0') || (pisPasep [indice] > '9'))
			return argumentoInvalido;
		
	soma +=  ((pisPasep[0] - '0')*3) + ((pisPasep[1] - '0')*2);
	
	for (indice = 0; indice < COMPRIMENTO_PISPASEP - 2; indice++)
		soma += (pisPasep [indice + 2] - '0') * (9 - indice);
	
	resto = soma % 11;
	
	if ((resto == 0) || (resto == 1))
		strcpy (digitoVerificador, "0");

	else 
	{
		resultado[0] = (11 - resto) + '0';
		resultado[1] = '\0';
		strcpy (digitoVerificador, resultado);
	}
	return ok;
}

tipoErros
ValidarPisPasep (char * pisPasep)
{
	tipoErros verificador;
	char * digitoVerificador;
	char * digitoValidado;
	unsigned indice;
	
	if (!pisPasep)
		return argumentoVazio;

	for (indice = 0; indice < NUMERO_DIGITOS_PISPASEP - 1; indice++)
		if ((pisPasep [indice] > '9') || (pisPasep [indice] < '0'))
			return argumentoInvalido;

	digitoVerificador = (char *) malloc (sizeof (char)*2);
	digitoValidado = (char *) malloc (sizeof (char)*2);

		
	digitoValidado [0] = pisPasep [COMPRIMENTO_PISPASEP + 1];

	verificador = GerarDigitoVerificadorPisPasep (pisPasep, digitoVerificador);
	
	
	if (verificador == argumentoVazio)
	{
		free (digitoVerificador);
		return argumentoVazio;
	}
	
	if (verificador == argumentoInvalido)
	{	
		free(digitoVerificador);
		return argumentoInvalido;
	}

	if (digitoValidado [0] != digitoVerificador [0])
	{
		free(digitoVerificador);
		return invalido;
	}
	free(digitoVerificador);
	return ok;

}







