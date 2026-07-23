/*

Approach:
- Use a single queue.
- Push the new element into the queue.
- Rotate the previous elements behind the new one.
- The front of the queue always represents the top of the stack.

Time Complexity:
- push()  : O(n)
- pop()   : O(1)
- top()   : O(1)
- empty() : O(1)

Space Complexity:
- O(n)
*/

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        if(q.empty())
        {
            q.push(x);
        }
        else{
            q.push(x);
            int size = q.size();
            for(int i=1 ; i<size ; i++)
            {
                q.push(q.front());
                q.pop();
            }
        }

    }
    
    int pop() {
        int temp = q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */