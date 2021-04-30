/*
Next Closest Time
https://leetcode.com/problems/next-closest-time/

Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

 

Example 1:

Input: time = "19:34"
Output: "19:39"
Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.
It is not 19:33, because this occurs 23 hours and 59 minutes later.
Example 2:

Input: time = "23:59"
Output: "22:22"
Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22.
It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.
 

Constraints:

time.length == 5
time is a valid time in the form "HH:MM".
0 <= HH < 24
0 <= MM < 60
*/

class Solution {
public:
    string nextClosestTime(string time) {
        vector<int> v = {time[0] - '0', time[1] - '0', time[3] - '0', time[4] - '0'};
        set<string> s;
        for(int a : v) {
            for(int b : v) {
                for(int c : v) {
                    for(int d : v) {
                        if(a * 10 + b < 24 && c * 10 + d < 60) {
                            string t = to_string(a) + to_string(b) + ":" + to_string(c) + to_string(d);
                            s.insert(t);
                        }
                    }
                }
            }
        }
        vector<string> ans(s.begin(), s.end());
        sort(ans.begin(), ans.end());
        int n = ans.size(), i = 0;
        while(i < n) {
            cout << ans[i] << endl;
            if(ans[i] == time) {
                break;
            }
            i++;
        }
        return ans[(++i % n)];
    }
};