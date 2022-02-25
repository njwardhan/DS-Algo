// O(N^2) time and constant space solution

void insertionSort(int n, vector<int> &arr){
    // Insertion Sort
    
    int i = 1;
    while(i < n)
    {
        int temp = arr[i];
        int j = i-1;
        while(j >= 0)
        {
            if(temp < arr[j])
                arr[j+1] = arr[j];
            else
                break;
            j--;
        }
        arr[j+1] = temp;
        i++; 
    }  
}

// Recursive Solution

void InsertionSort(int arr[], int start_index, int size)
{
    // base case
    if(start_index == size)
        return;

    int temp = arr[start_index];
    int j = start_index-1;
    while(j >= 0)
    {
        if(temp < arr[j])
            arr[j+1] = arr[j];
        else
            break;
        j--;
    }
    arr[j+1] = temp;
    InsertionSort(arr, start_index+1, size);
}
