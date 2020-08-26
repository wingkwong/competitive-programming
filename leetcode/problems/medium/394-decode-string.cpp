/*
Decode String

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/

class Solution {
public:
    string decodeString(string s) {
        int loop=0;
        string ans="";
        for(;i<s.size();i++){
            char c = s[i];
            if(c=='['){
                i++;
                // get the substring 
                string ss = decodeString(s);
                // append the substring k times
                for(int k=0;k<loop;k++) ans+=ss;
                // reset loop
                loop=0;
            }
            // return substring
            else if(c==']') return ans;
            // case "100[leetcode]" 
            else if(isdigit(c)) loop=loop*10+c-'0'; 
            // normal case 
            else ans+=c;
        }
        return ans;
    }
private:
    int i=0;
};
static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();