class FreqStack {
public:
    map<int,list<int>>elementsWithFrequency;
    map<int,int>frequency;
    int maxFrequency = 0;
    FreqStack() {
        
    }
    void push(int val) {
        frequency[val]++; 
        int freq = frequency[val];
        elementsWithFrequency[freq].push_back(val);  
        maxFrequency = max(maxFrequency, freq);  
    }

    int pop() {
        // cout<<" max freq: "<< maxFrequency<<" ";
        if(elementsWithFrequency.find(maxFrequency) == elementsWithFrequency.end()){
            return -1;
        }
        auto& elements = elementsWithFrequency[maxFrequency];
        int topElement = elements.back();
        elements.pop_back();
        frequency[topElement]--;
        if(elements.empty()){
            elementsWithFrequency.erase(maxFrequency);
            maxFrequency--;
        }
        if(frequency[topElement] == 0){
            frequency.erase(topElement);
        }
        return topElement;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */