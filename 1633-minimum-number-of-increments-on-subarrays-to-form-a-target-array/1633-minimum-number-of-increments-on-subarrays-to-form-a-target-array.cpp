class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        // Initialize the result with the value of the first element
        int operations = target[0];
        
        // Loop through the target array and count the increments
        for (int i = 1; i < target.size(); i++) {
            if (target[i] > target[i - 1]) {
                operations += target[i] - target[i - 1];
            }
        }
        
        return operations;
    }
};
