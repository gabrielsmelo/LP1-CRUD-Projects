#ifndef APARTAMENTO_H
#define APARTAMENTO_H
#include <string>
#include "Imovel.h"


class Apartamento : public Imovel
{
    public:
        Apartamento();
        Apartamento(std::string, int, int, double, double);
        virtual ~Apartamento();
        std::string getPosicao();
        std::string getDescricao();
        int getNumQuartos();
        int getVagasGaragem();
        double getValorCondominio();
        double getArea();
        void setPosicao(std::string);
        void setNumQuartos(int);
        void setVagasGaragem(int);
        void setValorCondominio(double);
        void setArea(double);
        void setValor(double);
        void setDescricao(std::string);
        void createDesc();
    protected:
        std::string posicao;
        int numQuartos, vagasGaragem;
        double valorCondominio, area;
    private:
};

#endif // APARTAMENTO_H
