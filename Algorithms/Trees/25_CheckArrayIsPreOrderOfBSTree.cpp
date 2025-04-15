/*
 * Description:
 * Program to check if given array represents the pre-order of BST.
 *
 * Created on: 4/16/2025
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
    left = nullptr;
    right = nullptr;
  }
};


int IsArrayPreOrderOfBSTree(std::vector<int> &preOrder, int &preIndex, int min, int max)
{
  if (preIndex >= preOrder.size()) {
    return preIndex;
  }

  //Get root node value and check if it falls under given range.
  int rootVal = preOrder[preIndex];
  if (min <= rootVal && max >= rootVal) {
    preIndex++;
    IsArrayPreOrderOfBSTree(preOrder, preIndex, min, rootVal);
    IsArrayPreOrderOfBSTree(preOrder, preIndex, rootVal, max);
  }
  return preIndex;
}

bool CheckArrayIsPreOrderOfBSTree(std::vector<int> &preOrder)
{
  int preIndex = 0;
  IsArrayPreOrderOfBSTree(preOrder, preIndex, INT_MIN, INT_MAX);
  //Check if all elements are visited.
  return (preIndex == preOrder.size());
}

/**********************************************************************************************************************/

void Test_CheckArrayIsPreOrderOfBSTree()
{
  std::cout << "\nTest to check if given array is preOrder of binary search tree\n";

  std::vector<int> preOrder1 = {10, 5, 1, 7, 40, 50};
  std::vector<int> preOrder2 = {10, 5, 1, 7, 40, 3};

  std::cout << "Approach #1, Test case #1: ";
  bool result = CheckArrayIsPreOrderOfBSTree(preOrder1);
  std::cout << "Array is " << (result ? "" : "not ") << "pre-order of Binary Search Tree\n";

  std::cout << "Approach #1, Test case #2: ";
  result = CheckArrayIsPreOrderOfBSTree(preOrder2);
  std::cout << "Array is " << (result ? "" : "not ") << "pre-order of Binary Search Tree\n";
}