/*
 * Description:
 * Program to get the lowest common ancestor for node in tree.
 *
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
BTreeNode* GetLowestCommonAncestorsOfNode(BTreeNode *root, int key1, int key2)
{
  if (root == NULL) {
    return NULL;
  }

  //If either of node is found, return node pointer.
  if ((root->data == key1) || (root->data == key2)) {
    return root;
  }

  BTreeNode* leftLca = GetLowestCommonAncestorsOfNode(root->left, key1, key2);
  BTreeNode* rightLca = GetLowestCommonAncestorsOfNode(root->right, key1, key2);

  //If key1 and key2 are found at this current node, return pointer to it.
  if (leftLca && rightLca) {
    return root;
  }

  return leftLca ? leftLca : rightLca;
}

//API to check if nodes are present.
bool IsPresent(BTreeNode *root, int key)
{
  if (root == NULL) {
    return false;
  }
  if (root->data == key) {
    return true;
  }
  return IsPresent(root->left, key) || IsPresent(root->right, key);
}


int FindLCA(BTreeNode *root, int key1, int key2)
{
  if (root == NULL) {
    return -1;
  }
  if (IsPresent(root, key1) && IsPresent(root, key2)) {
    BTreeNode* ancestor = GetLowestCommonAncestorsOfNode(root, key1, key2);
    return (ancestor ? ancestor->data : -1);
  }
  return -1;
}


void Test_GetLowestCommonAncestorOfNode()
{
  BTreeNode *root = nullptr;
  root = new BTreeNode(4);
  root->left = new BTreeNode(2);
  root->right = new BTreeNode(6);
  root->left->left = new BTreeNode(1);
  root->left->right = new BTreeNode(3);
  root->right->left = new BTreeNode(5);
  root->right->right = new BTreeNode(7);

  std::cout << "\nTest to find lowest common ancestor of node in a binary tree\n";
  /**************************************************************************************/

  std::cout << "Testcase #1: Lowest common ancestor for node with key '1' and '3' in a tree is: " <<
    FindLCA(root, 1, 3) << std::endl;
  std::cout << "Testcase #2: Lowest common ancestor for node with key '1' and '7' in a tree is: " <<
    FindLCA(root, 1, 7) << std::endl;
  std::cout << "Testcase #3: Lowest common ancestor for node with key '2' and '8' in a tree is: " <<
    FindLCA(root, 2, 8) << std::endl;
}
