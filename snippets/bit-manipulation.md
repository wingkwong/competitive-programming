# Set union 

```cpp
A | B
```

# Set intersection

```cpp
 A & B
 ```

# Set subtraction 

```
A & ~B
```

# Set negation 

```cpp
ALL_BITS ^ A or ~A
```
# Set bit 

```cpp
A |= 1 << bit
```

# Clear bit 

```cpp
A &= ~(1 << bit)
```
# Test bit 

```cpp
(A & 1 << bit) != 0
```
# Extract last bit 

```cpp
A & -A or A & ~(A - 1) or x ^ (x & (x - 1))
```
# Remove last bit 

```cpp
A & (A - 1)
```
# Get all 1-bits 

```cpp
~0
```