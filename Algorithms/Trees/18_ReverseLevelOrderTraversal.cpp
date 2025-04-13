/*
 * Description:
 * Program to traverse the tree in reverse level order manner.
 *
 * Algo: Using stack and queue.
 * TC: O(n), SC: O(n)
 *
 * Created on: 4/14/2025
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <queue>
#include <stack>
#include <vector>

class Node {
  public:
  int data;
  Node* left;
  Node* right;

  Node (int data)
  {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};


std::vector<int> ReverseLevelOrder(Node *root)
{
  std::vector<int> result;
  if (root == NULL) {
    return result;
  }

  std::queue<Node*> q;
  std::stack<int> s;
  q.push(root);

  while (!q.empty()) {
    Node* p = q.front();
    q.pop();
    s.push(p->data);

    if (p->right != NULL) {
      q.push(p->right);
    }
    if (p->left != NULL) {
      q.push(p->left);
    }
  }

  //Push elements from stack to vector.
  while (!s.empty()) {
    result.push_back(s.top());
    s.pop();
  }
  return result;
}

void Test_ReverseLevelOrder()
{
  Node *root1 = nullptr;
  root1 = new Node(4);
  root1->left = new Node(2);
  root1->right = new Node(6);
  root1->left->left = new Node(1);
  root1->left->right = new Node(3);
  root1->right->left = new Node(5);
  root1->right->right = new Node(7);

  std::vector<int> result;

  std::cout << "\nTest to traverse the tree in reverse level order\n";
  std::cout << "Test 1: Reverse level order traversal of tree (using stack and queue): [ ";
  result = ReverseLevelOrder(root1);
  for (auto i : result) {
    std::cout << i << " ";
  }
  std::cout << "]" << std::endl;
}