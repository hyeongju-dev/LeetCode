/* LeetCode: Pascal's Triangle
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/99/others/601/ */

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      if (numRows == 0)
        return vector<vector<int>>();
        
      vector<vector<int>> triangle(numRows, vector<int> (1,1));

      for (int currRow = 1; currRow < numRows; ++currRow) {
        vector<int> prevRow = triangle[currRow-1];
        for (int currCol = 1; currCol < currRow; ++currCol)
          triangle[currRow].push_back(prevRow[currCol-1] + prevRow[currCol]);
        triangle[currRow].push_back(1);
      }

      return triangle;
    }
 };
/* Time complextiy: O(n^2)
 * Space complexity: O(n^2) */
