/* LeetCode: Remove Duplicates from Sorted Array
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/727/ */

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int nsize = (int)nums.size();
      if (nsize == 0)
        return 0;

      int slow = 0;
      for (int fast = 1; fast < nsize; ++fast) {
        // if current element is not duplicate, slow runner grows one step and copys the current value
        if (nums[slow] != nums[fast]) {
          slow++;
          nums[slow] = nums[fast];
        }
      }

      return slow+1;
    }
};
/*  Time complextiy: O(n). Assume that n is the length of array. Each of slow and fast traverses at most n steps.
 * Space complexity : O(1). */
