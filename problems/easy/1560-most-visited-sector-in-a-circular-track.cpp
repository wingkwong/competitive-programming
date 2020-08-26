/*
Most Visited Sector in a Circular Track

Given an integer n and an integer array rounds. We have a circular track which consists of n sectors labeled from 1 to n. A marathon will be held on this track, the marathon consists of m rounds. The ith round starts at sector rounds[i - 1] and ends at sector rounds[i]. For example, round 1 starts at sector rounds[0] and ends at sector rounds[1]

Return an array of the most visited sectors sorted in ascending order.

Notice that you circulate the track in ascending order of sector numbers in the counter-clockwise direction (See the first example).

Input: n = 4, rounds = [1,3,1,2]
Output: [1,2]
Explanation: The marathon starts at sector 1. The order of the visited sectors is as follows:
1 --> 2 --> 3 (end of round 1) --> 4 --> 1 (end of round 2) --> 2 (end of round 3 and the marathon)
We can see that both sectors 1 and 2 are visited twice and they are the most visited sectors. Sectors 3 and 4 are visited only once.
Example 2:

Input: n = 2, rounds = [2,1,2,1,2,1,2,1,2]
Output: [2]
Example 3:

Input: n = 7, rounds = [1,3,5,7]
Output: [1,2,3,4,5,6,7]
 

Constraints:

2 <= n <= 100
1 <= m <= 100
rounds.length == m + 1
1 <= rounds[i] <= n
rounds[i] != rounds[i + 1] for 0 <= i < m
*/


class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> ans;
        // only first and last value matters
        int last = rounds.size()-1;
        // start <= end
        for(int i=rounds[0];i<=rounds[last];i++) ans.push_back(i);
        if(ans.size()>0) return ans;
        // start > end
        // [1..end] + [start..n]
        for(int i=1;i<=rounds[last];i++) ans.push_back(i);
        for(int i=rounds[0];i<=n;i++) ans.push_back(i);
        return ans;
    }
};

class Solution2 {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> ans, cnt(n+1,0);
        // brute force - simulation 
        int i,j;
        cnt[rounds[0]]=1;
        for(i=0;i<rounds.size()-1;i++) {
            int j=rounds[i]+1;
            while(true) {
                if(j==rounds[i+1]+1) break;
                if(j==n+1) j=1;
                cnt[j++]+=1;
            }
        }
        int mx=*max_element(cnt.begin(),cnt.end());
        for(int i=1;i<=n;i++) if(cnt[i]==mx) ans.push_back(i);
        return ans;
    }
};