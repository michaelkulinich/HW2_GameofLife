#include <"Simulation.h">

using namespace std;

Simulation::Simulation(){
  //default constructor
}

Simulation::Simulation(char **grid1, char **grid2){
  currentGrid = grid1;            //IS THIS SKETCH??
  nextGrid = grid2;
}

Simulation::run(){
  int mode;
  cout << "What Kind of gamemode will you like to run?(type in the number)\n(1)Classic\n(2)Doughnut\n(3)Mirror\n";
  cin >> mode;
  if (mode == 1){
    //code for classic
  }
  else if (mode == 2){
    //code for doughnut
  }
  else{
    //code for mirror
  }

}
//might not even need the methods
Simulation::classic(){

}

Simulation::doughnut(){

}
Simulation::mirror(){

}
