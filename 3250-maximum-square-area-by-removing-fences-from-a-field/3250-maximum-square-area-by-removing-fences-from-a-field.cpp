class Solution {
public:
    unordered_set<int> findPossibleSides(vector<int>fencePositions, int n){
        fencePositions.push_back(1);
        fencePositions.push_back(n);
        sort(fencePositions.begin(), fencePositions.end());

        unordered_set<int>sides;

        for(size_t i=0; i<fencePositions.size(); i++){
            for(size_t j=i+1; j<fencePositions.size(); j++){
                int side = fencePositions[j] - fencePositions[i];
                sides.insert(side);
            }
        }
        return sides;
    }
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        unordered_set<int>toplen = findPossibleSides(vFences, n);
        unordered_set<int>sidelen = findPossibleSides(hFences, m);
        int ans = -1;
        for(auto side: toplen){
            if(side > 0 && sidelen.count(side) > 0){
                ans = max(ans, side);
            }
        }
        long long mod = 1e9 + 7;
        long res = ((long)ans*ans)%(mod);
        return ans == -1 ? ans : res;
    }
};