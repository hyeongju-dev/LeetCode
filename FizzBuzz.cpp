/* LeetCode: Fizz Buzz
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/743/ */

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

using pis = pair<int, string>;

class Solution {
public:
    string generate(int num, int idx, const int itemsSize, string str, const vector<pis>& items) {
      if (idx == itemsSize) {
        if (str.empty())
          return to_string(num);
        else
          return str;
      }

      pis cand = items[idx];
      int divisor = cand.first;
      string word = cand.second;

      if (num % divisor == 0)
        return generate(num, idx+1, itemsSize, str+word, items);
      else
        return generate(num, idx+1, itemsSize, str, items);
    }

    vector<string> fizzBuzz(int n) {
      vector<pis> items; items.push_back({3, "Fizz"}); items.push_back({5, "Buzz"});
      vector<string> ans(n);
      int itemsSize = items.size();

      for (int num = 1; num <= n; ++num)
        ans[num-1] = generate(num, 0, itemsSize, "", items);

      return ans;
    }
};
/* Time complextiy: O(N)
 * Space complexity: O(N*k) k is size of itmes; depth of recursive call */
