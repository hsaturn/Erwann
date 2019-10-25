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
            
      Sprite(const Sprite&);
      Sprite& operator=(const Sprite&&);
      Sprite(const Sprite&&);
      Sprite& operator=(const Sprite&);
      virtual ~Sprite();
     
 protected:

      friend class SpriteFlyWeightFactory;

   private:
     SDL_Surface* sprite;
};

class SpriteFlyWeightFactory
{
 public:
   static SpriteFlyWeightFactory* instance();
   
   const Sprite& get(const string& bitmap);
   
 private:
   SpriteFlyWeightFactory() = default;
   unordered_map<string, Sprite> sprites;
};



