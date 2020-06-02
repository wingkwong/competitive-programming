/*
Hack the Interview IV (Asia Pacific) - Optimal Network Routing
https://www.hackerrank.com/contests/hack-the-interview-iv-apac/challenges/optimal-path-1
*/

/******************************************************
TLE - Passed 5/19 cases only  
*******************************************************/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*
 * Complete the 'getMinEffort' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY C as parameter.
 */


int ans=1e9;
void dfs(vector<vector<int>>& C, int i, int j, int k, int m, int n, int a){
    if(i<0||i>=m||j<0||j>=n||C[i][j]==0) return;

    a=max(abs(C[i][j]-k),a);
    if(a>ans) return;
    
    if(i==m-1&&j==n-1) {
        ans=min(ans,a);
        return;
    }
 
    int t=C[i][j];
    C[i][j]=0;
    dfs(C,i+1,j,t,m,n,a);
    dfs(C,i,j+1,t,m,n,a);
    dfs(C,i-1,j,t,m,n,a);
    dfs(C,i,j-1,t,m,n,a);
    C[i][j]=t;
    return;
}

int getMinEffort(vector<vector<int>> C) {
    // my approach:
    // dfs - find out each possible route - find out  the max effort 
    // when it reaches to the end, find out the min effort among all rounds
    int m=(int)C.size(),n=(int)C[0].size();
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             if(!v[C[i][j]][C[max(0,i-1)][j]]||!v[C[max(0,i-1)][j]][C[i][j]]) 
//                 v[C[max(0,i-1)][j]][C[i][j]]=v[C[i][j]][C[max(0,i-1)][j]]=abs(C[i][j]-C[max(0,i-1)][j]);
//             if(!v[C[i][j]][C[min(m-1,i+1)][j]]||!v[C[min(m-1,i+1)][j]][C[i][j]]) 
//                 v[C[min(m-1,i+1)][j]][C[i][j]]=v[C[i][j]][C[min(m-1,i+1)][j]]=abs(C[i][j]-C[min(m-1,i+1)][j]);
//             if(!v[C[i][j]][C[i][max(0,j-1)]]||!v[C[i][max(0,j-1)]][C[i][j]]) 
//                 v[C[i][max(0,j-1)]][C[i][j]]=v[C[i][j]][C[i][max(0,j-1)]]=abs(C[i][j]-C[i][max(0,j-1)]);
//             if(!v[C[i][j]][C[i][min(n,j+1)]]||!v[C[i][min(n,j+1)]][C[i][j]]) 
//                 v[C[i][min(n-1,j+1)]][C[i][j]]=v[C[i][j]][C[i][min(n-1,j+1)]]=abs(C[i][j]-C[i][min(n-1,j+1)]);
//         }
//     }
    
    dfs(C,0,0,C[0][0],m,n,0);
    return ans;
    
}

// 7 10
// 11232 6 51213 3 5 12 6123 5 3 5 
// 11232 11233 3 15123 5 1232 236 5643 373 1235 
// 11232 1232 6345 9345 5 11322 6 1235 3453 5345 
// 11232 2 6 9345 5 13452 3456 5 3 5 
// 11232 2 6 9345 5 13452 3456 123123 123123 12313 
// 11232 2 6 9345 5 13452 3456 123123 123123 12313 
// 11232 11232 11232 11232 11232 11232 11232 11232 11232 11232

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

// int getMinEffort(vector<vector<int>> C) {
//     int m=(int)C.size(),n=(int)C[0].size();
//     int dp[m+1][n+1], dp2[m+1][n+1];
//     memset(dp,1e6+7,sizeof(dp));
//     memset(dp2,0,sizeof(dp2));
//     dp[0][0]=0;
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             if(!i&&!j) continue;
//             cout << C[i][j] << endl;
//             if(i-1>0) dp[i][j]=min(dp[i][j],abs(C[i][j]-C[i-1][j]));
//             if(j-1>0) dp[i][j]=min(dp[i][j],abs(C[i][j]-C[i][j-1]));
//             if(i+1<m) dp[i][j]=min(dp[i][j],abs(C[i][j]-C[i+1][j]));
//             if(j+1<n) dp[i][j]=min(dp[i][j],abs(C[i][j]-C[i][j+1]));
//             // dp[i][j]=min(min(min(abs(C[i][j]-C[max(0,i-1)][max(0,j-1)]),abs(C[i][j]-C[max(0,i-1)][j])),abs(C[i][j]-C[max(m,i+1)][max(n,j+1)])),abs(C[i][j]-C[i][max(n,j+1)]));
//         }
//     }
    
    
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             dp2[i][j]+=dp[i][j];
//             // cout << i << " - " << j << " : " <<  dp[i][j] << " -- " << dp2[i][j] << endl;
//             if(i&&j) dp2[i][j]+=min(dp2[i-1][j],dp2[i][j-1]);
//             else if(i) dp2[i][j]+=dp2[i-1][j];
//             else if(j) dp2[i][j]+=dp2[i][j-1];
//         }
//     }
//     return dp2[m-1][n-1];
// }

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i].resize(m);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < m; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    }

    int answer = getMinEffort(arr);

    fout << answer << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
