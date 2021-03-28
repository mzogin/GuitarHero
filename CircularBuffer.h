// Copyright 2020 Michael Zogin
#ifndef CIRCULARBUFFER_H_
#define CIRCULARBUFFER_H_
#include <stdint.h>
#include <exception>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;

class CircularBuffer {
 public:
  explicit CircularBuffer(int capacity);
  int size();
  bool isEmpty();
  bool isFull();
  void enqueue(int16_t x);
  int16_t dequeue();
  int16_t peek();

  void output();
  void empty();

 private:
  std::vector<int16_t> buffer;
  int first;
  int last;
  int cap;
  int numItems;
};
#endif  // CIRCULARBUFFER_H_
