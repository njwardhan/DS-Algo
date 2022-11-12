// REDO!

// 1. Approach using an ordered C++ set: Algo works in O(logN) time for each addNum() and findMedian() call, along with O(N) space
// No idea why though the second (commented out) declaration of the ordered set is not giving the correct answer .. 

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set =tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update> ;


// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
  
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

class MedianFinder {
    ordered_set<int> s;
    int count = 0;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        s.insert(num);
        count++;
    }
    
    double findMedian() {
        if(count % 2 == 0)
        {
            int x = *s.find_by_order(count/2);
            int y = *s.find_by_order(count/2 - 1);
            return (x+y)/2.0;
        }
        else
            return *s.find_by_order(count/2)/1.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// 2. Using priority queue/heap 
// To-Do