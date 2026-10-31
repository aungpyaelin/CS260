/******************************************************************************

The purpose of this program is to place a correct suffix (st, nd, rd, th)  
at the end of any positive integer.

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

string nth(int);

int main()
{
    int ordinal_num = 0;
    
    for (ordinal_num = 1; ordinal_num <= 123; ++ordinal_num) {
        cout << "The correct suffix for " << ordinal_num;
        cout << " is " << nth(ordinal_num);
        cout << " as in " << ordinal_num << nth(ordinal_num) << endl;
    }
    
    return 0;
}



string nth(int num) {
    
    int dec = num % 100,
        units = num % 10;
    string result;
    
    if (dec >= 11 && dec <= 13 )
        result = "th";
    else {
        switch (units) {
            case 1:
                result = "st";
                break;
            case 2:
                result = "nd";
                break;
            case 3:
                result = "rd";
                break;
            default:
                result = "th";
        }
    }
       
    return result;
}
