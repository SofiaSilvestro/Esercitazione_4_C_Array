/* Declare functions */

#pragma once
#include "iostream"

using namespace std;

bool ImportData(const string &InputFilePath,
                double &S,
                size_t &n,
                double* &w,
                double* &r);

/** This function will open the input file to extract
 *  data to calculate the value of investment
 *  InputFilePath: path of the input file
 *  S: total sum to invest
 *  n: number of finacial investment and also number
 *  of elements in w and r
 *  w: fraction of the total sum for one asset
 *  r: rate of return
 *  Return: true if the file has been read,
 *  false otherwise **/


string ArrayToString(const size_t& n,
                      const double* const &vec);

/** This function allows to convert array to string
 *  operation necessary to write in the output file
 *  the value of w and r, declared with vec **/


double FinalValueV(const double &S,
                   const size_t &n,
                   const double* const &w,
                   const double* const &r);

/** This function will calculate the final value of
 *  the portfolio by using the formula
 *  V = Sum(i)((1 + ri) * S * wi, where 0 < i < n-1
 *  w and r are two arrays
 *  Return: the value of V **/


double CalculateRateOfReturn(const double &S,
                        const double &FinalValueV);

/** This function will calculate the rate of return
 *  of the portfolio by usign the formula
 *  RateOfRet = (V / S) - 1, where
 *  V = final value of the portfolio
 *  S = initial total sum
 *  Return: the value RateOfReturn **/


void OutputResults(ostream &output,
                   const double &S,
                   const size_t &n,
                   const double* const &w,
                   const double* const &r);

/** This function will write on the file output and
 *  on the screen the final result
 *  OutputFilePath: path of the output file
 *  S: sum to invest
 *  n: number of investments
 *  w: fraction of S for one asset
 *  r: rate of return
 *  Return: true if the output file is correctly
 *  opened and the results correctly writed,
 *  false otherwise **/

