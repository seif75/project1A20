#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enigmes.h"
#include <stdlib.h>
#include "personage.h"


void init_enigmes(posenigme *pose,enigme *eni )
{
    pose->posS.x=50;
    pose->posS.y=50;
    pose->posQ.x = 0;
    pose->posQ.y = 0;
    eni->E1= IMG_Load("enigm/1.png");
    eni->E2= IMG_Load("enigm/2.png");
    eni->E3= IMG_Load("enigm/3.png");
    eni->E4= IMG_Load("enigm/4.png");
    eni->E5= IMG_Load("enigm/5.png");
    eni->E6= IMG_Load("enigm/6.png");
    eni->E7= IMG_Load("enigm/7.png");
    eni->E8= IMG_Load("enigm/8.png");
    eni->E9= IMG_Load("enigm/9.png");
    eni->E10= IMG_Load("enigm/10.png");
}

void generation_auto(posenigme *pose,enigme *eni, SDL_Surface *ecran,int *chamb)
{
    srand(time(NULL));
    *chamb=rand()%10;
    switch (*chamb)
    {
    case 0 :
    {
        SDL_BlitSurface(eni->E1, NULL, ecran,&pose->posQ);
        SDL_Flip(ecran);
        SDL_Delay(500);
        break;
    }

    case 1 :
    {
        SDL_BlitSurface(eni->E2, NULL, ecran, &pose->posQ);
        SDL_Flip(ecran);
        SDL_Delay(500);
        break;
    }

    case 2 :
    {
        SDL_BlitSurface(eni->E3, NULL, ecran, &pose->posQ);
        SDL_Flip(ecran);
        SDL_Delay(500);
        break;
    }
    case 3 :
    {
        SDL_BlitSurface(eni->E4, NULL, ecran, &pose->posQ);
        SDL_Flip(ecran);
        SDL_Delay(500);
        break;
    }

    case 4 :
    {
        SDL_BlitSurface(eni->E5, NULL, ecran, &pose->posQ);
        SDL_Flip(ecran);
        SDL_Delay(500);
        break;
    }

    case 5 :
    {
        SDL_BlitSurface(eni->E6, NULL, ecran, &pose->posQ);
        SDL_Flip(ecran);
        SDL_Delay(500);
        break;
    }


    case 6 :
    {
        SDL_BlitSurface(eni->E7, NULL, ecran, &pose->posQ);
        SDL_Flip(ecran);
        SDL_Delay(500);
        break;
    }

    case 7 :
    {
        SDL_BlitSurface(eni->E8, NULL, ecran, &pose->posQ);
        SDL_Flip(ecran);
        SDL_Delay(500);
        break;
    }
    case 8 :
    {
        SDL_BlitSurface(eni->E9, NULL, ecran, &pose->posQ);
        SDL_Flip(ecran);
        SDL_Delay(500);
        break;
    }
    case 9 :
    {
        SDL_BlitSurface(eni->E10, NULL, ecran, &pose->posQ);
        SDL_Flip(ecran);
        SDL_Delay(500);
        break;
    }

    }
}



void init_resolution(enigme *eni)

{
    eni->key= IMG_Load("enigm/key.png");
    eni->try1= IMG_Load("enigm/try.png");
    eni->try2= IMG_Load("enigm/try2.png");
}


