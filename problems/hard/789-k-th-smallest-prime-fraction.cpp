/*
K-th Smallest Prime Fraction

A sorted list A contains 1, plus some number of primes.  Then, for every p < q in the list, we consider the fraction p/q.

What is the K-th smallest fraction considered?  Return your answer as an array of ints, where answer[0] = p and answer[1] = q.

Examples:
Input: A = [1, 2, 3, 5], K = 3
Output: [2, 5]
Explanation:
The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
The third fraction is 2/5.

Input: A = [1, 7], K = 1
Output: [1, 7]
Note:

A will have length between 2 and 2000.
Each A[i] will be between 1 and 30000.
K will be between 1 and A.length * (A.length - 1) / 2.
*/

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        int p=0,q=1,cnt;
        int n=(int)A.size();
        double l=0,r=1;
        while(l<r){
            double m = l+(r-l)/2;
            cnt=0; p=0;
            for(int i=0,j=n-1;i<n;i++){
                // A[i]/A[n-1-j] > m 
                // = A[i]>m*A[n-1-j]
                while(j>=0&&A[i]>m*A[n-1-j]) j--;
                cnt+=(j+1);
                // p/q < A[i]/A[n-1-j]
                // p*A[n-1-j]<A[i]*q
                if(j>=0&&p*A[n-1-j]<A[i]*q){
                    p=A[i];
                    q=A[n-1-j];
                }
            }
            if(cnt>K) r=m;
            else if(cnt<K)l=m;
            else break;
        }
        return vector<int>{p,q};
    }
};
static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();