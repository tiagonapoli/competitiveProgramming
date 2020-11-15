- [Inequalities](#inequalities)
  - [Modulus](#modulus)
    - [`|x| + |y| = max{|x + y|, |x - y|}`](#x--y--maxx--y-x---y)
  - [Tree](#tree)
    - [d(b,v) <= d(b,a) + d(a,v)](#dbv--dba--dav)

# Inequalities

## Modulus

### `|x| + |y| = max{|x + y|, |x - y|}`

## Tree

### d(b,v) <= d(b,a) + d(a,v)

# Properties

### ka % kb = k * (a % b)

```
r1 = ka % kb => ka = x * kb + r1, r1 < kb
r = a % b => a = y * b + r, r < b
```
There exists only one pair `r1`, `x` that satisfies the first equation,
and we can check that `r1 = k*r` and `x = y` satisfies.

# Misc

## Target position array

Def: Given an array `X`, the target position array is a permutation `P` that
describes de desired position for each index `X` so that, for each index `i` of
`X`, `P[i]` is the desired index for that element. Example:

```
X = [2, 9, 3, 5]
P = [0, 3, 1, 2]
The desired X is: [2, 3, 5, 9]
```

Usages:

- Sorting `P` is equivalent to reordering the elements in `X` in the desired positions, so we can count the necessary inversions to get the reordering in `X` by counting the inversions when sorting `P`.
  - [1430E - String reversal](http://codeforces.com/contest/1430/problem/E)
