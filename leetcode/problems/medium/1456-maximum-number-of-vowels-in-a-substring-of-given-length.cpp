/*
Maximum Number of Vowels in a Substring of Given Length

Given a string s and an integer k.

Return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are (a, e, i, o, u).

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
Example 4:

Input: s = "rhythms", k = 4
Output: 0
Explanation: We can see that s doesn't have any vowel letters.
Example 5:

Input: s = "tryhard", k = 4
Output: 1
 

Constraints:

1 <= s.length <= 10^5
s consists of lowercase English letters.
1 <= k <= s.length
*/

class Solution {
public:
    int maxVowels(string s, int k) {
        int v[26]={0};
        int ans=0,cur=0;
        v['a'-'a']=1;
        v['e'-'a']=1;
        v['i'-'a']=1;
        v['o'-'a']=1;
        v['u'-'a']=1;
        // sliding window approach
        // similar to Solution2
        for(int i=0;i<s.size();i++){
            cur+=v[s[i]-'a'];
            // if it s out of boundary, undo the (i-k)th element 
            if(i>=k) cur-=v[s[i-k]-'a'];
            ans=max(ans,cur);
        }
        return ans;
    }
};


class Solution2 {
public:
    bool isVowel(char c){
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }
    int maxVowels(string s, int k) {
        int ans=0,sum=0,start=0;
        char c;
        for(int end=0;end<s.size();end++){
            c=s[end];
            if(isVowel(c)) sum++;
            if(end>=k-1){
                ans=max(sum,ans);
                c=s[start++];
                if(isVowel(c)) sum--;
            }
        }
        return ans;
    }
};


// TLE
// class Solution {
//     public:
//     int maxVowels(string s, int k) {
//         int cnt=0,ans=0,sz=s.size();
//         int i=0,j=k;
//         while(i<sz){
//             int tmp=i;
//             while(tmp<j){
//                 if(j>sz) j=sz;
//                 char c=s[tmp];
//                 if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
//                     cnt++;
//                 }
//                 tmp++;
//             }
//             ans=max(ans,cnt);
//             if(ans>k) return k;
//             cnt=0;
//             i++;
//             j++;
//         }
//         return ans;
//     }
// };