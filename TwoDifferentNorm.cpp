/******************************************************************************

CS260 Week 1 C++ Fluency 1

Returning pairs
Using structured binding

*******************************************************************************/
#include <cmath>
#include <iostream>
#include <tuple> // for std::tie
#include <utility> // for std::pair

using namespace std;

struct Point {
    double x = 0;
    double y = 0;
    
    pair<double, double> norm() const
        { return {abs(x) + abs(y), sqrt(x * x + y * y)}; }
};

int main()
{
    double 
        l1 = 0.0,
        l2 = 0.0;
    Point p{3,4};
    pair<double, double> norm;
    
    cout << "Welcome to the Vector Norm program\n\n";
    
    cout << "The norm of a vector can be measured two common ways: \n";
    cout << "First, L1, the Manhattan norm: " << p.norm().first << endl;
    cout << "Second, L2, the Euclidean norm (magnitude): " 
         << p.norm().second << endl << endl;
    
    tie(l1, l2) = p.norm();
    cout << "L1: " << l1 << endl;
    cout << "L2: " << l2 << endl << endl;

    norm = p.norm();
    cout << "L1: " << norm.first << endl;
    cout << "L2: " << norm.second << endl << endl;    
    
    return 0;
}