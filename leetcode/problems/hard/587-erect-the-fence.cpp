/*
Erect the Fence
https://leetcode.com/problems/erect-the-fence/

There are some trees, where each tree is represented by (x,y) coordinate in a two-dimensional garden. Your job is to fence the entire garden using the minimum length of rope as it is expensive. The garden is well fenced only if all the trees are enclosed. Your task is to help find the coordinates of trees which are exactly located on the fence perimeter.

Example 1:

Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
Explanation:

Example 2:

Input: [[1,2],[2,2],[4,2]]
Output: [[1,2],[2,2],[4,2]]
Explanation:

Even you only have trees in a line, you need to use rope to enclose them. 
 

Note:

All trees should be enclosed together. You cannot cut the rope to enclose trees that will separate them in more than one group.
All input integers will range from 0 to 100.
The garden has at least one tree.
All coordinates are distinct.
Input points have NO order. No order required for output.
input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

*/

class Solution {
public:
    typedef long long coord_t;  // coordinate type
    typedef long long coord2_t;  // must be big enough to hold 2 * max(|coordinate|) ^ 2

    struct Point {
      coord_t x, y;
    };

    static bool cmp(Point &p1, Point &p2) {
      return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
    }

    static bool equ(Point &p1, Point &p2) { return p1.x == p2.x && p1.y == p2.y; }

    // 3D cross product of OA and OB vectors, (i.e z-component of their "2D" cross
    // product, but remember that it is not defined in "2D").
    // Returns a positive value, if OAB makes a counter-clockwise turn,
    // negative for clockwise turn, and zero if the points are collinear.
    coord2_t cross(const Point &O, const Point &A, const Point &B) {
      return (coord_t)(A.x - O.x) * (coord2_t)(B.y - O.y) -
             (coord_t)(A.y - O.y) * (coord2_t)(B.x - O.x);
    }

    // Returns a list of points on the convex hull in counter-clockwise order.
    // Note: the last point in the returned list is the same as the first one.
    vector<Point> convex_hull(vector<Point> P, int to_sort = 1, int remove_depulicate = 1) {
      size_t n = P.size(), k = 0;
      if (n <= 3) return P;
      vector<Point> H(2 * n);

      // Sort points lexicographically
      sort(P.begin(), P.end(), cmp);

      // Build lower hull
      for (int i = 0; i < n; i++) {
        while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) < 0) k--;
        H[k++] = P[i];
      }

      // Build upper hull
      for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && cross(H[k - 2], H[k - 1], P[i]) < 0) k--;
        H[k++] = P[i];
      }

      // Resize, Sort and Remove duplicates
      H.resize(k);
      if(to_sort) sort(H.begin(), H.end(), cmp);
      if(remove_depulicate) H.erase(unique(H.begin(), H.end(), equ), H.end());
      return H;
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        int n = (int) points.size();
        // Constrcut Point
        vector<Point> p(n);
        for(int i = 0; i < n; i++) p[i].x = points[i][0], p[i].y = points[i][1];
        // Convex Hull
        vector<Point> c = convex_hull(p);
        // Constrcut ans
        vector<vector<int>> ans;
        for(int i = 0; i < (int) c.size(); i++) ans.push_back({(int) c[i].x, (int) c[i].y});
        return ans;
    }
};