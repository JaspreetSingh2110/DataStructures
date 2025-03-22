/*
 * Description:
 * Program to check if tree is symmetric i.e. the one half is mirror of other half.
 *
 * Created on: 3/22/2025
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
  left = NULL;
  right = NULL;
 }
};


// *********************** Approach #1: Recursive **************************
// TC: O(n), SC: O(h)
bool IsMirror_v1(BSTNode *root1, BSTNode *root2)
{
  if (root1 == NULL && root2 == NULL) {
    return true;
  }

  if ((root1 == NULL) || (root2 == NULL) || (root1->data != root2->data)) {
    return false;
  }

  return (IsMirror_v1(root1->left, root2->right) &&
    IsMirror_v1(root1->right, root2->left));
}


bool IsSymmetricTree_v1(BSTNode *root)
{
  if (root == NULL) {
    return true;
  }
  return IsMirror_v1(root->left, root->right);
}

// *********************** Approach #2: Iterative using queue **************************
// TC: O(n), SC: O(n)
bool IsSymmetricTree_v2(BSTNode *root)
{
  if (root == NULL) {
    return true;
  }

  std::queue<BSTNode *> q;
  q.push(root->left);
  q.push(root->right);

  while (!q.empty()) {
    BSTNode *node1 = q.front();
    q.pop();
    BSTNode *node2 = q.front();
    q.pop();

    if (node1 == NULL && node2 == NULL) {
      continue;
    }

    //Invalid case
    if (node1 == NULL || node2 == NULL || node1->data != node2->data) {
      return false;
    }

    q.push(node1->left);
    q.push(node2->right);
    q.push(node1->right);
    q.push(node2->left);
  }

  return true;
}


void Test_SymmetricTree()
{
  BSTNode *root1 = nullptr;
  root1 = new BSTNode(50);
  root1->left = new BSTNode(20);
  root1->right = new BSTNode(60);
  root1->left->left = new BSTNode(10);
  root1->left->right = new BSTNode(30);
  root1->right->left = new BSTNode(40);
  root1->right->right = new BSTNode(50);
  root1->right->right->left = new BSTNode(45);

  BSTNode *root2 = nullptr;
  root2 = new BSTNode(50);
  root2->left = new BSTNode(20);
  root2->right = new BSTNode(20);
  root2->left->left = new BSTNode(10);
  root2->left->right = new BSTNode(30);
  root2->right->left = new BSTNode(30);
  root2->right->right = new BSTNode(10);

  std::cout << "\nProgram to check if tree is a symmetric tree\n";

  bool result = IsSymmetricTree_v1(root1);
  std::cout << "Using recursive approach:  Test case #1:  Tree is " << ((result == true) ? "SYMMETRIC" : "NOT SYMMETRIC" )<< ".\n";
  result = IsSymmetricTree_v1(root2);
  std::cout << "Using recursive approach:  Test case #2:  Tree is " << ((result == true) ? "SYMMETRIC" : "NOT SYMMETRIC" )<< ".\n";

  result = IsSymmetricTree_v2(root1);
  std::cout << "Using iterative approach:  Test case #1:  Tree is " << ((result == true) ? "SYMMETRIC" : "NOT SYMMETRIC" )<< ".\n";
  result = IsSymmetricTree_v2(root2);
  std::cout << "Using iterative approach:  Test case #2:  Tree is " << ((result == true) ? "SYMMETRIC" : "NOT SYMMETRIC" )<< ".\n";
}