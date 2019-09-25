#include "Simulation.h"

using namespace std;

Simulation::Simulation(){
  //default constructor
}

Simulation::Simulation(char **grid1, char **grid2, int rowDim, int colDim){
   currentGrid = grid1;            //IS THIS SKETCH??
   nextGrid = grid2;
   rowDimension = rowDim;
   columnDimension = colDim;
}

void Simulation::run(){
  int mode;
  int countCells = 0;   //counts the number of X's around the cell
  cout << "What Kind of gamemode will you like to run?(type in the number)\n(1)Classic\n(2)Doughnut\n(3)Mirror\n";
  cin >> mode;
  if (mode == 1){
    //code for classic

//create a method call check!!!!! make this less repetitive
    for(int i = 1; i < rowDimension+1; ++i){
      for(int j = 1; j < columnDimension+1; ++j){


        for(int k = -1; k <= 1 ; k++){
          for(int m = -1; m <= 1; m++){
            if((i + k == i) && (j + m == j)){
              // do nothing becasue it is at the index in which we are checking neighbors FOR
            }
            else if(currentGrid[i+k][j+m] == 'X'){
              countCells++;
            }
          }
        }
        switch(countCells){
          case 0:
          case 1:
            nextGrid[i][j] = '-';
            countCells = 0;
            break;
          case 2:
            nextGrid[i][j] = currentGrid[i][j];
            countCells = 0;
            break;
          case 3:
            nextGrid[i][j] = 'X';
            countCells = 0;
            break;
          case 4:
          case 5:
          case 6:
          case 7:
          case 8:
            nextGrid[i][j] = '-';
            countCells = 0;
            break;
        }

      }
    }

  for(int i = 0; i < rowDimension+2; ++i){
    for(int j = 0; j < columnDimension+2; ++j){
        cout << currentGrid[i][j];
  }
  cout << endl;
}
cout <<"next Grid\n";
for(int i = 0; i < rowDimension+2; ++i){
  for(int j = 0; j < columnDimension+2; ++j){
    cout << nextGrid[i][j];
}
cout << endl;
}
}
  else if (mode == 2){
    //code for doughnut
  }
  else{
    //code for mirror
  }

}
//might not even need the methods
void Simulation::classic(){

}

void Simulation::doughnut(){

}
void Simulation::mirror(){

}

Simulation::~Simulation(){
  // for(int i = 0; i < rowDimension + 2; ++i) {
  //     delete [] currentGrid[i];
  //     delete [] nextGrid[i];
  // }
  // delete [] nextGrid;
  // delete [] currentGrid;
}
