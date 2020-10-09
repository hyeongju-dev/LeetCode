/* LeetCode: Single Number
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/549/ */

#include <vector>
#include <unordered_set>

/* Math Apporach
 * 2*(a+b+c) - (a+a+b+b+c) = c */
class Solution {
public:
  int singleNumber(const vector<int>& nums) {
    int sumOfSet = 0, sumOfNums = 0;
    unordered_set<int> set;

    for (int i = 0; i < nums.size(); ++i) {
      if (set.find(nums[i]) == set.end()) {
        set.insert(nums[i]);
        setOfSet += nums[i];
      }
      setOfNums += nums[i];
    }

    return 2*sumOfSet - sumOfNums;
  }
};
/* Time complextiy: O(n+n)=O(n). sum will call next to iterate through nums. We can see it as sum(list(i, for i in nums)) which means the time complexity is O(n) because of the number of elements(n) in nums.
 * Space complexity: O(n+n)=O(n). set needs space for the elements in nums */


/* Bit Manipulation Approach
 * If we take XOR of zero and some bit, it will return that bit
      a⊕0=a
   If we take XOR of two same bits, it will return 0
      a⊕a=0
   a⊕b⊕a=(a⊕a)⊕b=0⊕b=b
 * So we can XOR all bits together to find the unique number. */
class Solution {
public:
  int singleNumber(const vector<int>& nums) {
    int a = 0;
    for (int i = 0; i < nums.size(); ++i)
      a ^= nums[i];
    return a;
  }
};
/* Time complextiy: O(n). We only iterate through nums, so the time complexity is the number of elements in nums.
 * Space complexity: O(1). */
