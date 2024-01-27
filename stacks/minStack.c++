class MinStack {
vector<pair<int, int>> stack;
int minVal;
public:
    // 1. Use a vector with pairs as elements, first element stores the value, second element stores relative global min
    // Time: O(1)
    // Space: O(n)
    // use vector to implement stack, don't have to worry about memory allocation, can push/pop from back
    // class constructor need to review
    // to get min keep track of global min whenever you push/pop to retrieve min val in constant time O(1)
    // however whenever we pop, how do we access the second minimum val in our stack in O(1), should we use a minHeap? insertion/pop is lognm, store a pair in stack, first element is the value & second element is the current minimum at that level
    // consider data type unsigned, signed long long etc. (int should suffice)
    // beware of accessing empty data structure, illegal access can cause overflow issues
    // if there are memory constraints on hardware we can use an array and directly allocate space if we know the limits of our input 
    MinStack() : minVal(INT_MAX) { }

    void push(int val) {
        if (stack.empty()) {
            minVal = val;
            stack.push_back({val, val});
        } else {
            minVal = min(val, minVal);
            stack.push_back({val, minVal});
        }
    }
    
    void pop() {
        if (stack.empty()) {
            minVal = INT_MAX;
        } else {
            stack.pop_back();
            if (!stack.empty())
            minVal = stack.back().second;
        }
       
    }
    
    int top() {
        return stack.back().first;
    }
    
    int getMin() {
        cout << stack.back().first << endl;
        cout << stack.back().second << endl;
        return stack.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */