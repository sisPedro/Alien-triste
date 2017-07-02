#pragma once
#include <SDL.h>
#include <string>
#include <iostream>
#include <SDL_image.h>
#include "loadTexture.h"
#include "Player.h"
#include "Errors.h"
#include "Entity.h"
#include "map.h"
#include "SDL_mixer.h"
enum class GameState { PLAY, EXIT };
class MainGame
{
public:
	MainGame();
	~MainGame();
	mapasJuego mapaActualM;
	void runGame(); //map mapObj 

private: // ESCRIBIR UNA FUNCION PARA COPIAR LOS PARAMETROS DE MAPOBJ ASIGNADOS EN SOURCE AL MAPOBJ CREADO ACA
	map mapClass;
	GameState _gameState;
	Player _alien;
	Entity vinola;
	//void setMapData();
	void initSystems(int Flags);
	void gameLoop();
	void processInput();
	void drawGame();
	void drawIntro();
	SDL_Rect cameraRect;
	SDL_Texture *_map;
	SDL_Texture *_player;
	SDL_Texture *_vino;
	SDL_Surface *_surface;
	SDL_Renderer *_renderTarget;
	SDL_Window* _window;
	SDL_Scancode keys[6];
	SDL_Event _event;
	int changeMap;
	int mapIndex,prevMapIndex;
	int mapaseneljuego;
	int _screenHeight, _screenWidth, initFlags;
	int levelWidth, levelHeight;
	int _prevTime, _currentTime;
	float _delta;
	float _elapsedTime;
	const Uint8 *_keyState;
	bool isPaused;
	//map _mapObj;
};

