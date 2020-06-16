/*
CodeChef June Challenge 2020 Division 2 - The Tom and Jerry Game! 
https://www.codechef.com/JUNE20B/problems/EOEO
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    long long t,ts,tmp,cnt;
    cin >> t;
    while(t--){
    	cin >> ts;
		if(ts%2){
			// if ts is odd, Jerry can win as long as JS is even and 1<=JS<=TS
	 		cout << (ts-1)/2 << "\n";
		} else {
			// if ts is even, JS cannot be odd. Hence, JS has to be even as well.
			// however, if JS is even, their values get divided by 2 and the game proceeds with the next turn
			// if TS is 2^n, Jerry never wins
			if((ts&(ts-1))==0) {
				cout << 0 << "\n";
			}
			else {
				// when you divide a number by 2, and the number is not a power of 2, at some point the number will become odd
				// so we need to find out how many rounds to make TS odd
				// as long as TS is odd, JS is still even, Jerry wins. 
				cnt=1;
				tmp=ts;
				while(tmp){
					// if a number is even, the last digit must be 0. If it is odd, that must be 1. 
					// just a simple loop to count how many rounds to make TS odd
					// TS can be up to 10^18, using this method won't get TLE
					if(tmp&1) break;
					cnt++;
					tmp>>=1; // shift 1 to the right, i.e. tmp/2 
				}
				// remember to use floorl & powl instead of floor & pow for calculating long long type
				// I got WA at the beginning because I missed the letter 'l' 
				cout << fixed << setprecision(0) << floorl(ts/powl(2,cnt)) << "\n";
			}
		}
	}
    return 0;
} 


//3
//1000000000000000000 900000000000000000 900000000000000006

//3
//1000000000000000000
//999999999999999999
//999999999999999998

//1000000000000000000
//18446744073709551615
//	      50000000000
//999999999999999998
//499999999999999999
// 110111100000101101101011001110100111011001000000000000000000

// 110111100000101101101011001110100111011000111111111111111110
//1907348632812
//2147483647


//5
//10 100 150 500 1000
// 20 
// 10
// 5
//
//500		111110100
//250		011111010
//125
//
//1000	1111101000
//500		0111110100
//250		0011111010
//125

//100 24
//50  16
//25  8

// 10 4 8
// 5  2 4 
//
//ts js
//6  4
//3  2

//1000 64  32  16   72 80	96 8
//500  32  16  8	36 40	48 4
//250  16  8   4	18 20	24 2
//125  8   4   2	9  10	12 1
//

//1111101000 
//
//64: 1000000
//96: 1100000


//20 22 24 26 28 30
//10 11 12 13 14 15
//5     6     7
//      3  

//
//12 8
//6  4
//3  2
//2
//1

//10 4  8
//5  2  4
//2
//
//6 4
//3 2
//1
//
//96  64 32
//48  32 16 
//24  16 8
//12  8  4
//6   4  2
//3   2  1 
//1
//
//=5

//70 2
//359

// 72   16   
// 36   8
// 18   4
// 9    2

//10 4 8 
//5  2 4
//1

//70 12
//35 6
//   3

//36
//13

//1000   16  800
//500		8  400
//250		4   200
//125		2  100

//12
// 8
//--
//8 16 24 32 40 48 56 64 72 80 88 92 


//32:	1111111111100000	0000000000100000
//16: 1111111111110000	0000000000010000
//4:  1111111111111010	0000000000000100
//1011101001000011101101110100000000000
//0000000000010000
//1111111111110001
//0000000000010000
//
//100 		1100100
//50		110010
//25		11001
//
//0000000000011001
//1111111111100111
//------------------
//0000000000000001

//1000000000000000000