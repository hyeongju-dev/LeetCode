/* LeetCode: Generate Parentheses
 * https://leetcode.com/explore/interview/card/top-interview-questions-medium/109/backtracking/794/ */

#include <vector>
#include <string>
using namespace std;

// Constraints: 1 <= n <= 8
class Solution {
public:
    vector<string> ret;

    void dfs(int n, int open, int close, string curStr) {
      if (close == n) {
        ret.push_back(curStr);
        return;
      }

      if (open < n)
        dfs(n, open+1, close, curStr+"(");
      if (open > close)
        dfs(n, open, close+1, curStr+")");
    }

    vector<string> generateParenthesis(int n) {
      if (n == 0)
        return vector<string>();

      dfs(n, 0, 0, "");
      return ret;
    }
};
/* Time complextiy: O(2^n). For every index there can be two options ‘(‘ or ‘)’. So it can be said that the upperbound of time complexity is O(2^n) or it has exponential time complexity.
 * Space complexity: O(n). The space complexity can be reduced to O(n) if global variable or static variable is used to store the output string. */
