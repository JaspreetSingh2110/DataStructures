#include <iostream>
#include <vector>

#include "Common/Utils.h"
#include "SortingTechniques/SortingTechniques.h"
#include "LinearDS/Stack.h"
#include "LinearDS/Queue.h"
#include "LinearDS/SingleLinkedLists.h"
#include "LinearDS/DoubleLinkedList.h"
#include "NonLinearDS/Graphs/Graphs.h"
#include "Search/Search.h"
#include "NonLinearDS/Trees/Trees.h"
#include "NonLinearDS/Heap/Heap.h"

#include "Algorithms/Algorithms.h"

void TestLinearDS() {
  std::cout << "Testing data structures implementation!" << std::endl;

  std::cout << "Testing 'Stack' implementation!" << std::endl;
  TestStack();

  std::cout << "Testing 'Queue' implementation!" << std::endl;
  TestQueue();

  std::cout << "Testing 'Single LinkedLists' implementation!" << std::endl;
  TestSingleLinkedLists();

  std::cout << "Testing 'Double LinkedLists' implementation!" << std::endl;
  TestDoubleLinkedLists();

  std::cout << "Testing DONE!" << std::endl;
}

void TestSortingTechniques()
{
  std::vector<int> nums1 = {5, 4, 3, 2, 1};
  std::vector<int> nums2 = {2, 4, 3, 5, 1};
  std::vector<int> nums3 = {3, 4, 2, 5, 1};
  std::vector<int> nums4 = {3, 4, 2, 5, 1, 3, 2};
  std::vector<int> nums5 = {
    22, 66, 33, 99, 6, 15, 67, 87, 55, 87, 91, 9, 71, 92, 25, 31, 48, 67, 1, 93
  };
  std::vector<std::vector<int>> testVectors = {nums1, nums2, nums3, nums4, nums5};

  for (auto testVector : testVectors) {
    std::cout << "Test array: " << std::endl;
    PrintVector(testVector);

    //std::cout << "Testing Bubble Sort\n";
    //BubbleSort(testVector);
    //PrintVector(testVector);

    //std::cout << "Testing Selection Sort\n";
    //SelectionSort(testVector);
    //PrintVector(testVector);

    //std::cout << "Testing Insertion Sort\n";
    //InsertionSort(testVector);
    //PrintVector(testVector);

    //std::cout << "Testing Counting Sort\n";
    //CountingSort(testVector);
    //PrintVector(testVector);

    //std::cout << "Testing Merge Sort\n";
    //MergeSort(testVector, 0, testVector.size() -1);
    //PrintVector(testVector);

    //std::cout << "Testing Shell Sort\n";
    //ShellSort(testVector);
    //PrintVector(testVector);

    //std::cout << "Testing Quick Sort\n";
    //QuickSort(testVector, 0, testVector.size() -1);
    //PrintVector(testVector);

    //std::cout << "Testing Bucket Sort\n";
    //BucketSort(testVector);
    //PrintVector(testVector);

    //std::cout << "Testing Radix Sort\n";
    //RadixSort(testVector);
    //PrintVector(testVector);
  }
}

void Test_Graphs()
{
  std::cout << "\nTesting Depth first search!!!\n";
  TestDFS();

  std::cout << "\nTesting Breadth first search!!!\n";
  TestBFS();

  std::cout << "\nTesting BFS shortest path !!!\n";
  TestBFSShortestPath();

  std::cout << "\nTesting BFS shortest path on Grid!!!\n";
  Test_BFS_ShortestPathOnGrid();

  std::cout << "\nTest topological sort\n";
  TestTopologicalSortAdjacencyList();

  std::cout << "\nTest Dijkstra SSSP algorithm\n";
  Test_Dijkstra_SingleSourceShortestPath();

  std::cout << "\nTest BellmanFord SSSP algorithm\n";
  Test_BellmanFord_SingleSourceShortestPath();

  std::cout << "\nTest FloydWarshall APSP algorithm\n";
  Test_FloydWarshall_AllPairShortestPath();

  std::cout << "\nTest EulerianPath\n";
  TestEulerianPath();

  std::cout << "\nTest Bridges locator\n";
  TestBridges();

  std::cout << "\nTest Tarjan's strongly connected components\n";
  Test_Tarjans_StronglyConnectedComponents();

  std::cout << "\nTest Articulation points\n";
  TestArticulationPoints();

  std::cout << "\nTest Kruskals MST\n";
  Test_KruskalsMinSpanningTree();

  std::cout << "\nTest Prims MST [lazy version]\n";
  Test_PrimsMinSpanningTree_LazySolver();

  std::cout << "\nTest Ford Fulkerson - Network flow - Max flow algorithm\n";
  Test_NF_FordFulkerson();

  std::cout << "\nTest Edmonds Karp - Network flow - Max flow algorithm\n";
  Test_NF_EdmondsKarp();
}

