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
  return z_function((int)s.size(), s);
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
    while (i != -1 && sj != s[k + i + 1]) {
      if (sj < s[k + i + 1]) k = j - i - 1;
      i = f[i];
    }
    if (sj != s[k + i + 1]) {
      // i == -1
      if (sj < s[k]) k = j;
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
  string s;
  cin >> s;
  int n = SIZE(s);
  int k = booth_function(s);
  s = s + s;
  cout << s.substr(k, n) << endl;
}
```

## Manacher's Algorithm

```cpp
string manacher(string s) {
  int n = (int)s.size();
  // d1[i]: the number of palindromes accordingly with odd lengths with centers in the position i.
  // d2[i]: the number of palindromes accordingly with even lengths with centers in the position i.
  vector<int> d1(n), d2(n);
  int l1 = 0, r1 = -1, l2 = 0, r2 = -1, mx_len = 0, start = 0;
  for (int i = 0; i < n; i++) {
    // ----------------------
    // calculate d1[i]
    // ----------------------
    int k = (i > r1) ? 1 : min(d1[l1 + r1 - i], r1 - i + 1);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) k++;
    d1[i] = k--;
    if (i + k > r1) l1 = i - k, r1 = i + k;
    if (d1[i] * 2 > mx_len) start = i - k, mx_len = d1[i] * 2 - 1;
    // ----------------------
    // calculate d2[i]
    // ----------------------
    k = (i > r2) ? 0 : min(d2[l2 + r2 - i + 1], r2 - i + 1);
    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) k++;
    d2[i] = k--;
    if (i + k > r2) l2 = i - k - 1, r2 = i + k;
    if (d2[i] * 2 > mx_len) start = i - k - 1, mx_len = d2[i] * 2;
  }
  // return the longest palindrome
  return s.substr(start, mx_len);
}
```

### Usage: find the longest palindrome substring

```cpp
string s; cin >> s;
string lps = manacher(s);
```

```cpp
int manacher(string s) {
  int n = (int) s.size();
  // d1[i]: the number of palindromes accordingly with odd lengths with centers in the position i.
  // d2[i]: the number of palindromes accordingly with even lengths with centers in the position i. 
  vector<int> d1(n), d2(n);
  int l1 = 0, r1 = -1, l2 = 0, r2 = -1, mx_len = 0, start = 0;
  for (int i = 0; i < n; i++) {
    // ----------------------
    // calculate d1[i]
    // ----------------------
    int k = (i > r1) ? 1 : min(d1[l1 + r1 - i], r1 - i + 1);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) k++;
    d1[i] = k--;
    if (i + k > r1) l1 = i - k, r1 = i + k;
    if (d1[i] * 2 > mx_len) start = i - k, mx_len = d1[i] * 2 - 1;
    // ----------------------
    // calculate d2[i]
    // ----------------------
    k = (i > r2) ? 0 : min(d2[l2 + r2 - i + 1], r2 - i + 1);
    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) k++;
    d2[i] = k--;
    if (i + k > r2) l2 = i - k - 1, r2 = i + k;
    if (d2[i] * 2 > mx_len) start = i - k - 1, mx_len = d2[i] * 2;
  }
  // count how many palindromic substrings in the given string
  int cnt = 0;
  for (int i = 0; i < n; i++) cnt += d1[i] + d2[i];
  return cnt;
}
```

### Usage: count how many palindromic substrings in the given string

```cpp
string s; cin >> s;
int cnt = manacher(s);
```

## Split string to vector

```cpp
vector<string> split(string str, char delim) {
    string line;
    vector<string> res;
    stringstream ss(str);
    while(getline(ss, line, delim)) res.push_back(line);
    return res;
}
```

## Prefix Function

```cpp
vector<int> prefix_function(string s) {
    int n = (int) s.size();
    // p[i] : the length of the longest proper prefix of the substring s[0 ... i] which is also a suffix of this substring
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) j = p[j - 1];
        if (s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}
```

## Check Palindrom

### Long + Efficient

```cpp
bool isPalindrome(const string& s) {
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1])
            return false;
    }

    return true;
}
```
### Shorter, but not efficient

```cpp
bool isPalindrome(const string& s) {
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}
```

### Shortest, but not efficient

```cpp
bool isPalindrome(const string& s) {
    return s == string(s.rbegin(), s.rend());
}
```

### Shortest, but efficient

```cpp
bool isPalindrome(const string &s) {
    return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
}
```