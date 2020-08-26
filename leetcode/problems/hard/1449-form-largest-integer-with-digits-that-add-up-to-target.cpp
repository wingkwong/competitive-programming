/*
Form Largest Integer With Digits That Add up to Target

Given an array of integers cost and an integer target. Return the maximum integer you can paint under the following rules:

The cost of painting a digit (i+1) is given by cost[i] (0 indexed).
The total cost used must be equal to target.
Integer does not have digits 0.
Since the answer may be too large, return it as string.

If there is no way to paint any integer given the condition, return "0".

Example 1:

Input: cost = [4,3,2,5,6,7,2,5,5], target = 9
Output: "7772"
Explanation:  The cost to paint the digit '7' is 2, and the digit '2' is 3. Then cost("7772") = 2*3+ 3*1 = 9. You could also paint "997", but "7772" is the largest number.
Digit    cost
  1  ->   4
  2  ->   3
  3  ->   2
  4  ->   5
  5  ->   6
  6  ->   7
  7  ->   2
  8  ->   5
  9  ->   5
Example 2:

Input: cost = [7,6,5,5,5,6,8,7,8], target = 12
Output: "85"
Explanation: The cost to paint the digit '8' is 7, and the digit '5' is 5. Then cost("85") = 7 + 5 = 12.
Example 3:

Input: cost = [2,4,6,2,4,6,4,4,4], target = 5
Output: "0"
Explanation: It's not possible to paint any integer with total cost equal to target.
Example 4:

Input: cost = [6,10,15,40,40,40,40,40,40], target = 47
Output: "32211"
 

Constraints:

cost.length == 9
1 <= cost[i] <= 5000
1 <= target <= 5000
*/


class Solution {
public:
    // top-down dp approach
    string largestNumber(vector<int>& cost, int target) {
        if(target==0) return "";
        if(target<0) return "0";
        if(dp[target].empty()){
             dp[target]="0";
             // 9 digits
             for(int i=1;i<=9;i++){
                 // build the result string 
                 string res=largestNumber(cost,target-cost[i-1]);
                 // if res is "0", that means cost[n]>=target, hence we can't take this digit
                 // if res size plus 1 is greater than the dp[target] size, 
                 if(res!="0"&&res.size()+1>=dp[target].size()){
                     dp[target]=to_string(i)+res;
                 }
             }
        }
        return dp[target];
    }
private:
    string dp[5001] = {};
};

class Solution2 {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<string> dp(target+1,"0");
        int n=(int)cost.size();
        dp[0]="";
        for(int i=0;i<n;i++){
            for(int j=1;j<=target;j++){
                if(
                    j<cost[i] || 
                    dp[j-cost[i]]=="0"
                ) continue;
                string s = string(1,'1'+i)+dp[j-cost[i]];
                if(
                    s.size() != dp[j].size() ?
                        s.size() > dp[j].size() :
                            s > dp[j]
                ) dp[j]=s;
            }
        }
        return dp[target];
    }
};


// Time Limit Exceeded 
// class Solution {
// public:
//     void helper(vector<int>& cost,int cur,string res){
//         if(cur==0) {
//             // cout << res << endl;
//             s.insert(res);
//             return;
//         }
//         for(int i=0;i<cost.size();i++){
//             if(cur>=cost[i]) helper(cost,cur-cost[i],res+" " +to_string(cost[i]));
//         }
//     }
    
//     string largestNumber(vector<int>& cost, int target) {
//         long long ans=0;
//         for(int i=1;i<=cost.size();i++){
//             s2.insert(cost[i-1]);
//             m[cost[i-1]]=i;
//         }
//         vector<int> cost2;
//          for(auto lt=s2.begin();lt!=s2.end();lt++){
//            cost2.push_back(*lt);   
//          }
//         helper(cost2,target,"");
//         for(auto lt=s.begin();lt!=s.end();lt++){
//             string ss = *lt;
//             long long tmp=0;
//             stringstream strs(ss);
//             string word;
//             while(strs >> word){
//                 tmp=tmp*10+m[stoi(word)];
//             }
//             ans=max(tmp,ans);
//         }
//         return to_string(ans);
//     }
// private:
//     set<string> s;
//     set<int>s2;
//     map<int,int> m;
// };