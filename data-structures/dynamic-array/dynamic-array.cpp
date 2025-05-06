class DynamicArray {
    private:
        int* myVector;
        int capacity;
        int length;
    
    public:
    
        DynamicArray(int capacity) : capacity(capacity), length(0) {
            myVector = new int[capacity];
        }
    
        int get(int i) {
            return myVector[i];
        }
    
        void set(int i, int n) {
            myVector[i] = n;
        }
    
        void pushback(int n) {
            if (length == capacity)
                resize();
            
            myVector[length] = n;
            length++;
        }
    
        int popback() {
            if (length > 0)
                length--;
            return myVector[length];
        }
    
        void resize() {
            capacity *= 2;
            int *newArr = new int[capacity];
    
            for (int i = 0; i < length; i++) {
                newArr[i] = myVector[i];
            }
    
            delete[] myVector;
            myVector = newArr;
        }
    
        int getSize() {
            return length;
        }
    
        int getCapacity() {
            return capacity;
        }
    };
    