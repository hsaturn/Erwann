#pragma once
#include <unordered_map>
#include "Coord.h"
#include <SDL2/SDL.h>

using namespace std;

class Sprite
{
   public:
     Sprite(const Sprite&);
     Sprite& operator=(const Sprite&&);
     Sprite(const Sprite&&);
     Sprite& operator=(const Sprite&);
      virtual ~Sprite();
     
 protected:
      Sprite(const string& file);

      void render(const Coord&) const;
      
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



