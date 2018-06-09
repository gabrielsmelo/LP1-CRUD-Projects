#include "SistemaImobiliaria.h"
#include "GerenteDePersistencia.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;
bool first = false;
SistemaImobiliaria::SistemaImobiliaria(){
    for(int i = 0; i < 100; i++){
        imoveis[i] = new Casa();
    }
    gp = GerenteDePersistencia();
}

void SistemaImobiliaria::cadastraImovel(){
    int index, tipo = 0, disp = 0, int1, int2, int3, int4, int5, int6, int7, int8, int9;
    double aux1, db1, db2, db3, db4;
    string aux2, str1, str2, str3, str4, str5;
    int entrada;
    
    if(!first){
        cout << "Primeiro Acesso, deseja recuperar da memória?\n" << std::endl;
        cout << "1- Sim | 0- Não" << std::endl;
        cin >> entrada;
        if(entrada){
            cout << "Recuperando da memória" << std::endl;
            gp.recuperaListaImoveis(imoveis);
            getchar();
        }else cout << "Começando sistema do zero" << std::endl;
        first = !first;
    }

    system("clear");


    index = gp.ProcuraIndex(imoveis);
    cout << ">> Qual tipo de imovel deseja cadastrar?" << endl;
    cout << "1-> Casa" << endl;
    cout << "2-> Apartamento" << endl;
    cout << "3-> Terreno" << endl;
    cout << "4-> Flat" << endl;
    cout << "5-> Studio" << endl;
    cout << "Digite a opcao desejada: ";
    cin >> tipo;
    while(tipo <= 0 || tipo > 5){
        cout << "Opcao invalida!" << endl;
        cout << "Digite a opcao desejada: ";
        cin >> tipo;
    }
    system("clear");
    if(tipo == 1){
        cout << "\t\tCadastrando uma CASA" << endl << endl;
        cout << "Numero de Pavimentos: ";
        cin >> int1;
        cout << "Numero de Quartos: ";
        cin >> int2;
        cout << "Area do Terreno: ";
        cin >> db1;
        cout << "Area Construida: ";
        cin >> db2;
        imoveis[index] = new Casa(int1, int2, db1, db2);
        imoveis[index]->setTipoImovel(tipo);
    }else if(tipo == 2){
        cout << "\t\tCadastrando um APARTAMENTO" << endl << endl;
        cout << "Numero de Quartos: ";
        cin >> int1;
        cout << "Numero de Vagas na Garagem: ";
        cin >> int2;
        cout << "Valor do Condominio: ";
        cin >> db1;
        cout << "Area do Apartamento: ";
        cin >> db2;
        cout << "Posicao (Ex.: Nascente Sul): ";
        cin >> str1;
        imoveis[index] = new Apartamento(str1, int1, int2, db1, db2);
        imoveis[index]->setTipoImovel(tipo);
    }else if(tipo == 3){
        cout << "\t\tCadastrando um TERRENO" << endl << endl;
        cout << "Area do Terreno: ";
        cin >> db1;
        imoveis[index] = new Terreno(db1);
        imoveis[index]->setTipoImovel(tipo);
    }else if(tipo == 4){
        cout << "\t\tCadastrando um FLAT" << endl << endl;
        cout << "Area do Flat: ";
        cin >> db1;
        cout << "Valor do Condominio: R$ ";
        cin >> db2;
        cout << "Tem Ar-Condicionado(1-> Sim / 0-> Nao)? ";
        cin >> int1;
        cout << "Tem Internet(1-> Sim / 0-> Nao)? ";
        cin >> int2;
        cout << "Tem TV(1-> Sim / 0-> Nao)? ";
        cin >> int3;
        cout << "Tem Lavanderia(1-> Sim / 0-> Nao)? ";
        cin >> int4;
        cout << "Tem Limpeza(1-> Sim / 0-> Nao)? ";
        cin >> int5;
        cout << "Tem Recepcao(1-> Sim / 0-> Nao)? ";
        cin >> int6;
        imoveis[index] = new Flat(db1, db2, int1, int2, int3, int4, int5, int6);
        imoveis[index]->setTipoImovel(tipo);
    }else if(tipo == 5){
        cout << "\t\tCadastrando um STUDIO" << endl << endl;
        cout << "Area do Studio: ";
        cin >> db1;
        cout << "Valor do Condominio: R$ ";
        cin >> db2;
        cout << "Tem Ar-Condicionado(1-> Sim / 0-> Nao)? ";
        cin >> int1;
        cout << "Tem Internet(1-> Sim / 0-> Nao)? ";
        cin >> int2;
        cout << "Tem TV(1-> Sim / 0-> Nao)? ";
        cin >> int3;
        cout << "Tem Lavanderia(1-> Sim / 0-> Nao)? ";
        cin >> int4;
        cout << "Tem Limpeza(1-> Sim / 0-> Nao)? ";
        cin >> int5;
        cout << "Tem Recepcao(1-> Sim / 0-> Nao)? ";
        cin >> int6;
        cout << "Tem Piscina(1-> Sim / 0-> Nao)? ";
        cin >> int7;
        cout << "Tem Sauna(1-> Sim / 0-> Nao)? ";
        cin >> int8;
        cout << "Tem Ginastica(1-> Sim / 0-> Nao)? ";
        cin >> int9;
        imoveis[index] = new Studio(db1, db2, int1, int2, int3, int4, int5, int6, int7, int8, int9);
        imoveis[index]->setTipoImovel(tipo);
    }
    getchar();
    cout << "Rua: ";
    getline(cin, aux2);
    Endereco temp;
    temp.setLogradouro(aux2);
    
    cout << "Numero: ";
    cin >> aux1;
    getchar();
    temp.setNumero(aux1);
    
    cout << "Bairro: ";
    getline(cin, aux2);
    temp.setBairro(aux2);

    cout << "Cidade: ";
    getline(cin, aux2);
    temp.setCidade(aux2);

    cout << "Estado: ";
    getline(cin, aux2);
    temp.setEstado(aux2);

    cout << "CEP: ";
    getline(cin, aux2);
    temp.setCep(aux2);

    imoveis[index]->setEndereco(temp);
    cout << endl << "Disponibilidade: " << endl;
    cout << "1-> Aluguel" << endl;
    cout << "2-> A Venda" << endl;
    cout << "3-> Venda ou Aluguel" << endl;
    cout << "Digite a opcao desejada: ";
    cin >> disp;
    while(disp <= 0 || disp > 3){
        cout << "Opcao invalida!" << endl;
        cout << "Digite a opcao desejada: ";
        cin >> disp;
    }
    imoveis[index]->setTipoOferta(disp);
    if(imoveis[index]->getTipoOferta() == 2){
        cout << "Digite o valor do imovel: ";
        cin >> aux1;
        imoveis[index]->setValor(aux1);
    }else if(imoveis[index]->getTipoOferta() == 1){
        cout << "Digite o valor do aluguel: ";
        cin >> aux1;
        imoveis[index]->setValorAluguel(aux1);
    }else if(imoveis[index]->getTipoOferta() == 3){
        cout << "Digite o valor do imovel: ";
        cin >> aux1;
        imoveis[index]->setValor(aux1);
        cout << "Digite o valor do aluguel: ";
        cin >> aux1;
        imoveis[index]->setValorAluguel(aux1);
    }
    imoveis[index]->createDesc();
    system("clear");
    cout << ">> IMOVEL CADASTRADO COM SUCESSO!!" << endl << endl;
    cout << setprecision (5)  << fixed << imoveis[index]->getDescricao();
    cout << endl << "Pressione qualquer tecla para voltar ao menu principal" << endl << endl;
    cin.clear();
    getchar();

    gp.salvaListaImoveis(imoveis); // consertar isso pra salvar o array de ponteiros com as modifica�oes que fizemos!
}

