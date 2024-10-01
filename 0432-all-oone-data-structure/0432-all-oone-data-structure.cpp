class Node{
public:
    int freq;
    unordered_set<string>words;
    Node*next;
    Node*prev;

    Node(int frequency){
        freq = frequency;
        next = NULL;
        prev = NULL;
    }
};
class AllOne {
Node*head;
Node*tail;
unordered_map<string, Node*>wordMap;
public:
    void removeNode(Node*node){
       Node*nextNode = node->next;
       Node*prevNode = node->prev;
       prevNode->next = nextNode;
       nextNode->prev = prevNode;
       delete node;
    }
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }
    
    void inc(string key) {
        if(wordMap.find(key) == wordMap.end()){
            Node*firstNode = head->next;
            if(firstNode == tail || firstNode->freq > 1){
                Node * newNode = new Node(1);
                newNode->words.insert(key);
                newNode->next = firstNode;
                newNode->prev = head;
                head->next = newNode;
                firstNode->prev = newNode;
                wordMap[key] = newNode;
            } else {
                firstNode->words.insert(key);
                wordMap[key] = firstNode;
            }
        } else {
            Node*node = wordMap[key];
            node->words.erase(key);
            int freq = node->freq;

            Node*nextNode = node->next;
            if(nextNode == tail || nextNode->freq != freq+1){
                Node*newNode = new Node(freq+1);
                newNode->words.insert(key);
                newNode->next = nextNode;
                nextNode->prev = newNode;
                newNode->prev = node;
                node->next = newNode;
                wordMap[key] = newNode;
            } else {
                nextNode->words.insert(key);
                wordMap[key] = nextNode;
            }
            if(node->words.empty()){
                removeNode(node);
            }
        }
    }
    
    void dec(string key) {
        if(wordMap.find(key) == wordMap.end()) return;

        Node*node = wordMap[key];
        node->words.erase(key);
        int freq = node->freq;
        if(freq == 1){
            wordMap.erase(key);
        } else{
            Node*prevNode = node->prev;
            if(prevNode == head || prevNode->freq != freq-1){
                Node*newNode = new Node(freq-1);
                newNode->words.insert(key);
                newNode->next = node;
                node->prev = newNode;
                newNode->prev = prevNode;
                prevNode->next = newNode;
                wordMap[key] = newNode;
            } else {
                prevNode->words.insert(key);
                wordMap[key] = prevNode;
            }
        }
        if(node->words.empty()){
            removeNode(node);
        }
    }
    
    string getMaxKey() {
        if(tail->prev == head ) return "";
        return *(tail->prev->words.begin());
    }
    
    string getMinKey() {
        if(head->next == tail ) return "";
        return *(head->next->words.begin());    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */