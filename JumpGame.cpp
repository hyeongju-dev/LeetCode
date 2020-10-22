/* LeetCode: Jump Game
 * https://leetcode.com/explore/interview/card/top-interview-questions-medium/111/dynamic-programming/807/ */

#include <vector>

/* Dynamic Programming Bottom-up Approach */
#define min(a,b) ((a) < (b) ? (a) : (b))

class Solution {
public:
    enum INDEX { GOOD, BAD, UNKNOWN, };

    bool canJump(vector<int>& nums) {
      vector<INDEX> memo(nums.size(), INDEX::UNKNOWN);
      memo[memo.size()-1] = INDEX::GOOD;

      for (int i = nums.size()-2; i >= 0; --i) {
        int furthestJump = min(i+nums[i], nums.size()-1);
        for (int j = i+1; j <= furthestJump; ++j) {
          if (memo[j] == INDEX::GOOD) {
            memo[i] = INDEX::GOOD;
            break;
          }
        }
      }

      return memo[0] == INDEX::GOOD;
    }
};
/* Time complextiy: O(n^2). For every element in the array, say i, we are looking at the next nums[i] elements to its right aiming to find a GOOD index. nums[i] can be at most n, where nnn is the length of array nums.
 * Space complexity: O(n). This comes from the usage of the memo table. */

/* Greedy Approach */
class Solution {
public:
    bool canJump(vector<int>& nums) {
      int lastPos = nums.size()-1;
      for (int i = nums.size()-1; i >= 0; --i)
        if (i+nums[i] >= lastPos)
          lastPos = i;

      return lastPos == 0;
    }
};
/* Time complextiy: O(n). We are doing a single pass through the nums array, hence n steps, where n is the length of array nums.
 * Space complexity: O(1). We are not using any extra memory. */
