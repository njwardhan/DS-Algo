// Problem link: https://www.codingninjas.com/codestudio/problems/replace-spaces_1172172?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_5&leftPanelTab=0
// O(lenght of string) time and constant space simple solution

string replaceSpaces(string &str){
	for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == ' ')
            str.replace(i, 1, "@40");
    }
    return str;
}