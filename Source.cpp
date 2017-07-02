#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#undef main
#include "MainGame.h"
#include "map.h"
int main()
{	
	MainGame mainGame;
	mainGame.runGame();
		
	return 0;
}