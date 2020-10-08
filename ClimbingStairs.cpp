/* LeetCode: Climbing Stairs
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/569 */

#include <vector>

/* Recursion with Memoization Approach */
class Solution {
public:
  int climbStairs(int n) {
    vector<int> memo(n+1, 0);
    return climbStairs(0, n, memo);
  }

  int climbStairs(int i, int n, vector<int>& memo) {
    if (i > n)
      return 0;
    if (i == n)
      return 1;
    if (memo[i] > 0)
      return memo[i];

    return memo[i] = climbStairs(i+1, n, memo) + climbStairs(i+2, n, memo);
  }
};
/* Time complextiy: O(n). Size of recursion tree can go upto n.
 * Space complexity: O(n). The depth of recursion tree can go upto n. */


/* Dynamic Programming Approach */
// It contains the optimal substructure property i.e. its optimal solution can be constructed efficiently from optimal solutions of its subproblems, we can use dynamic programming to solve this problem.
class Solution {
public:
  int climbStairs(int n) {
    if (n == 1)
      return 1;

    vector<int> cache(n+1, 0);
    cache[1] = 1; cache[2] = 2;
    for (int i = 3; i <= n; ++i)
      cache[i] = cache[i-1] + cache[i-2];

    return cache[n];
  }
};
/* Time complextiy: O(n). Single loop upto n.
 * Space complexity: O(n). cache array of size n is used. */


/* Fibonacci Number Approach */
class Solution {
public:
  int climbStairs(int n) {
    if (n == 1)
      return 1;

    int first = 1;
    int second = 2;
    for (int i = 3; i <= n; ++i) {
      int third = first + second;
      first = second;
      second = third;
    }
    return second;
  }
};
/* Time complextiy: O(n). Single loop upto n is required to calculate nth fibonacci number.
 * Space complexity: O(n). Constant space is used. */
