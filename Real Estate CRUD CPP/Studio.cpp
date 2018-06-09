#include "Studio.h"

Studio::Studio()
{
    flag = 5;
    //ctor
}

Studio::Studio(double area, double valorCondominio, int arCondicionado, int internet, int tv, int lavanderia, int limpeza, int recepcao, int piscina, int sauna, int ginastica){
    this->area = area;
    this->valorCondominio = valorCondominio;
    this->arCondicionado = arCondicionado;
    this->internet = internet;
    this->tv = tv;
    this->lavanderia = lavanderia;
    this->limpeza = limpeza;
    this->recepcao = recepcao;
    this->piscina = piscina;
    this->sauna = sauna;
    this->ginastica = ginastica;
}

Studio::~Studio()
{
    //dtor
}

void Studio::setValor(double v){
    valor = v;
}

std::string Studio::getDescricao(){
    return desc;
}

void Studio::setDescricao(std::string d){
    this->desc = d;
}

void Studio::createDesc(){
    if(tipoOferta == 1){
        desc = "Logradouro: " + endereco.getLogradouro() + "\nNumero: " + std::to_string(endereco.getNumero()) +
        "\nBairro: " + endereco.getBairro() + "\nEstado: " + endereco.getEstado() + "\nCidade: " + endereco.getCidade() +
        "\nCEP: " + endereco.getCep() + "\nAr condicionado: " + (getArCondicionado() ? "Sim" : "Nao")  + "\nInternet: " + (getInternet() ? "Sim" : "Nao") +
        "\nTV: " + (getTv() ? "Sim" : "Nao") + "\nLavanderia: " + (getLavanderia() ? "Sim" : "Nao") + "\nLimpeza: " + (getLimpeza() ? "Sim" : "Nao") + "\nRecepcao: " +
        (getRecepcao() ? "Sim" : "Nao") + "\nPiscina: " + (getPiscina() ? "Sim" : "Nao") + "\nSauna: " + (getSauna() ? "Sim" : "Nao") + "\nGinastica: " + (getGinastica() ? "Sim" : "Nao") +
        "\nValor do Aluguel: R$ " + std::to_string(getValorAluguel()) + "\nValor do condominio: R$ " + std::to_string(getValorCondominio()) +
        "\nArea: " + std::to_string(getArea());
    }else if(tipoOferta == 2){
        desc = "Logradouro: " + endereco.getLogradouro() + "\nNumero: " + std::to_string(endereco.getNumero()) +
        "\nBairro: " + endereco.getBairro() + "\nEstado: " + endereco.getEstado() + "\nCidade: " + endereco.getCidade() +
        "\nCEP: " + endereco.getCep() + "\nAr condicionado: " + (getArCondicionado() ? "Sim" : "Nao")  + "\nInternet: " + (getInternet() ? "Sim" : "Nao") +
        "\nTV: " + (getTv() ? "Sim" : "Nao") + "\nLavanderia: " + (getLavanderia() ? "Sim" : "Nao") + "\nLimpeza: " + (getLimpeza() ? "Sim" : "Nao") + "\nRecepcao: " +
        (getRecepcao() ? "Sim" : "Nao") + "\nPiscina: " + (getPiscina() ? "Sim" : "Nao") + "\nSauna: " + (getSauna() ? "Sim" : "Nao") + "\nGinastica: " + (getGinastica() ? "Sim" : "Nao") +
        "\nValor: R$ " + std::to_string(getValor()) + "\nValor do condominio: R$ " + std::to_string(getValorCondominio()) +
        "\nArea: " + std::to_string(getArea());
    }else if(tipoOferta == 3){
        desc = "Logradouro: " + endereco.getLogradouro() + "\nNumero: " + std::to_string(endereco.getNumero()) +
        "\nBairro: " + endereco.getBairro() + "\nEstado: " + endereco.getEstado() + "\nCidade: " + endereco.getCidade() +
        "\nCEP: " + endereco.getCep() + "\nAr condicionado: " + (getArCondicionado() ? "Sim" : "Nao")  + "\nInternet: " + (getInternet() ? "Sim" : "Nao") +
        "\nTV: " + (getTv() ? "Sim" : "Nao") + "\nLavanderia: " + (getLavanderia() ? "Sim" : "Nao") + "\nLimpeza: " + (getLimpeza() ? "Sim" : "Nao") + "\nRecepcao: " +
        (getRecepcao() ? "Sim" : "Nao") + "\nPiscina: " + (getPiscina() ? "Sim" : "Nao") + "\nSauna: " + (getSauna() ? "Sim" : "Nao") + "\nGinastica: " + (getGinastica() ? "Sim" : "Nao") +
        "\nValor: R$ " + std::to_string(getValor()) + "\nValor do Aluguel: R$ " + std::to_string(getValorAluguel()) + "\nValor do condominio: R$ " + std::to_string(getValorCondominio()) +
        "\nArea: " + std::to_string(getArea());
    }
}