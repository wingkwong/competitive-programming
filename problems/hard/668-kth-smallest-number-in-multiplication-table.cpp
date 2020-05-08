/*
Kth Smallest Number in Multiplication Table

Nearly every one have used the Multiplication Table. But could you find out the k-th smallest number quickly from the multiplication table?

Given the height m and the length n of a m * n Multiplication Table, and a positive integer k, you need to return the k-th smallest number in this table.

Example 1:
Input: m = 3, n = 3, k = 5
Output: 
Explanation: 
The Multiplication Table:
1	2	3
2	4	6
3	6	9

The 5-th smallest number is 3 (1, 2, 2, 3, 3).
Example 2:
Input: m = 2, n = 3, k = 6
Output: 
Explanation: 
The Multiplication Table:
1	2	3
2	4	6

The 6-th smallest number is 6 (1, 2, 2, 3, 4, 6).
Note:
The m and n will be in the range [1, 30000].
The k will be in the range [1, m * n]
*/

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        // binary search approach
        int l=1,r=m*n+1,x;
        while(l<r){
            x=l+(r-l)/2;
            if(helper(x,m,n,k)>=k) r=x;
            else l=x+1;
        }
        return l;
    }
private:
    int helper(int x, int m, int n, int k){
        int cnt=0;
        for(int i=1;i<=m;i++){
            // calculate how many values are less than/ equal to x
            // use min to avoid x/i > n
            // 1   2   3   ... n*1
            // 2   4   6   ... n*2
            //     ...
            // i   2*i 3*i ... n*i  <= x
            //     ...
            // m   2*m 3*m ... m*m

            // i 2*i 3*i ... n*i  <= x
            // divided by i on both side
            // 1,2,3...,n <= x/i
            cnt+=min(x/i,n);
            //if it reaches the boundary, return immediately 
            if(cnt>=k) return cnt;
        }
        return cnt;
    }
};

class Solution2 {
public:
    int findKthNumber(int m, int n, int k) {
        // binary search approach
        int l=1,r=m*n+1,x;
        while(l<r){
            x=l+(r-l)/2;
            if(helper(x,m,n,k)>=k) r=x;
            else l=x+1;
        }
        return l;
    }
private:
    int helper(int x, int m, int n, int k){
        int cnt=0,j=m;
        for(int i=1;i<=n;i++){
            // ×	1	2	3	4	5	6	7	8	9	10	11	12
            // 1	1	2	3	4	5	6	7	8	9	10	11	12
            // 2	2	4	6	8	10	12	14	16	18	20	22	24
            // 3	3	6	9	12	15	18	21	24	27	30	33	36
            // 4	4	8	12	16	20	24	28	32	36	40	44	48
            // 5	5	10	15	20	25	30	35	40	45	50	55	60
            // 6	6	12	18	24	30	36	42	48	54	60	66	72
            // 7	7	14	21	28	35	42	49	56	63	70	77	84
            // 8	8	16	24	32	40	48	56	64	72	80	88	96
            // 9	9	18	27	36	45	54	63	72	81	90	99	108
            // 10	10	20	30	40	50	60	70	80	90	100	110	120
            // 11	11	22	33	44	55	66	77	88	99	110	121	132
            // 12	12	24	36	48	60	72	84	96	108	120	132	144
            while(j>=1&&i*j>x) j--;
            cnt+=j;
        }
        return cnt;
    }
};