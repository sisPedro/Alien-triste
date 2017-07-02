#include "loadTexture.h"
SDL_Texture *loadtexture(std::string filePath, SDL_Renderer *renderTarget)
{
	SDL_Texture *texture = nullptr;
	SDL_Surface *surface = IMG_Load(filePath.c_str());
	if (surface == NULL)
		fatalError("Error en la carga de superficie");
	else
	{
		texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		if (texture == NULL)
			fatalError("Error en la conversion de textura a superficie");
	}

	SDL_FreeSurface(surface);

	return texture;
}
