## Primes

check if n is a prime number

```cpp
bool isPrime(LL n) {
   for(LL i = 2;i * i <= n; i++) {
      if(n % i == 0) return false;
   }
   return true;
}
```

check how many prime umbers less than a non-negative number n

```cpp
// using Sieve of Eratosthenes
int cntPrime(int n){
  if(n<2) return 0;
  bool isPrime[n];
  int cnt=0;
  for(int i=2;i<n;i++) isPrime[i]=true;
  for(int i=2;i*i<n;i++){
      if(isPrime[i]) {
          for(int j=i*i;j<n;j+=i){
              isPrime[j] = false;
          }
      }
  }
  for(int i=2;i<n;i++) {
      if(isPrime[i]) cnt++;
  }
  return cnt;
}
```

## Pow with mod

```cpp
typedef long long ll; 

ll modpow(ll base, ll exp, ll mod) {
  base%=mod;
  ll res=1;
  while(exp>0) {
    if (exp&1) res=(res*base)%mod;
    base=(base*base)%mod;
    exp>>=1;
  }
  return res;
}
```