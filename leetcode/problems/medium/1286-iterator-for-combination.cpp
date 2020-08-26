/*
Iterator for Combination

Design an Iterator class, which has:

A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
A function next() that returns the next combination of length combinationLength in lexicographical order.
A function hasNext() that returns True if and only if there exists a next combination.
 

Example:

CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false
 

Constraints:

1 <= combinationLength <= characters.length <= 15
There will be at most 10^4 function calls per test.
It's guaranteed that all calls of the function next are valid.
*/

class CombinationIterator {
public:
    string c;
    int n, mask;
    CombinationIterator(string characters, int combinationLength) {
        c = characters;
        n = combinationLength;
        mask = (1<<c.size())-1;
    }
    
    string next() {
        string res;
        int sz = c.size();
        while(mask&&__builtin_popcount(mask)!=n) mask--;
        for(int i=0;i<sz;i++){
            if(mask&(1<<(sz-i-1))){
                res+=c[i];
            }
        }
        mask--;
        return res;
    }
    
    bool hasNext() {
        while(mask&&__builtin_popcount(mask)!=n) mask--;
        return mask;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */