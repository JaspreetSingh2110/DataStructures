//
// Created by Jaspreet Singh on 29/09/24.
//

#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <iostream>

class UnionFind {
  private:
  int *sz = nullptr;
  int *ids = nullptr;
  int numNodes = 0;
  int numComponents = 0;

  public:
  UnionFind(int n);
  ~UnionFind();

  int Find(int p);
  void Unite(int x, int y);
  bool IsConnected(int x, int y);
  int GetComponentsCount();
};

#endif //UNIONFIND_H
