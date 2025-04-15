/*
 * Description:
 * Program to create binary tree from pre order and in order.
 *
 * Approach #1: Recursive using both array.
 * * TC: O(n^2), SC: O(n)
 *
 * Approach #2: Recursive but using map for inorder and preorder
 * TC: O(n), SC: O(n)
 *
 * Created on: 4/16/2025
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <map>
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

void LevelOrderTraversal(BTreeNode* root)
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


/********* Approach 1 *************************************************************************************************/
int GetIndex(std::vector<int> &inOrder, int val)
{
  for (int i = 0; i < inOrder.size(); i++) {
    if (inOrder[i] == val) {
      return i;
    }
  }
  return -1;
}


BTreeNode *CreateBinaryTreeFromPreOrderAndInOrder(
  std::vector<int> &preOrder, std::vector<int> &inOrder,
  int &preIndex, int left, int right)
{
  if (left > right) {
    return nullptr;
  }

  //Get root node value and create node
  int rootVal = preOrder[preIndex];
  BTreeNode *root = new BTreeNode(rootVal);
  preIndex++;

  //Find index of root element in inorder array.
  int index = GetIndex(inOrder, rootVal);

  //Process left and right subtree.
  root->left = CreateBinaryTreeFromPreOrderAndInOrder(preOrder, inOrder, preIndex, left, index -1);
  root->right = CreateBinaryTreeFromPreOrderAndInOrder(preOrder, inOrder, preIndex, index + 1, right);
  return root;
}

BTreeNode *BinaryTreeCreationFromPreOrderAndInOrder_v1(std::vector<int> &preOrder, std::vector<int> &inOrder)
{
  int preIndex = 0;
  BTreeNode *root = CreateBinaryTreeFromPreOrderAndInOrder(preOrder, inOrder, preIndex, 0, inOrder.size() - 1);
  return root;
}

/********* Approach 2 *************************************************************************************************/
//We replace function to find index of root in inOrder array by a map.
//This reduces the time complexity.
BTreeNode *CreateBinaryTreeFromPreOrderAndInOrderMap(std::map<int, int> &inOrderIndexMap, std::vector<int> &preOrder, int &preIndex, int left, int right)
{
  if (left > right) {
    return nullptr;
  }

  //Get root node value and create node
  int rootVal = preOrder[preIndex];
  BTreeNode *root = new BTreeNode(rootVal);
  preIndex++;

  //Find index of root element in inorder array.
  int index = inOrderIndexMap[rootVal];

  //Process left and right subtree.
  root->left = CreateBinaryTreeFromPreOrderAndInOrderMap(inOrderIndexMap, preOrder, preIndex, left, index -1);
  root->right = CreateBinaryTreeFromPreOrderAndInOrderMap(inOrderIndexMap, preOrder, preIndex, index + 1, right);
  return root;
}

BTreeNode *BinaryTreeCreationFromPreOrderAndInOrder_v2(std::vector<int> &preOrder, std::vector<int> &inOrder)
{
  int preIndex = 0;
  std::map <int, int> inOrderIndexMap;
  for (int i = 0; i < inOrder.size(); i++) {
    inOrderIndexMap[inOrder[i]] = i;
  }
  BTreeNode *root = CreateBinaryTreeFromPreOrderAndInOrderMap(inOrderIndexMap, preOrder, preIndex, 0, inOrder.size() - 1);
  return root;
}

/**********************************************************************************************************************/

void Test_BinaryTreeCreationFromPreOrderAndInOrder()
{
  std::cout << "\nTest to create binary tree from pre order and in order\n";

  std::vector<int> inOrder = {3, 1, 4, 0, 5, 2};
  std::vector<int> preOrder = {0, 1, 3, 4, 2, 5};

  std::cout << "Approach #1, Test case #1: \n";
  BTreeNode *root = BinaryTreeCreationFromPreOrderAndInOrder_v1(preOrder, inOrder);
  LevelOrderTraversal(root);
  std::cout << std::endl;

  std::cout << "Approach #2, Test case #1: \n";
  root = BinaryTreeCreationFromPreOrderAndInOrder_v2(preOrder, inOrder);
  LevelOrderTraversal(root);
  std::cout << std::endl;
}
