#include "CVect2D.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include<math.h>
#include <SDL.h>
#include<SDL_image.h>



CVect2D::CVect2D(float fltX, float fltY)
{
	m_fltX = fltX;
	m_fltY = fltY;
}



CGameObject::CGameObject()
{
}

void CGameObject::InitTexture(CGameObject * Ecran, int width, int height)
{
	Ecran->texture= SDL_CreateTexture(Ecran->rendu, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);

}

void CGameObject::InitEcran(CGameObject *Ecran, int xpos, int ypos, int width, int height, int flags)
{

	 Ecran ->ecran=SDL_CreateWindow("SDL", xpos, ypos, width, height, flags);
	 SDL_Delay(60000);
	 destroy(Ecran);

}

void CGameObject::Img(CGameObject *Ecran, CVect2D pos)
{
	
	SDL_Rect PositionImg;

	Ecran->surface = SDL_CreateRGBSurface(0, 100, 400, 32, 0, 0, 0, 0);

	SDL_Texture *texture_tampon = SDL_CreateTextureFromSurface(Ecran->rendu,Ecran->surface);
	SDL_SetRenderTarget(Ecran->rendu, texture_tampon);

	PositionImg.x = pos.m_fltX;
	PositionImg.y = pos.m_fltY;

	switch (Ecran->etat)
	{
	case 1: Ecran->surface = SDL_LoadBMP("Img1.bmp"); break;
	case 2: Ecran->surface = SDL_LoadBMP("Img2.bmp"); break;
	case 3: Ecran->surface = SDL_LoadBMP("Img3.bmp"); break;
	case 4: Ecran->surface = SDL_LoadBMP("Img4.bmp"); break;
	case 5: Ecran->surface = SDL_LoadBMP("Img5.bmp"); break;

	default:Ecran->surface = SDL_LoadBMP("Img1.bmp"); break;
	}

	SDL_BlitSurface(Ecran->surface,NULL,Ecran->surface,&PositionImg);
	SDL_QueryTexture(texture_tampon, NULL, NULL, &PositionImg.w, &PositionImg.h);
	SDL_RenderCopy(Ecran->rendu, texture_tampon, NULL, &PositionImg);
	SDL_RenderPresent(Ecran->rendu);
	
	
}

void CGameObject::Event(CGameObject * Ecran, CVect2D* pos)
{
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_LEFT:  pos->m_fltX--;
				if (Ecran->sens==1)
				{
					//SDL_Flip(Ecran->surface);
					Ecran->sens = 2;
				}
				break;
			case SDLK_RIGHT: pos->m_fltX++;
				if (Ecran->sens == 2)
				{
					//SDL_Flip(Ecran->surface);							
					Ecran->sens = 1;
				}
				break;
			case SDLK_UP:    pos->m_fltY--;
				break;
			case SDLK_DOWN:  pos->m_fltY++;
				break;
			
			}
			break;
		case SDL_KEYUP:; break;
		default:break;

		}
		if (Ecran->etat != 5)
		{
			Ecran->etat++;
		}
		else
		{
			Ecran->etat = 1;
		}
	}
}

void CGameObject::delay(unsigned int frameLimit)
{
	unsigned int ticks = SDL_GetTicks();

	if (frameLimit < ticks)
	{
		return;
	}

	if (frameLimit > ticks + 16)
	{
		SDL_Delay(16);
	}

	else
	{
		SDL_Delay(frameLimit - ticks);
	}
}

void CGameObject::destroy(CGameObject * Ecran)
{
	
	if (Ecran->rendu != NULL)
		SDL_DestroyRenderer(Ecran->rendu);


	if (Ecran->texture != NULL)
		SDL_DestroyTexture(Ecran->texture);

	
	if (Ecran->surface != NULL)
		SDL_FreeSurface(Ecran->surface);

	
	if (Ecran->ecran != NULL)
		SDL_DestroyWindow(Ecran->ecran);
}

