class BrowserHistory {
    private:
        struct node {
            string val;
            node* next;
            node* prev;
    
            node(string val, node* prev = nullptr, node* next = nullptr) : val(val), prev(prev), next(next) {}
        };
    
        node* current;
    
    public:
        BrowserHistory(string homepage) {
            current = new node(homepage);
        }
        
        void visit(string url) {
            node* newPage = new node(url);
            current->next = newPage;
            newPage->prev = current;
            current = newPage;
        }
        
        string back(int steps) {
            node* tmp = current;
            while (steps) {
                if (tmp->prev == nullptr) {
                    current = tmp;
                    return current->val;
                }
                tmp = tmp->prev;
                steps--;
            }
    
            current = tmp;
            return current->val;
        }
        
        string forward(int steps) {
            node* tmp = current;
            while (steps) {
                if (tmp->next == nullptr) {
                    current = tmp;
                    return current->val;
                }
                tmp = tmp->next;
                steps--;
            }
    
            current = tmp;
            return current->val;
        }
    };
    
    /**
     * Your BrowserHistory object will be instantiated and called as such:
     * BrowserHistory* obj = new BrowserHistory(homepage);
     * obj->visit(url);
     * string param_2 = obj->back(steps);
     * string param_3 = obj->forward(steps);
     */
    