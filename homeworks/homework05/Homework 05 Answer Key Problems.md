# Homework 5 — Answer Key

---

## Problem 2 — Correct insertion sort trace

Comparison = every evaluation of `sample_array[inner] > held_value`, including the false one that ends the inner loop.

| Pass | Held | Array after the pass | Shifts | Comparisons this pass | Running total |
|---|---|---|---|---|---|
| 1 | 17 | `17 22 10 84 99  7 36  8 15` | 1 | 1 | 1 |
| 2 | 10 | `10 17 22 84 99  7 36  8 15` | 2 | 2 | 3 |
| 3 | 84 | `10 17 22 84 99  7 36  8 15` | 0 | 1 | 4 |
| 4 | 99 | `10 17 22 84 99  7 36  8 15` | 0 | 1 | 5 |
| 5 | 7 | ` 7 10 17 22 84 99 36  8 15` | 5 | 5 | 10 |
| 6 | 36 | ` 7 10 17 22 36 84 99  8 15` | 2 | 3 | 13 |
| 7 | 8 | ` 7  8 10 17 22 36 84 99 15` | 6 | 7 | 20 |
| 8 | 15 | ` 7  8 10 15 17 22 36 84 99` | 5 | 6 | 26 |

**2-b) Total comparisons = 26**

**2-c)** Passes **3** (held 84) and **4** (held 99). In both cases the held value was already larger than every value in the sorted part, so the first comparison failed immediately and nothing shifted. These are the passes where insertion sort does its least work, which is why an already-sorted array is its best case.

### Best and worst case (for discussion, not graded)

- Already sorted `{7 8 10 15 17 22 36 84 99}` → **8 comparisons** = n − 1
- Reverse sorted `{99 84 36 22 17 15 10 8 7}` → **36 comparisons** = n(n−1)/2

---

## Problem 3 — Missing held copy

**3-a)** The reference saves `sample_array[outer]` into `held_value` before the loop. This version compares against and assigns from `sample_array[outer]` directly, with no saved copy.

**3-b)** Trace:

| Pass | Array after the pass |
|---|---|
| 1 | `22 22 10 84 99  7 36  8 15` |
| 2 | `22 22 22 84 99  7 36  8 15` |
| 3 | `22 22 22 84 99  7 36  8 15` |
| 4 | `22 22 22 84 99  7 36  8 15` |
| 5 | `22 22 22 84 99 99 36  8 15` |
| 6 | `22 22 22 84 99 99 99  8 15` |
| 7 | `22 22 22 84 99 99 99 99 15` |
| 8 | `22 22 22 84 99 99 99 99 99` |

Final: `22 22 22 84 99 99 99 99 99`

**3-c)** The fault appears on **pass 1**. The array becomes `22 22 ...`, which contains a second 22 that was not in the original. The value **17** has been lost.

**3-d)** On pass 1, `outer` is 1 and `inner` is 0. The first shift executes `sample_array[inner + 1] = sample_array[inner]`, which is `sample_array[1] = sample_array[0]` — and `sample_array[1]` is the very element the loop is comparing against. The 17 is overwritten by 22 before it is ever placed, so the final assignment stores 22 a second time instead of restoring 17. The value being inserted must be copied out before any shifting begins, because shifting can land on the position it came from.

---

## Problem 4 — Missing `inner >= 0` guard

**4-a)** The `while` condition has lost the `inner >= 0` test; it checks only `sample_array[inner] > held_value`.

**4-b)** The first pass where the inner loop shifts all the way to the left end is **pass 1** (held 17). After the single shift, `inner` becomes **−1**, and the loop condition is evaluated again as `sample_array[-1] > held_value`.

**4-c)** `sample_array[0]` is at `0x7ffd4a2b1c50`. Index −1 is four bytes lower:

```
0x7ffd4a2b1c50 − 0x4 = 0x7ffd4a2b1c4c
```

**4-d)** `sample_array[-1]` is not part of the array, so what it holds is whatever the program happens to have placed at that address — another local variable, saved register state, or padding. The value is not specified by C and can change between compilers, optimization levels, and even runs. If that memory happens to hold a value less than or equal to the held value, the loop stops and the sort appears to work. If it holds a larger value, the loop keeps walking backward through memory that does not belong to it. 

---

## Problem 5 — Outer loop starts at 0

**5-a)** The outer loop begins at `outer = 0` instead of `outer = 1`.

**5-b)** On the first pass, `outer` is 0, so `held_value = sample_array[0]` which is 22, and `inner = outer - 1 = -1`. The `while` condition evaluates `inner >= 0` first, which is false, so **the loop body does not execute** and `sample_array[-1]` is never read — the `&&` short-circuits. The final assignment is `sample_array[inner + 1] = held_value`, which is `sample_array[0] = 22`, storing 22 back where it already was. Array unchanged: `22 17 10 84 99 7 36 8 15`.

**5-c)** **This version sorts correctly.** Final output is `7 8 10 15 17 22 36 84 99`, identical to the reference.

Accept any of the following as a full-credit response:
- Nothing needs to be fixed; it is correct.
- It performs one unnecessary pass that accomplishes nothing, so starting at 1 is clearer about intent.
- The correctness depends entirely on `&&` short-circuiting before `sample_array[inner]` is evaluated — which is guaranteed by C, but worth knowing that it is what makes this safe.

---

## Problem 6 — Binary search traces

Sorted array: `{7 8 10 15 17 22 36 84 99}`

**6-a) Search for 15:**

| Iteration | minimum | maximum | midpoint | value at midpoint |
|---|---|---|---|---|
| 1 | 0 | 8 | 4 | 17 |
| 2 | 0 | 3 | 1 | 8 |
| 3 | 2 | 3 | 2 | 10 |
| 4 | 3 | 3 | 3 | 15 |

Returns **3** after **4 iterations**.

**6-b) Search for 50:**

| Iteration | minimum | maximum | midpoint | value at midpoint |
|---|---|---|---|---|
| 1 | 0 | 8 | 4 | 17 |
| 2 | 5 | 8 | 6 | 36 |
| 3 | 7 | 8 | 7 | 84 |

Returns **−1** after **3 iterations**. (After iteration 3, `maximum` becomes 6 while `minimum` is 7, so the loop exits.)

### Additional searches in the required test run

| Value | Result | Iterations |
|---|---|---|
| 15 | index 3 | 4 |
| 99 | index 8 | 4 |
| 7 | index 0 | 3 |
| 50 | −1 | 3 |