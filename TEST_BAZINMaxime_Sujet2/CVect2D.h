#pragma once
#include <SDL.h>
#include<SDL_image.h>

class CVect2D
{
public:

	
	
	CVect2D(float fltX,float fltY);
	
	
	float m_fltX;
	float m_fltY;

private:

	
};

class CGameObject
{
public:

	CGameObject();

	SDL_Window *ecran;
	SDL_Renderer *rendu;
	SDL_Texture *texture;
	SDL_Surface *surface;
	int Running;
	int etat=1,sens=1;
	


	unsigned int frameLimit = SDL_GetTicks() + 16;
	
	void InitTexture(CGameObject *Ecran, int width, int height);
	void InitEcran(CGameObject *Ecran, int xpos, int ypos, int width, int height, int flags);
	void Img(CGameObject *Ecran, CVect2D pos);
	void Event(CGameObject *Ecran, CVect2D* pos);
	void delay(unsigned int frameLimit);
	void destroy(CGameObject *Ecran);

private:

};






