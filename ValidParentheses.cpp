/* LeetCode: Valid Parentheses
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/99/others/721/ */

#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
      int size = (int)s.size();
      if (size % 2 != 0)
        return false;

      stack<char> check;
      for (int i = 0; i < size; ++i) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
          check.push(s[i]);
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
          if (check.empty())
            return false;
          char st = check.top(); check.pop();
          if ((s[i] == ')' && st != '(') || (s[i] == '}' && st != '{') || (s[i] == ']' && st != '['))
            return false;
        } else {
          return false;
        }
      }

      if (!check.empty())
        return false;

      return true;
    }
};
/* Time complextiy: O(s.size())
 * Space complexity: O(s.size()) */
