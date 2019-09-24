#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class RandGrid
{
  public:
    RandGrid(int rowDim, int colDim, double randProb);
    ~RandGrid();

  //  char** getGrid();

    char **myGrid;
    int rowDimension;
    int columnDimension;
    double randProbability;

  //  char updateGrid();
  //  char printGrid();



};
