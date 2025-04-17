/*
 * Description:
 * Program to print ancestors for given node.
 *
 * Approach #1: Using recursion.
 * TC: O(n), SC: O(h)
 *
 * Created on: 4/17/2025
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <stack>
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

//Approach #1: Recursive approach
bool GetAncestorsOfNode_v1(BTreeNode *root, int key, std::vector<BTreeNode> &ancestors)
{
  if (root == NULL) {
    return false;
  }

  //If target key is found.
  if (root->data == key) {
    return true;
  }

  if (GetAncestorsOfNode_v1(root->left, key, ancestors) ||
    GetAncestorsOfNode_v1(root->right, key, ancestors)) {
    ancestors.push_back(*root);
    return true;
  }
  return false;
}


void Test_GetAncestorsOfNode()
{
  BTreeNode *root = nullptr;
  root = new BTreeNode(4);
  root->left = new BTreeNode(2);
  root->right = new BTreeNode(6);
  root->left->left = new BTreeNode(1);
  root->left->right = new BTreeNode(3);
  root->right->left = new BTreeNode(5);
  root->right->right = new BTreeNode(7);

  std::cout << "\nTest to print ancestors of node in a binary tree\n";
  /**************************************************************************************/
  std::vector<BTreeNode> ancestors;

  std::cout << "Testcase #1: Ancestors for node with key '1' in a tree are: ";
  ancestors.clear();
  GetAncestorsOfNode_v1(root, 1, ancestors);
  for (auto ancestor : ancestors) {
    std::cout << ancestor.data << " ";
  }
  std::cout << std::endl;

  std::cout << "Testcase #2: Ancestors for node with key '3' in a tree are: ";
  ancestors.clear();
  GetAncestorsOfNode_v1(root, 3, ancestors);
  for (auto ancestor : ancestors) {
    std::cout << ancestor.data << " ";
  }
  std::cout << std::endl;

  std::cout << "Testcase #3: Ancestors for node with key '7' in a tree are: ";
  ancestors.clear();
  GetAncestorsOfNode_v1(root, 7, ancestors);
  for (auto ancestor : ancestors) {
    std::cout << ancestor.data << " ";
  }
  std::cout << std::endl;

  std::cout << "Testcase #4: Ancestors for node with key '4' in a tree are: ";
  ancestors.clear();
  GetAncestorsOfNode_v1(root, 4, ancestors);
  for (auto ancestor : ancestors) {
    std::cout << ancestor.data << " ";
  }
  std::cout << std::endl;

  std::cout << "Testcase #5: Ancestors for node with key '10' in a tree are: ";
  ancestors.clear();
  GetAncestorsOfNode_v1(root, 10, ancestors);
  for (auto ancestor : ancestors) {
    std::cout << ancestor.data << " ";
  }
  std::cout << std::endl;
}
