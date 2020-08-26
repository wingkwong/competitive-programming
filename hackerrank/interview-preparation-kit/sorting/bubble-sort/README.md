# [Bubble Sort](https://www.hackerrank.com/challenges/ctci-bubble-sort/problem)

![image](https://user-images.githubusercontent.com/35857179/81392453-4b4df480-9151-11ea-83f8-d776786c00f4.png)

A standard bubble sort algorithm
```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
        if (a[j] > a[j + 1]) {
            swap(a[j], a[j + 1]);
        }
    }
}
```

However, we can further optimize to skip the unnecessary cases
```cpp
bool swapped;
for (int i = 0; i < n; i++) {
    swapped = false;
    for (int j = 0; j < n - 1; j++) {
        if (a[j] > a[j + 1]) {
            swap(a[j], a[j + 1]);
            swapped=true;
        }
    }
    if(!swapped) break;
}
```