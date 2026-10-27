#include <iostream>
#include "bag.h"

using namespace std;

int main(){
	Bag bag, bag2;
	
	bag.insert(A, 2);
	bag.insert(B, 3);

	bag2.insert(A, 2);
	bag2.insert(C, 3);

	(bag+bag2).display();

	return 0;
}
