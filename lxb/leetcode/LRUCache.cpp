http://oj.leetcode.com/problems/lru-cache/
/*
  Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/

/* STL is much simpler than you write your own double list */
class LRUCache{
private:
    list<pair<int, int> > List;
    int cacheSize;
    unordered_map<int, list<pair<int,int> >::iterator> hash;
    
public:
    LRUCache(int capacity) {
        cacheSize = capacity;
    }
    
    int get(int key){
        if (hash.find(key) == hash.end()) return -1;
        
        //move to head
        auto &it = hash[key];
        List.splice(List.begin(), List, it);
        
        //update hash
        hash[key] = List.begin();
        return (*it).second;
    }
    
    void set(int key, int value){
        if (hash.find(key) != hash.end()){
            //update
            auto &it = hash[key];
            (*it).second = value;
            
            //move to head
            List.splice(List.begin(), List, it);
            
            //update hash
            hash[key] = List.begin();
            return;
        }
        
        // need insert or possible replace
        if (List.size() < cacheSize){
            List.push_front(make_pair(key,value));
            //update hash
            hash[key] = List.begin();
        }else{
            //remove last one.
            hash.erase(List.back().first);
            List.pop_back();
            
            //insert into head and put int hash table
            List.push_front(make_pair(key,value));
            hash[key] = List.begin();
        }
    }
};


/* There is bug in this code. Tired to debug it*/
class LRUCache{
    typedef struct Node{
        int key;
        int value;
        struct Node *prev, *next;
        
        Node(int k, int v):key(k),value(v),prev(NULL),next(NULL){};
    }Node;
    
public:
    LRUCache(int capacity) {
        maxCapacity = capacity;
        currNum = 0;
        head = new Node(-1,-1);  //dumy head;
        tail = NULL;
    }
    
    ~LRUCache(){
        while (head){
            Node *next = head->next;
            delete head;
            head = next;
        }
    }
    
    int get(int key) {
            if (Hash.find(key) == Hash.end()) return -1;
            
            //LRU
            Node *node = Hash[key];
            MoveToHead(node);
            return Hash[key]->value;
    }
    
    void set(int key, int value) {
        if (Hash.find(key) != Hash.end()){
            //update and move to head.
            Node *node = Hash[key];
            node->value = value;
            MoveToHead(node);
            return;
        }
        
        // need either insert a new one, or replace oldest one.
        if (currNum < maxCapacity){
            Node *node = new Node(key,value);
            
            //insert into head
            node->next = head->next;
            node->prev = head;
            if (node->next) node->next->prev = node;
            head->next = node;
            
            if (currNum == 0) tail = node;
            ++currNum;
            Hash[key] = node;
            return;
        }else{
            //replace oldest one.
            Node *node = tail;
            
            if (tail->prev == head){
                //only one element.
                Hash.erase(node->key);
                Hash[key] = value;
                
                node->key = key;
                node->value = value;
                
                return;
            }
            
            //move than one element.
            node->key = key;
            node->value = value;
            
            // manage Hash.
            Hash.erase(node->key);
            Hash[key] = node;
            
            //move to head
            MoveToHead(node);
        }
    }
    
private:
    int currNum;
    int maxCapacity;
    Node *head, *tail;
    unordered_map<int, Node *> Hash;
    
    void MoveToHead(Node *node)
    {
        //remove node from list
        if (tail == node){
            //special handle last node
            tail = node->prev;
            tail->next = NULL;
        }else{
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
            
        //insert into head
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }
};
