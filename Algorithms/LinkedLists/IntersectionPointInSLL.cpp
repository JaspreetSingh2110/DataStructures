/*
 * Description:
 * Approach 1: Using hashing. (Not implemented)
 *
 * Approach 2: Using difference in node counts.
 * 1. Get lengths of both list. say l1 and l2.
 * 2. Whichever list is greater, find difference. |l1-l2|.
 * 3. Move pointer of longer list by |l1-l2| nodes. That node is intersection node.
 *
 * Approach 3: Two pointer approach.
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

int GetNodesCount(Node* head)
{
  int count = 0;
  while (head != nullptr) {
    count++;
    head = head->next;
  }
  return count;
}


//Helper API for approach 2.
Node* FindIntersectionPoints_v2_Helper(Node* head1, Node* head2, int diffCnt)
{
  Node* temp1 = head1;
  Node* temp2 = head2;

  //Traverse the longer list by diffCnt
  int i = 0;
  while (i < diffCnt) {
    temp1 = temp1->next;
    i++;
  }

  //Traverse both list pointers till intersection node is reached.
  while (temp1 != nullptr && temp2 != nullptr) {
    if (temp1->data == temp2->data) {
      return temp1;
    }
    temp1 = temp1->next;
    temp2 = temp2->next;
  }

  //No intersection point.
  return nullptr;
}

//Approach 2: Using difference in lengths.
Node* FindIntersectionPoints_v2(Node* head1, Node* head2)
{
  //Base case.
  if (head1 == nullptr || head2 == nullptr) {
    return nullptr;
  }

  int count1 = GetNodesCount(head1);
  int count2 = GetNodesCount(head2);

  if (count1 > count2) {
    int diff = count1 - count2;
    return FindIntersectionPoints_v2_Helper(head1, head2, diff);
  }
  else {
    int diff = count2 - count1;
    return FindIntersectionPoints_v2_Helper(head1, head2, diff);
  }
}


//Approach 3: Using double pointers.
Node* FindIntersectionPoints_v3(Node* head1, Node* head2)
{
  //Base case.
  if (head1 == nullptr || head2 == nullptr) {
    return nullptr;
  }

  //Pointers for traversal.
  Node* temp1 = head1;
  Node* temp2 = head2;

  while (temp1 != temp2) {
    if (temp1) {
      temp1 = temp1->next;
    } else {
      temp1 = head2;
    }

    if (temp2) {
      temp2 = temp2->next;
    } else {
      temp2 = head1;
    }
  }
  return temp1;
}


void Test_SLLIntersectionPoints()
{
  std::cout << "\nTest find intersection points in linked lists\n";
  Node *head1 = new Node(1);
  head1->next = new Node(2);
  head1->next->next = new Node(3);
  head1->next->next->next = new Node(4);
  Node* node5 = new Node(5);
  head1->next->next->next->next = node5;
  head1->next->next->next->next->next = new Node(6);
  head1->next->next->next->next->next->next = new Node(7);

  //List 2.
  Node *head2 = new Node(11);
  head2->next = new Node(22);
  head2->next->next = node5;

  //List 3.
  Node *head3 = new Node(11);
  head3->next = new Node(22);
  head3->next->next = new Node(33);

  //Initial list.
  std::cout << "Initial list #1: ";
  PrintList(head1);
  std::cout << "Initial list #2: ";
  PrintList(head2);

  //Find intersection point in SLL.
  //Approach 2: Using difference in length of list.
  Node* intersectNode = FindIntersectionPoints_v2(head1, head2);
  if (intersectNode != nullptr) {
    std::cout << "List intersect at node (approach #2): " << intersectNode->data << std::endl;
  }
  else {
    std::cout << "List does not intersect at any node." << std::endl;
  }

  //Approach 3: Using two pointers.
  intersectNode = FindIntersectionPoints_v3(head1, head2);
  if (intersectNode != nullptr) {
    std::cout << "List intersect at node (approach #3): " << intersectNode->data << std::endl;
  }
  else {
    std::cout << "List does not intersect at any node." << std::endl;
  }

  //Test when list does not intersect.
  intersectNode = FindIntersectionPoints_v3(head2, head3);
  if (intersectNode != nullptr) {
    std::cout << "List intersect at node (approach #3): " << intersectNode->data << std::endl;
  }
  else {
    std::cout << "List does not intersect at any node." << std::endl;
  }
}