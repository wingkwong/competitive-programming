/*
Pyramid Transition Matrix

We are stacking blocks to form a pyramid. Each block has a color which is a one letter string.

We are allowed to place any color block C on top of two adjacent blocks of colors A and B, if and only if ABC is an allowed triple.

We start with a bottom row of bottom, represented as a single string. We also start with a list of allowed triples allowed. Each allowed triple is represented as a string of length 3.

Return true if we can build the pyramid all the way to the top, otherwise false.

Example 1:

Input: bottom = "BCD", allowed = ["BCG", "CDE", "GEA", "FFF"]
Output: true
Explanation:
We can stack the pyramid like this:
    A
   / \
  G   E
 / \ / \
B   C   D

We are allowed to place G on top of B and C because BCG is an allowed triple.  Similarly, we can place E on top of C and D, then A on top of G and E.
 

Example 2:

Input: bottom = "AABA", allowed = ["AAA", "AAB", "ABA", "ABB", "BAC"]
Output: false
Explanation:
We can't stack the pyramid to the top.
Note that there could be allowed triples (A, B, C) and (A, B, D) with C != D.
 

Note:

bottom will be a string with length in range [2, 8].
allowed will have length in range [0, 200].
Letters in all strings will be chosen from the set {'A', 'B', 'C', 'D', 'E', 'F', 'G'}.
*/

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // put allowed colors to a hashmap
        // where the first two characters as a key and the last character as a value
        for(string s:allowed) m[s.substr(0,2)].insert(s[2]);
        return dfs(bottom,"");
    }
private:
    unordered_map<string,unordered_set<char>> m;
    bool dfs(string cur, string above){
        int csz = (int)cur.size();
        int asz = (int)above.size();
        // A-G-E in Example 1 
        if(csz==2&&asz==1) return true;
        // G-E - B-C-D in Example 1
        // we have constructed the above layer, move to the next layer
        if(csz-1==asz) return dfs(above,"");
        // find out the key to get the possible color 
        string k = cur.substr(asz,2);
        // check it is allowed
        if(m.count(k)){
            // can be more than 1 color for the given key
            // e.g. key: BC
            // e.g. values: BCG, BCF
            for(char c:m[k]){
                // if it can be constructed, return ture
                if(dfs(cur,above+c)) return true;
                // if false, try out the next possible color
            }
        }
        return false;
    }
};
static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();