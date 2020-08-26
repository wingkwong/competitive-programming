/*
Two City Scheduling

There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].

Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.

Example 1:

Input: [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
 
Note:

1 <= costs.length <= 100
It is guaranteed that costs.length is even.
1 <= costs[i][0], costs[i][1] <= 1000
*/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // sort by the diff 
        // ------------------------------------------
        // [[10,20],[30,200],[400,50],[30,20]]
        // -10, -170, 350, 10
        // -170, -10, 10, 350
        sort(costs.begin(),costs.end(),[](vector<int>& a, vector<int>& b){
            return a[0]-b[0] < a[1]-b[1];
        });
        // another approach is to use nth_element to achieve O(n log n) runtime
        // becuase we don't need to care much about the exact order, 
        // just find the middle as a pivot and split into two groups
        // --------------------------------APPROACH 2-------------------------------------------------
        // nth_element(begin(cs), begin(cs) + cs.size() / 2, end(cs), [](vector<int> &a, vector<int> &b) {
        //     return (a[0] - a[1] < b[0] - b[1]);
        // });
        // --------------------------------APPROACH 2-------------------------------------------------
        int ans=0, n=(int)costs.size();
        // it is guaranteed that costs.length is even
        // hence, the first half goes to city A, the second half goes to city B
        for(int i=0;i<n/2;i++) ans+=costs[i][0]+costs[i+n/2][1];
        return ans;
    }
};

