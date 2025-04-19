/*
 * Description:
 * Program to transform a binary search tree to maximum sum tree.
 * i.e. each node value shall be replaced by the sum value of all nodes greater than given node value.
 * TC: O(n)
 *
 * Created on: 4/20/2025
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>

class BSTNode {
  public:
  int data;
  BSTNode* left;
  BSTNode* right;

  BSTNode(int data)
  {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};


//Helper to print inorder.
static void PrintInOrder(BSTNode *root)
{
  if (root == NULL) {
    return;
  }
  PrintInOrder(root->left);
  std::cout << root->data << " ";
  PrintInOrder(root->right);
}

void TransformBSTree(BSTNode *root, int &sum)
{
  if (root == NULL) {
    return;
  }

  TransformBSTree(root->right, sum);

  //Update node's value.
  sum += root->data;
  root->data = sum - root->data;

  TransformBSTree(root->left, sum);
}

void TransformBSTToMaxSumTree(BSTNode *root)
{
  int sum = 0;
  TransformBSTree(root, sum);
}

void Test_TransformBSTToMaxSumTree()
{
  // Constructing the BST
  //     11
  //    /  \
  //   2    29
  //  / \   / \
  // 1   7 15  40
  //             \
  //              50

  BSTNode* root = new BSTNode(11);
  root->left = new BSTNode(2);
  root->right = new BSTNode(29);
  root->left->left = new BSTNode(1);
  root->left->right = new BSTNode(7);
  root->right->left = new BSTNode(15);
  root->right->right = new BSTNode(40);
  root->right->right->right = new BSTNode(50);

  std::cout << "\nTest to transform a binary search tree to max sum tree!!!\n";
  std::cout << "Tree before transformation: \n";
  PrintInOrder(root);

  std::cout << "\nTree after transformation: \n";
  TransformBSTToMaxSumTree(root);
  PrintInOrder(root);
  std::cout << std::endl;
}
