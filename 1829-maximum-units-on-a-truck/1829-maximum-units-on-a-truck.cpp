class Solution {
public:
    static bool cmp(vector<int>&v1, vector<int>&v2){
        return v1[1] > v2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int trucksize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int curr =0;
        int n = boxTypes.size();
        int count =0;
        while(trucksize>0 && curr <n){
            int currUnit = boxTypes[curr][1];
            int canTake = min(boxTypes[curr][0], trucksize);
            count += (canTake*currUnit);
            curr++;
            trucksize -= canTake;
        }
        return count;
    }
};