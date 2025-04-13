/*
 * Description:
 * Program to check if tree2 is subtree of tree1.
 *
 * Approach 1: Recursive naive approach.
 * TC: O(n^2), SC: O(n)
 * Created on: 4/12/2025
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int d)
  {
    data = d;
    left = NULL;
    right = NULL;
  }
};


//Helper API for approach v1 - recursive approach.
//It checks if trees are identical.
bool IsIdentical(Node *root1, Node *root2)
{
  if (root1 == NULL && root2 == NULL) {
    return true;
  }
  if (root1 == NULL || root2 == NULL) {
    return false;
  }

  return ((root1->data == root2->data) &&
    IsIdentical(root1->left, root2->left) && IsIdentical(root1->right, root2->right));
}

//Process nodes in pre-order manner.
//If current node data mismatch, check for left node then right node.
bool IsSubTree_v1 (Node *root1, Node *root2)
{
  if (root2 == NULL) {
    return true;
  }
  if (root1 == NULL) {
    return false;
  }

  if (IsIdentical(root1, root2)) {
    return true;
  }
  return (IsSubTree_v1(root1->left, root2) || IsSubTree_v1(root1->right, root2));
}

/**********************************************************************************************************************/

//Helper API to compute inorder.
void ComputeInOrder(Node *root, std::vector<int> &inorder)
{
  if (root == NULL) {
    return;
  }
  ComputeInOrder(root->left, inorder);
  inorder.push_back(root->data);
  ComputeInOrder(root->right, inorder);
}

//Helper API to compute pre-order.
void ComputePreOrder(Node *root, std::vector<int> &preorder)
{
  if (root == NULL) {
    return;
  }
  preorder.push_back(root->data);
  ComputePreOrder(root->left, preorder);
  ComputePreOrder(root->right, preorder);
}

//TODO: Implement KMP algorithm for subarray check implementation.
bool IsSubArray(std::vector<int> orderR1, std::vector<int> orderR2)
{
  return true;
}

//Approach #2: For a tree to be subtree of another tree:
//a. PreOrder and InOrder of subtree will be substring/subarray of preorder and inorder of main tree respectively.
//TC: O(n) as substring can be implemented using KMP algorithm in O(n) also Inorder and Preorder can be computed in O(n)
bool IsSubTree_v2(Node *root1, Node *root2)
{
  if (root2 == NULL) {
    return true;
  }
  if (root1 == NULL) {
    return false;
  }

  std::vector<int> inorderR1;
  std::vector<int> inorderR2;
  std::vector<int> preorderR1;
  std::vector<int> preorderR2;

  ComputeInOrder(root1, inorderR1);
  ComputeInOrder(root2, inorderR2);
  ComputePreOrder(root1, preorderR1);
  ComputePreOrder(root2, preorderR2);

  std::cout << "InOrder primary tree: ";
  for (int i = 0; i < inorderR1.size(); i++) {
    std::cout << inorderR1[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "InOrder secondary tree: ";
  for (int i = 0; i < inorderR2.size(); i++) {
    std::cout << inorderR2[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "PreOrder primary tree: ";
  for (int i = 0; i < preorderR1.size(); i++) {
    std::cout << preorderR1[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "InOrder secondary tree: ";
  for (int i = 0; i < preorderR2.size(); i++) {
    std::cout << preorderR2[i] << " ";
  }
  std::cout << std::endl;

  return IsSubArray(preorderR1, preorderR2) && IsSubArray(inorderR1, inorderR2);
}


void Test_IsSubTree()
{
  //Tree #1
  Node *root1 = nullptr;
  root1 = new Node(4);
  root1->left = new Node(2);
  root1->right = new Node(6);
  root1->left->left = new Node(1);
  root1->left->right = new Node(3);
  root1->right->left = new Node(5);
  root1->right->right = new Node(7);

  //Tree #2
  Node *root2 = nullptr;
  root2 = new Node(2);
  root2->left = new Node(1);
  root2->right = new Node(3);

  //Tree #3
  Node *root3 = nullptr;
  root3 = new Node(6);
  root3->left = new Node(5);
  root3->right = new Node(7);

  std::cout << "\nTest IsSubtree!!!\n";

  //Approach 1: Recursive approach.
  std::cout << "Test using recursive approach!!!\n";
  std::cout << "Test case 1: Tree#2 is " << (IsSubTree_v1(root1, root2) ? "" : "not") << " subtree of Tree#1\n";
  std::cout << "Test case 2: Tree#3 is " << (IsSubTree_v1(root1, root3) ? "" : "not") << " subtree of Tree#1\n";
  std::cout << "Test case 3: Tree#2 is " << (IsSubTree_v1(root3, root2) ? "" : "not") << " subtree of Tree#3\n";

  //Approach 2: Using subarray check for inorder and preorder approach.
  std::cout << "Test using subarray check for inorder and preorder for both trees.!!!\n";
  std::cout << "Test case 1: \n";
  bool result = IsSubTree_v2(root1, root2);
  std::cout << "Tree#2 is " << (result ? "" : "not") << " subtree of Tree#1\n";
  result = IsSubTree_v2(root1, root3);
  std::cout << "Tree#3 is " << (result ? "" : "not") << " subtree of Tree#1\n";
  result = IsSubTree_v2(root3, root2);
  std::cout << "Tree#2 is " << (result ? "" : "not") << " subtree of Tree#3\n";

}