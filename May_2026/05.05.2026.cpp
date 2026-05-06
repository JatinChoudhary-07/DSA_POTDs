/*
LC 61: Rotate List
Topic: Linked List
Approach: Circular Linked List
Time: O(n)
Space: O(1)
*/

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
    ListNode* rotateRight(ListNode* head, int k) {

        if (!head || !head->next || k == 0)
            return head;

        int len = 1;

        ListNode* tail = head;

        while (tail->next) {
            tail = tail->next;
            len++;
        }

        k = k % len;

        if (k == 0)
            return head;

        int remainingNodes = len - k;

        tail->next = head;

        ListNode* newTail = head;

        for (int i = 1; i < remainingNodes; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;

        newTail->next = NULL;

        return newHead;
    }
};
