bool solve(vector<int>& nums) {
    unordered_map<int, int> m;
    for(int n : nums) m[n]++;
    set<int> s;
    int cnt = 0;
    for(auto k : m) {
        cnt++;
        s.insert(k.second);
    }
    return s.size() == cnt;
}