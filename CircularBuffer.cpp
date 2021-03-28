// Copyright 2020 Michael Zogin

#include "CircularBuffer.h"

CircularBuffer::CircularBuffer(int capacity) {
  if (capacity < 1) {
    throw std::invalid_argument(
        "CircularBuffer constructor: capacity must be greater than zero.");
  }
  first = 0;
  last = 0;
  cap = capacity;
  numItems = 0;
  buffer.resize(cap);
}

int CircularBuffer::size() { return numItems; }

bool CircularBuffer::isEmpty() {
  if (numItems == 0) {
    return true;
  }
  return false;
}

bool CircularBuffer::isFull() {
  if (numItems >= cap) {
    return true;
  }
  return false;
}

void CircularBuffer::enqueue(int16_t x) {
  if (isFull()) {
    throw std::runtime_error("enqueue: can't enqueue to a full ring");
    return;
  }
  else{
  if (last >= cap) {
    last = 0;
  }
  buffer.at(last) = x;

  last++;
  numItems++;
  }
}

// delete front and return it
int16_t CircularBuffer::dequeue() {
  if (isEmpty()) {
    throw std::runtime_error("dequeue: can't dequeue from empty string");
    return -1;
  }
  else{
  int16_t first16 = buffer.at(first);  // to remove from front
  buffer.at(first) = 0;

  first++;
  numItems--;

  if (first >= cap) {
    first = 0;
  }
  return first16;
  }
}

int16_t CircularBuffer::peek() {
  if (isEmpty()) {
    throw std::runtime_error("peek: can't peek from empty string");
    return -1;
  }
  else{
  return buffer.at(first);
  }
}

void CircularBuffer::output() {
  cout << "First: " << first << endl;
  cout << "Last: " << last << endl;
  cout << "Capacity: " << cap << endl;
  cout << "Size: " << numItems << endl;
  cout << "Vector capacity: " << buffer.capacity() << endl;
  cout << "Vector size: " << buffer.size() << endl;
  cout << "Printing out buffer" << endl;
  for_each(buffer.begin(), buffer.end(), [](int16_t i){cout << i << " ";});
  cout << endl << endl;
}

void CircularBuffer::empty() {
  first = 0;
  last = 0;
  numItems = 0;
}
