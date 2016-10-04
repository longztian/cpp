#include "threeInOne.hpp"

static const int SIZE = 9;
static int buffer[SIZE];

MyStack::MyStack(int* buffer, int size) : myBegin(buffer), myEnd(buffer+size), myTop(buffer) {};

void MyStack::push(int v) {
  if (myTop != myEnd) {
    *myTop = v;
    myTop += 1;
  }
}

int MyStack::pop() {
  if (myTop != myBegin) {
    myTop -= 1;
    return *(myTop);
  }
}

int MyStack::peek() {
  if (myTop != myBegin) {
    return *(myTop-1);
  }
}

bool MyStack::empty() {
  return myTop == myBegin;
}

void threeInOne(p_stack_t& s1, p_stack_t& s2, p_stack_t& s3) {
  s1 = std::make_shared<MyStack>(buffer, SIZE/3);
  s2 = std::make_shared<MyStack>(buffer+SIZE/3, SIZE/3);
  s3 = std::make_shared<MyStack>(buffer+SIZE/3*2, SIZE/3);
}
