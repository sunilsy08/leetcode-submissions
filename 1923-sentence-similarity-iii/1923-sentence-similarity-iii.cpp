class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        
        deque<string>dq1,dq2;

        stringstream s1(sentence1);
        stringstream s2(sentence2);
        if(sentence2.size() > sentence1.size()){
            swap(s1,s2);
        }
        string word;
        while(s1>> word){
            dq1.push_back(word);
        }
        while(s2 >> word){
            dq2.push_back(word);
        }

        while(!dq1.empty() && !dq2.empty() && dq1.front() == dq2.front()){
            dq1.pop_front();
            dq2.pop_front();
        }

        while(!dq1.empty() && !dq2.empty() && dq1.back() == dq2.back()){
            dq1.pop_back();
            dq2.pop_back();
        }
        return dq2.empty();

    }
};