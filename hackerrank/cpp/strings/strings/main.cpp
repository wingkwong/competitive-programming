#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    string a,b;
    cin >> a >> b;
    cout << a.size() << " " << b.size() << "\n";
    cout << a << b << "\n";

    char tmp = a[0];
    a[0] = b[0];
    b[0] = tmp;
    cout << a << " " << b;
    
    // for(int i=0;i<a.size();i++) {
    //     if(i==0) cout << b[i];
    //     else cout << a[i];
    // }
    // cout << " ";
    // for(int i=0;i<b.size();i++) {
    //     if(i==0) cout << a[i];
    //     else cout << b[i];
    // }
    cout << "\n";
    return 0;
}