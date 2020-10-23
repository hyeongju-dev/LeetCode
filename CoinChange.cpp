/* LeetCode: Coin Change
 * https://leetcode.com/explore/interview/card/top-interview-questions-medium/111/dynamic-programming/809/ */

#include <vector>

#define min(a,b) ((a) < (b) ? (a) : (b))

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      int max = amount + 1;
      vector<int> memo(max, max); memo[0] = 0;
      int size = coins.size();

      for (int i = 1; i <= amount; ++i)
        for (int j = 0; j < size; ++j)
          if (coins[j] <= i)
            memo[i] = min(memo[i], memo[i-coins[j]]+1);

      return memo[amount] > amount ? -1 : memo[amount];
    }
};
/* Time complextiy: O(S*n). On each step the algorithm finds the next F(i) in n iterations, where 1≤i≤S1. Therefore in total the iterations are S*n.
 * Space complexity: O(S). We use extra space for the memoization table. */
