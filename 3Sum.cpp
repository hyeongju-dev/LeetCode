/* LeetCode: 3Sum
 * https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/776/ */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      vector<vector<int>> ret;

      for (int i = 0; i < nums.size(); ++i) {
        if ((i > 0) && (nums[i] == nums[i-1]))
          continue;

        int low = i+1;
        int high = nums.size()-1;
        while (low < high) {
          int s = nums[i] + nums[low] + nums[high];
          if (s > 0) {
            --high;
          } else if (s < 0) {
            ++low;
          } else {
            ret.push_back(vector<int> {nums[i], nums[low], nums[high]});
            while (low+1 < nums.size() && nums[low] == nums[low+1])
              ++low;
            while (high-1 > 0 && nums[high] == nums[high-1])
              --high;
            ++low; --high;
          }
        }
      }

      return ret;
    }
};
/* Time complextiy: O(nlogn)
 * Space complexity: O(1) */
