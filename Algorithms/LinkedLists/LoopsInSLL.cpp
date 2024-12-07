/*
 * Description:
 * Program to detect loop in SLL.
 * Find first node in loop.
 * Remove loop.
 *
 * TC: O(n)
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

Node* FindFirstNodeofLoopSLL(Node* head)
{
  Node* slow = head;
  Node* fast = head;

  //Check if loop is present.
  while (slow && fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      break;
    }
  }

  //If fast pointer reaches end, no loop.
  if (fast == nullptr) {
    return nullptr;
  }

  //If loop is present, find first node.
  //Reset slow to head.
  //Increment each single step, till they point to same node.
  slow = head;
  while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
  }
  return slow;
}

Node* RemoveLoopInSLL(Node* head)
{
  Node* slow = head;
  Node* fast = head;

  while (slow && fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      break;
    }
  }

  //No loop present.
  if (fast == nullptr) {
    return nullptr;
  }

  //Reset slow to head.
  slow = head;

  //If both pointers met at first node.
  if (slow == fast) {
    while (fast->next != slow) {
      fast = fast->next;
    }
  } else {
    while (fast->next != slow->next) {
      fast = fast->next;
      slow = slow->next;
    }
  }

  //Break loop.
  fast->next = nullptr;
  return head;
}

void Test_LoopProblemsSLL()
{
  std::cout << "\nTest loop problems in SLL\n";
  Node *head1 = new Node(1);
  head1->next = new Node(2);
  head1->next->next = new Node(3);
  head1->next->next->next = new Node(4);
  head1->next->next->next->next = new Node(5);
  head1->next->next->next->next->next = new Node(6);

  Node* node7 = new Node(7);
  head1->next->next->next->next->next->next = node7;
  head1->next->next->next->next->next->next->next = new Node(8);
  head1->next->next->next->next->next->next->next->next = new Node(9);
  head1->next->next->next->next->next->next->next->next->next = new Node(10);

  //Create loop.
  head1->next->next->next->next->next->next->next->next->next->next = node7;

   //Reverse sub list
  Node* slow = FindFirstNodeofLoopSLL(head1);
  if (slow == nullptr) {
    std::cout << "Loop not present!!!" << std::endl;
    return;
  }
  std::cout << "Loop is present in list. Start node: " << slow->data << std::endl;

  //Remove loop.
  head1 = RemoveLoopInSLL(head1);
  std::cout << "List after removal of loop from SLL: ";
  PrintList(head1);
}