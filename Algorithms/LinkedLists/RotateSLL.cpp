/*
 * Description:
 * Program to rotate the SLL.
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

Node* SingleLinkedListRotate(Node* head, int rCount)
{
  if (head == nullptr || head->next == nullptr || rCount == 0) {
    return head;
  }

  int len = 1;
  Node* temp = head;
  //Move pointer to last node.
  while (temp->next != nullptr) {
    temp = temp->next;
    len++;
  }

  //Handle the large values of rotation count.
  rCount %= len;

  //If no rotations required.
  if (rCount == 0) {
    return head;
  }

  //Make list circular.
  temp->next = head;
  for (int i = 0; i < rCount; i++) {
    temp = head;
    head = head->next;
  }

  //Make the circular list single again.
  temp->next = nullptr;

  return head;
}


void Test_SingleLinkedListRotate()
{
  std::cout << "\nTest rotation of single linked lists\n";
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);
  head->next->next->next->next->next = new Node(6);
  head->next->next->next->next->next->next = new Node(7);

  //Initial list.
  std::cout << "Initial list: ";
  PrintList(head);

  //Rotate the list.
  head = SingleLinkedListRotate(head, 4);
  std::cout << "Rotated list (4 rotations): ";
  PrintList(head);

  //Rotate the list.
  head = SingleLinkedListRotate(head, 3);
  std::cout << "Rotated list (3 rotations): ";
  PrintList(head);

  //Rotate the list.
  head = SingleLinkedListRotate(head, 70);
  std::cout << "Rotated list (70 rotations): ";
  PrintList(head);
}