void resolution_enigmes(posenigme *pose,enigme *eni, SDL_Surface *ecran,int *chamb,SDL_Event event ,joueur *j)
{
    int continuer=1;

    while (continuer)
    { 
        SDL_PollEvent(&event);
        switch (*chamb)
        {
        /******************/
        case 0:
        {
            switch(event.type)
            {

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if(event.button.x>0 && event.button.x<=400 && event.button.y>=620 && event.button.y <=700)
                    {
                        SDL_BlitSurface(eni->key, NULL, ecran, &pose->posS);
                        SDL_Flip(ecran);SDL_Delay(500);

                      continuer=0;j->inv=1;j->inv=1;
                        break;

                    }

                    else if(event.button.x>1200 && event.button.x<=1428&& event.button.y>=620 && event.button.y <=700)
                    {
                        SDL_BlitSurface(eni->try1, NULL, ecran, &pose->posS);
                        SDL_Flip(ecran);SDL_Delay(500);continuer=0;
                        break;
                    }
                }
                break;
            }
            break;
        }
        /*********************/

        case 1:
        {
            switch(event.type)
            {

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if(event.button.x>0 && event.button.x<=400 && event.button.y>=620 && event.button.y <=700)
                    {
                        SDL_BlitSurface(eni->key, NULL, ecran, &pose->posS);
                       
                     
                         SDL_Flip(ecran);SDL_Delay(500);j->inv=1; continuer=0;
                        break;
                    }

                    else if(event.button.x>1200 && event.button.x<=1428&& event.button.y>=620 && event.button.y <=700)
                    {
                        SDL_BlitSurface(eni->try1, NULL, ecran, &pose->posS);
                         SDL_Flip(ecran);SDL_Delay(500);continuer=0;
                        break;
                    }
                }
                break;
            }
            break;
        }

        /********************************/
        case 2:
        {
            switch(event.type)
            {

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if(event.button.x>0 && event.button.x<=400 && event.button.y>=620 && event.button.y <=700)
                    {
                        SDL_BlitSurface(eni->try1, NULL, ecran, &pose->posS);
                         SDL_Flip(ecran);SDL_Delay(500);continuer=0;
                        
                        break;
                    }


                   else if(event.button.x>1200 && event.button.x<=1428&& event.button.y>=620 && event.button.y <=700)
                    {
                        SDL_BlitSurface(eni->key, NULL, ecran, &pose->posS);
                         SDL_Flip(ecran);SDL_Delay(500);
                      continuer=0;j->inv=1;
                       
                        break;
                    }
                }
                break;
            }
           break;
        }
        /*****************************/

        case 3:
        {
            switch(event.type)
            {

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if(event.button.x>0 && event.button.x<=400 && event.button.y>=620 && event.button.y <=700)
                    {
                        SDL_BlitSurface(eni->try1, NULL, ecran, &pose->posS);
                        SDL_Flip(ecran);SDL_Delay(500);continuer=0;
                        break;
                    }


                    else if(event.button.x>1200 && event.button.x<=1428&& event.button.y>=620 && event.button.y <=700)
                    {
                        SDL_BlitSurface(eni->key, NULL, ecran, &pose->posQ);
                         SDL_Flip(ecran);SDL_Delay(500);
                      continuer=0;j->inv=1;
                        
                        break;
                    }
                }
                break;
            }
             break;
        }
        /*****************************/
        case 4:
        {
            switch(event.type)
            {

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if(event.button.x>0 && event.button.x<=400 && event.button.y>=620 && event.button.y <=700)
                    {
                        SDL_BlitSurface(eni->try1, NULL, ecran, &pose->posS);
                       SDL_Flip(ecran);SDL_Delay(500);continuer=0;
                        break;
                    }


                   else if(event.button.x>1200 && event.button.x<=1428&& event.button.y>=620 && event.button.y <=700)
                    {
                        SDL_BlitSurface(eni->key, NULL, ecran, &pose->posS);
                        SDL_Flip(ecran);SDL_Delay(500);
                      continuer=0;j->inv=1;
                        
                        break;
                    }
                }
                break;
            }
          break;
        }
        /*****************************/

        case 5:
        {
            switch(event.type)
            {

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if(event.button.x>0 && event.button.x<=400 && event.button.y>=620 && event.button.y <=700)
                    {
                        SDL_BlitSurface(eni->key, NULL, ecran, &pose->posS);
                       SDL_Flip(ecran);SDL_Delay(500);
                      continuer=0;j->inv=1;
                        
                        break;
                    }

                    else if(event.button.x>1200 && event.button.x<=1428&& event.button.y>=620 && event.button.y <=700)
                    {
                        SDL_BlitSurface(eni->try1, NULL, ecran, &pose->posS);
                        SDL_Flip(ecran);SDL_Delay(500);continuer=0;
                        break;
                    }
                }
                break;
            }
            break;
        }
        /*********************/

        case 6:
        {
            switch(event.type)
            {

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if(event.button.x>0 && event.button.x<=400 && event.button.y>=620 && event.button.y <=700)
                    {
                        SDL_BlitSurface(eni->key, NULL, ecran, &pose->posS);
                        SDL_Flip(ecran);SDL_Delay(500);
                      continuer=0;j->inv=1;
                     
                        break;
                    }

                   else if(event.button.x>1200 && event.button.x<=1428 && event.button.y>=620 && event.button.y <=700)
                    {
                        SDL_BlitSurface(eni->try1, NULL, ecran, &pose->posS);
                        SDL_Flip(ecran);SDL_Delay(500);continuer=0;
                        break;
                    }
                }
                break;
            }
          break;
        }
        /*********************/
        case 7:
        {
            switch(event.type)
            {

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if(event.button.x>0 && event.button.x<=400 && event.button.y>=620 && event.button.y <=700)
                    {
                        SDL_BlitSurface(eni->try1, NULL, ecran, &pose->posS);
                         SDL_Flip(ecran);SDL_Delay(500);continuer=0;
                        break;
                    }


                    else if(event.button.x>1200 && event.button.x<=1428&& event.button.y>=620 && event.button.y <=700)
                    {
                        SDL_BlitSurface(eni->key, NULL, ecran, &pose->posS);
                        SDL_Flip(ecran);SDL_Delay(500); 
                      continuer=0;j->inv=1;
                       
                        break;
                    }
                }
                break;
            }
          break;
        }
        /*****************************/
        case 8:
        {
            switch(event.type)
            {

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if(event.button.x>0 && event.button.x<=400 && event.button.y>=620 && event.button.y <=700)
                    {
                        SDL_BlitSurface(eni->key, NULL, ecran, &pose->posS);
                         SDL_Flip(ecran);SDL_Delay(500);
                      continuer=0;j->inv=1;
                       
                        break;
                    }

                   else if(event.button.x>1200 && event.button.x<=1428&& event.button.y>=620 && event.button.y <=700)
                    {
                        SDL_BlitSurface(eni->try1, NULL, ecran, &pose->posS);
                        SDL_Flip(ecran);SDL_Delay(500);continuer=0;
                       
                        break;
                    }
                }
                break;
            }
         break;
        }
        /*********************/
        case 9:
        {
            switch(event.type)
            {

            case SDL_MOUSEBUTTONDOWN:
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if(event.button.x>0 && event.button.x<=400 && event.button.y>=620 && event.button.y <=700)
                    {
                        SDL_BlitSurface(eni->try1, NULL, ecran, &pose->posS);
                       
                         SDL_Flip(ecran);SDL_Delay(500);continuer=0;
                        break;
                    }


                   else if(event.button.x>1200 && event.button.x<=1428&& event.button.y>=620 && event.button.y <=700)
                    {
                        SDL_BlitSurface(eni->key, NULL, ecran, &pose->posS);
                        SDL_Flip(ecran);SDL_Delay(500);
                      continuer=0;j->inv=1;
                        
                    }
                }
                break;
            }
         break;
            }
            /*****************************/



        }
        }
   } }


