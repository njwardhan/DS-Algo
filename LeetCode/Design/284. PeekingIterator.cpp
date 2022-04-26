// Daily Challenge: 25th April 2022
// Not the best question at all .. 
// peek(), next() and hasNext() depends totally on the Iterator class' next() and hasNext() function; but overall, they run in constant
// space and time

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    Iterator* itr = NULL;
    bool flag = false;
    int store = 0;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    itr = new Iterator(nums);
	}
    
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(flag)
            return store;
        
        if(itr->hasNext())    
        {
            store = itr->next();
            flag = true;
        }
        return store;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if(flag)    
        {
            flag = false;
            return store;
        }
        else if(itr->hasNext())
            return itr->next();
        else
            return -1;
	}
	
	bool hasNext() const {
        if(flag)
            return true;
        
	    return itr->hasNext();
	}
};