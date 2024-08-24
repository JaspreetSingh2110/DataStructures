//
// Created by Jaspreet Singh on 24/08/24.
//

#include "SingleLinkedLists.h"

#include <iostream>

SingleLinkedList::SingleLinkedList()
  : head(nullptr) {}

SingleLinkedList::~SingleLinkedList()
{
  struct Node *temp = nullptr;
  while (head) {
    temp = head;
    head = head->next;
    delete temp;
  }
}

void SingleLinkedList::Print()
{
  struct Node *temp = head;
  std::cout << "HEAD -> ";
  while (temp) {
    std::cout << temp->data << " -> ";
    temp = temp->next;
  }
  std::cout << "NULL" << std::endl;
}

void SingleLinkedList::AddAtBegin(int data)
{
  struct Node *newNode = new Node(data);
  newNode->next = head;
  head = newNode;
}

void SingleLinkedList::AddAtEnd(int data)
{
  struct Node *newNode = new Node(data);

  //Create a temporary node pointer and iterate to last node in list.
  struct Node *temp = head;
  while (temp->next) {
    temp = temp->next;
  }

  //Point the last node to newly created node.
  temp->next = newNode;
}

void SingleLinkedList::AddAtPosition(int data, int position)
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

  struct Node *newNode = new Node(data);
  struct Node *temp = head;

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
  temp->next = newNode;
}

void SingleLinkedList::DeleteAtBegin()
{
  // Check if list is empty.
  if (head == nullptr) {
    return;
  }

  //Point head to next node and delete the first node.
  struct Node *temp = head;
  head = head->next;
  delete temp;
}

void SingleLinkedList::DeleteAtEnd()
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
  struct Node *temp = head;
  while (temp->next && temp->next->next) {
    temp = temp->next;
  }
  delete temp->next;
  temp->next = nullptr;
}

void SingleLinkedList::Clear()
{
  struct Node *temp = nullptr;
  while (head) {
    temp = head;
    head = head->next;
    delete temp;
  }
}


void TestSingleLinkedLists()
{
  SingleLinkedList sll;
  sll.AddAtBegin(10);
  sll.AddAtEnd(20);
  sll.AddAtEnd(30);
  sll.AddAtEnd(40);
  sll.AddAtEnd(50);

  sll.Print();

  //Add at position.
  sll.AddAtPosition(60, 6);
  sll.Print();

  // Try adding at invalid position.
  sll.AddAtPosition(70, 10);
  sll.Print();

  //Add at position.
  sll.AddAtPosition(35, 4);
  sll.Print();

  sll.DeleteAtBegin();
  sll.Print();
  sll.DeleteAtEnd();
  sll.Print();

  sll.Clear();
  sll.Print();
}