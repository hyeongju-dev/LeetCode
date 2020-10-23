/* LeetCode: Word Search
 * https://leetcode.com/explore/interview/card/top-interview-questions-medium/109/backtracking/797/ */

#include <vector>
#include <string>

class Solution {
public:
    const int dy[4] = {-1,0,+1,0};
    const int dx[4] = {0,+1,0,-1};

    bool foundWord(vector<vector<char> >& board, int y, int x, const string& word, int pos) {
      if (pos == word.size())
        return true;
      if (y < 0 || y >= board.size() || x < 0 || x >= board[0].size())
        return false;

      if (board[y][x] == word[pos]) {
        board[y][x] = '*';  // set true
        for (int d = 0; d < 4; ++d) {
          int ny = y + dy[d], nx = x + dx[d];
          if (foundWord(board, ny, nx, word, pos+1))
            return true;
        }
        board[y][x] = word[pos];  // set false
      }

      return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
      int size = (int)board.size();
      for (int y = 0; y < board.size(); ++y)
        for (int x = 0; x < board[0].size(); ++x)
          if (foundWord(board, y, x, word, 0))
            return true;
      return false;
    }
};
/* Time complextiy: O(m*n*4^s)
 * Space complexity: O(s) */
