class Solution {
public:
    vector<int>data;
    Solution(vector<int>& w) {
        data.push_back(w[0]);
        for(int i=1; i<w.size(); i++){
            data.push_back(data[i-1] + w[i]);
        }
    }
    
    int pickIndex() {
        int randomWeight = rand() %data.back();
        int sum =0;
        return upper_bound(data.begin(), data.end(), randomWeight) - data.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */