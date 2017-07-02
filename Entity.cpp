#include "Entity.h"
#include <SDL_image.h>
#include <string>
#include <iostream>
#include <SDL.h>
#include <cmath>



Entity::Entity(int x, int y, int framesX, int framesY) :
	isactive(true), 
	oscilar(0)
{
	positionRect.x = x;
	positionRect.y = y;
}


Entity::~Entity()
{
}
bool Entity::IntersectsWith(Player &p) 
{
	if (sqrt(pow(GetOriginX() - p.GetOriginX(), 2) + pow(GetOriginY() - p.GetOriginY(), 2)) >= GetRadius() + p.GetRadius()) // si da verdadero no se tocan
	{

		return true;
	}

	positionRect.x = (rand() % 800)*2;
	positionRect.y = (rand() % 100)+300;
	return false;
}
void Entity::Update(float delta)
{
	if (isactive)
	{
		if (oscilar <= 32 && oscilar % 2 == 0)
		{
			positionRect.y--;

		}
		else if (oscilar > 32 && oscilar % 2 == 0)
		{
			positionRect.y++;


		}
		if (oscilar == 64)
			oscilar = 0;
		oscilar++;
	}

}

void Entity::SetTextureSize(SDL_Texture *_vino)
{

	SDL_QueryTexture(_vino, NULL, NULL, &entityCrop.w, &entityCrop.h);
	radius = entityCrop.w / 2;
	originX = entityCrop.w / 2;
	originY = entityCrop.h / 2;
}


void Entity::Draw(SDL_Renderer *renderTarget, SDL_Texture *_vino, SDL_Rect cameraRect)
{
	SDL_QueryTexture(_vino, NULL, NULL, &entityCrop.w, &entityCrop.h);
	textureWidth = entityCrop.w;
	entityCrop.w /= 1;
	entityCrop.h /= 1;
	frameWidth = entityCrop.w; //getCrop()   setPoss()?
	positionRect.w = entityCrop.w;
	frameHeight = entityCrop.h;
	positionRect.h = entityCrop.h ;
	SDL_Rect drawingRect = { positionRect.x - (cameraRect.x*2), positionRect.y - cameraRect.y, cameraRect.w/4, cameraRect.h/4 };
	SDL_RenderCopy(renderTarget, _vino, &entityCrop, &drawingRect);  //srcRect, el 3er parametro busca DENTRO de la textura. el 4to parametro determina el target del render
}

int Entity::GetOriginX() { return originX + positionRect.x; }
int Entity::GetOriginY() { return originY + positionRect.y; }
int Entity::GetRadius()  { return radius; }


	