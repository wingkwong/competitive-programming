/*
Racing Horses Problem Code: HORSES

Chef is very fond of horses. He enjoys watching them race. As expected, he has a stable full of horses. He, along with his friends, goes to his stable during the weekends to watch a few of these horses race. Chef wants his friends to enjoy the race and so he wants the race to be close. This can happen only if the horses are comparable on their skill i.e. the difference in their skills is less.

There are N horses in the stable. The skill of the horse i is represented by an integer S[i]. The Chef needs to pick 2 horses for the race such that the difference in their skills is minimum. This way, he would be able to host a very interesting race. Your task is to help him do this and report the minimum difference that is possible between 2 horses in the race.

Input:
First line of the input file contains a single integer T, the number of test cases.
Every test case starts with a line containing the integer N.
The next line contains N space separated integers where the i-th integer is S[i].
Output:
For each test case, output a single line containing the minimum difference that is possible.
Constraints:
1 ≤ T ≤ 10
2 ≤ N ≤ 5000
1 ≤ S[i] ≤ 1000000000

Example:
Input:
1
5
4 9 1 32 13

Output:
3
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,n,ss;
    cin >> t;
    while(t--){
        // sort the input and find the min diff
        cin >> n;
        vector<int> s(n);
        for(int i=0;i<n;i++) cin >> s[i];
        sort(s.begin(),s.end());
        int ans= s[1]-s[0];
        for(int i=2;i<n;i++) ans=min(ans,s[i]-s[i-1]);
        cout << ans << "\n";
    }
    return 0;
} 