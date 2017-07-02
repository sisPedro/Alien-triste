#include "MainGame.h"


MainGame::MainGame():
	_screenWidth(1600),
	_screenHeight(900),
	_window(nullptr),
	_gameState(GameState::PLAY),
	_delta(0)
	, initFlags(SDL_INIT_VIDEO | SDL_INIT_AUDIO),
	_prevTime(0), _currentTime(0),
	_alien(45,350,0,0),
	_map(nullptr),
	_player(nullptr),
	_surface(nullptr),
	vinola(300,500,0,0),
	mapIndex(0),
	changeMap(0),
	mapaseneljuego(2),
	cameraRect{0,0,0,0},
	levelWidth(0),
	levelHeight(0),
	isPaused(false)
{
	initSystems(initFlags);
	keys[0] = SDL_SCANCODE_P;
	keys[1] = SDL_SCANCODE_M;

}


MainGame::~MainGame()
{
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderTarget);
	SDL_DestroyTexture(_player);
	SDL_DestroyTexture(_map);
	SDL_Quit();
}

void MainGame::initSystems(int initFlags)
{
	SDL_Init(initFlags);

	_window = SDL_CreateWindow("Alien triste",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		_screenWidth, _screenHeight,
		SDL_WINDOW_OPENGL);


	if (_window == nullptr)
		fatalError("SDL WINDOW COULD NOT BE CREATED!");

	_renderTarget = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (_renderTarget == nullptr)
		fatalError("PROBLEMA AL INICIALIZAR EL RENDER!");



}

void MainGame::runGame()
{
	drawIntro();
	while (_gameState != GameState::EXIT )
	{
		drawGame(); 
		gameLoop();
		_alien.resetPos(_alien);
	}
	
}
void MainGame::gameLoop()
{ 
	prevMapIndex = mapIndex;
	changeMap = false;
	_alien.SetTextureSize(_player);
	vinola.SetTextureSize(_vino);
	SDL_QueryTexture(_map, NULL, NULL, &levelWidth, &levelHeight);
	cameraRect.w = 800;
	cameraRect.h = 450;
	while (_gameState != GameState::EXIT && !changeMap)  
	{   
		if(!changeMap)
		{
			
			cameraRect.x = _alien.GetOriginX() - 400; // ???
			cameraRect.y = _alien.GetOriginY() - 275; // ??? de donde sale esto

			if (cameraRect.x < 0)
				cameraRect.x = 0;

			if (cameraRect.y < 0)
				cameraRect.y = 0;

			if (cameraRect.x + cameraRect.w >= (levelWidth))
				cameraRect.x = levelWidth - 800;
			if (cameraRect.y + cameraRect.h >= (levelHeight))
				cameraRect.y = levelHeight - 450;
			_prevTime = _currentTime;
			_currentTime = SDL_GetTicks();
			_delta = (_currentTime - _prevTime) / 1000.0f;
			_elapsedTime = _delta;
			processInput();
			_keyState = SDL_GetKeyboardState(NULL);
			if (!isPaused)
			{
				_alien.Update(_delta, _keyState);
				vinola.Update(_delta);
			}
			SDL_RenderClear(_renderTarget);
			SDL_RenderCopy(_renderTarget, _map, &cameraRect, NULL);
			_alien.Draw(_renderTarget, _player,cameraRect);
			vinola.Draw(_renderTarget, _vino,cameraRect);
			vinola.IntersectsWith(_alien);
			SDL_RenderPresent(_renderTarget);			
			changeMap = _alien.ChangeLevel();
		}		

	}
	if(9 > changeMap > 0)
		mapIndex+= changeMap;
	if (changeMap > 9)
		mapIndex += changeMap-11;
}


void MainGame::processInput()
{
	SDL_Event ev;
	while (SDL_PollEvent(&ev) != 0)
	{
		if (ev.type == SDL_QUIT)
			_gameState = GameState::EXIT;
		if (ev.type == SDL_KEYDOWN && _keyState[keys[0]])
			isPaused = !isPaused;
		//else if (ev.type == sdl_mousemotion)
		//	std::cout << ev.motion.x << " " << ev.motion.y << std::endl;
	}
}
void MainGame::drawGame()
{
	mapaActualM = mapClass.getMapData(mapIndex);
	_map = loadtexture(mapaActualM.mapName, _renderTarget);
	_vino = loadtexture("botella.png", _renderTarget);
	_player = loadtexture("player.png", _renderTarget);
}
void MainGame::drawIntro()
{
	_map = loadtexture("Eiko.png",_renderTarget);
	SDL_RenderClear(_renderTarget);
	SDL_RenderCopy(_renderTarget, _map, NULL, NULL); 
	SDL_RenderPresent(_renderTarget);
	//SDL_Delay(3500);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		printf("ERROR ABRIENDO EL MICSER : %s", Mix_GetError());
	Mix_Music *bgm = nullptr;
	bgm = Mix_LoadMUS("Alien triste.mp3");
	Mix_PlayMusic(bgm, -1);
	_map = loadtexture("Startscreen.png", _renderTarget);
	SDL_QueryTexture(_map, NULL, NULL, &levelWidth, &levelHeight);
	cameraRect.x = levelWidth - 800;
	cameraRect.y = levelHeight - 450;
	vinola.SetTextureSize(_vino);
	_vino = loadtexture("botella.png", _renderTarget);

	cameraRect.w = 800;
	cameraRect.h = 450;

	SDL_RenderClear(_renderTarget);
	SDL_RenderCopy(_renderTarget, _map, NULL, NULL);
	vinola.Draw(_renderTarget, _vino, cameraRect);
	SDL_RenderPresent(_renderTarget);
	SDL_Delay(6500);

}