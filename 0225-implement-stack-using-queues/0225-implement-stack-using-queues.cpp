class MyStack {
public:
    queue<int>q1,q2;

    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(q1.size()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    
    int pop() {
        if(q1.size()){
            int x = q1.front();
            q1.pop();
            return x;
        }
        return -1;
    }
    
    int top() {
        return q1.size() > 0 ? q1.front() : -1;
    }
    
    bool empty() {
        return q1.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */