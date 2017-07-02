#include "Player.h"
#include <SDL_image.h>
#include <iostream>
#include <cmath>





Player::Player(int x, int y, int framesX, int framesY) :  //EXTENDER PLAYER DESDE ENTIDAD, USAR UNA ESTRUCTURA PARA DEFINIR PARAMETROS
	nivel(0),
	changeLevel(false),
	prevNivel(0),
	isPaused(false),
	isJumping(false),
	isFalling(false),
	jump(0)
{
	//_alien = loadtexture("player.png", _renderTargetP); //RENDER ES NULL PORQUE PLAYER SE CREA ANTES DE QUE MAINGAME ENTRE EN SU CONSTRUCTOR
	//SDL_QueryTexture(_alien,NULL, NULL, &playerCrop.w, &playerCrop.h);


	positionRect.x = x;
	positionRect.y = y;
	//textureWidth = playerCrop.w; VIEJO

	
	mapaActual = mapClass.getMapData(nivel);
	
	
	isActive = false;
	
	static int playerNumber = 0;
	playerNumber++;
	
	
	if (playerNumber == 1) {
		keys[0] = SDL_SCANCODE_W;
		keys[1] = SDL_SCANCODE_S;
		keys[2] = SDL_SCANCODE_A;
		keys[3] = SDL_SCANCODE_D;
		keys[4] = SDL_SCANCODE_SPACE;
		keys[5] = SDL_SCANCODE_P;
	}
	else
	{
		keys[0] = SDL_SCANCODE_UP;
		keys[1] = SDL_SCANCODE_DOWN;
		keys[2] = SDL_SCANCODE_LEFT;
		keys[3] = SDL_SCANCODE_RIGHT;
		keys[4] = SDL_SCANCODE_SPACE;
	}
	moveSpeed = 197.0f;    // 197.0f al 4/11
	jumpHeight = 21;
	
}


Player::~Player()
{
	SDL_DestroyTexture(texture);

}
void Player::resetPos(Player &p)
{
	if (changeLevel < 9)
	{
		p.positionRect.x = 0;
		p.positionRect.y = 400;
	}
	if (changeLevel > 9)
	{
		p.positionRect.x = 1400;
		p.positionRect.y = 400;
	}
	
}
void Player::Update(float delta, const Uint8 *keyState)
{
	
	if(changeLevel != 0)
	mapaActual = mapClass.getMapData(nivel);
	
	


//	if (!isPaused) {
		prevNivel = nivel;
		isActive = true;
		changeLevel = 0;


		if (keyState[keys[0]] && positionRect.y >= mapaActual.posicion.arriba)/* mapObj.mapasjuegoV[nivel].posicion.arriba*/
		{
			if(!isJumping)
				positionRect.y -= moveSpeed * delta; //AGREGAR CHOQUE CONTRA LIMITES ACA
			else
				positionRect.y -= (moveSpeed-50) * delta;
		  //positionRect.x += moveSpeed * delta; para implementar movimiento diagonal
			playerCrop.y = 0;//playerCrop.y = frameHeight * 3;
		}

		 if (keyState[keys[1]] && positionRect.y <= mapaActual.posicion.abajo) /* MainGame::mapObj.mapasjuegoV[nivel].posicion.abajo*/
		{
			positionRect.y += moveSpeed * delta;
		  //positionRect.x -= moveSpeed * delta; para implementar movimiento diagonal
			playerCrop.y = 0;
		}

		 if (keyState[keys[2]] && positionRect.x >= mapaActual.posicion.izq)
		{
			positionRect.x -= moveSpeed * delta;										        // LA ANIMACION SE REALIZA, PERO NO SE MUEVE!! DEFINIR CUAL SE USA!!
			playerCrop.y = frameHeight;															// EXTENDIENDO EL COMENTARIO PAR QUE SE VEAAAAAAAAAAAAAAAAAAAAAAAAAA
																							// AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
		}																						// AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

		 if (keyState[keys[3]] && positionRect.x < mapaActual.posicion.der)					/*MainGame::mapObj.mapasjuegoV[nivel].posicion.der*/
		{

			positionRect.x += moveSpeed * delta;
			playerCrop.y = 0;																	//playerCrop.y = frameHeight * 2; que es esto??
		}

		if (keyState[keys[4]])
		{
			isActive = true;
			isJumping = true;
		}

		else if (positionRect.x >= mapaActual.posicion.der && keyState[keys[3]])//CAMBIO DE MAPA
		{
			changeLevel = 1;
		}

		else if (positionRect.x <= mapaActual.posicion.izq + 50 && keyState[keys[2]] && mapaActual.Indice >= 1) //CAMBIO DE MAPA
		{
			changeLevel = 10;
		}

		if(keyState[keys[0]] == NULL && keyState[keys[1]] == NULL && keyState[keys[2]] == NULL && keyState[keys[3]] == NULL)
			isActive = false;


		if (isActive)
		{
			frameCounter += delta;
			if (frameCounter >= 0.10f)  // 0.10F NO TOCARRRRR
			{
				frameCounter = 0;
				playerCrop.x += frameWidth;
				if (playerCrop.x >= textureWidth)
					playerCrop.x = 0;
			}
		}
		else
		{
			frameCounter = 0;
			playerCrop.x = frameWidth;
		}
		if (9 > changeLevel > 0)
			nivel += changeLevel;
		if (changeLevel > 9)
			nivel -= 1;
		if (isJumping == true)
		{
			if (jump == 0 && isFalling == true)
			{
				isFalling = false;
				isJumping = false;
			}
			else if (jump >= jumpHeight-5 || isFalling == true)
			{
				jump--;
				positionRect.y+=9;
				isFalling = true;
			}
			else if (jump < jumpHeight)
			{
				jump++;
				positionRect.y-=9;
			}
		}

}


