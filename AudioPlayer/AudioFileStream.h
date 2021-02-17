//
// Created by Giacomo Zanatta on 15/02/21.
//

#ifndef TEST_AUDIOFILESTREAM_H
#define TEST_AUDIOFILESTREAM_H


#include <string>
#include "WavFile.h"
class AudioFileStream {
public:
    static void Read(std::string path);
    static WavFile* ReadWav(const char* path);
};

#endif //TEST_AUDIOFILESTREAM_H
