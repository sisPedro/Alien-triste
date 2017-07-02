#include "Errors.h"
#include <iostream>
#include <SDL.h>
#include <cstdlib>
//imprime errores de mensaje
void fatalError(std::string errorString)
{
	std::cout << errorString +SDL_GetError()<< std::endl;
	std::cout << "Enter Enter to quit... " << std::endl;
	int tmp;
	std::cin >> tmp;

	SDL_Quit();
	exit(1);
}