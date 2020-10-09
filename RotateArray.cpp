/* LeetCode: Rotate Array
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/646/ */

#include <vector>

/* Cyclic Replacements Approach */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      k = k % nums.size();
      int cnt = 0;

      for (int start = 0; cnt < nums.size(); ++start) {
        int curr = start;
        int prev = nums[start];
        do {
          int next = (curr + k) % nums.size();
          int temp = nums[next];
          nums[next] = prev;
          prev = temp;
          curr = next;
          cnt++;
        } while (start != curr);
      }
    }
};
/* Time complextiy: O(n). Only one pass is used.
 * Space complexity: O(1). Constant extra space is used. */


/* Reverse Approach */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      k %= nums.size();
      reverse(nums, 0, nums.size()-1);
      reverse(nums, 0, k-1);
      reverse(nums, k, nums.size()-1);
    }

    void reverse(vector<int>& nums, int start, int end) {
      while (start < end) {
        int tmp = nums[start];
        nums[start] = nums[end];
        nums[end] = tmp;
        start++;
        end--;
      }
    }
};
/* Time complextiy: n elements are reversed a total of three times.
 * Space complexity: O(1). No extra space is used. */
