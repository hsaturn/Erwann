#include <Sound.h>
#include <RsrcFinder.h>
#include <iostream>

Sound::Sound(const string& rsrc_wav) : sound(nullptr)
{
  string wavefile = RsrcFinder::findFile(rsrc_wav);
  init();

  if (wavefile.length() == 0)
  {
    return;
  }

  sound = Mix_LoadWAV(wavefile.c_str());
  if (!sound)
  {
    cerr << "Unable to load (" << wavefile << ") : " << SDL_GetError() << endl;
  }
}

void Sound::play()
{
  Mix_PlayChannel(play_channel, sound, 0);
  play_channel++;
  if (play_channel >= channels) play_channel = 0;
}

bool Sound::init_done = false;
int Sound::play_channel = 0;

void Sound::init()
{
  if (init_done) return;
  init_done = true;
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
  {
    printf("%s", Mix_GetError());
    Mix_AllocateChannels(channels);  // TODO magic
  }
  Mix_Volume(1, MIX_MAX_VOLUME/2);
  cout << "Sound system init done." << endl;
  std::atexit(Sound::close);
}

void Sound::close()
{
  Mix_CloseAudio();
}
