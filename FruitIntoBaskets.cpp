/* LeetCode: Fruit Into Baskets
 * https://leetcode.com/problems/fruit-into-baskets/ */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
      unordered_map<int, int> counter;
      int cnt = 0, start = 0, ret = 0;
      int size = (int)tree.size();

      for (int end = 0; end < size; ++end) {
        if (!counter[tree[end]])
          ++cnt;
        ++counter[tree[end]];
        while (start < end && cnt > 2) {
          --counter[tree[start]];
          if (!counter[tree[start]])
            --cnt;
          ++start;
        }
        ret = max(ret, end-start+1);
      }

      return ret;
    }
};
/* Time complextiy: O(N), where N is the length of tree.
 * Space complexity: O(N) */
