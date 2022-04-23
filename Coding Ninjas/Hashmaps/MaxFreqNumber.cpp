// Problem Link: https://www.codingninjas.com/codestudio/problems/maximum-frequency-number_920319?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
// O(N) time and O(number of distinct elements) space solution

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> m;
	int max_freq = 0;
	
	for(int i = 0; i < arr.size(); i++)
	{
		m[arr[i]]++;
		max_freq = max(max_freq, m[arr[i]]);
	}
	
	int answer;
	
	for(int i = 0; i < arr.size(); i++)
	{
		if(m[arr[i]] == max_freq)
		{
			answer = arr[i];
			break;
		}
	}
	
	return answer;
}