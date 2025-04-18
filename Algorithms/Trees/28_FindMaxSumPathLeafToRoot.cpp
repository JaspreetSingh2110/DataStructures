/*
 * Description:
 * Program to find the path with max sum b/w root node and leaf node in tree.
 *
 * TC: O(n), SC: O(h)
 *
 * Created on: 4/18/2025
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

class BTreeNode {
  public:
  int data;
  BTreeNode *left;
  BTreeNode *right;

  BTreeNode(int data)
  {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};


void FindMaxSumPathHelper(BTreeNode *root, int currentSum, int &maxSum)
{
  if (root == NULL) {
    return;
  }

  //Add current node value to current sum.
  currentSum += root->data;

  //Check if leaf node, compare current sum for this leaf node with maxSum
  if (root->left == NULL && root->right == NULL) {
    maxSum = std::max(currentSum, maxSum);
    return;
  }
  FindMaxSumPathHelper(root->left, currentSum, maxSum);
  FindMaxSumPathHelper(root->right, currentSum, maxSum);
}

int FindMaxSumPath(BTreeNode *root)
{
  int maxSum = INT_MIN;
  if (root == NULL) {
    return maxSum;
  }
  FindMaxSumPathHelper(root, 0, maxSum);
  return maxSum;
}

void Test_GetMaxSumPath()
{
  BTreeNode *root = nullptr;
  root = new BTreeNode(4);
  root->left = new BTreeNode(2);
  root->right = new BTreeNode(6);
  root->left->left = new BTreeNode(1);
  root->left->right = new BTreeNode(3);
  root->right->left = new BTreeNode(5);
  root->right->right = new BTreeNode(7);

  std::cout << "\nTest to find maximum sum path b/w root and leaf node in a binary tree\n";
  /**************************************************************************************/

  std::cout << "Testcase #1: Max sum for path b/w root and leaf node in a tree is: "
            << FindMaxSumPath(root) << std::endl;
}
