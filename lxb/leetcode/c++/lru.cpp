#include <iostream>
#include <list>
using namespace std;

class LRUCache{
private:
    list<pair<int, int> > List;
    int cacheSize;
    unordered_map<int, list<pair<int,int> >::iterator> hashTable;
    
public:
    LRUCache(int capacity) {
        cacheSize = capacity;
    }
    
    int get(int key){
        if (hashTable.find(key) == hashTable.end()) return -1;
        
        //move to head
        auto &it = hashTable[key];
        List.splice(List.begin(), List, it);
        
        //update hashTable
        hashTable[key] = List.begin();
        return (*it).second;
    }
    
    void set(int key, int value){
        if (hashTable.find(key) != hashTable.end()){
            //update
            auto &it = hashTable[key];
            (*it).second = value;
            
            //move to head
            List.splice(List.begin(), List, it);
            
            //update hashTable
            hashTable[key] = List.begin();
            return;
        }
        
        // need insert or possible replace
        if (List.size() < cacheSize){
            ++cacheSize;
            List.push_front(make_pair(key,value));
            //update hashTable
            hashTable[key] = List.begin();
        }else{
            //remove last one.
            hashTable.erase(List.back().first);
            List.pop_back();
            
            //insert into head and put int hashTable table
            List.push_front(make_pair(key,value));
            hashTable[key] = List.begin();
        }
    }
};

int main()
{
	LRUCache lru(1);
	lru.set(2,1);
	cout << lru.get(2);

	lru.set(3,2);
	cout << lru.get(2);

	cout << lru.get(3);
}
