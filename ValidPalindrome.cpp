/* LeetCode: Valid Palindrome
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/883/ */

#include <string>
#include <vector>
using namespace std;

// considering only alphanumeric characters and ignoring cases.
// Note: For the purpose of this problem, we define empty string as valid palindrome.

/* Two Pointer Approach */
class Solution {
public:
    bool isPalindrome(string s) {
      int size = (int)s.size();
      int low = 0; int high = size - 1;

      while (low < high) {
        if (s[low] >= 'A' && s[low] <= 'Z')
          s[low] = s[low] - 'A' + 'a';
        if (s[high] >= 'A' && s[high] <= 'Z')
          s[high] = s[high] - 'A' + 'a';

        if (!((s[low] >= '0' && s[low] <= '9') || (s[low] >= 'a' && s[low] <= 'z'))) {
          ++low;
        } else if (!((s[high] >= '0' && s[high] <= '9') || (s[high] >= 'a' && s[high] <= 'z'))) {
          --high;
        } else {
          if (s[low] != s[high])
            return false;
          ++low;
          --high;
        }
      }

      return true;
    }
};
/* Time Complexity: O(n)
 * Space Complexity: O(1) */
