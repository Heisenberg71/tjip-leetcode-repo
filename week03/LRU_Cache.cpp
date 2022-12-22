class LRUCache {
public:
    list <int> lru;
    int max_cap;
    unordered_map <int, int> key_value;
    unordered_map <int, list<int> :: iterator> addressOf;
    LRUCache(int capacity) {
        max_cap = capacity;
    }
    
    int get(int key) {
        if(key_value.count(key) == 0) return -1;
        updateLRU(key);
        return key_value[key];
    }
    
    void put(int key, int value) {
        if(key_value.size() == max_cap && key_value.count(key) == 0)
            evict();
        updateLRU(key);
        key_value[key] = value;
    }

    void updateLRU(int key){
        if(key_value.count(key)) lru.erase(addressOf[key]);
        lru.push_front(key);
        addressOf[key] = lru.begin();

    }

    void evict(){
        addressOf.erase(lru.back());
        key_value.erase(lru.back());
        lru.pop_back();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
