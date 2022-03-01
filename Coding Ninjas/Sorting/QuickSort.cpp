// Constant (?) space and O(NlogN) average case time solution
// Quick Sort's worst case time goes as bad as O(N^2) btw ..

int Partition(vector<int>& arr, int start, int end)
{
    int pivot = arr[start];
    int smaller_elements = 0;
    
    for(int i = start+1; i <= end; i++)
    {
        if(arr[i] <= pivot)
            smaller_elements++;
    }
    
    int pivot_index = start + smaller_elements;
    swap(arr[pivot_index], arr[start]);
    
    int i = start, j = end;
    while(i < pivot_index and j > pivot_index)
    {
        while(arr[i] <= pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        
        if(i < pivot_index and j > pivot_index)
            swap(arr[i++], arr[j--]);
    }
    return pivot_index;
}

void QuickSort(vector<int>& arr, int start, int end)
{
    if(start >= end)
        return;
    
    int partition_index = Partition(arr, start, end);
    
    QuickSort(arr, start, partition_index-1);
    QuickSort(arr, partition_index+1, end);
}

vector<int> quickSort(vector<int> arr)
{
    QuickSort(arr, 0, arr.size()-1);
    return arr;
}
