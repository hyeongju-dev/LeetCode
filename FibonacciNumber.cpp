/* LeetCode: Fibonacci Number
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/ */

 class Solution {
 public:
     int fib(int N) {
       int a = 0, b = 1, c;
       if (N == 0)
         return a;

       for (int i = 2; i <= N; ++i) {
         c = a+b;
         a = b;
         b = c;
       }
       return b;
     }
 };
 /* Time complextiy: O(N)
  * Space complexity: O(1) */
