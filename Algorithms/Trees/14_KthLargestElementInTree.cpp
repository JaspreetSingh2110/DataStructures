/*
* Description:
 * Program for reverse morris traversal.
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
  Node(int d)
  {
    data = d;
    left = NULL;
    right = NULL;
  }
};

int GetKthLargestElementInTree(Node *root, int k)
{
  int result = -1;
  if (root == NULL) {
    return result;
  }

  Node* current = root;
  int cnt = 0;
  while (current != NULL) {
    if (current->right == NULL) {
      cnt++;
      if (cnt == k) {
        result = current->data;
      }
      current = current->left;
    }
    else {
      Node* temp = current->right;
      while ((temp->left != NULL) && (temp->left != current)) {
        temp = temp->left;
      }

      if (temp->left == NULL) {
        temp->left = current;
        current = current->right;
      }
      else {
        temp->left = NULL;
        cnt++;
        if (cnt == k) {
          result = current->data;
        }
        current = current->left;
      }
    }
  }

  return result;
}

void Test_KthLargestElementInTree()
{
  Node *root = nullptr;
  root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(6);
  root->left->left = new Node(1);
  root->left->right = new Node(3);
  root->right->left = new Node(5);
  root->right->right = new Node(7);

  std::cout << "\nTest to Kth largest element in a tree\n";
  /**************************************************************************************/
  std::cout << "Largest element in a tree is: " << GetKthLargestElementInTree(root, 1) << std::endl;
  std::cout << "2nd Largest element in a tree is: " << GetKthLargestElementInTree(root, 2) << std::endl;
  std::cout << "3rd Largest element in a tree is: " << GetKthLargestElementInTree(root, 3) << std::endl;
  std::cout << "4th Largest element in a tree is: " << GetKthLargestElementInTree(root, 4) << std::endl;
  std::cout << "10th Largest element in a tree is: " << GetKthLargestElementInTree(root, 10) << std::endl;
}