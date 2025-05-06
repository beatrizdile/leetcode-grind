class Deque {
    private:
        struct node {
            int val;
            node* next;
            node* prev;
    
            node(int val, node* prev = nullptr, node* next = nullptr) : val(val), prev(prev), next(next) {}
        };
        node* head;
        node* tail;
    
    public:
        Deque() : head(nullptr), tail(nullptr) {}
    
        bool isEmpty() {
            if (head == nullptr)
                return true;
            return false;
        }
    
        void append(int value) {
            node* newNode = new node(value);
    
            if (tail != nullptr) {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
            else {
                tail = newNode;
                head = newNode;
            }
        }
    
        void appendleft(int value) {
            node* newNode = new node(value);
    
            if (head != nullptr) {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            else {
                tail = newNode;
                head = newNode;
            }
        }
    
        int pop() {
            if (tail != nullptr) {
                int val = tail->val;
                tail = tail->prev;
                if (tail == nullptr)
                    head = nullptr;
                else
                    tail->next = nullptr;
    
                return val;
            }
            return -1;
        }
    
        int popleft() {
            if (head != nullptr) {
                int val = head->val;
                head = head->next;
                if (head == nullptr)
                    tail = nullptr;
                else
                    head->prev = nullptr;
                
                return val;
            }
    
            return -1;
        }
    };
    