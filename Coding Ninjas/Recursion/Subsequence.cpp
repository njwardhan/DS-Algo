// Problem very similar to the subset problem

void solve(string str, vector<string>& answer, string s, int index)
{
    if(index == str.size())
    {
        if(!s.empty())
        	answer.push_back(s);
        return;
    }
    solve(str, answer, s, index+1);
    
    s += str[index];
    solve(str, answer, s, index+1);
}

vector<string> subsequences(string str){
	vector<string> answer;
    string s = "";
    solve(str, answer, s, 0);
    return answer;
}
