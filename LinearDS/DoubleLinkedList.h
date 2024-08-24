//
// Created by Jaspreet Singh on 8/25/2024.
//

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

struct DllNode {
  int data;
  struct DllNode *next;
  struct DllNode *prev;

  DllNode()
  {
    data = 0;
    next = nullptr;
    prev = nullptr;
  }

  explicit DllNode(int value)
  {
    data = value;
    next = nullptr;
    prev = nullptr;
  }
};

class DoubleLinkedList {
public:
  DoubleLinkedList();
  ~DoubleLinkedList();

  // APIs to insert new nodes.
  void AddAtBegin(int data);
  void AddAtEnd(int data);
  void AddAtPosition(int data, int position);

  //APIs to delete nodes.
  void DeleteAtBegin();
  void DeleteAtEnd();
  //void DeleteAtPosition(int position);
  void Clear();

  //Miscellaneous APIS.
  //Print nodes.
  void Print(bool detail = false);

private:
  struct DllNode *head;
};

void TestDoubleLinkedLists();

#endif //DOUBLELINKEDLIST_H
