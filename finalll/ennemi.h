#ifndef MOMIE_H_INCLUDED
#define MOMIE_H_INCLUDED

typedef struct momie
{
SDL_Surface *image ;
SDL_Rect position ;
}momie ;

void initmomie1(momie *m);
void deplacementmomie(momie *m,int r,int i,SDL_Surface* image);
void affichermomie(momie *m,SDL_Surface *ecran);
int collisionmomie(SDL_Surface* image,momie *m,int d);
SDL_Color GetPixel1 ( SDL_Surface* pSurface , int x , int y);


#endif // MOMIE_H_INCLUDED
