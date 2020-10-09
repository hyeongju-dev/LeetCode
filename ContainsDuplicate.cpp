/* LeetCode: Contains Duplicate
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/578/ */

#include <vector>
#include <algorithm>
#include <unordered_set>

/* Sorting Approach
 * In general, it is not a good practice to modify the input unless it is clear to the caller that the input will be modified. */
class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    if (nums.size() == 0)   // DO NOT MISS THIS CASE
      return false;

    vector<int> tmp;
    tmp.assign(nums.begin(), nums.end());

    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < tmp.size()-1; ++i)
      if (tmp[i] == tmp[i+1])
        return true;
    return false;
  }
};
/* Time complextiy: O(nlogn). Sorting is O(nlog⁡n) and the sweeping is O(n). The entire algorithm is dominated by the sorting step, which is O(nlog⁡n).
 * Space complexity: O(1). Space depends on the sorting implementation which, usually, costs O(1) auxiliary space if heapsort is used. <= BUT I made a copy of nums so O(n) ! */


/* Hash Table Approach */
class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> set;
    for (int i = 0; i < nums.size(); ++i) {
      if (set.find(nums[i]) != set.end())
        return true;
      set.insert(nums[i]);
    }
    return false;
  }
};
/* Time complextiy: O(n). We do search() and insert() for n times and each operation takes constant time.
 * Space complexity: O(n). The space used by a hash table is linear with the number of elements in it. */
