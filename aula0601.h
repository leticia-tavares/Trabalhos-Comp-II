/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Leticia Tavares dos Santos
 * Descricao: prototipo da funcao GerarDigitoVerificadorPisPasep
 *
 * $Author: leticia.santos $
 * $Date: 2019/05/06 23:11:26 $
 * $Log: aula0601.h,v $
 * Revision 1.3  2019/05/06 23:11:26  leticia.santos
 * *** empty log message ***
 *
 * Revision 1.2  2019/05/03 02:49:41  leticia.santos
 * *** empty log message ***
 *
 * Revision 1.1  2019/05/03 01:20:50  leticia.santos
 * Initial revision
 *
 *
 *
 */

#ifndef _AULA0601_
#define _AULA0601_          "@(#)aula0601.h $Revision: 1.3 $"

#define COMPRIMENTO_PISPASEP                    10  

/* com o digito verificador*/
#define NUMERO_DIGITOS_PISPASEP                 11

typedef unsigned char byte;

typedef enum
{
	ok,
	argumentoInvalido,
	argumentoVazio,
	invalido
}tipoErros;

tipoErros
GerarDigitoVerificadorPisPasep (byte[]);

tipoErros
ValidarPisPasep(byte[]);

#endif
