/* 
 * File:   Sprite.cpp
 * Author: hsaturn
 * 
 * Created on 24 octobre 2019, 13:43
 */

#include "Sprite.h"
#include "RsrcFinder.h"

Sprite::Sprite(const string& file)
{
   string resolved = RsrcFinder::findFile(file);
   if (resolved.length()==0)
      sprite = nullptr;
   else
      sprite = SDL_LoadBMP(resolved.c_str());
}

 Sprite::Sprite(const Sprite& s)
   : sprite(s.sprite)
{

}

Sprite::Sprite(const Sprite&& s)
   : sprite(s.sprite)
{}

Sprite& Sprite::operator=(const Sprite& s)
{
   Sprite* sprite=new Sprite(s);
   return *sprite;
}
Sprite& Sprite::operator=(const Sprite&& s)
{
   Sprite* sprite=new Sprite(s);
   return *sprite;
}

Sprite::~Sprite()
{
   if (sprite) SDL_FreeSurface(sprite);
}

SpriteFlyWeightFactory* SpriteFlyWeightFactory::instance()
{
   static SpriteFlyWeightFactory instance;
   return &instance;
}

const Sprite& SpriteFlyWeightFactory::get(const string &bitmap)
{
   auto it=sprites.find(bitmap);
   if (it != sprites.end())
      return it->second;
      
   auto [iter, ins] = sprites.try_emplace(bitmap, Sprite(bitmap));
   return iter->second;
}


