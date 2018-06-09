#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "timovel.h"
#include "cadastro.h"
#include "consulta.h"

tImovel imoveis[200];

void IniciaArray(tImovel *imoveis){
    int i;
    for(i = 0; i < 200; i++){
        imoveis[i].type = 0;
    }
}

void SalvaArquivo(FILE *data){
	fseek(data, 0, SEEK_SET);
    int i;
    for(i = 0; i < 200; i++){
        fwrite(&imoveis[i], sizeof(tImovel), 1, data);
    }
	fseek(data, 0, SEEK_SET);
}

void LeArquivo(FILE *data){
	fseek(data, 0, SEEK_SET);
    int i;
    for(i = 0;i < 200; i++){
        fread(&imoveis[i], sizeof(tImovel), 1, data);
    }
	fseek(data, 0, SEEK_SET);
}

int main(void){
	system("cls");
	IniciaArray(imoveis);
    setlocale(LC_ALL, "Portuguese");
	char flag = 0;
	FILE *data;
    data = fopen("data.bin", "r+b");
	LeArquivo(data);
	// IniciaArray(imoveis);
	// SalvaArquivo(data);
    int option,id;
	while('1'){
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
		printf("\n10-> PROCURAR IDENTIFICADOR");
		printf("\n11-> SAIR\n");
		printf("\n>> Digite a opcao escolhida: ");
		scanf("%d", &option);

		switch(option){
			case 1:
				Cadastra(imoveis, ProcuraIndex(imoveis), 0);
				system("cls");
				SalvaArquivo(data);
				break;
			case 2:
				Update(imoveis);
				system("cls");
				SalvaArquivo(data);
				break;
			case 3:
				Deleta(imoveis);
				system("cls");
				SalvaArquivo(data);
				break;
			case 4:
				system("cls");
				printf("x-----------------------------------------x\n");
				Consulta(imoveis);
				printf("x-----------------------------------------x\n");
				getchar();
				getchar();
				system("cls");
				break;
			case 5:
				system("cls");
				Descricao(imoveis);
				system("cls");
				break;
			case 6:
				system("cls");
				DisponivelTipo(imoveis);
				getchar();
				getchar();
				system("cls");
				break;
			case 7:
				system("cls");
				printf("x-----------------------------------------x\n");
				AlugarPorBairro(imoveis);
				printf("x-----------------------------------------x\n");
				getchar();
				system("cls");
				break;
			case 8:
				system("cls");
				printf("x-----------------------------------------x\n");
				VenderPorBairro(imoveis);
				printf("x-----------------------------------------x\n");
				getchar();
				system("cls");
				break;
			case 9:
				system("cls");
				printf("x-----------------------------------------x\n");
				DisponivelPorCidade(imoveis);
				printf("x-----------------------------------------x\n");
				getchar();
				system("cls");
				break;
			case 10:
				id = Identificador(imoveis);
				system("cls");
				printf("x-----------------------------------------x\n");
				if(id == -1){
					printf("Endereco nao encontrado.\n");
					getchar();
				}else {
					printf("Identificador do imovel: %d\n", id);
				}
				printf("x-----------------------------------------x\n");
				getchar();
				getchar();
				system("cls");
				break;
			case 11:
			    system("cls");
                printf("x---------PROJETO DE LP1--------x\n");
                printf("By: Bruno Passeti\n    Joao da Mata\n    Joao Gabriel S de Melo\n\n\n\n");
				flag = 1;
				break;
			default:
				puts("Entrada Invalida");
				getchar();
				getchar();
				system("cls");
		}
		if(flag) break;

	}

	return 0;
}
