//
// Created by Giacomo Zanatta on 15/02/21.
//

#include "WavFile.h"

WavFile::WavFile(wavHeader header, wavData data) {
    this->header = header;
    this->data = data;
}
