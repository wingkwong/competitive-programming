```cpp
struct TrieNode {
    // 26 branches for 26 characters respectively 
    struct TrieNode *children[26];
    // flag to check if it is a tail
    bool isEndOfWord;
};

struct TrieNode *getNode(void){
    struct TrieNode *node = new TrieNode;
    // set it to false for a new node
    node->isEndOfWord = false;
    // init each branch to NULL
    for(int i=0;i<26;i++) node->children[i] = NULL;
    // return the node
    return node;
}

void insert(struct TrieNode *root, string key){
    struct TrieNode *node = root;
    // given that a string, take each character and insert to node
    for(int i=0;i<key.size();i++) {
        cout << key[i] << " ";
        int idx = key[i]-'a';
        // if it doesn't exist, create a new node for this character
        if(!node->children[idx]) node->children[idx] = getNode();
        // move to children to build the rest of the branches
        node = node->children[idx];
    }
    // set it to true
    node->isEndOfWord = true;
}

string search(struct TrieNode *root, string key){
    struct TrieNode *node = root;
    string res="";
    for(int i=0;i<key.size();i++) {
        int idx = key[i]-'a';
        // if the character does not exist in trie node, break it immediately
        if(!node->children[idx]) break;
        // append the character to res
        res+=key[i];
        // move to the next branch
        node = node->children[idx];
        // if it reaches to the tail, return res immediately
        if(node->isEndOfWord) return res;
    }
    return key;
}
```

### Usage:

```cpp
// init Trie
struct TrieNode *root = getNode();
// insert each dict char to trie node
for(int i=0;i<n;i++) insert(root,dict[i]);
// search 
string s = search(root,word);
```