/*
Minimum Number of Frogs Croaking

Given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can croak at the same time, so multiple “croak” are mixed. Return the minimum number of different frogs to finish all the croak in the given string.

A valid "croak" means a frog is printing 5 letters ‘c’, ’r’, ’o’, ’a’, ’k’ sequentially. The frogs have to print all five letters to finish a croak. If the given string is not a combination of valid "croak" return -1.

Example 1:

Input: croakOfFrogs = "croakcroak"
Output: 1 
Explanation: One frog yelling "croak" twice.
Example 2:

Input: croakOfFrogs = "crcoakroak"
Output: 2 
Explanation: The minimum number of frogs is two. 
The first frog could yell "crcoakroak".
The second frog could yell later "crcoakroak".
Example 3:

Input: croakOfFrogs = "croakcrook"
Output: -1
Explanation: The given string is an invalid combination of "croak" from different frogs.
Example 4:

Input: croakOfFrogs = "croakcroa"
Output: -1
 

Constraints:

1 <= croakOfFrogs.length <= 10^5
All characters in the string are: 'c', 'r', 'o', 'a' or 'k'.
*/

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int c=0,r=0,o=0,a=0,k=0,t=0;
        for(char l : croakOfFrogs){
            if(l=='c') {
                c++;
                // count only if the other croak starts after uttering 'k'
                t=max(t,c-k);
            }
            else if(l=='r') r++;
            else if(l=='o') o++;
            else if(l=='a') a++;
            else if(l=='k') k++;
            else return -1;
            // invalid as it is not printing sequentially
            if(c<r||r<o||o<a||a<k) return -1;
        }
        // if the given string is not a combination of valid "croak" return -1.
        return c==k?t:-1;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
