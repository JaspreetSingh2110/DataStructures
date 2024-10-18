/*
 * Description:
 *
 * Created on: 09/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#ifndef TREES_H
#define TREES_H

enum TraversalOrder {
 PRE_ORDER = 0,
 IN_ORDER = 1,
 POST_ORDER = 2,
 LEVEL_ORDER = 3,
 ORDER_MAX
};

void Test_BinarySearchTree();
void Test_AVLTree();
void Test_RedBlackTree();
void Test_BTree();
void Test_BPlusTree();
void Test_Trie();

#endif //TREES_H
