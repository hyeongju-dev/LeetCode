/* LeetCode: Permutations
 * https://leetcode.com/explore/interview/card/top-interview-questions-medium/109/backtracking/795/ */

 // cf. https://stackoverflow.com/questions/41627749/time-complexity-of-permutation-function

#include <vector>

// Given a collection of distinct integers, return all possible permutations.
class Solution {
public:
    vector<vector<int> > ret;
    vector<bool> isPicked;
    int tgtSize;

    void dfs(int cntPick, const vector<int>& nums, vector<int>& chosen) {
      if (cntPick == tgtSize) {
        ret.push_back(chosen);
        return;
      }

      for (int i = 0; i < tgtSize; ++i) {
        if (isPicked[i] == true)
          continue;

        isPicked[i] = true;
        chosen.push_back(nums[i]);
        dfs(cntPick+1, nums, chosen);
        chosen.pop_back();
        isPicked[i] = false;
      }
    }

    vector<vector<int> > permute(vector<int>& nums) {
      isPicked.assign(nums.size(), false);
      tgtSize = nums.size();
      vector<int> chosen;

      dfs(0, nums, chosen);
      return ret;
    }
};
/* Time complextiy: O(n!) as it is governed by the equation: T(n) = n * T(n-1) + O(1).
 * Space complexity: O(n*n!) */
