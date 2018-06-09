#ifndef FLAT_H
#define FLAT_H
#include "Imovel.h"

class Flat : public Imovel{
    public:
        Flat();
        Flat(double, double, int, int, int, int, int, int);
        virtual ~Flat();
        double getArea();
        double getValorCondominio();
        int getArCondicionado();
        int getInternet();
        int getTv();
        int getLavanderia();
        int getLimpeza();
        int getRecepcao();
        std::string getDescricao();
        void setArea(double);
        void setValorCondominio(double);
        void setArCondicionado(int);
        void setInternet(int);
        void setTv(int);
        void setLavanderia(int);
        void setRecepcao(int);
        void setValor(double);
        void setDescricao(std::string);
        void createDesc();
    protected:
        double area, valorCondominio;
        int arCondicionado, internet, tv, lavanderia, limpeza, recepcao;
    private:
};

#endif // FLAT_H
