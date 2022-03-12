// Recursive solution
// Sort thing needs to be done. Standard sort() not supported in this problem .. 

void solve(vector<string>& answer, string str, int index)
{
    if(index == str.size())
    {
        answer.push_back(str);
        return;
    }
    
    string temp = str;
    
    for(int i = index; i < str.size(); i++)
    {
        str = temp;
        swap(str[index], str[i]);
        solve(answer, str, index+1);
    }
}

vector<string> generatePermutations(string &str)
{
    vector<string> answer;
    solve(answer, str, 0);
	// Sort(answer);
    return answer;
}