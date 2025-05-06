class MinStack {
    private:
        stack<int> myStack;
        stack<int> minStack;
    
    public:
        MinStack(){}
        
        void push(int val) {
            myStack.push(val);
    
            if (!minStack.empty() && minStack.top() < val)
                minStack.push(minStack.top());
            else
                minStack.push(val);
        }
        
        void pop() {
            if (!myStack.empty() && !minStack.empty()) {
                myStack.pop();
                minStack.pop();
            }
        }
        
        int top() {
            return myStack.top();
        }
        
        int getMin() {
            return minStack.top();
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
