// Daily Challenge: 21st April 2022 
// add() function --> O(logN) time and O(1) space
// remove() function --> O(logN) time and O(1) space
// contains() function --> O(logN) time and O(1) space
  
class MyHashSet {
public:
    set<int> s;
    MyHashSet() {
        
    }
    
    void add(int key) {
        s.insert(key);
    }
    
    void remove(int key) {
        auto it = s.find(key);
        if(it != s.end())
            s.erase(it);
    }
    
    bool contains(int key) {
        auto it = s.find(key);
        if(it != s.end())
            return true;
        else
            return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */