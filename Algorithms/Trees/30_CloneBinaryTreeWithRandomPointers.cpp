/*
 * Description:
 * Program to clone binary tree with random pointers.
 *
 * TC: O(n), SC:O(n)
 *
 * Created on: 4/19/2025
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <map>

class BTreeNodeWithRandom {
  public:
  int data;
  BTreeNodeWithRandom *left;
  BTreeNodeWithRandom *right;
  BTreeNodeWithRandom *random;

  BTreeNodeWithRandom(int d)
  {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
    this->random = NULL;
  }
};


BTreeNodeWithRandom* CloneLeftRight(BTreeNodeWithRandom *root, std::map <BTreeNodeWithRandom*, BTreeNodeWithRandom*> &nodeMap)
{
  if (root == NULL) {
    return NULL;
  }
  //Create new node and update the map.
  BTreeNodeWithRandom *newNode = new BTreeNodeWithRandom(root->data);
  nodeMap[root] = newNode;

  //Process left and right child nodes.
  newNode->left = CloneLeftRight(root->left, nodeMap);
  newNode->right = CloneLeftRight(root->right, nodeMap);
  return newNode;
}

void UpdateRandomPointers(BTreeNodeWithRandom *root, std::map <BTreeNodeWithRandom*, BTreeNodeWithRandom*> &nodeMap)
{
  if (root == NULL) {
    return;
  }
  nodeMap[root]->random = nodeMap[root->random];
  UpdateRandomPointers(root->left, nodeMap);
  UpdateRandomPointers(root->right, nodeMap);
}

BTreeNodeWithRandom* CloneBinaryTreeWithRandomPointer(BTreeNodeWithRandom *root)
{
  if (root == NULL) {
    return NULL;
  }
  std::map <BTreeNodeWithRandom*, BTreeNodeWithRandom*> nodeMap;

  BTreeNodeWithRandom *clonedRoot = CloneLeftRight(root, nodeMap);
  UpdateRandomPointers(root, nodeMap);
  return clonedRoot;
}


static void PrintInOrder(BTreeNodeWithRandom *root)
{
  if (root == NULL) {
    return;
  }
  PrintInOrder(root->left);
  std::cout << root->data << " ";
  PrintInOrder(root->right);
}


void Test_CloneBinaryTreeWithRandomPointer()
{
  // Constructing the binary tree with random pointers
  // Tree structure:
  //         1
  //        / \
  //       2   3
  //      / \
  //     4   5
  // Random pointers:
  // 1 -> 5, 4 -> 1, 5 -> 3

  BTreeNodeWithRandom *node = new BTreeNodeWithRandom(1);
  node->left = new BTreeNodeWithRandom(2);
  node->right = new BTreeNodeWithRandom(3);
  node->left->left = new BTreeNodeWithRandom(4);
  node->left->right = new BTreeNodeWithRandom(5);

  //Set random pointers.
  node->random = node->left->right;
  node->left->left->random = node;
  node->left->right->random = node->right;

  std::cout << "\nTest to create a clone of binary tree with random pointers!!!\n";
  std::cout << "Inorder print for original tree: -> ";
  PrintInOrder(node);
  std::cout << std::endl;

  std::cout << "Inorder print for cloned tree: -> ";
  BTreeNodeWithRandom *clonedRoot = CloneBinaryTreeWithRandomPointer(node);
  PrintInOrder(clonedRoot);
  std::cout << std::endl;
}