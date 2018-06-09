#ifndef CASA_H
#define CASA_H
#include "Imovel.h"


class Casa : public Imovel{
    public:
        Casa();
        Casa(int, int, double, double);
        virtual ~Casa();
        int getPavimentos();
        int getQuartos();
        double getAreaTerreno();
        double getAreaConstruida();
        std::string getDescricao();
        void setPavimentos(int);
        void setQuartos(int);
        void setAreaTerreno(double);
        void setAreaConstruida(double);
        void setValor(double);
        void setDescricao(std::string);
        void createDesc();
    protected:
        int pavimentos, quartos;
        double areaTerreno, areaConstruida;

    private:
};

#endif // CASA_H
