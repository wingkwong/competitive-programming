# [Migratory Birds](https://www.hackerrank.com/challenges/migratory-birds/problem)

You have been asked to help study the population of birds migrating across the continent. Each type of bird you are interested in will be identified by an integer value. Each time a particular kind of bird is spotted, its id number will be added to your array of sightings. You would like to be able to find out which type of bird is most common given a list of sightings. Your task is to print the type number of that bird and if two or more types of birds are equally common, choose the type with the smallest ID number.

For example, assume your bird sightings are of types arr=[1,1,2,2,3]. There are two each of types 1 and 2, and one sighting of type 3. Pick the lower of the two types seen twice: type 1.

Sample Input
```
6
1 4 4 4 5 3
```

Sample Output
```
4
```

Loop through the array to count each type. 
```cpp
cin >> v;
a[v-1]++; // 0-base
```

We need a variable ``max`` to store the maximum value.
```cpp
int max=0;
if(a[v-1]>=max) max=a[v-1];
```

If several types have the same frequency, show the lowest one. Therefore, we need another variable ``id`` and update it only ``max`` is updated or the input value is less than ``id``.

```cpp
if(a[v-1]>max||v<id) id=v;
```

```
6
1 4 4 4 5 3
-----------------------------
1: 1
2: 0
3: 1
4: 3
5: 1
-----------------------------
1 - max: 1, id:1
4 - max: 1, id:1
4 - max: 2, id:4
4 - max: 3, id:4
5 - max: 3, id:4
3 - max: 3, id:4
-----------------------------
ans = 4
```