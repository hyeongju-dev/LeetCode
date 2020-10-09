/* LeetCode: Intersection of Two Arrays II
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/674/ */

#include <vector>
#include <unordered_map>

/* Hash Map Approach */
class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.empty() || nums2.empty())
      return vector<int>();

    unordered_map<int, int> map;
    for (int i = 0; i < nums1.size(); ++i) {
      if (map.find(nums1[i]) != map.end())
        map[nums1[i]] += 1;
      else
        map[nums1[i]] = 1;
    }

    vector<int> ans;
    for (int i = 0; i < nums2.size(); ++i) {
      if (map.find(nums2[i]) != map.end() && map[nums2[i]] > 0) {
        ans.push_back(nums2[i]);
        map[nums2[i]] -= 1;
      }
    }

    return ans;
  }
};
/* Time complextiy: O(n)
 * Space complexity: O(n) */
