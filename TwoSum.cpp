/*
LeetCode: Two Sum
https://leetcode.com/problems/two-sum/
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> ret;
        size_t numSize = nums.size();

        for(size_t i = 0; i < numSize; ++i) {
            int val = target-nums[i];
            if (hash.find(val) != hash.end()) {
                ret.push_back(i);
                ret.push_back(hash[val]);
                return ret;
            } else {
                hash[nums[i]] = i;
            }
        }

        return ret;
    }
};
