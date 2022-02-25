// Constant space and O() time implementation of Bubble Sort
// Conditioning of the loops is the key here. If i were from 1 to < n, j would have been till < n-i only .. 

void bubbleSort(vector<int>& arr, int n)
{   
    // Bubble Sort
    int i = 0;
    while(i < n-1)
    {
        int j = 0;
        while(j < n-i-1)
        {
            if(arr[j+1] < arr[j])
            	swap(arr[j], arr[j+1]);
            j++;
        }
        i++;
    }
}

// Optimized Bubble Sort code --> In the best case, it has a time ramification of O(N) only!

void bubbleSort(vector<int>& arr, int n)
{   
    // Bubble Sort
    int i = 0;
    while(i < n-1)
    {
        int j = 0, key = 0;
        while(j < n-i-1)
        {
            if(arr[j+1] < arr[j])
            {
                swap(arr[j], arr[j+1]);
                key = 1;
            }
            j++;
        }
        if(key == 0)
            break;
        else
	        i++;
    }
}

// Recursive Solution for Bubble Sort

void BubbleSort(int arr[], int size)
{
    if(size == 0 || size == 1)
        return;
    
    for(int i = 0; i < size-1; i++)
    {
        if(arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);
    }
    BubbleSort(arr, size-1);
}

