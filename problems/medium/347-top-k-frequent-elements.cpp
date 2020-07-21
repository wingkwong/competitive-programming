/*
Top K Frequent Elements

Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> ans;
        
        // [1,1,1,2,2,3], k = 2
        // 1:3
        // 2:2
        // 3:1
        unordered_map<int, int> m;
        for(int n:nums) m[n]++;
        
        priority_queue<pair<int, int>> q;
        for(auto &v : m){
            // 3,1
            // 2,2
            // 1,3
            q.push({v.second, v.first});
            if(q.size() > m.size()-k){
                ans.push_back(q.top().second);
                q.pop();
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int n:nums) m[n]++;
        vector<pair<int,int>> v;
        for(auto x:m) v.push_back({x.first,x.second});
        sort(v.begin(),v.end(),[](pair<int,int> a, pair<int,int> b){
            return a.second > b.second;
        });
        vector<int> ans;
        for(int i=0;i<k;i++) ans.emplace_back(v[i].first);
        return ans;
    }
};