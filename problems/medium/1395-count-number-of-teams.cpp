/*
Count Number of Teams

There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if:  (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

 

Example 1:

Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 
Example 2:

Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.
Example 3:

Input: rating = [1,2,3,4]
Output: 4
 

Constraints:

n == rating.length
1 <= n <= 200
1 <= rating[i] <= 10^5
*/


class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size(),ans=0;
        // for each number, find out how many numbers are smaller & greater than it on both side
        for(int j=0;j<n;j++){
            // ls: left smaller
            // lg: left greater
            // rs; right smaller
            // rg: right greater
            int ls=0,lg=0,rs=0,rg=0;
            // i..j
            for(int i=0;i<j;i++){
                if(rating[i]<rating[j]) ls++; // the number on the left is smaller than it
                else lg++; // the number on the left is greater than it 
            }
            // j..k
            for(int k=j+1;k<n;k++){
                if(rating[k]<rating[j]) rs++; // the number on the right is smaller than it
                else rg++; // the number on the right is greater than it 
            }
            // Example: [2,5,3,4,1]
            // take rating[2]=3 as an example
            // for rating[i] < rating[j] < rating[k], there is 1 number smaller than 3 from left side and 1 number greater than 3 
            // i.e. 2 < 3 < 4
            // for rating[i] > rating[j] > rating[k], there are 1 number smaller than 3 and 1 number greater than 3  
            // i.e. 5 > 3 > 1
            // there would be  1*1 + 1*1 = 2 tripplets in total for the number 3 being rating[j]
            ans+=ls*rg+lg*rs;
        }
        return ans;
    }
};

class Solution2 {
public:
    int numTeams(vector<int>& rating) {
        // n is just 200. brute force approach should work
        int n = rating.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                   if(
                    (rating[i]>rating[j]&&rating[j]>rating[k]) ||
                    (rating[i]<rating[j]&&rating[j]<rating[k])
                   ) {
                       ans++;
                   }
                }
            }
        }
        return ans;
    }
};