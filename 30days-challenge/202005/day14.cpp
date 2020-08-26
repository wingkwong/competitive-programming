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
    // Initialize your data structure here.
    bool is_word;
    TrieNode *children[26];
    
    TrieNode() {
        is_word = false;
        
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        int word_len = word.length();
        int k = 0;
        TrieNode *cur = root;
        
        for (int i = 0; i < word_len; i++)
        {
            k = word[i] - 'a';
            
            if (cur->children[k] == NULL)
            {
                cur->children[k] = new TrieNode();
            }
            
            cur = cur->children[k];
        }
        
        cur->is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        int word_len = word.length();
        int k = 0;
        TrieNode *cur = root;
        
        for (int i = 0; i < word_len; i++)
        {
            k = word[i] - 'a';
            cur = cur->children[k];
            
            if (cur == NULL)
                return false;
        }
        
        return cur->is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int word_len = prefix.length();
        int k = 0;
        TrieNode *cur = root;
        
        for (int i = 0; i < word_len; i++)
        {
            k = prefix[i] - 'a';
            cur = cur->children[k];
            
            if (cur == NULL)
                return false;
        }
        
        return true;
    }

private:
    TrieNode* root;
};