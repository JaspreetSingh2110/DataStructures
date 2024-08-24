//
// Created by Jaspreet Singh on 8/25/2024.
//

#include "DoubleLinkedList.h"
#include <iostream>

DoubleLinkedList::DoubleLinkedList()
  : head(nullptr) {}

DoubleLinkedList::~DoubleLinkedList()
{
  struct DllNode *temp = nullptr;
  while (head) {
    temp = head;
    head = head->next;
    delete temp;
  }
}

void DoubleLinkedList::Print(bool detail)
{
  struct DllNode *temp = head;
  std::cout << "HEAD -> ";
  while (temp) {
    if (detail) {
      std::cout << "[0x" << temp->prev << " | [0x"<< temp << "] " << temp->data << " | 0x" << temp->next << "] <=> ";
    } else {
      std::cout << temp->data << " <=> ";
    }
    temp = temp->next;
  }
  std::cout << "NULL" << std::endl;
}

void DoubleLinkedList::AddAtBegin(int data)
{
  struct DllNode *newNode = new DllNode(data);
  newNode->next = head;
  head = newNode;
}

void DoubleLinkedList::AddAtEnd(int data)
{
  struct DllNode *newNode = new DllNode(data);

  //Create a temporary node pointer and iterate to last node in list.
  struct DllNode *temp = head;
  while (temp->next) {
    temp = temp->next;
  }

  //Point the last node to newly created node.
  temp->next = newNode;
  newNode->prev = temp;
}

void DoubleLinkedList::AddAtPosition(int data, int position)
{
  if (position <= 0) {
    std::cout << "Invalid position. Please enter position greater than 0." << std::endl;
    return;
  }

  //Insert at position 0.
  if (position == 1) {
    AddAtBegin(data);
    return;
  }

  struct DllNode *newNode = new DllNode(data);
  struct DllNode *temp = head;

  // Iterate to given position.
  for (int i = 1; i < position -1; i++) {
    if (temp == nullptr) {
      break;
    }
    temp = temp->next;
  }
  if (temp == nullptr) {
    std::cout << "Less numbers of nodes present in list than the position. "
        << " Node cannot be added at given position!!!!" << std::endl;
    return;
  }
  newNode->next = temp->next;
  if (temp->next) {
    temp->next->prev = newNode;
  }
  newNode->prev = temp;
  temp->next = newNode;
}

void DoubleLinkedList::DeleteAtBegin()
{
  // Check if list is empty.
  if (head == nullptr) {
    return;
  }

  //Point head to next node and delete the first node.
  struct DllNode *temp = head;
  head = head->next;
  if (head) {
    head->prev = nullptr;
  }
  delete temp;
}

void DoubleLinkedList::DeleteAtEnd()
{
  //Check if list is empty.
  if (head == nullptr) {
    return;
  }
  //Check if only one node in list.
  if (head->next == nullptr) {
    delete head;
    head = nullptr;
    return;
  }

  //Iterate till 2nd last node in list.
  struct DllNode *temp = head;
  while (temp->next && temp->next->next) {
    temp = temp->next;
  }
  delete temp->next;
  temp->next = nullptr;
}

void DoubleLinkedList::Clear()
{
  struct DllNode *temp = nullptr;
  while (head) {
    temp = head;
    head = head->next;
    delete temp;
  }
}


void TestDoubleLinkedLists()
{
  DoubleLinkedList dll;
  dll.AddAtBegin(10);
  dll.AddAtEnd(20);
  dll.AddAtEnd(30);
  dll.AddAtEnd(40);
  dll.AddAtEnd(50);

  dll.Print();

  //Add at position.
  dll.AddAtPosition(60, 6);
  dll.Print();

  // Try adding at invalid position.
  dll.AddAtPosition(70, 10);
  dll.Print();

  //Add at position.
  dll.AddAtPosition(35, 4);
  dll.Print();
  dll.Print(true);

  dll.DeleteAtBegin();
  dll.Print();
  dll.DeleteAtEnd();
  dll.Print();

  dll.Clear();
  dll.Print();
}
