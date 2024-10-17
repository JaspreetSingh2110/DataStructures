/*
 * Description:
 * Implementation of BTree.
 *
 * Created on: 17/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>

class BTreeNode {
  public:
  int order;    // Order of tree.
  int* keys;    // Array of keys.
  int numKeys;  // Number of keys in this node.
  BTreeNode** children;   // Array of pointers of children.
  bool isLeaf;  // Boolean flag to check if node is a leaf node.

  BTreeNode(int order, bool isLeaf)
  {
    this->order = order;
    this->isLeaf = isLeaf;
    this->numKeys = 0;
    //BTree node contains '2*order - 1' keys.
    this->keys = new int[2*order - 1];
    //BTree node contains 2*order children pointers.
    this->children = new BTreeNode*[2*order];
  }

  bool Search(int key);
  void Traverse();
  void SplitNode(int pos, BTreeNode* node);
  void InsertNonFull(int key);
};

class BTree {
  public:
  BTreeNode* root;
  int order;

  explicit BTree(int order)
  {
    root = nullptr;
    this->order = order;
  }

  void Insert(int key);

  void Traverse()
  {
    if (root) {
      root->Traverse();
    }
  }

  bool Search(int key)
  {
    return (root == nullptr) ? false : root->Search(key);
  }
};

bool BTreeNode::Search(int key)
{
  int i=0;
  while ((i < numKeys) && (key > keys[i])) {
    i++;
  }

  if (keys[i] == key) {
    return true;
  }

  //If key is not found, check if it is leaf node.
  //If leaf node, then no further search possible, return false.
  if (isLeaf == true) {
    return false;
  }
  //If it is not a leaf node, then child node may contain key. Extend search to child node.
  return children[i]->Search(key);
}

void BTreeNode::Traverse()
{
  //Each node contains 2*order -1 keys.
  //Each  node contains 2*order children pointers/nodes.
  //As the first child will hold the keys smaller than 0th key at current node,
  // we need to start traverse from child node.

  //First process numKeys children.
  int i = 0;
  for (i = 0; i < numKeys; i++) {
    //If current node is not leaf node, first process its children node.
    if (isLeaf == false) {
      children[i]->Traverse();
    }
    std::cout << keys[i] << " ";
  }

  //Process last child.
  if (isLeaf == false) {
    children[i]->Traverse();
  }
}

void BTreeNode::SplitNode(int pos, BTreeNode *node)
{
  //Create a new node.
  BTreeNode* newNode = new BTreeNode(node->order, node->isLeaf);
  newNode->numKeys = order -1;

  //Copy the last [order-1] keys from node to newNode.
  for (int i=0; i < order-1; i++) {
    newNode->keys[i] = node->keys[i + order];
  }

  //Copy the last [order] children from node to new node.
  for (int i=0; i < order; i++) {
    newNode->children[i] = node->children[i + order];
  }

  //Update/Reduce the number of keys in node.
  node->numKeys = order - 1;

  //Now we need to assign this new node into current node children pointer array.
  //Shift the children pointers till pos.
  for (int i=numKeys; i >= pos+1; i--) {
    children[i + 1] = children[i];
  }
  //Add new child.
  children[pos + 1] = newNode;

  //Copy mid value from node to current node.
  for (int i = numKeys -1; i >= pos; i--) {
    keys[i + 1] = keys[i];
  }
  //Copy mid key present at index order-1.
  keys[pos] = node->keys[order -1];

  //Increment number of keys in current node.
  numKeys = numKeys + 1;
}

void BTreeNode::InsertNonFull(int key)
{
  //Check if it is leaf node.
  if (isLeaf == true) {
    //Find the correct index for new key in array of keys.
    int i = numKeys - 1;
    while ((i >=0) && (keys[i] > key)) {
      keys[i + 1] = keys[i];
      i--;
    }

    //Insert new key and increment numKeys count.
    keys[i + 1] = key;
    numKeys++;
  } else {  //Current node is not a leaf node.
    //Find the child node in which the key will be inserted.
    int i = numKeys - 1;
    while ((i >= 0) && (keys[i] > key)) {
      i--;
    }

    // NOTE: After above loop, children[i+1] is child node where new key will be inserted.
    //Check if the child node where key is to be inserted is full.
    if (children[i+1]->numKeys == (2*order -1)) {
      SplitNode(i+1, children[i+1]);

      //Check key will be inserted in i+1 or newly created node after split at i+2.
      if (key > keys[i+1]) {
        i++;
      }
    }
    //Recursively call this function on next node to insert the key.
    children[i+1]->InsertNonFull(key);
  }
}

void BTree::Insert(int key)
{
  std::cout << "\nInserting key: " << key << " in BTree." << std::endl;
  //If root is nullptr.
  if (root == nullptr) {
    root = new BTreeNode(order, true);
    root->keys[0] = key;
    root->numKeys = 1;
  }
  else { // Root node is present.
    //Check if root node is full.
    if (root->numKeys == (2*order - 1)) {
      //Create new node.
      BTreeNode* newNode = new BTreeNode(order, false);

      //Make current root node as child of this node.
      newNode->children[0] = root;

      //Split current root node.
      //This operation will split root into two nodes, each with half of values.
      //The mid-value will be copied to newNode.
      newNode->SplitNode(0, root);

      //As root is split into two half, check in which one of them new key will be inserted.
      int index = 0;  //Assume key will be inserted into first half node.
      if (key > newNode->keys[0]) {
        index = 1;
      }
      newNode->children[index]->InsertNonFull(key);

      //Assign newNode as new root node.
      root = newNode;
    }
    else {
      root->InsertNonFull(key);
    }
  }
}


void Test_BTree()
{
  BTree bTree(3);

  bTree.Insert(10);
  bTree.Insert(20);
  bTree.Insert(30);
  bTree.Insert(40);
  bTree.Insert(50);
  bTree.Insert(60);
  bTree.Insert(70);
  bTree.Insert(80);
  bTree.Insert(90);
  bTree.Insert(100);
  bTree.Insert(13);
  bTree.Insert(11);
  bTree.Insert(18);
  bTree.Insert(12);
  bTree.Insert(16);
  bTree.Insert(75);
  bTree.Insert(85);

  //Test traverse.
  std::cout << "\n\nTraversing the tree!!!\n";
  bTree.Traverse();
  std::cout << std::endl;

  //Test search.
  int searchKeys[] = {100, 200, 30, 48, 10, 50};
  for (int sKey : searchKeys)
  {
    if (bTree.Search(sKey)) {
      std::cout << "\nKey: " << sKey << " is present in tree.";
    }
    else {
      std::cout << "\nKey: " << sKey << " is not present in tree.";
    }
  }
  std::cout << std::endl;
}