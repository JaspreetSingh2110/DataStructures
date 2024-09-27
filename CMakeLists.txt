cmake_minimum_required(VERSION 3.28)
project(DataStructure)

set(CMAKE_CXX_STANDARD 14)

add_executable(DataStructures main.cpp
        SortingTechniques/BubbleSort.cpp
        SortingTechniques/SortingTechniques.h
        Common/Utils.cpp
        Common/Utils.h
        SortingTechniques/SelectionSort.cpp
        SortingTechniques/InsertionSort.cpp
        SortingTechniques/CountingSort.cpp
        SortingTechniques/MergeSort.cpp
        SortingTechniques/ShellSort.cpp
        SortingTechniques/QuickSort.cpp
        LinearDS/Stack.cpp
        LinearDS/Stack.h
        LinearDS/Queue.cpp
        LinearDS/Queue.h
        LinearDS/SingleLinkedLists.cpp
        LinearDS/SingleLinkedLists.h
        LinearDS/DoubleLinkedList.cpp
        LinearDS/DoubleLinkedList.h
        SortingTechniques/BucketSort.cpp
        SortingTechniques/RadixSort.cpp
        NonLinearDS/Graphs/BreadthFirstSearch.cpp
        NonLinearDS/Graphs/Graphs.h
        NonLinearDS/Graphs/Graphs.cpp
        NonLinearDS/Graphs/DepthFirstSearch.cpp
        NonLinearDS/Graphs/BFS_ShortestPathAlgorithm.cpp
        NonLinearDS/Graphs/BFS_ShortestPathOnGrid.cpp
        NonLinearDS/Graphs/TopologicalSortAdjacencyList.cpp
        NonLinearDS/Graphs/Dijkstra_SingleSourceShortestPath.cpp
        NonLinearDS/Graphs/BellManFord_SSSP.cpp
)
