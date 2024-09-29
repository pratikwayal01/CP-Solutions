#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class AllOne {
private:
    struct Node {
        int count;
        unordered_set<string> keys;
        Node* prev;
        Node* next;
        Node(int c) : count(c), prev(nullptr), next(nullptr) {}
    };

    Node* head;  
    Node* tail;  
    
    unordered_map<string, int> keyCountMap;       
    unordered_map<int, Node*> countNodeMap;       


    void addNodeAfter(Node* newNode, Node* prevNode) {
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        prevNode->next->prev = newNode;
        prevNode->next = newNode;
    }

 
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }


    void insertKey(const string& key, int count) {
        if (countNodeMap.find(count) == countNodeMap.end()) {
            Node* newNode = new Node(count);
            countNodeMap[count] = newNode;

            Node* prevNode = tail->prev;
            while (prevNode != head && prevNode->count > count) {
                prevNode = prevNode->prev;
            }
            addNodeAfter(newNode, prevNode);
        }
        countNodeMap[count]->keys.insert(key);
    }


    void removeKey(const string& key, int count) {
        Node* node = countNodeMap[count];
        node->keys.erase(key);
        if (node->keys.empty()) {
            removeNode(node);
            countNodeMap.erase(count);
        }
    }

public:
  
    AllOne() {
        head = new Node(INT_MIN);  
        tail = new Node(INT_MAX);  
        head->next = tail;
        tail->prev = head;
    }
    
    void inc(string key) {
        if (keyCountMap.find(key) != keyCountMap.end()) {
            int currentCount = keyCountMap[key];
            removeKey(key, currentCount);
            keyCountMap[key] = currentCount + 1;
        } else {
            keyCountMap[key] = 1;
        }
        insertKey(key, keyCountMap[key]);
    }

    void dec(string key) {
        if (keyCountMap.find(key) == keyCountMap.end()) return;

        int currentCount = keyCountMap[key];
        removeKey(key, currentCount);

        if (currentCount == 1) {
            keyCountMap.erase(key);  
        } else {
            keyCountMap[key] = currentCount - 1;
            insertKey(key, currentCount - 1);
        }
    }

    string getMaxKey() {
        if (tail->prev == head) return ""; 
        return *(tail->prev->keys.begin()); 
    }

    string getMinKey() {
        if (head->next == tail) return "";  
        return *(head->next->keys.begin()); 
    }
};
