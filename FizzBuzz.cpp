/* LeetCode: Fizz Buzz
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/743/ */

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
      vector<string> ans(n);
      for (int i = 1, fizz = 1, buzz = 1; i <= n; ++i, ++fizz, ++buzz) {
        if (fizz == 3 && buzz == 5)
          fizz = buzz = 0, ans[i-1] = "FizzBuzz";
        else if(fizz == 3)
          fizz = 0, ans[i-1] = "Fizz";
        else if (buzz == 5)
          buzz = 0, ans[i-1] = "Buzz";
        else
          ans[i-1] = to_string(i);
      }
      return ans;
    }
};
/* Time complextiy: O(N)
 * Space complexity: O(1) */
