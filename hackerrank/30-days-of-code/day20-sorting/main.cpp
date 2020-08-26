#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
    	cin >> a[a_i];
    }
    // Write Your Code Here
    bool swapped;
    int swaps=0;
    for (int i=0;i<n;i++){
        swapped=false;
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]) {
                swap(a[j],a[j+1]);
                swapped=true;
                swaps++;
            }
        }
        if(!swapped) break;
    }

    cout << "Array is sorted in " << swaps << " swaps." << "\n";
    cout << "First Element: " << a[0] << "\n";
    cout << "Last Element: " << a[n-1] << "\n";

    return 0;
}