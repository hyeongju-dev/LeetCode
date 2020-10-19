/* LeetCode: Valid Sudoku
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/769/ */

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      unordered_set<char> rows[9];
      unordered_set<char> cols[9];
      unordered_set<char> blos[9];

      for (int y = 0; y < 9; ++y) {
        for (int x = 0; x < 9; ++x) {
          char elem = board[y][x];
          if (elem == '.')
            continue;

          if (rows[y].count(elem) || cols[x].count(elem) || blos[(y/3)*3 + x/3].count(elem)) {
            return false;
          } else {
            rows[y].insert(elem); cols[x].insert(elem); blos[(y/3)*3 + x/3].insert(elem);
          }
        }
      }

      return true;
    }
};
/* Time complextiy: O(1)
 * Space complexity: O(1) */
