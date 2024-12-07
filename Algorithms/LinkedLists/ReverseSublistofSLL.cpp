/*
 * Description:
 * Program to reverse Sub list of SLL.
 *
 * Created on: 07/12/24
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

Node* ReverseSLL(Node* head)
{
  Node* prev = nullptr;
  Node* curr = head;
  Node* next = nullptr;
  while (curr != nullptr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

//Approach 1: Two traversals.
Node* ReverseSubListSLL_v1(Node* head, int start, int end)
{
  //Base case.
  if (head == nullptr) {
    return nullptr;
  }

  //Invalid case
  if ((start == end) || (start > end)) {
    return head;
  }

  Node* prev = nullptr;  //Pointer to 1 node prev to start position (start -1).
  Node* first = nullptr; //Pointer to first node of sublist (start).
  Node* last = nullptr;  //Pointer to last node of sublist (end).
  Node* next = nullptr;  //Pointer to node next to last node of sublist to be reversed (end + 1).

  //Assign pointers.
  Node* temp = head;
  for (int i = 1; i <= end; i++) {
    if (i == start - 1) {
      prev = temp;
    }
    else if (i == start) {
      first = temp;
    }
    else if (i == end) {
      last = temp;
      next = temp->next;
    }
    temp = temp->next;
  }

  //Break links
  last->next = nullptr;

  //Reverse the sub list.
  Node* temp2 = ReverseSLL(first);

  //If start was first node in list
  if (prev == nullptr) {
    head = temp2;
  } else {
    prev->next = temp2;
  }

  first->next = next;
  return head;
}

//Approach 2: Single traversal.
Node* ReverseSubListSLL_v2(Node* head, int start, int end)
{
  //Base case.
  if (head == nullptr) {
    return nullptr;
  }

  //Invalid case
  if ((start == end) || (start > end)) {
    return head;
  }

  Node* prev = head;  //Pointer to 1 node prev to start position (start -1).
  Node* current = head; //Pointer to first node of sublist (start).
  //Process till first node to be reversed.
  for (int i = 1; i < start; i++) {
    prev = current;
    current = current->next;
  }

  //Reverse the sublist
  Node* revHead = current;
  Node* revTail = nullptr;
  Node* nextNode = nullptr;
  for (int i = start; i <= end; i++) {
    nextNode = current->next;
    current->next = revTail;
    revTail = current;
    current = nextNode;
  }

  //Assign back links.
  if (prev == nullptr) {
    head = revTail;
  }
  else {
    prev->next = revTail;
  }

  revHead->next = current;
  return head;
}

void Test_ReverseSubListSLL()
{
  std::cout << "\nTest rever of sublist in SLL\n";
  Node *head1 = new Node(1);
  head1->next = new Node(2);
  head1->next->next = new Node(3);
  head1->next->next->next = new Node(4);
  head1->next->next->next->next = new Node(5);
  head1->next->next->next->next->next = new Node(6);
  head1->next->next->next->next->next->next = new Node(7);
  head1->next->next->next->next->next->next->next = new Node(8);
  head1->next->next->next->next->next->next->next->next = new Node(9);
  head1->next->next->next->next->next->next->next->next->next = new Node(10);

  std::cout << "Initial list: ";
  PrintList(head1);

  //Reverse sub list
  head1 = ReverseSubListSLL_v1(head1, 5, 8);
  std::cout << "List after reversal of sublist in SLLs (2 traversals): ";
  PrintList(head1);

  //Reverse sub list again, revert to original list
  head1 = ReverseSubListSLL_v2(head1, 5, 8);
  std::cout << "List after reversal of sublist in SLLs (1 traversal): ";
  PrintList(head1);
}