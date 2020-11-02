/* LeetCode: Kth Largest Element in an Array
 * https://leetcode.com/problems/kth-largest-element-in-an-array/ */

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      priority_queue<int, vector<int>, greater<int> > minHeap;
      for (int i : nums) {
        minHeap.push(i);
        if (minHeap.size() > k)
          minHeap.pop();
      }
      return minHeap.top();
    }
};
/* Time complextiy: O(logn)
 * Space complexity: O(k) */

/* sample 0 ms submission */
class Solution {
public:
    int partition(vector<int> &a,int low,int high) {
      int pi = low - 1;
      int offset = rand() % (high-low+1);
      swap(a[high], a[low+offset]);
      int pivot = a[high];
      for (int i = low; i < high; ++i)
        if(a[i] <= pivot)
          swap(a[i], a[++pi]);

      swap(a[high], a[++pi]);
      return pi;
    }

    void kMax(vector<int> &a,int low,int high,int k) {
      if(low < high) {
        int pi = partition(a, low, high);
        if (pi == a.size()-k)
          return;
        else if (pi < a.size()-k)
          kMax(a, pi+1, high, k);
        else
          kMax(a, low, pi-1, k);
      }
    }

    int findKthLargest(vector<int>& nums, int k) {
      kMax(nums, 0, nums.size()-1, k);
      return nums[nums.size()-k];
    }
};
