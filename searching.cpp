/*
    1. Linear Search
    Time Complexity: O(N)
    Space: O(1)

int linearSearch(const int arr[], int size, int target) 
{
    for (int i = 0; i < size; ++i) 
    {
        if (arr[i] == target) {
            return i;  // Element found, return its index
        }
    }
    return -1;  // Element not found


}

    2. binary Search
    Time Complexity: O(LogN)
    Space: O(1)

int binarySearch(vector<int>& arr, int target) 
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) 
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) 
        {
            return mid;  // Element found, return its index
        } 
        else if (arr[mid] < target) 
        {
            low = mid + 1;  // Target is in the right half
        } 
        else
        {
            high = mid - 1;  // Target is in the left half
        }
    }
    return -1;  // Element not found
}
*/