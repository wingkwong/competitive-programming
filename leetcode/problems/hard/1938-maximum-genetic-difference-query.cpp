/*
Maximum Genetic Difference Query
https://leetcode.com/problems/maximum-genetic-difference-query/

There is a rooted tree consisting of n nodes numbered 0 to n - 1. Each node's number denotes its unique genetic value (i.e. the genetic value of node x is x). The genetic difference between two genetic values is defined as the bitwise-XOR of their values. You are given the integer array parents, where parents[i] is the parent for node i. If node x is the root of the tree, then parents[x] == -1.

You are also given the array queries where queries[i] = [nodei, vali]. For each query i, find the maximum genetic difference between vali and pi, where pi is the genetic value of any node that is on the path between nodei and the root (including nodei and the root). More formally, you want to maximize vali XOR pi.

Return an array ans where ans[i] is the answer to the ith query.

 

Example 1:


Input: parents = [-1,0,1,1], queries = [[0,2],[3,2],[2,5]]
Output: [2,3,7]
Explanation: The queries are processed as follows:
- [0,2]: The node with the maximum genetic difference is 0, with a difference of 2 XOR 0 = 2.
- [3,2]: The node with the maximum genetic difference is 1, with a difference of 2 XOR 1 = 3.
- [2,5]: The node with the maximum genetic difference is 2, with a difference of 5 XOR 2 = 7.
Example 2:


Input: parents = [3,7,-1,2,0,7,0,2], queries = [[4,6],[1,15],[0,5]]
Output: [6,14,7]
Explanation: The queries are processed as follows:
- [4,6]: The node with the maximum genetic difference is 0, with a difference of 6 XOR 0 = 6.
- [1,15]: The node with the maximum genetic difference is 1, with a difference of 15 XOR 1 = 14.
- [0,5]: The node with the maximum genetic difference is 2, with a difference of 5 XOR 2 = 7.
 

Constraints:

2 <= parents.length <= 105
0 <= parents[i] <= parents.length - 1 for every node i that is not the root.
parents[root] == -1
1 <= queries.length <= 3 * 104
0 <= nodei <= parents.length - 1
0 <= vali <= 2 * 105
*/

class Solution {
public:
    struct Trie {
        Trie* ch[2] = {};
        int cnt = 0;
        void increment(int val, int d, int pos = 17) {
            cnt += d;
            if (pos >= 0) {
                bool b = val & (1 << pos);
                if (ch[b] == nullptr)
                    ch[b] = new Trie();
                ch[b]->increment(val, d, pos - 1);
            }
        }
        int match(int val, int pos = 17) {
            if (pos < 0)
                return 0;
            bool b = val & (1 << pos);
            if (ch[!b] != nullptr && ch[!b]->cnt > 0)
                return (1 << pos) + ch[!b]->match(val, pos - 1);
            return ch[b] == nullptr ? 0 : ch[b]->match(val, pos - 1);
        }
    };
    Trie t;
    void dfs(unordered_map<int, vector<pair<int, int>>> &q, vector<vector<int>> &al, vector<int> &res, int ni) {
        t.increment(ni, 1);
        for (auto [i, val] : q[ni])
            res[i] = t.match(val);
        for (auto nj : al[ni])
            dfs(q, al, res, nj);
        t.increment(ni, -1);
    }
    vector<int> maxGeneticDifference(vector<int>& pars, vector<vector<int>>& qs) {
        vector<vector<int>> al(pars.size());
        vector<int> res(qs.size());
        int root = -1;
        unordered_map<int, vector<pair<int, int>>> q;
        for (int i = 0; i < qs.size(); ++i)
            q[qs[i][0]].push_back({i, qs[i][1]});
        for (int i = 0; i < pars.size(); ++i)
            if (pars[i] == -1)
                root = i;
            else
                al[pars[i]].push_back(i);
        dfs(q, al, res, root);
        return res;
    }
};