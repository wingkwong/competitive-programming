/*
TEST - Life, the Universe, and Everything
https://www.spoj.com/problems/TEST/
*/

#include <iostream>
using namespace std;

int main() {
	int t;
    // keep reading an input
	while(1){
		cin >> t;
        // if "the Answer to Life, the Universe, and Everything" is found, break the loop 
		if(t==42) break;
        // if not, print the input
		cout << t << "\n";
	}
	return 0;
}