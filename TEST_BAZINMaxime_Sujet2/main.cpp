#include <iostream>
#include <SDL.h>
#include<SDL_image.h>
#include <stdlib.h>
#include"CVect2D.h"
#include <time.h>

const int LRG = 780;
const int LNG = 1024;


using namespace std;


int main(int argc, char * argv[]) {

		unsigned int frameLimit = SDL_GetTicks() + 16;
		CGameObject Ecran;
		CVect2D position(100.0f, 100.0f);

		Ecran.Running = 1;

		Ecran.InitTexture(&Ecran,LNG,LRG);
		Ecran.InitEcran(&Ecran , SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,LNG,LRG, SDL_WINDOW_SHOWN );

		while (Ecran.Running==1) {
		
		Ecran.Event(&Ecran, &position);
		Ecran.Img(&Ecran,position);

		}

		Ecran.delay(frameLimit);
		frameLimit = SDL_GetTicks() + 16;
		
	
		Ecran.destroy(&Ecran);
		SDL_Quit();

		
		

	system("pause");

	return 0;
}
