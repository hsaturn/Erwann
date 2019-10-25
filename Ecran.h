/* 
 * File:   Ecran.h
 * Author: hsaturn
 *
 * Created on 25 octobre 2019, 12:06
 */
#pragma once
#include <SDL2/SDL.h>
#include "Coord.h"
#include "Sprite.h"

class Couleur
{
 public:
   Couleur(int r, int v, int b);
   Couleur() : Couleur(0,0,0){};
   // Couleur(const char* color);
   // Couleur(const string& color) : Couleur(color.c_str() {}
   operator Uint32() const { return color; }
   
 private:
   Uint32 color;
};

class Ecran
{
   public:
      
      bool initialize(int largeur, int hauteur);
      bool listModes() const;
      
      static Ecran& instance();
      
      bool dessine(const Sprite& , const Coord&);
      void update();
      
      void efface(const Couleur& couleur = {});

      const Couleur& couleur(const string& couleur);
      const Couleur& couleur(int rouge, int vert, int bleu);

      SDL_Surface* surface() { return m_surface; }

   private:
      Ecran();
      ~Ecran();
      Ecran(const Ecran& orig) = delete;

      static SDL_Window* mpWindow;
      static SDL_Surface* m_surface;
      static bool mbInit;
};


