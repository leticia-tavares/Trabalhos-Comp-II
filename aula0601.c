/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: implementacao da funcao GerarDigitoVerificadorPisPasep
 *
 * $Author: leticia.santos $
 * $Date: 2019/05/06 23:11:34 $
 * $Log: aula0601.c,v $
 * Revision 1.3  2019/05/06 23:11:34  leticia.santos
 * *** empty log message ***
 *
 * Revision 1.2  2019/05/03 02:49:47  leticia.santos
 * *** empty log message ***
 *
 * Revision 1.1  2019/05/03 01:20:56  leticia.santos
 * Initial revision
 *
 *
 *
 */

#include "aula0601.h"

tipoErros
GerarDigitoVerificadorPisPasep (byte pisPasep[COMPRIMENTO_PISPASEP])
{
	unsigned soma = 0;
        unsigned indice, resto;
 
	if(!pisPasep)
		return argumentoVazio;

	for (indice = 0; indice < COMPRIMENTO_PISPASEP; indice++)
	{	
		if ((pisPasep [indice] > 9) || (pisPasep [indice] < 0))
			return argumentoInvalido;
	}	
	
	soma += (unsigned) pisPasep[0]*3 + pisPasep[1]*2;
	
	for (indice = 0; indice < COMPRIMENTO_PISPASEP - 2; indice++)
		soma += (unsigned) pisPasep[indice + 2] * (9 - indice);
	
	resto = soma % 11;
	
	if ((resto == 0) || (resto == 1))
		pisPasep[COMPRIMENTO_PISPASEP] = (byte) 0;
		
	else
		pisPasep [COMPRIMENTO_PISPASEP] = (byte) (11 - resto);
	
	return ok;
}


tipoErros
ValidarPisPasep (byte pisPasep [NUMERO_DIGITOS_PISPASEP])
{
	tipoErros validacao;
	byte validadePisPasep;
	unsigned indice;
	
	for (indice = 0; indice < COMPRIMENTO_PISPASEP; indice++)
		if (pisPasep [indice] > 9)
			return argumentoInvalido;

	validadePisPasep = pisPasep[COMPRIMENTO_PISPASEP];
 	
	validacao = GerarDigitoVerificadorPisPasep (pisPasep);

	if (pisPasep[COMPRIMENTO_PISPASEP] != validadePisPasep)
		return invalido;
	
	if (validacao == argumentoInvalido)
		return argumentoInvalido;
	
	return ok;
}

