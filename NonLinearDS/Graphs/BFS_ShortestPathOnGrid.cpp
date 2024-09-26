#include <iostream>
#include <ostream>
#include <queue>
//
// Created by Jaspreet Singh on 26/09/24.
//
class Grid {
  public:
  int rows = 5;
  int cols = 5;

  //Grid to traverse and reach end.
  char matrix[5][5] = {
    {'a', 'a', '#', 'a', '#'},
    {'a', 'a', 'a', 'a', 'a'},
    {'a', '#', 'a', '#', 'a'},
    {'a', '#', 'a', 'a', '#'},
    {'a', '#', 'E', 'a', '#'}
  };

  //Boolean matrix to represent if given cell is visited.
  bool visited[5][5] = {
  {false, false, false, false, false},
  {false, false, false, false, false},
  {false, false, false, false, false},
  {false, false, false, false, false},
  {false, false, false, false, false}
  };

  std::queue<int> rq; //Queue for rows indices
  std::queue<int> cq; //Queue for column indices

  //Traversal vectors
  int rVector[4] = {-1, 1, 0, 0};
  int cVector[4] = {0, 0, -1, 1};

  bool reachedEnd = false;
  int stepCount = 0;
  int nodesInNextLayer = 0;
  int nodesInThisLayer = 1; //1: because of starting node.

  //Reset local data members.
  void reset();
  void FindPath(int startRow, int startCol);
  void VisitNeighbours(int row, int col);
};

void Grid::reset()
{
  stepCount = 0;
  nodesInNextLayer = 0;
  nodesInThisLayer = 1;

  //Empty queues.
  while (!rq.empty()) {
    rq.pop();
  }
  while (!cq.empty()) {
    cq.pop();
  }

  //Reset visited matrix
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      visited[i][j] = false;
    }
  }
}


void Grid::VisitNeighbours(int row, int col)
{
 for (int i = 0; i < 4; i++) {
   int rr = row + rVector[i];
   int cc = col + cVector[i];

   //Bounds checks.
   if (rr < 0 || rr >= rows || cc < 0 || cc >= cols) {
     continue;
   }
   //Check if neighbor node is already visited.
   if (visited[rr][cc]) {
     continue;
   }
   //Check if invalid node (with character '#' representing rock)
   if (matrix[rr][cc] == '#') {
     continue;
   }

   //Add neighbor node to queue.
   visited[rr][cc] = true;
   rq.push(rr);
   cq.push(cc);
   nodesInNextLayer++;
 }
}


void Grid::FindPath(int startRow, int startCol)
{
  std::cout << "Start Location: (" << startRow << ", " << startCol << ")" << std::endl;
  rq.push(startRow);
  cq.push(startCol);
  visited[startRow][startCol] = true;

  //NOTE: What if start node itself is rock node?
  if (matrix[startRow][startCol] == '#') {
    std::cout << "Start index is obstacle..Cannot find path.." << std::endl;
    return;
  }

  while(!rq.empty()) { //Or we can even use !cq.empty()
    int row = rq.front();
    int col = cq.front();
    rq.pop();
    cq.pop();

    //Check if we have reached the location
    if (matrix[row][col] == 'E') {
      reachedEnd = true;
      break;
    }
    //Visit neighbours of current node
    VisitNeighbours(row, col);

    //Update stepCount
    nodesInThisLayer--;
    if (nodesInThisLayer == 0) {
      nodesInThisLayer = nodesInNextLayer;
      nodesInNextLayer = 0;
      stepCount++;
    }
  }

  if (reachedEnd) {
    std::cout << "Reached destination after step count: " << stepCount << std::endl;
    return;
  }
  std::cout << "No path found to reach destination!!!\n";
}


void Test_BFS_ShortestPathOnGrid()
{
  Grid g;
  g.FindPath(0, 0);
  g.reset();

  //Retest with different start location
  g.FindPath(1, 3);
  g.reset();
}