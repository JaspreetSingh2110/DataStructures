/*
 * Description:
 * Program to convert the binary search tree to max heap.
 *
 * Approach #1:
 * Perform inorder traversal and store the node values in array.
 * Traverse the tree now in post order manner and start replacing node values with inorder data in array.
 * TC: O(n), SC: O(n)
 *
 * Approach #2:
 * Perform level order traversal and store the data of nodes in array.
 * Perform max heap.
 * Traverse the tree again in level order and update the values.
 * TC: O(n), SC: O(n)
 *
 * Created on: 4/20/2025
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

class BSTNode {
  public:
  int data;
  BSTNode *left;
  BSTNode *right;
  BSTNode(int d)
  {
    data = d;
    left = NULL;
    right = NULL;
  }
};


static void PrintInOrder(BSTNode *root)
{
  if (root == NULL)
    return;

  PrintInOrder(root->left);
  std::cout << root->data << " ";
  PrintInOrder(root->right);
}

void PrintInOrder(BSTNode *root, std::vector<int> &inorder)
{
  if (root == NULL) {
    return;
  }

  PrintInOrder(root->left, inorder);
  inorder.push_back(root->data);
  PrintInOrder(root->right, inorder);
}

void TransformBSTreeToMaxHeapPostOrderTraversal(BSTNode *root, int &index, std::vector<int> &inorder)
{
  if (root == NULL) {
    return;
  }
  TransformBSTreeToMaxHeapPostOrderTraversal(root->left, index, inorder);
  TransformBSTreeToMaxHeapPostOrderTraversal(root->right, index, inorder);
  root->data = inorder[++index];
}

void TransformBSTToMaxHeap(BSTNode *root)
{
  int index = -1;
  std::vector<int> inorder;
  inorder.clear();
  PrintInOrder(root, inorder);
  TransformBSTreeToMaxHeapPostOrderTraversal(root, index, inorder);
}


void Test_TransformBSTToMaxHeap()
{
  // Constructing the BST
  //      4
  //     /  \
  //    2    6
  //   / \   / \
  //  1   3 5   7

  BSTNode* root = new BSTNode(4);
  root->left = new BSTNode(2);
  root->right = new BSTNode(6);
  root->left->left = new BSTNode(1);
  root->left->right = new BSTNode(3);
  root->right->left = new BSTNode(5);
  root->right->right = new BSTNode(7);

  std::cout << "\nTest to transform a binary search tree to max heap!!!\n";
  std::cout << "Tree before transformation: \n";
  PrintInOrder(root);

  std::cout << "\nTree after transformation: \n";
  TransformBSTToMaxHeap(root);
  PrintInOrder(root);
  std::cout << std::endl;
}