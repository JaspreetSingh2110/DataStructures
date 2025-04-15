/*
 * Description:
 * Program to create binary search tree from pre-order.
 *
 * Approach : Recursion with max limits.
 * TC: O(n), SC: O(n)
 *
 * Created on: 4/16/2025
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>
#include <queue>

class BTreeNode {
  public:
  int data;
  BTreeNode *left;
  BTreeNode *right;
  BTreeNode(int data)
  {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
};

static void LevelOrderTraversal(BTreeNode* root)
{
  if (root == NULL) {
    return;
  }

  std::queue<BTreeNode*> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty()) {
    BTreeNode* node = q.front();
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


BTreeNode *CreateBinarySearchTreeFromPreOrder(std::vector<int> &preOrder, int &preIndex, int min, int max)
{
  if (preIndex >= preOrder.size()) {
    return nullptr;
  }

  //Get root node value and create node
  int rootVal = preOrder[preIndex];

  //Check if node value falls in range.
  if (rootVal <= min || rootVal >= max) {
    return nullptr;
  }
  BTreeNode *root = new BTreeNode(rootVal);
  preIndex++;

  //Process left and right subtree.
  if (preIndex < preOrder.size()) {
    root->left = CreateBinarySearchTreeFromPreOrder(preOrder, preIndex, min, rootVal);
  }
  if (preIndex < preOrder.size()) {
    root->right = CreateBinarySearchTreeFromPreOrder(preOrder, preIndex, rootVal, max);
  }
  return root;
}

BTreeNode *BinarySearchTreeCreationFromPreOrder(std::vector<int> &preOrder)
{
  int preIdx = 0;
  return CreateBinarySearchTreeFromPreOrder(preOrder, preIdx, INT_MIN, INT_MAX);
}

/**********************************************************************************************************************/

void Test_BinarySearchTreeCreationFromPreOrder()
{
  std::cout << "\nTest to create binary tree from post-order and in-order\n";

  std::vector<int> preOrder = {10, 5, 1, 7, 40, 50};

  std::cout << "Approach #1, Test case #1: \n";
  BTreeNode *root = BinarySearchTreeCreationFromPreOrder(preOrder);
  LevelOrderTraversal(root);
  std::cout << std::endl;
}
