// O(M+N) time and space solution

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index1 = 0, index2 = 0;
        vector<int> answer;
        
        while(index1 < m and index2 < n)
        {
            if(nums1[index1] <= nums2[index2])
                answer.push_back(nums1[index1++]);
          
            if(nums1[index1] > nums2[index2])
                answer.push_back(nums2[index2++]);
        }
        while(index1 < m)
            answer.push_back(nums1[index1++]);
        
        while(index2 < n)
            answer.push_back(nums2[index2++]);
        
        for(int i = 0; i < answer.size(); i++)
            nums1[i] = answer[i];
    }
};