class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size();
        
        int i = 0;
        int j = n-1;
        int currwt = 0;
        int ans = 0;
        while(i<=j) {
            if((people[i] + currwt) > limit) {
                currwt = 0;
                ans++;
                continue;
            }
            if(people[i] + people[j] <= limit) {
                i++;
                j--;
                ans++;
                currwt = 0;
            }
            else {
                currwt += people[j];
                j--;
            }
        }
        return currwt == 0 ?ans : ans +1;
    }
};