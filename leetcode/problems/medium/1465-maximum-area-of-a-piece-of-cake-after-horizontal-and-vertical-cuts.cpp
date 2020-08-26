/*
Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts

Given a rectangular cake with height h and width w, and two arrays of integers horizontalCuts and verticalCuts where horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.

Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a huge number, return this modulo 10^9 + 7.

Example 1:
Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
Output: 4 
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green piece of cake has the maximum area.

Example 2:
Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
Output: 6
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green and yellow pieces of cake have the maximum area.
Example 3:

Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
Output: 9

Constraints:

2 <= h, w <= 10^9
1 <= horizontalCuts.length < min(h, 10^5)
1 <= verticalCuts.length < min(w, 10^5)
1 <= horizontalCuts[i] < h
1 <= verticalCuts[i] < w
It is guaranteed that all elements in horizontalCuts are distinct.
It is guaranteed that all elements in verticalCuts are distinct.
*/

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        // Approach: Find the max gap between each horizontal cuts and vertical cuts
        const long long M=1000000007; 
        // sort horizontalCuts & verticalCuts
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        // declare the size for horizontalCuts and verticalCuts
        int m=(int)horizontalCuts.size(), n=(int)verticalCuts.size();
        // mh: storing max horizontalCuts gap ; hgap: storing horizontalCuts gap between two horizontal cuts
        // mv: storing max verticalCuts gap   ; vgap: storing verticalCuts gap between two vectical cuts
        long long mh=horizontalCuts[0], mv=verticalCuts[0], hgap, vgap;
        for(int i=1;i<m;i++) {
            // find out the max horizontalCuts gap
            hgap=horizontalCuts[i]-horizontalCuts[i-1];
            mh=max(mh,hgap);
        }
        for(int i=1;i<n;i++) {
            // find out the max verticalCuts gap
            vgap=verticalCuts[i]-verticalCuts[i-1];
            mv=max(mv,vgap);
        }
        // need to take care of the last case
        hgap=h-horizontalCuts[m-1];
        vgap=w-verticalCuts[n-1];
        mh=max(mh,hgap);
        mv=max(mv,vgap);
        // the max area is max horizontalCuts gap * max verticalCuts gap
        return (int)(mh%M*mv%M);
    }
};

// another approach is to use adjacent_difference to find the differences and store them in a vector
// find out mh and mv by using *max_element