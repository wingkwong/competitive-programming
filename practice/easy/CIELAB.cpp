/*
Ciel and A-B Problem Problem Code: CIELAB
https://www.codechef.com/problems/CIELAB

In Ciel's restaurant, a waiter is training. Since the waiter isn't good at arithmetic, sometimes he gives guests wrong change. Ciel gives him a simple problem. What is A-B (A minus B) ?

Surprisingly, his answer is wrong. To be more precise, his answer has exactly one wrong digit. Can you imagine this? Can you make the same mistake in this problem?

Input
An input contains 2 integers A and B.

Output
Print a wrong answer of A-B. Your answer must be a positive integer containing the same number of digits as the correct answer, and exactly one digit must differ from the correct answer. Leading zeros are not allowed. If there are multiple answers satisfying the above conditions, anyone will do.

Constraints
1 ≤ B < A ≤ 10000

Sample Input
5858 1234
Sample Output
1624
Output details
The correct answer of 5858-1234 is 4624. So, for instance, 2624, 4324, 4623, 4604 and 4629 will be accepted, but 0624, 624, 5858, 4624 and 04624 will be rejected.

Notes
The problem setter is also not good at arithmetic.
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int a,b;
    cin >> a >> b;
    int d=a-b;
    string s=to_string(d);
    int n=(int)s.size(), ans;
    // check if the first digit is 9 
    // if so, update the first digit to 8 
    if(s[0]=='9') ans=d-pow(10,n-1);
    // if not, add 1 to the first digit
    else ans=d+pow(10,n-1);
    cout << ans << "\n";
    return 0;
} 