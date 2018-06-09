#ifndef CONSULTA_H_INCLUDED
#define CONSULTA_H_INCLUDED
#include "timovel.h"

void Consulta(tImovel *imoveis);

void DescricaoUmImovel(tImovel imovel);

void Descricao(tImovel *imoveis);

void AVendaPorTipo(tImovel *imoveis);

void AlugarPorBairro(tImovel *imoveis);

void VenderPorBairro(tImovel *imoveis);

void DisponivelPorCidade(tImovel *imoveis);

int Identificador(tImovel *imoveis);

void DisponivelTipo(tImovel *imoveis);
#endif //CONSULTA_H_INCLUDED

