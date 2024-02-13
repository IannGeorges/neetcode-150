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
//  Iterative Addition & Carry Solution 
// Time: O(max(l1, l2))
// Space: O(max(l1,l2))
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newList = new ListNode(-1);
        ListNode* dummy = newList;
        int carry = 0; 
        int sum = 0;
        while (l1 != NULL || l2 != NULL || carry) {
            int val1 = 0; int val2 =0;
            if (l1 != NULL) {
                val1 = l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                val2 = l2->val;
                l2 = l2->next;
            }
            sum = val1 + val2 + carry;
            carry = sum/10;
            sum %= 10;
            dummy->next = new ListNode(sum);
            dummy = dummy->next;
        } 

        return newList->next;
    }
};


class Solution {
public:
//  Recursive Addition & Carry Solution 
// Time: O(max(l1, l2))
// Space: O(max(l1,l2))
    ListNode* addTwoNumbersRecursive(ListNode* l1, ListNode* l2, int carry = 0) {
        if (!l1 && !l2 && carry == 0) {
            return nullptr; // Base case: both lists are fully traversed and no carry
        }

        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next; // Move to the next node in l1
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next; // Move to the next node in l2
        }

        ListNode* node = new ListNode(sum % 10); // Create a new node with the sum's last digit
        carry = sum / 10; // Calculate new carry

        // Recursively call for the next nodes and the carry
        node->next = addTwoNumbersRecursive(l1, l2, carry);

        return node;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbersRecursive(l1, l2, 0); // Start recursion with no initial carry
    }
};