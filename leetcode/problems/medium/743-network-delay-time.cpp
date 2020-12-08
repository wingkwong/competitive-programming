/*
Network Delay Time

There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

 Example 1:

Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2

Note:

N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.
*/

// floyd Warshall algorithm
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<long>> dist(N, vector<long>(N, INT_MAX));
        for(int i = 0; i < N; i++) dist[i][i] = 0;
        for(auto t : times) dist[--t[0]][--t[1]] = t[2];
        for(int k = 0; k < N; k++) {
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        long mx = 0;
        --K;
        for(int i = 0; i < N; i++) {
            if(dist[K][i] == INT_MAX) return -1;
            mx = max(mx, dist[K][i]);
        }
        return mx;
    }
};