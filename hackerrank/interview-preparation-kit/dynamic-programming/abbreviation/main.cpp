#include <bits/stdc++.h>

using namespace std;

// Complete the abbreviation function below.
string abbreviation(string a, string b) {
    int asz = (int)a.size();
    int bsz = (int)b.size();
    int dp[asz+1][bsz+1];
    memset(dp,0,sizeof(int)*(asz+1)*(bsz+1));
    dp[0][0] = 1;
    for(int i=1;i<=asz;i++) {
        if(!isupper(a[i-1])) dp[i][0]=1;
    }
    for(int i=1;i<=asz;i++){
        for(int j=1;j<=bsz;j++){
            if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1];
            else if(isupper(a[i-1])) dp[i][j] = 0;
            else if(toupper(a[i-1])==b[j-1]) dp[i][j] = dp[i-1][j-1] || dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j],dp[i-1][j]);
        }
    }
    return dp[asz][bsz]?"YES":"NO";
}
// AbCdE
// AFE
//     A F E
//   1 0 0 0 
// A 0 1 0 0 
// b 1 1 0 0 
// C 0 0 0 0 
// d 1 0 0 0 
// E 0 0 0 0 


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
