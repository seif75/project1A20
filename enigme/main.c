#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "enigmes.h"

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *image = NULL;
    SDL_Event event;
    enigme eni;
    SDL_Rect posbg;
    Mix_Music *music;
    int chamb;
    int done=1;

    posbg.x = 0;
    posbg.y = 0;

    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("background+enigme", NULL);

    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS, 1024);
    music = Mix_LoadMUS("soundtrack.mp3");
    Mix_VolumeMusic(100);
    Mix_PlayMusic(music,-1);

    init_enigmes(&eni);
    image = SDL_LoadBMP("background.bmp");
    
    while (done)
    {
        SDL_BlitSurface(image, NULL, ecran, &posbg);
        SDL_Flip(ecran);
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            done= 0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_0:
                generation_auto(&eni,ecran,&chamb);
                SDL_Flip(ecran);
                break;

            }
            break;
        }
        
    }

    Mix_FreeMusic(music);
    SDL_FreeSurface(ecran);
    SDL_FreeSurface(image);
    SDL_Quit();

    return EXIT_SUCCESS;
}
