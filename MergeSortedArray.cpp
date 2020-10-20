/* LeetCode: Merge Sorted Array
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/96/sorting-and-searching/587/ */

#include <vector>
using namespace std;

// Note: You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int i = m-1, j = n-1, k = m+n-1;

      while (i >= 0 && j >= 0 && k >= 0) {
        if (nums1[i] > nums2[j]) {
          nums1[k--] = nums1[i--];
        } else {
          nums1[k--] = nums2[j--];
        }
      }
      while (j >= 0 && k >= 0) {
        nums1[k--] = nums2[j--];
      } // We don't have to do this for nums1[i--]; cuz it's already located where it should be.
    }
};
/* Time complextiy: O(n+m)
 * Space complexity: O(1) No additional space is needed. */
