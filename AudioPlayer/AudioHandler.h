//
// Created by Giacomo Zanatta on 29/11/2020.
//

#ifndef TEST_AUDIOHANDLER_H
#define TEST_AUDIOHANDLER_H

#include <iostream>
#include "WavFile.h"


class AudioHandler {
public:
    AudioHandler();
    void StartOutstream();
    void SetPitch(float pitch);
   void SetStream(WavFile* wav);
    void StopOutstream();
   // void AddEffect(Effect effect, int position);
   // void RemoveEffect(int position);
private:
    struct SoundIo *soundio;
    struct SoundIoDevice *device;
    struct SoundIoOutStream *outstream;
};

class AudioCallbackContext {
public:
    float pitch;
    double *raw;
};
struct InitAudioHandlerException : public std::exception
{
public:
    const char * what () const noexcept override;

};

#endif //TEST_AUDIOHANDLER_H
