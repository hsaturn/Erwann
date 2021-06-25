#include "Sound.h"
#include <SDL2/SDL_mixer.h>
#include "RsrcFinder.h"

Sound::Sound(const string& rsrc_wav)
{
  string wavefile = RsrcFinder::findFile(rsrc_wav);

  if (wavefile.length() == 0)
  {
    return;
  }

}
