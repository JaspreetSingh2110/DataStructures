/*
 * Description:
 * Program to create binary tree from inorder and post order.
 *
 * Approach : Recursion with map.
 * TC: O(n), SC: O(n)
 *
 * Created on: 4/16/2025
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <map>

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

BTreeNode *CreateBinaryTreeFromPostOrderAndInOrderMap(std::map<int, int> &inOrderIndexMap, std::vector<int> &preOrder, int &postIndex, int left, int right)
{
  if (left > right) {
    return nullptr;
  }

  //Get root node value and create node
  int rootVal = preOrder[postIndex];
  BTreeNode *root = new BTreeNode(rootVal);
  postIndex--;

  //Find index of root element in inorder array.
  int index = inOrderIndexMap[rootVal];

  //Process right and left subtree.
  //NOTE that we first process the right subtree and then left subtree.
  root->right = CreateBinaryTreeFromPostOrderAndInOrderMap(inOrderIndexMap, preOrder, postIndex, index + 1, right);
  root->left = CreateBinaryTreeFromPostOrderAndInOrderMap(inOrderIndexMap, preOrder, postIndex, left, index -1);
  return root;
}

BTreeNode *BinaryTreeCreationFromPostOrderAndInOrder(std::vector<int> &inOrder, std::vector<int> &postOrder)
{
  int postIndex = inOrder.size() - 1;
  std::map <int, int> inOrderIndexMap;
  for (int i = 0; i < inOrder.size(); i++) {
    inOrderIndexMap[inOrder[i]] = i;
  }

  //Note that in this case, postIndex is size - 1.
  BTreeNode *root = CreateBinaryTreeFromPostOrderAndInOrderMap(inOrderIndexMap, postOrder, postIndex, 0, postOrder.size() - 1);
  return root;
}

/**********************************************************************************************************************/

void Test_BinaryTreeCreationFromPostOrderAndInOrder()
{
  std::cout << "\nTest to create binary tree from post-order and in-order\n";

  std::vector<int> inOrder = { 4, 8, 2, 5, 1, 6, 3, 7 };
  std::vector<int> postOrder = { 8, 4, 5, 2, 6, 7, 3, 1 };

  std::cout << "Approach #1, Test case #1: \n";
  BTreeNode *root = BinaryTreeCreationFromPostOrderAndInOrder(inOrder, postOrder);
  LevelOrderTraversal(root);
  std::cout << std::endl;
}
