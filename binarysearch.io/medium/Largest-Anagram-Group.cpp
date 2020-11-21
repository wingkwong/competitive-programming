int solve(vector<string>& words) {
    unordered_map<string, int> m;
    for(string s : words) {
        sort(s.begin(), s.end());
        m[s]++;
    }
    int ans = 0;
    for(auto k : m) ans = max(ans, k.second);
    return ans;
}