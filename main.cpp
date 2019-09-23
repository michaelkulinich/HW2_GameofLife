#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  cout << "------------- Welcome to the Game of Life -------------" << endl;
  cout << "Designed in the 1970s: A Simulation of Bacterial Life Cycle" << endl;
  cout << "\n" << endl;
  cout << "\n" << endl;
  cout << "Press a 'I' to import a map file or 'R' random assignment: ";
  char progStartChoice;
  cin >> progStartChoice;

  if (progStartChoice == 'I')
  {
    cout << "You chose " << progStartChoice << endl;
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
    cout << "Enter initial population density decimal (0,1]"
    double popDensity;
    cin >> popDensity;
    double randProbability;
    randProbability = (RAND_MAX - rand())/ static_cast<double>(RAND_MAX);


  }










  return 0;
}
