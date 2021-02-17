#include <soundio/soundio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <iostream>
#include "AudioHandler.h"
#include "AudioFileStream.h"


void playCerteNotti(AudioHandler *pHandler);

using namespace std::chrono_literals;

int main(int argc, char **argv) {
    WavFile* wav = AudioFileStream::ReadWav("/Users/giacomo/Downloads/21 guns.wav");
    WavFile* wav2 = AudioFileStream::ReadWav("/Users/giacomo/Downloads/21guns.wav");
    std::string test = "120\nA#/1|B#/2";
    std::string test2 = test.substr(0, test.find("\n"));
    std::string song = test.substr(test.find("\n"), test.length()-1);

    int bpm = 120; // default
    try {
        std::cout << "TEST2" << test2 << std::endl;
        bpm = std::stoi(test2);
        std::cout << "TEST2 INTEGER" << bpm << std::endl;
    } catch(std::exception e) {
        std::cout << "CIAO" << std::endl;
        return 0;
    }


    AudioHandler *audioHandler;
    AudioHandler *audioHandler2;
    AudioHandler *audioHandler3;
    try {
        audioHandler = new AudioHandler();
        audioHandler2 = new AudioHandler();
        //audioHandler3 = new AudioHandler();
        audioHandler->SetStream(wav);
        std::thread t1(&AudioHandler::StartOutstream, audioHandler);
        //audioHandler2->SetStream(wav2);
        //playCerteNotti(audioHandler);
        //std::thread t3(&AudioHandler::StartOutstream, audioHandler2);
        /*
        audioHandler->SetPitch(261.626);
        std::this_thread::sleep_for(0.5s);
        audioHandler->SetPitch(293.66);
        std::this_thread::sleep_for(0.5s);
        audioHandler->SetPitch(329.63); // MI
        std::this_thread::sleep_for(0.5s);
        audioHandler->SetPitch(349.23); // FA
        std::this_thread::sleep_for(0.5s);
        audioHandler->SetPitch(392.00); // SOL
        std::this_thread::sleep_for(0.5s);
        audioHandler->SetPitch(440.00); // LA
        std::this_thread::sleep_for(0.5s);
        audioHandler->SetPitch(493.88); // SI
        std::this_thread::sleep_for(0.5s);
        audioHandler->SetPitch(523.25); // DO
        std::this_thread::sleep_for(0.5s);
        audioHandler->SetPitch(587.33);
        std::this_thread::sleep_for(0.5s);
*/





        //audioHandler->SetPitch(220.0);
        // audioHandler2->SetPitch(164.81);
        //audioHandler3->SetPitch(196.00);


        /*audioHandler->SetPitch(261.63);
        std::this_thread::sleep_for(2s);
        audioHandler->SetPitch(293.66);
        std::this_thread::sleep_for(2s);
        audioHandler->SetPitch(329.63);
        std::this_thread::sleep_for(2s);
        audioHandler->SetPitch(349.23);
        std::this_thread::sleep_for(2s);
        audioHandler->SetPitch(392.00);
        std::this_thread::sleep_for(2s);
        audioHandler->SetPitch(440.00);
        std::this_thread::sleep_for(2s);
        audioHandler->SetPitch(493.88);
        std::this_thread::sleep_for(2s);
        audioHandler->SetPitch(523.25);
        std::this_thread::sleep_for(2s);*/
        std::this_thread::sleep_for(100s);
    } catch (InitAudioHandlerException& e)
    {
        std::cout << "MyException caught" << std::endl;
        std::cout << e.what() << std::endl;
    }

    return 0;
}


