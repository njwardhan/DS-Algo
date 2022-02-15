// O(size of char array) time and constant space solution
// Logic is simple, keep swapping and updating the start and end values!

class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0, end = s.size()-1;
        
        while(start < end)
            swap(s[start++], s[end--]);
    }
};