//
// Created by Giacomo Zanatta on 15/02/21.
//


#include "AudiofileStream.h"
#include "WavFile.h"
#include <iostream>
#include <cmath>
    void AudioFileStream::Read(std::string path) {}
    WavFile* AudioFileStream::ReadWav(const char* path)  {
        wavHeader header{};
        wavData data{};
        char chunkId[5];
       // wavHeader header;
        FILE *fin = fopen(path, "rb");
        // read chunkId
        fread(header.chunkID, 1,4, fin);
        header.chunkID[4] = '\0';
        if (strcmp(header.chunkID, "RIFF") == 0) {
            // the file is a RIFF file.
            fread(&header.chunkSize, 1,4,fin);
            fread(header.format, 1,4, fin);
            header.format[4] = '\0';
            if (strcmp(header.format, "WAVE") == 0) {
                fread(header.subchunk1ID, 1,4, fin);
                header.subchunk1ID[4] = '\0';
                if (strcmp(header.subchunk1ID, "fmt ") == 0) {
                    fread(&header.subchunk1Size, 1,4, fin);
                    fread(&header.audioFormat, 1,2, fin);
                    fread(&header.numChannels, 1,2, fin);
                    fread(&header.sampleRate, 1,4, fin);
                    fread(&header.byteRate, 1,4, fin);
                    fread(&header.blockAlign, 1,2, fin);
                    fread(&header.bitsPerSample, 1,2, fin);
                }

            }
        }
        // read data
        // we need to check if the next chunk is data. If not, we can skip it until we found the data chunk.
        char chunkName[5];
        fread(chunkName, 1,4, fin);
        chunkName[4] = '\0';
        while(strcmp(chunkName, "data") != 0) {
            unsigned long subchunkSize = 0;
            fread(&subchunkSize, 1,4, fin);
            printf("%ld\n", subchunkSize);
            long int readedBytes = ftell(fin);
            fseek(fin,subchunkSize, SEEK_CUR);
            long int readedBytes2 = ftell(fin);
            fread(chunkName, 1,4, fin);
            chunkName[4] = '\0';
            //printf("%s\n", chunkName);
        }

        //we are in the data chunk. We can get chunkName, subchunk2size
        strcpy(data.subchunk2ID, chunkName);

        fread(&data.subchunk2Size,1,4, fin);
        // read the data

        // array is our array of data
        //unsigned char *array = new unsigned char[data.subchunk2Size];
        //fread(array, 1, data.subchunk2Size, fin);
      /*for (int i = 0; i < data.subchunk2Size; i+=4) {

            printf("%02X ", array[i]);
            if ((i+1)%16 == 0) {
                printf("\n");
            }
        }*/
        /* get only first channel
         */
        // our two channel
        int numSamples = data.subchunk2Size / (header.numChannels * header.bitsPerSample / 8);
        short *left = new short[numSamples];
        short *right = new short[numSamples];
        double *leftD = new double[numSamples];
        double *rightD = new double[numSamples];
        double pow2 = pow(2,16);
        for (int i = 0; i < numSamples; i++) {
            fread(&left[i], 1, 2, fin);
            fread(&right[i], 1, 2, fin);
           // printf("%f %f \n", left[i]/pow2, right[i]/pow2);
            leftD[i] = left[i]/pow2;
            rightD[i] = right[i]/pow2;
            /*printf("%02X%02X\n ", array[i], array[i+1]);
            unsigned char *frame = new unsigned char[2];
            frame[0] = array[i];
            frame[1] = array[i+1];*/
            // std::cout << static_cast<short>(frame) << std::endl;
            /*short value;
            memcpy( &value, frame, sizeof( short ) );
            printf("%d\n", value);
            i+=4;*/
        }
        data.RightChannel = rightD;
        data.leftChannel = leftD;
        //printf("%02X%02X ", array[22244], array[22245]);*/
        // I have my byte of data. Now i need to convert it to "double" (amplitude) and split for channels.

        /*while(!feof(fin)) {
            int sampleLeft = 0;
            int sampleRight = 0;
            fread(&left[i],1,4, fin);
            fread(&right[i],1,4, fin);
            std::printf("LEFT = %d\n", left[i]);
            std::printf("RIGHT = %d\n", right[i]);
            i ++;

        }*/

        std::printf("NUMBER OF SAMPLES = %d\n", numSamples);
        std::printf("SUBCHUNK2ID = %s\n", data.subchunk2ID);
        std::printf("SUBCHUNK2SIZE = %ld\n", data.subchunk2Size);
        /*wavHeader header{};
        printf("%d\n", sizeof(header));
        fread(&header, sizeof(header), 1, fin);
        std::printf("%zu\n", sizeof(char));
        */
        //Print WAV header
        std::cout << std::uppercase << std::hex << header.chunkID << std::endl;
        std::cout << std::uppercase << std::hex << header.chunkSize << std::endl;
        printf("WAV File Header read:\n");
        printf("File Type: %s\n", header.chunkID);
        printf("File Size: %ld\n", header.chunkSize);
        printf("WAV Marker: %s\n", header.format);
        printf("Format Name: %s\n", header.subchunk1ID);
        printf("Format Length: %ld\n", header.subchunk1Size );
        printf("Format Type: %hd\n", header.audioFormat);
        printf("Number of Channels: %hd\n", header.numChannels);
        printf("Sample Rate: %ld\n", header.sampleRate);
        printf("Byte rate ->Sample Rate * Bits/Sample * Channels / 8: %ld\n", header.byteRate);
        printf("Block align -> Bits per Sample * Channels / 8: %hd\n", header.blockAlign);
        printf("Bits per Sample: %hd\n", header.bitsPerSample);
        return new WavFile(header, data);
    }

