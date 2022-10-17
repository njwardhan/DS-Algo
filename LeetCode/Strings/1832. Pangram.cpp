// O(length of the sentence) and constant space solution

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> alphabets(26, 0);
        
        for(int i = 0; i < sentence.size(); i++)
        {
            int k = sentence[i] - 'a';
            alphabets[k]++;
        }
        
        for(int i = 0; i < alphabets.size(); i++)
        {
            if(alphabets[i] == 0)
                return false;
            else
                continue;
        }
        return true;
    }
};