/*
Last Moment Before All Ants Fall Out of a Plank

We have a wooden plank of the length n units. Some ants are walking on the plank, each ant moves with speed 1 unit per second. Some of the ants move to the left, the other move to the right.

When two ants moving in two different directions meet at some point, they change their directions and continue moving again. Assume changing directions doesn't take any additional time.

When an ant reaches one end of the plank at a time t, it falls out of the plank imediately.

Given an integer n and two integer arrays left and right, the positions of the ants moving to the left and the right. Return the moment when the last ant(s) fall out of the plank.
*/

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // find the max leaving time from left & right  
        int ans=INT_MIN;
        for(int l:left) ans=max(l,ans);
        for(int r:right) ans=max(n-r,ans);
        return ans;
    }
};