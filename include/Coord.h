/*
 * File:   Coord.h
 * Author: hsaturn
 *
 * Created on 24 octobre 2019, 14:09
 */
#pragma once

#include <SDL2/SDL.h>

struct Coord
{
   public:
      using type=int;

      Coord(type _x , type _y) : x(_x), y(_y) {}

      Coord operator +(const Coord& coord)
      {
         x += coord.x;
         y += coord.y;
         return *this;
      }

      Coord operator -(const Coord& coord)
      {
         x -= coord.x;
         y -= coord.y;
         return *this;
      }

      type x;
      type y;
};
