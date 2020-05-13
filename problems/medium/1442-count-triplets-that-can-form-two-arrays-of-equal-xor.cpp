/*
Count Triplets That Can Form Two Arrays of Equal XOR

Given an array of integers arr.

We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).

Let's define a and b as follows:

a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
Note that ^ denotes the bitwise-xor operation.

Return the number of triplets (i, j and k) Where a == b.

 

Example 1:

Input: arr = [2,3,1,6,7]
Output: 4
Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
Example 2:

Input: arr = [1,1,1,1,1]
Output: 10
Example 3:

Input: arr = [2,3]
Output: 0
Example 4:

Input: arr = [1,3,5,7,9]
Output: 3
Example 5:

Input: arr = [7,11,12,9,5,2,7,17,22]
Output: 8
 

Constraints:

1 <= arr.length <= 300
1 <= arr[i] <= 10^8
*/

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int sz=(int)arr.size(), ans=0;
        for(int i=0;i<sz-1;i++){
            int XOR=arr[i];
            for(int j=i+1;j<sz;j++){
                // a^b=c // 2^3=1
                // a=b^c // 2=3^1
                if(XOR==arr[j]){
                    ans+=j-i;
                }
                XOR^=arr[j];
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    struct TrieNode{
        TrieNode* children[2];
        int sum;
        int num;
        TrieNode(){
           this->children[0]=NULL; 
           this->children[1]=NULL; 
           this->sum = 0; 
           this->num = 0; 
        }
    };
    
    void insert(TrieNode* node, int num, int index){
        for(int i=31;i>=0;i--){
            int cur=(num>>i)&1;
            if(!node->children[cur]) node->children[cur]=new TrieNode();
            node=node->children[cur];
        }    
        node->sum+=index;
        node->num++;
    }
    
    int query(TrieNode* node, int num, int index){
        for(int i=31;i>=0;i--){
            int cur=(num>>i)&1;
            if(!node->children[cur]) return 0;
            node=node->children[cur];
        }  
        
        int sz=node->num;
        int sum=node->sum;
        return (sz*index)-sum;
    }
    
    int countTriplets(vector<int>& arr) {
        int sz=(int)arr.size();
        int ans=0,cur=0;
        TrieNode* root = new TrieNode(); 
        for(int i=0;i<sz;i++){
            int x=arr[i];
            insert(root,cur,i);
            cur^=x;
            ans+=query(root,cur,i);
        }
        return ans;
    }
};

// TLE
// class Solution3 {
// public:
//     int countTriplets(vector<int>& arr) {
//         int sz=(int)arr.size();
//         int ans=0;
//         for(int i=0;i<sz;i++){
//             for(int j=i+1;j<sz;j++){
//                 for(int k=j;k<sz;k++){
//                     int x1=0,x2=0;
//                     for(int x=i;x<j;x++) x1^=arr[x];
//                     for(int x=j;x<=k;x++) x2^=arr[x];
//                     if(x1==x2) ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };