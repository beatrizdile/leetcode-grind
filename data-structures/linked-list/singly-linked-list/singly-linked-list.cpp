class LinkedList {
    private:
        struct node {
            int val;
            node* next;
    
            node(int v, node* n = nullptr) : val(v), next(n) {}
        };
    
        node* head;
        node* tail;
    
    public:
        LinkedList() : head(nullptr), tail(nullptr) {}
    
        int get(int index) {
            int i = 0;
            node* cur = head;
    
            while (cur != nullptr && i < index) {
                cur = cur->next;
                i++;
            }
    
            return (cur != nullptr) ? cur->val : -1;
        }
    
        void insertHead(int val) {
            node* newNode = new node(val, head);
            head = newNode;
    
            if (tail == nullptr)
                tail = newNode;
    
        }
        
        void insertTail(int val) {
            node* newNode = new node(val);
            if (tail != nullptr)
                tail->next = newNode;
            
            if (head == nullptr)
                head = newNode;
    
            tail = newNode;
        }
    
        bool remove(int index) {
            if (head == nullptr)
                return false;
    
            if (index == 0) {
                node* tmp = head;
                head = tmp->next;
    
                if (head == nullptr) {
                    tail = nullptr;
                }
    
                delete tmp;
                return true;
            }
    
            node* previous = nullptr;
            node* cur = head;
    
            int i = 0;
            while (cur != nullptr && i < index) {
                previous = cur;
                cur = cur->next;
                i++;
            }
    
            if (cur == nullptr)
                return false;
    
            if (cur->next != nullptr) {
                previous->next = cur->next;
            }
            else {
                previous->next = nullptr;
                tail = previous;
            }
    
            delete cur;
            return true;
        }
    
        vector<int> getValues() {
            vector<int> values;
    
            node* cur = head;
            while (cur != nullptr) {
                values.push_back(cur->val);
                cur = cur->next;
            }
    
            return values;
        }
    };
    