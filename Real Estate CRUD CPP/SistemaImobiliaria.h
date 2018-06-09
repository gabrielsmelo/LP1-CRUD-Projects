#if !defined(SI_H)
#define SI_H
#include "Endereco.h"
#include "Apartamento.h"
#include "Casa.h"
#include "Endereco.h"
#include "Flat.h"
#include "GerenteDePersistencia.h"
#include "Imovel.h"
#include "Studio.h"
#include "Terreno.h"
#include "list"

class SistemaImobiliaria{
    public:
        SistemaImobiliaria();
        GerenteDePersistencia gp;
        void cadastraImovel();
        void getImoveis();
        void getDescricaoImoveis();
        void getImoveisParaAlugarPorBairro(std::string);
        void getImoveisParaVenderPorBairro(std::string);
        void getImoveisPorCidade(std::string);
        void getImoveisDisponiveis();
        void atualizaImovel();
        void deletaImovel(int);
        Imovel *imoveis[100];
};


#endif // SI_H