void SistemaImobiliaria::getImoveis(){
    int i = 0, casas = 0, apts = 0, flats = 0, studios = 0, terrenos = 0;

    for(i=0; i<100; i++){
        if(imoveis[i]->getTipoImovel() == 1){
            casas++;
        }
        if(imoveis[i]->getTipoImovel() == 2){
            apts++;
        }
        if(imoveis[i]->getTipoImovel() == 3){
            terrenos++;
        }
        if(imoveis[i]->getTipoImovel() == 4){
            flats++;
        }
        if(imoveis[i]->getTipoImovel() == 5){
            studios++;
        }
    }

    cout << "Casas: " << casas << "\nApartamentos: " << apts << "\nTerrenos: " << terrenos << "\nFlats: " << flats << "\nStudios: " << studios << endl;

}
void SistemaImobiliaria::getDescricaoImoveis(){
    for(int i = 0; i < 100; i++){
        if(imoveis[i]->getTipoOferta() != 0){
            cout << imoveis[i]->getDescricao() << endl;
            cout <<"\nX-------------------------X\n" << endl;
        }
    }
}

void SistemaImobiliaria::getImoveisParaAlugarPorBairro(string bairro){
    int i;
    for(i=0;i<100;i++){
        if(imoveis[i]->getEndereco().getBairro() == bairro && (imoveis[i]->getTipoOferta() == 1 || imoveis[i]->getTipoOferta() == 3)){
            cout <<"\nX-------------------------X\n" << setprecision (5)  << fixed << imoveis[i]->getDescricao() << endl;
        }
    }
    cout <<"\nX-------------------------X\n" << endl;
}

void SistemaImobiliaria::getImoveisParaVenderPorBairro(string bairro){
    int i;
    for(i=0;i<100;i++){
        if(imoveis[i]->getEndereco().getBairro() == bairro && (imoveis[i]->getTipoOferta() == 2  || imoveis[i]->getTipoOferta() == 3)){
            cout <<"\nX-------------------------X\n" << setprecision (5)  << fixed << imoveis[i]->getDescricao() << endl;
        }
    }
    cout <<"\nX-------------------------X\n" << endl;
}

void SistemaImobiliaria::getImoveisPorCidade(string cidade){
    int i;
    for(i=0;i<100;i++){
        if(imoveis[i]->getEndereco().getCidade() == cidade){
            cout <<"\nX-------------------------X\n" << setprecision (5)  << fixed << imoveis[i]->getDescricao() << endl;
        }
    }
    cout <<"\nX-------------------------X\n" << endl;
}

void SistemaImobiliaria::getImoveisDisponiveis(){
    int i, cont =0;

    for(i=0;i<100;i++){
        if(imoveis[i]->getTipoOferta() != 0){
            cont++;
        }
    }
    cout << "Imoveis disponiveis: " << cont << endl;
}

void SistemaImobiliaria::atualizaImovel(){
    int id;
    cout << "Digite o Identificador desejado: ";
    cin >> id;
    deletaImovel(id);
    cadastraImovel();
    cout << ">> IMOVEL ATUALIZADO COM SUCESSO! =)\n\n";
    getchar();
    getchar();
}

void SistemaImobiliaria::deletaImovel(int id){
    imoveis[id]->setTipoOferta(0);
    imoveis[id]->setTipoImovel(0);
}