void TestSearchingTechniques() {
  std::cout << "\nTest Searching Techniques!!!\n";

  std::cout << "\nTest Linear search technique\n";
  TestLinearSearch();

  std::cout << "\nTest Binary search\n";
  TestBinarySearch();

  std::cout << "\nTest Ternary search\n";
  TestTernarySearch();

  std::cout << "\nTest Interpolation search\n";
  TestInterpolationSearch();
}

void Test_Trees()
{
  //Test Binary search tree.
  std::cout << "\nTesting Binary Search Trees\n";
  Test_BinarySearchTree();

  std::cout << "\nTesting AVL Trees\n";
  Test_AVLTree();

  std::cout << "\nTesting Red Black Trees\n";
  Test_RedBlackTree();

  std::cout << "\nTesting B-Trees\n";
  Test_BTree();

  std::cout << "\nTesting B+ Trees\n";
  Test_BPlusTree();

  std::cout << "\nTesting Trie data structure\n";
  Test_Trie();
}

void Test_Heap()
{
  std::cout << "\nTesting Heap\n";

  std::cout << "\nTest Max heap!!!\n";
  Test_MaxHeap();

  std::cout << "\n\nTest Min heap!!!\n";
  Test_MinHeap();

  std::cout << "\n\nTest Heap sort!!!\n";
  Test_HeapSort();
}

void TestNonLinearDS()
{
  Test_Graphs();
  Test_Trees();
  Test_Heap();
}

void Test_DataStructures()
{
  std::cout << "\nTesting Data Structures\n";

  TestSearchingTechniques();
  TestSortingTechniques();
  TestLinearDS();
  TestNonLinearDS();
  std::cout << "*******************************************" << std::endl;
}

void Test_ArrayAlgorithms()
{
  std::cout << "\nTesting Array Algorithms \n";
  Test_MaxArraySum();
  Test_MaxArraySum_KadaneAlgo();

  Test_FindMissingNumber();

  Test_CalculateTrappedWater();
  Test_CalculateTrappedWater_OptimisedUsingSpace();
  Test_CalculateTrappedWater_OptimisedDoublePointers();

  Test_MaxSubArrayProduct();
  Test_MaxSubArrayProductOptimised();

  Test_EquilibriumPoint();
  Test_EquilibriumPoint_Optimised_UsingSpace();
  Test_EquilibriumPoint_Optimised_WithoutUsingSpace();

  Test_FindLeaders();
  Test_FindLeaders_Optimised();

  Test_ArrayRotation();

  Test_KthLargestNumber();
  Test_KthLargestNumber_Optimised_HeapSort();

  Test_FindMaxPlatforms();
  Test_FindMaxPlatforms_Optimised_UsingSort();

  Test_BotanicSequenceMaxLength();

  Test_FindPairSum();
  Test_FindPairSum_Optimised1();
  Test_FindPairSum_Optimised2();
  Test_FindPairSum_Optimised3();

  Test_MaxProfit_1_Transaction();
  Test_MaxProfit_1_Transaction_Optimisedv1();

  Test_FindMinElement();

  Test_BinarySearchRotatedArray();

  Test_FindMaxWaterContained();

  Test_InsertInterval_Optimised();
  Test_MergeIntervals();
  Test_FindNonOverlappingIntervals();

  Test_Sort012_DutchNationalFlagAlgo();
  Test_MoveNegativesToLeft();
  Test_FindMajorityElement();
  Test_SortArrayInWaveForm();
  Test_FindSubArrayWithTargetSum();
  Test_FindPairsWithTargetSum();
  Test_FindTripletsWithTargetSum();
  Test_FindCommonElementsInSortedArray();

  Test_FindLongestSubArrayWithTargetSum0();
  Test_FindLongestSubArrayWithEqual0and1();
  Test_CountSubArraysWithEqual0and1();
  Test_FindLongestConsecutiveSubSequence();

  Test_FindSmallestPositiveMissingNumber();
  Test_FindMissingAndRepeatingNumber();
  Test_MinimizeHeightDifference();
  Test_FindMaxSumPathInTwoSortedArrays();
  Test_StockSpan();
  Test_StockBuySell_1();
  Test_StockBuySellMultipleTransactions();

  Test_LongestAlternatingSubSequence();
  Test_LongestIncreasingSubSequence();
  Test_FindMaxReachableIndex();
  Test_UnionSortedArrays();
  Test_IntersectionSortedArrays();
}

