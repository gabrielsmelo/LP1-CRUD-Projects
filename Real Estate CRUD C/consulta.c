#include <stdio.h>
#include <stdlib.h>
#include "timovel.h"
#include <locale.h>
#include <string.h>
#include <ctype.h>

char *strlwr(char *str)
{
  unsigned char *p = (unsigned char *)str;

  while (*p) {
     *p = tolower((unsigned char)*p);
      p++;
  }

  return str;
}

void Consulta(tImovel *imoveis){
	int casas=0, apart=0, terr=0, flat=0, studio=0, i;

	for(i=0; i<200; i++){
		if(imoveis[i].flag != 0){
			if(imoveis[i].type == 1)
				casas++;
			else if(imoveis[i].type == 2)
				apart++;
			else if(imoveis[i].type == 3)
				terr++;
            		else if(imoveis[i].type == 4)
               			flat++;
            		else if(imoveis[i].type == 5)
                		studio++;
		}
	}
	printf("DISPONIVEIS:\n%d CASAS\n%d APARTAMENTOS\n%d TERRENOS\n%d FLATS\n%d STUDIOS\n", casas, apart, terr, flat, studio);
}

void DescricaoUmImovel(tImovel imovel){

	if(imovel.type != 0){
		printf("\nx-----------------------------------------x\n");

		printf("RUA: %s\n", imovel.streetName);
		printf("BAIRRO: %s\n", imovel.hood);
		printf("CIDADE: %s\n", imovel.city);
		printf("NUMERO: %d\n", imovel.number);
		printf("CEP: %d\n", imovel.cep);
		printf("DISPONIBILIDADE: ");
            if(imovel.flag == 1)
                printf("Venda\n");
            else if(imovel.flag == 2)
                printf("Aluguel\n");
            else
                printf("Aluguel ou Venda\n");
		printf("VALOR DO IMOVEL: R$ %.2lf\n", imovel.value);
            if(imovel.flag == 2 || imovel.flag == 3)
                printf("VALOR DO ALUGUEL: R$ %.2lf\n", imovel.valueAluguel);

		if(imovel.type == 1){
			printf("ANDARES: %d\n", imovel.d.c.floors);
			printf("QUARTOS: %d\n", imovel.d.c.rooms);
			printf("AREA TOTAL: %.2lf\n", imovel.d.c.terrainArea);
			printf("AREA CONSTRUIDA: %.2lf\n", imovel.d.c.builtArea);
			printf("x-----------------------------------------x\n");
		}

		if(imovel.type == 2){
			printf("AREA: %.2lf\n", imovel.d.a.area);
			printf("VALOR DO CONDOMINIO: R$ %.2lf\n", imovel.d.a.condom);
			printf("QUARTOS: %d\n", imovel.d.a.rooms);
			printf("VAGAS DE GARAGEM: %d\n", imovel.d.a.garage);
			printf("ANDAR: %d\n", imovel.d.a.andar);
			printf("POSICAO: %s\n", imovel.d.a.pos);
			printf("x-----------------------------------------x\n");
		}

		if(imovel.type == 3){
			printf("AREA: %.2lf\n", imovel.d.t.area);
			printf("x-----------------------------------------x\n");
		}

		if(imovel.type == 4){
			printf("AREA: %.2lf\n", imovel.d.f.area);
			printf("VALOR DO CONDOMINIO: R$ %.2lf\n", imovel.d.f.condom);
			if(imovel.d.f.ar == 1)
			    printf("POSSUI ARCONDICIONADO\n");
			else
			    printf("NAO POSSUI ARCONDICIONADO\n");

			if(imovel.d.f.tv == 1)
			    printf("POSSUI TV A CABO\n");
			else
			    printf("NAO POSSUI TV A CABO\n");

			if(imovel.d.f.net == 1)
			    printf("POSSUI INTERNET\n");
			else
			    printf("NAO POSSUI INTERNET\n");

			if(imovel.d.f.lav == 1)
			    printf("POSSUI SERVICO DE LAVANDERIA\n");
			else
			    printf("NAO POSSUI SERVICO DE LAVANDERIA\n");

			if(imovel.d.f.limp == 1)
			    printf("POSSUI SERVICO DE LIMPEZA\n");
			else
			    printf("NAO POSSUI SERVICO DE LIMPEZA\n");

			if(imovel.d.f.recep == 1)
			    printf("POSSUI RECEPCAO 24 HORAS\n");
			else
			    printf("NAO POSSUI RECEPCAO 24 HORAS\n");

			printf("x-----------------------------------------x\n");

		}
		if(imovel.type == 5){
			printf("AREA: %.2lf\n", imovel.d.s.area);
			printf("VALOR DO CONDOMINIO: R$ %.2lf\n", imovel.d.s.condom);

			if(imovel.d.s.ar == 1)
			    printf("POSSUI ARCONDICIONADO\n");
			else
			    printf("NAO POSSUI ARCONDICIONADO\n");

			if(imovel.d.s.tv == 1)
			    printf("POSSUI TV A CABO\n");
			else
			    printf("NAO POSSUI TV A CABO\n");

			if(imovel.d.s.net == 1)
			    printf("POSSUI INTERNET\n");
			else
			    printf("NAO POSSUI INTERNET\n");

			if(imovel.d.s.lav == 1)
			    printf("POSSUI SERVICO DE LAVANDERIA\n");
			else
			    printf("NAO POSSUI SERVICO DE LAVANDERIA\n");

			if(imovel.d.s.limp == 1)
			    printf("POSSUI SERVICO DE LIMPEZA\n");
			else
			    printf("NAO POSSUI SERVICO DE LIMPEZA\n");

			if(imovel.d.s.recep == 1)
			    printf("POSSUI RECEPCAO 24 HORAS\n");
			else
			    printf("NAO POSSUI RECEPCAO 24 HORAS\n");

			if(imovel.d.s.pool == 1)
			    printf("POSSUI PISCINA\n");
			else
			    printf("NAO POSSUI PISCINA\n");

			if(imovel.d.s.sauna == 1)
			    printf("POSSUI SAUNA\n");
			else
			    printf("NAO POSSUI SAUNA\n");

			if(imovel.d.s.gin == 1)
			    printf("POSSUI SALA DE GINASTICA\n");
			else
			    printf("NAO POSSUI SALA DE GINASTICA\n");

			printf("x-----------------------------------------x\n");
		}
	}
}

