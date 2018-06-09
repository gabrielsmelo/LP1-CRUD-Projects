#include "Endereco.h"

Endereco::Endereco()
{
    //ctor
}

Endereco::Endereco(std::string logradouro, std::string estado,int numero, std::string bairro, std::string cidade, std::string cep)
{
    this->estado = estado;
    this->logradouro = logradouro;
    this->numero = numero;
    this->bairro = bairro;
    this->cidade = cidade;
    this->cep = cep;
}

Endereco::~Endereco()
{
    //dtor
}

void Endereco::setLogradouro(std::string logradouro){
    this->logradouro = logradouro;
}
void Endereco::setEstado(std::string estado){
    this->estado = estado;
}
void Endereco::setNumero(int numero){
    this->numero = numero;std::string getEstado();
}
void Endereco::setBairro(std::string bairro){
    this->bairro = bairro;
}
void Endereco::setCidade(std::string cidade){
    this->cidade = cidade;
}
void Endereco::setCep(std::string cep){
    this->cep = cep;
}
std::string Endereco::getLogradouro(){
    return logradouro;
}
std::string Endereco::getEstado(){
    return estado;
}
int Endereco::getNumero(){
    return numero;
}
std::string Endereco::getBairro(){
    return bairro;
}
std::string Endereco::getCidade(){
    return cidade;
}
std::string Endereco::getCep(){
    return cep;
}