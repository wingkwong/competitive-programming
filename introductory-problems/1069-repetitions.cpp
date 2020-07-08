/*
Repetitions

You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence. This is a maximum-length substring containing only one type of character.

Input

The only input line contains a string of n characters.

Output

Print one integer: the length of the longest repetition.

Constraints
1≤n≤106
Example

Input:
ATTCGGGA

Output:
3
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    string s;
    cin >> s;
    int ans=1,cnt=1;
    for(int i=1;i<s.size();i++){
    	// if s[i] is same as previous character
    	// increase cnt
    	if(s[i]==s[i-1]) cnt++;
    	// if not, reset cnt
    	else cnt=1;
    	// take the max
    	ans=max(ans,cnt);
	}
	cout << ans << "\n";
    return 0;
} 