void Descricao(tImovel *imoveis){
	int i;

	for(i=0; i<200; i++){


		if(imoveis[i].type != 0){
			printf("x-----------------------------------------x\n");
			if(imoveis[i].type == 1)
				printf("\t\t\tCASA\n\n");
			else if(imoveis[i].type == 2)
				printf("\t\t\tAPARTAMENTO\n\n");
			else if(imoveis[i].type == 3)
				printf("\t\t\tTERRENO\n\n");
			else if(imoveis[i].type == 4)
				printf("\t\t\tFLAT\n\n");
			else if(imoveis[i].type == 5)
				printf("\t\t\tSTUDIO\n\n");

			printf("RUA: %s\n", imoveis[i].streetName);
			printf("BAIRRO: %s\n", imoveis[i].hood);
			printf("CIDADE: %s\n", imoveis[i].city);
			printf("NUMERO: %d\n", imoveis[i].number);
			printf("CEP: %d\n", imoveis[i].cep);
			printf("VALOR DO IMOVEL: R$ %.2lf\n", imoveis[i].value);
			printf("DISPONIBILIDADE: ");
            if(imoveis[i].flag == 1)
                printf("Venda\n");
            else if(imoveis[i].flag == 2)
                printf("Aluguel\n");
            else
                printf("Aluguel ou Venda\n");
			if(imoveis[i].flag == 2 || imoveis[i].flag == 3)
                printf("VALOR DO ALUGUEL: R$ %.2lf\n", imoveis[i].valueAluguel);

			if(imoveis[i].type == 1){
				printf("ANDARES: %d\n", imoveis[i].d.c.floors);
				printf("QUARTOS: %d\n", imoveis[i].d.c.rooms);
				printf("AREA TOTAL: %.2lf\n", imoveis[i].d.c.terrainArea);
				printf("AREA CONSTRUIDA: %.2lf\n", imoveis[i].d.c.builtArea);
			}

			if(imoveis[i].type == 2){
				printf("AREA: %.2lf\n", imoveis[i].d.a.area);
				printf("VALOR DO CONDOMINIO: R$ %.2lf\n", imoveis[i].d.a.condom);
				printf("QUARTOS: %d\n", imoveis[i].d.a.rooms);
				printf("VAGAS DE GARAGEM: %d\n", imoveis[i].d.a.garage);
				printf("ANDAR: %d\n", imoveis[i].d.a.andar);
				printf("POSICAO: %s\n", imoveis[i].d.a.pos);
			}

			if(imoveis[i].type == 3){
				printf("AREA: %.2lf\n", imoveis[i].d.t.area);
			}

			if(imoveis[i].type == 4){
				printf("AREA: %.2lf\n", imoveis[i].d.f.area);
				printf("VALOR DO CONDOMINIO: R$ %.2lf\n", imoveis[i].d.f.condom);
				if(imoveis[i].d.f.ar == 1)
				    printf("POSSUI ARCONDICIONADO\n");
				else
				    printf("NAO POSSUI ARCONDICIONADO\n");

				if(imoveis[i].d.f.tv == 1)
				    printf("POSSUI TV A CABO\n");
				else
				    printf("NAO POSSUI TV A CABO\n");

				if(imoveis[i].d.f.net == 1)
				    printf("POSSUI INTERNET\n");
				else
				    printf("NAO POSSUI INTERNET\n");

				if(imoveis[i].d.f.lav == 1)
				    printf("POSSUI SERVICO DE LAVANDERIA\n");
				else
				    printf("NAO POSSUI SERVICO DE LAVANDERIA\n");

				if(imoveis[i].d.f.limp == 1)
				    printf("POSSUI SERVICO DE LIMPEZA\n");
				else
				    printf("NAO POSSUI SERVICO DE LIMPEZA\n");

				if(imoveis[i].d.f.recep == 1)
				    printf("POSSUI RECEPCAO 24 HORAS\n");
				else
				    printf("NAO POSSUI RECEPCAO 24 HORAS\n");

					}
			if(imoveis[i].type == 5){
				printf("AREA: %.2lf\n", imoveis[i].d.s.area);
				printf("VALOR DO CONDOMINIO: R$ %.2lf\n", imoveis[i].d.s.condom);
				if(imoveis[i].d.s.ar == 1)
				    printf("POSSUI ARCONDICIONADO\n");
				else
				    printf("NAO POSSUI ARCONDICIONADO\n");

				if(imoveis[i].d.s.tv == 1)
				    printf("POSSUI TV A CABO\n");
				else
				    printf("NAO POSSUI TV A CABO\n");

				if(imoveis[i].d.s.net == 1)
				    printf("POSSUI INTERNET\n");
				else
				    printf("NAO POSSUI INTERNET\n");

				if(imoveis[i].d.s.lav == 1)
				    printf("POSSUI SERVICO DE LAVANDERIA\n");
				else
				    printf("NAO POSSUI SERVICO DE LAVANDERIA\n");

				if(imoveis[i].d.s.limp == 1)
				    printf("POSSUI SERVICO DE LIMPEZA\n");
				else
				    printf("NAO POSSUI SERVICO DE LIMPEZA\n");

				if(imoveis[i].d.s.recep == 1)
				    printf("POSSUI RECEPCAO 24 HORAS\n");
				else
				    printf("NAO POSSUI RECEPCAO 24 HORAS\n");

				if(imoveis[i].d.s.pool == 1)
				    printf("POSSUI PISCINA\n");
				else
				    printf("NAO POSSUI PISCINA\n");

				if(imoveis[i].d.s.sauna == 1)
				    printf("POSSUI SAUNA\n");
				else
				    printf("NAO POSSUI SAUNA\n");

				if(imoveis[i].d.s.gin == 1)
				    printf("POSSUI SALA DE GINASTICA\n");
				else
				    printf("NAO POSSUI SALA DE GINASTICA\n");
			}
		printf("ID: %d\n", i);
		}
	}
	printf("x-----------------------------------------x\n");
	getchar();
	getchar();
}//

