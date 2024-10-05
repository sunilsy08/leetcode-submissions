class RandomizedCollection {
public:
    vector<int>data;
    unordered_map<int,unordered_set<int>>indices;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool isNew = indices[val].size() == 0;
        data.push_back(val);
        indices[val].insert(data.size()-1);
        return isNew;
    }
    
    bool remove(int val) {
        if(indices[val].empty()) return false;

        int removingIndex = *indices[val].begin();
        indices[val].erase(removingIndex);
        int lastElement = data.back();

        data[removingIndex] = lastElement;
        indices[lastElement].insert(removingIndex);
        indices[lastElement].erase(data.size() - 1);
        data.pop_back();
        if(indices[val].empty()){
            indices.erase(val);
        }
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand()%data.size();
        return data[randomIndex];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */