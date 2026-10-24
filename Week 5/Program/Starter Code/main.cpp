#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack s;
    
    s.push(5);
    s.push(15);
    s.push(25);
    
    cout << "Top item: " << s.topItem()->data << endl; // 25
    
    s.pop();
    
    cout << "Top item: " << s.topItem()->data << endl; // 15

    while (!s.empty()) {
        cout << "Popping: " << s.topItem()->data << endl;
        s.pop();
    }

    cout << "Stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    return 0;
}
