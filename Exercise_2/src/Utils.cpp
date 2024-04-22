/* Define functions */

#include "Utils.hpp"
#include "iostream"
#include "fstream"
#include "sstream"
#include "iomanip"

using namespace std;

bool ImportData(const string &InputFilePath,
                double &S,
                size_t &n,
                double* &w,
                double* &r)
{

    // Open File Data
    ifstream FileData; // Declare stream object
    FileData.open(InputFilePath); // open the file

    if (FileData.fail())
    {
        cerr << "Error! The input file doesn't exist."
             << endl;
        return false;
    }

    //
    string FLine;
    int j = 0;
    string name_col;
    string w_frac;
    string r_rate;

    while (!FileData.eof())
    {
        j = j + 1; // variable to count lines
        if (j == 1) // read the first line of the file
        {
            /* Read from the file "DataFile" the
             * first char 'S' and the symbol ';' */
            getline(FileData, name_col, ';');
            /* Read from the file "DataFile" the
             * string "1000" */
            getline(FileData, FLine);
            // Create a istringstrem object
            istringstream Stot;
            // Put the content of FLine in Stot
            Stot.str(FLine);
            Stot >> S; // Extract S from Stot
        }
        // Read the second line of the file
        else if (j == 2)
        {
            getline(FileData, name_col, ';');
            getline(FileData, FLine);
            istringstream n_asset;
            n_asset.str(FLine);
            n_asset >> n;
            /* Now the value n is known and it is
             * possible to initialize arrays w and r
             * with dynamic memory allocation */
            w = new double[n];
            r = new double[n];
        }
        else if (j == 3)
            /* The third line is ignored because
             * contains only name of arrays */
            getline(FileData, FLine);
        else /* From the fourth to the end of the file,
              * lines contain values of arrays w, r */
        {
            /* Read the first part of the line and
             * memorized the element of w in w_frac */
            getline(FileData, w_frac, ';');
            istringstream w_val;
            // The value in w_frac is moved in w_val
            w_val.str(w_frac);
            /* w_val is cleared to free space for the
             * next element of w */
            w_val.clear();
            /* The value in w_val is saved in w array
             * in position 0 */
            w_val >> w[j - 4];

            // Same procedure as w for r
            getline(FileData, r_rate);
            istringstream r_val;
            r_val.str(r_rate);
            r_val.clear();
            r_val >> r[j - 4];
        }
    }
    FileData.close(); // Close input file
    return true;
}


string ArrayToString(const size_t &n,
                      const double* const &vec)
{
    ostringstream toString;
    toString << "[ ";
    for (unsigned int j = 0; j < n; j++)
        toString << vec[j] << " ";
    toString << "]";
    return toString.str();
}


double FinalValueV(const double &S,
                   const size_t &n,
                   const double* const &w,
                   const double* const &r)
{
    double FinalValueV = 0.0;
    for (unsigned int i = 0; i < n; i++)
        FinalValueV += (1 + r[i]) * S * w[i];
    return FinalValueV;
}


double CalculateRateOfReturn(const double &S,
                             const double &FinalValueV)
{
    return ((FinalValueV / S) - 1);
}


void OutputResults(ostream &output,
                   const double &S,
                   const size_t &n,
                   const double* const &w,
                   const double* const &r)
{
    output << "S = " << fixed << setprecision(2) << S
           << ", n = " << n
           << "\nw = " << ArrayToString(n, w)
           << "\nr = " << ArrayToString(n, r) << "\n"
           << fixed << setprecision(4)
           << "Rate of return of the portfolio: "
           << CalculateRateOfReturn(S, FinalValueV(S, n, w, r))
           << "\nV: " << fixed << setprecision(2) << FinalValueV(S, n, w, r)
           << endl;
}

