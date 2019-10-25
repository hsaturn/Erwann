#pragma once
#include <unordered_map>
#include "Coord.h"
#include <SDL2/SDL.h>

using namespace std;

class Sprite
{
   public:
      Sprite(const string& file);
      bool render(const Coord&, SDL_Surface*) const;
      
      int w() const { return sprite ? sprite->w : 0; }
      int h() const { return sprite ? sprite->h : 0; }
     
   private:
     SDL_Surface* sprite;
     static unordered_map<string, SDL_Surface*>  surfaces;
};

