/* LeetCode: First Unique Character in a String
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/881/ */

#include <string>
#include <vector>
using namespace std;

// Note: You may assume the string contains only lowercase English letters.
class Solution {
public:
    int firstUniqChar(string s) {
      vector<int> cnt; cnt.assign('z'-'a'+1, 0);
      int size = (int)s.size();

      for (int i = 0; i < size; ++i)
        cnt[s[i]-'a']++;

      for (int i = 0; i < size ; ++i)
        if (cnt[s[i]-'a'] == 1)
          return i;

      return -1;
    }
 };
/* Time Complexity: O(n) since we go through the string of length N two times.
 * Space Complexity: O(1) because English alphabet contains 26 letters. */
