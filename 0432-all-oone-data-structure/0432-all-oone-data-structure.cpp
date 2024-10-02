class Node{
  public:
    int freq;
    set<string>words;
    Node*next;
    Node*prev;  
    
    Node(int frequency){
        freq = frequency;
        next = NULL;
        prev = NULL;
    }
};
class AllOne {
public:
    Node*head;
    Node*tail;
    unordered_map<string, Node*>wordNode;
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }
    void removeNode(Node* node){
        Node* prevNode = node->prev;
        Node*nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        delete node;
    }
    void inc(string key) {
        if(wordNode.find(key) == wordNode.end()){
            Node*firstNode = head->next;

            if(firstNode == tail || firstNode->freq != 1){
                Node* newNode = new Node(1);
                newNode->words.insert(key);
                newNode->next = firstNode;
                firstNode->prev = newNode;
                newNode->prev = head;
                head->next = newNode;
                wordNode[key] = newNode;
            } else {
                firstNode->words.insert(key);
                wordNode[key] = firstNode;
            }
        } else {
            Node * node = wordNode[key];
            int freq = node->freq;
            node->words.erase(key);

            Node* nextNode = node->next;

            if(nextNode == tail || nextNode->freq != freq +1){
                Node*newNode = new Node(freq+1);
                newNode->words.insert(key);
                newNode->next = nextNode;
                nextNode->prev = newNode;
                newNode->prev = node;
                node->next = newNode;
                wordNode[key] = newNode;
            } else {
                nextNode->words.insert(key);
                wordNode[key] = nextNode;
            }
            if(!node->words.size()){
                removeNode(node);
            }
        }
    }
    
    void dec(string key) {
        if(wordNode.find(key) == wordNode.end()){
            return;
        }
        Node * node = wordNode[key];
        int freq = node->freq;
        node->words.erase(key);
        if(freq == 1){
            wordNode.erase(key);
        } else {
            Node*prevNode = node->prev;
            if(prevNode == head || prevNode->freq != freq-1){
                Node * newNode = new Node(freq-1);
                newNode->words.insert(key);
                newNode->next = node;
                node->prev = newNode;
                newNode->prev = prevNode;
                prevNode->next = newNode;
                wordNode[key] = newNode;
            } else {
                prevNode->words.insert(key);
                wordNode[key]= prevNode;
            }
        }
        if(node->words.size() == 0){
            removeNode(node);
        }
    }
    
    string getMaxKey() {
        if(tail->prev == head) return "";
        return *(tail->prev->words.begin());
    }
    
    string getMinKey() {
        if(head->next == tail) return "";
        return *(head->next->words.begin()); 
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */