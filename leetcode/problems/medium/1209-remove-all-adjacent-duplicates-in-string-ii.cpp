/*
Remove All Adjacent Duplicates in String II

Given a string s, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made.

It is guaranteed that the answer is unique.

Example 1:

Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.
Example 2:

Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
Example 3:

Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"
 

Constraints:

1 <= s.length <= 10^5
2 <= k <= 10^4
s only contains lower case English letters.
*/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> st;
        string ans;
        for(auto c : s) {
            if(st.empty() || st.back().first != c) st.push_back({c, 0});
            if(++st.back().second == k) st.pop_back();
        }
        for(auto x : st) ans += string(x.second, x.first);
        return ans;
    }
};

class Solution2 {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        string ans="";
        int sz=(int)s.size();
        for(int i=0;i<sz;){
            char c = s[i];
            if(st.empty()){
                // if the stack is empty, insert a pair <character,occurrence>
                st.push({c,1});
                ++i;
            }else if(c==st.top().first&&st.top().second<k){
                // if the top element is the current char and its occurrence is less than k
                auto p = st.top();
                // remove the existing one
                st.pop();
                // insert a new one with updated occurrence
                st.push({p.first, p.second+1});
                ++i;
            }else if(st.top().second==k){
                // if it reaches the max occurrence, remove the element
                // stay the same index to see if there is any further case
                st.pop();
            }else{
                // normal case. insert a pair <character,occurrence>
                st.push({c,1});
                ++i;
            }
        }
        
        // if the last input reaches k, pop it out
        if(!st.empty()&&st.top().second==k) st.pop();
        
        // constrcut a final answer
        while(!st.empty()){
            for(int i=0;i<st.top().second;i++){
                ans=st.top().first+ans;
            }
            st.pop();
        }
        return ans;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
