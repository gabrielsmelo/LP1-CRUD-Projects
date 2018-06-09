#ifndef CADASTRO_H_INCLUDED
#define CADASTRO_H_INCLUDED
#include "timovel.h"

void Cadastra(tImovel *imoveis, int index, int flag);
int ProcuraIndex(tImovel *imoveis);
void Deleta(tImovel *imoveis);
void Update(tImovel *imoveis);

#endif // CADASTRO_H_INCLUDED
