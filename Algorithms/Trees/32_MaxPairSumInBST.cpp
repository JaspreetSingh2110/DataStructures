/*
 * Description:
 * Program to find pair nodes with target sum.
 *
 * Approach: Get inorder format of tree in array.
 * Use array algorithm to find pair.
 * TC: O(n), SC:O(n)
 *
 * Created on: 4/19/2025
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include<iostream>
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


void GetInorder(BSTNode *root, std::vector<int> &inorder)
{
  if (root == NULL) {
    return;
  }
  GetInorder(root->left, inorder);
  inorder.push_back(root->data);
  GetInorder(root->right, inorder);
}


std::pair<int, int> GetPairNodesWithTargetSum(BSTNode *root, int targetSum)
{
  std::pair<int,int> result = std::make_pair(-1, -1);;
  if (root == NULL) {
    result;
  }

  //Get inorder of binary search tree.
  std::vector <int> inorder;
  GetInorder(root, inorder);
  int left = 0;
  int right = inorder.size() - 1;

  while (left < right) {
    if (inorder[left] + inorder[right] == targetSum) {
      result = std::make_pair(inorder[left], inorder[right]);
      return result;
    }

    if (inorder[left] + inorder[right] > targetSum) {
      right--;
    }
    else {
      left++;
    }
  }

  return result;
}


void Test_FindPairOfNodesWithTargetSum()
{
  // BST structure
  //
  //        15
  //       /  \
  //     10   20
  //    / \   / \
  //   8  12 16 25

  BSTNode* root = new BSTNode(15);
  root->left = new BSTNode(10);
  root->right = new BSTNode(20);
  root->left->left = new BSTNode(8);
  root->left->right = new BSTNode(12);
  root->right->left = new BSTNode(16);
  root->right->right = new BSTNode(25);

  int target = 35;
  std::cout << "\nTest to find the pair of nodes with target sum!!!\n";
  std::pair<int, int> result = GetPairNodesWithTargetSum(root, target);
  if (result.first != -1) {
    std::cout << "Test #1: Target sum #35 is achieved using node with values: "
              << result.first << " and " << result.second << "\n";
  }
  else {
    std::cout << "Test #1: Target sum #35 is not achieved using any pair of nodes!!!\n";
  }

  //Test 2.
  target = 55;
  result = GetPairNodesWithTargetSum(root, target);
  if (result.first != -1) {
    std::cout << "Test #2: Target sum #55 is achieved using node with values: "
              << result.first << " and " << result.second << "\n";
  }
  else {
    std::cout << "Test #2: Target sum #55 is not achieved using any pair of nodes!!!\n";
  }
}