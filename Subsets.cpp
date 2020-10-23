/* LeetCode: Subsets
 * https://leetcode.com/explore/interview/card/top-interview-questions-medium/109/backtracking/796/ */

#include <vector>
using namespace std;

// Given a set of distinct integers, nums, return all possible subsets (the power set).
// Note: The solution set must not contain duplicate subsets.
class Solution {
public:
    vector<vector<int> > ret;
    int n, k;

    void dfs(int first, vector<int>& chosen, const vector<int>& nums) {
      if (chosen.size() == k) {
        ret.push_back(chosen);
        return;
      }

      for (int i = first; i < n; ++i) {
        chosen.push_back(nums[i]);
        dfs(i+1, chosen, nums);
        chosen.pop_back();
      }
    }

    vector<vector<int> > subsets(vector<int>& nums) {
      n = nums.size();
      for (k = 0; k <= n; ++k) {
        vector<int> chosen;
        dfs(0, chosen, nums);
      }
      return ret;
    }
};
/* Time complextiy: O(n*2^n) to generate all subsets and then copy them into output list.
 * Space complexity: O(n*2^n) to keep all the subsets of length n, since each of n elements could be present or absent. */
