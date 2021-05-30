vector<int> solve(vector<int>& nums) {
    auto a = nums;
    a.erase(unique(a.begin(), a.end()), a.end());
    if (a.size() < 2) return {};
    int l = 0;
    int n = (int)nums.size();
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (nums[i] != a[l]) l++;
        int left = l - 1 >= 0 ? a[l - 1] : INT32_MIN;
        int right = l + 1 < a.size() ? a[l + 1] : INT32_MIN;
        if (left < nums[i] && right < nums[i]) ans.push_back(i);
    }
    return ans;
}