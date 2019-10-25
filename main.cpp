#include "Ecran.h"
#include "Sprite.h"

#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
   Ecran& ecran(Ecran::instance());
   
   ecran.listModes();
   
   if (!ecran.initialize(640,480))
   {
      cerr << "Erreur d'init écran" << endl;
      return 1;
   }

   cout << "Ecran correctement initialisé" << endl;
   
   Sprite rond=Sprite("rond.bmp");
   
   Coord position = {0,0};
   Coord vitesse = {1,1};
   
   long i=0;
   while(i++<1000)
   {
      ecran.efface({255,0,0});
      ecran.dessine(rond, position);
      ecran.update();
      
      position = position+vitesse;
      
      SDL_Delay(1);
   }

   return 0;
}
