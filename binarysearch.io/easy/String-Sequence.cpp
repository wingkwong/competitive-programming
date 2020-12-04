/*
String Sequence
https://binarysearch.com/problems/String-Sequence
*/

string solve(string s0, string s1, int n) {
    vector<string> a;
    a.push_back(s0);
    a.push_back(s1);
    for(int i = 2; i <= n; i++) {
        if((i & 1) ^ 1) a.push_back(a[i - 1] + a[i - 2]);
        else a.push_back(a[i - 2] + a[i - 1]);
    }
    return a[n];
}