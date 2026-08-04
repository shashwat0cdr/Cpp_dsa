/*
==================== AGGRESSIVE COWS ====================

Problem:
---------
Given positions of stalls and M cows.
Place all cows in the stalls such that the
minimum distance between any two cows is maximum.

Rules:
------
1. One stall can contain only one cow.
2. Every cow must be placed.
3. We have to maximize the minimum distance.

Example:
---------
Stalls = {1, 2, 4, 8, 9}
Cows = 3

Possible placement:
1, 4, 8

Distances:
4-1 = 3
8-4 = 4

Minimum distance = 3

Answer = 3

---------------------------------------------------------

Why Binary Search?
------------------
We are searching for the ANSWER.

Answer = Minimum distance between cows.

Search Space:
-------------
Start = 1

End = Last Stall - First Stall

Example:
1 2 4 8 9

Start = 1
End = 9 - 1 = 8

---------------------------------------------------------

isPossible(mid)
---------------
Question:

Can we place all cows such that
minimum distance between every two cows >= mid ?

Logic:
------
1. Place first cow in first stall.

2. Traverse remaining stalls.

3. If current stall - last placed stall >= mid
      Place another cow.

4. If all cows are placed
      return true

5. Otherwise
      return false

---------------------------------------------------------

Binary Search
-------------

If isPossible(mid) == true

Answer may be larger.

ans = mid;
start = mid + 1;

--------------------------------

If isPossible(mid) == false

Distance is too large.

end = mid - 1;

---------------------------------------------------------

Time Complexity
---------------

Sorting
O(n log n)

Binary Search
O(log(maxDistance))

isPossible()
O(n)

Overall

O(n log n + n log(maxDistance))

Space
O(1)

---------------------------------------------------------

Pattern

Book Allocation
----------------
Minimum Maximum Pages
Possible -> LEFT
end = mid - 1

Painter Partition
-----------------
Minimum Maximum Time
Possible -> LEFT
end = mid - 1

Split Array Largest Sum
-----------------------
Minimum Largest Sum
Possible -> LEFT
end = mid - 1

Aggressive Cows
---------------
Maximum Minimum Distance
Possible -> RIGHT
start = mid + 1

Magnetic Force Between Two Balls (LeetCode 1552)
------------------------------------------------
Exactly same as Aggressive Cows.

=================================================
*/