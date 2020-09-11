/*
Task Hare
https://binarysearch.io/problems/Task-Hare

You are given a list of integers tasks and another list of integers people. The integer tasks[i] represents the amount of strength required to perform the ith task. people[i] represents the amount of strength the ith person has.

Return the number of tasks that can be finished if one person can perform at most one task.

Constraints

n ≤ 100,000 where n is the length of tasks
m ≤ 100,000 where m is the length of people
Example 1
Input

tasks = [3, 2, 9, 13]
people = [10, 5, 2, 1]
Output

3
Explanation

First person can perform task 9
Second person can perform task 3
Third person can perform task 2
Fourth person can't perform any tasks
*/

#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(vector<int>& tasks, vector<int>& people) {
        sort(tasks.begin(), tasks.end());
        sort(people.begin(), people.end());
        int j=0;
        for(int i=0;i<people.size();i++){
            if(j<tasks.size()&&people[i]>=tasks[j]){
                j++;
            }
        }
        return j;
    }
};

class Solution2 {
    public:
    int solve(vector<int>& tasks, vector<int>& people) {
        sort(tasks.rbegin(), tasks.rend());
        sort(people.rbegin(), people.rend());
        int ans=0, j=0;
        for(int i=0;i<people.size();i++){
            while(j<tasks.size()){
                if(people[i]<tasks[j]){
                    j++;
                } else {
                    ans++;
                    j++;
                    break;
                }
            }
        }
        return ans;
    }
};
