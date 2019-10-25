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
      
      int w() const { return surface ? surface->w : 0; }
      int h() const { return surface ? surface->h : 0; }
            
      Sprite(const Sprite&);
      Sprite& operator=(const Sprite&&);
      Sprite(const Sprite&&);
      Sprite& operator=(const Sprite&);
      virtual ~Sprite();
     
 protected:

      friend class SpriteFlyWeightFactory;

   private:
     SDL_Surface* surface;
     
     static unordered_map<string, SDL_Surface*> surfaces;
};
