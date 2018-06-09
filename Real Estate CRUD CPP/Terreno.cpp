#include "Terreno.h"

Terreno::Terreno()
{
    flag = 3;
    //ctor
}

Terreno::Terreno(double area){
    this->area = area;
}

Terreno::~Terreno()
{
    //dtor
}

double Terreno::getArea(){
    return area;
}

std::string Terreno::getDescricao(){
    return desc;
}

void Terreno::setArea(double a){
    area = a;
}

void Terreno::setValor(double v){
    valor = v;
}

void Terreno::setDescricao(std::string d){
    this->desc = d;
}

void Terreno::createDesc(){
    if(tipoOferta == 1){
        desc = "Logradouro: " + endereco.getLogradouro() + "\nNumero: " + std::to_string(endereco.getNumero()) +
        "\nBairro: " + endereco.getBairro() + "\nEstado: " + endereco.getEstado() + "\nCidade: " + endereco.getCidade() +
        "\nCEP: " + endereco.getCep() + "\nArea: " + std::to_string(getArea()) + "\nValor do aluguel: R$ " + std::to_string(getValorAluguel());
    }else if(tipoOferta == 2){
        desc = "Logradouro: " + endereco.getLogradouro() + "\nNumero: " + std::to_string(endereco.getNumero()) +
        "\nBairro: " + endereco.getBairro() + "\nEstado: " + endereco.getEstado() + "\nCidade: " + endereco.getCidade() +
        "\nCEP: " + endereco.getCep() + "\nArea: " + std::to_string(getArea()) + "\nValor: R$ " + std::to_string(getValor());
    }else if(tipoOferta == 3){
        desc = "Logradouro: " + endereco.getLogradouro() + "\nNumero: " + std::to_string(endereco.getNumero()) +
        "\nBairro: " + endereco.getBairro() + "\nEstado: " + endereco.getEstado() + "\nCidade: " + endereco.getCidade() +
        "\nCEP: " + endereco.getCep() + "\nArea: " + std::to_string(getArea()) + "\nValor: R$ " + std::to_string(getValor()) + "\nValor do Aluguel: R$ " +std::to_string(getValorAluguel());
    }
}