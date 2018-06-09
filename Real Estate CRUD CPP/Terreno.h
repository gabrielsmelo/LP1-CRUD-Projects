#ifndef TERRENO_H
#define TERRENO_H
#include "Imovel.h"


class Terreno : public Imovel{
    public:
        Terreno();
        Terreno(double);
        virtual ~Terreno();
        double getArea();
        std::string getDescricao();
        void setArea(double);
        void setValor(double);
        void setDescricao(std::string);
        void createDesc();
    protected:
        double area;
    private:
};

#endif // TERRENO_H