void Test_StringAlgorithms()
{
  std::cout << "\nTesting string Algorithms !!!\n";

  Test_ReverseWords();
  Test_FindClosestDistance();
  Test_IsIsomorphic();
  Test_IsKAnagrams();
  Test_IsPanagrams();
  Test_IsSubSequence();
  Test_ValidateIPAddress();

  Test_CountDeletionsToMakeStringPalindrome();
  Test_CheckIfEqualAfterRotations();

  Test_FindLongestPalindromeSubString();
  Test_LongestCommonSubSequence();
  Test_FindLongestPalindromeSubSequence();
  Test_FindLongestSubSequenceWordInDict();

  Test_LargeNumbersAddition();
  Test_LargeNumbersMultiplication();

  Test_ReplaceSubStrings();
  Test_LengthOfLongestPrefixSuffix();
  Test_SmallestSubstringContainingAllCharactersOfOtherString();
  Test_LongestSubstringOfUniqueCharacters();

  Test_StrStrKnuthMorrisPratt();
  Test_StrStrRabinKarp();

  Test_CountOps();
  Test_ShortestCommonSuperSequence();

  Test_AsciiToInt();
  Test_GenerateDistinctSubsequence();
  Test_CountInsertionsAtBeginToMakePalindrome();
  Test_CountInsertionsToMakePalindrome();
}

void Test_MatrixAlgorithms()
{
  std::cout << "\nTesting matirx Algorithms !!!\n";

  Test_SpiralTraversal_v1();
  Test_FindWords();
  Test_CountIslands();
  Test_FloodFillAlgorithm();
  Test_FindMaximumGridPaths();
  Test_FindShortestPathInBinaryMaze();
  Test_IslandsPerimeter();
}

void Test_LinkedListsAlgorithms()
{
  std::cout << "\nTesting LinkedList Algorithms !!!\n";
  Test_SingleLinkedListReverse();
  Test_DoubleLinkedListReverse();
  Test_SingleLinkedListRotate();
  Test_DeleteLastOccurrenceSLL();
  Test_MergeSLLsAlternatePositions();
  Test_DeleteNodeWithoutHeadPointer();
  Test_IsSLLPalindrome();
  Test_MergeKSortedSLLs_OneByOne();
  Test_MergeKSortedSLLs_MinHeap();
  Test_ReverseSubListSLL();
  Test_LoopProblemsSLL();
  Test_SLLIntersectionPoints();
}


void Test_TreesAlgorithms()
{
  std::cout << "\nTesting Trees Algorithms !!!\n";
/*
  Test_HeightOfBinarySearchTree();
  Test_CheckIfTreesAreIdentical();
  Test_MorrisInorderTraversal();
  Test_MirrorTree();
  Test_SymmetricTree();
  Test_GetDiameterOfTree();
  Test_ZigZagTraversal();
  Test_CheckIfTreesIsBalanced();
  Test_IsSumPropertyFollowed();
  Test_IsBST();
  Test_InorderSuccessor();
  Test_LargestValueNodesInEachLevel();
  Test_ReverseMorrisTraversal();
  Test_KthLargestElementInTree();
  Test_BSTCreationFromSortedArray();

  Test_IsSubTree();
  Test_IterativeTraversal_InPrePostOrder();
  Test_ReverseLevelOrder();
  Test_VerticalTraversal();
  Test_BoundaryTraversal();
  */
  Test_BinaryTreeCreationFromParentArray();
  Test_BinaryTreeCreationFromPreOrderAndInOrder();
  Test_BinaryTreeCreationFromPostOrderAndInOrder();
  Test_BinarySearchTreeCreationFromPreOrder();
  Test_CheckArrayIsPreOrderOfBSTree();
  Test_GetAncestorsOfNode();
  Test_GetLowestCommonAncestorOfNode();
  Test_GetMaxSumPath();
  Test_CloneBinaryTreeWithRandomPointer();
  Test_RemoveNodesOutsideRangeInBST();
  Test_FindPairOfNodesWithTargetSum();
  Test_IsSumTree();
  Test_GetMaxSumUsingNonAdjacentNodes();
  Test_TransformBSTToMaxSumTree();
}


void Test_Algorithms()
{
  std::cout << "\nTesting Algorithms !!!\n";

  //Test_ArrayAlgorithms();
  //Test_StringAlgorithms();
  //Test_MatrixAlgorithms();
  //Test_LinkedListsAlgorithms();
  Test_TreesAlgorithms();

  std::cout << "\n*******************************************\n";
}


int main()
{
  //Test_DataStructures();

  Test_Algorithms();
  return 0;
}


