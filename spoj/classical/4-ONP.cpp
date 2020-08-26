/*
ONP - Transform the Expression
https://www.spoj.com/problems/ONP/
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 

int main()  
{ 
    FAST_INP;
    int t;
    string s;
    cin >> t;
    while(t--){
    	// simple stack approach
    	cin >> s;
    	stack<char> ops;
    	string ans="";
    	// traverse each character
    	for(auto c:s){
    		if(isalpha(c)){
    		// if we see an alphabet, add it to ans 
    			ans+=c;
			} else if(c=='(') {
				// do nothing if it is '('
				continue;
			} else if(c==')') {
				// if it is ')', we need to get one operator from the stack 
				// and pop it 
				if(!ops.empty()) {
	    			ans+=ops.top();
	    			ops.pop();
				}
			} else {
				// if it is one of the operators, push it to the stack
				ops.push(c);
			}
		}
		// print the final answer
		cout << ans << "\n";
    }
    return 0;
}

//Input:
//3
//(a+(b*c))
//((a+b)*(z+x))
//((a+t)*((b+(a+c))^(c+d)))
//
//Output:
//abc*+
//ab+zx+*
//at+bac++cd+^*
