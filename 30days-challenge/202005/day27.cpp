/*
Possible Bipartition

Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false

Note:

1 <= N <= 2000
0 <= dislikes.length <= 10000
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j].
*/

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N,vector<int>(N,0));
        vector<int> group(N,0);
        for(vector<int> d:dislikes){
            // build a bi-directional graph
            graph[d[0]-1][d[1]-1]=graph[d[1]-1][d[0]-1]=1;
        }
        
        // traverse each person
        for(int i=0;i<N;i++){
            // check if this person does not belong to any group and its dfs result
            // group[i]==0  : no group
            // group[i]==1  : group 1
            // group[i]==-1 : group 2
            if(!group[i]&&!dfs(graph,group,i,1)){
                return false;
            }
        }
        return true;
    }
private:
    bool dfs(vector<vector<int>>& graph, vector<int>& group, int index, int grp){
        // assign this person to group grp
        group[index]=grp;
        // traverse each graph
        for(int i=0;i<graph.size();i++){
            // if person index dislikes person i
            if(graph[index][i]){
                // and if person i belongs to the same group
                if(group[i]==grp){
                    // then return false
                    return false;
                } 
                // check if person i does not belong to any group and its dfs result
                if(!group[i]&&!dfs(graph,group,i,-grp)){
                    return false;
                }
            }
        }
        return true;
    }
};