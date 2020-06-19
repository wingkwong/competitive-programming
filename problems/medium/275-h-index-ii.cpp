/*
H-Index II

Given an array of citations sorted in ascending order (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

Example:

Input: citations = [0,1,3,5,6]
Output: 3 
Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had 
             received 0, 1, 3, 5, 6 citations respectively. 
             Since the researcher has 3 papers with at least 3 citations each and the remaining 
             two with no more than 3 citations each, her h-index is 3.
Note:

If there are several possible values for h, the maximum one is taken as the h-index.

Follow up:

This is a follow up problem to H-Index, where citations is now guaranteed to be sorted in ascending order.
Could you solve it in logarithmic time complexity?
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        // binary search approach
        int n = citations.size();
        if(n==0) return 0;
        int l=0,r=n-1,m;
        while(l<=r){
            m=l+(r-l)/2;
            // there are citations[mid] papers that have at least citations[mid] citations
            if(citations[m]==n-m) return citations[m]; 
            // there are citations[mid] papers that have less than citations[mid] citations
            else if(citations[m]<n-m) l=m+1;
            // there are citations[mid] papers that have more than citations[mid] citations
            else r=m-1;
        }
        //      left
        //       v
        // 0, 1, 4, 5, 7
        //    ^  
        //    right
        return n-r-1;
        // or return n-l;
    }
};