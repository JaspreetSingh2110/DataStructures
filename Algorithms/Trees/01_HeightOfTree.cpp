/*
 * Description:
 * Program to find height of Binary Tree.
 *
 * Created on: 3/19/2025
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

//Recursive approach.
int GetHeight_v1(BSTNode *root)
{
  if (root == nullptr)
  {
    return 0;
  }
  return (1 + std::max(GetHeight_v1(root->left), GetHeight_v1(root->right)));
}


// Level order traversal approach.
int GetHeight_v2(BSTNode *root)
{
  if (root == nullptr)
  {
    return 0;
  }

  int height = 0;
  int nodesInCurrentLevel = 1;
  int nodesInNextLevel = 0;
  std::queue<BSTNode *> q;
  q.push(root);

  while (!q.empty()) {
    BSTNode *node = q.front();
    q.pop();
    nodesInCurrentLevel--;

    if (node->left != nullptr) {
      q.push(node->left);
      nodesInNextLevel++;
    }
    if (node->right != nullptr) {
      q.push(node->right);
      nodesInNextLevel++;
    }

    if (nodesInCurrentLevel == 0) {
      height++;
      nodesInCurrentLevel = nodesInNextLevel;
      nodesInNextLevel = 0;
    }
  }
  return height;
}


void Test_HeightOfBinarySearchTree()
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

  std::cout << "Program to find the height of tree\n";
  std::cout << "Height of binary tree using recursive approach is: " << GetHeight_v1(root) << std::endl;
  std::cout << "Height of binary tree using level traversal approach is: " << GetHeight_v2(root) << std::endl;
}