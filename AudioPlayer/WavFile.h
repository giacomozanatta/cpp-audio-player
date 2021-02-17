//
// Created by Giacomo Zanatta on 15/02/21.
//

#ifndef TEST_WAVFILE_H
#define TEST_WAVFILE_H
struct wavHeader
{
    char chunkID[5]; //"RIFF" = 0x46464952
    unsigned long chunkSize; //28 [+ sizeof(wExtraFormatBytes) + wExtraFormatBytes] + sum(sizeof(chunk.id) + sizeof(chunk.size) + chunk.size)
    char format[5]; //"WAVE" = 0x45564157
    char subchunk1ID[5]; //"fmt " = 0x20746D66
    unsigned long subchunk1Size; //16 [+ sizeof(wExtraFormatBytes) + wExtraFormatBytes]
    unsigned short audioFormat;
    unsigned short numChannels;
    unsigned long sampleRate;
    unsigned long byteRate;
    unsigned short blockAlign;
    unsigned short bitsPerSample;
    //[WORD wExtraFormatBytes;]
    //[Extra format bytes]
};

struct wavData {
    char subchunk2ID[5];
    unsigned long subchunk2Size;
    double *leftChannel;
    double *RightChannel;
};
class WavFile {
private:
    wavHeader header;
public:
    explicit WavFile(wavHeader header, wavData data);

    wavData data;
};


#endif //TEST_WAVFILE_H
