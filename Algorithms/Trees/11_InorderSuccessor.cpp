/*
 * Description:
 * Program to find inorder successor for the given node in tree.
 *
 * Approach 1: Morris travel approach
 * TC: O(n). SC: O(n)
 *
 * Approach #2: Using BST properties
 * TC: O(h), SC: O(1)
 *
 * Created on: 3/29/2025
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
    this->data = d;
    left = NULL;
    right = NULL;
  }
};

void InorderPrint(Node *root)
{
  if (root == NULL) {
    return;
  }
  InorderPrint(root->left);
  std::cout << root->data << " ";
  InorderPrint(root->right);
}


int GetInorderSuccessor_v1(Node* root, int target)
{
  if (root == NULL) {
    return -1;
  }

  Node* current = root;
  bool targetFound = false;

  while (current != NULL) {
    if (current->left == NULL) {
      //When we have already visited the target node, the leftmost node is inorder successor.
      if (targetFound) {
        return current->data;
      }
      if (current->data == target) {
        targetFound = true;
      }
      current = current->right;
    }
    else {
      Node* temp = current->left;
      while ((temp->right != NULL) && (temp->right != current)) {
        temp = temp->right;
      }

      if (temp->right == NULL) {
        temp->right = current;
        current = current->left;
      }
      else { //temp->right == current
        temp->right = NULL;
        //if target is already visited, then current points to inorder successor.
        if (targetFound) {
          return current->data;
        }
        if (current->data == target) {
          targetFound = true;
        }
        current = current->right;
      }
    }
  }
  return -1;
}

int GetInorderSuccessor_v2(Node * root, int target)
{
  //Case 1: root node is NULL -> no successor
  if (root == NULL) {
    return -1;
  }

  //Case 2: if there is no right most node for target value.
  if (root->data == target && root->right != NULL) {
    Node *temp = root->right;
    while (temp->left != NULL) {
      temp = temp->left;
    }
    return temp->data;
  }

  Node *successor = nullptr;
  Node *current = root;
  while (current != NULL) {
    if (target < current->data) {
      successor = current;
      current = current->left;
    }
    else if (target > current->data) {
      current = current->right;
    }
    else {
      break;
    }
  }
  if (successor == NULL || current == NULL) {
    return -1;
  }
  return successor->data;
}

void Test_InorderSuccessor()
{
  Node *root = nullptr;
  root = new Node(50);
  root->left = new Node(30);
  root->right = new Node(70);
  root->left->left = new Node(20);
  root->left->right = new Node(35);
  root->right->left = new Node(60);
  root->right->right = new Node(80);

  Node *root2 = nullptr;
  root2 = new Node(4);
  root2->left = new Node(2);
  root2->right = new Node(6);
  root2->left->left = new Node(1);
  root2->left->right = new Node(3);
  root2->right->left = new Node(5);
  root2->right->right = new Node(6);

  std::cout << "\nTest to find the inorder successor in tree\n";
  /**************************************************************************************/
  std::cout << "Test using Morris traversal approach\n";
  std::cout << "Test 1: Inorder success for node 50 is: " << GetInorderSuccessor_v1(root, 50) << ".\n";
  std::cout << "Test 2: Inorder success for node 20 is: " << GetInorderSuccessor_v1(root, 20) << ".\n";
  std::cout << "Test 3: Inorder success for node 35 is: " << GetInorderSuccessor_v1(root, 35) << ".\n";
  std::cout << "Test 4: Inorder success for node 80 is: " << GetInorderSuccessor_v1(root, 80) << ".\n";
  std::cout << "Test 5: Inorder success for node 90 is: " << GetInorderSuccessor_v1(root, 90) << ".\n";

  /**************************************************************************************/
  std::cout << "Test using Morris traversal approach\n";
  std::cout << "Test 1: Inorder success for node 4 is: " << GetInorderSuccessor_v2(root2, 4) << ".\n";
  std::cout << "Test 2: Inorder success for node 1 is: " << GetInorderSuccessor_v2(root2, 1) << ".\n";
  std::cout << "Test 3: Inorder success for node 3 is: " << GetInorderSuccessor_v2(root2, 3) << ".\n";
  std::cout << "Test 4: Inorder success for node 6 is: " << GetInorderSuccessor_v2(root2, 6) << ".\n";
  std::cout << "Test 5: Inorder success for node 90 is: " << GetInorderSuccessor_v2(root2, 90) << ".\n";
}