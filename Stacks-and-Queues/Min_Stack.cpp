/*
Approach:
- Use two stacks:
  1. Main stack (s1) stores all the elements.
  2. Min stack (s2) stores the minimum elements.
- While pushing, insert into s2 only if the current value is smaller than or equal to the current minimum.
- While popping, if the top of s1 is equal to the top of s2, pop from both stacks.
- The top of s2 always represents the minimum element in the stack.

Time Complexity:
- push()   : O(1)
- pop()    : O(1)
- top()    : O(1)
- getMin() : O(1)

Space Complexity:
- O(n)
*/

// Code :-

class MinStack {
public:
    stack<int> s1,s2;
    MinStack() {
        
    }
    
    void push(int value) {
        s1.push(value);
        if(s2.empty() || value<=s2.top())
        {
            s2.push(value);
        }
    }
    
    void pop() {
        if(s1.top()==s2.top())
        s2.pop();

        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */