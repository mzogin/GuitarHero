// Copyright 2020 Michael Zogin
#include "StringSound.h"

StringSound::StringSound(double frequency) {
  num = ceil(SAMPLE_RATE / frequency);  // size of buffer
  try {
    buff = new CircularBuffer(num);
  } catch (const std::bad_alloc &e) {
    cout << "Allocation failed" << e.what() << std::endl;
  }

  for (int i = 0; i < num; i++) {
    buff->enqueue((int16_t)0);
  }
  _time = 0;
}

StringSound::StringSound(vector<sf::Int16> init) {
  num = init.size();
  try {
    buff = new CircularBuffer(num);
  } catch (const std::bad_alloc &e) {
    std::cout << "Allocation failed" << e.what() << std::endl;
  }
  vector<sf::Int16>::iterator it;

  for (it = init.begin(); it < init.end(); it++) {
    buff->enqueue((int16_t)*it);
  }
  _time = 0;
}

StringSound::~StringSound() {
  // std::cout << "Destructing" << std::endl;
  delete buff;
}

void StringSound::pluck() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int16_t> random(-32768, 32767);
  // for (int i = 0; i < num; i++) // first make sure buffer is empty
  // {
  // buff->dequeue();
  // }
  buff->empty();
  // add on random nums
  for (int i = 0; i < num; i++) {
    buff->enqueue(random(gen));
  }
}

void StringSound::tic() {
  int16_t first = buff->dequeue();
  int16_t second = buff->peek();

  int16_t avg = (first + second) / 2;

  int16_t kar = avg * ENERGY_DECAY_FACTOR;  // karplus algorithm

  buff->enqueue((sf::Int16)kar);

  _time++;
}

sf::Int16 StringSound::sample() {
  sf::Int16 samp = (sf::Int16)buff->peek();
  return samp;
}

int StringSound::time() { return _time; }
