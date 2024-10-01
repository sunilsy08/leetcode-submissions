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
public:
    Node*head;
    Node*tail;
    unordered_map<string, Node*>wordAddress;
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
    void inc(string key) {
        if(wordAddress.find(key) == wordAddress.end()){
            Node * firstNode = head->next;

            if(firstNode == tail || firstNode->freq > 1){
                Node*newNode = new Node(1);
                newNode->words.insert(key);
                newNode->next = firstNode;
                firstNode->prev = newNode;
                head->next = newNode;
                newNode->prev = head;
                wordAddress[key] = newNode;
            }else {
                firstNode->words.insert(key);
                wordAddress[key] = firstNode;
            }
        } else {
            Node*node = wordAddress[key];
            int freq = node->freq;
            node->words.erase(key);
            // wordAddress.erase(key);
            Node*nextNode = node->next;
            if(nextNode == tail || nextNode->freq != freq+1){
                Node*newNode = new Node(freq+1);
                newNode->words.insert(key);
                newNode->next = nextNode;
                newNode->prev = node;
                node->next = newNode;
                nextNode->prev = newNode;
                wordAddress[key] = newNode;
            } else {
                nextNode->words.insert(key);
                wordAddress[key] = nextNode;
            }
            if (node->words.empty()) {
                removeNode(node);
            }
        }
    }
    
    void dec(string key) {
        if(wordAddress.find(key) == wordAddress.end()) return;

        Node*node = wordAddress[key];
        int freq = node->freq;
        node->words.erase(key);
        wordAddress.erase(key);

        Node*prevNode =node->prev;
        if(freq == 1) {
            wordAddress.erase(key);
            // return;
        } else if(prevNode == head || prevNode->freq != freq-1){
            Node*newNode = new Node(freq-1);
            newNode->words.insert(key);
            newNode->prev = prevNode;
            newNode->next = node;
            node->prev = newNode;
            prevNode->next = newNode;
            wordAddress[key] = newNode;
        } else {
            prevNode->words.insert(key);
            wordAddress[key] = prevNode;
        }
        if (node->words.empty()) {
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