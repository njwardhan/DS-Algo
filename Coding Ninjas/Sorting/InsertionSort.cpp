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