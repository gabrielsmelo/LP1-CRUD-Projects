#ifndef GP_H
#define GP_H
#include "Imovel.h"
#include <fstream>

class GerenteDePersistencia{
    public:
        GerenteDePersistencia();
        std::fstream arq;
        void salvaListaImoveis(Imovel** im);
        void recuperaListaImoveis(Imovel **imoveis);
        int ProcuraIndex(Imovel **imoveis);
};



#endif //GP_H
