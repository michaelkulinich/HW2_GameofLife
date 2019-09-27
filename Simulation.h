#include <iostream>
#include <fstream>

using namespace std;

class Simulation
{
  public:
    Simulation(); // constructor
    Simulation(char **&grid1, char **&grid2, int rowDim, int colDim); //overload constructor
    ~Simulation();
    void run();//runs the simulation and calls the gamemode methods
               //when it is needed to update the board
    void update(); // will handle updating the grid for classic gamemode
    void doughnut();
    void mirror();
    int rowDimension;
    int columnDimension;
    ofstream outFile;
    int countCells;
    int differenceCounter;

  private:
    char **currentGrid;
    char **nextGrid;




};
