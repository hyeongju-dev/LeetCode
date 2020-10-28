/* LeetCode: Longest Increasing Subsequence
 * https://leetcode.com/explore/interview/card/top-interview-questions-medium/111/dynamic-programming/810/ */

#include <vector>
using namespace std;

#define max(a,b) ((a) > (b) ? (a) : (b))
#define INT_MIN 0x80000000
#define INT_MAX 0x7fffffff

// Note: Your algorithm should run in O(n^2) complexity.
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

// Follow up: Could you improve it to O(nlogn) time complexity?
/* Dynamic Programming with Binary Search */
class Solution {
public:
    int binarySearch(int low, int high, int num, const vector<int>& c) {
      // find i that matches c[i-1] < num <= c[i]
      if (low == high) {
        return low;
      } else if (low+1 == high) {
        if (c[low] >= num) {
          return low;
        } else {
          return high;
        }
      }

      int mid = low + (high - low) / 2;
      if (c[mid] == num)
        return mid;
      else if (c[mid] < num)
        return binarySearch(mid+1, high, num, c);
      else
        return binarySearch(low, mid, num, c);
    }

    int lengthOfLIS(vector<int>& nums) {
      if (nums.empty())
        return 0;

      // c[i] means smallest last number of lis subsequences whose length are i
      vector<int> c(nums.size()+1, INT_MAX);
      c[0] = INT_MIN; c[1] = nums[0];
      int len = 1;

      for (auto num : nums) {
        if (c[len] < num) {
          len++;
          c[len] = num;
        } else {
          int nextLoc = binarySearch(0, len, num, c);
          c[nextLoc] = num;
        }
      }

      return len;
    }
};
/* Time complextiy: O(nlog⁡n). Binary search takes log⁡n time and it is called n times.
 * Space complexity: O(n). dp array of size n is used. */
