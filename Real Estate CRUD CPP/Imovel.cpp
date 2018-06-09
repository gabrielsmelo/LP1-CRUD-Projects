#include "Imovel.h"

Imovel::Imovel()
{
    //ctor
}

Imovel::~Imovel()
{
    //dtor
}

double Imovel::getValor(){
    return valor;
}

double Imovel::getValorAluguel(){
    return valorAluguel;
}

int Imovel::getTipoOferta(){
    return tipoOferta;
}

/*
std::string Imovel::getDescricao(){
    return desc;
}
*/

Endereco Imovel::getEndereco(){
    return endereco;
}

int Imovel::getTipoImovel(){
    return tipoImovel;
}

void Imovel::setValor(double v){
    valor = v;
}

void Imovel::setValorAluguel(double v){
    valorAluguel = v;
}

void Imovel::setTipoOferta(int t){
    tipoOferta = t;
}


// void Imovel::setDescricao(std::string d){
//     desc = d;
// }


void Imovel::setEndereco(Endereco e){
    endereco = e;
}

void Imovel::setTipoImovel(int t){
    tipoImovel = t;
}
