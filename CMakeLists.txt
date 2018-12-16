cmake_minimum_required(VERSION 3.13)
project(AT_Library)

set(CMAKE_CXX_STANDARD 14)

add_library(AT_Library AT_Library.cpp AT_Library.h)

# change the diretory location to your arduino install location for fetching Arduino.h
include_directories(../Downloads/arduino-1.8.8/hardware/arduino/avr/cores/arduino/)
