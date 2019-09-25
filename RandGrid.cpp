#include "RandGrid.h"
#include <cmath>
#include <cstdlib>
using namespace std;



RandGrid::RandGrid(int rowDim, int colDim, double popDensity)
{
  int rowDimension = rowDim;
  int columnDimension = colDim;
  double randProbability;

//declaring the current grid
  myCurrentGrid = new char*[rowDimension+2];
  for(int i = 0; i < rowDimension+2; ++i)
      myCurrentGrid[i] = new char[columnDimension+2];

  //declaring the next grid
  myNextGrid = new char*[rowDimension+2];
  for(int i = 0; i < rowDimension+2; ++i)
      myNextGrid[i] = new char[columnDimension+2];



  for (int i = 1; i<rowDimension+1; ++i)
  {
    for (int j = 1; j<columnDimension+1; ++j)
    {
      randProbability = (RAND_MAX - rand())/ static_cast<double>(RAND_MAX);

      if (randProbability < popDensity)
      {
        myCurrentGrid[i][j] = 'X';
        myNextGrid[i][j] = 'X';
      }

      else
      {
        myCurrentGrid[i][j] = '-';
        myNextGrid[i][j] = '-';
      }

    }

  }

}

char** RandGrid::getCurrentGrid()
{

  return myCurrentGrid;
}
char** RandGrid::getNextGrid()
{
  return myNextGrid;
}


  RandGrid::~RandGrid(){
    for(int i = 0; i < rowDimension + 2; ++i) {
        delete [] myCurrentGrid[i];
        delete [] myNextGrid[i];
    }
    delete [] myNextGrid;
  }






  //char updateGrid();
  //char printGrid();





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
