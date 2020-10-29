/* LeetCode: Container With Most Water
 * https://leetcode.com/problems/container-with-most-water/ */

#include <vector>
using namespace std;

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

class Solution {
public:
    int maxArea(vector<int>& height) {
      int low = 0;
      int high = height.size()-1;
      int maxArea = (high-low) * min(height[low], height[high]);

      while (low < high) {
        if (height[low] <= height[high]) {
          ++low;
        } else {
          --high;
        }
        maxArea = max(maxArea, (high-low) * min(height[low], height[high]));
      }

      return maxArea;
    }
};
/* Time complextiy: O(N)
 * Space complexity: O(1) */
