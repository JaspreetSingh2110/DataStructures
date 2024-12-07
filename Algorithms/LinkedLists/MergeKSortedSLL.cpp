/*
 * Description:
 * Program to merge K-sorted SLL.
 *
 * For time complexity, assume each list has equal nos of nodes.
 *
 * Approach 1: Merge lists one by one.
 * TC:
 * We have below processing of list: n + 2n + 3n + ... + k
 * The sum of this series is n * k * (k + 1) / 2 which is:
 * O(n * k * k)
 *
 * Approach 2: Using min heap.
 * TC: O(n*k*logn) = O(Nlogn), N= total nodes in list.
 *
 * Created on: 07/12/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <queue>

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

Node* MergeTwoSLLs(Node* head1, Node* head2)
{
  //Base case.
  if (head1 == nullptr) {
    return head2;
  }
  if (head2 == nullptr) {
   return head1;
  }

  Node* newHead = new Node(0);
  Node* temp = newHead;
  Node* temp1 = head1;
  Node* temp2 = head2;
  while (temp1 != nullptr && temp2 != nullptr) {
    if (temp1->data < temp2->data) {
      temp->next = temp1;
      temp1 = temp1->next;
    } else {
      temp->next = temp2;
      temp2 = temp2->next;
    }
    temp = temp->next;
  }

  //If pending items for wither of lists.
  if (temp1 != nullptr) {
    temp->next = temp1;
  }
  if (temp2 != nullptr) {
    temp->next = temp2;
  }
  return newHead->next;
}

Node* MergeKSortedSLLs_OneByOne(std::vector<Node*> headP, int k)
{
  //Merge All lists with 0th list.
  for (int i = 1; i < k; i++) {
    std::cout << "Merging list: " << i << "...\n";
    headP[0] = MergeTwoSLLs(headP[0], headP[i]);
  }
  return headP[0];
}


struct compare {
  bool operator() (const Node* a, const Node* b)
  {
    return a->data > b->data;
  }
};

Node* MergeKSortedSLLs_MinHeap(std::vector<Node*> headP, int k)
{
  //Create Min heap.
  std::priority_queue<Node*, std::vector<Node*>, compare> minHeap;

  //Push root nodes of the lists into heap.
  for (int i = 0; i < k; i++) {
    if (headP[i] != nullptr) {
      minHeap.push(headP[i]);
    }
  }

  Node* newHead = new Node(0);
  Node* temp = newHead;
  while (minHeap.empty() == false) {
    //Get smallest node.
    Node* curr = minHeap.top();
    minHeap.pop();

    //Append new node to result sorted list.
    temp->next = curr;
    temp = temp->next;

    //If the list from which node was picked, has more nodes, add it to pq.
    if (curr->next != nullptr) {
      minHeap.push(curr->next);
    }
  }

  //delete first dummy node added
  Node* actualHead = newHead->next;
  delete newHead;
  return actualHead;
}

void Test_MergeKSortedSLLs_OneByOne()
{
  std::cout << "\nTest merge of K sorted single linked lists (using merge one-by-one approach)\n";
  Node *head1 = new Node(1);
  head1->next = new Node(5);
  head1->next->next = new Node(9);
  head1->next->next->next = new Node(12);
  head1->next->next->next->next = new Node(16);

  Node *head2 = new Node(2);
  head2->next = new Node(6);
  head2->next->next = new Node(7);
  head2->next->next->next = new Node(11);
  head2->next->next->next->next = new Node(15);

  Node *head3 = new Node(3);
  head3->next = new Node(8);
  head3->next->next = new Node(10);

  Node *head4 = new Node(4);
  head4->next = new Node(13);
  head4->next->next = new Node(14);

  //Initial list.
  std::cout << "Initial list #1: ";
  PrintList(head1);
  std::cout << "Initial list #2: ";
  PrintList(head2);
  std::cout << "Initial list #3: ";
  PrintList(head3);
  std::cout << "Initial list #4: ";
  PrintList(head4);

  Node *head = nullptr;
  std::vector<Node*> headPointers = {head, head1, head2, head3, head4};

  //Merge K sorted SLLs..
  head = MergeKSortedSLLs_OneByOne(headPointers, headPointers.size());
  std::cout << "List after merge of k sorted SLLs: ";
  PrintList(head);
}


void Test_MergeKSortedSLLs_MinHeap()
{
  std::cout << "\nTest merge of K sorted single linked lists (using min heap)\n";
  Node *head1 = new Node(1);
  head1->next = new Node(5);
  head1->next->next = new Node(9);
  head1->next->next->next = new Node(12);
  head1->next->next->next->next = new Node(16);

  Node *head2 = new Node(2);
  head2->next = new Node(6);
  head2->next->next = new Node(7);
  head2->next->next->next = new Node(11);
  head2->next->next->next->next = new Node(15);

  Node *head3 = new Node(3);
  head3->next = new Node(8);
  head3->next->next = new Node(10);

  Node *head4 = new Node(4);
  head4->next = new Node(13);
  head4->next->next = new Node(14);

  //Initial list.
  std::cout << "Initial list #1: ";
  PrintList(head1);
  std::cout << "Initial list #2: ";
  PrintList(head2);
  std::cout << "Initial list #3: ";
  PrintList(head3);
  std::cout << "Initial list #4: ";
  PrintList(head4);

  std::vector<Node*> headPointers = {head1, head2, head3, head4};

  //Merge K sorted SLLs..
  Node* head = MergeKSortedSLLs_MinHeap(headPointers, headPointers.size());
  std::cout << "List after merge of k sorted SLLs: ";
  PrintList(head);
}

