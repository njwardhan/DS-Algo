// Problem Link: https://www.codingninjas.com/codestudio/problems/find-power-of-a-number_893198?leftPanelTab=1

long long Pow(int X, int N)
{
    if(X == 0 and N == 0)
        return 1;
    if(X == 0)
        return 0;
    if(X == 1)
        return 1;
    if(N == 1)
        return X;
    if(N == 0)
        return 1;
    
    long long answer = Pow(X, N/2);
    
    if(N % 2 == 0)
        return answer * answer;
    else
        return X * answer * answer;
}