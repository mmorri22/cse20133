# Homework 6 — Answer Key

---

# Part 1 — Typed Problems

## Problem 1 — Initializing Arrays on Computing Hardware

### Why the output behaves that way

`int prob_array[ROW][COL];` is declared with no initializer, so its four elements hold whatever bytes already occupied that stack location. `runArray` uses `+=`, which reads the existing value before adding to it, so each run accumulates onto a different pile of leftover garbage — and the second call accumulates on top of the first.

### The one-line fix

```c
int prob_array[ROW][COL] = {0};
```

Verified under `-std=c2x -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror`:

```
0 1 2 3
0 2 4 6
```

**Also accept:** `= { {0,0,0,0} }`, or an explicit nested loop that zeroes the array before the first `runArray` call.

---

## Problem 2 — Deriving Backtracking by Hand [250 pts]

Puzzle:

```
1 0 0 4
0 0 3 1
0 4 0 3
3 1 4 2
```

Conventions matching the assignment: `all four values failed -> return failure` occupies its own numbered step, and a rejection names the conflicting cell that comes first in row-major order.

### 2-a) Steps 14 through completion

```
step   depth   cell     try   result
  14     5     (1,0)    1     rejected, 1 found at (0, 0)
  15     5     (1,0)    2     VALID   -> place 2, recurse deeper
  16     6     (1,1)    1     rejected, 1 found at (0, 0)
  17     6     (1,1)    2     rejected, 2 found at (1, 0)
  18     6     (1,1)    3     rejected, 3 found at (0, 1)
  19     6     (1,1)    4     rejected, 4 found at (2, 1)
  20     6     (1,1)          all four values failed -> return failure
  21     5     (1,0)          UNDO the 2 (reset to 0), continue the loop
  22     5     (1,0)    3     rejected, 3 found at (0, 1)
  23     5     (1,0)    4     VALID   -> place 4, recurse deeper
  24     6     (1,1)    1     rejected, 1 found at (0, 0)
  25     6     (1,1)    2     VALID   -> place 2, recurse deeper
  26     7     (1,2)    X     contains a valid integer (3), recurse deeper
  27     8     (1,3)    X     contains a valid integer (1), recurse deeper
  28     9     (2,0)    1     rejected, 1 found at (0, 0)
  29     9     (2,0)    2     VALID   -> place 2, recurse deeper
  30    10     (2,1)    X     contains a valid integer (4), recurse deeper
  31    11     (2,2)    1     VALID   -> place 1, recurse deeper
  32    12     (2,3)    X     contains a valid integer (3), recurse deeper
  33    13     (3,0)    X     contains a valid integer (3), recurse deeper
  34    14     (3,1)    X     contains a valid integer (1), recurse deeper
  35    15     (3,2)    X     contains a valid integer (4), recurse deeper
  36    16     (3,3)    X     contains a valid integer (2), recurse deeper
                            all sixteen cells filled -> return success
```

**Final step number: 36.** Two undos in the whole trace — step 9 (given) and step 21.


### 2-b) The completed grid

```
1 3 2 4
4 2 3 1
2 4 1 3
3 1 4 2
```

### 2-c) The undo removed

```
step   depth   cell     try   result
   1     1     (0,0)    X     contains a valid integer (1), recurse deeper
   2     2     (0,1)    1     rejected, 1 found at (0, 0)
   3     2     (0,1)    2     VALID   -> place 2, recurse deeper
   4     3     (0,2)    1     rejected, 1 found at (0, 0)
   5     3     (0,2)    2     rejected, 2 found at (0, 1)
   6     3     (0,2)    3     rejected, 3 found at (1, 2)
   7     3     (0,2)    4     rejected, 4 found at (0, 3)
   8     3     (0,2)          all four values failed -> return failure
   9     2     (0,1)          NO UNDO - the 2 stays at (0,1), continue the loop
  10     2     (0,1)    3     rejected, cell already contains 2
  11     2     (0,1)    4     rejected, cell already contains 2
  12     2     (0,1)          all four values failed -> return failure
```

The solver returns **failure after 12 steps**, against 36 steps and a correct answer for the version that undoes.

**Board when it gives up** — only one cell ever changed:

```
1 2 0 4
0 0 3 1
0 4 0 3
3 1 4 2
```

**Value left at (0,1): 2.**

**What the solver reports:** that the puzzle has no solution — on a puzzle it solves correctly when the undo is present.

