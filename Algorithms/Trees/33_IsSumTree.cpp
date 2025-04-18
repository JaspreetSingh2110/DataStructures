/*
 * Description:
 * Program to check if given tree is sum tree.
 * * TC: O(n), SC:O(n)
 *
 * Created on: 4/19/2025
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include<iostream>
#include <vector>

class BTreeNode {
  public:
  int data;
  BTreeNode *left;
  BTreeNode *right;

  BTreeNode(int d)
  {
    data = d;
    left = NULL;
    right = NULL;
  }
};


bool IsLeafNode(BTreeNode *root)
{
  if ((root == NULL) || (root->left == NULL) && (root->right == NULL)) {
    return true;
  }
  return false;
}

bool IsSumTree(BTreeNode *root)
{
  //For null node or leaf node.
  if (IsLeafNode(root)) {
    return true;
  }

  if (IsSumTree(root->left) && IsSumTree(root->right)) {
    int leftSum = 0;
    int rightSum = 0;
    if (root->left == NULL) {
      leftSum = 0;
    }
    else if (IsLeafNode(root->left)) {
      leftSum = root->left->data;
    }
    else {
      leftSum = 2 * root->left->data;
    }

    if (root->right == NULL) {
      rightSum = 0;
    }
    else if (IsLeafNode(root->right)) {
      rightSum = root->right->data;
    }
    else {
      rightSum = 2 * root->right->data;
    }

    if (leftSum + rightSum == root->data) {
      return true;
    }
    return false;
  }
  return false;
}

void Test_IsSumTree()
{
  // create hard coded tree
  //       26
  //      /  \
  //     10   3
  //    / \    \
  //   4  6     3
  BTreeNode* root = new BTreeNode(26);
  root->left = new BTreeNode(10);
  root->right = new BTreeNode(3);
  root->left->left = new BTreeNode(4);
  root->left->right = new BTreeNode(6);
  root->right->right = new BTreeNode(3);

  BTreeNode *root2 = nullptr;
  root2 = new BTreeNode(4);
  root2->left = new BTreeNode(2);
  root2->right = new BTreeNode(6);
  root2->left->left = new BTreeNode(1);
  root2->left->right = new BTreeNode(3);
  root2->right->left = new BTreeNode(5);
  root2->right->right = new BTreeNode(7);

  std::cout << "\nTest to check if given tree is sum tree!!!\n";
  std::cout << "Test #1: Tree#1 is " << (IsSumTree(root) ? "" : "not") << " a sum tree!!!\n";
  std::cout << "Test #2: Tree#2 is " << (IsSumTree(root2) ? "" : "not") << " a sum tree!!!\n";
}