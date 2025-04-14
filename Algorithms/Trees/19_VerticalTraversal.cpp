/*
 * Description:
 * Program to implement vertical traversal of tree using BFS.
 *
 * TC: O(n), SC: O(n)
 *
 * Created on: 4/14/2025
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>

class Node {
  public:
  int data;
  Node* left;
  Node* right;

  Node (int data)
  {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};


std::vector<std::vector<int>> VerticalLevelTraversal_BFS(Node *root)
{
  std::vector<std::vector<int>> result;
  if (root == NULL) {
    return result;
  }
  int minD = 0;
  int maxD = 0;
  std::map<int, std::vector<int>> map;
  std::queue<std::pair<int, Node*>> q;

  q.push(std::make_pair(0, root));
  while (!q.empty()) {
    std::pair<int, Node*> current = q.front();
    q.pop();

    Node *temp = current.second;
    int hd = current.first;

    map[hd].push_back(temp->data);
    if (temp->left) {
      q.push(std::make_pair(hd - 1, temp->left));
    }
    if (temp->right) {
      q.push(std::make_pair(hd + 1, temp->right));
    }

    minD = std::min(minD, hd);
    maxD = std::max(maxD, hd);
  }

  //Populate results from map to vector.
  for (int i = minD; i <= maxD; i++) {
    if (map.find(i) != map.end()) {
      result.push_back(map[i]);
    }
  }
  return result;
}


void Test_VerticalTraversal()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);
  root->right->left->right = new Node(8);
  root->right->right->right = new Node(9);

  //Tree 2
  Node *root2 = nullptr;
  root2 = new Node(4);
  root2->left = new Node(2);
  root2->right = new Node(6);
  root2->left->left = new Node(1);
  root2->left->right = new Node(3);
  root2->right->left = new Node(5);
  root2->right->right = new Node(7);

  std::vector<std::vector<int>> result;

  std::cout << "\nTest to traverse the tree in vertical level order\n";
  std::cout << "Test 1: Vertical level order traversal of tree (using BFS): [ ";
  result = VerticalLevelTraversal_BFS(root);
  for (auto i : result) {
    std::cout << "[";
    for (auto j : i) {
      std::cout << j << ", ";
    }
    std::cout << "],";
  }
  std::cout << "]" << std::endl;

  std::cout << "Test 2: Vertical level order traversal of tree (using BFS): [ ";
  result = VerticalLevelTraversal_BFS(root2);
  for (auto i : result) {
    std::cout << "[";
    for (auto j : i) {
      std::cout << j << ", ";
    }
    std::cout << "],";
  }
  std::cout << "]" << std::endl;
}