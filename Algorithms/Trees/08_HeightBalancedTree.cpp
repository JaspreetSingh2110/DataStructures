/*
 * Description:
 * Program to check if given tree is height balanced.
 *
 * TC: O(n) -> Bottom up recursive aproach.
 *
 * Created on: 3/26/2025
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

int GetHeightDifference(BSTNode *root)
{
  if (root == NULL) {
    return 0;
  }

  int lHeight = GetHeightDifference(root->left);
  int rHeight = GetHeightDifference(root->right);

  if (abs(lHeight - rHeight) > 1) {
    return -1;
  }

  return std::max(lHeight, rHeight) + 1;
}

bool IsTreeBalanced(BSTNode *root)
{
  if (root == NULL) {
    return true;
  }
  return (GetHeightDifference(root) > 0);
}

void Test_CheckIfTreesIsBalanced()
{
  BSTNode *root1 = nullptr;
  root1 = new BSTNode(50);
  root1->left = new BSTNode(20);
  root1->right = new BSTNode(60);
  root1->left->left = new BSTNode(10);
  root1->left->right = new BSTNode(30);
  root1->left->left->left = new BSTNode(45);

  BSTNode *root2 = nullptr;
  root2 = new BSTNode(50);
  root2->left = new BSTNode(20);
  root2->right = new BSTNode(60);
  root2->left->left = new BSTNode(10);
  root2->left->right = new BSTNode(30);
  root2->right->left = new BSTNode(40);
  root2->right->right = new BSTNode(50);

  bool result = false;
  std::cout << "Test to check if given trees is balanced\n";

  /**************************************************************************************/
  std::cout << "Test using bottoms up recursive approach\n";
  result = IsTreeBalanced(root1);
  std::cout << "Test 1: Tree is " << (result ? "balanced" : "not balanced") << ".\n";

  result = IsTreeBalanced(root2);
  std::cout << "Test 2: Tree is " << (result ? "balanced" : "not balanced") << ".\n";
}