void AVendaPorTipo(tImovel *imoveis){

	int tipo, i;

	printf("1 ---> CASA\n");
	printf("2 ---> APARTAMENTO\n");
	printf("3 ---> TERRENO\n");
	printf("4 ---> FLAT\n");
	printf("5 ---> STUDIO\n");

	setbuf(stdin,NULL);

	printf("DIGITE O TIPO QUE VOCE QUER PESQUISAR: ");
	scanf("%d", &tipo);

	for(i=0; i<200; i++){
		if((imoveis[i].flag == 1 || imoveis[i].flag == 3) && tipo == imoveis[i].type){
            DescricaoUmImovel(imoveis[i]);
		}
		else printf("NAO POSSUI IMOVEIS DESSE TIPO A VENDA");
	}
}

void AlugarPorBairro(tImovel *imoveis){

	char bairro[50], aux[50];
	int i, count = 0;

	setbuf(stdin,NULL);

	printf("DIGITE O BAIRRO QUE VOCE DESEJA: ");
	fgets(bairro, 50, stdin);
	bairro[strlen(bairro)-1] = '\0';
	strlwr(bairro);
	for(i=0; i<200; i++){
		if(imoveis[i].flag == 2 || imoveis[i].flag == 3){
			strcpy(aux, imoveis[i].hood);
			strlwr(aux);

			if(strcmp(aux, bairro) == 0){
				DescricaoUmImovel(imoveis[i]);
				count = 1;
			}
		}
	}
	if(count == 0)
        printf("\n\n>> NAO EXISTEM IMOVEIS PARA ALUGAR NESTE BAIRRO.\n\n");
}//

