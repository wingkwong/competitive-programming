bool solve(string s) {
    int cnt[26] = {0};
    for(char c : s) cnt[c - 'a']++;
    int even = 0, odd = 0;
    for(int i = 0; i < 26; i++) {
        even += cnt[i] % 2 == 0;
        odd += cnt[i] & 1;
    }
    if(even > 0 && odd == 0) return true;
    if(even >= 0 && odd == 1) return true;
    return false;
}