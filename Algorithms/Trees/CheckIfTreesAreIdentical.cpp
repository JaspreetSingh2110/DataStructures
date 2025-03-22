/*
* Description:
 * Program to check if given binary trees are identical.
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


//Approach using BFS.
bool AreTreesIdentical_v1(BSTNode *root1, BSTNode *root2)
{
  if (root1 == nullptr && root2 == nullptr) {
    return true;
  }

  //Check if only one of them is nullptr.
  if ((root1 && (root2 == nullptr)) || ((root1 == nullptr) && root2)) {
    return false;
  }

  //Check if both nodes are valid but has data mismatch.
  if (root1 && root2 && (root1->data != root2->data)) {
    return false;
  }

  return (AreTreesIdentical_v1(root1->left, root2->left) &&
    AreTreesIdentical_v1(root1->right, root2->right));
}

//Approach using DFS.
bool AreTreesIdentical_v2(BSTNode *root1, BSTNode *root2)
{
  std::queue<BSTNode *> q1;
  std::queue<BSTNode *> q2;

  //Check if only one of them is nullptr.
  if ((root1 && (root2 == nullptr)) || ((root1 == nullptr) && root2)) {
    return false;
  }

  q1.push(root1);
  q2.push(root2);

  while (!q1.empty() && !q2.empty()) {
    BSTNode *nodeTree1 = q1.front();
    BSTNode *nodeTree2 = q2.front();
    q1.pop();
    q2.pop();

    //Validate current node data.
    if (nodeTree1->data != nodeTree2->data) {
      return false;
    }

    //Push child nodes from tree1.
    if (nodeTree1->left && nodeTree2->left) {
      q1.push(nodeTree1->left);
      q2.push(nodeTree2->left);
    }
    else if (nodeTree1->left || nodeTree2->left) {
      return false;
    }

    if (nodeTree1->right && nodeTree2->right) {
      q1.push(nodeTree1->right);
      q2.push(nodeTree2->right);
    }
    else if (nodeTree1->right || nodeTree2->right) {
      return false;
    }
  }
  return true;
}

//Approach using Morris Traversal.
//TC: O(n)
//SC: O(1)
bool AreTreesIdentical_v3(BSTNode *root1, BSTNode *root2)
{
  BSTNode *curr1 = root1;
  BSTNode *curr2 = root2;

  while (curr1 && curr2) {
    //Get next node from first tree.
    if (curr1->data != curr2->data) {
      return false;
    }

    if (curr1->left == nullptr) {
      curr1 = curr1->right;
    }
    else {
      BSTNode *leftNode = curr1->left;
      BSTNode *temp = leftNode;
      while (temp->right) {
        temp = temp->right;
      }

      temp->right = curr1;
      curr1->left = nullptr;
      curr1 = leftNode;
    }

    //Get next node from 2nd tree.
    if (curr2->left == nullptr) {
      curr2 = curr2->right;
    }
    else {
      BSTNode *leftNode = curr2->left;
      BSTNode *temp = leftNode;
      while (temp->right) {
        temp = temp->right;
      }

      temp->right = curr2;
      curr2->left = nullptr;
      curr2 = leftNode;
    }
  }

  if (curr1 || curr2) {
    return false;
  }

  return true;
}



void Test_CheckIfTreesAreIdentical()
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
  root2->right = new BSTNode(60);
  root2->left->left = new BSTNode(10);
  root2->left->right = new BSTNode(30);
  root2->right->left = new BSTNode(40);
  root2->right->right = new BSTNode(50);

  BSTNode *root3 = nullptr;
  root3 = new BSTNode(50);
  root3->left = new BSTNode(20);
  root3->right = new BSTNode(60);
  root3->left->left = new BSTNode(10);
  root3->left->right = new BSTNode(30);
  root3->right->left = new BSTNode(40);
  root3->right->right = new BSTNode(50);
  root3->right->right->left = new BSTNode(45);

  bool result = false;
  std::cout << "Test to check if given trees are identical\n";

  /**************************************************************************************/
  std::cout << "Test using DFS approach\n";
  result = AreTreesIdentical_v1(root1, root3);
  std::cout << "Test 1: Trees are " << (result ? "identical" : "not identical") << ".\n";

  result = AreTreesIdentical_v1(root1, root2);
  std::cout << "Test 2: Trees are " << (result ? "identical" : "not identical") << ".\n";

  /**************************************************************************************/
  std::cout << "Test using BFS approach\n";
  result = AreTreesIdentical_v2(root1, root3);
  std::cout << "Test 1: Trees are " << (result ? "identical" : "not identical") << ".\n";

  result = AreTreesIdentical_v2(root1, root2);
  std::cout << "Test 2: Trees are " << (result ? "identical" : "not identical") << ".\n";

  /**************************************************************************************/
  std::cout << "Test using Morris traversal approach\n";
  result = AreTreesIdentical_v3(root1, root3);
  std::cout << "Test 1: Trees are " << (result ? "identical" : "not identical") << ".\n";

  result = AreTreesIdentical_v3(root1, root2);
  std::cout << "Test 2: Trees are " << (result ? "identical" : "not identical") << ".\n";
}