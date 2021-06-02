# Set union 

```cpp
A | B
```

# Set intersection

```cpp
 A & B
 ```

# Set subtraction 

```
A & ~B
```

# Set negation 

```cpp
ALL_BITS ^ A or ~A
```
# Set bit 

```cpp
A |= 1 << bit
```

# Clear bit 

```cpp
A &= ~(1 << bit)
```
# Test bit 

```cpp
(A & 1 << bit) != 0
```
# Extract last bit 

```cpp
A & -A or A & ~(A - 1) or x ^ (x & (x - 1))
```
# Remove last bit 

```cpp
A & (A - 1)
```
# Get all 1-bits 

```cpp
~0
```

# Supermask Sum & Submask Sum

```
template<typename T_out, typename T_in>
vector<T_out> submask_sums(int n, const vector<T_in> &values) {
    assert(int(values.size()) == 1 << n);
    vector<T_out> dp(values.begin(), values.end());
    for (int i = 0; i < n; i++)
        for (int base = 0; base < 1 << n; base += 1 << (i + 1))
            for (int mask = base; mask < base + (1 << i); mask++)
                dp[mask + (1 << i)] += dp[mask];
    return dp;
}

template<typename T_out, typename T_in>
vector<T_out> supermask_sums(int n, vector<T_in> values) {
    reverse(values.begin(), values.end());
    vector<T_out> result = submask_sums<T_out>(n, values);
    reverse(result.begin(), result.end());
    return result;
}
```