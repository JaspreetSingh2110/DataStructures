/*
 * Description:
 * Program to generate the mirror trees.
 *
 * Created on: 3/22/2025
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <queue>

class BSTNode {
public:
  int data;
  BSTNode* left;
  BSTNode* right;

  BSTNode(int data)
  {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};


void LevelOrderTraversal(BSTNode* root)
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

//TC: O(n), SC: O(h)
void GenerateMirrorTree_Recursive(BSTNode* root)
{
  if (root == NULL) {
    return;
  }

  GenerateMirrorTree_Recursive(root->left);
  GenerateMirrorTree_Recursive(root->right);

  std::swap(root->left, root->right);
}

//TC: O(n), SC: O(n)
void GenerateMirrorTree_Iterative(BSTNode* root)
{
  if (root == NULL) {
    return;
  }

  std::queue<BSTNode*> q;
  q.push(root);

  while (!q.empty()) {
    BSTNode* node = q.front();
    q.pop();

    std::cout << node->data << " ";
    std::swap(root->left, root->right);

    if (node->left != NULL) {
      q.push(node->left);
    }
    if (node->right != NULL) {
      q.push(node->right);
    }
  }
}


void Test_MirrorTree()
{
  BSTNode *root = nullptr;
  root = new BSTNode(50);
  root->left = new BSTNode(20);
  root->right = new BSTNode(60);
  root->left->left = new BSTNode(10);
  root->left->right = new BSTNode(30);
  root->right->left = new BSTNode(40);
  root->right->right = new BSTNode(50);
  root->right->right->left = new BSTNode(45);

  std::cout << "\nProgram to generate mirror of a tree\n";
  std::cout << "\nLevel order traversal for binary tree (BEFORE):\n";
  LevelOrderTraversal(root);

  std::cout << "\nLevel order traversal for binary tree (using recursive approach) (AFTER):\n";
  GenerateMirrorTree_Recursive(root);
  LevelOrderTraversal(root);

  std::cout << "\nLevel order traversal for binary tree (using iterative approach) (AFTER):\n";
  GenerateMirrorTree_Recursive(root);
  LevelOrderTraversal(root);
}