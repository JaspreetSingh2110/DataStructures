//
// Created by Jaspreet Singh on 29/09/24.
//

#include "UnionFind.h"

UnionFind::UnionFind(int n)
{
  ids = new int[n];
  sz = new int[n];
  numNodes = n;

  //As each node initially is unique component.
  numComponents = n;

  // Initialise each node Id as own to represent it is a root node.
  // As initially each node is unique component in itself, and
  // contains only itself, so initialise size as 1.
  for (int i = 0; i < n; i++) {
    ids[i] = i;
    sz[i] = 1;
  }
}

UnionFind::~UnionFind()
{
  delete[] ids;
  delete[] sz;
  numNodes = 0;
  numComponents = 0;
}

//Get the root node of given node in argument.
int UnionFind::Find(int p)
{
  int root = p;
  //If node is not a root node, the Id will contain the Id of its root node, go to that node.
  //Perform similar check and continue, till it reaches the root node index.
  while (root != ids[root]) {
    root = ids[root];
  }

  // Below code is for compressing the path.
  // i.e. make all the nodes on the path from p->x->y->z->Root to point directly at root.
  // After this loop, p->Root, x->Root, y->Root and z->Root.
  // Why we need this?
  // While finding the root of given node, the latency decreases.
  while (ids[p] != root) {
    int currentParent = ids[p];
    ids[p] = root;
    p = currentParent;
  }

  return root;
}

void UnionFind::Unite(int x, int y)
{
  //If both nodes belong to same component, do nothing.
  if (IsConnected(x,y)) {
    return;
  }

  int rootX = Find(x);
  int rootY = Find(y);

  //Merge smaller component into bigger component.
  if (sz[rootX] < sz[rootY]) {
    //Assign the root of smaller component to point to root of larger component.
    ids[rootX] = rootY;
    //Increase the size of larger component by size of smaller component that got unified.
    sz[rootY] += sz[rootX];
    //Reset the size of smaller component to 0.
    sz[rootX] = 0;
  }
  else {
    ids[rootY] = rootX;
    sz[rootX] += sz[rootY];
    sz[rootY] = 0;
  }

  // Whenever a unification happens, the component count decreases.
  // Also note that, numComponents=1 means, all nodes are part of same component.
  numComponents--;
}

bool UnionFind::IsConnected(int x, int y)
{
  // If root node of both nodes are same, they are part of same component.
  // So, they are connected, directly or indirectly.
  return Find(x) == Find(y);
}

int UnionFind::GetComponentsCount()
{
  return numComponents;
}
