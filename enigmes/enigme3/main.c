#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

int main (void) 
{
	SDL_Surface *screen; 
	
	SDL_Surface *image;
	
	SDL_Rect dest;


	
	SDL_Init(SDL_INIT_VIDEO); 
		
	screen = SDL_SetVideoMode(120, 120, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Enigme03", NULL);

// integration du son

	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS, 1024);
	Mix_Music *music;
	music = Mix_LoadMUS("soundtrack.mp3");
	Mix_VolumeMusic(100);
	Mix_PlayMusic(music,-1);
	
// insert image background

	image = SDL_LoadBMP("enigme03.bmp");
	dest.x = 0; 
	dest.y = 0; 
	int done =1;
	
//boucle jeu
while (done)
{
    SDL_BlitSurface(image, NULL, screen, &dest);
	SDL_Flip(screen);
    SDL_Event event;
    SDL_WaitEvent(&event);	
	if(event.key.keysym.sym==SDLK_ESCAPE) done=0;
}   
	Mix_FreeMusic(music);
	SDL_FreeSurface(screen);
	SDL_FreeSurface(image);
	SDL_Quit();
	return(0);
}

