/***************************************************************************
*
*  $MCI Módulo de definição: Módulo Critério de avaliação
*
*  Arquivo gerado:              criterio_de_aprovacao.C
*  Letras identificadoras:      CRI
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acadêmico da turma 3WB
*  Gestor:  Grupo 4
*  Autores: SaintL - Leonardo Abreu Santos
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data        Observações
*       0.01		   28/09/2017  
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "criterio_de_aprovação.h"

/***************************************************************************
*
*  Função: CRI criterio 1
*  ****/
CRI_tpCondRet CRI_criterio1(float G1, float G2, float G3, float* media, int* situacao)
{
	float NF;

	NF = (G1 + G2)/2;
	*media = NF;

	if (G1 >= 3.0 && G2 >= 3.0 && NF >= 6.0)
	{
		*situacao = 1; /* Aprovado */
		CRI_CondRetOK;
	}
	else
	{
		NF = (G1 + G2 + (G3*2))/4;
		*media = NF;

		if (NF >= 5.0)
		{
			*situacao = 1; /* Aprovado */
			CRI_CondRetOK;
		}
		else
		{
			*situacao = 0; /* Reprovado */
			CRI_CondRetOK;
		}
	}

	CRI_CondRetErroEstrutura;
}
/* Fim função: CRI criterio 1 */
/***************************************************************************
*
*  Função: CRI criterio 2
*  ****/
CRI_tpCondRet CRI_criterio2(float G1, float G2, float G3, float G4, float* media, int* situacao)
{
	float NF, Gm, Gn, temp;

	NF = (G1 + G2 + G3)/3;

	if (( G1 >= 5.0 && G2 >= 5.0 && G3 >=5.0 ) || NF >= 6.0)
	{
		*media = NF;
		*situacao = 1; /* Aprovado */
		CRI_CondRetOK;
	}
	else
	{
		if (G4 < 3.0)
		{
			NF = (G1 + G2 + G3 + (G4 * 3))/6;
			*media = NF;

			if (NF >= 5.0)
			{
				*situacao = 1; /* Aprovado */
				CRI_CondRetOK;
			}
			else
			{
				*situacao = 0; /* Reprovado */
				CRI_CondRetOK;
			}
		}
		else
		{
			if (G2 > G1)        /* Essa sequência de if ordena as notas de forma decrescente */
			{					/* Para o calculo da média */
				temp = G2;		/* Que utiliza as duas maiores notas e a G4 */
				G2 = G1;
				G1 = temp;
			}
				if (G3 > G2)
			{
				temp = G3;
				G3 = G2;
				G2 = temp;
			}	
			if (G2 > G1)
			{
				temp = G2;
				G2 = G1;
				G1 = temp;
			}

			Gm = G1; /* Gm = Maior nota */
			Gn = G2; /* Gn = Segunda maior nota */

			NF = (Gm + Gn + G4)/3;
			*media = NF;

			if (NF >= 5.0)
			{
				*situacao = 1; /* Aprovado */
				CRI_CondRetOK;
			}
			else
			{
				*situacao = 0; /* Reprovado */
				CRI_CondRetOK;
			}
		}
	}

	CRI_CondRetErroEstrutura;

}
/* Fim função: CRI criterio 2 */
