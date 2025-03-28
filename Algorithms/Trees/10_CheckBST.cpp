/*
 * Description:
 * Program to check if given tree is BST.
 *
 * Created on: 3/28/2025
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

class Node {
  public:
  int data;
  Node* left;
  Node* right;

  Node(int d)
  {
    data = d;
    left = NULL;
    right = NULL;
  }
};


bool IsBST(Node* root)
{
  if ((root == NULL) || ((root->left == NULL) && (root->right == NULL))) {
    return true;
  }

  //Check if left sub tree follows BST property
  if (root->left && root->data < (root->left->data)) {
    return false;
  }
  //Check if right subtree follows the BST property.
  if (root->right && root->data > (root->right->data)) {
    return false;
  }

  //Check for left sub tree and right sub tree.
  return IsBST(root->left) && IsBST(root->right);
}


//Approach 2: Morris traversal.
//TC: O(n), TC: O(1)
bool IsBST_MorrisTraversalApproach(Node* root)
{
  if (root == NULL) {
    return true;
  }

  Node *current = root;
  while (current != NULL) {
    if (current->left == NULL) {
      if ((current && current->right) && (current->data > (current->right->data))) {
        return false;
      }
      current = current->right;
    }
    else {
      Node *leftNode = current->left;
      Node *temp = leftNode;
      while (temp->right != NULL) {
        temp = temp->right;
      }

      temp->right = current;
      current->left = NULL;
      current = leftNode;
    }
  }
  return true;
}


void Test_IsBST()
{
  Node *root1 = nullptr;
  root1 = new Node(50);
  root1->left = new Node(30);
  root1->right = new Node(70);
  root1->left->left = new Node(20);
  root1->left->right = new Node(35);
  root1->right->left = new Node(60);
  root1->right->right = new Node(80);

  Node *root2 = nullptr;
  root2 = new Node(50);
  root2->left = new Node(30);
  root2->right = new Node(70);
  root2->left->left = new Node(20);
  root2->left->right = new Node(35);
  root2->right->left = new Node(60);
  root2->right->right = new Node(10);

  bool result;
  std::cout << "\nTest to check if given tree is BST\n";

  /**************************************************************************************/
  std::cout << "Test using recursive approach\n";
  result = IsBST(root1);
  std::cout << "Test 1: Tree is " << (result ? "" : "not ") << "BST.\n";

  result = IsBST(root2);
  std::cout << "Test 2: Tree is " << (result ? "" : "not ") << "BST.\n";

  /**************************************************************************************/
  std::cout << "Test using Morris traversal approach\n";
  result = IsBST_MorrisTraversalApproach(root1);
  std::cout << "Test 1: Tree is " << (result ? "" : "not ") << "BST.\n";

  result = IsBST_MorrisTraversalApproach(root2);
  std::cout << "Test 2: Tree is " << (result ? "" : "not ") << "BST.\n";
}
