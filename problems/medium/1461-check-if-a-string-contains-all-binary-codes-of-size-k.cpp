/*
Check If a String Contains All Binary Codes of Size K

Given a binary string s and an integer k.

Return True if all binary codes of length k is a substring of s. Otherwise, return False.

 

Example 1:

Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indicies 0, 1, 3 and 2 respectively.
Example 2:

Input: s = "00110", k = 2
Output: true
Example 3:

Input: s = "0110", k = 1
Output: true
Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 
Example 4:

Input: s = "0110", k = 2
Output: false
Explanation: The binary code "00" is of length 2 and doesn't exist in the array.
Example 5:

Input: s = "0000000001011100", k = 4
Output: false
*/


class Solution {
public:
    bool hasAllCodes(string s, int k) {
        // sliding window approach
        int n=(int)s.size();
        set<string> ss;
        for(int i=0;i<n-k+1;i++){
            // put all k-size substring to a set
            ss.insert(s.substr(i,k));
        }
        // and compare if it has the same as 2^k
        return ss.size()==pow(2,k);
    }
};

// TLE
// class Solution {
// public:
//     bool hasAllCodes(string s, int k) {
//         string zero(k,'0');
//         if(s.find(zero)==string::npos) return false;
//         for(int i=1;i<pow(2,k);i++){
//             string ss=bitset<20>(i).to_string().substr(20-k,k);
//             if(s.find(ss)==string::npos) return false;
//         }
//         return true;
//     }
// };