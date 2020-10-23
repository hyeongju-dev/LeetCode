/* LeetCode: Unique Paths
 * https://leetcode.com/explore/interview/card/top-interview-questions-medium/111/dynamic-programming/808/ */

#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
      vector<vector<int> > grid;
      grid.assign(m, vector<int>(n, 1));

      for (int y = 1; y < m; ++y)
        for (int x = 1; x < n; ++x)
          grid[y][x] = grid[y-1][x] + grid[y][x-1];

      return grid[m-1][n-1];
    }
};
/* Time complextiy: O(m*n)
 * Space complexity: O(m*n) */
