/*
AtCoder Beginner Contest 170 - D - Not Divisible
https://atcoder.jp/contests/abc170/tasks/abc170_d
*/

#include <bits/stdc++.h>
using namespace std;

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
unordered_set<int> s;

int helper(vector<int>& arr, int n, int mx) {
    unordered_set<int> res;
    for(int i=0;i<n;i++) { 
        if(arr[i]!=0) { 
            // check the factor of arr[i]
            for(int j=arr[i]*2;j<=mx;j+=arr[i]) { 
                if(s.find(j)!=s.end()) res.insert(j);
            } 
        } 
    } 
    unordered_map<int,int> mp;
    // find the frequency for non-distinct elements
    for(int i=0;i<n;i++) mp[arr[i]]++;
    vector<int> ans;
    for(auto it=mp.begin();it!=mp.end();it++) { 
        if(it->second>=2) { 
            // not divisble by any other number
            if(res.find(it->first) == res.end()) { 
                int val=it->second; 
                while(val--) ans.push_back(it->first);
            } 
        } 
        // frequency > 1 & it is divisible 
        if(res.find(it->first)!=res.end()) { 
            int val=it->second;
            while (val--) ans.push_back(it->first);
        } 
    } 
    return ans.size();
}

int main()  
{ 
    FAST_INP;
    int t;
    cin >> t;
    vector<int> arr(t);
    int mx=INT_MIN;
    // read input, insert to unordered set, find out the max
    for(int i=0;i<t;i++) {
        cin >> arr[i];
        s.insert(arr[i]);
        mx=max(mx,arr[i]);
    }
    cout << ( t-helper(arr,t,mx) ) << "\n";
    return 0;
} 
