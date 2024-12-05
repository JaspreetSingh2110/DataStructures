/*
 * Description:
 * Program to delete node from list without head pointer.
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

void DeleteNodeWithoutHeadPointer(Node* delNode)
{
  if (delNode == nullptr) {
    return;
  }

  //Copy the value from next node.
  delNode->data = delNode->next->data;

  //Update the pointers and delete the next node.
  Node* temp = delNode->next;
  delNode->next = temp->next;
  delete temp;
}

void Test_DeleteNodeWithoutHeadPointer()
{
  std::cout << "\nTest deletion of node without head pointer in single linked lists\n";
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
  DeleteNodeWithoutHeadPointer(head->next->next->next);
  std::cout << "List after deleting 4: ";
  PrintList(head);
}
