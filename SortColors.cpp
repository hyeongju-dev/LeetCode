/* LeetCode: Sort Colors
 * https://leetcode.com/problems/sort-colors/ */

#include <vector>
using namespace std;

#define swap(a,b) {int t; t = (a); (a) = (b); (b) = t;}

class Solution {
public:
    void sortColors(vector<int>& nums) {
      int red = 0, white = 0, blue = nums.size()-1;

      while (white <= blue) {
        if (nums[white] == 0) {
          swap(nums[red], nums[white]);
          ++white;
          ++red;
        } else if (nums[white] == 1) {
          ++white;
        } else {
          swap(nums[white], nums[blue]);
          --blue;
        }
      }
    }
};
/* Time complextiy: O(nlogn)
 * Space complexity: O(1) */
