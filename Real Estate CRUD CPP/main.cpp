#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "SistemaImobiliaria.h"

using namespace std;

int main(){
	system("clear");
	cout.precision(3);
	int option = 0, flag = 0;
	int debugMode = 0;
	string str1;
    SistemaImobiliaria sys;
    while(1){
  		printf("x-----------------------------------------x\n");
		printf("x-------------IMOBILIARIA GJB-------------x");
		printf("\n\nDIGITE QUAL MENU DESEJA ACESSAR:");
		printf("\n\n1-> CADASTRAR IMOVEL");
		printf("\n2-> ATUALIZAR IMOVEL");
		printf("\n3-> REMOVER IMOVEL");
		printf("\n4-> QUANTIDADE DE IMOVEIS DISPONIVEIS");
		printf("\n5-> TODOS OS IMOVEIS REGISTRADOS");
		printf("\n6-> DISPONIVEIS POR TIPO");
		printf("\n7-> DISPONIVEIS PARA ALUGUEL POR BAIRRO");
		printf("\n8-> DISPONIVEIS PARA VENDER POR BAIRRO");
		printf("\n9-> IMOVEIS DISPONIVEIS POR CIDADE");
		printf("\n10-> SAIR\n");
		if(debugMode) {
			printf("(((DEBUG MODE)))\n");
			printf("11-> LER DA MEMORIA(DebugMode)\n");
			printf("12-> SALVAR DA MEMORIA(DebugMode)\n");
		}
		printf("\n>> Digite a opcao escolhida: ");
		scanf("%d", &option);
		while(option <= 0 && option != 1337){
            cout << "Opcao invalida!" << endl;
            printf("\n>> Digite a opcao escolhida: ");
            scanf("%d", &option);
		}

		switch(option){
			case 1:
				sys.cadastraImovel();
				system("clear");
				break;
			case 2:
				sys.atualizaImovel();
				system("clear");
				break;
			case 3:
				int id;
				cout << "Insira o identificador do imovel: ";
				cin >> id;
				sys.deletaImovel(id);
				system("clear");
				break;
			case 4:
				system("clear");
				printf("x-----------------------------------------x\n");
				sys.getImoveisDisponiveis();
				printf("x-----------------------------------------x\n");
				getchar();
				getchar();
				system("clear");
				break;
			case 5:
				system("clear");
				printf("x-----------------------------------------x\n");
				sys.getDescricaoImoveis();
				getchar();
				getchar();
				system("clear");
				break;
			case 6:
				system("clear");
				printf("x-----------------------------------------x\n");
				sys.getImoveis();
				getchar();
				getchar();
				system("clear");
				break;
			case 7:
				system("clear");
				printf("x-----------------------------------------x\n");
				cout << "Digite o bairro: ";
				cin >> str1;
				sys.getImoveisParaAlugarPorBairro(str1);
				printf("x-----------------------------------------x\n");
				getchar();
				getchar();
				system("clear");
				break;
			case 8:
				system("clear");
				printf("x-----------------------------------------x\n");
				cout << "Digite o bairro: ";
				cin >> str1;
				sys.getImoveisParaVenderPorBairro(str1);
				printf("x-----------------------------------------x\n");
				getchar();
				getchar();
				system("clear");
				break;
			case 9:
				system("clear");
				printf("x-----------------------------------------x\n");
				cout << "Digite a cidade: ";
				cin >> str1;
				sys.getImoveisPorCidade(str1);
				printf("x-----------------------------------------x\n");
				getchar();
				getchar();
				system("clear");
				break;
			case 10:
			    system("clear");
                printf("x---------PROJETO DE LP1--------x\n");
                printf("By: Bruno Passeti\n    Joao da Mata\n    Joao Gabriel S de Melo\n\n\n\n");
				flag = 1;
				break;
			case 11:
				if(debugMode){
					system("clear");
					sys.gp.recuperaListaImoveis(sys.imoveis);
					getchar();
					getchar();
					break;
				}
				break;
			case 12:			
				if (debugMode){
					system("clear");
					sys.gp.salvaListaImoveis(sys.imoveis);
					getchar();
					getchar();
					break;
				}
			    break;
			case 1337:
				debugMode = !debugMode;
				system("clear");
				break;
			default:
				puts("Entrada Invalida");
				getchar();
				getchar();
				system("clear");
		}
		if(flag) break;

	}



	return 0;




}
