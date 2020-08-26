/*
STRHH - Half of the half
https://www.spoj.com/problems/STRHH/
*/

#include <iostream>
using namespace std;

int main() {
    int t;
    string s;
    cin >> t;
    while(t--){
    	cin >> s;
    	int sz=(int)s.size();
        // traverse i=0..sz/2
        // add 2 to i for every iteration
    	for(int i=0;i<sz/2;i+=2){
    		cout << s[i];
		}
		cout << "\n";
	}
	return 0;
}
