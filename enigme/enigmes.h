#ifndef ENIGMES_H_INCLUDED
#define ENIGMES_H_INCLUDED
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <time.h>
typedef struct
{
	SDL_Surface *E1,*E2,*E3,*E4,*E5,*try1,*try2,*key;
	SDL_Rect pose;

}enigme;



void init_enigmes(enigme *eni);
void generation_auto(enigme *eni, SDL_Surface *ecran,int *chamb);
void init_resolution(enigme *eni);
void resolution_enigmes(enigme *eni, SDL_Surface *ecran,int *chamb ,SDL_Event event);


#endif // ENIGMES_H_INCLUDED
