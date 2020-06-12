class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        const auto it = cache_m_.find(key);
        if(it == cache_m_.end()){
            return -1;
        }else{
            cache_.splice(cache_.begin(), cache_, it->second);
            return it->second->second;
        }
    }
    
    void put(int key, int value) {
        const auto it = cache_m_.find(key);
        if(it == cache_m_.end()){
            if(capacity_ == 0){
                auto d = cache_.back();
                cache_.pop_back();
                cache_m_.erase(d.first);
                cout << "erase: " << d.first <<endl;
                capacity_++;
            }
            
            pair<int,int> node(key,value);
            cache_.push_front(node);
            cache_m_[key] = cache_.begin();
            capacity_--;
            cout << "put: " << key << "capacity: "<< capacity_ <<endl;
        }else{
            it->second->second = value;
            cache_.splice(cache_.begin(), cache_, it->second);
        }
    }
    
private:    
    int capacity_;
    unordered_map<int,list<pair<int,int>>::iterator> cache_m_;
    list<pair<int,int>> cache_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */