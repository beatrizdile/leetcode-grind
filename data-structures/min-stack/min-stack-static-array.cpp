class MinStack {
    private:
        int *ptrStack;
        int capacity;
        int length;
    
        void resize() {
            this->capacity *= 2;
            int *newStack = new int[capacity];
    
            for (int i = 0; i < length; i++) {
                newStack[i] = ptrStack[i];
            }
    
            delete[] ptrStack;
            ptrStack = newStack;
        }
    
    public:
        MinStack() : ptrStack(nullptr), capacity(10), length(0) {
            this->ptrStack = new int[capacity];
        }
        
        void push(int val) {
            if (capacity == length)
                resize();
            
            ptrStack[length] = val;
            length++;
        }
        
        void pop() {
            if (length > 0)
                length--;
        }
        
        int top() {
            if (length == 0)
                throw std::out_of_range("Stack is empty");
    
            return ptrStack[length - 1];
        }
        
        int getMin() {
            if (length == 0)
                throw std::out_of_range("Stack is empty");
    
            int minVal = ptrStack[0];
            for (int i = 0; i < length; i++) {
                if (minVal > ptrStack[i])
                    minVal = ptrStack[i];
            }
    
            return minVal;
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
