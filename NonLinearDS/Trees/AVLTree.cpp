/*
 * Description:
 *
 * Created on 10/12/2024.
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com
*/

#include <iostream>
#include <queue>

#include "Trees.h"


class AVLTree {
  public:
  class Node {
    public:
    int key;
    Node *left;
    Node *right;
    int height;

    explicit Node(int value)
    {
      key = value;
      left = nullptr;
      right = nullptr;
      height = 1;
    }
  };

  AVLTree()
  {
    root = nullptr;
  }

  ~AVLTree()
  {
    DeleteTree();
    root = nullptr;
  }

  //API for right rotation of tree/subtree.
  Node* RightRotate(Node *node)
  {
    //Make rotation.
    Node *y = node->left;
    node->left = y->right;
    y->right = node;

    //Update heights
    node->height = std::max(Height(node->left), Height(node->right)) + 1;
    y->height = std::max(Height(y->left), Height(y->right)) + 1;

    //Now y is new root for given subtree after rotation.
    return y;
  }

  //API for left rotation of tree/subtree.
  Node* LeftRotate(Node *node)
  {
    //Make rotation.
    Node *y = node->right;
    node->right = y->left;
    y->left = node;

    //Update heights.
    node->height = std::max(Height(node->left), Height(node->right)) + 1;
    y->height = std::max(Height(y->left), Height(y->right)) + 1;

    //Now y is the new root for given subtree after rotation.
    return y;
  }

  Node* AddNode(int value)
  {
    std::cout << "Adding node: " << value << std::endl;
    if (root == nullptr) {
      root = new Node(value);
      return root;
    }

    //Print Level order after adding each node to validate balance.
    //Update root pointer, as there is possibility of root node becoming the child node.
    root = AddNode(root, value);
    Traverse(LEVEL_ORDER);
    return root;
  }

  Node* AddNode(Node* node, int value)
  {
    if (node == nullptr) {
      return new Node(value);
    }

    if (value < node->key) {
      node->left = AddNode(node->left, value);
    }
    else if (value > node->key) {
      node->right = AddNode(node->right, value);
    }
    else {
      std::cout << "Duplicate node being added. Skipped!!!" << std::endl;
      return node;
    }

    //Set height of nodes for all those nodes that comes in path from root to newly added node.
    node->height = 1 + std::max(Height(node->left), Height(node->right));

    //Logic to balance tree.
    //Get balance factor of node.
    int balanceFactor = BalanceFactor(node);

    //Case 1: Left-Left case.
    //New node is added on left hand side of left child of node.
    if ((balanceFactor > 1) && (value < node->left->key)){
      return RightRotate(node->left);
    }

    //Case 2: Right-Right case.
    //Node is added on right side of right child of node.
    if ((balanceFactor < -1) && (value > node->right->key)) {
      return LeftRotate(node);
    }

    //Case 3: Left-right case.
    // New node is added on right side for left child of node.
    if ((balanceFactor > 1) && (value > node->left->key)) {
      node->left = LeftRotate(node->left);
      return RightRotate(node);
    }

    //Case 4: Right-Left case.
    // New node is added on left hand side of right child of node.
    if ((balanceFactor < -1) && (value < node->right->key)) {
      node->right = RightRotate(node->right);
      return LeftRotate(node);
    }

    return node;
  }

  Node *DeleteNode(int value)
  {
    if (root == nullptr) {
      return nullptr;
    }
    root = DeleteNode(root, value);
    return root;
  }

  Node* DeleteNode(Node* node, int value)
  {
    if (node == nullptr) {
      return nullptr;
    }

    if (value < node->key) {
      node->left = DeleteNode(node->left, value);
    }
    else if (value > node->key) {
      node->right = DeleteNode(node->right, value);
    }
    else {
      //Value matched. Delete current node.
      //Case 1: Leaf node.
      // This case can be removed and will be handled by case2/3.
      // But for readability and clear understanding, it is being added here.
      if (node->left == nullptr && node->right == nullptr) {
        delete node;
        return nullptr;
      }

      //Case 2: If only right child exists.
      if (node->left == nullptr) {
        Node* rchild = node->right;
        delete node;
        return rchild;
      }

      //Case 3: If only left child exists.
      if (node->right == nullptr) {
        Node* lchild = node->left;
        delete node;
        return lchild;
      }

      //Case 4: Both child exists.
      //BST implements this case using min node from right subtree.
      //Here, we will use max node from left subtree.
      //Get max node from left subtree.
      Node *temp = node->left;
      while (temp->right != nullptr) {
        temp = temp->right;
      }

      //Copy value of temp node to current node.
      node->key = temp->key;

      //Delete temp node.
      // Using left child pointer, as the temp node is present in left.
      node->left = DeleteNode(node->left, temp->key);
      return node;
    }

    //Balance the tree, if gone out of balance.
    //Update the height of node.
    node->height = std::max(Height(node->left), Height(node->right)) + 1;

    //Get balance factor.
    int balanceFactor = BalanceFactor(node);

    //Case 1: Left-Left case.
    if ((balanceFactor > 1) && (BalanceFactor(node->left) >= 0)) {
      return RightRotate(node);
    }

    //Case 2: Right-Right case.
    if ((balanceFactor < -1) && (BalanceFactor(node->right) <= 0)) {
      return LeftRotate(node);
    }

    //Case 3: Left-Right case.
    if ((balanceFactor > 1) && (BalanceFactor(node->left) < 0)) {
      node->left = LeftRotate(node->left);
      return RightRotate(node);
    }

    //Case 4: Right-Left case.
    if ((balanceFactor < -1) && (BalanceFactor(node->right) > 0)) {
      node->right = RightRotate(node->right);
      return LeftRotate(node);
    }

    return node;
  }

