// Problem Link: https://www.codingninjas.com/codestudio/problems/binary-search_972?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_11

int BSearch(int *input, int start, int end, int val)
{
    int middle = start + (end-start)/2;
    
    if(start > end)
        return -1;
    if(input[middle] == val)
        return middle;
    
    if(input[middle] > val)
        return BSearch(input, start, middle-1, val);
    else
        return BSearch(input, middle+1, end, val);
}

int binarySearch(int *input, int n, int val)
{
    return BSearch(input, 0, n-1, val);
}