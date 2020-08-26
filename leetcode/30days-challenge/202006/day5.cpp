/*
Random Pick with Weight

Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

Note:

1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex will be called at most 10000 times.
Example 1:

Input: 
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]
Example 2:

Input: 
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output: [null,0,1,1,1,0]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array w. pickIndex has no arguments. Arguments are always wrapped with a list, even if there aren't any.
*/

class Solution {
public:
    Solution(vector<int>& w) {
        // given that w = {a,b,c,d}, 
        // pickIndex() will have 
        // - a/(a+b+c+d) chance of picking up a
        // - b/(a+b+c+d) chance of picking up b
        // - c/(a+b+c+d) chance of picking up c
        // - d/(a+b+c+d) chance of picking up d
        for(int i=1;i<w.size();i++) {
            // update the value - the boundary 
            // e.g.
            // w={2,4,1,5,3}
            // v would be {2,6,7,12,15}
            // i.e {1-2}, {3-6}, {7}, {8-12}, {13-15}
            // pickIndex is used to find out which group a randomly generated value should be in
            w[i]+=w[i-1];
        }
        v=w;
    }
    
    int pickIndex() {
        // v.back() is the overall weight
        int val = rand()%v.back();
        // val is generated randomly.
        // we can use binary search / upper_bound directly to find out the answer
        auto it = upper_bound(v.begin(), v.end(), val);
        // convert iterator to an index by substracting v.begin()
        return it - v.begin();
        // or one-liner
        // return upper_bound(v.begin(),v.end(),rand()%v.back())-v.begin();
    }
    
private:
    vector<int> v;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */