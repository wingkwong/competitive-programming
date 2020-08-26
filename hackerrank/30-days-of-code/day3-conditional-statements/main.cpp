#include <bits/stdc++.h>

using namespace std;



int main()
{
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if((N>=2&&N<=5&&N%2==0) || (N>20&&N%2==0)) cout << "Not Weird";
    else cout << "Weird"; 

    return 0;
}
