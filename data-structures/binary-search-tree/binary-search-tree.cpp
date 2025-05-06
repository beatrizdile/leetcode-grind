class TreeMap {
    private:
        class Node {
            public:
                int key;
                int val;
                Node* left;
                Node* right;
    
                Node(int key, int val, Node* left = nullptr, Node* right = nullptr) : key(key), val(val), left(left), right(right) {}
        };
    
        Node* head;
    
    public:
        TreeMap() : head(nullptr){}
    
        Node* insertNode(Node* node, int key, int val) {
            if (node == nullptr)
                return new Node(key, val);
            
            if (node->key > key)
                node->left = insertNode(node->left, key, val);
            else if (node->key < key)
                node->right = insertNode(node->right, key, val);
            else
                node->val = val;
            
            return node;
        }
    
        void insert(int key, int val) {
            head = insertNode(head, key, val);
        }
    
        int get(int key) {
            Node* curr = head;
    
            while (curr != nullptr) {
                if (curr->key > key)
                    curr = curr->left;
                else if (curr->key < key)
                    curr = curr->right;
                else
                    return curr->val;
            }
    
            return -1;
        }
    
        int getMin() {
            Node* cur = head;
            if (cur == nullptr)
                return -1;
            
            while (cur->left != nullptr)
                cur = cur->left;
    
            return cur->val;
        }
    
        int getMax() {
            Node* cur = head;
            if (cur == nullptr)
                return -1;
            
            while (cur->right != nullptr)
                cur = cur->right;
    
            return cur->val;
        }
    
        Node* findMinNode(Node* node) {
            if (node == nullptr)
                return nullptr;
            
            Node* cur = node;
            while (cur->left != nullptr)
                cur = cur->left;
    
            return cur;
        }
    
        Node* removeNode(Node* node, int key) {
            if (node == nullptr)
                return nullptr;
                
            if (node->key < key)
                node->right = removeNode(node->right, key);
            else if (node->key > key)
                node->left = removeNode(node->left, key);
            else {
                if (node->left == nullptr)
                    return node->right;
                else if (node->right == nullptr)
                    return node->left;
                else {
                    Node* min = findMinNode(node->right);
                    node->val = min->val;
                    node->key = min->key;
                    node->right = removeNode(node->right, min->key);
                }
            }
    
            return node;
        }
    
        void remove(int key) {
            head = removeNode(head, key);
        }
    
        void traverseInorder(std::vector<int>& result, Node* node) {
            if (node == nullptr)
                return ;
    
            traverseInorder(result, node->left);
            result.push_back(node->key);
            traverseInorder(result, node->right);
        }
    
        std::vector<int> getInorderKeys() {
            std::vector<int> result;
            traverseInorder(result, head);
            return result;
        }
    };
    