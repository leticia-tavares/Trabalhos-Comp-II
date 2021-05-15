/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: prototipos das funcoes recebendo strings
 *
 * $Author: leticia.santos $
 * $Date: 2019/05/07 05:36:02 $
 * $Log: aula0604.h,v $
 * Revision 1.2  2019/05/07 05:36:02  leticia.santos
 * *** empty log message ***
 *
 * Revision 1.1  2019/05/07 03:09:03  leticia.santos
 * Initial revision
 *
 *
 *
 */

#ifndef _AULA0604_
#define _AULA0604_        "@(#)aula0604.h $Revision: 1.2 $"

#define COMPRIMENTO_PISPASEP                  10
#define NUMERO_DIGITOS_PISPASEP               11

typedef unsigned char byte;

typedef enum 
{
	ok,
	argumentoInvalido,
	argumentoVazio,
	invalido
}tipoErros;

tipoErros
GerarDigitoVerificadorPisPasep (char *, char *);

tipoErros
ValidarPisPasep (char *);

#endif
