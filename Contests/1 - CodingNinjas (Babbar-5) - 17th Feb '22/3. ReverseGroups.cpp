// Problem Link: https://www.codingninjas.com/codestudio/contests/love-babbar-contest-5/problems/17496

stack<int> reverseTheGroups(stack<int> &s, int n, int k) {
    stack<int> help;
    stack<int> answer;
    
    while(s.size() >= k)
    {
        for(int i = 1; i <= k; i++)
        {
            help.push(s.top());
            s.pop();
        }
            
		for(int i = 1; i <= k; i++)
        {
            answer.push(help.top());
        	help.pop();
        }            

    }    
    while(!s.empty())
    {
        answer.push(s.top());
        s.pop();
    }
    
	for(int i = 0; i < n; i++)
    {
        s.push(answer.top());
        answer.pop();
    } 
    
    return s;
}