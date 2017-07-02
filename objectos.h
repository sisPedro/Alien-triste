#pragma once
#include <SDL.h>
#include "string"
#include "Player.h"
class objectos
{
	SDL_Rect objCrop;
	SDL_Texture *texture;
	int originX, originY;
	int radius;
	int frameWidth, frameHeight;
public:
	objectos(SDL_Renderer *renderTarget, std::string filePath, int x, int y);
	int GetOriginX();
	int GetOriginY();
	int GetRadius();
	bool IntersectsWith(Player &p);
	SDL_Rect positionRect;
	void Draw(SDL_Renderer *renderTarget);
	~objectos();
};

