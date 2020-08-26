/*
Replace Words

In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.

Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.

You need to output the sentence after the replacement.

Example 1:

Input: dict = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
 

Constraints:

The input will only have lower-case letters.
1 <= dict.length <= 1000
1 <= dict[i].length <= 100
1 <= sentence words number <= 1000
1 <= sentence words length <= 1000
*/

class Solution {
public:
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
    
    string replaceWords(vector<string>& dict, string sentence) {
        int n = (int)dict.size();
        // create a trie root node
        struct TrieNode *root = getNode();
        // insert each dict char to trie node
        for(int i=0;i<n;i++) insert(root,dict[i]);
        // stream the sentence to skip the space
        stringstream ss(sentence);
        string word;
        string ans = "";
        while(ss>>word) {
            // append space if it is not empty
            if(ans.size()>0) ans+=" ";
            // search if it can form the word or not
            string s = search(root,word);
            // append it to ans
            ans+=s;
        }
        return ans;
    }
};

class Solution2 {
public:
    struct TrieNode {
        struct TrieNode *children[26];
        string word;
        
        TrieNode(){
            for(int i=0;i<26;i++) children[i]=NULL;
        }
        
        bool containsKey(char ch){
            return children[ch-'a']!=NULL;
        }
        
        void put(char ch, TrieNode* node){
            children[ch-'a'] = node;
        }
        
        TrieNode* get(char ch){
            return children[ch-'a'];
        }
    };
    
    TrieNode* build(vector<string>& dict){
        TrieNode* root = new TrieNode();
        for(string word:dict){
            TrieNode *node = root;
            for(char c:word){
                if(!node->containsKey(c)){
                    node->put(c,new TrieNode());
                }
                node = node->get(c);
            }
            node->word = word;
        }
        return root;
    }
    
    string replaceWords(vector<string>& dict, string sentence) {
        int n = (int)dict.size();
        struct TrieNode *root = build(dict);
        stringstream ss(sentence);
        string word;
        string ans = "";
        while(ss>>word) {
            TrieNode * node = root;
            for(char c:word){
                if(!node->containsKey(c)||node->word!="") break;
                node = node->get(c);
            }
            if(!ans.empty()) ans+= " ";
            ans += (node->word!=""?node->word:word);
        }
        return ans;
    }
};
static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
