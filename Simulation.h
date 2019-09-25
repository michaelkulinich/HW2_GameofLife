#include <iostream>

using namespace std;

class Simulation
{
  public:
    Simulation(); // constructor
    Simulation(char **grid1, char **grid2); //overload constructor
    ~Simulation();
  private:
    char **currentGrid;
    char **nextGrid;


    void run();//runs the simulation and calls the gamemode methods
               //when it is needed to update the board
    classic(); // will handle updating the grid for classic gamemode
    doughnut();
    mirror();


};
