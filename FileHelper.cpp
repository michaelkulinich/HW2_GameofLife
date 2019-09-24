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

  myGrid = new char*[rowDimension+2];
  for(int i = 0; i < rowDimension+2; ++i)
      myGrid[i] = new char[columnDimension+2];
    while (inFile >> line)
    {
      for (int i = 0; i<line.size(); ++i)
      {
        myGrid[lineCount+1][i+1] = line[i];
      }
      ++lineCount;

    }
inFile.close();
}

char** FileHelper::getGrid()
{
  return myGrid;
}

FileHelper::~FileHelper(){
  for(int i = 0; i < columnDimension; ++i) {
      delete [] myGrid[i];
  }
  delete [] myGrid;
}
