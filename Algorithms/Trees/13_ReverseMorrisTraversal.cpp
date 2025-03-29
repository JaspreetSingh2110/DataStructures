/*
 * Description:
 * Program for reverse morris traversal.
 * TC: O(n), SC: O(n)
 *
 * Created on: 3/30/2025
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

class Node {
  public:
  int data;
  Node *left;
  Node *right;
  Node(int d)
  {
    data = d;
    left = NULL;
    right = NULL;
  }
};

std::vector<int> ReverseMorrisTraversal(Node *root)
{
  std::vector<int> result = std::vector<int>();
  if (root == NULL) {
    return result;
  }

  Node* current = root;
  while (current != NULL) {
    if (current->right == NULL) {
      result.push_back(current->data);
      current = current->left;
    }
    else {
      Node* temp = current->right;
      while ((temp->left != NULL) && (temp->left != current)) {
        temp = temp->left;
      }

      if (temp->left == NULL) {
        temp->left = current;
        current = current->right;
      }
      else {
        temp->left = NULL;
        result.push_back(current->data);
        current = current->left;
      }
    }
  }

  return result;
}

void Test_ReverseMorrisTraversal()
{
  Node *root = nullptr;
  root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(6);
  root->left->left = new Node(1);
  root->left->right = new Node(3);
  root->right->left = new Node(5);
  root->right->right = new Node(7);

  std::cout << "\nTest to perform reverse morris traversal of a tree\n";
  /**************************************************************************************/
  std::vector<int> result;
  result = ReverseMorrisTraversal(root);

  //print result.
  for (auto i : result) {
    std::cout << i << " | ";
  }
  std::cout << std::endl;
}