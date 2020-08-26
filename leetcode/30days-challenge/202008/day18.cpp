/*
Numbers With Same Consecutive Differences

Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

You may return the answer in any order.

 

Example 1:

Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 

Note:

1 <= N <= 9
0 <= K <= 9
*/

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        if(N == 1) return {0,1,2,3,4,5,6,7,8,9};
        // bfs approach 
        deque<int> q{1,2,3,4,5,6,7,8,9};
        while(--N>0){
            for(int i=q.size();i>0;i--){
                int n = q.front(); 
                q.pop_front();
                for(int j=0;j<10;j++){
                    if(abs((n%10)-j)==K){
                        q.push_back(n*10+j);
                    }
                }
            }
        }
        return vector<int>{q.begin(),q.end()};
    }
};