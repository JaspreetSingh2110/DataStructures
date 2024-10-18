/*
 * Description:
 * Implementation of B+ tree.
 *
 * Created on: 18/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>

class BPlusTreeNode {
  public:
  int order;
  int numKeys;
  bool isLeaf;
  int *keys;
  BPlusTreeNode **children;

  explicit BPlusTreeNode(int order, bool isLeaf)
  {
    this->order = order;
    this->isLeaf = isLeaf;
    this->numKeys = 0;
    this->keys = new int [2*order-1];
    this->children = new BPlusTreeNode *[2*order];
  }

  bool Search(int key);
  void Traverse();
  void InsertNonFull(int key);
  void SplitNode(int pos, BPlusTreeNode *node);
};

class BPlusTree {
  public:
  int order;
  BPlusTreeNode *root;

  explicit BPlusTree(int order)
  {
    this->order = order;
    this->root = nullptr;
  }

  void Insert(int key);

  void Traverse()
  {
    if (root != nullptr) {
      root->Traverse();
    }
  }

  bool Search(int key)
  {
    return (root != nullptr) ? root->Search(key) : false;
  }
};

void BPlusTree::Insert(int key)
{
  //Check if root is null.
  if (root == nullptr) {
    root = new BPlusTreeNode(order, true);
    root->keys[0] = key;
    root->numKeys = 1;
  } else {
    //If root is present.
    //Check if root node is full.
    if (root->numKeys == (2*order-1)) {
      //Create a new node.
      BPlusTreeNode *newNode = new BPlusTreeNode(order, false);

      //Point current root as first child of new node.
      newNode->children[0] = root;
      //Split current root node.
      newNode->SplitNode(0, root);

      //After split, check the new key will go into which child.
      int childIndex = 0;
      if (key > newNode->keys[0]) {
        childIndex = 1;
      }
      //Insert new key.
      newNode->children[childIndex]->InsertNonFull(key);

      //Make new node as new root node.
      root = newNode;
    } else {
      //If root node is not full. insert key.
      root->InsertNonFull(key);
    }
  }
}

void BPlusTreeNode::InsertNonFull(int key)
{
  //Check if give node is a leaf node.
  if (isLeaf == true) {
    //Insert new key in sorted manner.
    int kIndex = numKeys - 1;
    while ((kIndex >=0 ) && (keys[kIndex] > key)) {
      keys[kIndex + 1] = keys[kIndex];
      kIndex--;
    }
    //Insert new key.
    keys[kIndex + 1] = key;
    //Increment keys count.
    numKeys++;
  } else {
    //If current node is a internal node, find child in which key will be inserted.
    int cIndex = numKeys - 1;
    while ((cIndex >=0) && keys[cIndex] > key) {
      cIndex--;
    }
    //Check if the child node is full, it might need split.
    if (children[cIndex+1]->numKeys == (2*order-1)) {
      SplitNode(cIndex+1, children[cIndex+1]);

      //After split, check in which child node the key will be inserted.
      if (key > (keys[cIndex+ 1])) {
        cIndex++;
      }
    }

    //Insert new key in correct child node.
    children[cIndex+1]->InsertNonFull(key);
  }
}

void BPlusTreeNode::SplitNode(int pos, BPlusTreeNode *node)
{
  //Create a new node.
  BPlusTreeNode *newNode = new BPlusTreeNode(node->order, node->isLeaf);
  //New node will hold order - 1 keys. Set it as numKeys.
  newNode->numKeys = order;

  //Copy the last |order| nos of keys from node to new node.
  for (int i = 0; i < order; i++) {
    newNode->keys[i] = node->keys[i + order -1];
  }
  //Copy last |order| nos of children from node to new node.
  for (int i = 0; i < order + 1; i++) {
    newNode->children[i] = node->children[i + order - 1];
  }
  //Update/reduce the keys count in node.
  node->numKeys = order -1;

  //IMPORTANT: current node after split will point to new node as linked list.
  //Assign last child pointer to newly created node.
  node->children[order] = newNode;

  //The new node needs to be inserted into position |pos+1|
  //Shift current children of this node to create space for new node.
  for (int i = numKeys; i > pos; i--) {
    children[i + 1] = children[i];
  }
  //Insert this as child in allocated space.
  children[pos + 1] = newNode;

  //Copy the middle child from node to current node.
  for (int i = numKeys-1; i >= pos; i--) {
    keys[i+1] = keys[i];
  }
  keys[pos] = node->keys[order - 1];

  //Increment keys count in current node.
  numKeys++;
}

void BPlusTreeNode::Traverse()
{
  int i=0;
  for (i = 0; i < numKeys; i++) {
    if (isLeaf == false) {
      children[i]->Traverse();
    }

    //Use only leaf node to print data. Ignore internal nodes.
    if (isLeaf == true) {
      std::cout << keys[i] << " ";
    }
  }
  //Traverse the last child.
  if (isLeaf == false) {
    children[i]->Traverse();
  }
}

bool BPlusTreeNode::Search(int key)
{
  int i=0;
  while ((i < numKeys) && (key > keys[i])) {
    i++;
  }
  if (keys[i] == key) {
    return true;
  }
  if (isLeaf == true) {
    return false;
  }
  return children[i]->Search(key);
}

void Test_BPlusTree()
{
  BPlusTree bPlusTree(3);

  bPlusTree.Insert(10);
  bPlusTree.Insert(20);
  bPlusTree.Insert(30);
  bPlusTree.Insert(40);
  bPlusTree.Insert(50);
  bPlusTree.Insert(60);
  bPlusTree.Insert(70);
  bPlusTree.Insert(80);
  bPlusTree.Insert(90);
  bPlusTree.Insert(100);
  bPlusTree.Insert(13);
  bPlusTree.Insert(11);
  bPlusTree.Insert(18);
  bPlusTree.Insert(12);
  bPlusTree.Insert(16);
  bPlusTree.Insert(75);
  bPlusTree.Insert(85);

  //Test traverse.
  std::cout << "\n\nTraversing the tree!!!\n";
  bPlusTree.Traverse();
  std::cout << std::endl;

  //Test search.
  int searchKeys[] = {100, 200, 30, 48, 10, 50};
  for (int sKey : searchKeys)
  {
    if (bPlusTree.Search(sKey)) {
      std::cout << "\nKey: " << sKey << " is present in tree.";
    }
    else {
      std::cout << "\nKey: " << sKey << " is not present in tree.";
    }
  }
  std::cout << std::endl;
}