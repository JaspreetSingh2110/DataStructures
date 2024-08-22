//
// Created by Jaspreet Singh on 8/22/2024.
//

#include "Queue.h"

#include <iostream>
#include <ostream>

Queue::Queue(int size) {
  this->size = size;
  rear = -1;
  queuePtr = new int[size];
}

Queue::~Queue() {
  delete[] queuePtr;
}


bool Queue::IsEmpty() const {
  return rear == -1;
}

bool Queue::IsFull() const {
  return rear == size - 1;
}

void Queue::Enqueue(int value) {
  if (IsFull()) {
    std::cout << "Queue is full" << std::endl;
    return;
  }
  queuePtr[++rear] = value;
}

int Queue::Dequeue() {
  int frontElement = queuePtr[0];

  //Check if Queue is empty.
  if (IsEmpty()) {
    std::cout << "Queue is empty" << std::endl;
    return -1;
  }

  //Shifts elements one step front.
  for (int i = 1; i <= rear; i++) {
    queuePtr[i - 1] = queuePtr[i];
  }

  //Decrement rear position.
  rear--;
  return frontElement;
}

void Queue::Print() const {
  std::cout << "**************** Queue elements: " << std::endl;
  if (IsEmpty()) {
    std::cout << "Queue is empty" << std::endl;
  }

  //Print elements
  for (int i = 0; i < rear + 1; i++) {
    std::cout << queuePtr[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "**************** ***************: " << std::endl;
}


void TestQueue() {
  Queue q(5);

  // Enter elements into queue.
  for (int i = 1; i <= 5; i++) {
    q.Enqueue(i);
    q.Print();
  }

  // Try adding additional elements into queue when queue is full.
  q.Enqueue(6);

  //Remove elements from queue
  for (int i = 1; i <= 5; i++) {
    std::cout << "Removed element from begin: " << q.Dequeue() << std::endl;
    q.Print();
  }

  //Try removing element from queue when it is empty.
  q.Dequeue();

  //Add single element to queue.
  q.Enqueue(100);
  q.Print();

  //Remove element from queue.
  std::cout << q.Dequeue() << std::endl;
}
