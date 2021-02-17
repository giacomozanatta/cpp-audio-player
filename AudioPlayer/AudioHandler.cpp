//
// Created by Giacomo Zanatta on 29/11/2020.
//

#include "AudioHandler.h"

#include <soundio/soundio.h>
#include "AudioFileStream.h"
using namespace std;
static const float PI = 3.1415926535f;
static float seconds_offset = 0.0f;
int i = 0;
float rawSound(double dTime /*time passed since the start of the program.*/, double frequency) {
    double value =  1.0*(sin(frequency * 2* PI * dTime));// convert frequency to radian per second
    //printf("%f", value);
    if (value > 0.0) {
        return 0.2;
    } else {
        return -0.2;
    }
}



void write_callback3(struct SoundIoOutStream *outstream, int frame_count_min, int frame_count_max) {
    WavFile *wav = static_cast<WavFile*>(outstream->userdata);
    const struct SoundIoChannelLayout *layout = &outstream->layout;
    float float_sample_rate = outstream->sample_rate; //default to 48000
    float seconds_per_frame = 1.0f /float_sample_rate;
    struct SoundIoChannelArea *areas;
    int frames_left = frame_count_max;
    int err;

    while (frames_left > 0) {
        int frame_count = frames_left;

        if ((err = soundio_outstream_begin_write(outstream, &areas, &frame_count))) {
            fprintf(stderr, "%s\n", soundio_strerror(err));
            exit(1);
        }

        if (!frame_count)
            break;

        //float pitch = 440.0f;
        //float radians_per_second = pitch * 2.0f * PI;
        for (int frame = 0; frame < frame_count; frame += 1) {

                float *ptrLeft = (float*)(areas[0].ptr + areas[0].step * frame);
                *ptrLeft = wav->data.leftChannel[i]*(wav->data.leftChannel[i]/2);
                float *ptrRight  = (float*)(areas[1].ptr + areas[1].step * frame);
                *ptrRight = wav->data.RightChannel[i]*(wav->data.RightChannel[i]/2);
                i++;
        }
        seconds_offset = fmodf(seconds_offset +
                               seconds_per_frame * frame_count, 1.0f);

        if ((err = soundio_outstream_end_write(outstream))) {
            fprintf(stderr, "%s\n", soundio_strerror(err));
            exit(1);
        }

        frames_left -= frame_count;
    }

}
const char * InitAudioHandlerException::what() const noexcept {
    return "Failed to load SoundIo";
}


AudioHandler::AudioHandler() {
    int err;
    int default_out_device_index;
    // create soundio object
    soundio = soundio_create();
    if (!soundio) {
        throw InitAudioHandlerException();
    }
    // handle soundio connection
    err = soundio_connect(soundio);
    if (err) {
        throw InitAudioHandlerException();
    }
    soundio_flush_events(soundio);
    default_out_device_index = soundio_default_output_device_index(soundio);
    if (default_out_device_index < 0) {
        throw InitAudioHandlerException();
    }
    // init device
    device = soundio_get_output_device(soundio, default_out_device_index);
    if (!device) {
        throw InitAudioHandlerException();
    }
    // create outstream
    outstream = soundio_outstream_create(device);
    if (!outstream) {
        throw InitAudioHandlerException();
    }
    outstream->format = SoundIoFormatFloat32NE;

    // open out stream
    err = soundio_outstream_open(outstream);
    if (err || outstream->layout_error) {
        throw InitAudioHandlerException();
    }

}

void AudioHandler::StartOutstream() {
    outstream->write_callback = write_callback3;
    int err =  soundio_outstream_start(outstream);
    if (err) {

        throw InitAudioHandlerException();
    }
    for(;;) {
        soundio_wait_events(soundio);
    }

}

void AudioHandler::StopOutstream() {
    soundio_outstream_destroy(outstream);
}

void AudioHandler::SetPitch(float pitch) {
    AudioCallbackContext *context = new AudioCallbackContext;
    context->pitch = pitch;
    outstream->userdata = static_cast<void*>(context);
}

void AudioHandler::SetStream(WavFile* wav) {
    outstream->userdata = static_cast<void*>(wav);
}



