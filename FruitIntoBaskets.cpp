/* LeetCode: Fruit Into Baskets
 * https://leetcode.com/problems/fruit-into-baskets/ */

// "finding longest substring w/ at most two characters"
#include <vector>
#include <unordered_map>
using namespace std;

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

class Solution {
public:
    int totalFruit(vector<int>& tree) {
      if (tree.empty())
        return 0;

      unordered_map<int, int> hash;
      int amount = 1, i = 0, start = 0, k = 2;

      for (i = 0; i < tree.size(); ++i) {
        if (hash.size() <= k) {
          hash[tree[i]] = i;
        }

        if (hash.size() > k) {
          int min = tree.size()-1;
          for (unordered_map<int, int>::iterator it = hash.begin(); it != hash.end(); ++it) {
            int value = it->second;
            min = MIN(min, value);
          }
          start = min+1;
          hash.erase(tree[min]);
        }

        amount = MAX(amount, i-start+1);
      }

      return amount;
    }
};
/* Time complextiy: O(N), where N is the length of tree.
 * Space complexity: O(N) */
