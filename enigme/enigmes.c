#include "enigmes.h"
void init_enigmes(enigme *eni)
{
    eni->pose.x=500;
    eni->pose.y=260;
    eni->E1=SDL_LoadBMP("enigme01.bmp");
    eni->E2= SDL_LoadBMP("enigme02.bmp");
    eni->E3= SDL_LoadBMP("enigme03.bmp");
    eni->E4= SDL_LoadBMP("enigme04.bmp");
    eni->E5=SDL_LoadBMP("enigme05.bmp");
}
void generation_auto(enigme *eni, SDL_Surface *ecran,int *chamb)
{
    srand(time(NULL));
    *chamb=rand()%5;
    switch (*chamb)
    {
    case 0 :
    {
        SDL_BlitSurface(eni->E1, NULL, ecran,&eni->pose);
        SDL_Flip(ecran);
        SDL_Delay(500);
        break;
    }

    case 1 :
    {
        SDL_BlitSurface(eni->E2, NULL, ecran, &eni->pose);
        SDL_Flip(ecran);
        SDL_Delay(500);
        break;
    }

    case 2 :
    {
        SDL_BlitSurface(eni->E3, NULL, ecran, &eni->pose);
        SDL_Flip(ecran);
        SDL_Delay(500);
        break;
    }
    case 3 :
    {
        SDL_BlitSurface(eni->E4, NULL,ecran, &eni->pose);
        SDL_Flip(ecran);
        SDL_Delay(500);
        break;
    }

    case 4 :
    {
        SDL_BlitSurface(eni->E5, NULL, ecran, &eni->pose);
        SDL_Flip(ecran);
        SDL_Delay(500);
        break;
    }
    }
}





void init_resolution(enigme *eni)

{
    eni->key=SDL_LoadBMP("key.bmp");
    eni->try1=SDL_LoadBMP("try1.bmp");
    eni->try2=SDL_LoadBMP("try2.bmp");
}


void resolution_enigmes(enigme *eni, SDL_Surface *ecran,int *chamb,SDL_Event event )
{
    int continuer=1;
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch (*chamb)
        {
        case 0:
        {
            switch(event.type)
            {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_1:SDL_BlitSurface(eni->try1,NULL,ecran,&eni->pose);SDL_Delay(1000);continuer=0;break;
                    //case !SDLK_1
                }

            }
        }
        }
    }
}
