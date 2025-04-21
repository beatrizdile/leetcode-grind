class LRUCache {
    private:
        unordered_map<int, int> cache;
        vector<int> accesed;
        int maxCapacity;
        int currentCapacity;
    
    public:
        LRUCache(int capacity) : maxCapacity(capacity), currentCapacity(0) {}
        
        int get(int key) {
            if (cache.count(key) == 0)
                return -1;
            
            accesed.erase(find(accesed.begin(), accesed.end(), key));
            accesed.push_back(key);
            return cache[key];
        }
        
        void put(int key, int value) {
            if (cache.count(key) != 0) {
                cache[key] = value;
                accesed.erase(find(accesed.begin(), accesed.end(), key));
                accesed.push_back(key);
            }
            else if (currentCapacity + 1 <= maxCapacity) {
                cache[key] = value;
                currentCapacity++;
                accesed.push_back(key);
            }
            else {
                cache.erase(accesed.front());
                accesed.erase(accesed.begin());
                cache[key] = value;
                accesed.push_back(key);
            }
    
        }
    };
    
    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache* obj = new LRUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */
