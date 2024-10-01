class Node {
public:
    int freq;
    unordered_set<string> words;
    Node* prev;
    Node* next;

    Node() {
        freq = -1;
        prev = NULL;
        next = NULL;
    }

    Node(int frequency) {
        freq = frequency;
        prev = NULL;
        next = NULL;
    }
};

class AllOne {
public:
    Node* head;
    Node* tail;
    unordered_map<string, Node*> wordAddress;

    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }

    void inc(string key) {
        if (wordAddress.find(key) != wordAddress.end()) {
            Node* node = wordAddress[key];
            int freq = node->freq;
            node->words.erase(key);
            Node* nextNode = node->next;

            if (nextNode == tail || nextNode->freq != freq + 1) {
                Node* newNode = new Node(freq + 1);
                newNode->words.insert(key);
                newNode->prev = node;
                newNode->next = nextNode;
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
        } else {
            Node* firstNode = head->next;

            if (firstNode == tail || firstNode->freq > 1) {
                Node* newNode = new Node(1);
                newNode->words.insert(key);
                newNode->next = firstNode;
                newNode->prev = head;
                head->next = newNode;
                firstNode->prev = newNode;
                wordAddress[key] = newNode;
            } else {
                firstNode->words.insert(key);
                wordAddress[key] = firstNode;
            }
        }
    }

    void dec(string key) {
        if (wordAddress.find(key) == wordAddress.end()) {
            return;
        }

        Node* node = wordAddress[key];
        node->words.erase(key);
        int freq = node->freq;

        if (freq == 1) {
            wordAddress.erase(key);
        } else {
            Node* prevNode = node->prev;
            if (prevNode == head || prevNode->freq != freq - 1) {
                Node* newNode = new Node(freq - 1);
                newNode->words.insert(key);

                newNode->next = node;
                newNode->prev = prevNode;
                prevNode->next = newNode;
                node->prev = newNode;

                wordAddress[key] = newNode;
            } else {
                prevNode->words.insert(key);
                wordAddress[key] = prevNode;
            }
        }

        if (node->words.empty()) {
            removeNode(node);
        }
    }

    string getMaxKey() {
        if (tail->prev == head) {
            return "";
        }
        return *(tail->prev->words.begin());
    }

    string getMinKey() {
        if (head->next == tail) {
            return "";
        }
        return *(head->next->words.begin());
    }

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        delete node;
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
