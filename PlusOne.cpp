/* LeetCode: Plus One
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/559/ */

#include <vector>

class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    vector<int> ans;
    int carry = 0;
    int n = digits.size() - 1;
    int sum = digits[n] + 1;

    for (int i = n-1; i >= 0; --i) {
        ans.insert(ans.begin(), sum % 10);
        carry = sum / 10;
        sum = digits[i] + carry;
    }

    ans.insert(ans.begin(), sum % 10);
    carry = sum / 10;

    if (carry > 0)
        ans.insert(ans.begin(), carry);

    return ans;
  }
};
/* Time complextiy: O(n)
 * Space complexity: O(n) */
