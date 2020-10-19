/* LeetCode: Reverse String
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/879/ */

#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
      int size = (int)s.size();
      for (int i = 0; i < size/2; ++i) {
        int tmp = s[i];
        s[i] = s[size-1-i];
        s[size-1-i] = tmp;
      }
    }
};
/* Time complextiy: O(n)
 * Space complexity: O(1) */
