#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
class LRUCache : public Cache {
public:
    LRUCache(int capacity) {
        cp = capacity;
        head = nullptr;
        tail = nullptr;
    }
    
    void set(int key, int value) override {
        if (mp.find(key) != mp.end()) {
            // Key exists, update value and move to front
            Node* node = mp[key];
            node->value = value;
            moveToFront(node);
        } else {
            // Key doesn't exist, add new node
            Node* newNode = new Node(key, value);
            if (mp.size() >= cp) {
                // Cache is full, remove least recently used
                removeLRU();
            }
            addToFront(newNode);
            mp[key] = newNode;
        }
    }
    
    int get(int key) override {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            moveToFront(node);
            return node->value;
        }
        return -1;
    }
    
private:
    void moveToFront(Node* node) {
        if (node == head) return;
        
        remove(node);
        
        node->next = head;
        node->prev = nullptr;
        if (head) head->prev = node;
        head = node;
        
        if (!tail) tail = head;
    }
    
    void addToFront(Node* node) {
        node->next = head;
        node->prev = nullptr;
        if (head) head->prev = node;
        head = node;
        if (!tail) tail = head;
    }
    
    void removeLRU() {
        if (!tail) return;
        
        Node* lru = tail;
        remove(lru);
        
        mp.erase(lru->key);
        delete lru;
    }
    
    void remove(Node* node) {
        if  (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;
        
        if (node == head) head = node->next;
        if (node == tail) tail = node->prev;
        
        node->prev = node->next = nullptr;
    }
};
int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
