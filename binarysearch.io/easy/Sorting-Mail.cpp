/*
Sorting Mail
https://binarysearch.io/problems/Sorting-Mail

You are given a list of mailboxes. Each mailbox is a list of strings, where each string is either "junk", "personal", "work". Go through each mailbox in round robin order starting from the first one, filtering out junk, to form a single pile and return the pile.

Example 1
Input

mailboxes = [
    ["work", "personal"],
    ["junk", "personal", "junk"],
    ["work"]
]
Output

["work", "work", "personal", "personal"]
Explanation

In order and without filtering, we'd have work -> junk -> work -> personal -> personal -> junk, and since we filter out junk we get work -> work -> personal -> personal.
*/

#include "solution.hpp"
using namespace std;


class Solution {
    public:
    vector<string> solve(vector<vector<string>>& mailboxes) {
        vector<string> ans;
        int mx=-1;
        for(auto mailbox:mailboxes){
            mx=max(mx,(int)mailbox.size());
        }
        for(int i=0;i<mx;i++){
            for(auto mailbox: mailboxes){
                if(i<mailbox.size()&&mailbox[i]!="junk"){
                    ans.push_back(mailbox[i]);
                }
            }
        }
        return ans;
    }
};
