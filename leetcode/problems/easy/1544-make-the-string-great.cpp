/*
Make The String Great

Given a string s of lower and upper case English letters.

A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:

0 <= i <= s.length - 2
s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.

Return the string after making it good. The answer is guaranteed to be unique under the given constraints.

Notice that an empty string is also good.
*/

class Solution {
public:
    string makeGood(string s) {
        // stack approach
        stack<char> st;
        for(char c:s){
            int skip=0;
            while(st.size()&& c!=st.top()&&tolower(c)==tolower(st.top())){
                st.pop();
                skip=1;
                break;
            }
            if(!skip) st.push(c);
        }
        string ans;
        while(st.size()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};

class Solution2 {
public:
    string makeGood(string s) {
        // brute force
        int sz = 0 ;
        while(sz!=s.size()){
            sz=s.size();
            for(int i=0;i+1<s.size();i++){
                if(s[i]!=s[i+1]&&tolower(s[i])==tolower(s[i+1])){
                    s=s.substr(0,i)+s.substr(i+2);
                }
            }
        }
        return s;
    }
};