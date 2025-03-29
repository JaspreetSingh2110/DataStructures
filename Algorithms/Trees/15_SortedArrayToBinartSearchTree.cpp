/*
 * Description:
 * Program to create BST from sorted array.
 *
 * Approach recursive
 * TC: O(n), SC: O(n)
 *
 * Created on: 3/30/2025
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

class Node {
  public:
  int data;
  Node *left;
  Node *right;
  Node (int data)
  {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

void Inorder(Node *root)
{
  if (root == NULL) {
    return;
  }
  Inorder(root->left);
  std::cout << root->data << " ";
  Inorder(root->right);
}


Node* CreateBSTFromSortedArray(std::vector <int> &arr, int low, int high)
{
  //Check for invalid condition
  if (low > high) {
    return NULL;
  }

  //Get the mid index.
  int mid = low + (high - low) / 2;

  Node *root = new Node(arr[mid]);
  std::cout << "Node created with value: " << root->data << "\n";
  root->left = CreateBSTFromSortedArray(arr, low, mid - 1);
  root->right = CreateBSTFromSortedArray(arr, mid + 1, high);
  return root;
}


void Test_BSTCreationFromSortedArray()
{
  std::cout << "\nTest to create BST from sorted array\n";
  /**************************************************************************************/
  std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Node* root = CreateBSTFromSortedArray(v, 0, v.size() - 1);
  Inorder(root);
}