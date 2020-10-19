/* LeetCode: Rotate Image
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/770/ */

#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      int n = (int)matrix.size();
      for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < (n+1)/2; ++j) {
          int tmp = matrix[i][j];
    			matrix[i][j] = matrix[n-1-j][i];
    			matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
    			matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
    			matrix[j][n-1-i] = tmp;
        }
      }
    }
};
/* Time complextiy: O(n^2)
 * Space complexity: O(1) */
