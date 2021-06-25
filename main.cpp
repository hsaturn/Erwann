#include "Ecran.h"
#include "Sprite.h"
#include <Sound.h>

#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
   Ecran& ecran(Ecran::instance());

   ecran.listModes();

   ecran.initialize(320,200);

   cout << "Ecran correctement initialisé !" << endl;

   Sprite rond = Sprite("rond.png");
   Sound toc("toc.ogg");

   Coord position = {250,0};
   Coord vitesse = {1,1};

   while(true)
   {
      ecran.efface({255,0,0});
      ecran.dessine(rond, position);
      ecran.update();

      if (position.x > ecran.largeur())
      {
         if (vitesse.x > 0) toc.play();
         vitesse.x = -1;
      }

      if (position.x < 0)
      {
         if (vitesse.x < 0) toc.play();
         vitesse.x = 1;
      }

      if (position.y > ecran.hauteur())
      {
         if (vitesse.y > 0) toc.play();
         vitesse.y = -1;
      }

      if (position.y < 0)
      {
         if (vitesse.y < 0) toc.play();
         vitesse.y = 1;
      }

      position = position+vitesse;

      SDL_Delay(1);
   }

   return 0;
}
