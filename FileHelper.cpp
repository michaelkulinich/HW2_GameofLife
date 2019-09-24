#include "FileHelper.h"
#include <fstream>

using namespace std;

FileHelper::FileHelper(string fileName)
{
  inputFile = fileName;

}

void FileHelper::setGrid()
{
  string line;
  int lineCount = 0;

  inFile.open(inputFile);

  if(!inFile)
  {
    cout << "unable to open file: " << inputFile;
    exit(1);
  }

  while (inFile >> line)
  {
      if(lineCount == 0)
      {
        rowDimension = stoi(line); //????????????????????????????
        ++lineCount;
      }
      else
      {
        columnDimension = stoi(line);//???????????????????
        lineCount = 0;
        break;
      }

  }

  myGrid = new char*[rowDimension];
  for(int i = 0; i < rowDimension; ++i)
      myGrid[i] = new char[columnDimension];
    while (inFile >> line)
    {
      for (int i = 0; i<line.size(); ++i)
      {
        myGrid[lineCount][i] = line[i];
        cout << myGrid[lineCount][i];
      }
      ++lineCount;
      cout << endl;
    }
inFile.close();
}

void FileHelper::getGrid()
{
  cout << "check 1 inside of getGrid\n";
  cout << rowDimension << endl;
  cout << columnDimension << endl;

  for (int i = 0; i<rowDimension; ++i)
  {
    for (int j = 0; j<columnDimension; ++j)
    {
      cout << myGrid[i][j];

    }
    cout <<endl;

  }
}

FileHelper::~FileHelper(){
  for(int i = 0; i < columnDimension; ++i) {
      delete [] myGrid[i];
  }
  delete [] myGrid;
}