void VenderPorBairro(tImovel *imoveis){

	char bairro[50], aux[50];
	int i, count = 0;

	setbuf(stdin,NULL);

	printf("DIGITE O BAIRRO QUE VOCE DESEJA: ");
	fgets(bairro, 50, stdin);
	bairro[strlen(bairro)-1] = '\0';
	//puts(bairro);
    strlwr(bairro);

	for(i=0; i<200; i++){
		if(imoveis[i].flag == 1 || imoveis[i].flag == 3){
			strcpy(aux, imoveis[i].hood);
			strlwr(aux);

			if(strcmp(aux, bairro) == 0){
				DescricaoUmImovel(imoveis[i]);
				count = 1;
			}
		}
	}
	if(count == 0)
        printf("\n\n>> NAO EXISTEM IMOVEIS PARA VENDER NESTE BAIRRO.\n\n");
}//

void DisponivelPorCidade(tImovel *imoveis){

	char cidade[50], aux[50];
	int i, count = 0;

	setbuf(stdin,NULL);

	printf("DIGITE A CIDADE QUE VOCE DESEJA: ");
	fgets(cidade, 50, stdin);
	cidade[strlen(cidade)-1] = '\0';
	strlwr(cidade);

	for(i=0; i<200; i++){
		if(imoveis[i].type !=0){
			strcpy(aux, imoveis[i].city);
			strlwr(aux);

			if(strcmp(aux, cidade) == 0){
				DescricaoUmImovel(imoveis[i]);
				count = 1;
			}
		}
	}
	if(count == 0)
        printf("\n\n>> NAO EXISTEM IMOVEIS DISPONIVEIS NESTA CIDADE.\n\n");
}//

int Identificador(tImovel *imoveis){

    char rua[50], aux[50];
    int nmr, i;

    setbuf(stdin,NULL);

    printf("\nDIGITE A RUA QUE VOCE DESEJA: ");
    fgets(rua, 50, stdin);
    rua[strlen(rua)-1] = '\0';
    strlwr(rua);

    setbuf(stdin,NULL);

    printf("\nDIGITE O NUMERO DO IMOVEL: ");
    scanf("%d", &nmr);

    for(i=0; i<200; i++){
        strcpy(aux, imoveis[i].streetName);
        strlwr(aux);
        if(strcmp(rua,aux) == 0 && nmr == imoveis[i].number){
                return i;
        }
    }
    return -1;
}

void DisponivelTipo(tImovel *imoveis){

	int tipo, i, count = 0;

    printf("0-> VOLTAR AO MENU PRINCIPAL\n");
	printf("1-> CASA\n");
	printf("2-> APARTAMENTO\n");
	printf("3-> TERRENO\n");
	printf("4-> FLAT\n");
	printf("5-> STUDIO\n");

	printf("DIGITE O TIPO QUE VOCE DESEJA: ");
	while(1){
        scanf("%d", &tipo);
        if(tipo >= 0 && tipo <= 5)
            break;
        printf("Opcao invalida.\nDIGITE O TIPO QUE VOCE DESEJA: ");
	}
	if(tipo == 0)
        return;
	system("cls");
	for(i=0; i<200; i++){
		if(imoveis[i].type == tipo){
		    count = 1;
			DescricaoUmImovel(imoveis[i]);
		}
	}
	if(count == 0)
        printf("NAO EXISTEM MOVEIS DESTE TIPO.\n");
}
