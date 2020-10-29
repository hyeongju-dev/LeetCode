/* LeetCode: Decode Ways
 * https://leetcode.com/problems/decode-ways/ */

class Solution {
public:
    int numDecodings(string s) {
      if (s.empty() || s[0] == '0')
        return 0;

      int a = 1, b = 1, c;

      for (int i = 1; i < s.size(); ++i) {
        if (s[i] == '0') {
          if (s[i-1] > '2' || s[i-1] == '0')
            return 0;
          c = a; a = 0; b = c;
        } else if (s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7')) {
          c = a; a = b; b = b + c;
        } else {
          a = b;
        }
      }

      return b;
    }
};
/* Time complextiy: O(N)
 * Space complexity: O(1) */
