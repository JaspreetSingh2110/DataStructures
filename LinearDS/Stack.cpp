//
// Created by Jaspreet Singh on 8/21/2024.
//

#include "Stack.h"

#include <iostream>
#include <ostream>

//Constructor
Stack::Stack(int size) {
  this->size = size;
  this->top = -1;

  stackPtr = new int[size];
}

//Destructor
Stack::~Stack() {
  delete[] stackPtr;
}

bool Stack::IsFull() const {
  return (top == size - 1);
}

bool Stack::IsEmpty() const {
  return (top == -1);
}

void Stack::Push(int data) {
  if (IsFull()) {
    std::cout << "Stack is Full" << std::endl;
    return;
  }
  stackPtr[++top] = data;
}

int Stack::Pop() {
  if (IsEmpty()) {
    std::cout << "Stack is Empty" << std::endl;
    return -1;
  }
  return stackPtr[top--];
}

int Stack::Top() const {
  if (IsEmpty()) {
    std::cout << "Stack is Empty" << std::endl;
    return -1;
  }
  return stackPtr[top];
}


//Function to test Stack implementation
void TestStack() {
  Stack s(5);

  //Insert Elements in stack
  for (int i = 0; i < 5; i++) {
    s.Push(i);
  }

  // Try inserting additional element when stack is full.
  s.Push(6);

  // Try popping out elements from stack
  for (int i = 0; i < 5; i++) {
    std::cout << s.Pop() << std::endl;
  }

  // Try popping out element when stack is empty.
  s.Pop();
}