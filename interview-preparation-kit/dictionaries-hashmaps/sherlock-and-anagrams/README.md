# [Sherlock and Anagrams](https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem)

![image](https://user-images.githubusercontent.com/35857179/80808780-dcbde380-8bf2-11ea-8ea7-aeec9a7c4eba.png)

Sample Input
```
2
abba
abcd
```

Sample Output
```
4
0
```

Traverse the string from ``i...n-1`` and ``j...n`` to take the sub string ``string[i:j]``. Sort it and check if the string is in the map. If it exists, increase ans by ``m[str]`` and increase ``m[str]`` by 1. If not, simple set it to one.

Final Solution
```cpp
int sherlockAndAnagrams(string s) {
    int ans=0;
    unordered_map<string, int> m;
    for(int i=0;i<s.size();i++){
        for(int j=0;j+i<=s.size();j++){
            string str = s.substr(i,j);
            if(str.size()){
                sort(str.begin(),str.end());
                if(m.count(str)) {
                    ans+=m[str];
                    m[str]++;
                }
                else m[str]=1;
            }
        }
    }
    return ans;
}
```