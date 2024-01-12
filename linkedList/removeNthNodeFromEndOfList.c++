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
    // 1. Two Pass Approach
    // Time: O(2n) = O(n)
    // Space: O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // idea, solve by doing two pass
        // first pass to get size of list
        int sz = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            sz++;
            curr = curr->next;
        }
        // second to remove link and delete node
        int pos = sz-n;
        // Use a dummy head in case of edge case where there's only 1 pointer
        ListNode* newHead = new ListNode(-1, head);
        curr = newHead;
        while (pos > 0) {
            pos--;
            curr = curr->next;
        }

        ListNode* deleteNode = curr->next;
        curr->next = curr->next->next;
        delete deleteNode;
        return newHead->next;

    }

    // 2. One Pass Method - Slow & Fast Pointer separated by a distance of n
    // Time: O(n)
    // Space: O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int idx = n;
        ListNode* newHead = new ListNode(-1, head);
        ListNode* fast = newHead;
        ListNode* slow = newHead;

        while (idx > 0) {
            fast = fast->next;
            idx--;
        }

        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* deleteNode = slow->next;
        slow->next = slow->next->next;
        delete deleteNode;

        return newHead->next; 
    }
};