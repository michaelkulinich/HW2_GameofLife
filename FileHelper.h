#include <iostream>
#include <fstream>
using namespace std;

class FileHelper
{
  public:

    FileHelper(string fileName);
    ~FileHelper();

    void setGrid();
    //char** getGrid();
    ifstream inFile;
    string inputFile;
    char **myGrid;
    int rowDimension;
    int columnDimension;
    char** getGrid();

};
