/*
 * Description:
 * Programs to iteratively traverse the tree for pre-order, inorder and post order.
 *
 * Pre-order and In-order: Morris traversal.
 * TC: O(n), SC: O(1)
 *
 * Post-order: Stack is used.
 * TC: O(n), SC: O(n)
 *
 * Created on: 4/13/2025
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <algorithm>
#include <iostream>
#include <vector>

class Node {
  public:
  int data;
  Node* left;
  Node* right;
  Node(int data)
  {
    data = data;
    left = NULL;
    right = NULL;
  }
};

// In-Order traversal
std::vector<int> InOrderMorrisTraversal(Node *root)
{
  std::vector<int> result;
  if (root == NULL) {
    return result;
  }

  Node *current = root;
  while (current != NULL) {
    if (current->left == NULL) {
      result.push_back(current->data);
      current = current->right;
    }
    else {
      Node *temp = current->left;
      while (temp && (temp->right != NULL) && (temp->right != current)) {
        temp = temp->right;
      }

      if (temp && temp->right == current) {
        temp->right = NULL;
        result.push_back(current->data);
        current = current->right;
      }
      else if (temp && temp->right == NULL) {
        temp->right = current;
        current = current->left;
      }
    }
  }

  return result;
}

// Pre-Order traversal
std::vector<int> PreOrderMorrisTraversal(Node *root)
{
  std::vector<int> result;
  if (root == NULL) {
    return result;
  }

  Node *current = root;
  while (current != NULL) {
    if (current->left == NULL) {
      result.push_back(current->data);
      current = current->right;
    }
    else {
      Node *temp = current->left;
      while (temp && (temp->right != NULL) && (temp->right != current)) {
        temp = temp->right;
      }

      if (temp && temp->right == current) {
        temp->right = NULL;
        current = current->right;
      }
      else if (temp && temp->right == NULL) {
        result.push_back(current->data);
        temp->right = current;
        current = current->left;
      }
    }
  }

  return result;
}


// Post-Order traversal
std::vector<int> PostOrderMorrisTraversal(Node *root)
{
  std::vector<int> result;
  if (root == NULL) {
    return result;
  }

  Node *current = root;
  while (current != NULL) {
    if (current->right == NULL) {
      result.push_back(current->data);
      current = current->left;
    }
    else {
      Node *temp = current->right;
      while (temp && (temp->left != NULL) && (temp->left != current)) {
        temp = temp->left;
      }

      if (temp && temp->left == current) {
        temp->left = NULL;
        current = current->left;
      }
      else if (temp && temp->right == NULL) {
        result.push_back(current->data);
        temp->left = current;
        current = current->right;
      }
    }
  }

  //Reverse the result.
  std::reverse(result.begin(), result.end());

  return result;
}


void Test_IterativeTraversal_InPrePostOrder()
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

  std::vector<int> result;

  std::cout << "Test 1: Pre-order traversal of tree (using Morris traversal): [ ";
  result = InOrderMorrisTraversal(root1);
  for (auto i : result) {
    std::cout << i << " ";
  }
  std::cout << "]" << std::endl;

  std::cout << "Test 2: Pre-order traversal of tree (using Morris traversal): [ ";
  result = PreOrderMorrisTraversal(root1);
  for (auto i : result) {
    std::cout << i << " ";
  }
  std::cout << "]" << std::endl;

  std::cout << "Test 3: Post-order traversal of tree (using Morris traversal): [ ";
  result = PostOrderMorrisTraversal(root1);
  for (auto i : result) {
    std::cout << i << " ";
  }
  std::cout << "]" << std::endl;
}