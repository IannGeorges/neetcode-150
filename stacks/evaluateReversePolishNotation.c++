class Solution {
    // 1. Stack Method, leverage Last In First Out to match parentheses
    // Time: O(n)
    // Space: O(n/2) or O(n)
public:
    int performOperation(int a, int b, string op) {
        char operand = op[0];
        switch (operand) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                cout << a / b << endl;
                return a / b; 
            default:
                throw std::invalid_argument("Invalid operand");
        }
    }
    int evalRPN(vector<string>& tokens) {
        // key thing to acknowledge is that each operand maybe an int or expression
        // therefore how should I control operations & leverage a stack, when should I push and when should I pop?

        // variables: int to store intermediate & final answer, stack to store numbers
        // whenever I see a number push into stack, when I see an operand I pop the last two values if there's no val stored in intermediate answer, else just pop once and perfom operand between answer & top popped element, order of operation matters so be careful

        if (tokens.size() == 1) {
            return stoi(tokens[0]);
        }
        int ans = INT_MIN;
        deque<int> stack;

        for (string val : tokens) {
            // if we see a number then push value into stack
            // else if we see an operand we perform some intermediate operation
            if (val != "+" && val != "-" && val != "*" && val != "/" ) {
                int num = stoi(val);
                stack.push_back(num);
            } else {
                // if this is the first operand we see pop the last two element in stack (given it's not empty...) & perform operation and store resulting value into ans
                // else we perform the operand between the ans & recently popped value
                
                    int secondNum = stack.back();
                    stack.pop_back();
                    int firstNum = stack.back();
                    stack.pop_back();
                    ans = performOperation(firstNum, secondNum, val);
                    stack.push_back(ans);
                    cout << "first: " << firstNum << endl;
                    cout << "second: " << secondNum << endl;
                    cout << "ans: " << ans << endl;
            }
        }

        return stack.back();
    }
};