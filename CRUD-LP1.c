typedef struct{
	int floors, rooms;
	float terrainArea, builtArea;
}tCasa;


typedef struct{
	float area, condom;
	int rooms, garage;
	char pos[30];
}tApartamento;


typedef struct{
	float area;
}tTerreno;


typedef union{
	tCasa c;
	tApartamento a;
	tTerreno t;
}tUnion;


typedef struct{
	char streetname[50], hood[50], city[50];
	int number, cep, flag; // flag = 1 -> à venda // flag = 2 -> para alugar // flag = 3 -> os dois
	float value;
	int type; // type = 1 -> casa // type = 2 -> apartamento // type = 3 -> terreno
	tUnion d;
}tImovel;
