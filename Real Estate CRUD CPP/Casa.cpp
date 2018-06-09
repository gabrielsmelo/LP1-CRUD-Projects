#include "Casa.h"

Casa::Casa()
{
    flag = 1;
    //ctor
}

Casa::Casa(int pavimentos, int quartos, double areaTerreno, double areaConstruida){
    this->pavimentos = pavimentos;
    this->quartos = quartos;
    this->areaTerreno = areaTerreno;
    this->areaConstruida = areaConstruida;
}

Casa::~Casa()
{
    //dtor
}

int Casa::getPavimentos(){
    return pavimentos;
}

int Casa::getQuartos(){
    return quartos;
}

double Casa::getAreaConstruida(){
    return areaConstruida;
}

double Casa::getAreaTerreno(){
    return areaTerreno;
}

std::string Casa::getDescricao(){
    return desc;
}

void Casa::setValor(double v){
    valor = v;
}

void Casa::setPavimentos(int p){
    pavimentos = p;
}

void Casa::setQuartos(int q){
    quartos = q;
}

void Casa::setAreaConstruida(double ac){
    areaConstruida = ac;
}

void Casa::setAreaTerreno(double atr){
    areaTerreno = atr;
}

void Casa::setDescricao(std::string d){
    this->desc = d;
}

void Casa::createDesc(){
    if(tipoOferta == 1){
        desc = "Logradouro: " + endereco.getLogradouro() + "\nNumero: " + std::to_string(endereco.getNumero()) +
        "\nBairro: " + endereco.getBairro() + "\nEstado: " + endereco.getEstado() + "\nCidade: " + endereco.getCidade() +
        "\nCEP: " + endereco.getCep() + "\nPavimentos: " + std::to_string(getPavimentos()) + "\nNumero de Quartos: " + std::to_string(getQuartos()) +
        "\nArea de terreno: " + std::to_string(getAreaTerreno()) + "\nArea construida: " + std::to_string(getAreaConstruida()) + "\nValor do Aluguel: R$ " + std::to_string(getValorAluguel());
    }else if(tipoOferta == 2){
        desc = "Logradouro: " + endereco.getLogradouro() + "\nNumero: " + std::to_string(endereco.getNumero()) +
        "\nBairro: " + endereco.getBairro() + "\nEstado: " + endereco.getEstado() + "\nCidade: " + endereco.getCidade() +
        "\nCEP: " + endereco.getCep() + "\nPavimentos: " + std::to_string(getPavimentos()) + "\nNumero de Quartos: " + std::to_string(getQuartos()) +
        "\nArea de terreno: " + std::to_string(getAreaTerreno()) + "\nArea construida: " + std::to_string(getAreaConstruida()) + "\nValor: R$ " + std::to_string(getValor());
    }else if(tipoOferta == 3){
        desc = "Logradouro: " + endereco.getLogradouro() + "\nNumero: " + std::to_string(endereco.getNumero()) +
        "\nBairro: " + endereco.getBairro() + "\nEstado: " + endereco.getEstado() + "\nCidade: " + endereco.getCidade() +
        "\nCEP: " + endereco.getCep() + "\nPavimentos: " + std::to_string(getPavimentos()) + "\nNumero de Quartos: " + std::to_string(getQuartos()) +
        "\nArea de terreno: " + std::to_string(getAreaTerreno()) + "\nArea construida: " + std::to_string(getAreaConstruida()) + "\nValor: R$ " +
        std::to_string(getValor()) + "\nValor do Aluguel: R$ " + std::to_string(getValorAluguel());
    }
}