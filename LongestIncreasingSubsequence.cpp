/* LeetCode: Longest Increasing Subsequence
 * https://leetcode.com/explore/interview/card/top-interview-questions-medium/111/dynamic-programming/810/ */

#include <vector>
using namespace std;

#define max(a,b) ((a) > (b) ? (a) : (b))

// Note: Your algorithm should run in O(n2) complexity.
/* Dynamic Programming Approach */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      if (nums.size() == 0)
        return 0;

      vector<int> memo;
      memo.assign(nums.size(), 0);
      memo[0] = 1;
      int maxAns = 1;

      for (int i = 1; i < memo.size(); ++i) {
        int maxVal = 0;
        for (int j = 0; j < i; ++j)
          if (nums[i] > nums[j])
            maxVal = max(maxVal, memo[j]);
        memo[i] = maxVal + 1;
        maxAns = max(maxAns, memo[i]);
      }

      return maxAns;
    }
};
/* Time complextiy: O(n^2). Two loops of n are there.
 * Space complexity: O(n). dp array of size n is used. */

// Follow up: Could you improve it to O(n log n) time complexity?
/* Dynamic Programming with Binary Search */
class Solution {
public:
    int binarySearch(vector<int>& tail, int low, int high, int key) {
      while (high - low > 1) {
        int mid = low + (high - low) / 2;
        if (tail[mid] >= key)
          high = mid;
        else
          low = mid;
      }
      return high;
    }

    int lengthOfLIS(vector<int>& nums) {
      if (nums.empty())
        return 0;

      vector<int> tail(nums.size(), 0); tail[0] = nums[0];
      int len = 1;

      for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] < tail[0])
          tail[0] = nums[i];
        else if (nums[i] > tail[len-1])
          tail[len++] = nums[i];
        else
          tail[binarySearch(tail, -1, len-1, nums[i])] = nums[i];
      }

      return len;
    }
};
/* Time complextiy: O(nlog⁡n). Binary search takes log⁡n time and it is called n times.
 * Space complexity: O(n). dp array of size n is used. */
