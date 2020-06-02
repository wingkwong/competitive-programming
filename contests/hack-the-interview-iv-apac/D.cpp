/*
Hack the Interview IV (Asia Pacific) - Number of integers
https://www.hackerrank.com/contests/hack-the-interview-iv-apac/challenges/maximum-or-1
*/

/******************************************************
WA - Passed 13/17 cases only  
*******************************************************/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'getNumberOfIntegers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING L
 *  2. STRING R
 *  3. INTEGER K
 */

const int M=1000000007; 
int helper(string s, int k){
    int n=(int)s.size();
    long long dp[n+1][2][k+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<2;j++){
            for(int x=0;x<=k;x++){
                dp[i][j][x]=0;
            }
        }
    }
    dp[0][0][0]=1;
    for(int i=0;i<n;i++){
        int y=0;
        while(y<2){
            for(int j=0;j<k+1;j++){
                int x=0;
                while(x<=(y?9:s[i]-'0')){
                    dp[i+1][y||x<(s[i]-'0')][j+(x>0)]+=dp[i][y][j];
                    dp[i+1][y||x<(s[i]-'0')][j+(x>0)]%=M;
                    x++;
                }
            }
            y++;    
        }
    }
    return dp[n][0][k]+dp[n][1][k];
}

int getNumberOfIntegers(string L, string R, int K) {
    return helper(R,K)-helper(L,K);
}


// int dp[20][20][2];

// int helper2(int x, int y, int z, vector<int> n, int k){
//     if(x==(int)n.size()) return y<=k?1:0;
//     if(dp[x][y][z]!=-1) return dp[x][y][z];
//     int ans=0;
//     int mx=z?9:n[x];
//     for(int i=0;i<=mx;i++){
//         int curY=y;
//         if(i!=0) curY++;
//         int curZ=z;
//         if(i<n[x]) z=1;
//         ans+=helper2(x+1,curY,curZ,n,k);
//         ans%=1000000007;
//     }
//     return dp[x][y][z]=ans;
// }

// int helper(int x, int k){
//     vector<int> n;
//     while(x){
//         n.push_back(x%10);
//         x/=10;
//     }
//     reverse(n.begin(),n.end());
//     memset(dp,-1,sizeof(dp));
//     return helper2(0,0,0,n,k);
// }

// int getNumberOfIntegers(string L, string R, int K) {
//     return helper(stoi(R), K)-helper(stoi(L)-1, K);
// }

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string L;
    getline(cin, L);

    string R;
    getline(cin, R);

    string K_temp;
    getline(cin, K_temp);

    int K = stoi(ltrim(rtrim(K_temp)));

    int ans = getNumberOfIntegers(L, R, K);

    fout << ans << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
