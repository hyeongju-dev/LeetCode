/*
LeetCode: Best Time to Buy and Sell Stock II
https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/564/
*/

/*  Peak Valley Approach - O(n) time & O(1) space */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];
        int maxProfit = 0;

        int psize = (int)prices.size();
        while (i < psize-1) {
            while (i < psize-1 && prices[i] >= prices[i+1])
                i++;
            valley = prices[i];
            while (i < psize-1 && prices[i] <= prices[i+1])
                i++;
            peak = prices[i];
            maxProfit += peak - valley;
        }
        return maxProfit;
    }
};

/* Simple One Pass - O(n) time & O(1) space */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int psize = prices.size();
        for (int i = 1; i < psize; ++i)
            if (prices[i] > prices[i-1])
                maxProfit += (prices[i] - prices[i-1]);

        return maxProfit;
    }
};
