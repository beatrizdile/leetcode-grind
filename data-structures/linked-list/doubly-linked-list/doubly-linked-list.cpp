class MyLinkedList {
    private:
        struct node {
            int val;
            node* prev;
            node* next;
    
            node(int v, node* prev = nullptr, node* next = nullptr) : val(v), prev(prev), next(next) {}
        };
    
        node* head;
        node* tail;
    
    public:
        MyLinkedList() {
            head = new node(-1);
            tail = head;
        }
        
        int get(int index) {
            node* cur = head->next;
            int i = 0;
    
            while (i < index && cur != nullptr) {
                cur = cur->next;
                i++;
            }
    
            if (cur == nullptr)
                return -1;
    
            return cur->val;
        }
        
        void addAtHead(int val) {
            node* tmp = head->next;
            node* newNode = new node(val, head, tmp);
            head->next = newNode;
    
            if (tmp != nullptr) {
                tmp->prev = newNode;
            }
    
            if (tail == head)
                tail = head->next;
        }
        
        void addAtTail(int val) {
            tail->next = new node(val, tail, nullptr);
            tail = tail->next;
        }
        
        void addAtIndex(int index, int val) {
            if (index == 0) {
                addAtHead(val);
                return ;
            }
    
            node* cur = head->next;
            int i = 0;
    
            while (i < index && cur != nullptr) {
                cur = cur->next;
                i++;
            }
    
            if (i == index && cur == nullptr) {
                addAtTail(val);
                return ;
            }
    
            if (cur == nullptr)
                return ;
    
            node* newNode = new node(val, cur->prev, cur);
            if (cur->prev != nullptr)
                cur->prev->next = newNode;
    
            cur->prev = newNode;
        }
        
        void deleteAtIndex(int index) {
            node* cur = head->next;
            int i = 0;
    
            while (i < index && cur != nullptr) {
                cur = cur->next;
                i++;
            }
    
            if (cur == nullptr)
                return ;
    
            node* previous = cur->prev;
            node* next = cur->next;
    
            if (cur == tail) {
                if (next != nullptr)
                    tail = next;
                else
                    tail = previous;
            }
    
            if (previous != nullptr) {
                previous->next = next;
            }
    
            if (next != nullptr) {
                next->prev = previous;
            }
    
            delete cur;
        }
    };
    
    /**
     * Your MyLinkedList object will be instantiated and called as such:
     * MyLinkedList* obj = new MyLinkedList();
     * int param_1 = obj->get(index);
     * obj->addAtHead(val);
     * obj->addAtTail(val);
     * obj->addAtIndex(index,val);
     * obj->deleteAtIndex(index);
     */
