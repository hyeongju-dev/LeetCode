/* LeetCode: First Bad Version
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/96/sorting-and-searching/774/ */

#include <vector>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
class Solution {
public:
    int firstBadVersion(int n) {
      int low = 1, high = n;

      while (low < high) {
        int mid = low + (high-low)/2;
        if (isBadVersion(mid))
          high = mid;
        else
          low = mid + 1;
      }
      return low ;
    }
};
/* Time complextiy: O(log_2{n}) The search space is halved each time.
 * Space complexity: O(1) */
