#ifndef ENDERECO_H
#define ENDERECO_H
#include <string>


class Endereco
{
    public:
        Endereco();
        Endereco(std::string, std::string,int, std::string, std::string, std::string);
        virtual ~Endereco();
        void setLogradouro(std::string logradouro);
        void setNumero(int numero);
        void setBairro(std::string bairro);
        void setEstado(std::string estado);
        void setCidade(std::string cidade);
        void setCep(std::string cep);
        std::string getLogradouro();
        std::string getEstado();
        int getNumero();
        std::string getBairro();
        std::string getCidade();
        std::string getCep();

    protected:

    private:
        std::string logradouro;
        int numero;
        std::string estado;
        std::string bairro;
        std::string cidade;
        std::string cep;
};

#endif // ENDERECO_H
