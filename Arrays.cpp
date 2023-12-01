/*
    1. Kadane's Algo//largest continuous subarray
    Time Complexity: O(N)
    Auxiliary Space: O(1)

int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < size; i++) 
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

    2. Boyer-Moore Majority Voting Algorithm (N/2)
    Time Complexity: O(n) ( For two passes over the array )
    Space Complexity: O(1)

int findMajority(int arr[], int n)
{
    int i, candidate = -1, votes = 0;
    // Finding majority candidate
    for (i = 0; i < n; i++) {
        if (votes == 0) {
            candidate = arr[i];
            votes = 1;
        }
        else {
            if (arr[i] == candidate)
                votes++;
            else
                votes--;
        }
    }
    int count = 0;
    // Checking if majority candidate occurs more than n/2
    // times
    for (i = 0; i < n; i++) {
        if (arr[i] == candidate)
            count++;
    }
 
    if (count > n / 2)
        return candidate;
    return -1;
}

    3. Moore's Voting Algorithm for N/3 Majority element
    Time Complexity:  O(n)
    Space Complexity: O(1)

int appearsNBy3(int arr[], int n)
{
    int count1 = 0, count2 = 0;
    int first=INT_MAX    , second=INT_MAX    ;
 
    for (int i = 0; i < n; i++) {
 
        // if this element is previously seen, 
        // increment count1.
        if (first == arr[i])
            count1++;
 
        // if this element is previously seen, 
        // increment count2.
        else if (second == arr[i])
            count2++;
     
        else if (count1 == 0) {
            count1++;
            first = arr[i];
        }
 
        else if (count2 == 0) {
            count2++;
            second = arr[i];
        }
 
        // if current element is different from
        // both the previously seen variables, 
        // decrement both the counts.
        else {
            count1--;
            count2--;
        }
    }
 
    count1 = 0;
    count2 = 0;
 
    // Again traverse the array and find the
    // actual counts.
    for (int i = 0; i < n; i++) {
        if (arr[i] == first)
            count1++;
 
        else if (arr[i] == second)
            count2++;
    }
 
    if (count1 > n / 3)
        return first;
 
    if (count2 > n / 3)
        return second;
 
    return -1;
}
    4. Quick select Algorithm// for kth smallest element
    Time Complexity: O(N)
    Space Complexity: O(1)


int partition(int arr[], int l, int r) 
{ 
    int x = arr[r], i = l; 
    for (int j = l; j <= r - 1; j++) { 
        if (arr[j] <= x) { 
            swap(arr[i], arr[j]); 
            i++; 
        } 
    } 
    swap(arr[i], arr[r]); 
    return i; 
} 
  
// This function returns k'th smallest  
// element in arr[l..r] using QuickSort  
// based method.  ASSUMPTION: ALL ELEMENTS 
// IN ARR[] ARE DISTINCT 
int kthSmallest(int arr[], int l, int r, int k) 
{ 
    // If k is smaller than number of  
    // elements in array 
    if (k > 0 && k <= r - l + 1) { 
  
        // Partition the array around last  
        // element and get position of pivot  
        // element in sorted array 
        int index = partition(arr, l, r); 
  
        // If position is same as k 
        if (index - l == k - 1) 
            return arr[index]; 
  
        // If position is more, recur  
        // for left subarray 
        if (index - l > k - 1)  
            return kthSmallest(arr, l, index - 1, k); 
  
        // Else recur for right subarray 
        return kthSmallest(arr, index + 1, r,  
                            k - index + l - 1); 
    } 
  
    // If k is more than number of  
    // elements in array 
    return INT_MAX; 
} 

*/