/*
 * Description:
 * Implementation of Binary search trees.
 *
 * Created on: 09/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <ostream>
#include <queue>
#include <stack>

enum TraversalOrder {
  PRE_ORDER = 0,
  IN_ORDER = 1,
  POST_ORDER = 2,
  LEVEL_ORDER = 3,
  ORDER_MAX
};

class BinarySearchTrees {
  public:

  class Node {
    public:
    int data;
    Node *left;
    Node *right;

    explicit Node(int d)
    {
      data = d;
      left = nullptr;
      right = nullptr;
    }
  };

  ~BinarySearchTrees()
  {
    DeleteTree();
  }

  void DeleteTree()
  {
    //Delete Tree. i.e. all nodes.
    //Traverse the tree and get all node pointers.
    std::queue<Node *> q;

    if (root == nullptr) {
      return;
    }

    q.push(root);
    while (!q.empty()) {
      auto node = q.front();
      q.pop();

      if (node->left) {
        q.push(node->left);
      }
      if (node->right) {
        q.push(node->right);
      }
      delete node;
    }

    //Reset root.
    root = nullptr;
  }

  //Primary function to add new node to tree.
  Node* AddNode(int value)
  {
    //If empty tree.
    if (root == nullptr) {
      root = new Node(value);
      return root;
    }
    return AddNode(root, value);
  }

  //Helper function to recursively add node to tree.
  Node* AddNode(Node* node, int value)
  {
    if (node == nullptr) {
       return new Node(value);
    }

    //If value is less than root's value, traverse left.
    if (value < node->data) {
      node->left = AddNode(node->left, value);
    }
    //If value is greater than root's value, traverse right.
    else if (value > node->data) {
      node->right = AddNode(node->right, value);
    }
    //Avoid adding duplicate nodes.
    else {
      std::cout << "Duplicate value !!! Not adding node !!!" << std::endl;
    }

    return node;
  }

  //Primary function to delete node
  bool DeleteNode(int value)
  {
    //If empty tree.
    if (Search(value)) {
      root = DeleteNode(root, value);
      return true;
    }
    return false;
  }

  //Helper function to delete node from tree.
  Node *DeleteNode(Node* node, int value)
  {
    //Traverse to required node to be deleted.
    if (value < node->data) {
      node->left = DeleteNode(node->left, value);
    }
    else if (value > node->data) {
      node->right = DeleteNode(node->right, value);
    }
    else {
      //Node found. Value matched.

      /* If node is a leaf node and has no subtree
       * return nullptr to the parent node to point at.
       */
      if (node->left == nullptr && node->right == nullptr) {
        delete node;
        return nullptr;
      }

      /* If node has only right subtree,
       * return its right child pointer to parent node to point at.
       */
      if (node->left == nullptr) {
        Node *rchild = node->right;
        delete node;
        return rchild;
      }
      /* If node has only left subtree,
       * return its left child pointer t oparent node to point at.
       */
      if (node->right == nullptr) {
        Node *lchild = node->left;
        delete node;
        return lchild;
      }
      /* If node has both the childs,
       * get either max child from left subtree, or
       * least child from right subtree.
       * Replace its value with current node to be deleted and
       * delete the node with whose value was swapped.
       */

      //Get the least value node from right subtree.
      Node *temp = node->right;
      while (temp->left != nullptr) {
        temp = temp->left;
      }

      //Copy the data of temp node to current node.
      node->data = temp->data;

      //Delete the temp node.
      node->right = DeleteNode(node->right, temp->data);

      /*
       * Alternate way:
       * Using max value node from left subtree.
       *
       * Node *temp = node->left;
       * while (temp->right != nullptr) {
       *   temp = temp->right;
       * }
       *
       * node->data = temp->data;
       * node->left = DeleteNode(node->left, temp->value);
       */
      return node;
    }
    return node;
  }

  //Primary function to search for node in a tree.
  bool Search(int value)
  {
    //Empty tree.
    if (root == nullptr) {
      return false;
    }

    return Search(root, value);
  }

  //Helper function to recursively search for node in a tree.
  bool Search(Node* node, int value)
  {
    //If node is not found, after traversing all levels.
    if (node == nullptr) {
      return false;
    }

    if (value < node->data) {
      return Search(node->left, value);
    }
    else if (value > node->data) {
      return Search(node->right, value);
    }
    // Else case when value matches.
    return true;
  }

  //Primary function for traversing the tree.
  void Traverse(TraversalOrder traversalOrder)
  {
    switch (traversalOrder) {
      case PRE_ORDER:
        TraversePreOrder(root);
        break;
      case IN_ORDER:
        TraverseInOrder(root);
        break;
      case POST_ORDER:
        TraversePostOrder(root);
        break;
      case LEVEL_ORDER:
        TraverseLevelOrder();
      break;
      default:
        std::cout << "Unknown traversal order !!!" << std::endl;
        break;
    }
    std::cout << std::endl;
  }

  //Helper function to pre-order traverse the tree.
  void TraversePreOrder(Node *node)
  {
    if (node == nullptr) {
      return;
    }

    std::cout << node->data << " ";
    TraversePreOrder(node->left);
    TraversePreOrder(node->right);
  }

  //Helper function to in-order traverse the tree.
  void TraverseInOrder(Node *node)
  {
    if (node == nullptr) {
      return;
    }

    TraverseInOrder(node->left);
    std::cout << node->data << " ";
    TraverseInOrder(node->right);
  }

  //Helper function to post-order traverse the tree.
  void TraversePostOrder(Node *node)
  {
    if (node == nullptr) {
      return;
    }

    TraversePostOrder(node->left);
    TraversePostOrder(node->right);
    std::cout << node->data << " ";
  }

  //Helper function to level-order traverse the tree.
  void TraverseLevelOrder()
  {
    //If empty tree.
    if (root == nullptr) {
      return;
    }

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
      Node *front = q.front();
      q.pop();

      //Print data of current node.
      std::cout << front->data << " ";

      //Add children of current node to queue.
      if (front->left != nullptr) {
        q.push(front->left);
      }
      if (front->right != nullptr) {
        q.push(front->right);
      }
    }
  }

  //Primary function to get height of tree.
  int Height()
  {
    return Height(root);
  }

  //Helper function to get height of tree.
  int Height(Node *node)
  {
    if (node == nullptr) {
      return 0;
    }

    return (1 + std::max(Height(node->left), Height(node->right)));
  }

  Node *root = nullptr;
};


void Test_BinarySearchTree()
{
  BinarySearchTrees tree;

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
