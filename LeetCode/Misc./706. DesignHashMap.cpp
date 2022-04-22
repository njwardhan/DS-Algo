// Daily Challenge: 22nd April 2022
// 1. Using an array to accomodate ALL the possible values. Not the best LC solution obv
// Functions put(), get() and remove() working in constant time, but overall space too much

class MyHashMap {
public:
    int arr[1000001] = { [0 ... 1000000] = -2 };
    MyHashMap() {

    }
    
    void put(int key, int value) {
        arr[key] = value;
    }
    
    int get(int key) {
        if(arr[key] == -2)
            return -1;
        else
            return arr[key];
    }
    
    void remove(int key) {
        arr[key] = -2;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

// ---------------------------------------------------------------------------------------------------------------------------

// 2. Obviously much better space performance, but because iterating over the vector in every operation, time ain't good.
// All the put(), get() and remove() functions run in O(size of the vector) time in their worst case :/

class MyHashMap {
public:
    vector<pair<int,int>> njw;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        bool tha = false;
        for(int i = 0; i < njw.size(); i++)
        {
            if(njw[i].first == key)
            {
                njw[i].second = value;
                tha = true;
                break;
            }
        }
        if(!tha)
        {
            pair<int,int> temp = make_pair(key, value);
            njw.push_back(temp);   
        }
    }
    
    int get(int key) {
        for(int i = 0; i < njw.size(); i++)
        {
            if(njw[i].first == key)
                return njw[i].second;
        }
        return -1;
    }
    
    void remove(int key) {
        for(int i = 0; i < njw.size(); i++)
        {
            if(njw[i].first == key)
            {
                njw.erase(njw.begin()+i);
                break;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */