// Recursive Divide and Conquer approach
// Extra auxillary space taken here is O(N) as we create 2 arrays of N/2 sizes each time .. 
// O(NlogN) time apparently ..

void Merge(vector<int>& arr, int start, int middle, int end)
{
    // Create two arrays of appropriate size
    int size1 = middle-start+1;
    int size2 = end-middle;

    int* left = new int[size1];
    int* right = new int[size2];

    // Copy values into the array
    int mainIndex = start;
    for(int i = 0; i < size1; i++)
        left[i] = arr[mainIndex++];

    for(int i = 0; i < size2; i++)
        right[i] = arr[mainIndex++];

    // Merge the two arrays
    int index1 = 0, index2 = 0;
    mainIndex = start;

    while(index1 < size1 && index2 < size2)
    {
        if(left[index1] < right[index2])
            arr[mainIndex++] = left[index1++];
        else
            arr[mainIndex++] = right[index2++];
    }
    while(index1 < size1)
        arr[mainIndex++] = left[index1++];

    while(index2 < size2)
        arr[mainIndex++] = right[index2++];
    
    // Important Step!!
    delete []left;
    delete []right;
}

void MergeAlgo(vector<int>& arr, int start, int end)
{
    if(start >= end)
        return;
    
    int middle = (start+end)/2;
    
    MergeAlgo(arr, start, middle);
    MergeAlgo(arr, middle+1, end);
    Merge(arr, start, middle, end);
}

void mergeSort(vector < int > & arr, int n) {
    MergeAlgo(arr, 0, n-1);
}