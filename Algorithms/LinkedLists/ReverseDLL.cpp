/*
 * Description:
 * Program to reverse the linked list.
 *
 * Created on: 06/12/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>

class Node {
public:
  int data;
  Node *next;
  Node *prev;

  Node(int d)
  {
    data = d;
    next = nullptr;
    prev = nullptr;
  }
};

void PrintList(Node *head)
{
  std::cout << "HEAD <-> ";
  while (head != nullptr) {
    std::cout << head->data << " <-> ";
    head = head->next;
  }
  std::cout << "NULL" << std::endl;
}

Node *DoubleLinkedListReverse_Iterative(Node *head)
{
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  Node *prev = nullptr;
  Node *curr = head;
  Node *next;

  while (curr != nullptr) {
    next = curr->next;

    curr->next = prev;
    curr->prev = next;

    prev = curr;
    curr = next;
  }
  return prev;
}


void Test_DoubleLinkedListReverse()
{
  std::cout << "\nTest reverse of double linked lists\n";
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->prev = head;
  head->next->next = new Node(3);
  head->next->next->prev = head->next;
  head->next->next->next = new Node(4);
  head->next->next->next->prev = head->next->next;
  head->next->next->next->next = new Node(5);
  head->next->next->next->next->prev = head->next->next->next;

  //Initial list.
  std::cout << "Initial list: ";
  PrintList(head);

  //Reverse the list.
  Node *revHead = DoubleLinkedListReverse_Iterative(head);
  std::cout << "Reversed list (iterative): ";
  PrintList(revHead);
}
