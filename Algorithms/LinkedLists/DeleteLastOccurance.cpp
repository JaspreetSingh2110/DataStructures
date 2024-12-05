/*
 * Description:
 * Program to delete last occurrence of given key in SLL.
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

Node* DeleteLastOccurrenceSLL(Node* head, int key)
{
  //Empty list.
  if (head == nullptr) {
    return nullptr;
  }
  //If single node and that is key.
  if ((head->next == nullptr) && (head->data == key)) {
    delete head;
    return nullptr;
  }

  Node *current = head;
  Node *previous = nullptr;

  while (current->next != nullptr) {
    if (current->next->data == key) {
      previous = current;
    }
    current = current->next;
  }

  //Update the links.
  Node *temp = previous->next;
  previous->next = temp->next;
  return head;
}


void Test_DeleteLastOccurrenceSLL()
{
  std::cout << "\nTest deletion of last occurrence of node in single linked lists\n";
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);
  head->next->next->next->next->next = new Node(4);
  head->next->next->next->next->next->next = new Node(4);
  head->next->next->next->next->next->next->next = new Node(8);
  head->next->next->next->next->next->next->next->next = new Node(9);
  head->next->next->next->next->next->next->next->next->next = new Node(10);

  //Initial list.
  std::cout << "Initial list: ";
  PrintList(head);

  //Delete the last occurrence of key from list.
  head = DeleteLastOccurrenceSLL(head, 4);
  std::cout << "List after deletion of last occurrence of 4: ";
  PrintList(head);
}