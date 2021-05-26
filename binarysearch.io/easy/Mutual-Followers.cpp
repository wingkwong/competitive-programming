vector<int> solve(vector<vector<int>>& relations) {
    set<int> ans;
    set<pair<int, int>> s;
    for(auto x : relations) {
        s.insert({x[0], x[1]});
    }
    for(auto x : s) {
        if(s.find({x.second, x.first}) != s.end()) {
            ans.insert(x.first);
            ans.insert(x.second);
        }
    }
    return vector<int>(ans.begin(), ans.end());
}