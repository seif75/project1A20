#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "momie.h"

SDL_Color GetPixel1 ( SDL_Surface* pSurface , int x , int y)
{
 SDL_Color color;
 Uint32 col = 0;
 char *pPosition = (char *) pSurface ->pixels;
 pPosition += (pSurface ->pitch * y);
 pPosition += (pSurface->format->BytesPerPixel * x);
 memcpy (&col ,pPosition , pSurface->format->BytesPerPixel);
 SDL_GetRGB(col ,pSurface->format , &color.r , &color.g , &color.b);
 return (color) ;
}


int collisionmomie(SDL_Surface* image,momie *m,int d)
{
SDL_Color p;
float X,Y;
switch (d)
  {
   case 0 :
     X= m->position.x +16.4;
     Y= m->position.y +9.6;
     break;
   case 1 :
     X= m->position.x +16.4;
     Y= m->position.y -9.6;
     break;
   case 3 :
     X= m->position.x -16.4;
     Y= m->position.y -9.6;
     break;
   case 2 :
     X= m->position.x -16.4;
     Y= m->position.y +9.6;
     break;
  }
X+=266;
p=GetPixel1 (image,X,Y);
if (((p.r==255)&&(p.b==255)&&(p.g==255))||((p.r==255)&&(p.b==0)&&(p.g==0)))
	return 1;
else
	return 0;
}


void initmomie1(momie *m)
{

    m->position.x =2141 ;
    m->position.y =670 ;
    m->image = IMG_Load("image/move-1.png");
}
 void deplacementmomie(momie *m,int r,int i,SDL_Surface* image)
{
    int c=0;
    c=collisionmomie(image,m,r);
        if ((r==0)&&(c==0))
			{

				m->position.x +=8;
				m->position.y +=4.6;
                                  switch (i)
                                    {
                                       case 1:
                                         m->image= IMG_Load("image/move-1.png");
                                         break;
                                       case 2:
                                         m->image= IMG_Load("image/move-2.png");
                                         break;
                                       case 3:
                                         m->image= IMG_Load("image/move-3.png");
                                         break;
                                       case 4:
                                         m->image= IMG_Load("image/move-4.png");
                                         break;
                                       case 5:
                                         m->image= IMG_Load("image/move-5.png");
                                         break;
                                     }

	     }else  if ((r==1)&&(c==0))
			{
				m->position.x +=8;
				m->position.y -=4.6;
                                  switch (i)
                                    {
                                       case 1:
                                         m->image= IMG_Load("image/Rmove-5.png");
                                         break;
                                       case 2:
                                         m->image= IMG_Load("image/Rmove-4.png");
                                         break;
                                       case 3:
                                         m->image= IMG_Load("image/Rmove-3.png");
                                         break;
                                       case 4:
                                         m->image= IMG_Load("image/Rmove-2.png");
                                         break;
                                       case 5:
                                         m->image= IMG_Load("image/Rmove-1.png");
                                         break;
                                     }
            }else  if ((r==3)&&(c==0))
			{

				m->position.x -=8;
				m->position.y -=4.6;
                                  switch (i)
                                    {
                                       case 1:
                                         m->image= IMG_Load("image/move-5.png");
                                         break;
                                       case 2:
                                         m->image= IMG_Load("image/move-4.png");
                                         break;
                                       case 3:
                                         m->image= IMG_Load("image/move-3.png");
                                         break;
                                       case 4:
                                         m->image= IMG_Load("image/move-2.png");
                                         break;
                                       case 5:
                                         m->image= IMG_Load("image/move-1.png");
                                         break;
                                     }

            }else  if ((r==2)&&(c==0))
			{
				m->position.x -=8;
				m->position.y +=4.6;
                                  switch (i)
                                    {
                                       case 1:
                                         m->image= IMG_Load("image/Rmove-1.png");
                                         break;
                                       case 2:
                                         m->image= IMG_Load("image/Rmove-2.png");
                                         break;
                                       case 3:
                                         m->image= IMG_Load("image/Rmove-3.png");
                                         break;
                                       case 4:
                                         m->image= IMG_Load("image/Rmove-4.png");
                                         break;
                                       case 5:
                                         m->image= IMG_Load("image/Rmove-5.png");
                                         break;
                                     }

 }}
void affichermomie(momie *m,SDL_Surface *ecran)
{
 SDL_BlitSurface(m->image, NULL, ecran, &m->position);
}
