#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Errors.h"
SDL_Texture *loadtexture(std::string filePath, SDL_Renderer *renderTarget);