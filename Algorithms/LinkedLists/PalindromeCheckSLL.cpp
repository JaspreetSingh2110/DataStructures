/*
* Description:
 * Program to check if given SLL is palindrome.
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

static bool IsIdentical(Node* head1, Node* head2)
{
  while (head1 && head2) {
    if (head1->data != head2->data) {
      return false;
    }

    head1 = head1->next;
    head2 = head2->next;
  }
  return true;
}

Node* Reverse(Node* head)
{
  Node* current = head;
  Node* prev = nullptr;
  Node* next;

  while (current != nullptr) {
    next = current->next;

    current->next = prev;
    prev = current;
    current = next;
  }
  return prev;
}

bool IsSLLPalindrome(Node* head)
{
  //Empty list
  if (head == nullptr) {
    return false;
  }

  //Move to middle node of list.
  Node *middle = head;
  Node *temp = head;
  while (temp->next && temp->next->next) {
    temp = temp->next->next;
    middle = middle->next;
  }

  //NOTE: Middle node is the slow pointer next.
  Node* head2 = Reverse(middle->next);
  middle->next = nullptr;

  return IsIdentical(head, head2);
}

void Test_IsSLLPalindrome()
{
  std::cout << "\nTest if given SLL is palindrome\n";
  Node *head1 = new Node(1);
  head1->next = new Node(2);
  head1->next->next = new Node(3);
  head1->next->next->next = new Node(4);
  head1->next->next->next->next = new Node(3);
  head1->next->next->next->next->next = new Node(2);
  head1->next->next->next->next->next->next = new Node(1);

  Node *head2 = new Node(1);
  head2->next = new Node(2);
  head2->next->next = new Node(3);
  head2->next->next->next = new Node(3);
  head2->next->next->next->next = new Node(2);
  head2->next->next->next->next->next = new Node(1);

  Node *head3 = new Node(1);
  head3->next = new Node(2);
  head3->next->next = new Node(3);


  //Check if list is palindrome.
  std::cout << "Testcase 1: ";
  PrintList(head1);
  bool result = IsSLLPalindrome(head1);
  std::cout << "Result: List 1 is " << (result ? "palindrome." : "not palindrome.") << std::endl;

  //Check if list is palindrome.
  std::cout << "Testcase 2: ";
  PrintList(head2);
  result = IsSLLPalindrome(head2);
  std::cout << "Result: List 2 is " << (result ? "palindrome." : "not palindrome.") << std::endl;

  //Check if list is palindrome.
  std::cout << "Testcase 3: ";
  PrintList(head3);
  result = IsSLLPalindrome(head3);
  std::cout << "Result: List 3 is " << (result ? "palindrome." : "not palindrome.") << std::endl;
}
