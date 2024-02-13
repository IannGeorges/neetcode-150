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
    // 1. Merge Two List approach 
    // Time:  = O(m+n)
    // Space: O(m+n)
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // create a new list along with pointer pointing to the head/start of linked-list

        ListNode* head = new ListNode(-1);
        ListNode* dummy = head;

        while (list1 != NULL && list2 != NULL) {
            // if list1 curr val is less than list2 curr val add it to new linked list and move the ptrs to next node
            // else add list2 curr val 
            if (list1->val < list2->val) {
                dummy->next = new ListNode(list1->val);
                dummy = dummy->next;
                list1 = list1->next;
            } else {
                dummy->next = new ListNode(list2->val);
                dummy = dummy->next;
                list2 = list2->next;
            }
        }

        // edge case when both list aren't same length append the rest of the linked list
        while (list1 != NULL) {
            dummy->next = new ListNode(list1->val);
            dummy = dummy->next;
            list1 = list1->next;
        }

        while (list2 != NULL) {
            dummy->next = new ListNode(list2->val);
            dummy = dummy->next;
            list2 = list2->next;
        }

        return head->next;
    }
};