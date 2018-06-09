#ifndef TIMOVEL_H_INCLUDED
#define TIMOVEL_H_INCLUDED

typedef struct{
	int floors, rooms;
	float terrainArea, builtArea;
}tCasa;


typedef struct{
	float area, condom;
	int rooms, garage, andar;
	char pos[30];
}tApartamento;


typedef struct{
	float area;
}tTerreno;

typedef struct{
    float area, condom;
    int ar, tv, net, lav, limp, recep; // 1 = sim , 2 = nao
}tFlat;

typedef struct{
    float area, condom;
    int ar, tv, net, lav, limp, recep, pool, sauna, gin; // 1 = sim, 2 = nao
}tStudio;


typedef union{
	tCasa c;
	tApartamento a;
	tTerreno t;
	tFlat f;
	tStudio s;
}tUnion;


typedef struct{
	char streetName[50], hood[50], city[50];
	int number, cep, flag; // flag = 1 -> à venda // flag = 2 -> para alugar // flag = 3 -> os dois
	float value, valueAluguel;
	int type; // type = 1 -> casa // type = 2 -> apartamento // type = 3 -> terreno // type = 4 -> flat // type = 5 -> studio
	tUnion d;
}tImovel;


#endif // timovel.h
