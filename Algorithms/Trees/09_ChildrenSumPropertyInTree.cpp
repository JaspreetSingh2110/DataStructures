/*
* Description:
 * Program to check if given tree follows children sum property.
 * i.e. each node value is equal to its child nodes values.
 *
 * TC: O(n) -> Recursive approach.
 *
 * Alternate approach: Using Queue -> Level order traversal.
 * If root is following the property, push its children to queue.
 *
 * Created on: 3/26/2025
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>

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


int IsSumPropertyFollowed(BSTNode *root)
{
  if ((root == NULL) ||
    (root->left == NULL && root->right == NULL) ) {
    return 1;
  }

  int sum = 0;
  if (root->left != NULL) {
    sum += root->left->data;
  }
  if (root->right != NULL) {
    sum += root->right->data;
  }

  return (root->data == sum) &&
    IsSumPropertyFollowed(root->left) &&
      IsSumPropertyFollowed(root->right);
}

void Test_IsSumPropertyFollowed()
{
  BSTNode *root1 = nullptr;
  root1 = new BSTNode(10);
  root1->left = new BSTNode(8);
  root1->right = new BSTNode(2);
  root1->left->left = new BSTNode(3);
  root1->left->right = new BSTNode(5);
  root1->right->left = new BSTNode(2);

  BSTNode *root2 = nullptr;
  root2 = new BSTNode(10);
  root2->left = new BSTNode(8);
  root2->right = new BSTNode(2);
  root2->left->left = new BSTNode(2);
  root2->left->right = new BSTNode(5);
  root2->right->left = new BSTNode(2);

  int result = -1;
  std::cout << "\nTest to check if given tree is following sum property\n";

  /**************************************************************************************/
  std::cout << "Test using bottoms up recursive approach\n";
  result = IsSumPropertyFollowed(root1);
  std::cout << "Test 1: Tree is " << ((result > 0) ? "" : "not ") << "obeying sum property.\n";

  result = IsSumPropertyFollowed(root2);
  std::cout << "Test 2: Tree is " << ((result > 0) ? "" : "not ") << "obeying sum property.\n";
}