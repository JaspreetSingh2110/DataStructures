/*
 * Description:
 * Given an array that represents a tree in such a way that
 * array indexes are values in tree nodes and
 * array values give the parent node of that particular index (or node).
 * The value of the root node index would always be -1 as there is no parent for root.
 * Construct the standard linked representation of given Binary Tree from this given representation.
 *
 * Examples:
 * Input: parent[] = {1, 5, 5, 2, 2, -1, 3}
 * Output: root of below tree
 *           5
 *          /  \
 *         1    2
 *        /    / \
 *       0    3   4
 *      /
 *     6
 *     Explanation:
 *     Index of -1 is 5.  So 5 is root.
 *     5 is present at indexes 1 and 2.  So 1 and 2 are children of 5.
 *     1 is present at index 0, so 0 is child of 1.
 *     2 is present at indexes 3 and 4.  So 3 and 4 are children of 2.
 *     3 is present at index 6, so 6 is child of 3.
 *
 * Created on: 4/15/2025
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

class BTreeNode {
  public:
  int data;
  BTreeNode *left;
  BTreeNode *right;

  BTreeNode(int data)
  {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

//API to print the tree in inorder format.
void PrintInOrder(BTreeNode *root)
{
  if (root == nullptr) {
    return;
  }

  PrintInOrder(root->left);
  std::cout << root->data << " ";
  PrintInOrder(root->right);
}

BTreeNode *CreateBinaryTreeFromParentArray(int *parent, int n)
{
  // Invalid case check.
  if (n <= 0) {
    return NULL;
  }
  BTreeNode *root = nullptr;

  //Create vector of nodes with only date and no child nodes assignment.
  std::vector<BTreeNode *> nodes(n, nullptr);
  for (int i = 0; i < n; i++) {
    nodes[i] = new BTreeNode(i);
  }

  for (int i = 0; i < n; i++) {
    if (parent[i] == -1) {
      root = nodes[i];
    }
    else {
      int parentNodeIndex = parent[i];
      BTreeNode *parent = nodes[parentNodeIndex];
      if (parent->left == nullptr) {
        parent->left = nodes[i];
      }
      else if (parent->right == nullptr) {
        parent->right = nodes[i];
      }
    }
  }
  return root;
}


void Test_BinaryTreeCreationFromParentArray()
{
  std::cout << "\nTest to create binary tree from parent array\n";

  std::cout << "Executing test case #1!!!   Output: ";
  int parent[] = {1, 5, 5, 2, 2, -1, 3};
  BTreeNode *root = CreateBinaryTreeFromParentArray(parent, 7);
  PrintInOrder(root);
  std::cout << std::endl;
}

