**Why.** Steps 4 through 8 established that nothing fits at (0,2) while a 2 sits at (0,1), which is a proof that the 2 is wrong. Leaving it there means every later decision is made about a board that cannot lead anywhere.

At step 10 the solver tries 3 at (0,1) — the next candidate, and the one that is actually correct. It is rejected, but **not because 3 conflicts with anything.** It is rejected because `check_guess` tests whether the target cell is empty before anything else, and (0,1) still holds the solver's own abandoned guess. The solver has locked itself out of the cell it is trying to fill. Step 11 fails the same way.

With candidates 3 and 4 refused on those grounds, the loop at depth 2 is exhausted and returns failure at step 12. The call above it, at depth 1, is the pre-filled cell (0,0), whose only action is to recurse and pass along whatever comes back — there is no candidate loop there to continue. The failure propagates straight out.

The search cannot tell the two situations apart. "This puzzle is unsolvable" and "I corrupted the board at step 3 and never cleaned up" produce the same return value.

**Full credit requires:** the stuck 2, the false report of unsolvability, and a causal explanation. Partial credit for a trace that stops in the right place without the explanation.

#### Bonus observation, and a correction worth having on hand

A sharp student may ask whether the occupancy test in `check_guess` is what causes this, and whether removing that test would rescue the no-undo solver. The answer is no, and it is worth being precise because the surface evidence is misleading.

Without the occupancy test, the stale 2 *does* get overwritten, and on **this** puzzle the no-undo solver reaches the correct answer in 22 steps. But it is still not a correct algorithm. I searched all 288 valid 4×4 grids and every unique-solution puzzle with 8 or fewer blanks — 42,474 puzzles — and the no-undo solver without an occupancy test **reports "no solution" on 3 solvable puzzles.** One of them:

```
puzzle:  1 2 3 4 / 3 4 1 2 / 2 0 0 0 / 4 0 2 3
correct: 1 2 3 4 / 3 4 1 2 / 2 3 4 1 / 4 1 2 3
reports: no solution
```

The mechanism, from the trace of that puzzle:

```
   5  (2,2) try 4: VALID, write it
   9      (2,3) try 4: rejected (4 found in row at (2,2))
          (2,3) all four failed -> return failure
        (2,2) failed below; NO UNDO, cell still holds 4
  ...
  11  (2,1) try 3: VALID, write it
  12    (2,2) try 1: rejected (1 found in column at (1,2))
  13    (2,2) try 2: rejected (2 found in row at (2,0))
  14    (2,2) try 3: rejected (3 found in row at (2,1))
  15    (2,2) try 4: rejected (4 found in row at ITSELF)   <<<<
```

Cell (2,2) still holds a stale 4. On re-entry, candidates 1, 2, and 3 are all genuinely invalid, so nothing overwrites it. Then candidate 4 — the correct value — is rejected because the row scan finds a 4 at (2,2) itself. The cell rejects its own answer. That configuration never arises on the assignment's puzzle, which is why removing the test looks harmless there.

**The useful framing:** the occupancy test does not cause the bug, it *exposes* it immediately and on every input. Remove the test and the same defect survives, now firing only on inputs nobody thought to try. A check that makes a latent fault fail loudly on the first run is doing you a favor.

### 2-d) [15 pts] The success condition

The algorithm succeeds when **no empty cells remain in the grid** — equivalently, when the row-major walk advances past the last cell with nothing left to fill.

Accept any phrasing of that: every cell holds a digit, there are no zeros left, the solver has moved beyond (3,3).

**Reject** "when the solution is correct" or "when the grid is valid." The algorithm never checks validity, and that gap is the point of the `check_solution` work in Part 2.

---

## Memory Map Problem

```
REGISTERS:
Function    Variable   Address           Final Value
main        iter       0x7fffb1b10be8    2
main        jter       0x7fffb1b10bec    0
map_array   iter       0x7fffb1b10bc8    0x7fffb1b10be8
map_array   jter       0x7fffb1b10bc4    3

STACK:
Variable           Address           Final Value
int_array[0][0]    0x7fffb1b10bf0    0
int_array[0][1]    0x7fffb1b10bf4    1
int_array[0][2]    0x7fffb1b10bf8    2
int_array[1][0]    0x7fffb1b10bfc    5
int_array[1][1]    0x7fffb1b10c00    6
int_array[1][2]    0x7fffb1b10c04    7
```