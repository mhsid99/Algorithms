/*
    1.Insertion Sort:

Time Complexity: O(N^2) 
Auxiliary Space: O(1)


void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) 
	{
        key = arr[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1],
        // that are greater than key, 
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

    2. Quick Sort

Time Complexity: Avg: θ ( N log (N)); Worst: O(N^2)
Space Complexity: O(1);O(N) considering the recursive stack

int partition(int arr[],int low,int high)
{
  //choose the pivot
   
  int pivot=arr[high];
  //Index of smaller element and Indicate
  //the right position of pivot found so far
  int i=(low-1);
   
  for(int j=low;j<=high;j++)
  {
    //If current element is smaller than the pivot
    if(arr[j]<pivot)
    {
      //Increment index of smaller element
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[high]);
  return (i+1);
}
 
// The Quicksort function Implement
            
void quickSort(int arr[],int low,int high)
{
  // when low is less than high
  if(low<high)
  {
    // pi is the partition return index of pivot
     
    int pi=partition(arr,low,high);
     
    //Recursion Call
    //smaller element than pivot goes left and
    //higher element goes right
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
  }
}

    3. Merge Sort
Time Complexity: O(N log(N))
Auxiliary Space: O(N)

void merge(vector<int>&arr, int l, int m, int r)
{
    int n1=m-l+1;
    int n2=r-m;
    
    int left[n1],right[n2];
    
    int i,j,k;
    
    for(i=0; i<n1; i++)
    {
        left[i] = arr[l+i];
    }
    for(j=0; j<n2; j++)
        right[j] = arr[m+j+1];
    
    i=0, j=0, k=l;
    while(i<n1 && j<n2)
    {
        if(left[i] <right[j])
        {
            arr[k++] = left[i++];
            //i++;
        }
        else
        {
            arr[k++] = right[j++];
            //j++;
        }
        //k++;
            
    }
    
    while(i<n1)
    {
        arr[k++] = left[i++];
        //i++;
        //k++;
    }
    while(j<n2)
    {
        arr[k++] = right[j++];
        //j++;
        //k++;
    }
    cout<<"array till now: ";
    for(int x=0;x<arr.size(); x++)
    {
        cout<<arr[x]<<" ";
    }
    cout<<endl;
    cout<<endl;
     // Your code here
}

void mergeSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
        
    }
}


    4. Counting Sort//good for sorting elements with small range.
    Time Complexity: O(N+M),where N and M are the size of inputArray[] and countArray[] respectively.
    Auxiliary Space: O(N+M), where N and M are the space taken by outputArray[] and countArray[] respectively.

vector<int> countSort(vector<int>& inputArray)
{
    int N = inputArray.size();
 
    // Finding the maximum element of array inputArray[].
    int M = 0;
 
    for (int i = 0; i < N; i++)
        M = max(M, inputArray[i]);
 
    // Initializing countArray[] with 0
    vector<int> countArray(M + 1, 0);
 
    // Mapping each element of inputArray[] as an index
    // of countArray[] array
 
    for (int i = 0; i < N; i++)
        countArray[inputArray[i]]++;
 
    // Calculating prefix sum at every index
    // of array countArray[]
    for (int i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];
 
    // Creating outputArray[] from countArray[] array
    vector<int> outputArray(N);
 
    for (int i = N - 1; i >= 0; i--)
    {
        outputArray[countArray[inputArray[i]] - 1]
            = inputArray[i];
 
        countArray[inputArray[i]]--;
    }
 
    return outputArray;
}

    5. Heap Sort
Time Complexity: O(N log N)
Auxiliary Space: O(log n), due to the recursive call stack. However, auxiliary space can be O(1) 
for iterative implementation.

void heapify(int arr[], int N, int i)
{
 
    // Initialize largest as root
    int largest = i;
 
    // left = 2*i + 1
    int l = 2 * i + 1;
 
    // right = 2*i + 2
    int r = 2 * i + 2;
 
    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest
    // so far
    if (r < N && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) 
    {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}
 
// Main function to do heap sort
void heapSort(int arr[], int N)
{
 
    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
 
    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--) 
    {
 
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

    6.Selection Sort//not stable
    Time Complexity:O(n^2)
    Space Complexity: O(1)
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n - 1; i++) {
 
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
 
        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

    7.Bubble Sort
    Time Complexity: O(N^2)
    Auxiliary Space: O(1)

void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
 
        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
}

*/
