/*
LRU Cache

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 ); // capacity = 2 

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class LRUCache {
public:
    LRUCache(int capacity):capacity(capacity) {}
    
    int get(int key) {
        // if key not found
        if(m.find(key)==m.end()) return -1;
        // get the value
        const int value = m[key]->second;
        // remove the pair 
        cache.erase(m[key]);
        // add the pair back to the front
        m[key] = cache.insert(cache.begin(), make_pair(key,value));
        // return the value 
        return value;
    }
    
    void put(int key, int value) {
        // if the key exists in the cache, remove it first
        if(m.find(key)!=m.end()){
            // remove the pair from cache
            cache.erase(m[key]);
            // remove the position 
            m.erase(key);
        }
        // no more room for the new pair. delete the least used one
        if(cache.size()>=capacity){
            // select the key to be deleted
            int key = cache.rbegin()->first;
            // remove the key & its position from m
            m.erase(key);
            // remove the least used cache
            cache.pop_back();
        }
        // put the new pair to the front and update m
        m[key] = cache.insert(cache.begin(), make_pair(key,value));
    }
private: 
    // capacity of the cache
    const int capacity;
    // storing the cache
    list<pair<int,int>> cache;
    // storing the position of the cache for each key
    unordered_map<int, list<pair<int,int>>::iterator> m;
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();