//
// Created by Jaspreet Singh on 24/08/24.
//

#ifndef SINGLELINKEDLISTS_H
#define SINGLELINKEDLISTS_H

struct Node {
  int data;
  struct Node *next;

  Node()
  {
    data = 0;
    next = nullptr;
  }

  explicit Node(int value)
  {
    data = value;
    next = nullptr;
  }
};

class SingleLinkedList {
  public:
  SingleLinkedList();
  ~SingleLinkedList();

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
  void Print();

private:
  struct Node *head;
};

void TestSingleLinkedLists();

#endif //SINGLELINKEDLISTS_H
