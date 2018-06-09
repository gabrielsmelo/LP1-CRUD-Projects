#include <stdio.h>
#include <stdlib.h>
#include "timovel.h"
#include <locale.h>
#include <string.h>
#include "consulta.h"

int ProcuraIndex(tImovel *imoveis){
	int i;
	for(i = 0; i < 200; i++){
        if(imoveis[i].type == 0)
            return i;
	}
}

void Cadastra(tImovel *imoveis, int index, int flag){
    setlocale(LC_ALL, "Portuguese");
    char confirm = 'n';
    int cancelar = 0;
    system("cls");
    if(flag == 0){
        printf("x----------------------------------x\n");
        printf("x---------CADASTRO DE IMOVEL-------x");
        printf("\n\nQUE TIPO DE IMOVEL VOCE DESEJA CADASTRAR?\n");
	}else if(flag == 1){
        printf("x-------------------------------------x\n");
        printf("x---------ATUALIZACAO DE IMOVEL-------x");
        printf("\n\nQUE TIPO DE IMOVEL VOCE DESEJA ATUALIZAR?\n");
	}
	printf("0-> CANCELAR\n");
	printf("1-> CASA\n");
	printf("2-> APARTAMENTO\n");
	printf("3-> TERRENO\n");
	printf("4-> FLAT\n");
	printf("5-> STUDIO\n");
	printf("\n>> Digite a opcao escolhida: ");
	while(1){
        scanf("%d", &imoveis[index].type);
        if(imoveis[index].type >= 0 && imoveis[index].type <=5)
            break;
        printf("Opcao Invalida.\n>> Digite a opcao escolhida: ");
	}
	if(imoveis[index].type == 0){
        return;
	}

    while(confirm != 's'){
        printf("\nRUA: ");
        getchar();
        fgets(imoveis[index].streetName, 50, stdin);
        imoveis[index].streetName[strlen(imoveis[index].streetName)-1] = '\0';
        printf("Confirmar(s/n)? ");
        scanf("%c", &confirm);
    }
    confirm = 'n';
    while(confirm != 's'){
        printf("\nBAIRRO: ");
        getchar();
        fgets(imoveis[index].hood, 50, stdin);
        imoveis[index].hood[strlen(imoveis[index].hood)-1] = '\0';
        printf("Confirmar(s/n)? ");
        scanf("%c", &confirm);
    }
    confirm = 'n';
    while(confirm != 's'){
        printf("\nCIDADE: ");
        getchar();
        fgets(imoveis[index].city, 50, stdin);
        imoveis[index].city[strlen(imoveis[index].city)-1] = '\0';
        printf("Confirmar(s/n)? ");
        scanf("%c", &confirm);
    }
    confirm = 'n';
    while(confirm != 's'){
        printf("\nNUMERO: ");
        scanf("%d", &imoveis[index].number);
        printf("Confirmar(s/n)? ");
        scanf("%*c%c", &confirm);
    }
    confirm = 'n';
    while(confirm != 's'){
        printf("\nCEP: ");
        scanf("%d", &imoveis[index].cep);
        printf("Confirmar(s/n)? ");
        scanf("%*c%c", &confirm);
    }
    confirm = 'n';
    while(confirm != 's'){
        printf("\nDISPONIBILIDADE:\n");
        printf("1-> A VENDA\n");
        printf("2-> ALUGUEL\n");
        printf("3-> AMBOS\n");
        printf("Digite a opcao escolhida: ");
        scanf("%d", &imoveis[index].flag);
        printf("Confirmar(s/n)? ");
        scanf("%*c%c", &confirm);
    }
    confirm = 'n';
    while(confirm != 's'){
        printf("\nVALOR DO IMOVEL (EM R$): ");
        scanf("%f", &imoveis[index].value);
        printf("Confirmar(s/n)? ");
        scanf("%*c%c", &confirm);
    }
    confirm = 'n';
    if(imoveis[index].flag == 2 || imoveis[index].flag == 3){
            while(confirm != 's'){
            printf("\nVALOR DO ALUGUEL (EM R$): ");
            scanf("%f", &imoveis[index].valueAluguel);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
    }
    confirm = 'n';
    if(imoveis[index].type == 1){ // CASA
        while(confirm != 's'){
            printf("\nAREA DO TERRENO(em m²): ");
            scanf("%f", &imoveis[index].d.c.terrainArea);
            printf("Confirmar(s/n)?  ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';
        while(confirm != 's'){
            printf("\nAREA CONSTRUIDA(em m²): ");
            scanf("%f", &imoveis[index].d.c.builtArea);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';
        while(confirm != 's'){
            printf("\nNUMERO DE PISOS: ");
            scanf("%d", &imoveis[index].d.c.floors);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';
        while(confirm != 's'){
            printf("\nNUMERO DE COMODOS : ");
            scanf("%d", &imoveis[index].d.c.rooms);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';

        system("cls");
        if(flag == 0)
            printf(">>IMOVEL CADASTRADO COM SUCESSO!!\n");
        else
            printf(">>IMOVEL ATUALIZADO COM SUCESSO!!\n");
        printf("Voce cadastrou uma >>CASA<<\n\n");
        printf("RUA: %s", imoveis[index].streetName);
        printf("\nBAIRRO: %s", imoveis[index].hood);
        printf("\nCIDADE: %s", imoveis[index].city);
        printf("\nNUMERO: %d\n", imoveis[index].number);
        printf("CEP: %d\n", imoveis[index].cep);
        printf("DISPONIBILIDADE: ");
        if(imoveis[index].flag == 1){
            printf("Venda\n");
        }else if(imoveis[index].flag == 2){
            printf("Aluguel\n");
        }else if(imoveis[index].flag == 3){
            printf("Venda ou Aluguel\n");
        }else
            printf("Nao especificado\n");

        printf("VALOR DO IMOVEL: R$ %.2f\n", imoveis[index].value);
        if(imoveis[index].flag == 2 || imoveis[index].flag == 3)
            printf("VALOR DO ALUGUEL: R$ %.2f\n", imoveis[index].valueAluguel);
        printf("AREA DO TERRENO: %.2f m²\n", imoveis[index].d.c.terrainArea);
        printf("AREA CONSTRUIDA: %.2f m²\n", imoveis[index].d.c.builtArea);
        printf("NUMERO DE PISOS: %d\n", imoveis[index].d.c.floors);
        printf("NUMERO DE COMODOS: %d\n", imoveis[index].d.c.rooms);
    }

    if(imoveis[index].type == 2){ // APARTAMENTO
        while(confirm != 's'){
            printf("\nAREA DO APARTAMENTO(em m²): ");
            scanf("%f", &imoveis[index].d.a.area);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';
        while(confirm != 's'){
            printf("\nVALOR DO CONDOMINIO (EM R$): ");
            scanf("%f", &imoveis[index].d.a.condom);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';
        while(confirm != 's'){
            printf("\nVAGAS NA GARAGEM : ");
            scanf("%d", &imoveis[index].d.a.garage);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';
        while(confirm != 's'){
            printf("\nNUMERO DE COMODOS : ");
            scanf("%d", &imoveis[index].d.a.rooms);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';
         while(confirm != 's'){
            printf("\nNUMERO DO ANDAR : ");
            scanf("%d", &imoveis[index].d.a.andar);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';
         while(confirm != 's'){
            printf("\nPOSICAO(Ex.: Nascente Sul): ");
            getchar();
            fgets(imoveis[index].d.a.pos, 50, stdin);
            printf("Confirmar(s/n)? ");
            scanf("%c", &confirm);
        }
        confirm = 'n';
        system("cls");
        if(flag == 0)
            printf(">>IMOVEL CADASTRADO COM SUCESSO!!\n");
        else
            printf(">>IMOVEL ATUALIZADO COM SUCESSO!!\n");
        printf("Voce cadastrou um >>APARTAMENTO<<\n\n");
        printf("RUA: %s", imoveis[index].streetName);
        printf("\nBAIRRO: %s", imoveis[index].hood);
        printf("\nCIDADE: %s", imoveis[index].city);
        printf("\nNUMERO: %d\n", imoveis[index].number);
        printf("CEP: %d\n", imoveis[index].cep);
        printf("DISPONIBILIDADE: ");
        if(imoveis[index].flag == 1){
            printf("Venda\n");
        }else if(imoveis[index].flag == 2){
            printf("Aluguel\n");
        }else if(imoveis[index].flag == 3){
            printf("Venda ou Aluguel\n");
        }else
            printf("Nao especificado\n");

        printf("VALOR DO IMOVEL: R$ %.2f\n", imoveis[index].value);
        if(imoveis[index].flag == 2 || imoveis[index].flag == 3)
            printf("VALOR DO ALUGUEL: R$ %.2f", imoveis[index].valueAluguel);
        printf("\nAREA DO APARTAMENTO: %.2f m²", imoveis[index].d.a.area);
        printf("\nVALOR DO CONDOMINIO: R$ %.2f", imoveis[index].d.a.condom);
        printf("\nVAGAS DE GARAGEM: %d", imoveis[index].d.a.garage);
        printf("\nNUMERO DE COMODOS: %d", imoveis[index].d.a.rooms);
        printf("\nNUMERO DO ANDAR: %d", imoveis[index].d.a.andar);
        printf("\nPOSICAO: %s", imoveis[index].d.a.pos);
    }

   if(imoveis[index].type == 3){ // TERRENO
        while(confirm != 's'){
            printf("\nAREA DO TERRENO(em m²): ");
            scanf("%f", &imoveis[index].d.t.area);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';

        system("cls");
        if(flag == 0)
            printf(">>IMOVEL CADASTRADO COM SUCESSO!!\n");
        else
            printf(">>IMOVEL ATUALIZADO COM SUCESSO!!\n");
        printf("Voce cadastrou um >>TERRENO<<\n\n");
        printf("RUA: %s", imoveis[index].streetName);
        printf("\nBAIRRO: %s", imoveis[index].hood);
        printf("\nCIDADE: %s", imoveis[index].city);
        printf("\nNUMERO: %d\n", imoveis[index].number);
        printf("CEP: %d\n", imoveis[index].cep);
        printf("DISPONIBILIDADE: ");
        if(imoveis[index].flag == 1){
            printf("Venda\n");
        }else if(imoveis[index].flag == 2){
            printf("Aluguel\n");
        }else if(imoveis[index].flag == 3){
            printf("Venda ou Aluguel\n");
        }else
            printf("Nao especificado\n");

        printf("VALOR DO IMOVEL: R$ %.2f\n", imoveis[index].value);
        if(imoveis[index].flag == 2 || imoveis[index].flag == 3)
            printf("VALOR DO ALUGUEL: R$ %.2f", imoveis[index].valueAluguel);
        printf("\nAREA DO TERRENO: %.2f m²\n", imoveis[index].d.t.area);
    }

    if(imoveis[index].type == 4){ // FLAT
        while(confirm != 's'){
            printf("\nAREA DO FLAT(em m²): ");
            scanf("%f", &imoveis[index].d.f.area);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';
        while(confirm != 's'){
            printf("\nVALOR DO CONDOMINIO (EM R$): ");
            scanf("%f", &imoveis[index].d.f.condom);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';
        while(confirm != 's'){
            printf("\nTEM AR-CONDICIONADO?\n1->Sim / 2->Nao: ");
            scanf("%d", &imoveis[index].d.f.ar);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';
        while(confirm != 's'){
            printf("\nTEM TV?\n1->Sim / 2->Nao: ");
            scanf("%d", &imoveis[index].d.f.tv);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';
        while(confirm != 's'){
            printf("\nTEM INTERNET?\n1->Sim / 2->Nao: ");
            scanf("%d", &imoveis[index].d.f.net);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';
        while(confirm != 's'){
            printf("\nTEM SERVICO DE LAVANDERIA?\n1->Sim / 2->Nao: ");
            scanf("%d", &imoveis[index].d.f.lav);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';
        while(confirm != 's'){
            printf("\nTEM SERVICO DE LIMPEZA?\n1->Sim / 2->Nao: ");
            scanf("%d", &imoveis[index].d.f.limp);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';
        while(confirm != 's'){
            printf("\nTEM RECEPCAO?\n1->Sim / 2->Nao: ");
            scanf("%d", &imoveis[index].d.f.recep);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';

        system("cls");
        if(flag == 0)
            printf(">>IMOVEL CADASTRADO COM SUCESSO!!\n");
        else
            printf(">>IMOVEL ATUALIZADO COM SUCESSO!!\n");
        printf("Voce cadastrou um >>FLAT<<\n\n");
        printf("RUA: %s", imoveis[index].streetName);
        printf("\nBAIRRO: %s", imoveis[index].hood);
        printf("\nCIDADE: %s", imoveis[index].city);
        printf("\nNUMERO: %d\n", imoveis[index].number);
        printf("CEP: %d\n", imoveis[index].cep);
        printf("DISPONIBILIDADE: ");
        if(imoveis[index].flag == 1){
            printf("Venda\n");
        }else if(imoveis[index].flag == 2){
            printf("Aluguel\n");
        }else if(imoveis[index].flag == 3){
            printf("Venda ou Aluguel\n");
        }else
            printf("Nao especificado\n");

        printf("VALOR DO IMOVEL: R$ %.2f\n", imoveis[index].value);
        if(imoveis[index].flag == 2 || imoveis[index].flag == 3)
            printf("VALOR DO ALUGUEL: R$ %.2f", imoveis[index].valueAluguel);
        printf("\nAREA DO FLAT: %.2f m²\n", imoveis[index].d.f.area);
        printf("VALOR DO CONDOMINIO: R$ %.2f\n", imoveis[index].d.f.condom);
        printf("AR-CONDICIONADO: ");
        if(imoveis[index].d.f.ar == 1)
            printf("Sim\n");
        else
            printf("Nao\n");
        printf("TV: ");
        if(imoveis[index].d.f.tv == 1)
            printf("Sim\n");
        else
            printf("Nao\n");
        printf("INTERNET: ");
        if(imoveis[index].d.f.net == 1)
            printf("Sim\n");
        else
            printf("Nao\n");
        printf("SERVICO DE LAVANDERIA: ");
        if(imoveis[index].d.f.lav == 1)
            printf("Sim\n");
        else
            printf("Nao\n");
        printf("SERVICO DE LIMPEZA: ");
        if(imoveis[index].d.f.limp == 1)
            printf("Sim\n");
        else
            printf("Nao\n");
        printf("RECEPCAO 24HRS: ");
        if(imoveis[index].d.f.recep == 1)
            printf("Sim\n");
        else
            printf("Nao\n");
    }

    if(imoveis[index].type == 5){ // STUDIO
        while(confirm != 's'){
            printf("\nAREA DO STUDIO(em m²): ");
            scanf("%f", &imoveis[index].d.s.area);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';
        while(confirm != 's'){
            printf("\nVALOR DO CONDOMINIO (EM R$): ");
            scanf("%f", &imoveis[index].d.s.condom);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';
        while(confirm != 's'){
            printf("\nTEM AR-CONDICIONADO?\n1->Sim / 2->Nao: ");
            scanf("%d", &imoveis[index].d.s.ar);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';
        while(confirm != 's'){
            printf("\nTEM TV?\n1->Sim / 2->Nao: ");
            scanf("%d", &imoveis[index].d.s.tv);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';
        while(confirm != 's'){
            printf("\nTEM INTERNET?\n1->Sim / 2->Nao: ");
            scanf("%d", &imoveis[index].d.s.net);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';
        while(confirm != 's'){
            printf("\nTEM SERVICO DE LAVANDERIA?\n1->Sim / 2->Nao: ");
            scanf("%d", &imoveis[index].d.s.lav);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';
        while(confirm != 's'){
            printf("\nTEM SERVICO DE LIMPEZA?\n1->Sim / 2->Nao: ");
            scanf("%d", &imoveis[index].d.s.limp);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';
        while(confirm != 's'){
            printf("\nTEM RECEPCAO?\n1->Sim / 2->Nao: ");
            scanf("%d", &imoveis[index].d.s.recep);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';
        while(confirm != 's'){
            printf("\nTEM PISCINA?\n1->Sim / 2->Nao: ");
            scanf("%d", &imoveis[index].d.s.pool);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';
        while(confirm != 's'){
            printf("\nTEM SAUNA?\n1->Sim / 2->Nao: ");
            scanf("%d", &imoveis[index].d.s.sauna);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';
        while(confirm != 's'){
            printf("\nTEM SALA DE GINASTICA/ACADEMIA?\n1->Sim / 2->Nao: ");
            scanf("%d", &imoveis[index].d.s.gin);
            printf("Confirmar(s/n)? ");
            scanf("%*c%c", &confirm);
        }
        confirm = 'n';

        system("cls");
        if(flag == 0)
            printf(">>IMOVEL CADASTRADO COM SUCESSO!!\n");
        else
            printf(">>IMOVEL ATUALIZADO COM SUCESSO!!\n");
        printf("Voce cadastrou um >>STUDIO<<\n\n");
        printf("RUA: %s", imoveis[index].streetName);
        printf("\nBAIRRO: %s", imoveis[index].hood);
        printf("\nCIDADE: %s", imoveis[index].city);
        printf("\nNUMERO: %d\n", imoveis[index].number);
        printf("CEP: %d\n", imoveis[index].cep);
        printf("DISPONIBILIDADE: ");
        if(imoveis[index].flag == 1){
            printf("Venda\n");
        }else if(imoveis[index].flag == 2){
            printf("Aluguel\n");
        }else if(imoveis[index].flag == 3){
            printf("Venda ou Aluguel\n");
        }else
            printf("Nao especificado\n");

        printf("VALOR DO IMOVEL: R$ %.2f\n", imoveis[index].valueAluguel);
        if(imoveis[index].flag == 2 || imoveis[index].flag == 3)
            printf("VALOR DO ALUGUEL: R$ %.2f", imoveis[index].valueAluguel);
        printf("\nAREA DO STUDIO: %.2f m²\n", imoveis[index].d.s.area);
        printf("VALOR DO CONDOMINIO: R$ %.2f\n", imoveis[index].d.s.condom);
        printf("AR-CONDICIONADO: ");
        if(imoveis[index].d.s.ar == 1)
            printf("Sim\n");
        else
            printf("Nao\n");
        printf("TV: ");
        if(imoveis[index].d.s.tv == 1)
            printf("Sim\n");
        else
            printf("Nao\n");
        printf("INTERNET: ");
        if(imoveis[index].d.s.net == 1)
            printf("Sim\n");
        else
            printf("Nao\n");
        printf("SERVICO DE LAVANDERIA: ");
        if(imoveis[index].d.s.lav == 1)
            printf("Sim\n");
        else
            printf("Nao\n");
        printf("SERVICO DE LIMPEZA: ");
        if(imoveis[index].d.s.limp == 1)
            printf("Sim\n");
        else
            printf("Nao\n");
        printf("RECEPCAO 24HRS: ");
        if(imoveis[index].d.s.recep == 1)
            printf("Sim\n");
        else
            printf("Nao\n");
        printf("PISCINA: ");
        if(imoveis[index].d.s.pool == 1)
            printf("Sim\n");
        else
            printf("Nao\n");
        printf("SAUNA: ");
        if(imoveis[index].d.s.sauna == 1)
            printf("Sim\n");
        else
            printf("Nao\n");
        printf("SALA DE GINASTICA/ACADEMIA: ");
        if(imoveis[index].d.s.gin == 1)
            printf("Sim\n");
        else
            printf("Nao\n");
    }
    printf("\n");
    getchar();
    getchar();
}

void Deleta(tImovel *imoveis){
    setlocale(LC_ALL, "Portuguese");
    int option = 3;
    int id = -1;
    char confirm = 'n';
    while(confirm == 'n'){
        system("cls");
        printf("x------------------------------x\n");
        printf("x---------REMOVER IMOVEL-------x");
        printf("\n\nQUAL O ID DO IMOVEL QUE VOCE DESEJA REMOVER?\n\n");
        printf("OBS: CASO VOCE NAO CONHECA O ID DO IMOVEL, SE INFORME\nNO MENU PRINCIPAL >> PROCURAR IDENTIFICADOR\n");
        printf("\n1-> DIGITAR ID\n");
        printf("2-> CANCELAR\n");
        printf("\nDigite a opcao escolhida: ");
        do{
            scanf("%d", &option);
        }while(option > 2 || option < 1);

        if(option == 1){
            while(1){
                printf("DIGITE O ID DO IMOVEL: ");
                scanf("%d", &id);

                if(id >= 0 && id <= 199)
                    break;

                printf("ID INVALIDO.\n");
            }
            if(imoveis[id].type == 0){
                printf("\nIMOVEL NAO EXISTENTE.\n");
                getchar();
                getchar();
                confirm == 's';
            }else{
                printf("\n\nx--------------------------------x\n");
                printf("ESTE E O IMOVEL QUE VOCE DESEJA DELETAR?: ");
                DescricaoUmImovel(imoveis[id]);
                printf("\n\nx--------------------------------x\n");
                printf("\n\nVOCE TEM CERTEZA QUE QUER DELETAR ESTE IMOVEL? TODOS OS DADOS SERAO PERDIDOS.\n");
                printf("Confirmar(s/n)? ");
                scanf("%*c%c", &confirm);
                if(confirm == 's'){
                    imoveis[id].type = 0;
                    system("cls");
                    printf("\n\n\n>>O IMOVEL FOI REMOVIDO DA IMOBILIARIA COM SUCESSO<<\n\n\n");
                }
            }
        }else{
            confirm = 's';
        }
    }
    getchar();
    getchar();
}

void Update(tImovel *imoveis){
    setlocale(LC_ALL, "Portuguese");
    int option = 3;
    int id;
    char confirm = 'n';
    while(confirm == 'n'){
        system("cls");
        printf("x--------------------------------x\n");
        printf("x---------ATUALIZAR IMOVEL-------x");
        printf("\n\nQUAL O ID DO IMOVEL QUE VOCE DESEJA ATUALIZAR?\n\n");
        printf("OBS: CASO VOCE NAO CONHECA O ID DO IMOVEL, SE INFORME\nNO MENU PRINCIPAL >> PROCURAR IDENTIFICADOR\n");
        printf("\n1-> DIGITAR ID\n");
        printf("2-> CANCELAR\n");
        printf("\nDigite a opcao escolhida: ");
        while(1){
            scanf("%d", &option);
            if(option == 2 || option == 1)
                break;
            printf("Opcao invalida.\nDigite a opcao escolhida: ");
        }

        if(option == 1){
            while(1){
                printf("DIGITE O ID DO IMOVEL: ");
                scanf("%d", &id);

                if(id >= 0 && id <= 199)
                    break;

                printf("ID INVALIDO.\n");
            }
            if(imoveis[id].type == 0){
                printf("\nIMOVEL NAO EXISTENTE.\n");
                getchar();
                getchar();
                confirm == 's';
            }else{
                printf("\n\nx-----------------------------------------x\n");
                printf("ESTE E O IMOVEL QUE VOCE DESEJA ATUALIZAR?: ");
                DescricaoUmImovel(imoveis[id]);
                printf("\n\nVOCE TEM CERTEZA QUE QUER ATUALIZAR ESTE IMOVEL? TODOS OS DADOS ANTERIORES\nSERAO PERDIDOS.\n");
                printf("Confirmar(s/n)? ");
                    scanf("%*c%c", &confirm);
                if(confirm == 's'){
                    Cadastra(imoveis, id, 1);
                    system("cls");
                    printf("\n\n\n>>O IMOVEL FOI ATUALIZADO COM SUCESSO<<\n\n\n");
                }
            }
        }else{
            confirm = 's';
        }
    }
    printf("Pressione qualquer tecla para continuar...");
    getchar();
    getchar();
    system("cls");
}
