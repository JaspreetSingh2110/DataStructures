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

  bool DeleteNode(int val)
  {
    std::cout << "\nDeleting node with value: " << val << std::endl;
    if (Delete(val) == nil) {
      return false;
    }
    return true;
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
      root = rChild;
    } else if (node == node->parent->left) {
      node->parent->left = rChild;
    } else {
      node->parent->right = rChild;
    }

    rChild->left = node;
    node->parent = rChild;
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

    lChild->right = node;
    node->parent = lChild;
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
    //Case 2: If parent is RED, check for specific case and fix tree.
    while (node->parent->color == RED) {
      //If node's parent is left child of grand parent.
      if (node->parent == node->parent->parent->left) {
        Node* uncle = node->parent->parent->right;
        //Case 2.1: If uncle node is RED in color.
        if (uncle->color == RED) {
          uncle->color = BLACK;
          node->parent->color = BLACK;
          node->parent->parent->color = RED;
          node = node->parent->parent;
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
        if (uncle->color == RED) {
          uncle->color = BLACK;
          node->parent->color = BLACK;
          node->parent->parent->color = RED;
          node = node->parent->parent;
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
    nil->parent = nullptr;
  }

  Node* Delete(int val)
  {
    Node* z = Search(val);
    if (z == nil) {
      return nil;
    }

    Node* x;  //This will point to replacement node.
    Node* y = z; //This points to node to be removed.
    bool yOrigColor = y->color;

    //BST delete with transplant.
    //Case 1: Leaf node.
    if (y->left == nil && y->right == nil) {
      x = nil;
      Transplant(y, x);
    }
    //Case 2: Node with only left child.
    else if (y->left == nil) {
      x = y->right;
      Transplant(y, x);
    }
    //Case 3: Node with only right child.
    else if (y->right == nil) {
      x = y->left;
      Transplant(y,x);
    }
    //Case 4: Node with both left and right child.
    else {
      //Get the successor. (Min node from right subtree.)
      // NOTE: We can also use max node from left subtree.
      y = z->right;
      while(y->left != nil) {
        y = y->left;
      }
      yOrigColor = y->color;

      //Leftmost node will only have right child (if present)
      x = y->right;
      if (y->parent == z) {
        x->parent = y;
      } else {
        Transplant(y, x);
        y->right = z->right;
        z->right->parent = y;
      }
      Transplant(z,y);
      y->left = z->left;
      z->left->parent = y;
      y->color = z->color;
    }

    if (yOrigColor == BLACK) {
      FixDelete(x);
    }
    return root;
  }

  void FixDelete(Node* node)
  {
    Node* x = node;
    //Repeat this: current node is not root and its color is BLACK.
    while ((x != root) && (x->color == BLACK)) {
      //If x is left node of child
      if (x == x->parent->left) {
        //Get sibling node. Since x is left child, sibling would be right child of x's parent.
        Node* s = x->parent->right;

        //Case 1: Sibling color is RED.
        if (s->color == RED) {
          s->color = BLACK;
          x->parent->color = RED;
          LeftRotate(x->parent);
          //Reassign sibling pointer 's' to updated sibling of x.
          s = x->parent->right;
        }
        //Case 2: Sibling is black and both children of sibling are black nodes.
        if ((s->left->color == BLACK) && (s->right->color == BLACK)) {
          //Update color of sibling as RED.
          s->color = RED;
          //Update the x to its parent and next loop will take care its violations.
          x = x->parent;
        } else {
          //Case 3: One of the children of sibling is BLACK.
          //3.1: If right child of sibling is black.
          if (s->right->color == BLACK) {
            s->left->color = BLACK;
            s->color = RED;
            RightRotate(s);
            //Update the sibling pointer.
            s = s->parent->right;
          }
          //3.2: If left child of sibling is black.
          s->color = x->parent->color;
          x->parent->color = BLACK;
          s->right->color = BLACK;
          LeftRotate(x->parent);
          x = root;
        }
      }
      else {  //x is right child of its parent.
        //Since, x is right child of its parent, its sibling will be left child.
        Node* s = x->parent->left;
        //Case 1: Sibling is red node.
        if (s->color == RED) {
          s->color = BLACK;
          x->parent->color = RED;
          RightRotate(x->parent);
          s = x->parent->left;
        }

        //Case 2: Sibling is black and color of its both children is BLACK.
        if ((s->left->color == BLACK) && (s->right->color == BLACK)) {
          s->color = RED;
          x = x->parent;
        } else {
          //Case 3: One of child of sibling is BLACK.
          //3.1: Left child is black node.
          if (s->left->color == BLACK) {
            s->right->color = BLACK;
            s->color = RED;
            LeftRotate(s);
            s = x->parent->left;
          }

          s->color = s->parent->color;
          x->parent->color = BLACK;
          s->left->color = BLACK;
          RightRotate(x->parent);
          x = root;
        }
      }
    } //while loop ends.
    x->color = BLACK;
  }

  RedBlackTree()
  {
    //Create nil node.
    nil = new Node(-1);
    nil->color = BLACK;
    nil->left = nil;
    nil->right = nil;
    nil->parent = nullptr;

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
      //std::cout << front->key << " (" << (front->color == BLACK ? "BLACK" : "RED") << ") " << std::endl;

      //Add children of current node to queue.
      if (front->left != nil) {
        q.push(front->left);
      }
      if (front->right != nil) {
        q.push(front->right);
      }
    }
  }

  Node* Search(int val)
  {
    Node* temp = root;
    while (temp != nil) {
      if (val < temp->key) {
        temp = temp->left;
      } else if (val > temp->key) {
        temp = temp->right;
      } else {
        return temp;
      }
    }
    return nil;
  }

  //Primary function to get height of tree.
  int Height()
  {
    return Height(root);
  }

  //Helper function to get height of tree.
  int Height(Node *node)
  {
    if (node == nil) {
      return 0;
    }

    return (1 + std::max(Height(node->left), Height(node->right)));
  }

  void DeleteTree()
  {
    while (root != nil) {
      DeleteNode(root->key);
    }
  }

  void Transplant(Node* u, Node* v)
  {
    if (u->parent == nil) {
      root = v;
    }
    else if (u == u->parent->left) {
      u->parent->left = v;
    } else {
      u->parent->right = v;
    }
    v->parent = u->parent;
  }

private:
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

  //Print height of tree.
  std::cout << "\nHeight of tree is: " << tree.Height() << std::endl;

  //Test deletions.
  /*
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
    tree.LevelOrderTraverse();
  }
  */

  //Test deletion of tree.
  std::cout << "\nDeleting complete tree i.e. all nodes are getting deleted\n";
  tree.DeleteTree();
  std::cout << "Height of tree after tree deletion: " << tree.Height() << std::endl;
}