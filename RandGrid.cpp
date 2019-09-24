#include "RandGrid.h"
#include <cmath>
#include <cstdlib>
using namespace std;



RandGrid::RandGrid(int rowDim, int colDim, double popDensity)
{
  int rowDimension = rowDim;
  int columnDimension = colDim;
  double randProbability;

//  cout << "check 1\n";
  myGrid = new char*[rowDimension+2];
  for(int i = 0; i < rowDimension+2; ++i)
      myGrid[i] = new char[columnDimension+2];

    //  cout << "check 2\n";

  for (int i = 1; i<rowDimension+1; ++i)
  {
    for (int j = 1; j<columnDimension+1; ++j)
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

// test to show there is a box around our array


// for (int i = 0; i < columnDimension+2; ++i)
// {
//   myGrid[rowDimension+1][i] = 'X';
//
// }
//
// for (int i = 0; i<rowDimension+2; ++i)
// {
//   for (int j = 0; j<columnDimension+2; ++j)
//   {
//     cout << myGrid[i][j];
//   }
//   cout << endl;
// }

//  cout << "check 3\n";

}
  RandGrid::~RandGrid(){
    for(int i = 0; i < columnDimension; ++i) {
        delete [] myGrid[i];
    }
    delete [] myGrid;
  }

  char** getGrid();
  {
    // returns myGrid
  }

  //char updateGrid();
  //char printGrid();
