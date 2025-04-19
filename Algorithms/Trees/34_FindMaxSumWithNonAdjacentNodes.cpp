/*
 * Description:
 * Program to find the maximum sum using non adjacent nodes.
 * i.e. if a node is selected in computing sum, its children cannot be used.
 *
 * Approach: Recursion with memoisation.
 * TC: O(n), SC: O(n)
 *
 * Created on: 4/20/2025
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <unordered_map>

class BTreeNode {
  public:
  int data;
  BTreeNode *left;
  BTreeNode *right;

  explicit BTreeNode(int d)
  {
    data = d;
    left = NULL;
    right = NULL;
  }
};


int CalculateMaxSum(BTreeNode *root, std::unordered_map<BTreeNode*, int> &memo)
{
  if (root == NULL) {
    return 0;
  }

  //Check if precomputed sum exists.
  if (memo.find(root) != memo.end()) {
    return memo[root];
  }

  //Calculate inclSum and exclSum.
  //Calculate inclSum.
  int inclSum = root->data;
  if (root->left) {
    //As this is inclusive sum, add node values of grandchildren to sum.
    inclSum += CalculateMaxSum(root->left->left, memo);
    inclSum += CalculateMaxSum(root->left->right, memo);
  }
  if (root->right) {
    inclSum += CalculateMaxSum(root->right->left, memo);
    inclSum += CalculateMaxSum(root->right->right, memo);
  }

  int exclSum = 0;
  if (root->left) {
    exclSum += CalculateMaxSum(root->left, memo);
  }
  if (root->right) {
    exclSum += CalculateMaxSum(root->right, memo);
  }

  memo[root] = std::max(inclSum, exclSum);
  return memo[root];
}

int GetMaxSumUsingNonAdjacentNodesInTree(BTreeNode *root)
{
  std::unordered_map<BTreeNode*, int> memo;
  return CalculateMaxSum(root, memo);
}

void Test_GetMaxSumUsingNonAdjacentNodes()
{
  // Creating a binary tree with the following structure:
  //          1
  //         / \
  //        2   3
  //       /   / \
  //      1   4   5

  BTreeNode* root = new BTreeNode(1);
  root->left = new BTreeNode(2);
  root->right = new BTreeNode(3);
  root->right->left = new BTreeNode(4);
  root->right->right = new BTreeNode(5);
  root->left->left = new BTreeNode(1);

  std::cout << "\nTest to calculate maximum sum excluding adjacent nodes!!!\n";
  std::cout << "Test #1: Max sum for given tree is: " << GetMaxSumUsingNonAdjacentNodesInTree(root) << std::endl;
}