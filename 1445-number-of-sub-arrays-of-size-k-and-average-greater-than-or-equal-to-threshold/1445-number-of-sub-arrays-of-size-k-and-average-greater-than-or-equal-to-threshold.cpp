class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        if(arr.size() <k) return -1;
        int sum = 0;
        int count = 0;
        for(int i=0; i<k; i++){
            sum += arr[i];
        }
        if(sum/k >= threshold) count++;
        int l=0,r=k-1;
        while(r<arr.size()-1){
            sum-= arr[l++];
            sum+= arr[++r];
            if(sum/k >=threshold)count++;
        }
        return count;
        
        
    }
};