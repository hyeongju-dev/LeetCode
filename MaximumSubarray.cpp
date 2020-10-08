/* LeetCode: Maximum Subarray
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/566/ */

#include <vector>
#include <algorithm>  // max_element()
using namespace std;

#define max(a,b) ((a) > (b) ? (a) : (b))

/* Divide and Conquer Approach
 * 1. Divide the array into two halves
 * 2. Recursively find the maximum subarray sum for left subarray
 * 3. Recursively find the maximum subarray sum for right subarray
 * 4. Find the maximum subarray sum that crosses the midpoint
 * 5. return the maximum of above three sums */
class Solution {
public:
  int maxSubArray(const vector<int>& nums) {
    int low = 0, high = nums.size()-1;
      return maxSubArray(nums, low, high);
    }

    int maxSubArray(const vector<int>& nums, int low, int high) {
      if (low == high)
        return nums[low];

      int mid = (low+high)/2;
      int leftMaxSubArray = maxSubArray(nums, low, mid);
      int rightMaxSubArray = maxSubArray(nums, mid+1, high);

      int left_sum = INT_MIN, right_sum = INT_MIN;
      int sum = 0;
      for (int i = mid+1; i <= high; ++i) {
        sum += nums[i];
        right_sum = max(right_sum, sum);
      }
      sum = 0;
      for (int i = mid; i >= low; --i) {
        sum += nums[i];
        left_sum = max(left_sum, sum);
      }
      int ans = max(leftMaxSubArray, rightMaxSubArray);
      return max(ans, left_sum + right_sum);
    }
};
/* Time complextiy: O(nlogn).
 * Space complexity: O(nlogn). call stack */


/* Incremental Appoach */
class Solution {
public:
  int maxSubArray(const vector<int>& nums) {
    vector<int> cache;
    cache.push_back(nums[0]);
    for (int i = 1; i < nums.size(); ++i)
      cache.push_back(max(0, cache[i-1]) + nums[i]);

    return *max_element(cache.begin(), cache.end());
  }
};
/* Time complextiy: O(n).
 * Space complexity: O(n). */
