bool solve(vector<int>& nums) {
    int one = 0, ok = 1;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == 1) {
            if(one && nums[i - 1] != 1) {
                ok = 0;
                break;
            }
            one++;
        }
    }
    return one && ok;
}