/*
Queue Reconstruction by Height

Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

 
Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // sort by the tallest groups
        sort(
            people.begin(),
            people.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[0]>b[0]||(a[0]==b[0]&&a[1]<b[1]);
            }
        );
        vector<vector<int>> ans;
        for(vector<int> p:people){
            // cout << p[0] << " " << p[1] << endl;
            // Input: [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
            // 7 0
            // 7 1
            // 6 1
            // 5 0
            // 5 2
            // 4 4
            ans.insert(ans.begin()+p[1],p);
            // [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
        }
        return ans;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();