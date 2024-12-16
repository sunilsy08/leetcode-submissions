class Solution {
public:
    struct Comparator{
        bool operator()(pair<int,int>p1, pair<int,int>p2){
            double avg1 = (double)p1.first/(double)p1.second;
            double avg2 = (double)p2.first/(double)p2.second;
            double gain1 = (double)(p1.first+1)/(double)(p1.second+1);
            double gain2 = (double)(p2.first+1)/(double)(p2.second+1);
            return (gain1-avg1) < (gain2-avg2);
        }
    };
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, Comparator>pq;

        for(int i=0; i<classes.size(); i++) {
            pq.push({classes[i][0], classes[i][1]});
        }

        while(extraStudents--) {
            auto curr = pq.top();
            pq.pop();
            pq.push({curr.first+1, curr.second+1});
        }

        double ans = 0;
        double sum = 0.0;

        while(pq.size()) {
            auto curr = pq.top();
            pq.pop();
            sum += (double)curr.first / curr.second;
        }
        return sum/(double)classes.size();
    }
};


// bitgo:

/*
fidxed: 48LPA (includes pf)
relocation bonus: 1 lakh
disc bonus: 4.8 dependnb on perf
esops: 3200 esops in 4 years, apprx 10usd /share no 10 dollar
JB: 2 if joined on 6 jan

no 
800 stocks per year
increase what?

Food : 600 for 2 meals(Zomato) if working from office
Travel: upto 400 per day reimburse
Welness : upto 3k / month

*/
// ?????

// nahi badha rhi kuch
// sab standard h keh rhi h