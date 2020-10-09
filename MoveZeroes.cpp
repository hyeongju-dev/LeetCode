/* LeetCode: Move Zeroes
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/567/ */

#include <vector>
#include <algorithm>

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++)
        if (nums[cur] != 0)
          swap(nums[lastNonZeroFoundAt++], nums[cur]);
    }
};
/* Time complextiy: O(n). However, the total number of operations are optimal. The total operations (array writes) that code does is Number of non-0 elements. This gives us a much better best-case (when most of the elements are 0) complexity than last solution. However, the worst-case (when all elements are non-0) complexity for both the algorithms is same.
 * Space complexity: O(1). Only constant space is used. */
