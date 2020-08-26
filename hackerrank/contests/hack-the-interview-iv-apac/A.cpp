/*
Hack the Interview IV (Asia Pacific) - Valid Binary String
https://www.hackerrank.com/contests/hack-the-interview-iv-apac/challenges/good-binary-string
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumMoves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER d
 */

int minimumMoves(string s, int d) {
    // sliding window approach
    // given that window size d
    // find out how many 1s we need to add 
    int n=(int)s.size();
    int ans=0,sum=0,tmp=0;
    for(int start=0,end=0;end<n;end++) {
        tmp=s[end]-'0';
        if(!tmp) sum++;
        if(end>=d-1) {
            if(sum==d) {
                ans++;
                s[end]='1';
                sum--;
            }
            tmp=s[start++]-'0';
            if(!tmp) sum--;
        }
    }
    return ans;
        
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string d_temp;
    getline(cin, d_temp);

    int d = stoi(ltrim(rtrim(d_temp)));

    int result = minimumMoves(s, d);

    fout << result << "\n";

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