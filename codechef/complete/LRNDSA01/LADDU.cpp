/*
DSA Learning Series - Contest 1 - Laddu   
https://www.codechef.com/LRNDSA01/problems/LADDU
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    int t; cin >> t;
    while(t--){
		int activities, points = 0;
        string origin;
        cin >> activities >> origin;
        while (activities--) {
            string kind;
            cin >> kind;
            if (kind == "CONTEST_WON") {
                int rank;
                cin >> rank;
                int bonus = max(0, 20 - rank);
                points += 300 + bonus;
            } else if (kind == "TOP_CONTRIBUTOR") {
                points += 300;
            } else if (kind == "BUG_FOUND") {
                int severity;
                cin >> severity;
                points += severity;
            } else if (kind == "CONTEST_HOSTED") {
                points += 50;
            }
        }
        cout << points / (origin == "INDIAN" ? 200 : 400) << endl;
	}
    return 0;
} 
