class LRUCache {
public:
    int size;
    list<pair<int,int>>q;
    unordered_map<int, list<pair<int,int>>::iterator>m;
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()){
            return -1;
        }
        int val = m[key]->second;
        q.erase(m[key]);
        q.push_front({key,val});
        m[key] = q.begin();
        return val;
    }
    
    void put(int key, int value) {
         if(m.find(key) != m.end()){
            q.erase(m[key]); 
         }else  if(q.size() == size){
                auto last = q.back();
                q.pop_back();
                m.erase(last.first);
            }
            q.push_front({key,value});
            m[key] = q.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */