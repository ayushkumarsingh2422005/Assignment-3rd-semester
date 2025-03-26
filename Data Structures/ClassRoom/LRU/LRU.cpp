// #include <iostream>
// #include <unordered_map>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
//     Node* prev;
// };
// class LinkedList {
//    private:
//     Node* head;
//     Node* tail;

//     public:
//     LinkedList() {
//         head = nullptr;
//         tail = nullptr;
//     }
//     void push_front(Node* newNode) {
//         if (head == nullptr) {
//             head = newNode;
//             tail = newNode;
//         } else {
//             newNode->next = head;
//             head->prev = newNode;
//             head = newNode;
//         }
//     }
//     void delete_tail() {
//         if (tail == nullptr) {
//             return;
//         }
//         if (tail == head) {
//             delete tail;
//             head = nullptr;
//             tail = nullptr;
//             return;
//         }
//         Node* temp = tail;
//         tail = tail->prev;
//         tail->next = nullptr;
//         delete temp;
//     }
//     void shift_node_to_front(Node* node) {
//         if (node == head) {
//             return;
//         }
//         if (node == tail) {
//             Node* temp = tail;
//             tail = tail->prev;
//             tail->next = nullptr;
//             temp->next = head;
//             head->prev = temp;
//             head = temp;
//             head->prev = nullptr;
//             return;
//         } else {
//             node->prev->next = node->next;
//             node->next->prev = node->prev;
//             node->next = head;
//             head->prev = node;
//             head = node;
//             head->prev = nullptr;
//             return;
//         }
//     }
// };

// class LRUCache {
//    private:
//     int capacity;
//     int currentSize = 0;
//     LinkedList* list = nullptr;
//     unordered_map<int, Node*> map;

//     public:
//     LRUCache(int capacity){
//         this->capacity = capacity;
//         list = new LinkedList();
//     }
//     void put(int key, int value){
//         if (currentSize < capacity) {
//             // add the key value pair
//             // add the key to the list
//             // add the key to the map
//             Node* newNode = new Node();
//             newNode->data = key;
//             newNode->next = nullptr;
//             newNode->prev = nullptr;
//             list->push_front(newNode);
//             map[key] = newNode;
//             currentSize++;
//         } else {
//             // remove the last element from the list
//             // remove the last element from the map
//             // add the new key value pair
//             // add the new key to the list
//             // add the new key to the map
//             list->delete_tail();
//             map.erase(key);
//             Node* newNode = new Node();
//             newNode->data = key;
//             newNode->next = nullptr;
//             newNode->prev = nullptr;
//             list->push_front(newNode);
//             map[key] = newNode;
//         }
//     }
//     int get(int key){
//         if (map.find(key) == map.end()) {
//             return -1;
//         } else {
//             Node* node = map[key];
//             list->shift_node_to_front(node);
//             return key;
//         }
//     }
// };

// int main(int argc, char const* argv[]) {
//     /* code */
//     LRUCache* cache = new LRUCache(3);
//     cache->put(1, 1);
//     cache->put(2, 2);
//     cache->put(3, 3);
//     cout << cache->get(1) << endl;
//     cache->put(4, 4);
//     cout << cache->get(2) << endl;
//     return 0;
// }

#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int key, value;
    Node* next;
    Node* prev;
};

class LinkedList {
   public:
    Node* head;
    Node* tail;
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push_front(Node* newNode) {
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        head->prev = nullptr;  // Ensure the new head has no previous node
    }

    void delete_tail() {
        if (tail == nullptr) {
            return;
        }
        if (tail == head) {
            delete tail;
            head = nullptr;
            tail = nullptr;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }

    void shift_node_to_front(Node* node) {
        if (node == head) {
            return;
        }
        if (node == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        node->next = head;
        head->prev = node;
        head = node;
        head->prev = nullptr;
    }
};

class LRUCache {
   private:
    int capacity;
    int currentSize = 0;
    LinkedList* list;
    unordered_map<int, Node*> map;

   public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        list = new LinkedList();
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            // Key already exists, update value and move to front
            map[key]->value = value;
            list->shift_node_to_front(map[key]);
            return;
        }

        if (currentSize < capacity) {
            Node* newNode = new Node();
            newNode->key = key;
            newNode->value = value;
            newNode->next = nullptr;
            newNode->prev = nullptr;
            list->push_front(newNode);
            map[key] = newNode;
            currentSize++;
        } else {
            // Remove LRU element (tail)
            int lastKey = list->tail->key;
            Node* removedNode = list->tail;
            list->delete_tail();
            map.erase(lastKey);
            delete removedNode;  // Free memory

            // Add new node
            Node* newNode = new Node();
            newNode->key = key;
            newNode->value = value;
            newNode->next = nullptr;
            newNode->prev = nullptr;
            list->push_front(newNode);
            map[key] = newNode;
        }
    }

    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        } else {
            Node* node = map[key];
            list->shift_node_to_front(node);
            return node->value;
        }
    }
};

int main() {
    LRUCache* cache = new LRUCache(3);
    cache->put(1, 100);
    cache->put(2, 200);
    cache->put(3, 300);
    cout << cache->get(1) << endl;  // Should return 100
    cache->put(4, 400);
    cout << cache->get(2) << endl;  // Should return -1 (evicted)
    cout << cache->get(3) << endl;  // Should return 300
    cout << cache->get(4) << endl;  // Should return 400
    return 0;
}
