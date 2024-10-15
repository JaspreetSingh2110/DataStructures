/*
 * Description:
 * Implementation of Red-Black tree.
 *
 * Created on: 15/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <queue>

#define RED true
#define BLACK false

class RedBlackTree {
  public:
  class Node {
    public:
    int key;
    bool color;
    Node *left;
    Node *right;
    Node *parent;

    explicit Node(int key)
    {
      this->key = key;
    }

    explicit Node(int key, bool color, Node *left, Node *right, Node *parent)
    {
      this->key = key;
      this->color = color;
      this->left = left;
      this->right = right;
      this->parent = parent;
    }
  };

  void AddNode(int val)
  {
    std::cout << "\nAdding node with value: " << val << std::endl;
    Insert(val);
    LevelOrderTraverse();
  }

  void DeleteNode(int val)
  {
    std::cout << "\nDeleting node with value: " << val << std::endl;
    Delete(val);
    LevelOrderTraverse();
  }

  void LeftRotate(Node* node)
  {
    Node* rChild = node->right;
    node->right = rChild->left;
    if (rChild->left != nil) {
      rChild->left->parent = node;
    }

    rChild->parent = node->parent;
    if (node->parent == nil) {
      root = node;
    } else if (node == node->parent->left) {
      node->parent->left = rChild;
    } else {
      node->parent->right = rChild;
    }
    node->parent = rChild;
    rChild->left = node;
  }

  void RightRotate(Node* node)
  {
    Node* lChild = node->left;
    node->left = lChild->right;
    if (lChild->right != nil) {
      lChild->right->parent = node;
    }

    lChild->parent = node->parent;
    if (node->parent == nil) {
      root = lChild;
    } else if (node == node->parent->left) {
      node->parent->left = lChild;
    } else {
      node->parent->right = lChild;
    }
    node->parent = lChild;
    lChild->right = node;
  }

  Node* Insert(int val)
  {
    if (root == nil) {
      root = new Node(val, BLACK, nil, nil, nil);
      return root;
    }
    return Insert(root, val);
  }

  Node* Insert(Node* node, int val)
  {
    Node* parent = nil;
    Node* current = root;

    //Traverse till parent node, to which new node will be added.
    while (current != nil) {
      parent = current;
      if (val < current->key) {
        current = current->left;
      } else if (val > current->key) {
        current = current->right;
      } else {
        std::cout << "Node with same value already exists. Skipping node addition!!!\n";
        return root;
      }
    }

    //Create new node.
    Node* newNode = new Node(val, RED, nil, nil, parent);

    //Assign parent's left/right pointer to new node.
    if (val < parent->key) {
      parent->left = newNode;
    } else {
      parent->right = newNode;
    }

    //Fix the insert violations.
    FixInsert(newNode);
    return root;
  }

  void FixInsert(Node* node)
  {
    //Case 1: If Parent is black, no violation, return.
    if (node->parent && node->parent->color == BLACK) {
      return;
    }

    //Case 2: If parent is RED, check for specific case and fix tree.
    while (node->parent->color == RED) {
      //If node's parent is left child of grand parent.
      if (node->parent == node->parent->parent->left) {
        Node* uncle = node->parent->parent->right;
        //Case 2.1: If uncle node is RED in color.
        if (uncle && uncle->color == RED) {
          uncle->color = BLACK;
          node->parent->color = BLACK;
          node->parent->parent->color = RED;
        } else {
          //Case 2.2: Uncle node is BLACK in color.
          //Subcase 2.2.1: Node is right child of parent. Rotate left.
          // Also, note that when we assign node = parent, after rotation it becomes child node.
          // So, in below case, 2.2.2, when we access it, its actually becomes grandchild of rotation case.
          if (node == node->parent->right) {
            node = node->parent;
            LeftRotate(node);  //Left rotation to be done on parent. It will become child node.
          }
          //Subcase 2.2.2: If node is left child of parent, Rotate right.
          //NOTE: Even if above case hits, Left-Right case,
          // it will eventually become Left Left case after Left rotation.
          // So, we are not using else here.
          node->parent->color = BLACK;
          node->parent->parent->color = RED;
          //Right rotation to be done on grand parent.
          RightRotate(node->parent->parent);
        }
      }
      else {  // If node's parent is right child of grand parent.
        Node* uncle = node->parent->parent->left;
        //Case 2.1: If uncle node is RED in color.
        if (uncle && uncle->color == RED) {
          uncle->color = BLACK;
          node->parent->color = BLACK;
          node->parent->parent->color = RED;
        } else {
          //Case 2.2: Uncle node is BLACK in color.
          //Subcase 2.2.1: Node is left child of parent, Rotate right.
          if (node == node->parent->left) {
            node = node->parent;
            RightRotate(node);
          }
          //Subcase 2.2.2: Node is right child of parent.
          node->parent->color = BLACK;
          node->parent->parent->color = RED;
          LeftRotate(node->parent->parent);
        }
      }
    }

    //Fix color of root node.
    root->color = BLACK;
  }

  Node* Delete(int val)
  {
    if (root == nil) {
      return nullptr;
    }
    return Delete(root, val);
  }

  Node* Delete(Node* node, int val)
  {
    return root;
  }

  RedBlackTree()
  {
    //Create nil node.
    nil = new Node(0);
    nil->color = BLACK;
    nil->left = nil;
    nil->right = nil;
    nil->parent = nil;

    root = nil;
  }

  void LevelOrderTraverse()
  {
    //If empty tree.
    if (root == nil) {
      return;
    }

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
      Node *front = q.front();
      q.pop();

      //Print data of current node.
      std::cout << front->key << " ";

      //Add children of current node to queue.
      if (front->left != nil) {
        q.push(front->left);
      }
      if (front->right != nil) {
        q.push(front->right);
      }
    }
  }

  Node *root = nullptr;
  Node *nil = nullptr;
};


void Test_RedBlackTree()
{
  RedBlackTree tree;

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
  std::cout << "\nLevel-Order traversal order : ";
  tree.LevelOrderTraverse();

  /*
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
  */
}