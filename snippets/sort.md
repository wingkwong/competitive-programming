## Bubble Sort

```cpp
bool swapped;
for(int i=0;i<n;i++){
    swapped = false;
    for(int j=0;j<n-1;j++){
        if(a[j]>a[j+1]) {
            swap(a[j], a[j+1]);
            swapped = true;
        }
    }
    if(!swapped) break;
}
```

## Partial Sort:

```cpp
// we dont need to sort all of them, just sort the first k 
partial_sort(arr.begin(),arr.begin()+k,arr.end(),[m](int a, int b){
  // A value arr[i] is said to be stronger than a value arr[j] if |arr[i] - m| > |arr[j] - m|
  // If |arr[i] - m| == |arr[j] - m|, then arr[i] is said to be stronger than arr[j] if arr[i] > arr[j]
  return (abs(a-m) > abs(b-m)) || (abs(a-m) == abs(b-m) && a>b);
} );
// only show first k
arr.resize(k);
```