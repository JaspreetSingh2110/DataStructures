/*
 * Description:
 * Program to delete nodes outside given range in BST.
 * TC: O(n), SC: O(h)
 *
 * Created on: 4/19/2025
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>

class BSTNode {
  public:
  int data;
  BSTNode *left;
  BSTNode *right;

  BSTNode(int data)
  {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};


void PrintInOrder(BSTNode *root)
{
  if (root == NULL) {
    return;
  }
  PrintInOrder(root->left);
  std::cout << root->data << " ";
  PrintInOrder(root->right);
}


BSTNode* RemoveNodesOutsideRange(BSTNode *root, int min, int max)
{
  if (root == NULL) {
    return NULL;
  }

  //Not updating directly the left and right pointer in root, because it can be NULL.
  //Accessing it later down in code, can lead to exception.
  BSTNode *left = RemoveNodesOutsideRange(root->left, min, max);
  BSTNode *right = RemoveNodesOutsideRange(root->right, min, max);

  // If in valid range.
  if (root->data >= min && root->data <= max) {
    root->left = left;
    root->right = right;
    return root;
  }
  else if (root->data < min) {
    return right;
  }
  else {
    return left;
  }
}


void Test_RemoveNodesOutsideRangeInBST()
{
  // BST
  //          6
  //       /    \
  //     -13     14
  //       \    /  \
  //       -8 13    15
  //         /
  //        7
  BSTNode* root = new BSTNode(6);
  root->left = new BSTNode(-13);
  root->right = new BSTNode(14);
  root->left->right = new BSTNode(-8);
  root->right->left = new BSTNode(13);
  root->right->right = new BSTNode(15);
  root->right->left->left = new BSTNode(7);

  int low = -10, high = 13;

  std::cout << "\nTest to remove the nodes with values outside range in BST!!!\n";
  std::cout << "Inorder print for original tree: -> ";
  PrintInOrder(root);
  std::cout << std::endl;

  std::cout << "Inorder print for resulted tree (after removing elements outside range [-8,13]): -> ";
  BSTNode* updatedRoot = RemoveNodesOutsideRange(root, low, high);
  PrintInOrder(updatedRoot);
  std::cout << std::endl;
}