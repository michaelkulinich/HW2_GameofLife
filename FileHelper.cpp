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
        rowDimension = int(line[0]);
        ++lineCount;
      }
      else if(lineCount == 1)
      {
        columnDimension = int(line[0]);
        ++lineCount;
      }
      else
      {
        lineCount = 0;
        break;
      }
  }

  char **myGrid = new char*[rowDimension];
  for(int i = 0; i < rowDimension; ++i)
      myGrid[i] = new char[columnDimension];
    while (inFile >> line)
    {
      for (int i = 0; i<line.size(); ++i)
      {
        myGrid[lineCount][i] = line[i];
      }
      ++lineCount;
    }
inFile.close();
}

void FileHelper::getGrid()
{
  for (int i = 0; i<rowDimension; ++i)
  {
    for (int j = 0; j<columnDimension; ++j)
    {
      cout << myGrid[i][j];

    }
    cout <<endl;

  }
}
