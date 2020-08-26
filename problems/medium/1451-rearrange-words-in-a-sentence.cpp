/*
Rearrange Words in a Sentence

Given a sentence text (A sentence is a string of space-separated words) in the following format:

First letter is in upper case.
Each word in text are separated by a single space.
Your task is to rearrange the words in text such that all words are rearranged in an increasing order of their lengths. If two words have the same length, arrange them in their original order.

Return the new text following the format shown above.

 

Example 1:

Input: text = "Leetcode is cool"
Output: "Is cool leetcode"
Explanation: There are 3 words, "Leetcode" of length 8, "is" of length 2 and "cool" of length 4.
Output is ordered by length and the new first word starts with capital letter.
Example 2:

Input: text = "Keep calm and code on"
Output: "On and keep calm code"
Explanation: Output is ordered as follows:
"On" 2 letters.
"and" 3 letters.
"keep" 4 letters in case of tie order by position in original text.
"calm" 4 letters.
"code" 4 letters.
Example 3:

Input: text = "To be or not to be"
Output: "To be or to be not"
 

Constraints:

text begins with a capital letter and then contains lowercase letters and single space between words.
1 <= text.length <= 10^5
*/

class Solution {
public:
    bool compare(pair<int,string> &s1,pair<int,string> &s2) { 
        // If they have the same size, order by original order
        // else order by size
        return s1.second.size()==s2.second.size()? s1.first<s2.first: s1.second.size()<s2.second.size();
    } 
    
    string arrangeWords(string text) {
        // First letter is in upper case.
        // Convert it to lower case first.
        text=tolower(text[0]);
        stringstream ss(text);
        string word, ans="";
        vector<pair<int,string>> v;
        int i=0;
        // put each word with original order to a pair
        while(ss>>word){
            v.push_back({i,word});
            i++;
        }
        // sort with comparator
        sort(v.begin(),v.begin()+i,[this](pair<int,string>& a, pair<int,string>& b){return compare(a,b);});
        
        // build the result
        for(int i=0;i<v.size();i++){
            ans+=v[i].second; 
            if(i!=v.size()-1) ans+=" ";
        }
        // First letter needs to be in upper case.
        ans[0]=toupper(ans[0]);
        return ans;
    }
};
static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();