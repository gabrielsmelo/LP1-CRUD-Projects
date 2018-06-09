#ifndef IMOVEL_H
#define IMOVEL_H
#include "Endereco.h"
#include <string>


class Imovel
{
    public:
        Imovel();
        virtual ~Imovel();
        double getValor();
        double getValorAluguel();
        int getTipoOferta();
        int getTipoImovel();
        Endereco getEndereco();
        virtual std::string getDescricao() = 0;
        void setValor(double);
        void setValorAluguel(double);
        void setTipoOferta(int);
        void setEndereco(Endereco);
        void setTipoImovel(int);
        virtual void setDescricao(std::string) = 0;
        virtual void createDesc() = 0;
        int flag = 0;
    protected:
        Endereco endereco;
        double valor, valorAluguel;
        int tipoImovel;
        int tipoOferta = 0; // aluguel 1, venda 2 ou ambos 3
        std::string desc;
    private:
};

#endif // IMOVEL_H
