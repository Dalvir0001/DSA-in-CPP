/*
 Approach:
    - Use two stacks:
        1. s1 -> Used for push operations.
        2. s2 -> Used for pop and peek operations.

    - Push:
        Simply push the new element into s1. (O(1))

    - Pop / Peek:
        If s2 is empty, transfer all elements from s1 to s2.
        This reverses the order and makes the oldest element available
        at the top of s2.
        Then perform pop/peek from s2.

    - Empty:
        Queue is empty only if both stacks are empty.

    Time Complexity:
    - push()  : O(1)
    - pop()   : Amortized O(1)
    - peek()  : Amortized O(1)
    - empty() : O(1)

    Space Complexity:
    - O(n)

    Key Concept:
    Each element is moved from s1 to s2 at most once, giving
    amortized O(1) complexity for pop and peek operations.
*/

// Code :-

class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(!s2.empty()){
            int temp = s2.top();
            s2.pop();
            return temp;
        }
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int temp = s2.top();
        s2.pop();
        return temp;
    }
    
    int peek() {
        if(!s2.empty()){
            int temp = s2.top();
            return temp;
        }
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int temp = s2.top();
        return temp;
    }
    
    bool empty() {
        return s1.empty()&&s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */