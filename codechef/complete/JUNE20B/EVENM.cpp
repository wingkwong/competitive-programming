/*
CodeChef June Challenge 2020 Division 2 - Even Matrix
https://www.codechef.com/JUNE20B/problems/EVENM
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,n;
    cin >> t;
    
    while(t--){
    	cin >> n;
		// the pattern should be easy to observe 
    	if(n%2==0){
			// if it is even,
			// print in ascending order for every odd row
			// print in descending order for every even row
			// ---------------------------------------------
			// 1 2 3 4 5 6 7 8 9 10
			// 20 19 18 17 16 15 14 13 12 11
			// 21 22 23 24 25 26 27 28 29 30
			// 40 39 38 37 36 35 34 33 32 31
			// 41 42 43 44 45 46 47 48 49 50
			// 60 59 58 57 56 55 54 53 52 51
			// 61 62 63 64 65 66 67 68 69 70
			// 80 79 78 77 76 75 74 73 72 71
			// 81 82 83 84 85 86 87 88 89 90
			// 100 99 98 97 96 95 94 93 92 91
    		for(int i=1;i<=n;i++){
    			if(i%2==0){
					// even row
    				for(int j=0;j<n;j++) {
    					cout << i*n-j << " ";
					}
					
				} else {
					// odd row
					for(int j=1;j<=n;j++) {
						cout << (i-1)*n+j  << " ";
					}
				}
				cout << "\n";
			}
		} else {
			// if it is odd, just print all numbers in ascending order
			// ---------------------------------------------
			// 1 2 3 4 5 6 7 8 9 10 11
			// 12 13 14 15 16 17 18 19 20 21 22
			// 23 24 25 26 27 28 29 30 31 32 33
			// 34 35 36 37 38 39 40 41 42 43 44
			// 45 46 47 48 49 50 51 52 53 54 55
			// 56 57 58 59 60 61 62 63 64 65 66
			// 67 68 69 70 71 72 73 74 75 76 77
			// 78 79 80 81 82 83 84 85 86 87 88
			// 89 90 91 92 93 94 95 96 97 98 99
			// 100 101 102 103 104 105 106 107 108 109 110
			// 111 112 113 114 115 116 117 118 119 120 121
			for(int i=1;i<=n*n;i++){
				cout << i << " ";
				if(i%n==0) cout << "\n";
			}
		}
	}
    return 0;
} 
