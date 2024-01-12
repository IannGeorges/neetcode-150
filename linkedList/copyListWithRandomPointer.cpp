/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // 1. Two Pass Method, use a map to associate old nodes with new nodes in order to ease reconstructing the random ptrs
    // Time: O(2n) = O(n)
    // Space: O(n)
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> dict;
        Node* newHead = new Node(INT_MIN);
        Node* newList = newHead;
        Node* curr = head;
        while (curr != NULL) {
            newList->next = new Node(curr->val);
            dict[curr] = newList->next;
            newList = newList->next;
            curr = curr->next;
            
        }
        curr = head;
        newList = newHead;
        while (curr != NULL) {
            Node* random = curr->random;
            newList->next->random = dict.find(random) != dict.end() ? dict[random] : NULL;
            newList = newList->next;
            curr = curr->next;
        }

        return newHead->next;
    }

    // 2. Three Pass with no use of map
    // Time: O(3n) = O(n)
    // Space: O(1)
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        Node* curr = head;
        while (curr != NULL) {
            // create the cloned node
            Node* newNode = new Node(curr->val);
            // set the cloned's next ptr to the same as our original node
            newNode->next = curr->next;
            // then set the original node's next ptr to our cloned node
            curr->next = newNode;
            // move the original node's to its next orignal node (which is now our cloned node's next value)
            curr = newNode->next;
        }

        Node* original = head;
        
        while (original != NULL) {
            // here we set the clone to the random next node only if it's not null since we know our clone node is adjacent to the right 
            original->next->random = (original->random != NULL) ? original->random->next : NULL;
            // move the original pointer to it's next node
            original = original->next->next;
        }

        original = head;
        Node* newHead = head->next;
        Node* clone = newHead;
        while (original != NULL) {
            original->next = original->next->next;
            clone->next = clone->next != NULL ? clone->next->next : NULL;
            original = original->next;
            clone = clone->next;
        }
        return newHead;
    }
};