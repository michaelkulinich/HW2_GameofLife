#include "Simulation.h"
#include <stdio.h>
#include <stdlib.h>


using namespace std;
//should it print the 2nd geneation that is the same?
Simulation::Simulation()
{
  //default constructor
}
Simulation::Simulation(char **&grid1, char **&grid2, int rowDim, int colDim)
{
   currentGrid = grid1;            //IS THIS SKETCH??
   nextGrid = grid2;
   rowDimension = rowDim;
   columnDimension = colDim;
}

void Simulation::run()
{
  int mode;
  int gen = 1;
  differenceCounter = 0; //if the generations are the same, program should end;
  countCells = 0;   //counts the number of X's around the cell
  //userFile.open("MichaelKulinich.out");
  cout << "What kind of gamemode will you like to run?" << endl;
  cout << "(type in the number)\n(1) Classic\n(2) Doughnut\n(3) Mirror\n" << endl;
  cin >> mode;

  cout << "Would you like a brief pause in between generations? (Y/N)" << endl;
  cin >> briefPause;
  if (toupper(briefPause) == 'Y')
  {
    briefPauseBool = true;
  //  enterPauseBool = false;
  }

  else
  {
    briefPauseBool = false;
  //  enterPauseBool = false;
  }
  if(toupper(briefPause) != 'Y')
  {
    cout << "Would you like to press 'Enter' key to display generations? (Y/N)" << endl;
    cin >> enterPause;
    if (toupper(enterPause) == 'Y')
    {
    //  briefPauseBool = false;
      enterPauseBool = true;
    }

    else
    {
    //  briefPauseBool = false;
      enterPauseBool = false;
    }

    if(toupper(enterPause) != 'Y')
    {
      cout << "Would you like to press output everything to a file? (Y/N)" << endl;
      cin >> outToFile;
      cout << outToFile << endl;
      if (toupper(outToFile) == 'Y')
      {
        cout << "Enter the file name, no spaces: " << endl;
        cin >> userFileName;
        userFile.open(userFileName);
      }
      else
      {
        cout << "Ddfdf";
      }
    }
  }



//CLASSIC MODE
  if (mode == 1)
  {
    cout << 0 << endl;
    userFile << 0 << endl;
    for(int i = 1; i < rowDimension+2; ++i)
      {
        for(int j = 1; j < columnDimension+2; ++j)
        {
            cout << currentGrid[i][j];
            userFile << currentGrid[i][j];
        }
      cout << endl;
      userFile << endl;
    }
    while(true)
    {
      differenceCounter = 0; //set the counter to 0 before each update generation
    //create a method call check!!!!! make this less repetitive
      conductPause();
      update();
      if(differenceCounter == 0)
      {
        cout << "THE PROGRAM STOPS BECAUSE THE BOARD WILL NO LONGER CHANGE" << endl;
        cout << "Press 'enter' to exit program" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "Exiting..\n";
        break;
      }
      cout << gen << endl;
      userFile << gen << endl;
      for(int i = 1; i < rowDimension+1; ++i){
        for(int j = 1; j < columnDimension+1; ++j){
          cout << nextGrid[i][j];
          userFile << nextGrid[i][j];
        }
      cout << endl;
      userFile << endl;
      }


    // cout << "new current grid"<< endl;;
    // //copy the next grid into the current grid, the boundary will always stay -
      for(int i = 0; i < rowDimension+2; ++i)
      {
        for(int j = 0; j < columnDimension+2; ++j)
        {
          currentGrid[i][j] = nextGrid[i][j];
        }
      }
      gen++;
    }
  }









  else if (mode == 2)
  {
    //code for doughnut

    //set the corner boundaries
    //the corner boundaries are equal to the actual board boundaries
    currentGrid[0][columnDimension+1] = currentGrid[rowDimension][1];
    currentGrid[0][0] = currentGrid[rowDimension][columnDimension];
    currentGrid[rowDimension+1][0] = currentGrid[1][columnDimension];
    currentGrid[rowDimension+1][columnDimension+1] = currentGrid[1][1];



      //set the boundary for row 0 and last
    for(int i = 1; i < columnDimension+1;++i)
    {
      currentGrid[0][i] = currentGrid[rowDimension][i];
      currentGrid[rowDimension+1][i] = currentGrid[1][i];
    }

    //set boudary for column
    for(int i = 1; i < rowDimension+1;++i)
    {
      currentGrid[i][0] = currentGrid[i][columnDimension];
      currentGrid[i][columnDimension+1] = currentGrid[i][1];
    }

    cout << 0 << endl;
    userFile << 0 << endl;
      for(int i = 1; i < rowDimension+1; ++i)
      {
        for(int j = 1; j < columnDimension+1; ++j)
        {
            cout << currentGrid[i][j];
            userFile << currentGrid[i][j];
        }
      cout << endl;
      userFile << endl;
    }

    while(gen < 100)
    {
      differenceCounter = 0;
    //create a method call check!!!!! make this less repetitive
        conductPause();
        update();
      if(differenceCounter == 0)
      {
        cout << "THE PROGRAM STOPS BECAUSE THE BOARD WILL NO LONGER CHANGE" << endl;
        cout << "Press 'enter' to exit program...\n" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "Exiting..\n";
        break;
      }

      cout << "Generation Number: " << gen << endl;
      userFile << "Generation Number: " << gen << endl;
      for(int i = 1; i < rowDimension+1; ++i){
        for(int j = 1; j < columnDimension+1; ++j)
        {
          cout << nextGrid[i][j];
          userFile << nextGrid[i][j];
        }
      cout << endl;
      userFile << endl;
      }



    // cout << "new current grid"<< endl;;
    // //copy the next grid into the current grid, the boundary will always stay -
      for(int i = 0; i < rowDimension+2; ++i)
      {
        for(int j = 0; j < columnDimension+2; ++j)
        {
          currentGrid[i][j] = nextGrid[i][j];
        }
      }

      //set the corner boundaries
      currentGrid[0][columnDimension+1] = currentGrid[rowDimension][1];
      currentGrid[0][0] = currentGrid[rowDimension][columnDimension]; //  DOUBLE CHECK IF THE LOGIC HERE IS CURRECT. IF this is the right place to set boundaries
      currentGrid[rowDimension+1][0] = currentGrid[1][columnDimension];
      currentGrid[rowDimension+1][columnDimension+1] = currentGrid[1][1];

      gen++;
    }
  }
  else
  {
    //code for mirror
    currentGrid[0][columnDimension+1] = currentGrid[1][columnDimension];
    currentGrid[0][0] = currentGrid[1][1];
    currentGrid[rowDimension+1][0] = currentGrid[rowDimension][1];
    currentGrid[rowDimension+1][columnDimension+1] = currentGrid[rowDimension][columnDimension];

    //set boudary for column
    for(int i = 1; i < rowDimension+1;++i)
    {
      currentGrid[i][0] = currentGrid[i][1];
      currentGrid[i][columnDimension+1] = currentGrid[i][columnDimension];
    }
    for(int i = 1; i < columnDimension+1;++i)
    {
      currentGrid[0][i] = currentGrid[1][i];
      currentGrid[rowDimension+1][i] = currentGrid[rowDimension][i];
    }

    cout << 0 << endl;
    userFile << 0 << endl;
      for(int i = 1; i < rowDimension+1; ++i)
      {
        for(int j = 1; j < columnDimension+1; ++j)
        {
            cout << currentGrid[i][j];
            userFile << currentGrid[i][j];
        }
      cout << endl;
      userFile << endl;
    }

    while(true)
    {
      differenceCounter = 0;// set counter to 0 before every generation update
        conductPause();
        update();
      if(differenceCounter == 0)
      {
        cout << "THE PROGRAM STOPS BECAUSE NO THE BOARD WILL NO LONGER CHANGE" << endl;
        cout << "Press 'enter' to exit program" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "Exiting..\n";
        break;
      }


    cout << gen << endl;
    userFile << gen << endl;
    for(int i = 1; i < rowDimension+1; ++i)
    {
      for(int j = 1; j < columnDimension+1; ++j)
      {
        cout << nextGrid[i][j];
        userFile << nextGrid[i][j];
      }
    cout << endl;
    userFile << endl;
    }

    // //copy the next grid into the current grid, the boundary will always stay -
      for(int i = 0; i < rowDimension+2; ++i)
      {
        for(int j = 0; j < columnDimension+2; ++j)
        {
          currentGrid[i][j] = nextGrid[i][j];
        }
      }

      //code for mirror
      currentGrid[0][columnDimension+1] = currentGrid[1][columnDimension];
      currentGrid[0][0] = currentGrid[1][1];
      currentGrid[rowDimension+1][0] = currentGrid[rowDimension][1];
      currentGrid[rowDimension+1][columnDimension+1] = currentGrid[rowDimension][columnDimension];
      gen++;
    }
    }
    userFile.close();
  }

