// Complexity ramifications for standard functions are not clearly defined, but with a decent guess, it should be close to O(M*N) .. 
// New point to learn, the size_t data type for standard string functions ..

class Solution {
public:
    int strStr(string haystack, string needle) {
        int c = needle.size();
        
        if(c == 0)
            return 0;
        
        if(c > haystack.size())
            return -1;
        
        size_t pos = -1;
        pos = haystack.find(needle);
        
        if(pos!=-1)
            return pos;
        else
            return -1;
    }
};