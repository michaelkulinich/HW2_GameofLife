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
  char **currentGrid;
  char **nextGrid;
  string fileName;


  if (progStartChoice == 'I')
  {
    cout << "You chose " << progStartChoice << endl;
    cout << "Insert File name: " << endl;
    cin >> fileName;

    FileHelper helper(fileName);
    helper.setGrid();  //take out the print statements
    currentGrid = helper.getCurrentGrid();
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
    RandGrid grid(rowDimension, columnDimension, popDensity);
    currentGrid = grid.getCurrentGrid();                         //is this sketch?? memory leak
    nextGrid = grid.getNextGrid();

    for (int i = 0; i<rowDimension+2; ++i)
    {
      for (int j = 0; j<columnDimension+2; ++j)
      {
        cout << currentGrid[i][j];
      }
      cout << endl;
    }
    cout << "next\n";
    for (int i = 0; i<rowDimension+2; ++i)
    {
      for (int j = 0; j<columnDimension+2; ++j)
      {
        cout << nextGrid[i][j];
      }
      cout << endl;
    }



  }

//the initial grids are ready so now we can start the simulation


//  int mode;
  //cout << "What kind of gamemode will you want"      ask in run







  return 0;
}
