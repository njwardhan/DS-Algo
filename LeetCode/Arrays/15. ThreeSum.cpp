// 1. 

class Solution {
public:
    int T;
    vector<vector<int>> returnvc;
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        if(nums.size()<3)
            return {};
        
        sort(nums.begin(), nums.end());
        
        set<vector<int>> s;

        for(int i = 0; i < nums.size(); i++)
        {
            unordered_map<int, int> umap;
            T = nums[i];
            for (int j = i+1; j < nums.size(); j++)
            {
                umap[j] = nums[j];
                for (auto x : umap)
                {
                    if (x.first != j && x.second + nums[j] == -T)
                    {
                        vector<int> tempvc;
                        tempvc = {T, nums[j], x.second};
                        if(s.find(tempvc)==s.end())
                        {   
                            returnvc.push_back(tempvc); 
                            s.insert(tempvc);
                        }
                        else    
                            continue;
                    }    
                }
            }
        }
        return returnvc;
    }   
};

// 2. 

class Solution {
public:
    int T;
    vector<vector<int>> returnvc;
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3)
            return {};
        
        sort(nums.begin(), nums.end());
        
        set<vector<int>> s;

        for(int i = 0; i < nums.size() - 2; i++)
        {
            //unordered_map<int, int> umap;
            T = nums[i];
            int left = i+1, right = nums.size() - 1;
            while(left != right)
            {
                int temp;
                temp = nums[left] + nums[right];
                if (temp == -T)
                {
                    /* vector<int> tempvc;
                    tempvc = {T, nums[left], nums[right]};
                    if(s.find(tempvc)==s.end())
                    {   
                        returnvc.push_back(tempvc); 
                        s.insert(tempvc);
                    }
                    else    
                        continue; */
                    returnvc.push_back({T, nums[left], nums[right]});
                }   
                else if (temp < -T)
                    left++;
                else   
                    right--; 
            }
        }
        return returnvc;
    }   
};