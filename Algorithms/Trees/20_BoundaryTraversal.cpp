/*
 * Description:
 * Program to traverse the tree to touch only outer nodes.
 * i.e. start from left nodes -> then central leaf nodes -> upwards traversal for right nodes.
 *
 * Created on: 4/15/2025
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

/*************** Helper APIs ******************************************************************************************/
bool IsLeafNode(Node *root)
{
  return (root && (root->left == NULL) && (root->right == NULL));
}

void TraverseLeftNodes(Node *root, std::vector<int> &result)
{
  if (root == NULL) {
    return;
  }

  Node *current = root;
  while (!IsLeafNode(current)) {
    result.push_back(current->data);
    if (current->left != NULL) {
      current = current->left;
    } else if (current->right != NULL) {
      current = current->right;
    }
  }
}

void TraverseRightNodes(Node *root, std::vector<int> &result)
{
  if (root == NULL) {
    return;
  }

  Node *current = root;

  //Use temp vector because we will traver the right boundary downwards, but the results needs to be stored upwards.
  //So, get the right nodes and then copy back the data from temp vector to results in reverse order.
  std::vector<int> rightNodes;
  while (!IsLeafNode(current)) {
    rightNodes.push_back(current->data);
    if (current->right != NULL) {
      current = current->right;
    } else if (current->left != NULL) {
      current = current->left;
    }
  }

  //Copy back the data from temp vector to results in reverse order.
  for (auto it = rightNodes.rbegin(); it != rightNodes.rend(); it++) {
    result.push_back(*it);
  }
}

void TraverseLeafNodes(Node *root, std::vector<int> &result)
{
  if (root == NULL) {
    return;
  }

  Node *current = root;
  while (current) {
    if (current->left == NULL) {
      //Is leaf node?
      if (current->right == NULL) {
        result.push_back(current->data);
      }
      current = current->right;
    }
    else {
      Node *lChild = current->left;
      while (lChild->right && lChild->right != current) {
        lChild = lChild->right;
      }

      if (lChild->right == NULL) {
        lChild->right = current;
        current = current->left;
      }
      if (lChild->right == current) {
        lChild->right = NULL;
        current = current->right;
        if (lChild->left == NULL) {
          result.push_back(lChild->data);
        }
      }
    }
  }
}
/**********************************************************************************************************************/

std::vector<int> AntiClockwiseBoundaryTraversal_MorrisTraversal(Node *root)
{
  std::vector<int> result;
  if (root == NULL) {
    return result;
  }

  result.push_back(root->data);
  if (IsLeafNode(root)) {
    return result;
  }

  TraverseLeftNodes(root->left, result);
  TraverseLeafNodes(root, result);
  TraverseRightNodes(root->right, result);

  return result;
}

void Test_BoundaryTraversal()
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

  std::vector<int> result;

  std::cout << "\nTest to traverse the tree in anti-clockwise boundary traversal order\n";
  std::cout << "Test 1: Anti clockwise boundary traversal of tree (using Morris Traversal): [ ";
  result = AntiClockwiseBoundaryTraversal_MorrisTraversal(root);
  for (auto i : result) {
    std::cout << i << " ";
  }
  std::cout << "]" << std::endl;

  std::cout << "Test 2: Anti clockwise boundary traversal of tree (using Morris Traversal): [ ";
  result = AntiClockwiseBoundaryTraversal_MorrisTraversal(root2);
  for (auto i : result) {
    std::cout << i << " ";
  }
  std::cout << "]" << std::endl;
}
