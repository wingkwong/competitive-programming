/*
DI String Match

Given a string S that only contains "I" (increase) or "D" (decrease), let N = S.length.

Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:

If S[i] == "I", then A[i] < A[i+1]
If S[i] == "D", then A[i] > A[i+1]
 

Example 1:

Input: "IDID"
Output: [0,4,1,3,2]
Example 2:

Input: "III"
Output: [0,1,2,3]
Example 3:

Input: "DDI"
Output: [3,2,0,1]
 

Note:

1 <= S.length <= 10000
S only contains characters "I" or "D".
*/

class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> ans;
        int sz=(int)S.size();
        for(int i=0,l=0,h=sz;i<=sz;i++){
            if(S[i]=='I'){
                // add low pointer to ans
                ans.push_back(l);
                // increase low pointer
                l++;
            } else {
                // add high pointer to ans
                ans.push_back(h);
                // decrease high pointer
                h--;
            }
        }
        return ans;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();