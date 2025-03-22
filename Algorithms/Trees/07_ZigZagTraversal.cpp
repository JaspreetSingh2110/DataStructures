/*
 * Description:
 * Program for zig-zag traversal of tree.
 * TC: O(n), SC: O(n)
 *
 * Created on: 3/23/2025
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <stack>
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


static void LevelOrderTraversal(BSTNode* root)
{
  if (root == NULL) {
    return;
  }

  std::queue<BSTNode*> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty()) {
    BSTNode* node = q.front();
    q.pop();

    if (node == NULL) {
      std::cout << "\n";
      if (q.empty()) {
        break;
      }
      q.push(NULL);
      continue;
    }

    std::cout << node->data << " ";
    if (node->left != NULL) {
      q.push(node->left);
    }
    if (node->right != NULL) {
      q.push(node->right);
    }
  }
}


void ZigZagTraversal(BSTNode *root)
{
  if (root == NULL) {
    return;
  }

  bool leftToRight = true;
  std::stack<BSTNode *> currentLevelNodes;
  std::stack<BSTNode *> nextLevelNodes;

  currentLevelNodes.push(root);

  while (!currentLevelNodes.empty()) {
    BSTNode *node = currentLevelNodes.top();
    currentLevelNodes.pop();

    std::cout << node->data << " ";

    if (leftToRight) {
      if (node->left) {
        nextLevelNodes.push(node->left);
      }
      if (node->right) {
        nextLevelNodes.push(node->right);
      }
    }
    else {
      if (node->right) {
        nextLevelNodes.push(node->right);
      }
      if (node->left) {
        nextLevelNodes.push(node->left);
      }
    }

    //If all the nodes from current level are traversed,
    // swap the stacks.
    if (currentLevelNodes.empty()) {
      leftToRight = !leftToRight;
      std::swap(currentLevelNodes, nextLevelNodes);
      std::cout << std::endl;
    }
  }
}


void Test_ZigZagTraversal()
{
  BSTNode *root = nullptr;
  root = new BSTNode(1);
  root->left = new BSTNode(2);
  root->right = new BSTNode(3);
  root->left->left = new BSTNode(4);
  root->left->right = new BSTNode(5);
  root->right->left = new BSTNode(6);
  root->right->right = new BSTNode(7);
  root->left->left->left = new BSTNode(8);
  root->left->left->right = new BSTNode(9);
  root->left->right->left = new BSTNode(10);
  root->left->right->right = new BSTNode(11);
  root->right->left->left = new BSTNode(12);
  root->right->left->right = new BSTNode(13);
  root->right->right->left = new BSTNode(14);
  root->right->right->right = new BSTNode(15);

  std::cout << "\nTest ZigZag Traversal\n";
  std::cout << "Tree normal print (level order):\n";
  LevelOrderTraversal(root);

  std::cout << "ZigZag Traversal (level order):\n";
  ZigZagTraversal(root);
}