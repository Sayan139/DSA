#include <iostream>
using namespace std;
// Intuition:

// Quick Sort is a divide-and-conquer algorithm like the Merge Sort. But unlike Merge sort, this algorithm does not use any extra array for sorting(though it uses an auxiliary stack space). So, from that perspective, Quick sort is slightly better than Merge sort.

// This algorithm is basically a repetition of two simple steps that are the following:

// Pick a pivot and place it in its correct place in the sorted array.
// Shift smaller elements(i.e. Smaller than the pivot) on the left of the pivot and larger ones to the right.
// Now, let’s discuss the steps in detail considering the array {4,6,2,5,7,9,1,3}:

// Step 1: The first thing is to choose the pivot. A pivot is basically a chosen element of the given array. The element or the pivot can be chosen by our choice. So, in an array a pivot can be any of the following:

// The first element of the array
// The last element of the array
// Median of array
// Any Random element of the array
// After choosing the pivot(i.e. the element), we should place it in its correct position(i.e. The place it should be after the array gets sorted) in the array. For example, if the given array is {4,6,2,5,7,9,1,3}, the correct position of 4 will be the 4th position.

// Note: Here in this tutorial, we have chosen the first element as our pivot. You can choose any element as per your choice.

// Step 2: In step 2, we will shift the smaller elements(i.e. Smaller than the pivot) to the left of the pivot and the larger ones to the right of the pivot. In the example, if the chosen pivot is 4, after performing step 2 the array will look like: {3, 2, 1, 4, 6, 5, 7, 9}. 

// From the explanation, we can see that after completing the steps, pivot 4 is in its correct position with the left and right subarray unsorted. Now we will apply these two steps on the left subarray and the right subarray recursively. And we will continue this process until the size of the unsorted part becomes 1(as an array with a single element is always sorted).

// So, from the above intuition, we can get a clear idea that we are going to use recursion in this algorithm.

// To summarize, the main intention of this process is to place the pivot, after each recursion call, at its final position, where the pivot should be in the final sorted array.

// Approach:

// Now, let’s understand how we are going to implement the logic of the above steps. In the intuition, we have seen that the given array should be broken down into subarrays. But while implementing, we are not going to break down and create any new arrays. Instead, we will specify the range of the subarrays using two indices or pointers(i.e. low pointer and high pointer) each time while breaking down the array.

// The algorithm steps are the following for the quickSort() function:

// Initially, the low points to the first index and the high points to the last index(as the range is n i.e. the size of the array). 
// After that, we will get the index(where the pivot should be placed after sorting) while shifting the smaller elements on the left and the larger ones on the right using a partition() function discussed later.
// Now, this index can be called the partition index as it creates a partition between the left and the right unsorted subarrays.
// After placing the pivot in the partition index(within the partition() function specified), we need to call the function quickSort() for the left and the right subarray recursively. So, the range of the left subarray will be [low to (partition index - 1)] and the range of the right subarray will be [(partition index + 1) to high]. 
// This is how the recursion will continue until the range becomes 1.

// Partition function for Quick Sort

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;
    
    // Find the correct position for the pivot
    while (i < j) {
        // Move i to the right while arr[i] is less than or equal to pivot
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        // Move j to the left while arr[j] is greater than pivot
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        // Swap arr[i] and arr[j] if they are not in the correct position
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    // Swap the pivot element with the element at index j
    swap(arr[low], arr[j]);
    return j;
}
// Now, let’s understand how to implement the partition() function to get the partition index.

// Inside the function, we will first select the pivot(i.e. arr[low] in our case).
// Now, we will again take two-pointers i and j. The i pointer points to low and the j points to high.
// Now, the pointer i will move forward and find the first element that is greater than the pivot. Similarly, the pointer j will move backward and find the first element that is smaller than the pivot.
// Here, we need to add some checks like i <= high-1 and j >= low+1. Because it might happen that i is standing at high and trying to proceed or j is standing at low and trying to exceed.
// Once we find such elements i.e. arr[i] > pivot and arr[j] < pivot, and i < j, we will swap arr[i] and arr[j].
// We will continue step 3 and step 4, until j becomes smaller than i.
// Finally, we will swap the pivot element(i.e. arr[low]) with arr[j] and will return the index j i.e. the partition index.

// Quick Sort function
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pindex = partition(arr, low, high); // Partition the array
        quicksort(arr, low, pindex - 1); // Recursively sort the left part
        quicksort(arr, pindex + 1, high); // Recursively sort the right part
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quicksort(arr, 0, n - 1); // Calling Quick Sort

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
