// O(NlogN + MN) time and O(MN) space, where M = number of elements added
// Daily Challenge: 8th April 2022
// lower_bound() --> good concept

class KthLargest {
public:
    vector<int> elements, useful; 
    int z;
    
    KthLargest(int k, vector<int>& nums) {
        elements = nums;
        z = k;
        sort(elements.begin(), elements.end());    
    }
    
    int add(int val) {
        auto it = lower_bound(elements.begin(), elements.end(), val);
        elements.insert(it, val);
        
        return elements[elements.size()-z];
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */