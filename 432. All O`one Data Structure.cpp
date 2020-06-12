class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        auto it = m_.find(key);
        //new node
        cout << key <<" front_val_" << l_.front().val <<endl;
        if(it == m_.end()){

            if(l_.front().val != 1){
                unordered_set<string> st;
                st.insert(key);
                Node n({1, st});
                l_.push_front(n);
            }else{
                l_.front().st.insert(key);
            }
            
            m_[key] = l_.begin();
        }else{ //already exist
            auto lit = it->second;
            auto next_lit = next(lit);
            int val = lit->val + 1;
            if(next_lit != l_.end() && next_lit->val == val){
                next_lit->st.insert(key);
                lit->st.erase(key);
                if(lit->st.size() == 0){
                    l_.erase(lit);
                }
                
                m_[key] = next_lit;
            }else{
                if(lit->st.size() == 1){
                    lit->val++;
                }else{
                    lit->st.erase(key);
                    unordered_set<string> st;
                    st.insert(key);
                    Node n({val, st});
                    l_.insert(next_lit, n);
                    m_[key] = next(lit);
                }
            }
        }
        //for_each(m_.begin(),m_.end(),[](auto a){cout<< " inc " << a.first << " " << a.second->val;});
        //cout << endl;
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        auto it = m_.find(key);
        cout << "dec: " << key << endl;
        if(it == m_.end()) return;
        auto lit = it->second;
        auto pre_lit = prev(lit);
        
        if(lit->val == 1){
            m_.erase(it);
        }else{
            if(lit == l_.begin() || pre_lit->val != lit->val - 1)
                pre_lit = l_.insert(lit, {lit->val - 1, {}});

            pre_lit->st.insert(key);
            m_[key] = pre_lit;
        }
        
        lit->st.erase(key);
        cout << "erase: " << key <<endl;
        if(lit->st.size() == 0){
            l_.erase(lit);
        }
        //for_each(m_.begin(),m_.end(),[](auto a){cout<< "d-list " << a.first << " " << a.second->val;});
        //cout << endl;
        //for_each(l_.begin(), l_.end(),[](Node a){cout<< a.val << " ";});
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(!l_.empty()) {
            auto it = l_.back().st.begin();
            for(;it != l_.back().st.end();++it){
                cout << "back: " << *it << endl;
            }
        }
        return l_.empty() ? "": *l_.back().st.cbegin();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(!l_.empty()) {
            auto it = l_.front().st.begin();
            for(;it != l_.front().st.end();++it){
                cout << "front: " << *it << endl;
            }
        }
        return l_.empty() ? "": *l_.front().st.cbegin();
    }
    
private:
    typedef struct node{
        int val;
        unordered_set<string> st;
    }Node;
    list<Node> l_;
    unordered_map<string, list<Node>::iterator> m_;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */