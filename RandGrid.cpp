#include "RandGrid.h"

using namespace std;



RandGrid::RandGrid(int rowDim, int colDim, double popDensity)
{
  int rowDimension = rowDim;
  int columnDimension = colDim;
  double randProbability;

  char **myGrid = new char*[rowDimension];
  for(int i = 0; i < rowDimension; ++i)
      myGrid[i] = new char[columnDimension];

  for (int i = 0; i<rowDimension; ++i)
  {
    for (int j = 0; j<columnDimension; ++j)
    {
      randProbability = (RAND_MAX - rand())/ static_cast<double>(RAND_MAX);

      if (randProbability < popDensity)
      {
        myGrid[i][j] = 'X';
      }

      else
      {
        myGrid[i][j] = '-';
      }
    }
  }
  //~RandGrid();

  /*char** getGrid();
  {
    // returns myGrid
  }
*/
  //char updateGrid();
  //char printGrid();
}
