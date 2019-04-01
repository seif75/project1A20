#ifndef ENIGMES_H_INCLUDED
#define ENIGMES_H_INCLUDED
#include"personage.h"
typedef struct 
{      
	SDL_Rect posQ,posS;

}posenigme;

typedef struct 
{
	SDL_Surface *E1,*E2,*E3,*E4,*E5,*E6,*E7,*E8,*E9,*E10,*try1,*try2,*key;

}enigme;



void init_enigmes(posenigme *pose,enigme *eni );
void generation_auto(posenigme *pose,enigme *eni, SDL_Surface *ecran,int *chamb);
void init_resolution(enigme *eni);
void resolution_enigmes(posenigme *pose,enigme *eni, SDL_Surface *ecran,int *chamb ,SDL_Event event, joueur *j);


#endif // ENIGMES_H_INCLUDED
