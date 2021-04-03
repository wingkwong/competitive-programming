```cpp
vector<int> v;
int n = (int)nums.size();
for (int i = 0; i < n; i++) {
  for (int j = i, sum = 0; j < n; j++) {
    sum += nums[j];
    v.emplace_back(sum);
  }
}
```