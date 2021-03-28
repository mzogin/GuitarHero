// Copyright 2020 Michael Zogin
#ifndef STRINGSOUND_H
#define STRINGSOUND_H

#include "CircularBuffer.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>
#include <random>
#include <string>
#include <vector>

const int SAMPLE_RATE = 44100;
const double ENERGY_DECAY_FACTOR = 0.996;

using std::vector;
using std::cout;
using std::endl;

class StringSound {
 public:
  explicit StringSound(double frequency);
  explicit StringSound(vector<sf::Int16> init);
  StringSound(const StringSound &obj) {}
  ~StringSound();

  void pluck();
  void tic();
  sf::Int16 sample();
  int time();

 private:
  CircularBuffer *buff;
  int _time;
  int num;
};

#endif
