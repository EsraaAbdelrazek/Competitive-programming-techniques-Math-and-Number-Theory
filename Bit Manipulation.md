# Bit Manipulation

## 1. Checking if a Number is Odd or Even

**Formula:**

- `n & 1 == 1` → Odd
- `n & 1 == 0` → Even

```python
def is_odd(n):
    return (n & 1) == 1

print(is_odd(5))  # True
print(is_odd(6))  # False

```

why ?  

- Binary of **even** numbers ends with `0`.
- Binary of **odd** numbers ends with `1`.
- `&` is a **bitwise AND**. So `num & 1` checks the **last bit** (least significant bit).
    - If last bit is `1` → **Odd**
    - If last bit is `0` → **Even**
    

## **2. Checking if the `k`th Bit is Set (1)**

**Formula:** `(n & (1 << k)) != 0`

This checks if the k-th bit of `n` is `1`.

```python
def is_kth_bit_set(n, k):
    return (n & (1 << k)) != 0

print(is_kth_bit_set(5, 0))  # True (5 = 101, LSB is set)
print(is_kth_bit_set(5, 1))  # False
print(is_kth_bit_set(5, 2))  # True

```

### Why ?

- `1 << i` creates a mask with only the `i`th bit = 1.
- `n & (1 << i)` will return a non-zero value **only if the bit is set**.

```python

n = 10  # binary: 1010
i = 1   # we check 2nd bit from right

mask = 1 << 1 = 0010

n & 0010 → 1010 & 0010 = 0010 → Bit is set 

```

## 3. Setting the `k`-th Bit

**Formula:** `n | (1 << k)`

Sets the `k`-th bit to `1`.

```python
def set_kth_bit(n, k):
    return n | (1 << k)

print(set_kth_bit(5, 1))  # 7 (0111)

```

### Why ?

- `1 << i` creates a number where only the `i`th bit is 1.
- `|= (OR)` with that sets the `i`th bit of `n` to 1.

```python

n = 8         # binary: 1000
i = 1
mask = 1 << 1 → 0010

n |= 0010 → 1000 | 0010 = 1010 → 10

```

### **4. Clearing the `k`th Bit**

**Formula:** `n & ~(1 << k)`

Clears the `k`-th bit (sets it to `0`).

```python
def clear_kth_bit(n, k):
    return n & ~(1 << k)

print(clear_kth_bit(7, 1))  # 5 (0101)

```

### Why

- `1 << i` makes a mask like `00010000`
- `~` flips all bits: now it's `11101111`
- `&=` keeps all bits of `n`, except the `i`th bit → sets that one to 0.

```python

n = 14  # binary: 1110
i = 1

mask = ~(1 << 1) = ~0010 = 1101

n &= 1101 → 1110 & 1101 = 1100 → 12

```

## 5. Counting the Number of Set Bits

```python
def count_set_bits(n):
    return bin(n).count('1')

print(count_set_bits(7))  # Output: 3 (111)

```

### **Counting the Number of Set Bits using `while n: n &= (n - 1)`**

This method efficiently counts the number of `1`s in a binary number.

```python
def count_set_bits(n):
    count = 0
    while n:
        n &= (n - 1)  # Removes the rightmost set bit
        count += 1
    return count

# Test Cases
print(count_set_bits(13))  # 3 (Binary: 1101)
print(count_set_bits(7))   # 3 (Binary: 0111)
print(count_set_bits(32))  # 1 (Binary: 100000)

```

## 6. Checking if a Number is a Power of Two

**Formula:** `n & (n - 1) == 0`

```python
def is_power_of_two(n):
    return n > 0 and (n & (n - 1)) == 0

print(is_power_of_two(8))  # True (1000)
print(is_power_of_two(10)) # False (1010)
'''
  1000   (8)
& 0111   (7)
-------
  0000 --> ok 
'''

'''
  1010   (10)
& 1001   (9)
-------
  1000-- >. No 

'''

```

## Why It Works:

This trick works **because**:

- A power of two has a single `1` in its binary.
- Subtracting 1 flips that `1` to `0`, and turns all bits after it to `1`.
- So, `n & (n - 1)` removes the only `1` bit, making the result `0`.

## 7. Swapping Two Numbers Without Using a Third Variable

```python
a, b = 5, 3
a = a ^ b
b = a ^ b
a = a ^ b
print(a, b)  # Output: 3, 5

```

### **8. Checking if a Number is a Power of Two using `n & (n - 1) == 0`**

A number is a power of two if it has exactly **one set bit** in its binary representation.

```python
def is_power_of_two(n):
    return n > 0 and (n & (n - 1)) == 0

# Test Cases
print(is_power_of_two(1))  # True  (2^0)
print(is_power_of_two(2))  # True  (2^1)
print(is_power_of_two(4))  # True  (2^2)
print(is_power_of_two(8))  # True  (2^3)
print(is_power_of_two(10)) # False (Not a power of two)

```

## Tips and Tricks

### Problem 1: Find the Unique Number (XOR Trick)

Given an array where every number appears **twice except one**, find the unique number.

```python
def find_unique(arr):
    result = 0
    for num in arr:
        result ^= num  # XOR cancels out duplicate numbers
    return result

print(find_unique([2, 3, 5, 3, 2]))  # Output: 5

```

## Problem 2: Find Two Unique Numbers

Given an array where every number appears **twice except two**, find the two unique numbers.

**Solution:**

1. XOR all elements to get `x ^ y`.
2. Find the rightmost set bit to separate numbers into two groups.
3. XOR elements in each group to find `x` and `y`.

```python
def find_two_uniques(arr):
    xor_all = 0
    for num in arr:
        xor_all ^= num
    
    # Find rightmost set bit
    rightmost_bit = xor_all & -xor_all

    x, y = 0, 0
    for num in arr:
        if num & rightmost_bit:
            x ^= num
        else:
            y ^= num
    return x, y

print(find_two_uniques([1, 2, 3, 2, 1, 4]))  # Output: (3, 4)

```

## Left shifting and Right Shifting

Left shift : Each left shift multiplies the number by `2`.

> N << i == N * (2 ^ i )
> 

Right shift : Each right shift divides the number by `2` (ignores remainder for integers).

> N << i == N / (2 ^ i )
> 

## Multiply or divide by powers of 2

```python
# Multiply by 2: n << 1
# Divide by 2:   n >> 1
n = 5  # binary: 101

n << 1 = 1010 → 10  (5 * 2)
n >> 1 = 10   → 2   (5 // 2)

```

### Why it works

- `n << 1` means "shift bits left" → doubles the number (×2)
- `n >> 1` means "shift bits right" → halves the number (//2)

## Toggle (flip) the **ith bit**

```python
n ^= (1 << i)
```

### Why it works:

- `^` is XOR. It flips bits:
    - If bit is 0 → becomes 1
    - If bit is 1 → becomes 0

### Example:

```python
n = 10  # binary: 1010
i = 1

mask = 1 << 1 = 0010

n ^= 0010 → 1010 ^ 0010 = 1000 → 8

```
