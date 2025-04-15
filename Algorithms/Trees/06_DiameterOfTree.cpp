/*
 * Description:
 * Program to find diameter of tree.
 * Diameter is basically height of left subtree + height of right subtree.
 *
 * Created on: 3/23/2025
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */


#include <iostream>

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


int GetDiameterOfTree_Recursive(BSTNode *root, int &result)
{
  if (root == NULL) {
    return 0;
  }

  int lHeight = GetDiameterOfTree_Recursive(root->left, result);
  int rHeight = GetDiameterOfTree_Recursive(root->right, result);

  result = std::max(result, lHeight + rHeight);

  return 1 + std::max(lHeight, rHeight);
}

//Recursive approach - bottom up.
//TC: O(n)
int GetDiameterOfTree(BSTNode *root)
{
  int result = 0;
  GetDiameterOfTree_Recursive(root, result);
  return result;;
}


void Test_GetDiameterOfTree()
{
  // Constructed binary tree is
  //          5
  //        /   \
  //       8     6
  //      / \   /
  //     3   7 9
  BSTNode* root1 = new BSTNode(5);
  root1->left = new BSTNode(8);
  root1->right = new BSTNode(6);
  root1->left->left = new BSTNode(3);
  root1->left->right = new BSTNode(7);
  root1->right->left = new BSTNode(9);

  BSTNode *root2 = nullptr;
  root2 = new BSTNode(50);
  root2->left = new BSTNode(20);
  root2->right = new BSTNode(20);
  root2->left->left = new BSTNode(10);
  root2->left->right = new BSTNode(30);
  root2->left->left->left = new BSTNode(100);
  root2->right->left = new BSTNode(30);
  root2->right->right = new BSTNode(10);

  std::cout << "\nProgram to find the diameter of tree\n";
  std::cout << "Using recursive approach:  Test case #1:  Diameter of tree is " << GetDiameterOfTree(root1) << ".\n";
  std::cout << "Using recursive approach:  Test case #2:  Diameter of tree is " << GetDiameterOfTree(root2) << ".\n";
}