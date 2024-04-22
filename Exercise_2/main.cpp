#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
    string InputFileName = "./data.csv"; // Import file

    double S = 0.0;
    size_t n = 0;

    // Initialization of pointers for w and r
    double* w = nullptr;
    double* r = nullptr;

    /** Verify that the file is correctly opened,
     *  if this is true the function
     *  OutputResult will print results on
     *  the screen **/
    if (!ImportData(InputFileName, S, n, w, r))
    {
        cerr << "Import error!" << endl;
        return -1;
    }
    else
    {
        OutputResults(cout, S, n, w, r);
    }

    // Read and Open Results File
    string OutputFileName = "./result.txt";
    ofstream OutFile;
    OutFile.open(OutputFileName);

    /** Verify that the result file is correctly
     *  opened, if this is true write results on
     *  this file **/
    if (OutFile.fail())
    {
        cerr << "Unopened result file!" << endl;
    }
    else
    {
        OutputResults(OutFile, S, n, w, r);
    }

    // Close Results File
    OutFile.close();

    // Deallocate dynamic memory
    delete[] w;
    delete[] r;

    return 0;
}

