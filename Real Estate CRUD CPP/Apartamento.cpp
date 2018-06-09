#include "Apartamento.h"
#include <string>

Apartamento::Apartamento()
{
    flag = 2;
    //ctor
}

Apartamento::Apartamento(std::string posicao, int numQuartos, int vagasGaragem, double valorCondominio, double area){
    this->posicao = posicao;
    this->numQuartos = numQuartos;
    this->vagasGaragem = vagasGaragem;
    this->valorCondominio = valorCondominio;
    this->area = area;
}

Apartamento::~Apartamento()
{
    //dtor
}

std::string Apartamento::getPosicao(){
    return posicao;
}

int Apartamento::getNumQuartos(){
    return numQuartos;
}

int Apartamento::getVagasGaragem(){
    return vagasGaragem;
}

double Apartamento::getValorCondominio(){
    return valorCondominio;
}

double Apartamento::getArea(){
    return area;
}

std::string Apartamento::getDescricao(){
    return desc;
}

void Apartamento::setPosicao(std::string p){
    posicao = p;
}

void Apartamento::setArea(double a){
    area = a;
}

void Apartamento::setVagasGaragem(int v){
    vagasGaragem = v;
}

void Apartamento::setNumQuartos(int n){
    numQuartos = n;
}

void Apartamento::setValorCondominio(double val){
    valorCondominio = val;
}

void Apartamento::setValor(double value){
    valor = value;
}

void Apartamento::setDescricao(std::string d){
    this->desc = d;
}

void Apartamento::createDesc(){
    if(tipoOferta == 1){
        desc = "Logradouro: " + endereco.getLogradouro() + "\nNumero: " + std::to_string(endereco.getNumero()) +
        "\nBairro: " + endereco.getBairro() + "\nEstado: " + endereco.getEstado() + "\nCidade: " + endereco.getCidade() +
        "\nCEP: " + endereco.getCep() + "\nPosicao: " + getPosicao() + "\nNumero de Quartos: " + std::to_string(getNumQuartos()) +
        "\nVagas de Garagem: " + std::to_string(getVagasGaragem()) + "\nValor do Condominio: R$" + std::to_string(getValorCondominio()) + "\nArea: " +
        std::to_string(getArea()) + "\nValor do Aluguel: R$ " + std::to_string(getValorAluguel());
    }else if(tipoOferta == 2){
        desc = "Logradouro: " + endereco.getLogradouro() + "\nNumero: " + std::to_string(endereco.getNumero()) +
        "\nBairro: " + endereco.getBairro() + "Estado: " + endereco.getEstado() + "\nCidade: " + endereco.getCidade() +
        "\nCEP: " + endereco.getCep() + "\nPosicao: " + getPosicao() + "\nNumero de Quartos: " + std::to_string(getNumQuartos()) +
        "\nVagas de Garagem: " + std::to_string(getVagasGaragem()) + "\nValor do Condominio: R$ " + std::to_string(getValorCondominio()) + "\nArea: " +
        std::to_string(getArea()) + "\nValor: R$ " + std::to_string(getValor());
    }else if(tipoOferta == 3){
        desc = "Logradouro: " + endereco.getLogradouro() + "\nNumero: " + std::to_string(endereco.getNumero()) +
        "\nBairro: " + endereco.getBairro() + "Estado: " + endereco.getEstado() + "\nCidade: " + endereco.getCidade() +
        "\nCEP: " + endereco.getCep() + "\nPosicao: " + getPosicao() + "\nNumero de Quartos: " + std::to_string(getNumQuartos()) +
        "\nVagas de Garagem: " + std::to_string(getVagasGaragem()) + "\nValor do Condominio: R$ " + std::to_string(getValorCondominio()) + "\nArea: " +
        std::to_string(getArea()) + "\nValor: R$ " + std::to_string(getValor()) + "\nValor do Aluguel: R$ " + std::to_string(getValorAluguel());
    }
}