void Player::Draw(SDL_Renderer *_renderTarget, SDL_Texture *_alien, SDL_Rect cameraRect)
{       

	SDL_Rect drawingRect = { positionRect.x-cameraRect.x, positionRect.y-cameraRect.y, positionRect.w, positionRect.h };
	SDL_RenderCopy(_renderTarget, _alien, &playerCrop, &drawingRect);
}


bool Player::IntersectsWith(Player &p)
{
	if (sqrt(pow(GetOriginX() - p.GetOriginX(), 2) + pow(GetOriginY() - p.GetOriginY(), 2)) >= radius + p.GetRadius()) //pitagoras para sacar la distancia
	{
		SDL_SetTextureColorMod(texture, 255, 255, 255);

	}
	else {
		positionRect.x = rand() % 750;
		positionRect.y = rand() % 500;
	}
	return false;
}
int Player::GetOriginX() { return positionRect.x + originX; }
int Player::GetOriginY() { return positionRect.y + originY; }
int Player::GetRadius() { return radius; }
int Player::ChangeLevel() { return changeLevel; }

void Player::SetTextureSize(SDL_Texture *_alien)
{
	SDL_QueryTexture(_alien, NULL, NULL, &playerCrop.w, &playerCrop.h);
	textureWidth = playerCrop.w;
	playerCrop.w /= 3;
	playerCrop.h /= 2;
	frameWidth = playerCrop.w;			 //getCrop()   setPoss()?
	positionRect.w = playerCrop.w * 2;
	frameHeight = playerCrop.h;
	positionRect.h = playerCrop.h * 2;
	radius = frameWidth / 5;
	originX = frameWidth / 2;
	originY = frameHeight / 2;
}


// crear funciones basicas, como radius para una clase entidad que extienda player, coin ... 
/* Interseccion a través de la deteccion de colision de rectangulos contenedores
*bool Player::IntersectsWith(Player &p)
*{
*	if (positionRect.x + positionRect.w < p.positionRect.x || positionRect.x > p.positionRect.x + p.positionRect.w ||
*		positionRect.y + positionRect.h < p.positionRect.y || positionRect.y > p.positionRect.y + p.positionRect.h)
*	{
*		SDL_SetTextureColorMod(texture, 255, 255, 255);
*		return true;
*	}
*	else
*		SDL_SetTextureColorMod(texture, 0, 0, 0);
*	return false;
*
*}
*/