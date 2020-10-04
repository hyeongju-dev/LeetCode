/*
LeetCode: Remove Duplicates from Sorted Array
https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/727/
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int nsize = (int)nums.size();
        if (nsize == 0)
            return 0;

        int i = 0;
        for (int j = 1; j < nsize; ++j) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }

        return i+1;
    }
};
/*  Time complextiy: O(n). Assume that n is the length of array. Each of i and j traverses at most n steps.
 * Space complexity : O(1). */