//might not even need the methods
void Simulation::update(){
  //iterate through the actual board, not the boundaries
  for(int i = 1; i < rowDimension+1; ++i){
    for(int j = 1; j < columnDimension+1; ++j){

      //this iterates the 8 cells around each cell were inspecting
      for(int k = -1; k <= 1 ; k++){
        for(int m = -1; m <= 1; m++){
          if((i + k == i) && (j + m == j)){
            // do nothing becasue it is at the index in which we are checking neighbors FOR
          }
          //count the number of X around each cell
          else if(currentGrid[i+k][j+m] == 'X'){
            countCells++;
          }
        }
      }
      //depending on how many cells are X's, determines if the cell lives or dies
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
        default:
          cout << ":(";
      }
    }
  }
//check if the generations are the same, if differenceCounter = 0, the program will end
for(int i = 1; i < rowDimension+1; ++i){
  for(int j = 1; j < columnDimension+1; ++j){
    if( !(currentGrid[i][j] == nextGrid[i][j])){
      differenceCounter++;
    }
  }
}

}

void Simulation::doughnut(){

}
void Simulation::mirror(){

}

void Simulation::conductPause()
{
  if(briefPauseBool)
  {
    this_thread::sleep_for(chrono::seconds(1));
  }

  else if(enterPauseBool)
  {
    cout << "Press Enter to Continue...\n" << endl;
    getchar();
  }



}

Simulation::~Simulation(){
  for(int i = 0; i < rowDimension+2; ++i) {
      delete [] currentGrid[i];
      delete [] nextGrid[i];
  }
  delete [] currentGrid;
  delete [] nextGrid;

}
