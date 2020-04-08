# [Time Conversion](https://www.hackerrank.com/challenges/time-conversion/problem)

Given a time in 12-hour AM/PM format, convert it to military (24-hour) time.

Note: Midnight is 12:00:00AM on a 12-hour clock, and 00:00:00 on a 24-hour clock. Noon is 12:00:00PM on a 12-hour clock, and 12:00:00 on a 24-hour clock.

Sample Input
```
07:05:45PM
```

Sample Output
```
19:05:45
```

First we notice that the first two characters ``07`` will be displayed as ``19`` based on the last two characters ``PM`` which will be removed in the output. Hence, we can use ``substr`` to get these two variables first.

Take 2 characters from index 0 and convert it to an integer.
```cpp
hh=stoi(s.substr(0,2));
```

Take 2 characters from index 8 
```cpp
ap=s.substr(8,2);
```

Here it shows each character with corresponding index
```
s:07:05:45PM    
i:0123456789
```

If ``ap`` is ``AM``, there is a case that the time is ``12:00:00AM``. We need to output it as ``00:00:00``. Hence we can check if ``hh`` is ``12``, the first two characters of the output would be ``00``. Since ``ap`` is ``AM``, ``hh`` must between ``00`` to ``12``. However, we use ``stoi`` to convert it an integer. If ``hh`` is below ``10``, the leading 0 will be missing. Therefore, we need to add it back for such case.

If ``ap`` is ``PM``, similarly we add the missing leading 0 for ``hh<10`` cases. Otherwise, we can display ``hh+12``.

We need to append ``s.substr(2,6)`` to the first characters to form the answer.