#include "map.h"

map::map()
{
	setMapData(mapasArray);
}



map::~map()
{

}


mapasJuego map::getMapData(int index)
{

	mapasJuego mapaObj;
	strcpy_s(mapaObj.mapName, mapasArray[index].mapName);
	mapaObj.posicion.der = mapasArray[index].posicion.der;
	mapaObj.posicion.izq = mapasArray[index].posicion.izq;
	mapaObj.posicion.arriba = mapasArray[index].posicion.arriba;
	mapaObj.posicion.abajo = mapasArray[index].posicion.abajo;
	mapaObj.Indice = index;
	return mapaObj;
}

void map::setMapData(mapasJuego mapasArray[])
{
	int indeX= 0;
	strcpy_s(mapasArray[indeX].mapName, "bg1.png");
	mapasArray[indeX].posicion.izq = 0;
	mapasArray[indeX].posicion.arriba = 316;
	mapasArray[indeX].posicion.abajo = 408;
	mapasArray[indeX].posicion.der = 1400;
	indeX++;
	strcpy_s(mapasArray[indeX].mapName, "bgdajd.png");
	mapasArray[indeX].posicion.izq = 0;
	mapasArray[indeX].posicion.arriba = 316;
	mapasArray[indeX].posicion.abajo = 428;
	mapasArray[indeX].posicion.der = 1400;
	indeX++;
	strcpy_s(mapasArray[indeX].mapName, "bg2.png");
	mapasArray[indeX].posicion.izq = 0;
	mapasArray[indeX].posicion.arriba = 316;
	mapasArray[indeX].posicion.abajo = 428;
	mapasArray[indeX].posicion.der = 1400;
	indeX++;
	strcpy_s(mapasArray[indeX].mapName, "bg.png");
	mapasArray[indeX].posicion.izq = 0;
	mapasArray[indeX].posicion.arriba = 316;
	mapasArray[indeX].posicion.abajo = 428;
	mapasArray[indeX].posicion.der = 1400;
	indeX++;
	strcpy_s(mapasArray[indeX].mapName, "bg1.png");
	mapasArray[indeX].posicion.izq = 0;
	mapasArray[indeX].posicion.arriba = 316;
	mapasArray[indeX].posicion.abajo = 428;
	mapasArray[indeX].posicion.der = 1400;
	indeX++;
	strcpy_s(mapasArray[indeX].mapName, "bg1.png");
	mapasArray[indeX].posicion.izq = 0;
	mapasArray[indeX].posicion.arriba = 316;
	mapasArray[indeX].posicion.abajo = 428;
	mapasArray[indeX].posicion.der = 1400;
	indeX++;
	strcpy_s(mapasArray[indeX].mapName, "bg1.png");
	mapasArray[indeX].posicion.izq = 0;
	mapasArray[indeX].posicion.arriba = 316;
	mapasArray[indeX].posicion.abajo = 428;
	mapasArray[indeX].posicion.der = 1400;
	indeX++;
	strcpy_s(mapasArray[indeX].mapName, "bg1.png");
	mapasArray[indeX].posicion.izq = 0;
	mapasArray[indeX].posicion.arriba = 316;
	mapasArray[indeX].posicion.abajo = 428;
	mapasArray[indeX].posicion.der = 1400;
	indeX++;
	strcpy_s(mapasArray[indeX].mapName, "bg1.png");
	mapasArray[indeX].posicion.izq = 0;
	mapasArray[indeX].posicion.arriba = 316;
	mapasArray[indeX].posicion.abajo = 428;
	mapasArray[indeX].posicion.der = 1400;
	indeX++;
	strcpy_s(mapasArray[indeX].mapName, "bg1.png");
	mapasArray[indeX].posicion.izq = 0;
	mapasArray[indeX].posicion.arriba = 316;
	mapasArray[indeX].posicion.abajo = 428;
	mapasArray[indeX].posicion.der = 1400;
	indeX++;


}