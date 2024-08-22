//
// Created by Jaspreet Singh on 8/22/2024.
//

#ifndef QUEUE_H
#define QUEUE_H

class Queue {
  public:
  Queue() = default;
  ~Queue();
  explicit Queue(int size);

  void Enqueue(int value);
  int Dequeue();
  bool IsEmpty() const;
  bool IsFull() const;
  void Print() const;

  private:
  int rear;
  int size;
  int *queuePtr;
};

void TestQueue();

#endif //QUEUE_H
