class RandomizedSet {
public:
    vector<int>data;
    unordered_map<int,int>index;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(index.find(val) == index.end()){
            data.push_back(val);
            index[val] = data.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(index.find(val) == index.end()){
            return false;
        }
        int ind = index[val];
        swap(data[ind], data[data.size()-1]);
        index[data[ind]] = ind;
        data.pop_back();
        index.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % data.size();
        return data[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */