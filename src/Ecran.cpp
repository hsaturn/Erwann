/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Ecran.cpp
 * Author: hsaturn
 *
 * Created on 25 octobre 2019, 12:06
 */

#include "Ecran.h"
#include <iostream>

using namespace std;

SDL_Window*    Ecran::mpWindow{};
SDL_Surface*   Ecran::m_surface{};
bool Ecran::mbInit(false);

Ecran::Ecran()
{
   if (mbInit == false)
   {
      mbInit = true;

      if (SDL_Init(SDL_INIT_VIDEO) != 0 )
      {
         cerr << "Échec de l'initialisation de la SDL : " << SDL_GetError() << endl;
      }
   }
}

Ecran& Ecran::instance()
{
   static Ecran ecran;
   return ecran;
}



bool Ecran::initialize(int largeur, int hauteur)
{
   if (mpWindow == nullptr)
   {
      /* Création de la fenêtre */
      mpWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                  SDL_WINDOWPOS_UNDEFINED,
                  largeur,
                  hauteur,
                  SDL_WINDOW_SHOWN);

   }
   if (mpWindow)
   {
      m_surface = SDL_GetWindowSurface(mpWindow);
      return true;
   }
   else
   {
       cerr << "Erreur de création de la fenêtre: " << SDL_GetError() << endl;
   }
   return false;
}

bool Ecran::listModes() const
{
	int n = SDL_GetNumDisplayModes(0);
	if (n < 0)
   {
		cerr << "Unable to get number of video modes" << endl;
      return false;
   }
	else
	{
		SDL_DisplayMode mode;
		for(int i=0; i<n; i++)
		{
			auto error = SDL_GetDisplayMode(0,i,&mode);
			if (error < 0)
         {
				cerr << "  Cannot get display mode " << i << " " << error << endl;
         }
			else
			{
				cout << "Video mode [" << i << "] " << mode.w << "x" << mode.h << endl;
			}
		}
	}
   return true;
}

bool Ecran::dessine(const Sprite& sprite, const Coord& coord)
{
   return sprite.render(coord, m_surface);
}

Ecran::~Ecran()
{
   if (mpWindow)
      SDL_DestroyWindow(mpWindow);
   SDL_Quit();
}

void Ecran::update()
{
   SDL_UpdateWindowSurface(mpWindow);
}

void Ecran::efface(const Couleur& couleur)
{
   SDL_FillRect(m_surface, NULL, couleur);
}

Couleur::Couleur(int r, int v, int b)
   : color(0)
{
   SDL_Surface* surface(Ecran::instance().surface());
   if (surface == nullptr)
   {
      cerr << "Impossible de choisir une couleur sans écran." << endl;
      return;
   }

   color = SDL_MapRGB(surface->format,r,v,b);
}
