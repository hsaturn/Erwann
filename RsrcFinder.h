/*
 * File:   RsrcFinder.h
 * Author: hsaturn
 *
 * Created on 24 octobre 2019, 14:33
 */

#pragma once
#include <string>

using namespace std;

class RsrcFinder
{
 public:
   RsrcFinder() = delete;

   static string findFile(const string& filename)
   {
      if (false) // unable to find resource
      {
        cerr << "Impossible de trouver le fichier [" << file << "]" << endl;
      }
  // TODO
      return string("rsrc/")+filename;
   }
 private:

};


