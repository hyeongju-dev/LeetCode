/* LeetCode: Best Time to Buy and Sell Stock
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/572/ */

/* We need to find out the maximum difference (which will be the maximum profit) between two numbers in the given array. Also, the second number (selling price) must be larger than the first one (buying price).
 * In formal terms, we need to find max⁡(prices[j] − prices[i]), for every i and j such that j > i.
 * The points of interest are the peaks and valleys in the given graph. We need to find the largest peak following the smallest valley. We can maintain two variables - minprice and maxprofit corresponding to the smallest valley and maximum profit (maximum difference between selling price and minprice) obtained so far respectively. */

class Solution {
public:
  int maxProfit(const vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int i = 0; i < prices.size(); ++i)
      if (prices[i] < minPrice)
        minPrice = prices[i];
      else if (prices[i] - minPrice > maxProfit)
        maxProfit = prices[i] - minPrice;

    return maxProfit;
  }
};
/* Time complextiy: O(n). Only a single pass is needed.
 * Space complexity: O(1). Only two variables are used. */
