/* LeetCode: Number of 1 Bits
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/99/others/565/ */

/* Bit Manipulation Trick Approach */
class Solution {
public:
    int hammingWeight(uint32_t n) { // uint32 equals unsigned int
      int cnt = 0;
      while (n != 0) {
        cnt++;
        n &= (n-1);
      }
      return cnt;
    }
};
/* Time complextiy: O(1). The run time depends on the number of 1-bits in n. In the worst case, all bits in n are 1-bits. In case of a 32-bit integer.
 * Space complexity: O(1) since no additional space is allocated */
