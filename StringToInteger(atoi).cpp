/* LeetCode: String to Integer (atoi)
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/884/ */

#include <string>
using namespace std;

//#define INT_MIN 0x80000000
//#define INT_MAX 0x7fffffff

class Solution {
public:
    int myAtoi(string s) {
      int idx = 0;
      int ret = 0;
      int size = (int)s.size();
      bool positive = true;

      while (idx < size && s[idx] == ' ')
        idx++;

      if (idx < size && (s[idx] == '+' || s[idx] == '-'))
        positive = (s[idx++] == '-' ? false : true);

      while (idx < size && s[idx] >= '0' && s[idx] <= '9') {
        int pop = (positive ? s[idx]-'0' : '0'-s[idx]);

  			if (ret > INT_MAX/10 || (ret == INT_MAX/10 && pop > 7))
  				return INT_MAX;
  			if (ret < INT_MIN/10 || (ret == INT_MIN/10 && pop < -8))
  				return INT_MIN;

        ret = ret*10 + pop;

        ++idx;
  		}

		  return ret;
    }
};
/* Time complextiy: O(n)
 * Space complexity: O(1) */
