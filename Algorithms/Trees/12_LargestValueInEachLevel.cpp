/*
 * Description:
 * Program to find the largest value node in each level.
 *
 * Approach: Level order traversal.
 * TC: O(n), SC:O(w)
 *
 * Created on: 3/30/2025
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>
#include <queue>

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


std::vector<int> GetLargestValueNodesInEachLevel(Node* root)
{
  std::vector<int> result;
  if (root == NULL) {
    return result;
  }

  std::queue<Node*> q;
  q.push(root);
  while (!q.empty()) {
    int size = q.size();

    //Get current nodes in current level
    int cMin = INT_MIN;
    for (int i = 0; i < size; i++) {
      Node* node = q.front();
      q.pop();

      if (node->data > cMin) {
        cMin = node->data;
      }

      if (node->left != NULL) {
        q.push(node->left);
      }
      if (node->right != NULL) {
        q.push(node->right);
      }
    }
    if (cMin != INT_MIN) {
      result.push_back(cMin);
    }
  }
  return result;
}

void Test_LargestValueNodesInEachLevel()
{
  Node *root = nullptr;
  root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(6);
  root->left->left = new Node(1);
  root->left->right = new Node(3);
  root->right->left = new Node(5);
  root->right->right = new Node(7);

  std::cout << "\nTest to find the the largest value node in each level in tree\n";
  /**************************************************************************************/
  std::cout << "Test using Level order traversal approach\n";
  std::vector<int> result;
  result = GetLargestValueNodesInEachLevel(root);

  //print result.
  for (auto i : result) {
    std::cout << i << " | ";
  }
  std::cout << std::endl;
}