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

  Node(int d)
  {
    data = d;
    next = nullptr;
  }
};

static void PrintList(Node *head)
{
  std::cout << "HEAD -> ";
  while (head != nullptr) {
    std::cout << head->data << " -> ";
    head = head->next;
  }
  std::cout << "NULL" << std::endl;
}

Node *SingleLinkedListReverse_Iterative(Node *head)
{
  //Empty list.
  if (head == nullptr) {
    return nullptr;
  }
  //Single node.
  if (head->next == nullptr) {
    return head;
  }

  Node *prev = head;
  Node *curr = head->next;
  Node *next;
  if (curr && curr->next) {
    next = curr->next;
  }

  //Make first two nodes reverse.
  curr->next = prev;
  prev->next = nullptr;

  //Process remaining list.
  while (next) {
    prev = curr;
    curr = next;
    next = next->next;
    curr->next = prev;
  }
  if (curr) {
    head = curr;
  }
  return head;
}

Node *SingleLinkedListReverse_Recursive(Node *head)
{
  //If last node reaches, return self.
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  //Reverse remaining portion of list.
  //At topmost stack, rest will be last node, head will be 2nd last node.
  Node *rest = SingleLinkedListReverse_Recursive(head->next);

  //2nd last node point point the last node's next to self.
  head->next->next = head;
  //Set current nodes next as null.
  head->next = nullptr;

  //Always the last node in list will be returned while stack collapse/return.
  return rest;
}


void Test_SingleLinkedListReverse()
{
  std::cout << "\nTest reverse of single linked lists\n";
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);

  //Initial list.
  std::cout << "Initial list: ";
  PrintList(head);

  //Reverse the list.
  Node *revHead = SingleLinkedListReverse_Iterative(head);
  std::cout << "Reversed list (iterative): ";
  PrintList(revHead);

  //Re-reverse the list.
  head = SingleLinkedListReverse_Iterative(revHead);
  std::cout << "Re-Reversed list (recursion): ";
  PrintList(head);
}
