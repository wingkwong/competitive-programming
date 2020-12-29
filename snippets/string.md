## Z Function 

```cpp
// Z Function - template starts
template <typename T>
vector<int> z_function(int n, const T &s) {
  vector<int> z(n, n);
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    z[i] = (i > r ? 0 : min(r - i + 1, z[i - l]));
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}

template <typename T>
vector<int> z_function(const T &s) {
  return z_function((int) s.size(), s);
}
// Z Function - template ends
```

## Booth's Algorithm

```cpp
int booth_function(string s) {
  s = s + s;
  int n = SIZE(s);
  // failure function
  vi f(n, -1);
  // least roation of string found so far
  int k = 0; 
  FOR(j, 1, n) {
    char sj = s[j];
    int i = f[j - k - 1];
    while(i != -1 && sj != s[k + i + 1]) {
      if(sj < s[k + i + 1]) k = j - i - 1;
      i = f[i];
    }
    if(sj != s[k + i + 1]) {
      // i == -1
      if(sj < s[k]) k = j;
      f[j - k] = -1;
    } else {
      f[j - k] = i + 1;
    }
  }
  return k;
}
```

### Usage: determine the lexicographically minimal rotation of a string

```cpp
void solve() {
  string s; cin >> s;
  int n = SIZE(s);
  int k = booth_function(s);
  s = s + s;
  OUT(s.substr(k, n));
}
```
