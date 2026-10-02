/******************************************************************************
FunctionForLoop.cpp

Display the f(n) for each f in sin, cos, sqrt, ln, exp for each int n in [1, 5].
The output should appear as shown below.

       fn/(n)         1         2         3         4         5
       sin(n)  0.841471  0.909297   0.14112 -0.756802 -0.958924
       cos(n)  0.540302 -0.416147 -0.989992 -0.653644  0.283662
      sqrt(n)         1   1.41421   1.73205         2   2.23607
       log(n)         0  0.693147   1.09861   1.38629   1.60944
       exp(n)   2.71828   7.38906   20.0855   54.5982   148.413

*******************************************************************************/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

#define fn (double (*)(double))

using namespace std;

const int COL = 10; // column width of output table
const string FUNCTION_NAME[] {"fn/", "sin", "cos", "sqrt", "log", "exp"};

int main()
{
    int idx = 0;
  
    for (auto f : {fn abs, fn sin, fn cos, fn sqrt, fn log, fn exp})  {
        cout << setw(COL) << FUNCTION_NAME[idx++] << "(n)";
        for (int n = 1; n <= 5; ++n)
            cout << setw(COL) << f(n);
        cout << endl;
    }

    return 0;
}