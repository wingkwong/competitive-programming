/*
Divisor Game

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number N on the chalkboard.  On each player's turn, that player makes a move consisting of:

Choosing any x with 0 < x < N and N % x == 0.
Replacing the number N on the chalkboard with N - x.
Also, if a player cannot make a move, they lose the game.

Return True if and only if Alice wins the game, assuming both players play optimally.

 

Example 1:

Input: 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.
Example 2:

Input: 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.
 

Note:

1 <= N <= 1000
*/


// Math approach
class Solution {
public:
    bool divisorGame(int N) {
        // win if N is even, lose if not
        // Eventually it will reach 2 for N>=2 
        return N%2==0;
        // or 
        // return !(N&1）
    }
};

// DP approach
class Solution {
public:
    bool divisorGame(int N) {
        bool dp[N+1]; // true: Alice wins; false: Alice loses
        memset(dp,false,sizeof(dp));
        for(int i=2;i<=N;i++){
            for(int j=1;j*j<=i;j++){ // N % x == 0
                if(i%j==0&&!dp[i-j]) // can be disviable and opponent must lose for the next turn
                    dp[i]=true;
            }
        }
        return dp[N];
    }
};

// DP approach 2
// Similar to Solution 1
class Solution2 {
public:
    bool divisorGame(int N) {
        dp.assign(N+1,0);
        return helper(N);
    }
private:
    vector<int> dp;
    bool helper(int n, bool res=false){
        if(dp[n]!=0) return dp[n]==1;
        for(int i=1;!res&&i*i<n;i++){
            if(n%i==0) res=!helper(n-i);
        }
        dp[n]=res?1:-1;
        return res;
    }
};