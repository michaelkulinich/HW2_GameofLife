#include "RandGrid.h"

using namespace std;



RandGrid::RandGrid(int rowDim, int colDim, double randProb)
{
  rowDimension = rowDim;
  columnDimension = colDim;
  randProbability = randProb;

  char **myGrid = new char*[rowDimension];
  for(int i = 0; i < rowDimension; ++i)
      myGrid[i] = new char[columnDimension];
      

}
  ~RandGrid();

  char** getGrid();
