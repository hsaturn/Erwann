#pragma once
#include <string>
#include <SDL2/SDL_mixer.h>

using namespace std;

class Sound
{
    public:
      Sound(const string& rsrc_wav);
      Sound(const Sound&) = delete;
      Sound& operator=(const Sound&) = delete;

      ~Sound() { if (sound) Mix_FreeChunk(sound); }
      void play();

      static constexpr int channels = 6; // TODO magic
      static int play_channel;
      static bool init_done;
      static void init();

    protected:
      static void close();

    private:
      Mix_Chunk* sound;
};
