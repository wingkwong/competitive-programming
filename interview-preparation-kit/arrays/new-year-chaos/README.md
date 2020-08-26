# [New Year Chaos](https://www.hackerrank.com/challenges/new-year-chaos/problem)

![image](https://user-images.githubusercontent.com/35857179/80279421-2a88a680-8730-11ea-90d7-0847027fb363.png)

Two points to bear in mind while solving this problem:

- A person can bribe the one who is sitting just in front of him. The opposite is not possible.
- A person can bribe atmost 2 different persons.

Keeping this in mind, let's have a look at testcase-1.

First case:

Current position : 5 1 2 3 7 8 6 4
Initial position : 1 2 3 4 5 6 7 8
In the first test, the person-5 has occupied 1st seat. That means he has to bribe 4 persons in front of him to reach on the 1st seat So he violated the second rule here. So that answer is "Too chaotic" without further speculation.

```cpp
for(int i=q.size()-1;i>=0;i--){
    if(q[i]-(i+1)>2){
        cout << "Too chaotic" << "\n";
        return;
    }
// ...
}
```

Second case:

Current position : 1 2 5 3 7 8 6 4
Initial position : 1 2 3 4 5 6 7 8
So how did person-4 occupy at position 8? As per the rules, it's not possible for person-4 to bribe persons who are sitting behind him. Instead person 5, 6, 7 & 8 bribed person-4 as he is sitting in front of them. Here is the trasition from initial position to the current position.

1 2 3 4 5 6 7 8  : 0 swap (initial)
1 2 3 5 4 6 7 8  : 1 swap (5 and 4)
1 2 3 5 6 4 7 8  : 1 swap (6 and 4)
1 2 3 5 6 7 4 8  : 1 swap (7 and 4)
1 2 3 5 6 7 8 4  : 1 swap (8 and 4)
1 2 5 3 6 7 8 4  : 1 swap (5 and 3)
1 2 5 3 7 6 8 4  : 1 swap (7 and 6)
1 2 5 3 7 8 6 4  : 1 swap (8 and 6)
Obviously no person violated the second rule here. Hence the output is minimum number of swaps 7.

```cpp
for(int i=q.size()-1;i>=0;i--){
    // ...
    for(int j=max(q[i]-2,0);j<i;j++){
        if(q[j]>q[i]) ans++;
    }
}
```

We do not need to sort for this question. Instead, we count how many times ``q[i]`` is being bribed. If a number which is greater than ``q[i]`` can be found from ``max(q[i-2],0)`` to current ``i``, that means this number has bribed ``q[i]``. Since ``q[i]-2`` can be negative, we need to safeguard it by setting it to 0 for this case.