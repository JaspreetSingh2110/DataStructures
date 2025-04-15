/*
* Description:
 * Program for inorder traversal of tree using Morris Traversal algorithm.
 *
 * TC: O(n)
 * SC: O(1)
 *
 * Created on: 3/20/2025
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <queue>

class BSTNode {
public:
  int data;
  BSTNode *left;
  BSTNode *right;

  BSTNode(int d)
  {
    data = d;
    left = nullptr;
    right = nullptr;
  }
};


std::vector<int> MorrisInorderTraversal(BSTNode *root)
{
  std::vector<int> result;

  BSTNode *current = root;

  while (current != nullptr) {
    if (current->left == nullptr) {
      result.push_back(current->data);
      current = current->right;
    }
    else {
      BSTNode *temp = current->left;
      BSTNode *curr = current;
      while (temp->right != nullptr) {
        temp = temp->right;
      }

      temp->right = current;
      current = current->left;
      curr->left = nullptr;
    }
  }

  return result;
}

void Test_MorrisInorderTraversal()
{
  BSTNode *root = nullptr;
  root = new BSTNode(50);
  root->left = new BSTNode(20);
  root->right = new BSTNode(60);
  root->left->left = new BSTNode(10);
  root->left->right = new BSTNode(30);
  root->right->left = new BSTNode(40);
  root->right->right = new BSTNode(50);
  root->right->right->left = new BSTNode(45);

  std::cout << "Program for inorder traversal of binary tree using Morris traversal algorithm\n";
  std::vector<int> inorder = MorrisInorderTraversal(root);
  std::cout << "Inorder traversal order:\n";
  for (auto i : inorder) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}