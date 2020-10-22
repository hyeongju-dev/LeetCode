/* LeetCode: Letter Combinations of a Phone Number
 * https://leetcode.com/explore/interview/card/top-interview-questions-medium/109/backtracking/793/ */

#include <vector>
#include <unordered_map>

class Solution {
public:
    unordered_map<char, string> hash = {{'2', "abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}};
    vector<string> ret;
    vector<int> pick;
    int size;

    void dfs(int lastPick, int cnt, string curStr, string& digits) {
      if (cnt == size) {
        ret.push_back(curStr);
        return;
      }

      for (int i = lastPick+1; i < size; ++i) {
        pick.push_back(i);

        string cand = hash[digits[i]];
        int candSize = hash[digits[i]].size();
        for (int j = 0; j < candSize; ++j)
          dfs(i, cnt+1, curStr+cand[j], digits);

        pick.pop_back();
      }
    }

    vector<string> letterCombinations(string digits) {
      if (digits.empty())
        return vector<string>();

      size = (int)digits.size();
      dfs(-1, 0, "", digits);

      return ret;
    }
};
/* Time complextiy: O(3^N×4^M) where N is the number of digits in the input that maps to 3 letters (e.g. 2, 3, 4, 5, 6, 8) and M is the number of digits in the input that maps to 4 letters (e.g. 7, 9), and N+M is the total number digits in the input.
 * Space complexity: O(3^N×4^M) since one has to keep 3^N×4^M solutions. */
