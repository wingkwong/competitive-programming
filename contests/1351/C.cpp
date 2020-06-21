/*
C. Skier
time limit per test1 second
memory limit per test: 256 megabytes
inputstandard input
outputstandard output
Skier rides on a snowy field. Its movements can be described by a string of characters 'S', 'N', 'W', 'E' (which correspond to 1 meter movement in the south, north, west or east direction respectively).

It is known that if he moves along a previously unvisited segment of a path (i.e. this segment of the path is visited the first time), then the time of such movement is 5 seconds. If he rolls along previously visited segment of a path (i.e., this segment of the path has been covered by his path before), then it takes 1 second.

Find the skier's time to roll all the path.

Input
The first line contains an integer 𝑡 (1≤𝑡≤104) — the number of test cases in the input. Then 𝑡 test cases follow.

Each set is given by one nonempty string of the characters 'S', 'N', 'W', 'E'. The length of the string does not exceed 105 characters.

The sum of the lengths of 𝑡 given lines over all test cases in the input does not exceed 105.

Output
For each test case, print the desired path time in seconds.

Example

input
5
NNN
NS
WWEN
WWEE
NWNWS

output
15
6
16
12
25

*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        // we need a map storing two pairs, 
        // one for the point Skier is going from, let's say p1
        // another for the point Skier is going to, let's say p2
        map<pair<pair<int,int>,pair<int,int>>,bool> m;
        int x=0,y=0,ans=0;
        
        for(char c : s){
            pair<int,int> p1,p2;
            p1=make_pair(x,y);
            // for four directions, store the coordinate (x,y) to a pair
            if(c=='S') {
                p2 = make_pair(x,--y);
            }else if(c=='N'){
                p2 = make_pair(x,++y);
            }else if(c=='W'){
                p2 = make_pair(--x,y);
            }else if(c=='E'){
                p2 = make_pair(++x,y);
            }
            // if this point is visited, add 1
            if(m[{p1,p2}]) ans++;
            else {
                // if not, add 5
                ans+=5;
                // set both from & to pair to true
                m[{p1,p2}]=m[{p2,p1}]=true;
            }
        }
        cout << ans << "\n";
    }
    return 0;
} 