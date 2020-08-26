/*
Implement Trie (Prefix Tree)

Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.

*/

class TrieNode {
public: 
    bool isEndOfWord;
    TrieNode* children[26];
    
    TrieNode(){
        isEndOfWord=false;
        for(int i=0;i<26;i++) children[i]=NULL;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        int sz=(int)word.size();
        for(int i=0;i<sz;i++){
            int idx=word[i]-'a';
            if(!node->children[idx]) node->children[idx]=new TrieNode();
            node=node->children[idx];
        }
        node->isEndOfWord=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        int sz=(int)word.size();
        for(int i=0;i<sz;i++){
            int idx=word[i]-'a';
            if(!node->children[idx]) return false;
            node=node->children[idx];
        }
        return node->isEndOfWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        int sz=(int)prefix.size();
        for(int i=0;i<sz;i++){
            int idx=prefix[i]-'a';
            if(!node->children[idx]) return false;
            node=node->children[idx];
        }
        return true;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */