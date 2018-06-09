#include "Flat.h"

Flat::Flat()
{
    flag = 4;
    //ctor
}

Flat::Flat(double area, double valorCondominio, int arCondicionado, int internet, int tv, int lavanderia, int limpeza, int recepcao){
    this->area = area;
    this->valorCondominio = valorCondominio;
    this->arCondicionado = arCondicionado;
    this->internet = internet;
    this->tv = tv;
    this->lavanderia = lavanderia;
    this->limpeza = limpeza;
    this->recepcao = recepcao;
}

Flat::~Flat()
{
    //dtor
}

double Flat::getArea(){
    return area;
}

double Flat::getValorCondominio(){
    return valorCondominio;
}

void Flat::setValor(double v){
    valor = v;
}

int Flat::getArCondicionado(){
    return arCondicionado;
}

int Flat::getInternet(){
    return internet;
}

int Flat::getTv(){
    return tv;
}

int Flat::getLavanderia(){
    return lavanderia;
}

int Flat::getLimpeza(){
    return limpeza;
}

int Flat::getRecepcao(){
    return recepcao;
}
std::string Flat::getDescricao(){
    return desc;
}

void Flat::setArea(double a){
    area = a;
}

void Flat::setValorCondominio(double val){
    valorCondominio = val;
}

void Flat::setArCondicionado(int ar){
    arCondicionado = ar;
}

void Flat::setInternet(int net){
    internet = net;
}

void Flat::setTv(int tv){
    this->tv = tv;
}

void Flat::setLavanderia(int lav){
    lavanderia = lav;
}

void Flat::setRecepcao(int rec){
    recepcao = rec;
}

void Flat::setDescricao(std::string d){
    this->desc = d;
}

void Flat::createDesc(){
    if(tipoOferta == 1){
        desc = "Logradouro: " + endereco.getLogradouro() + "\nNumero: " + std::to_string(endereco.getNumero()) +
        "\nBairro: " + endereco.getBairro() + "\nEstado: " + endereco.getEstado() + "\nCidade: " + endereco.getCidade() +
        "\nCEP: " + endereco.getCep() + "\nAr condicionado: " + (getArCondicionado() ? "Sim" : "Nao")  + "\nInternet: " + (getInternet() ? "Sim" : "Nao") +
        "\nTV: " + (getTv() ? "Sim" : "Nao") + "\nLavanderia: " + (getLavanderia() ? "Sim" : "Nao") + "\nLimpeza: " + (getLimpeza() ? "Sim" : "Nao") + "\nRecepcao: " +
        (getRecepcao() ? "Sim" : "Nao") + "\nValor do Aluguel: R$ " + std::to_string(getValorAluguel()) + "\nValor do condominio: R$ " + std::to_string(getValorCondominio()) +
        "\nArea: " + std::to_string(getArea());
    }else if(tipoOferta == 2){
        desc = "Logradouro: " + endereco.getLogradouro() + "\nNumero: " + std::to_string(endereco.getNumero()) +
        "\nBairro: " + endereco.getBairro() + "Estado: " + endereco.getEstado() + "\nCidade: " + endereco.getCidade() +
        "\nCEP: " + endereco.getCep() + "\nAr condicionado: " + (getArCondicionado() ? "Sim" : "Nao")  + "\nInternet: " + (getInternet() ? "Sim" : "Nao") +
        "\nTV: " + (getTv() ? "Sim" : "Nao") + "\nLavanderia: " + (getLavanderia() ? "Sim" : "Nao") + "\nLimpeza: " + (getLimpeza() ? "Sim" : "Nao") + "\nRecepcao: " +
        (getRecepcao() ? "Sim" : "Nao") + "\nValor: R$ " + std::to_string(getValor()) + "\nValor do condominio: R$ " + std::to_string(getValorCondominio()) +
        "\nArea: " + std::to_string(getArea());
    }else if(tipoOferta == 3){
        desc = "Logradouro: " + endereco.getLogradouro() + "\nNumero: " + std::to_string(endereco.getNumero()) +
        "\nBairro: " + endereco.getBairro() + "Estado: " + endereco.getEstado() + "\nCidade: " + endereco.getCidade() +
        "\nCEP: " + endereco.getCep() + "\nAr condicionado: " + (getArCondicionado() ? "Sim" : "Nao")  + "\nInternet: " + (getInternet() ? "Sim" : "Nao") +
        "\nTV: " + (getTv() ? "Sim" : "Nao") + "\nLavanderia: " + (getLavanderia() ? "Sim" : "Nao") + "\nLimpeza: " + (getLimpeza() ? "Sim" : "Nao") + "\nRecepcao: " +
        (getRecepcao() ? "Sim" : "Nao") + "\nValor: R$ " + std::to_string(getValor()) + "\nValor do Aluguel: R$ " + std::to_string(getValorAluguel()) + "\nValor do condominio: R$ " + std::to_string(getValorCondominio()) +
        "\nArea: " + std::to_string(getArea());
    }
}