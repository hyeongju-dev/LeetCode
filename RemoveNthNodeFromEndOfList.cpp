/* LeetCode: Remove Nth Node From End of List
 * https://leetcode.com/problems/fibonacci-number/ */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      if (head == nullptr)
        return head;

      ListNode* dummy = new ListNode(0);
      dummy->next = head;

      ListNode* fast = dummy;
      ListNode* slow = dummy;

      for (int i = 0; i < n; ++i)
        fast = fast->next;

      while (fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
      }

      slow->next = slow->next->next;

      return dummy->next;
    }
};
/*  Time complextiy: O(L). The algorithm makes one traversal of the list of L nodes. Therefore time complexity is O(L).
 * Space complexity: O(1). We only used constant extra space. */
