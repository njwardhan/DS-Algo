// O(N) time and space approach in worst case, where N = size of the input 'ops' array of strings
// Daily challenge: 10th April 2022

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> score;
        
        for(int i = 0; i < ops.size(); i++)
        {
            if(ops[i] == "+")
            {
                int temp = score[score.size()-1] + score[score.size()-2];
                score.push_back(temp);
            } 
            else if(ops[i] == "D")
            {
                int temp = 2 * score[score.size()-1];
                score.push_back(temp);
            }    
            else if(ops[i] == "C")
                score.pop_back();
            else
                score.push_back(stoi(ops[i]));
        }
        
        int sum = 0;
        
        for(int i = 0; i < score.size(); i++)
            sum += score[i];
        
        return sum;
    }
};