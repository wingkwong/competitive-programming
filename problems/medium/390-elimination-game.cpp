/*
Elimination Game

There is a list of sorted integers from 1 to n. Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.

Repeat the previous step again, but this time from right to left, remove the right most number and every other number from the remaining numbers.

We keep repeating the steps again, alternating left to right and right to left, until a single number remains.

Find the last number that remains starting with a list of length n.

Example:

Input:
n = 9,
1 2 3 4 5 6 7 8 9
2 4 6 8
2 6
6

Output:
6

*/

class Solution {
public:
    int lastRemaining(int n) {
        int ans=1,step=1;
        // true: left to right ; false : right to left
        bool flag = true; 
        while(n>1){
            // flag==true or odd case -> first element would be removed
            // add the step
            if(flag||n%2==1){
                ans+=step;
            }
            step*=2;
            n/=2;
            flag = !flag;
        }
        return ans;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

// 1 2 3 4 5 6 7 --- 7
// 2 4 6  --- 3
// 4  --- 1

// 1 2 3 4 5 6 7 8  --- 8
// 2 4 6 8  --- 4
// 2 6 --- 2
// 6 -- 1
    
// 1 2 3 4 5 6 7 8 9 --- 9
// 2 4 6 8 --- 4
// 2 6 --- 2
// 6 --- 1
    
// 1 2 3 4 5 6 7 8 9 10 --- 10
// 2 4 6 8 10 --- 5
// 4 8 --- 2 
// 8 --- 1