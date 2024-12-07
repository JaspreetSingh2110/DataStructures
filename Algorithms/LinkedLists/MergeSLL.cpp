/*
* Description:
 * Program to merge two SLLs at alternating positions.
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

Node* MergeSLLsAlternatePositions(Node* head1, Node* head2)
{
  //If either of list is empty, return other list pointer.
  if (head1 == nullptr) {
    return head2;
  }
  if (head2 == nullptr) {
    return head1;
  }

  Node* head = head1;
  Node* temp1 = head1->next;
  Node* temp2 = head2;
  Node* temp = head;

  //Merge
  while (temp1 != nullptr && temp2 != nullptr) {
    //Assign node from list2
    temp->next = temp2;
    temp2 = temp2->next;
    temp = temp->next;

    //Assign node from list1.
    temp->next = temp1;
    temp1 = temp1->next;
    temp = temp->next;
  }

  //Append the remaining list if present.
  if (temp1 != nullptr) {
    temp->next = temp1;
  }
  if (temp2 != nullptr) {
    temp->next = temp2;
  }
  return head;
}


void Test_MergeSLLsAlternatePositions()
{
  std::cout << "\nTest deletion of last occurrence of node in single linked lists\n";
  Node *head1 = new Node(1);
  head1->next = new Node(2);
  head1->next->next = new Node(3);
  head1->next->next->next = new Node(4);
  head1->next->next->next->next = new Node(5);

  Node *head2 = new Node(11);
  head2->next = new Node(22);
  head2->next->next = new Node(33);
  head2->next->next->next = new Node(44);
  head2->next->next->next->next = new Node(55);

  //Initial list.
  std::cout << "Initial list #1: ";
  PrintList(head1);
  std::cout << "Initial list #2: ";
  PrintList(head2);

  //Merge the SLLs in alternating positions.
  Node* head = MergeSLLsAlternatePositions(head1, head2);
  std::cout << "List after merge at alternating positions: ";
  PrintList(head);
}