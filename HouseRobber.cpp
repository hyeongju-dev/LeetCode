/* LeetCode: House Robber
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/576/ */

#include <vector>
using namespace std;

/* Dynamic Programming Approach */
#include <vector>

class Solution {
public:
    int rob(vector<int>& nums) {
        // base case
        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return nums[0];

        vector<int> cache(nums.size(), 0);
        cache[0] = nums[0];
        cache[1] = (nums[0] < nums[1] ? nums[1] : nums[0]);

        for (int i = 2; i < nums.size(); ++i)
           cache[i] = (cache[i-2] + nums[i] > cache[i-1] ? cache[i-2] + nums[i] : cache[i-1]);

        return cache[nums.size()-1];
    }
};
/* Time complextiy: O(n).
 * Space complexity: O(n). */
