#include <iostream>
#include <cmath>
#include <cstdlib>
#include "FileHelper.h"
#include "RandGrid.h"



using namespace std;

int main(int argc, char const *argv[]) {


  cout << "------------- Welcome to the Game of Life -------------" << endl;
  cout << "Designed in the 1970s: A Simulation of Bacterial Life Cycle" << endl;
  cout << "\n" << endl;
  cout << "\n" << endl;
  cout << "Press a 'I' to import a map file or 'R' random assignment: ";
  char progStartChoice;
  cin >> progStartChoice;
  char **ourGrid;
  string fileName;

  if (progStartChoice == 'I')
  {
    cout << "You chose " << progStartChoice << endl;
    cout << "Insert File name: " << endl;
    cin >> fileName;
    cout << "check 1" << endl;

    FileHelper helper(fileName);
    cout << "check 2" << endl;

    helper.setGrid();
    cout << "check 3" << endl;

    helper.getGrid();
    cout << "check 4" << endl;

    cout << "Importing map file..." << endl;



  }

  else if (progStartChoice == 'R')
  {
    cout << "You chose " << progStartChoice << endl;
    cout << "Enter Row Dimension" << endl;
    int rowDimension;
    cin >> rowDimension;
    cout << "Enter Column Dimension" << endl;
    int columnDimension;
    cin >> columnDimension;
    cout << "Enter initial population density decimal (0,1]";
    double popDensity;
    cin >> popDensity;
  //  RandGrid grid(rowDimension, columnDimension, popDensity);
    //ourGrid = grid.getGrid();



  }








  return 0;
}
