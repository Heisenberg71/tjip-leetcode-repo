// Every operation is O(1)

mt19937 rnd(0);

class RandomizedSet {
public:
    vector <int> store;
    unordered_map <int, int> index;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(!index.count(val)){
            index[val] = store.size();
            store.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(index.count(val)){
            int current_index = index[val];
            index[ store.back() ] = current_index;
            swap(store[current_index], store.back());
            index.erase(val);
            store.pop_back();
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int random_index = rnd()%store.size();
        return store[random_index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
