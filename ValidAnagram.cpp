/* LeetCode: Valid Anagram
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/882/ */

#include <string>
#include <vector>
using namespace std;

// Note: You may assume the string contains only lowercase alphabets.

class Solution {
public:
    bool isAnagram(string s, string t) {
      int ssize = (int)s.size(); int tsize = (int)t.size();
      if (ssize != tsize)
        return false;

      int numAlphabet = 'z'-'a'+1;
      vector<int> check; check.assign(numAlphabet, 0);

      for (int i = 0; i < ssize; ++i) {
        check[s[i]-'a'] += 1;
        check[t[i]-'a'] -= 1;
      }

      for (int i = 0; i < numAlphabet; ++i)
        if (check[i] != 0)
          return false;

      return true;
    }
};
/* Time Complexity: O(n). Accessing the counter table is a constant time operation.
 * Space Complexity: O(1). Although we do use extra space, the space complexity is O(1) because the table's size stays constant no matter how large n is. */


// Follow up: What if the inputs contain unicode characters? How would you adapt your solution to such case?
// Use a hash table instead of a fixed size counter. Imagine allocating a large size array to fit the entire range of unicode characters, which could go up to more than 1 million. A hash table is a more generic solution and could adapt to any range of characters.
