# [Luck Balance](https://www.hackerrank.com/challenges/luck-balance/problem)

![image](https://user-images.githubusercontent.com/35857179/79744796-97b7c880-8339-11ea-847a-4bca21d531ea.png)

We sort the array in a descending order and assume Lena loses all non-important competition so that we can have maximum luck. If it it an important contest, we add ``T[i]`` to her luck and deduct ``k`` by 1 because losing a contest means increasing her luck. The more ``L[i]`` it provides , the more luck she will get. If she cannot lose anymore, deduct the luck by ``T[i]``. 

Final Solution
```cpp
int n,k,ans=0;

int main()  
{ 
    FAST_INP;
    cin>>n>>k;
    vector<vector<int>> c(n);
    for (int i=0; i<n; i++) {
        c[i].resize(2);
        for (int j = 0; j < 2; j++) cin >> c[i][j];
    }
    sort(c.rbegin(),c.rend());
    REP(i,n){
        if(!c[i][1]){
            // not important 
            ans+=c[i][0];
        }else{
            if(k){
                ans+=c[i][0]; // lose
                k--;
            }
            else ans-=c[i][0];    // win
        }
    }
    cout << ans;
    return 0; 
} 
```