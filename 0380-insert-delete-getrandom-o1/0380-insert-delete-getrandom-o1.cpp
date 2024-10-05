class RandomizedSet {
public:
    unordered_map<int, int> m;  // Map from value to its index in the deque
    deque<int> dq;  // Deque to store the elements
    
    RandomizedSet() {}
    
    bool insert(int val) {
        if (m.find(val) == m.end()) {
            dq.push_back(val);  // Insert element at the back of the deque
            m[val] = dq.size() - 1;  // Store the index of the new element
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (m.find(val) == m.end()) {
            return false;
        }
        
        // Get the index of the element to remove
        int idx = m[val];
        // Swap the element with the last element in the deque
        dq[idx] = dq.back();
        // Update the map for the element that was swapped
        m[dq[idx]] = idx;
        // Remove the last element
        dq.pop_back();
        // Erase the element from the map
        m.erase(val);
        
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % dq.size();  // Generate a random index
        return dq[randomIndex];  // Directly access the element at the random index
    }
};
