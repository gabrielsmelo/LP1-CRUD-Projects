#ifndef STUDIO_H

#define STUDIO_H

#include "Imovel.h"





class Studio : public Imovel {

    public:

        Studio();

        Studio(double, double, int, int, int, int, int, int, int, int, int);

        virtual ~Studio();

        void setValor(double);

        double getArea() { return area; }

        void setArea(double val) { area = val; }

        double getValorCondominio() { return valorCondominio; }

        void setValorCondominio(double val) { valorCondominio = val; }

        int getArCondicionado() { return arCondicionado; }

        void setArCondicionado(int val) { arCondicionado = val; }

        int getInternet() { return internet; }

        void setInternet(int val) { internet = val; }

        int getTv() { return tv; }

        void setTv(int val) { tv = val; }

        int getLavanderia() { return lavanderia; }

        void setLavanderia(int val) { lavanderia = val; }

        int getLimpeza() { return limpeza; }

        void setLimpeza(int val) { limpeza = val; }

        int getRecepcao() { return recepcao; }

        void setRecepcao(int val) { recepcao = val; }

        int getPiscina() { return piscina; }

        void setPiscina(int val) { piscina = val; }

        int getSauna() { return sauna; }

        void setSauna(int val) { sauna = val; }

        int getGinastica() { return ginastica; }

        void setGinastica(int val) { ginastica = val; }

        std::string getDescricao();

        void setDescricao(std::string);

        void createDesc();

    protected:

        double area;

        double valorCondominio;

        int arCondicionado;

        int internet;

        int tv;

        int lavanderia;

        int limpeza;

        int recepcao;

        int piscina;

        int sauna;

        int ginastica;



    private:

};



#endif // STUDIO_H

