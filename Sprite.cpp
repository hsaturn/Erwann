/* 
 * File:   Sprite.cpp
 * Author: hsaturn
 * 
 * Created on 24 octobre 2019, 13:43
 */

#include <SDL2/SDL_image.h>
#include "Sprite.h"
#include "Ecran.h"
#include "RsrcFinder.h"
#include <iostream>

using namespace std;

unordered_map<string, SDL_Surface*> Sprite::surfaces;


bool Sprite::render(const Coord& coord, SDL_Surface* surface) const
{
   if (surface == nullptr) return false;
   
   SDL_Rect dest = { coord.x-w()/2, coord.y-h()/2, 0, 0};
   
   SDL_BlitSurface(sprite,NULL,surface,&dest);
   
   return true;
}

Sprite::Sprite(const string& file)
{
   string resolved = RsrcFinder::findFile(file);
   if (resolved.length()==0)
   {
      sprite = nullptr;
      cerr << "Impossible de trouver le fichier [" << file << "]" << endl;
      return;
   }
   
   auto it = surfaces.find(resolved);
   
   if (it == surfaces.end())
   {
      sprite = IMG_Load(resolved.c_str());

      if (sprite)
      {
         cout << "Image [" << file << "] chargée" << endl;
      }
      else
      {
         cerr << "Impossible de charger l'image " << file << endl;
      }
      surfaces[resolved] = sprite;
   }
   else
   {
      sprite = it->second;
      cout << "Reusing " << resolved << endl;
   }
}

