/* LeetCode: Implement strStr()
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/885/ */

#include <string>
using namespace std;

/* Two Pointer Approach */
class Solution {
public:
    int strStr(string haystack, string needle) {
      int hsize = (int)haystack.size();
      int nsize = (int)needle.size();
      if (!nsize)
        return 0;
      if (hsize < nsize)
        return -1;

      for (int slow = 0; slow <= hsize-nsize; ++slow) {
        int fast;
        for (fast = 0; fast < nsize; ++fast)
          if (haystack[slow+fast] != needle[fast])
            break;

        if (fast == nsize)
          return slow;
      }

      return -1;
    }
};
/* Time complextiy: O(n^2) in worst case
 * Space complexity: O(1) */
