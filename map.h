#pragma once
#include <string>
typedef struct
{
	int izq;
	int der;
	int arriba;
	int abajo;
}Posicion;
struct mapasJuego
{
	Posicion  posicion;
	char mapName[12];
	int Indice;
};
class map{
public:
	void setMapData(mapasJuego mapasArray[]);
	mapasJuego getMapData(int index);
	map();
	~map();
	mapasJuego mapasArray[40];
};
//class map
//{
//public:
//	map();
//	~map();
//
//};



