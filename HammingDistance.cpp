/* LeetCode: Hamming Distance
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/99/others/762/ */

class Solution {
public:
    int hammingDistance(int x, int y) {
      int ans = x^y;
      int cnt = 0;

      while (ans != 0) {
        cnt++;
        ans &= (ans-1);
      }

      return cnt;
    }
};
/* Time complextiy: O(1). The run time depends on the number of 1-bits in n. In the worst case, all bits in n are 1-bits. In case of a 32-bit integer.
 * Space complexity: O(1) since no additional space is allocated */
