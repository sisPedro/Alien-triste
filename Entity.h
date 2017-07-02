#pragma once
#include "SDL.h"
#undef main
#include <string>
#include "Player.h"
#include "map.h"
class Entity
{
public:
	Entity( int x, int y, int framesX, int FramesY) ;      //SDL_Renderer *renderTarget, std::string filePath, int x, int y y fX/fY en player
	~Entity();
	void Draw(SDL_Renderer *renderTarget, SDL_Texture *_vino, SDL_Rect cameraRect);
	bool IntersectsWith(Player &p);
	int GetOriginX();
	int GetOriginY();
	int  GetRadius();
	bool isactive;
	void Update(float delta);
	void SetTextureSize(SDL_Texture *_vino);
private:
	int oscilar;
	float frameCounter;
	int frameWidth, frameHeight;
	int textureWidth; 
	SDL_Rect entityCrop;   
	SDL_Rect positionRect;
	int originX, originY;
	int radius;
};