void playCerteNotti(AudioHandler *audioHandler) {
    audioHandler->SetPitch(349.23);
    std::this_thread::sleep_for(1.0s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(440.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(349.23);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(349.23);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(440.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(440.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(1.0s);
    audioHandler->SetPitch(349.23);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(440.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(349.23);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(440.00);
    std::this_thread::sleep_for(1.5s);
    audioHandler->SetPitch(440.00);
    std::this_thread::sleep_for(1.0s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(349.23);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(349.23);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(349.23);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(349.23);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(440.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(440.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(1s);
    audioHandler->SetPitch(349.23);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(440.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(349.23);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(261.626);
    std::this_thread::sleep_for(1.0s);
    audioHandler->SetPitch(0);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(523.25);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(523.25);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(523.25);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(523.25);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(523.25);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(523.25);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(659.25);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(698.46);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(698.46);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(659.25);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(587.33);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(587.33);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(523.25);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(466.16);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(523.25);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(466.16);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(440.0);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(440.0);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(466.16);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(523.25);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(349.23);
    std::this_thread::sleep_for(1.5s);
    // pause 1
    audioHandler->SetPitch(0);
    audioHandler->SetPitch(349.23);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(440.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(349.23);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(349.23);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(440.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(440.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(1.0s);
    audioHandler->SetPitch(349.23);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(440.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(349.23);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(349.00);
    std::this_thread::sleep_for(3s);
    audioHandler->SetPitch(0);
    std::this_thread::sleep_for(1.5s);
    audioHandler->SetPitch(587.33);
    std::this_thread::sleep_for(0.25s);
    audioHandler->SetPitch(523.25);
    std::this_thread::sleep_for(0.25s);
    audioHandler->SetPitch(587.33);
    std::this_thread::sleep_for(0.25s);
    audioHandler->SetPitch(523.25);
    std::this_thread::sleep_for(0.25s);
    audioHandler->SetPitch(587.33);
    std::this_thread::sleep_for(0.25s);
    audioHandler->SetPitch(523.25);
    std::this_thread::sleep_for(0.25s);
    audioHandler->SetPitch(523.25);
    std::this_thread::sleep_for(1.5s);
    audioHandler->SetPitch(440.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(349.23);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(0);
    std::this_thread::sleep_for(1.5s);
    audioHandler->SetPitch(466.16);
    std::this_thread::sleep_for(0.25s);
    audioHandler->SetPitch(466.16);
    std::this_thread::sleep_for(0.25s);
    audioHandler->SetPitch(466.16);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(523.25);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(440.0);
    std::this_thread::sleep_for(3.0s);
    audioHandler->SetPitch(0); //49
    std::this_thread::sleep_for(1.5s);
    audioHandler->SetPitch(587.33);
    std::this_thread::sleep_for(0.25s);
    audioHandler->SetPitch(587.33);
    std::this_thread::sleep_for(0.25s);
    audioHandler->SetPitch(587.33);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(587.33);
    std::this_thread::sleep_for(0.5s); // 698.46
    audioHandler->SetPitch(698.46);
    std::this_thread::sleep_for(0.5s); // 659.25
    audioHandler->SetPitch(659.25);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(587.33);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(0);
    std::this_thread::sleep_for(1.0s);
    audioHandler->SetPitch(349.23);
    std::this_thread::sleep_for(0.5s); // 466.16
    audioHandler->SetPitch(466.16);
    std::this_thread::sleep_for(1.0s);
    audioHandler->SetPitch(523.25);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(440.0);
    std::this_thread::sleep_for(1.5s);
    audioHandler->SetPitch(440.0);
    std::this_thread::sleep_for(1.0s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(0.5s); // 57
    audioHandler->SetPitch(349.23);
    std::this_thread::sleep_for(1.5s);
    audioHandler->SetPitch(466.16);
    std::this_thread::sleep_for(1.0s);
    audioHandler->SetPitch(440.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(440.00);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00);
    std::this_thread::sleep_for(1.5s);
    audioHandler->SetPitch(349.23);
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00); // SOL
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(440.00); // LA
    std::this_thread::sleep_for(1s);
    audioHandler->SetPitch(523.25); // DO
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(440.00); // LA
    std::this_thread::sleep_for(1.0s);
    audioHandler->SetPitch(392.00); // SOL
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(349.23); // FA
    std::this_thread::sleep_for(1.5s);
    audioHandler->SetPitch(0); // PAUSE
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(349.23); // FA
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(349.23); // FA
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(349.23); // FA 65
    std::this_thread::sleep_for(1.5s);
    audioHandler->SetPitch(392.00); // SOL
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(466.16); // SIb
    std::this_thread::sleep_for(1.0s);
    audioHandler->SetPitch(440.00); // LA
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(440.00); // LA
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(392.00); // SOL
    std::this_thread::sleep_for(1.5s);
    audioHandler->SetPitch(349.23); // FA
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(329.63); // MI
    std::this_thread::sleep_for(0.5s);
    audioHandler->SetPitch(349.23); // FA
    std::this_thread::sleep_for(3s);
}