class Node {
public:
    int data;
    int curr_max;
    Node* next;
    
    Node() {
    }
    
    Node(int val) {
        this->data = val;
        next = NULL;
    }
};

class MyStack {
public:
    Node* head;
    MyStack() {
        head = NULL;
    }
    
    void push(int x) {
        if(head == NULL){
            head = new Node(x);
            head->curr_max = x;
        } else{
            Node * temp = new Node(x);
            temp->curr_max = max(head->curr_max, x);
            temp->next = head;
            head = temp;
        }
    }
    
    int pop() {
        int x = head->data;
        head = head->next;
        return x;
    }
    
    int top() {
        return head->data;
    }
    
    bool empty() {
        return head == NULL;
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