  bool Search(int value)
  {
    if (root == nullptr) {
      return false;
    }
    return Search(root, value);
  }

  bool Search(Node* node, int value)
  {
    if (node == nullptr) {
      return false;
    }

    if (value < node->key) {
      return Search(node->left, value);
    }
    if (value > node->key) {
      return Search(node->right, value);
    }
    return true;
  }

  void Traverse(TraversalOrder traversalOrder)
  {
    switch (traversalOrder) {
      case PRE_ORDER:
        PrintPreOrder(root);
        break;
      case IN_ORDER:
        PrintInOrder(root);
        break;
      case POST_ORDER:
        PrintPostOrder(root);
        break;
      case LEVEL_ORDER:
        PrintLevelOrder();
        break;
      default:
        break;
    }
  }

  void PrintPreOrder(Node *node)
  {
    if (node == nullptr) {
      return;
    }

    std::cout << node->key << " ";
    PrintPreOrder(node->left);
    PrintPreOrder(node->right);
  }

  void PrintInOrder(Node *node)
  {
    if (node == nullptr) {
      return;
    }

    PrintInOrder(node->left);
    std::cout << node->key << " ";
    PrintInOrder(node->right);
  }

  void PrintPostOrder(Node *node)
  {
    if (node == nullptr) {
      return;
    }

    PrintPostOrder(node->left);
    PrintPostOrder(node->right);
    std::cout << node->key << " ";
  }

  void PrintLevelOrder()
  {
    if (root == nullptr) {
      return;
    }

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
      Node* top = q.front();
      q.pop();
      std::cout << top->key << " ";

      if (top->left != nullptr) {
        q.push(top->left);
      }
      if (top->right != nullptr) {
        q.push(top->right);
      }
    }
    std::cout << std::endl;
  }

  int Height()
  {
    if (root == nullptr) {
      return 0;
    }
    return Height(root);
  }

  int Height(Node* node)
  {
    return (node == nullptr) ? 0 : node->height;
  }

  int BalanceFactor(Node *node)
  {
    if (node == nullptr) {
      return 0;
    }
    return (Height(node->left) - Height(node->right));
  }

  void DeleteTree()
  {
    //This is alternate approach from BST.
    //Keep deleting root node, until all nodes are deleted.
    while (root != nullptr) {
      root = DeleteNode(root->key);
    }
    root = nullptr;
  }

private:
  Node *root;
};


void Test_AVLTree()
{
  AVLTree tree;

  //Add nodes to the trees.
  tree.AddNode(50);
  tree.AddNode(7);
  tree.AddNode(8);
  tree.AddNode(2);
  tree.AddNode(15);
  tree.AddNode(34);
  tree.AddNode(67);
  tree.AddNode(61);
  tree.AddNode(99);
  tree.AddNode(18);
  tree.AddNode(43);
  tree.AddNode(56);
  tree.AddNode(130);
  tree.AddNode(144);
  tree.AddNode(55);

  //Test traversal functions.
  std::cout << "\nPre-Order traversal order : ";
  tree.Traverse(PRE_ORDER);

  std::cout << "\nIn-Order traversal order : ";
  tree.Traverse(IN_ORDER);

  std::cout << "\nPost-Order traversal order : ";
  tree.Traverse(POST_ORDER);

  std::cout << "\nLevel-Order traversal order : ";
  tree.Traverse(LEVEL_ORDER);

  //Test search of elements in tree.
  int searchTestElems[] = {99, 34, 5, 4, 89, 45};
  for (int searchTestElem : searchTestElems) {
    if (tree.Search(searchTestElem)) {
      std::cout << "Element [" << searchTestElem << "] is present in tree!!!" << std::endl;
    }
    else {
      std::cout << "Element [" << searchTestElem << "] is not present in tree!!!" << std::endl;
    }
  }

  //Print height of tree.
  std::cout << "\nHeight of tree is: " << tree.Height() << std::endl;

  //Test deletions.
  int deleteTestElems[] = {43, 56, 15, 61, 50, 100};
  for (int deleteTestElem : deleteTestElems) {
    std::cout << "\nDeleting element [" << deleteTestElem << "] from tree!!!" << std::endl;

    bool result = tree.DeleteNode(deleteTestElem);
    if (result)
    {
      std::cout << "Element [" << deleteTestElem << "] deleted successfully!!!" << std::endl;
    }
    else
    {
      std::cout << "Element [" << deleteTestElem << "] not present in tree and could not be deleted!!!" << std::endl;
    }

    std::cout << "Level order traversal of tree after deletion of node: ";
    tree.Traverse(LEVEL_ORDER);
  }

  //Test deletion of tree.
  std::cout << "\nDeleting complete tree i.e. all nodes are getting deleted\n";
  tree.DeleteTree();
  std::cout << "Height of tree after tree deletion: " << tree.Height() << std::endl;
}