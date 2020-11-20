bool solve(vector<vector<int>>& votes) {
    unordered_map<int, int> m;
    for(auto v : votes) m[v[1]]++;
    for(auto k : m) if(k.second > 1) return true;
    return false;
}