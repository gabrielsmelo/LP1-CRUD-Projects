#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int floors, rooms;
	float terrainArea, builtArea;
}tCasa;

typedef struct{
	float area, condom;
	int rooms, garage;
	char posit[30];
}tApartamento;

typedef struct{
	float area;
}tTerreno;

typedef struct{
	char streetName[50], hood[50], city[50];
	int number, cep, flag; // flag = 1 -> à venda // flag = 2 -> para alugar // flag = 3 -> os dois
	float value;
	tCasa house;
	tApartamento ap;
	tTerreno tr;
}tImovel;

int main(void){








	return 0;
}