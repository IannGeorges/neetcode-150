class Solution {
public:
    // 1. Stack Method, leverage Last In First Out to match parentheses
    // Time: O(n)
    // Space: O(1)
    bool isValid(string s) {
        deque<char> stack;
        if (s.size() % 2 != 0) {
            return false;
        }
        
        for (auto ch : s) {
            // if opening bracket push into stack
            // else check the first element in stack & evaluate if it matches the current closing brack 
            if (ch == '(' || ch == '{' || ch == '[') {
                stack.push_front(ch);
            } else if (!stack.empty()) {
                char temp = stack.front();
                if (temp == '(' && ch != ')') {
                    return false;
                } else if (temp == '{' && ch != '}') {
                    return false;
                } else if (temp == '[' && ch != ']') {
                    return false;
                }
                stack.pop_front();
            } else {
                return false;
            }
        }

        return stack.empty();
    }
};