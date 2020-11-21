bool solve(vector<int>& nums) {
    unordered_map<int, int> m;
    for(int n : nums) m[n]++;
    for(auto k : m) {
        if(k.first == k.second) {
            return true;
        }
    }
    return false;
}