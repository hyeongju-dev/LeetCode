/* LeetCode: Missing Number
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/99/others/722/ */

#include <vector>
using namespace std;

// Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?

/* Bit Manipulation */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int size = (int)nums.size();
      int missing = size;
      for (int i = 0; i < size; ++i)
            missing ^= i ^ nums[i];

      return missing;
    }
};
/* Time complextiy: O(n). Assuming that XOR is a constant-time operation, this algorithm does constant work on n iterations, so the runtime is overall linear.
 * Space complexity: O(1). This algorithm allocates only constant additional space. */


/* Gauss' Formula Approach */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int size = (int)nums.size();
      int expectedSum = size * (size + 1) / 2;
      int actualSum = 0;

      for (int i = 0; i < size; ++i)
        actualSum += nums[i];

      return expectedSum - actualSum;
    }
};
/* Time complextiy: O(n). Although Gauss' formula can be computed in O(1) time, summing nums costs us O(n) time, so the algorithm is overall linear. Because we have no information about which number is missing, an adversary could always design an input for which any algorithm that examines fewer than n numbers fails. Therefore, this solution is asymptotically optimal.
 * Space complexity: O(1). This approach only pushes a few integers around, so it has constant memory usage. */
