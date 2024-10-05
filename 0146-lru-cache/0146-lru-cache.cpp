class LRUCache {
public:
    list<pair<int,int>>dq;
    unordered_map<int, list<pair<int,int>>::iterator>m;
    int size=0;
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()){
            return -1;
        }
        auto it = m[key];
        pair<int,int>p = *it;
        int ans = p.second;;
        dq.erase(it);
        dq.push_front({key, ans});
        m[key] = dq.begin();
        return ans;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            auto it = m[key];
            pair<int,int>p = *it;
            dq.erase(it);
            dq.push_front({key,value});
            m[key] = dq.begin();
        } else {
            if(dq.size() >= size){
                pair<int,int>p = dq.back();
                m.erase(p.first);
                dq.pop_back();
            }
            dq.push_front({key,value});
            m[key] = dq.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */