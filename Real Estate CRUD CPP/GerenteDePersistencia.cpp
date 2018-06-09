#include "GerenteDePersistencia.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "SistemaImobiliaria.h"
#include <iomanip> 
#include <typeinfo>

GerenteDePersistencia::GerenteDePersistencia(){
    arq.open("example.txt");
    // if(arq.is_open()){
    //     std::cout << "ABERTO" << "\n";
    //     getchar();
    //     getchar();
    // }
}

int GerenteDePersistencia::ProcuraIndex(Imovel **imoveis){
    for(int i = 0; i < 100; i++){
        if(imoveis[i]->getTipoOferta() == 0){
            return i;
        }
    }
}

void GerenteDePersistencia::salvaListaImoveis(Imovel **imoveis){
    arq.seekp(0, std::ios::beg);
    int count = 0;
    for(int i = 0; i < 100; i++){
        if(imoveis[i]->getTipoOferta() != 0) count ++;
    }
    arq << count << std::endl;
    for(int i = 0; i < 100; i++){
        if(imoveis[i]->getTipoOferta() != 0){
            arq << std::setprecision(3) << imoveis[i]->getTipoOferta() << std::endl;
            arq << std::setprecision(3) << imoveis[i]->getTipoImovel() << std::endl;
            arq << std::setprecision(3) << imoveis[i]->getEndereco().getEstado() << std::endl;
            arq << std::setprecision(3) << imoveis[i]->getEndereco().getCidade() << std::endl;
            arq << std::setprecision(3) << imoveis[i]->getEndereco().getBairro() << std::endl;
            arq << std::setprecision(3) << imoveis[i]->getDescricao() << std::endl;
        }
    }
    arq.seekp(0, std::ios::beg);
}

void GerenteDePersistencia::recuperaListaImoveis(Imovel **imoveis){
    arq.seekg(0, std::ios::beg);
    std::string estado, cidade, bairro,s, desc;
    int tipoO, tipoI, count;
    arq >> count;
    std::string lixo;
    for(int i = 0; i < count; i++){
        desc = "";
        if(arq.eof()) break;
        arq >> tipoO;
        arq >> tipoI;
        std::getline(arq,lixo);
        std::getline(arq,estado);
        std::getline(arq,cidade);
        std::getline(arq,bairro);
        switch(tipoI){
            case 1:
            imoveis[i] = new Casa();
			if(tipoO == 1 || tipoO == 2){            
				for(int j = 0; j < 11;j++){
                	s = "";
                	std::getline(arq, s);
                	desc += s + "\n";
				}             
            }else{
				for(int j = 0; j < 12;j++){
                	s = "";
                	std::getline(arq, s);
                	desc += s + "\n";
				}    
			}
            break;
            case 2:
            imoveis[i] = new Apartamento();
			if(tipoO == 1 || tipoO == 2){    
		        for(int j = 0; j < 12;j++){
		            s = "";
		            std::getline(arq, s);
		            desc += s + "\n";                
		        }
			}else{
		        for(int j = 0; j < 13;j++){
		            s = "";
		            std::getline(arq, s);
		            desc += s + "\n";                
		        }
			}
            case 3:
            imoveis[i] = new Terreno();
            if(tipoO == 1 || tipoO == 2){
                for(int j = 0; j < 8; j++){
                    s = "";
                    std::getline(arq, s);
                    desc += s + "\n";
                }
            }else{
                for(int j = 0; j < 9; j++){
                    s = "";
                    std::getline(arq, s);
                    desc += s + "\n";
                }
            }
            break;
            case 4:
            imoveis[i] = new Flat();
			if(tipoO == 1 || tipoO == 2){   
			    for(int j = 0; j < 15; j++){
			        s = "";
			        std::getline(arq, s);
			        desc += s + "\n";
			    }
			}else{
			    for(int j = 0; j < 16; j++){
			        s = "";
			        std::getline(arq, s);
			        desc += s + "\n";
                }
			}
            break;
            case 5:
            imoveis[i] = new Studio();
			if(tipoO == 1 || tipoO == 2){   
		        for(int j = 0; j < 18; j++){
		            s = "";
		            std::getline(arq, s);
		            desc += s + "\n";
		        }
			}else{
		        for(int j = 0; j < 19; j++){
		            s = "";
		            std::getline(arq, s);
		            desc += s + "\n";
		        }
			}
            break;
        }
        imoveis[i]->setTipoOferta(tipoO);
        imoveis[i]->setTipoImovel(tipoI);
        imoveis[i]->setEndereco(Endereco("",estado,0,bairro,cidade,""));
        imoveis[i]->setDescricao(desc);
    }
    arq.seekg(0, std::ios::beg);
}


