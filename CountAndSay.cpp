/* LeetCode: count and Say
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/886/ */

#include <string>
using namespace std;

// Note: Each term of the sequence of integers will be represented as a string.
class Solution {
public:
  string countAndSay(int n) {
    string ret;
    ret.push_back('1');
    if (n == 1)
      return ret;

    string tmp = "";
    for (int i = 1; i < n; ++i) {
      int cnt = 1;
      int len = ret.size();
      for (int j = 0; j < len; ++j) {
        if (j == len-1) {
          tmp.push_back(cnt + '0');
          tmp.push_back(ret[j]);
          break;
        }
        if (ret[j] == ret[j+1]) {
          ++cnt;
        } else {
          tmp.push_back(cnt + '0');
          tmp.push_back(ret[j]);
          cnt = 1;
        }
      }
      ret = tmp;
      tmp.clear();
    }
    return ret;
  }
};
/* Time complextiy: O(n*m)
 * Space complexity: O(1) */
