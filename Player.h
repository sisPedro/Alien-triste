#pragma once
#include "SDL.h"
#include "string"
#include "loadTexture.h"
#include "map.h"


class Player
{
public:
	Player(int x, int y, int framesX, int FramesY);
	~Player();
	void SetTextureSize(SDL_Texture *_alien);
	void Update(float delta, const Uint8 *keyState);
	void Draw(SDL_Renderer *renderTarget, SDL_Texture *_alien, SDL_Rect cameraRect);
	SDL_Rect DrawingRect;
	bool IntersectsWith(Player &p);
	int GetOriginX();
	int GetOriginY();
	int GetRadius();	
	int ChangeLevel();
	void resetPos(Player &p);
private:
	mapasJuego mapaActual;
	map mapClass;
	SDL_Texture *texture;
	float moveSpeed;
	float frameCounter;
	int frameWidth, frameHeight;
	int textureWidth;
	int jumpHeight;
	int jump;
	bool isActive;
	bool isPaused;
	bool isJumping;
	bool isFalling;
	int changeLevel;
	SDL_Scancode keys[6];
	int originX, originY;
	int radius;
	int nivel, prevNivel;
//	SDL_Event ev;
	SDL_Texture *_alien;
	SDL_Rect playerCrop;
	SDL_Rect positionRect;
};


