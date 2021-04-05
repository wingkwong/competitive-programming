# Pseudo-code 

```
Input: a list P of points in the plane.

Precondition: There must be at least 3 points.

Sort the points of P by x-coordinate (in case of a tie, sort by y-coordinate).

Initialize U and L as empty lists.
The lists will hold the vertices of upper and lower hulls respectively.

for i = 1, 2, ..., n:
    while L contains at least two points and the sequence of last two points
            of L and the point P[i] does not make a counter-clockwise turn:
        remove the last point from L
    append P[i] to L

for i = n, n-1, ..., 1:
    while U contains at least two points and the sequence of last two points
            of U and the point P[i] does not make a counter-clockwise turn:
        remove the last point from U
    append P[i] to U

Remove the last point of each list (it's the same as the first point of the other list).
Concatenate L and U to obtain the convex hull of P.
Points in the result will be listed in counter-clockwise order.
```


# Andrew's Monotone Chain 2D Convex Hull

- Asymptotic complexity: O(n log n).
- Practical performance: 0.5-1.0 seconds for n=1000000 on a 1GHz machine.

```cpp
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

  // Precondition: There must be at least 3 points.
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
```

### Usage:

```cpp
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
```


# Reference 

- [Monotone chain](https://algorithmist.com/wiki/Monotone_chain_convex_hull.cpp)