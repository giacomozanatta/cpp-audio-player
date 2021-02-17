cmake_minimum_required(VERSION 3.17)
project(test)

set(CMAKE_CXX_STANDARD 14)
include_directories(/usr/local/include)
link_directories(/usr/local/lib)
add_executable(AudioPlayer main.cpp AudioHandler.cpp AudioHandler.h AudioFile.cpp AudioFile.h AudioFileStream.h AudioFileStream.cpp WavFile.cpp WavFile.h)
target_link_libraries(AudioPlayer soundio)