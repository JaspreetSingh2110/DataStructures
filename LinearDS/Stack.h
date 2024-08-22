//
// Created by Jaspreet Singh on 8/21/2024.
//

#ifndef STACK_H
#define STACK_H

class Stack{
  public:
  Stack() = default;
  explicit Stack(int size);

  ~Stack();
  bool IsEmpty() const;
  bool IsFull() const;
  void Push(int data);
  int Pop();
  int Top() const;

  private:
  int size{};
  int top{};
  int *stackPtr = nullptr;
};

void TestStack();

#endif //STACK_H
